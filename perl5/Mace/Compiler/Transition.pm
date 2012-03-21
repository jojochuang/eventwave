# 
# Transition.pm : part of the Mace toolkit for building distributed systems
# 
# Copyright (c) 2011, Charles Killian, James W. Anderson, Adolfo Rodriguez, Dejan Kostic
# All rights reserved.
# 
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
# 
#    * Redistributions of source code must retain the above copyright
#      notice, this list of conditions and the following disclaimer.
#    * Redistributions in binary form must reproduce the above copyright
#      notice, this list of conditions and the following disclaimer in the
#      documentation and/or other materials provided with the distribution.
#    * Neither the names of the contributors, nor their associated universities 
#      or organizations may be used to endorse or promote products derived from
#      this software without specific prior written permission.
# 
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
# DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
# FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
# SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
# CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
# OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
# USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
# 
# ----END-OF-LEGAL-STUFF----
package Mace::Compiler::Transition;

use strict;
use Switch;

use Mace::Util qw(:all);

use Class::MakeMethods::Template::Hash 
    (
     'new' => 'new',
     'string' => 'name',
     'string' => 'type', 
     'string' => 'readStateVariable', 
     'array_of_objects' => ['guards' => { class => 'Mace::Compiler::Guard' }], #XXX these guards will eventually be more, with defining variables
     'scalar' => 'transitionNum',
     'hash --get_set_items' => 'options',
     'scalar' => 'startFilePos',
     'scalar' => 'columnStart',
     'object' => ['method' => { class => "Mace::Compiler::Method" }],
     'string' => 'context',
     #'array' => 'snapshotContext',
     'hash' => 'snapshotContext',
     'string' => 'contextVariablesAlias',
    );

sub toString {
    my $this = shift;
    my $s = $this->type()." ".$this->name()." [ guards : ";
    $s .= join(" && ", map { "(".$_->toString().")" } $this->guards());
    $s .= " ] ".$this->method()->toString(noline => 1);
    $s =~ s|\n||g;
    return $s;
} # toString


# Note
# Q : Why do we need to check locking for guard function?? Do we need r/w lock??
# A : No, we don't need locking for guard function. They are used only for checking
#     we have any referenced state variables within guard function so they can be
#     read_* referenced before use.

sub printGuardFunction {
  my $this = shift;
  my $handle = shift;
  my $service_impl = shift;
  my %arg = @_;
  my $methodprefix = $arg{methodprefix};
  my $serviceLocking = $arg{serviceLocking};  # note : stores service-wide locking
  my $transitionNum = $this->transitionNum();
  my $type = $this->type();

  my $locking = 1;

  # note : lockings in here are used ONLY TO CHECK whether we need to refer state variables
  #        with read_ functions.
  
  if( $this->isLockingTypeDefined() ) {
    $locking = $this->getLockingType();
  } else {
    if( defined($serviceLocking) )
    {
      $locking = $serviceLocking;
    }
  }

  if( defined($this->name() ) ) {
    if ( $this->name() eq 'maceInit' ||
         $this->name() eq 'maceExit' ||
         $this->name() eq 'hashState' ||
         $this->name() eq 'maceReset') {
        # Exclusive locking if the transition is of these types, regardless of any other specification.
        $locking = 1;
    }
  }

  
  my $routine = $this->method()->toString("noreturn" => 1, "novirtual" => 1, "paramconst" => 1, "methodconst" => 1, "methodprefix" => "bool ${methodprefix}guard_${type}_${transitionNum}_");

  my @declares = ();
  my @usedVar = ();

  my $guardString = '';
  my $guardStringEnd = <<END;
  return true;
END

  my $guardReferredVariables;

  foreach my $guard ($this->guards()) 
  {
    if( defined $guard && $guard ne '')
    {
      my $gs = $guard->toString('withline' => 1);
      my $type = $guard->getType();

      push(@declares, "// guard_type = ${type}");

      # if locking=read
      if( $locking == 0 )
      {
        push(@declares, "// transition is in read mode. adding referenced variables.");
        @usedVar = array_unique((@usedVar, @{$guard->usedVar()}));
      }
      else
      {
        push(@declares, "// transition is in write mode.");
      }

      $guardString .= <<END;
      if($gs) {
END
        $guardStringEnd .= <<END;
      }
END
    }
    else
    {
      push(@declares, "// guard is not defined!!!!");
    }
  }

  # print referenced variables

  push(@declares, "// referenced variables = ".join(",", @usedVar)."\n");

  # Add referenced variables
  if( $locking == 0 )
  {
    for my $var ($service_impl->state_variables()) 
    {
      my $t_name = $var->name();
      my $t_type = $var->type()->toString(paramref => 1);

      if (!$this->method()->isUsedVariablesParsed()) {
        # If default parser is used since incontext parser failed, include every variable.
        if( $Mace::Compiler::Globals::useSnapshot ) {
          push(@declares, "const ${t_type} ${t_name} __attribute((unused)) = read_${t_name}();");
        }
      } else { # If InContext parser is used, selectively include variable.
        if(grep $_ eq $t_name, @usedVar) {
          push(@declares, "const ${t_type} ${t_name} __attribute((unused)) = read_${t_name}();");
        } else {
          push(@declares, "// const ${t_type} ${t_name} = read_${t_name}();");
        }
      }
    }

    if (!$this->method()->isUsedVariablesParsed()) {
      # If default parser is used since incontext parser failed, include every variable.
      if( $Mace::Compiler::Globals::useSnapshot ) {
        push(@declares, "const state_type& state __attribute((unused)) = read_state();");
      }
    } else { # If InContext parser is used, selectively include variable.
      if(grep $_ eq "state", @usedVar) {
        push(@declares, "const state_type& state __attribute((unused)) = read_state();");
      } else {
        push(@declares, "// const state_type& state = read_state();");
      }
    }
  }

  # note : printout locking information of the guard event.
  push(@declares, "__eventContextType = ".$locking.";");

  $guardReferredVariables = join("\n", @declares);

  print $handle <<END;
  $routine {
    $guardReferredVariables
    $guardString $guardStringEnd return false;
  }
END

}

sub toGuardDeclaration {
  my $this = shift;
  my $transitionNum = $this->transitionNum();
  my $type = $this->type();

  return $this->method()->toString("noreturn" => 1, "novirtual" => 1, "paramconst" => 1, "methodconst" => 1, "methodprefix" => "bool guard_${type}_${transitionNum}_");
}

sub getGuardMethodName {
  my $this = shift;
  my $transitionNum = $this->transitionNum();
  my $type = $this->type();

  return "guard_${type}_${transitionNum}_".$this->method->name();
}

sub getTransitionMethodName {
  my $this = shift;
  my $transitionNum = $this->transitionNum();
  my $type = $this->type();

  return "${type}_${transitionNum}_".$this->method->name();
}

sub toTransitionDeclaration {
  my $this = shift;
  my $transitionNum = $this->transitionNum();
  my $type = $this->type();

  return $this->method->returnType()->toString()." ${type}_${transitionNum}_".$this->method()->toString("noreturn" => 1, "novirtual" => 1);
}

#
# Note : This subroutine is used to print demuxed transitions like downcall_*_xxx() / upcall_*_xxx() functions.
#

sub printTransitionFunction {
  my $this = shift;
  my $handle = shift;
#  my $selector = $this->method->options('selector');
  my $selectorVar = $this->method->options('selectorVar');
  my %args = @_;
  my $methodprefix = $args{methodprefix};
  my $serviceLocking = $args{serviceLocking};
#  my $readStateVariable = $arg{readStateVariable};
  my $transitionNum = $this->transitionNum();
  my $type = $this->type();
  my $name = $this->method->name();
  my $routine = $this->method()->toString("novirtual" => 1, "methodprefix" => "${methodprefix}${type}_${transitionNum}_");
  my $body = $this->method()->body();
  my $returnType = $this->method->returnType()->toString();
  #TODO: Only do onChangeVars if body might modify the vars mentioned.
  my $changeTracker = ""; 
  if($this->type() ne "aspect" and !$this->method->isConst() and scalar(@{$args{onChangeVars}})) { #XXX
    $changeTracker = "__ChangeTracker__ _ct(this);\n"
  }

  my $prep = "PREPARE_FUNCTION";
  if ($Mace::Compiler::Globals::MACE_TIME) {
#      $prep = "MaceTime curtime = MaceTime::currentTime();";
      $prep = "MaceTime _curtime = 0;";
  }

  # process locking mode
  #
  # Note : Locking in here is ONLY USED TO CHECK whether it holds read lock.

  my $locking = 1;
  
  if( $this->isLockingTypeDefined() ) {
    $locking = $this->getLockingType();
  } else {
    if( defined($serviceLocking) ) {
      $locking = $serviceLocking;
    }
  }

  if ( $name eq 'maceInit' ||
       $name eq 'maceExit' ||
       $name eq 'hashState' ||
       $name eq 'maceResume' ||
       $name eq 'maceReset') {
      # Exclusive locking if the transition is of these types, regardless of any other specification.
      $locking = 1;
  }

  my $read_state_variable = "// Transition.pm:printTransitionFunction()\n";
 
  $read_state_variable .= "// Locking type = ".$locking."\n";

  if( $locking == 0 )
  {
    $read_state_variable .= $this->readStateVariable();
  }

  if( defined($this->context) and  not ($this->context eq "" or $this->context eq "global" or $this->context eq "__internal" ) ){
    $read_state_variable .= $this->readStateVariable();
  }

  my $contextAlias = $this->contextVariablesAlias();

  $read_state_variable .= "__eventContextType = ".$locking.";\n";

  my $snapshotContexts = "";
  while( my ($context,$alias) = each (%{ $this->snapshotContext() } ) ){
    $snapshotContexts .= "//$context -> $alias\n";

    $snapshotContexts .= $this->getContextAliasRef($context, $alias);
  }

  print $handle <<END;
  $routine {
    #define selector selector_$selectorVar
    #define selectorId selectorId_$selectorVar
    $prep
    ADD_LOG_BACKING
    $changeTracker
    $read_state_variable
    $contextAlias
    $snapshotContexts
    $body
    #undef selector
    #undef selectorId
  }
END
}

# this subroutine is used to determine the least(lowest) common parent context.
# The event will start from the context, make direct calls to child contexts to collect snapshots,
# 
sub getLeastCommonParentContext {
    my $this = shift;

    my $ret = "mace::vector< mace::vector<mace::string> > contextPathList;";

    my @contextpaths = ();
    # put all used contexts into array. prepend "global::" as needed.
    if( $this->context =~ /^global/ ){
        push @contextpaths, $this->context;
    }else{
        push @contextpaths, "global::" . $this->context;
    }

    while( my ($context,$alias) = each (%{ $this->snapshotContext() } ) ){
        if( $this->context =~ /^global/ ){
            push @contextpaths, $context;
        }else{
            push @contextpaths, "global::" . $context;
        }
    }

    for my $contextpath ( @contextpaths ) {
        my $contextPathOutput = "mace::vector<mace::string> contextPathNodes;\n";
        my @contextScope= split(/::/, $contextpath);

        # initializes context class if not exist
        my $regexIdentifier = "[_a-zA-Z][a-zA-Z0-9_]*";

        while( defined (my $contextID = shift @contextScope)  ){
            if ( $contextID =~ /($regexIdentifier)<($regexIdentifier)>/ ) {

                #$contextPathOutput .= "contextPathNodes.push_back(\"$1\");\n";

                $contextPathOutput .= qq/
                { 
                    mace::string tmp = mace::string("$1<") + boost::lexical_cast<std::string>( $2 ) + ">";
                    contextPathNodes.push_back(tmp);
                }
                /;
            } elsif ($contextID =~ /($regexIdentifier)<([^>]+)>/) {
              my @contextParam = split("," , $2);
              my $param = "__$1__Context__param(" . join(",", @contextParam)  .")";
                $contextPathOutput .= qq/
                { 
                    mace::string tmp = mace::string("$1<") + boost::lexical_cast<std::string>( $param ) + ">";
                    contextPathNodes.push_back(tmp);
                }
                /;
            }else{ #single context
                $contextPathOutput .= "contextPathNodes.push_back(\"$contextID\");\n";
            }

            if( @contextScope == 0 ){
                
            }else{

            }
        }

        $ret .= "{ $contextPathOutput }";
     
    }
    #my $ret = "mace::vector< mace::vector<mace::string> > contextPathList;";
    $ret .= qq/
        mace::string leastCommonParent;
       
        for(int pathLen = 0; pathLen < contextPathList[0].size(); pathLen ++){
            bool samePrefix = true;
            for( int ctxNo = 1; ctxNo < contextPathList.size(); ctxNo++  ){
                if( contextPathList[ctxNo].size() <= pathLen ){
                    samePrefix = false;
                    break;
                }
                if( contextPathList[0][pathLen].compare( contextPathList[ctxNo][pathLen] ) != 0 ){
                    samePrefix = false;
                    break;
                }
            }
            if( samePrefix == true ){
                if( pathLen > 0 ) leastCommonParent += "::";
                leastCommonParent += contextPathList[0][pathLen];
            }
        }
    /;
    return $ret;
}


sub getContextAliasRef {
    my $this = shift;
    my $snapshotcontext = shift;
    my $alias = shift;

    my $ret = "";
    my @contextScope= split(/::/, $snapshotcontext);

    # initializes context class if not exist
    my $contextString = "";
    my $regexIdentifier = "[_a-zA-Z][a-zA-Z0-9_]*";

    while( defined (my $contextID = shift @contextScope)  ){
        my $contextName = "";
        if ( $contextID =~ /($regexIdentifier)<($regexIdentifier)>/ ) {
            $contextString .= "$1\[$2\]";
            $contextName = $1;
        } elsif ($contextID =~ /($regexIdentifier)<([^>]+)>/) {
            $contextString .= "$1\[$2\]";
            $contextName = $1;
        } else{ #single context
            $contextString .= $contextID;
            $contextName = $contextID;
        }

        if( @contextScope == 0 ){
            $ret = "const __${contextName}__Context& $alias = $contextString.getSnapshot();";
            
        }else{

            $contextString = $contextString . ".";
        }
    }
    
    return $ret;
}

sub isRaw {
    my $this = shift;
    return $this->type() eq "raw_upcall";
}

sub isOnce {
    my $this = shift;
    if (defined($this->method()->options()->{exec})) {
	return ($this->method()->options("exec") eq "once");
    }
    return 0;
}

sub isLockingTypeDefined {
  my $this = shift;
  return defined($this->method()->options()->{locking});
}

sub getLockingType {
    my $this = shift;
    my $def = shift;
    if (defined($this->method()->options()->{locking})) {
      return $this->method()->options("locking");
    }
    return $def;       # return default
}

sub getMergeType {
    my $this = shift;
    if (defined($this->method()->options()->{merge})) {
      return $this->method()->options("merge");
    }
    return "";
}

sub validate {
  my $this = shift;
  my $selectors = shift;
  my $timerName = shift;
  my $transitionNum = $this->transitionNum();
  my $selectorType = 'default';
  my $messageName = '';
  my $fnName = $this->method->name;
  if($this->type eq 'scheduler') {
    $selectorType = 'message';
    $messageName = $this->method->options('timer');;
    $fnName = 'expire';
  }
  elsif($this->method->options('message')) {
    $selectorType = 'message';
    $messageName = $this->method->options('message');
  }

  if (defined($this->method()->options()->{locking})) {
    if ($this->method()->options("locking") eq "on") {
        $this->method()->options("locking", 1);
    } elsif ($this->method()->options("locking") eq "write") {
        $this->method()->options("locking", 1);
    } elsif ($this->method()->options("locking") eq "global") {
        $this->method()->options("locking", 1);
    } elsif ($this->method()->options("locking") eq "read") {
        $this->method()->options("locking", 0);
    } elsif ($this->method()->options("locking") eq "anonymous") {
        $this->method()->options("locking", 0);
    } elsif ($this->method()->options("locking") eq "anon") {
        $this->method()->options("locking", 0);
    } elsif ($this->method()->options("locking") eq "none") {
        $this->method()->options("locking", -1);
    } elsif ($this->method()->options("locking") eq "null") {
        $this->method()->options("locking", -1);
    } elsif ($this->method()->options("locking") eq "off") {
        $this->method()->options("locking", -1);
    } else {
        my $l = $this->method()->options("locking");
        Mace::Compiler::Globals::error("bad_transition", $this->method()->filename(), $this->method()->line(),
                                       "Unrecognized method option for locking: $l.  Expected 'write|on|read|off'.");
    }
  }

  my $state = join("&&",map{"(".$_->toString('oneline'=>1).")"} $this->guards);
  $state =~ s/\"/\\\"/g; # Escape quotes for string literals within (quoted) selector
  my $selector = $selectors->{$selectorType};
  $selector =~ s/\$function/$fnName/g;
  $selector =~ s/\$state/$state/g;
  if($selectorType eq 'message') {
    $selector =~ s/\$message/$messageName/g;
  }
  my $selectorVar = $this->type."_".$this->method->name."_".$transitionNum."_transition";
  $this->setSelector($selector);
  $this->setSelectorVar($selectorVar);

  while (my ($k, $v) = each(%{$this->options()})) {
      if ($k =~ m/^(message|timer|transitions|monitor)$/) {
	  next;
      }
      if ($k eq "merge") {
	  unless ($v =~ m/^(pre|post)$/) {
	      Mace::Compiler::Globals::error("bad_transition", $this->method()->filename(), $this->method()->line(),
					     "Unrecognized method option for merge: $v.  Expected 'pre' or 'post'.");
	  }
      }
      elsif ($k eq "exec") {
	  unless ($v =~ m/^(once)$/) {
	      Mace::Compiler::Globals::error("bad_transition", $this->method()->filename(), $this->method()->line(),
					     "Unrecognized method option for exec: $v.  Expected 'once'.");
	  }
      }
      else {
	  Mace::Compiler::Globals::error("bad_transition", $this->method()->filename(), $this->method()->line(),
					 "Unrecognized method option $k = $v.  Expected 'merge' or 'exec'.");
      }
  }
}

sub getSelector {
  my $this = shift;
  return $this->method->options('selector');
}

sub getSelectorVar {
  my $this = shift;
  return $this->method->options('selectorVar');
}

sub setSelector {
  my $this = shift;
  $this->method->options('selector', shift);
}

sub setSelectorVar {
  my $this = shift;
  $this->method->options('selectorVar', shift);
}

sub array_unique
{
    my %seen = ();
    @_ = grep { ! $seen{ $_ }++ } @_;
}


1;

