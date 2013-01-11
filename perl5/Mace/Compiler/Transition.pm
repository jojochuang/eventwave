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
use v5.10.1;
use feature 'switch';

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
use Data::Dumper;
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
    #for my $var ($service_impl->state_variables()) 
    my $contextString = "(*globalContext)";
    my $alias = "global";
    my $currentContext = ${ $service_impl->contexts() }[0];
    push( @declares, "const $currentContext->{className}& $alias __attribute((unused)) = $contextString.getSnapshot();");
    for my $var ( $currentContext->ContextVariables() ) 
    {
      my $t_name = $var->name();
      my $t_type = $var->type()->toString(paramref => 1);

      next if( $t_name =~ m/^__internal_/ );


      if (!$this->method()->isUsedVariablesParsed()) {
        # If default parser is used since incontext parser failed, include every variable.
        #if( $Mace::Compiler::Globals::useSnapshot ) {
          #push(@declares, "const ${t_type} ${t_name} __attribute((unused)) = read_${t_name}();");
          push(@declares, "const ${t_type} ${t_name} __attribute((unused)) = $alias.${t_name};");
        #}
      } else { # If InContext parser is used, selectively include variable.
        if(grep $_ eq $t_name, @usedVar) {
          push(@declares, "const ${t_type} ${t_name} __attribute((unused)) = $alias.${t_name};");
        } else {
          push(@declares, "// const ${t_type} ${t_name} = $contextString.${t_name};");
        }
      }
    }

    if (!$this->method()->isUsedVariablesParsed()) {
      # If default parser is used since incontext parser failed, include every variable.
      #if( $Mace::Compiler::Globals::useSnapshot ) {
        #push(@declares, "const state_type& state __attribute((unused)) = read_state();");
      #}
    } else { # If InContext parser is used, selectively include variable.
      if(grep $_ eq "state", @usedVar) {
        #push(@declares, "const state_type& state __attribute((unused)) = read_state();");
      } else {
        #push(@declares, "// const state_type& state = read_state();");
      }
    }
  }else{ # $locking != 0
    #if( $this->count_guards() > 0 ){
    #}
    my $nonemptyGuards = 0;
    foreach my $guard ($this->guards() ) {
      $nonemptyGuards = 1 if($guard->type eq "state_expr" and $guard->state_expr->type ne "null" );
    }
    if( $nonemptyGuards == 1 ){
      push(@declares, $this->contextVariablesAlias() );
    }
    #print $this->method->toString(noline=>1) . "--->guard: " . Dumper( $this->guards() ) . "\n";
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

    my $ctx = $this->method->targetContextObject;
  print $handle <<END;
  $routine {
    #define selector selector_$selectorVar
    #define selectorId selectorId_$selectorVar
    $prep
    ADD_LOG_BACKING
    $changeTracker
    //__printTransitionFunction__ $ctx
    $read_state_variable
    $contextAlias
    $body
    #undef selector
    #undef selectorId
  }
END
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
        when (/(async|scheduler)/) {return "__async_at${uniqid}_$pname" }
        when ("upcall") {
            my $ptype = ${ $this->method->params }[2]->type->type;
            #return "__deliver_at${uniqid}_$ptype"; 
            return "__deliver_at_$ptype"; 
        }
        when ("downcall") { }
    }
}

sub toWrapperName {
    my $this = shift;

    my $uniqid = $this->transitionNum;
    my $pname = $this->method->name;
    given( $this->type() ){
        when (/(async|scheduler)/) {return "__async_wrapper_fn${uniqid}_$pname" }
        when ("downcall") { }
    }
}

sub toRealHeadHandlerName {
    my $this = shift;

    my $uniqid = $this->transitionNum;
    my $pname = $this->method->name;
    given( $this->type() ){
        when (/(async|scheduler)/) {return "__async_head_fn${uniqid}_$pname" }
#        when "upcall" {
#            my $ptype = ${ $this->method->params }[2]->type->type;
#            return "__deliver_fn_$ptype";
#        }
        when ("downcall") { }
    }
}
sub toRealHandlerName {
    my $this = shift;

    my $uniqid = $this->transitionNum;
    my $pname = $this->method->name;
    given( $this->type() ){
        when (/(async|scheduler)/) {return "__async_fn${uniqid}_$pname" }
#        when "upcall" {
#            my $ptype = ${ $this->method->params }[2]->type->type;
#            return "__deliver_fn_$ptype";
#        }
        when ("downcall") { }
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
=begin
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
=cut

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
      if ($k =~ m/^(message|timer|transitions|monitor|originalTransition|originalTransportDeliverMessage)$/) {
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
sub createRealAsyncHeadHandler {
    my $this = shift;
    my $message = shift;
    my $name = shift;
    my $extra = shift;

    my $adMethod = shift; #output

    my $pname = $this->method->name();
    my $ptype = $message->name(); 
    my $this_subs_name = (caller(0))[3];
    my $messageName = $message->name();
    my $adName = $this->toRealHandlerName();
    my $adHeadName = $this->toRealHeadHandlerName();
    my $async_upcall_param = "param";

    if( not defined $extra ){
        Mace::Compiler::Globals::error("bad_message", __FILE__, __LINE__, "can't find the auto-generated autotype '__asyncExtraField'");
        return;
    }
    my @origParams;
    for my $param ($message->fields()) {
        given( $param->name ){
            when ("extra") { push @origParams, "newExtra"; }
            default { push @origParams, "$async_upcall_param ->" . $_; }
        }
    }
    my $headMessage = "$ptype pcopy(" . join(",", @origParams) . ");";
#--------------------------------------------------------------------------------------
    my @nextHopMsgParams;
    my @nextExtraParams;

    foreach( $message->fields() ){
        given( $_->name ){
            when ("extra") { push @nextHopMsgParams, "nextExtra"; }
            default { push @nextHopMsgParams,  "$async_upcall_param.$_"; }
        }
    }
    my $nextHopMessage = join(", ", @nextHopMsgParams);
#--------------------------------------------------------------------------------------
    my @asyncMethodParams;
    my $startAsyncMethod;
    my $eventType = "";
    if( defined $this->options('originalTransition') ){
        if( $this->options('originalTransition') eq "scheduler" ){
            $eventType = "TIMEREVENT";
        }elsif( $this->options('originalTransition') eq "upcall" ){
            $eventType = "UPCALLEVENT";
        }
    }else{
        $eventType = "ASYNCEVENT";
    }
#--------------------------------------------------------------------------------------
    my $adBody = "// Generated by ${this_subs_name}() line: " . __LINE__ . qq#
      $messageName *$async_upcall_param = ($messageName*)p;
      ASSERTMSG( $async_upcall_param ->extra.isRequest == true, "Not head!" );

      if( mace::HighLevelEvent::isExit ) {
        mace::AgentLock::nullTicket();
        return;
      }
      asyncHead( *$async_upcall_param, $async_upcall_param ->extra, mace::HighLevelEvent::$eventType );
      __asyncExtraField newExtra( $async_upcall_param ->extra.targetContextID, $async_upcall_param ->extra.snapshotContextIDs, ThreadStructure::myEvent(), false ) ;
      $headMessage
      ASYNCDISPATCH( contextMapping.getNodeByContext( $async_upcall_param ->extra.targetContextID ) , __ctx_dispatcher, $ptype , pcopy );

      delete $async_upcall_param;
    #;
    my $adReturnType = Mace::Compiler::Type->new(type=>"void",isConst=>0,isConst1=>0,isConst2=>0,isRef=>0);
    my $adParamType = Mace::Compiler::Type->new( type => "void*", isConst => 0,isRef => 0 );
    $$adMethod = Mace::Compiler::Method->new( name => $adHeadName, body => $adBody, returnType=> $adReturnType);
    $$adMethod->push_params( Mace::Compiler::Param->new( name => "p", type => $adParamType ) );

}
sub createRealAsyncHandler {
    my $this = shift;
    my $message = shift;
    my $name = shift;
    my $extra = shift;

    my $adMethod = shift; #output
    my $adHeadName = $this->toRealHeadHandlerName();

    my $pname = $this->method->name();
    my $ptype = $message->name(); 
    my $this_subs_name = (caller(0))[3];
    my $messageName = $message->name();
    my $adName = $this->toRealHandlerName();
    my $async_upcall_param = "param";

    if( not defined $extra ){
        Mace::Compiler::Globals::error("bad_message", __FILE__, __LINE__, "can't find the auto-generated autotype '__asyncExtraField'");
        return;
    }

    my @origParams;
    for my $param ($message->fields()) {
        given( $param->name ){
            when ("extra") { push @origParams, "newExtra"; }
            default { push @origParams, "$async_upcall_param." . $_; }
        }
    }
    my $headMessage = "$ptype hmcopy(" . join(",", @origParams) . ");";
#--------------------------------------------------------------------------------------
    my @nextHopMsgParams;
    my @nextExtraParams;

    foreach( $message->fields() ){
        given( $_->name ){
            when ("extra") { push @nextHopMsgParams, "nextExtra"; }
            default { push @nextHopMsgParams,  "$async_upcall_param.$_"; }
        }
    }
    my $nextHopMessage = join(", ", @nextHopMsgParams);
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
            my $origUpcallMessage = $this->options('originalTransportDeliverMessage');
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
    my $adBody = "// Generated by ${this_subs_name}() line: " . __LINE__ . qq#
      if( $async_upcall_param.extra.isRequest == true ){
          if( mace::HighLevelEvent::isExit ) {
            mace::AgentLock::nullTicket();
            return;
          }

          HeadEventDispatch::HeadEventTP::executeEvent( this, (HeadEventDispatch::eventfunc)&${name}_namespace::${name}Service::$adHeadName, (void*) new $ptype($async_upcall_param) );
          return;
      }
      mace::AgentLock::nullTicket();
  
      mace::ContextBaseClass * thisContext = getContextObjByName( $async_upcall_param.extra.targetContextID );
      ThreadStructure::setMyContext( thisContext );

      ThreadStructure::setEvent( $async_upcall_param.extra.event );

      ThreadStructure::ScopedServiceInstance si( instanceUniqueID ); 
      ThreadStructure::ScopedContextID sc( $async_upcall_param.extra.targetContextID );
      ThreadStructure::insertEventContext( $async_upcall_param.extra.targetContextID );
      asyncPrep($async_upcall_param.extra.targetContextID,   $async_upcall_param.extra.snapshotContextIDs);
      mace::ContextLock __contextLock( *thisContext, mace::ContextLock::WRITE_MODE); // acquire context lock. 
      $startAsyncMethod 
      asyncFinish( );// after the prev. call finishes, do distribute-collect
    #;
    my $adReturnType = Mace::Compiler::Type->new(type=>"void",isConst=>0,isConst1=>0,isConst2=>0,isRef=>0);
    my $adParamType = Mace::Compiler::Type->new( type => "$ptype", isConst => 1,isRef => 1 );
    my $adParamType2 = Mace::Compiler::Type->new( type => "MaceAddr", isConst => 1,isRef => 1 );
    $$adMethod = Mace::Compiler::Method->new( name => $adName, body => $adBody, returnType=> $adReturnType);
    $$adMethod->push_params( Mace::Compiler::Param->new( name => "$async_upcall_param", type => $adParamType ) );
    $$adMethod->push_params( Mace::Compiler::Param->new( name => "source", type => $adParamType2 ) );

}
sub createAsyncHelperMethod {
#chuangw: This subroutine creates helper method and demux method for the async transition
    my $this = shift;
    my $at = shift;
    my $extra = shift;

    my $demuxMethod = shift; # output
    my $helpermethod = shift; # output

    my $pname = $this->method->name;
    # It is needed to specify the return type of async transition method's, because compiler doesn't know it from matching interface specification.
    $this->method->returnType(  Mace::Compiler::Type->new('type'=>'void') );
    my $asyncMessageName = $this->toMessageTypeName( ); 

    # chuangw: $demuxMethod is the demux method for this async transition.
    $$demuxMethod = ref_clone($this->method);
    # TODO: remove the guard function of demuxMethod 
    $$demuxMethod->body("");
    if( defined $this->options('originalTransition') and $this->options('originalTransition') eq "upcall" ){
      # compiler generated async transition does not need async_foo() helper function.
      return;
    }

#------------------------------------------------------------------------------------------------------------------
    # Generate async_foo helper method. The user uses this helper method to create an async event
    $$helpermethod = ref_clone($this->method);
    $$helpermethod->validateLocking( );
    $$helpermethod->name("async_$pname");

    my $contextToStringCode = $this->method->generateContextToString(snapshotcontexts=>1);

    my @extraParams;
    for ( $extra->fields() ){
        given( $_->name ){
            when ("srcContextID") { push @extraParams, "currContextID"; }
            when ("event") { push @extraParams, "he"; }
            when ("lastHop") { push @extraParams, "currContextID"; }
            when ("isRequest") { push @extraParams, "true";}
            when ("visitedContexts") { push @extraParams, " mace::vector< mace::string >() ";}
            default  { push @extraParams, "$_"; }
        }
    }
    my @copyParams;
    map {push @copyParams, "$_->{name}"}  $at->fields() ;
    my $extraParam = "
    __asyncExtraField extra(" . join(", ", @extraParams) . ");";
    my $copyParam = join(", ", @copyParams);
    my $this_subs_name = (caller(0))[3];
    my $helperbody = qq#{
        // Generated by ${this_subs_name}() file: # . __FILE__ . qq# line: # . __LINE__ . qq#
        $contextToStringCode
        mace::HighLevelEvent he(  ThreadStructure::myEvent().getEventID() );
        $extraParam
        $asyncMessageName pcopy($copyParam );
        // send a message to head node to create an event
        static const bool no_payload = params::get<bool>("EVENTREQ_PAYLOAD", false );
        if( no_payload ){
          requestNewEvent( extra, pcopy );
        }else{
          ASYNCDISPATCH( contextMapping.getHead(), __ctx_dispatcher, $asyncMessageName, pcopy );
        }
    }
    #;
    $$helpermethod->body($helperbody);
}
sub createTimerHelperMethod {
    my $this = shift;
    my $at = shift;
    my $extra = shift;

    my $helperbody;
    my $pname = $this->method->name;
    my $v = Mace::Compiler::Type->new('type'=>'void');
    $this->method->returnType($v);
    # Generate timer helper method. This method is called when timer goes off.
    my $helpermethod = ref_clone($this->method);
    $helpermethod->validateLocking();
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
            when ("event") { push @extraParams, "dummyEvent"; }
            when ("isRequest") { push @extraParams, "true";}
            default  { push @extraParams, "$_"; }
        }
    }
    map {push @copyParams, "$_->{name}"; } $at->fields();
    my $extraParam = "__asyncExtraField extra(" . join(", ", @extraParams) . ");";
    my $copyParam = join(", ", @copyParams);
    $helperbody = qq#{
        $contextToStringCode
        
        // send a message to head node
        mace::HighLevelEvent dummyEvent( ThreadStructure::myEvent().getEventID() );
        $extraParam
        $timerMessageName pcopy($copyParam );
        ASYNCDISPATCH( contextMapping.getHead(), __ctx_dispatcher , $timerMessageName, pcopy );
    }
    #;
    $helpermethod->body($helperbody);
    return $helpermethod;
}
1;
