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
use Class::MakeMethods::Utility::Ref qw( ref_clone );

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
     'string' => 'contextVariablesAlias',
    );

my $regexIdentifier = "[_a-zA-Z][a-zA-Z0-9_.]*";

sub toString {
    my $this = shift;
    my $s = $this->type()." ".$this->name()." [ guards : ";
    $s .= join(" && ", map { "(".$_->toString().")" } $this->guards());
    $s .= " ] ".$this->method()->toString(noline => 1);
    $s =~ s/\"/\\\"/g; # Escape quotes for string literals within (quoted) selector
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


  # FIXME: chuangw: will modify guard function to address the issue with context access.
  # Add referenced variables
  if( $locking == 0 )
  {
    # chuangw: FIXME: not correct. use global context now instead.
    for my $var ($service_impl->state_variables()) 
    {
      my $t_name = $var->name();
      my $t_type = $var->type()->toString(paramref => 1);

      next if( $t_name =~ m/^__internal_/ );

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

  if( defined($this->getTargetContext() ) and  not ($this->getTargetContext() eq "" or $this->getTargetContext() eq "global" or $this->getTargetContext() eq "__internal" ) ){
    $read_state_variable .= $this->readStateVariable();
  }

  my $contextAlias = $this->contextVariablesAlias();

  $read_state_variable .= "__eventContextType = ".$locking.";\n";

  my $snapshotContexts = "";
  while( my ($context,$alias) = each (%{ $this->getSnapshotContexts() } ) ){
    $snapshotContexts .= "//$context -> $alias\n";

    $snapshotContexts .= $this->getContextAliasRef($context, $alias);
  }

	$snapshotContexts = "";

    my $ctx = $this->method->targetContextObject;
    my $contextLock = "";

    #print $this->method->name() . ":" . $args{locktype} . "\n";
    if ( $args{locktype} eq "ContextLock" ){
        if( $this->type eq "async" or $this->type eq "sync" ){
            $contextLock = $this->method->getContextLock();
        }
    }
  print $handle <<END;
  $routine {
    #define selector selector_$selectorVar
    #define selectorId selectorId_$selectorVar
    $prep
    ADD_LOG_BACKING
    $changeTracker
    //__printTransitionFunction__ $ctx
    $contextLock
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
    if( $this->getTargetContext() =~ /^global/ ){
        push @contextpaths, $this->getTargetContext();
    }else{
        push @contextpaths, "global::" . $this->getTargetContext();
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

        while( defined (my $contextID = shift @contextScope)  ){
            if ( $contextID =~ /($regexIdentifier)<($regexIdentifier)>/ ) {

                #$contextPathOutput .= "contextPathNodes.push_back(\"$1\");\n";

                $contextPathOutput .= qq/
                { 
                    mace::string tmp = mace::string("$1<") + boost::lexical_cast<mace::string>( $2 ) + ">";
                    contextPathNodes.push_back(tmp);
                }
                /;
            } elsif ($contextID =~ /($regexIdentifier)<([^>]+)>/) {
              my @contextParam = split("," , $2);
              my $param = "__$1__Context__param(" . join(",", @contextParam)  .")";
                $contextPathOutput .= qq/
                { 
                    mace::string tmp = mace::string("$1<") + boost::lexical_cast<mace::string>( $param ) + ">";
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

sub getTargetContext {
    my $this = shift;
    return $this->method()->targetContextObject();
}

sub getSnapshotContexts{
    my $this = shift;
    return $this->method()->snapshotContextObjects();
}

sub toMessageTypeName {
    my $this = shift;

    my $uniqid = $this->transitionNum;
    my $pname = $this->method->name;
    given( $this->type() ){
        when /(async|scheduler)/ {return "__async_at${uniqid}_$pname" }
        when "upcall" {
            my $ptype = ${ $this->method->params }[2]->type->type;
            return "__deliver_at_$ptype"; 
        }
        when "downcall" { }
    }
}

sub toWrapperName {
    my $this = shift;

    my $uniqid = $this->transitionNum;
    my $pname = $this->method->name;
    given( $this->type() ){
        when /(async|scheduler)/ {return "__async_wrapper_fn${uniqid}_$pname" }
        when "upcall" {
            my $ptype = ${ $this->method->params }[2]->type->type;
            return "__deliver_wrapper_fn_$ptype";
        }
        when "downcall" { }
    }
}

sub toRealHandlerName {
    my $this = shift;

    my $uniqid = $this->transitionNum;
    my $pname = $this->method->name;
    given( $this->type() ){
        when /(async|scheduler)/ {return "__async_fn${uniqid}_$pname" }
        when "upcall" {
            my $ptype = ${ $this->method->params }[2]->type->type;
            return "__deliver_fn_$ptype";
        }
        when "downcall" { }
    }
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
  my $contexts = shift;
  my $selectors = shift;
  my $timerName = shift;

  $this->method->validate( $contexts );
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
      if ($k =~ m/^(message|timer|transitions|monitor|originalTransition)$/) {
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
sub createRealAsyncHandler {
    my $this = shift;
    my $message = shift;
    my $name = shift;
    my $extra = shift;

    my $adMethod = shift; #output
    my $adWrapperMethod = shift; #output

    my $pname = $this->method->name();
    my $ptype = $message->name(); 
    my $this_subs_name = (caller(0))[3];
    my $messageName = $message->name();
    my $adWrapperName = $this->toWrapperName(); 
    my $adName = $this->toRealHandlerName();
    my $async_upcall_param = "param";

    if( not defined $extra ){
        Mace::Compiler::Globals::error("bad_message", __FILE__, __LINE__, "can't find the auto-generated autotype '__asyncExtraField'");
        return;
    }
    my @origParams;
    for my $param ($message->fields()) {
        given( $param->name ){
            when "extra" { push @origParams, "newExtra"; }
            default { push @origParams, "$async_upcall_param." . $param->name; }
        }
    }
    my $headMessage = "$ptype pcopy(" . join(",", @origParams) . ");";
#--------------------------------------------------------------------------------------
    my @nextHopMsgParams;
    my @nextExtraParams;

    foreach( $message->fields() ){
        given( $_->name ){
            when "extra" { push @nextHopMsgParams, "nextextra"; }
            default { push @nextHopMsgParams,  "$async_upcall_param.$_->{name}"; }
        }
    }
    foreach( @{ $extra->fields() } ){
        given( $_->name ){
            when "lastHop" { push @nextExtraParams, "$async_upcall_param.extra.nextHop"; }
            when "nextHop" { push @nextExtraParams, "nextHop"; }
            when "seqno" { push @nextExtraParams, "msgseqno"; }
            when /^(targetContextID|snapshotContextIDs|ticket)$/  { push @nextExtraParams, "$async_upcall_param.extra.$_->{name}"; }
        }
    }
    my $nextHopMessage = join(", ", @nextHopMsgParams);
    my $nextExtraParam = "__asyncExtraField nextextra(" . join(",", @nextExtraParams) . ");";
    my $prepareNextHopMessage = qq#
        uint32_t msgseqno = getNextSeqno(nextHop);
        $nextExtraParam
        $ptype nextmsg($nextHopMessage );
    #;
#--------------------------------------------------------------------------------------
    my @asyncMethodParams;
    my $startAsyncMethod;
    my $eventType = "";
    if( defined $this->options('originalTransition') ){
        if( $this->options('originalTransition') eq "scheduler" ){
            map{ push @asyncMethodParams,  "const_cast<" . $_->type->type . "&>($async_upcall_param.$_->{name})" if ($_->name ne "extra") ; } $message->fields();
            $startAsyncMethod = "expire_" . $pname . "(" . join(", ", @asyncMethodParams ) . ");";
            $eventType = "TIMEREVENT";
        }elsif( $this->options('originalTransition') eq "upcall" ){
            my $origUpcallMessage;
            my $numberIdentifier = "[1-9][0-9]*";
            my $methodIdentifier = "[_a-zA-Z][_a-zA-Z0-9]*";
            if($messageName =~ /__async_at($numberIdentifier)_upcall_deliver_($methodIdentifier)/){
                $origUpcallMessage = $2;
            }
            my @asyncParam;
            my @upcallParam;
            my $fieldCount = 0;
            foreach( $message->fields() ){
                if( $fieldCount <= 1 ){
                    push @asyncParam, "$async_upcall_param." . $_->name;
                }elsif ( $_->name ne "extra" ){
                    push @upcallParam, "$async_upcall_param." . $_->name;
                }
                $fieldCount++;
            }
            push @asyncParam, "$origUpcallMessage(" . join(",", @upcallParam ) . " )";
            $startAsyncMethod = "$pname(" . join(",", @asyncParam) . ");";
            $eventType = "UPCALLEVENT";
        }
    }else{
        map{ push @asyncMethodParams,  "$async_upcall_param.$_->{name}" if ($_->name ne "extra") ; } $message->fields();
        $startAsyncMethod = $pname . "(" . join(", ", @asyncMethodParams ) . ");";
        $eventType = "ASYNCEVENT";
    }
#--------------------------------------------------------------------------------------
    my $headWork = "";
    if( defined $this->options('originalTransition') and $this->options('originalTransition') eq "upcall" ){
        $headWork = qq#
    ASSERT( thisContextID != ContextMapping::getHeadContext() ); #;
    }else{
        $headWork = qq#
    if( thisContextID == ContextMapping::getHeadContext() ){
        __asyncExtraField newExtra;
        newExtra = asyncHead( $async_upcall_param, $async_upcall_param.extra, mace::HighLevelEvent::$eventType );
        $headMessage
        const MaceAddr globalContextAddr = contextMapping.getNodeByContext( "" );
        ASYNCDISPATCH( globalContextAddr , $adWrapperName , $ptype , pcopy );
        pthread_mutex_unlock( &mace::ContextBaseClass::headMutex );
        return;
    }
        #;
    }
#--------------------------------------------------------------------------------------
    my $adBody = "// Generated by ${this_subs_name}() line: " . __LINE__ . qq#
        //if( ! ackUpdateRespond(source, $async_upcall_param.extra.lastHop, $async_upcall_param.extra.seqno) ) return;
        const mace::string& thisContextID = $async_upcall_param.extra.nextHop;
        $headWork
        bool isTarget = false;
        if( thisContextID == $async_upcall_param.extra.targetContextID ) isTarget = true;

        asyncEventCheck($async_upcall_param.extra, isTarget );
        mace::ContextBaseClass *thisContext = ThreadStructure::myContext();
        
        if( isTarget ){
            asyncPrep(thisContextID,   $async_upcall_param.extra.snapshotContextIDs);
            ThreadStructure::ScopedServiceInstance si( instanceUniqueID ); //--->???
            $startAsyncMethod 
            asyncFinish( $async_upcall_param.extra.snapshotContextIDs );// after the prev. call finishes, do distribute-collect
        }else{ // not in target context
            if( thisContext->isLocalCommittable()  ){ // ignore DAG case.
                sendAsyncSnapshot( $async_upcall_param.extra, thisContextID, thisContext);
                mace::set< mace::string > const& subcontexts = ThreadStructure::getEventChildContexts( thisContextID ); //thisContext->getChildContextID();
                macedbg(1)<< "subcontexts -->" <<subcontexts <<"<--" <<Log::endl;
                for( mace::set<mace::string>::const_iterator subctxIter= subcontexts.begin(); subctxIter != subcontexts.end(); subctxIter++ ){
                    // TODO: if child contexts are located on the same node, queue the message on the async event queue...
                    const mace::string& nextHop  = *subctxIter; // prepare messages sent to the child contexts
                    $prepareNextHopMessage
                    mace::MaceAddr nextHopAddr = contextMapping.getNodeByContext( nextHop );
                    ASYNCDISPATCH( nextHopAddr , $adWrapperName, $ptype , nextmsg );
                }
            }else{
                // increment number of received messages from parent contexts.
                ABORT("multiple parent contexts is not supported yet");
            }
        }
    #;
    my $adReturnType = Mace::Compiler::Type->new(type=>"void",isConst=>0,isConst1=>0,isConst2=>0,isRef=>0);
    my $adParamType = Mace::Compiler::Type->new( type => "$ptype", isConst => 1,isRef => 1 );
    $$adMethod = Mace::Compiler::Method->new( name => $adName, body => $adBody, returnType=> $adReturnType);
    $$adMethod->push_params( Mace::Compiler::Param->new( name => "$async_upcall_param", type => $adParamType ) );

    my @adWrapperParam;
    my $adWrapperParamType = Mace::Compiler::Type->new( type => "void*", isConst => 0,isRef => 0 );
    push @adWrapperParam, Mace::Compiler::Param->new( name => "__param", type => $adWrapperParamType );
    my $adWrapperBody = qq/
        $ptype* __p = ($ptype*)__param;
        $adName ( *__p  );
        delete __p;
    /;

    $$adWrapperMethod = Mace::Compiler::Method->new( name => $adWrapperName, body => $adWrapperBody, returnType=> $adReturnType, params => @adWrapperParam);
}
sub createRealUpcallHandler {
    my $this = shift;
    my $message = shift;
    my $pname = shift;
    
    my $adMethod = shift;
    my $adWrapperMethod = shift;

    my $this_subs_name = (caller(0))[3];
    my $methodIdentifier = "[_a-zA-Z][_a-zA-Z0-9]*";
    my $upcall_param = "param";
    my $adWrapperName = $this->toWrapperName();
    my $adName = $this->toRealHandlerName();
    my @newMsg;
    foreach( $message->fields() ){
        given( $_->name ){
            when /^(__real_dest|__real_regid|__event|__msgcount)$/ { }
            default{ push @newMsg,  "${upcall_param}.$_->{name}"; }
        }
    }
    my $msgObj = join("", map{"," . $_ } @newMsg  );
    my $ptype = $message->name(); 
    my $adBody = qq#
        ASSERTMSG( contextMapping.getHead() == Util::getMaceAddr(), "This message is supposed to be received by the local head node. But this physical node is not head node.");
        // TODO: need to check that this message comes from one of the internal physical nodes.
        mace::AgentLock lock( mace::AgentLock::WRITE_MODE );
        {
            /*mace::string buf;
            mace::serialize(buf,&${upcall_param});
            mace::HierarchicalContextLock hl( he, buf );
            storeHeadLog(hl, he );*/
        }
        lock.downgrade( mace::AgentLock::NONE_MODE );

        ScopedLock sl( deliverMutex_$pname );
        deferred_queue_${pname}.insert( mace::pair<uint64_t, DeferralContainer_${pname} >( ${upcall_param}.__event, DeferralContainer_${pname}( ${upcall_param}.__real_dest $msgObj, ${upcall_param}.__real_regid ) )  );
        //    downcall_route( ${upcall_param}.__real_dest, $msgObj, ${upcall_param}.__real_regid);
    #;
    my $adReturnType = Mace::Compiler::Type->new(type=>"void",isConst=>0,isConst1=>0,isConst2=>0,isRef=>0);
    my $adParamType = Mace::Compiler::Type->new( type => "$ptype", isConst => 1,isRef => 1 );
    my @adParam;
    push @adParam, Mace::Compiler::Param->new( name => "$upcall_param", type => $adParamType );
    $$adMethod = Mace::Compiler::Method->new( name => $adName, body => $adBody, returnType=> $adReturnType, params => @adParam);

    my @adWrapperParam;
    my $adWrapperParamType = Mace::Compiler::Type->new( type => "void*", isConst => 0,isRef => 0 );
    push @adWrapperParam, Mace::Compiler::Param->new( name => "__param", type => $adWrapperParamType );
    my $adWrapperBody = qq/
        $ptype* __p = ($ptype*)__param;
        $adName ( *__p  );
        delete __p;
    /;

    $$adWrapperMethod = Mace::Compiler::Method->new( name => $adWrapperName, body => $adWrapperBody, returnType=> $adReturnType, params => @adWrapperParam);
}
sub createAsyncHelperMethod {
#chuangw: This subroutine creates helper method and demux method for the async transition
    my $this = shift;
    my $at = shift;
    my $hasContexts = shift;
    my $extra = shift;

    my $demuxMethod = shift; # output

    my $pname = $this->method->name;
    my $v = Mace::Compiler::Type->new('type'=>'void');
    $this->method->returnType($v);

    my $asyncMessageName = $this->toMessageTypeName( ); 
    my $adWrapperName = $this->toWrapperName(); 
#------------------------------------------------------------------------------------------------------------------
    # Generate async_foo helper method. The user uses this helper method to create an async transition.
    my $helpermethod = ref_clone($this->method);
    $helpermethod->name("async_$pname");

    my $contextToStringCode = $this->method->generateContextToString(snapshotcontexts=>1);

    my @extraParams;
    for ( $extra->fields() ){
        given( $_->name ){
            when "srcContextID" { push @extraParams, "currContextID"; }
            when "ticket" { push @extraParams, "0"; }
            when "seqno" { push @extraParams, "msgseqno"; }
            when "lastHop" { push @extraParams, "currContextID"; }
            when "nextHop" { push @extraParams, "ContextMapping::getHeadContext()";}
            when "visitedContexts" { push @extraParams, " mace::vector< mace::string >() ";}
            default  { push @extraParams, "$_->{name}"; }
        }
    }
    my @copyParams;
    if( defined $this->options('originalTransition') and $this->options('originalTransition') eq "upcall" ){
        my $fieldCount = 0;
        for my $atparam ($at->fields()){
            if( $fieldCount >= 2  ){
                if( $atparam->name eq "extra" ){
                    push @copyParams, "$atparam->{name}";
                }else{
                    my $origParam = @{ $this->method->params()}[2];
                    push @copyParams,  $origParam->name . ".$atparam->{name}";
                }
            }else{
                my $orig_param = $atparam->{name};
                $orig_param =~ s/^__//g;
                push @copyParams, $orig_param;
            }
            $fieldCount++;
        }
    }else{
        map {push @copyParams, "$_->{name}"}  $at->fields() ;
    }
    my $extraParam = "__asyncExtraField extra(" . join(", ", @extraParams) . ");";
    my $copyParam = join(", ", @copyParams);
    my $this_subs_name = (caller(0))[3];
    my $helperbody = qq#{
        // Generated by ${this_subs_name}() file: # . __FILE__ . qq# line: # . __LINE__ . qq#
        $contextToStringCode
        mace::string currContextID = ThreadStructure::getCurrentContext();
        
        // send a message to head node
        ScopedLock sl(mace::ContextBaseClass::__internal_ContextMutex );
        const MaceKey headNode( mace::ctxnode, contextMapping.getHead() );
        uint32_t msgseqno = 1; //getNextSeqno(ContextMapping::getHeadContext());
        $extraParam
        $asyncMessageName pcopy($copyParam );
        ASYNCDISPATCH( contextMapping.getHead(), $adWrapperName, $asyncMessageName, pcopy );
    }
    #;
    $helpermethod->body($helperbody);
    # chuangw: $demuxMethod is the demux method for this async transition.
    $$demuxMethod = ref_clone($this->method);
    $$demuxMethod->body("");
    return $helpermethod;
}
sub createTimerHelperMethod {
    my $this = shift;
    my $at = shift;
    my $hasContexts = shift;
    my $extra = shift;

    my $helperbody;
    my $pname = $this->method->name;
    my $v = Mace::Compiler::Type->new('type'=>'void');
    $this->method->returnType($v);
    # Generate timer helper method. This method is called when timer goes off.
    my $helpermethod = ref_clone($this->method);
    $helpermethod->name("scheduler_$pname");
    if ($this->method->targetContextObject() eq '__internal' ){
        my $v = Mace::Compiler::Type->new('type'=>'void');
        $helpermethod->returnType($v);
        my @paramArray;
        for my $atparam ($this->method->params()){
            push @paramArray, $atparam->name;
        }
        my $params = join(",", @paramArray);
        $helperbody = qq#
        expire_$pname($params);
        #;
        $helpermethod->body($helperbody);
        return $helpermethod;
    }
    # Generate auto-type for the method parameters.
    my $timerMessageName = $this->toMessageTypeName( );
    $this->options('originalTransition','scheduler');
#------------------------------------------------------------------------------------------------------------------
    my $contextToStringCode = $this->method->generateContextToString(snapshotcontexts=>1);

    my $this_subs_name = (caller(0))[3];
    my $helperBody = "// Generated by ${this_subs_name}() line: " . __LINE__;
    my @extraParams;

    my @copyParams;
    for ( $extra->fields() ){
        given( $_->name ){
            when "srcContextID" { push @extraParams, "currContextID"; }
            when "ticket" { push @extraParams, "0"; }
            when "seqno" { push @extraParams, "msgseqno"; }
            when "lastHop" { push @extraParams, "currContextID"; }
            when "nextHop" { push @extraParams, "ContextMapping::getHeadContext()";}
            when "visitedContexts" { push @extraParams, " mace::vector< mace::string >() ";}
            default  { push @extraParams, "$_->{name}"; }
        }
    }
    map {push @copyParams, "$_->{name}"; } $at->fields();
    my $extraParam = "__asyncExtraField extra(" . join(", ", @extraParams) . ");";
    my $copyParam = join(", ", @copyParams);
    my $adWrapperName = $this->toWrapperName();
    $helperbody = qq#{
        $contextToStringCode
        mace::string currContextID = targetContextID; //ThreadStructure::getCurrentContext();
        
        // send a message to head node
        ScopedLock sl(mace::ContextBaseClass::__internal_ContextMutex );
        uint32_t msgseqno = 1; //getNextSeqno(ContextMapping::getHeadContext());
        $extraParam
        $timerMessageName pcopy($copyParam );
        ASYNCDISPATCH( contextMapping.getHead(), $adWrapperName , $timerMessageName, pcopy );
    }
    #;
    $helpermethod->body($helperbody);
    return $helpermethod;
}
1;
