# 
# Transition.pm : part of the Mace toolkit for building distributed systems
# 
# Copyright (c) 2007, Charles Killian, James W. Anderson, Adolfo Rodriguez, Dejan Kostic
# All rights reserved.
# 
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
# 
#    * Redistributions of source code must retain the above copyright
#      notice, this list of conditions and the following disclaimer.
#    * Redistributions in binary form must reproduce the above copyright
#      notice, this list of conditions and the following disclaimer in
#      the documentation and/or other materials provided with the
#      distribution.
#    * Neither the names of Duke University nor The University of
#      California, San Diego, nor the names of the authors or contributors
#      may be used to endorse or promote products derived from
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
    );

sub toString {
    my $this = shift;
    my $s = $this->type()." ".$this->name()." [ guards : ";
    $s .= join(" && ", map { "(".$_->toString().")" } $this->guards());
    $s .= " ] ".$this->method()->toString(noline => 1);
    $s =~ s|\n||g;
    return $s;
} # toString

sub printGuardFunction {
  my $this = shift;
  my $handle = shift;
  my %arg = @_;
  my $methodprefix = $arg{methodprefix};
  my $transitionNum = $this->transitionNum();
  my $type = $this->type();
  my $routine = $this->method()->toString("noreturn" => 1, "novirtual" => 1, "paramconst" => 1, "methodconst" => 1, "methodprefix" => "bool ${methodprefix}guard_${type}_${transitionNum}_");

  my $guardString = '';
  my $guardStringEnd = <<END;
  return true;
END

  foreach my $guard ($this->guards()) {
    my $gs = $guard->toString('withline' => 1);
    $guardString .= <<END;
      if($gs) {
END
    $guardStringEnd .= <<END;
      }
END
  }

  print $handle <<END;
  $routine {
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

sub printTransitionFunction {
  my $this = shift;
  my $handle = shift;
#  my $selector = $this->method->options('selector');
  my $selectorVar = $this->method->options('selectorVar');
  my %args = @_;
  my $methodprefix = $args{methodprefix};
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

  my $lockingType = $this->getLockingType();
  my $read_state_variable = "// Locking type = ".$lockingType."\n";
  if( $lockingType == 0 )
  {
    $read_state_variable .= "// State variables are to be read\n";
    $read_state_variable .= $this->readStateVariable();
  }
# shyoo : uncomment when done.

  print $handle <<END;
  $routine {
    #define selector selector_$selectorVar
    #define selectorId selectorId_$selectorVar
    $prep
    ADD_LOG_BACKING
    $changeTracker
    $read_state_variable
    $body
    #undef selector
    #undef selectorId
  }
END
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

sub getLockingType {
    my $this = shift;
    if (defined($this->method()->options()->{locking})) {
      return $this->method()->options("locking");
    }
    return 1;       # shyoo: default locking mode is write.
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
  my $transitionNum = shift;
  my $selectors = shift;
  my $timerName = shift;
  $this->transitionNum($transitionNum);
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
    } elsif ($this->method()->options("locking") eq "off") {
        $this->method()->options("locking", -1);
    } else {
        my $l = $this->method()->options("locking");
        Mace::Compiler::Globals::error("bad_transition", $this->method()->filename(), $this->method()->line(),
                                       "Unrecognized method option for locking: $l.  Expected 'write|on|read|off'.");
    }
  }

  my $state = join("&&",map{"(".$_->toString('oneline'=>1).")"} $this->guards);
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

1;

