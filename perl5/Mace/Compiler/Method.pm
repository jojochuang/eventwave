# 
# Method.pm : part of the Mace toolkit for building distributed systems
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
package Mace::Compiler::Method;

use strict;
use Class::MakeMethods::Utility::Ref qw( ref_clone );

use Mace::Compiler::Param;
use Mace::Compiler::Type;
use Mace::Util qw(:all);

use Class::MakeMethods::Template::Hash 
    (
     'new' => 'new',
     'string' => "name",
     'object' => ["returnType" => { class => "Mace::Compiler::Type"}],
     'boolean' => "isVirtual",
     'boolean' => "isStatic",
     'boolean' => "isConst",
     'scalar' => "throw",
     'array_of_objects' => ["params" => { class => "Mace::Compiler::Param" }],
     'hash --get_set_items' => "options",
     'string' => "body",
     'number' => 'line',
     'string' => "filename",
     'boolean' => "doStructuredLog",
     'boolean' => "shouldLog",
     'string' => "logClause"
     );

sub setLogOpts {
    my $this = shift;
    my $slog = shift;
    my $clause = shift;
    
    $this->shouldLog($slog);
    if (defined($clause)) {
	$this->logClause($clause);
    }
}

sub shouldLogFunc {
    my $this = shift;
    my $binlogname = $this->options('binlogname');
    if (defined $binlogname) {
	my $prefix = "";
	my $suffix = " const";
	if ($this->isStatic()) {
	    $prefix = "static ";
	    $suffix = "";
	}
	return $prefix . "bool shouldLog_" . $binlogname . "(" . 
	    $this->paramsToString(noline=>1, nodefaults=>1) . ")" . $suffix . ";\n";
    }
    else {
	return "";
    }
}

sub shouldLogFuncBody {
    my $this = shift;
    my $prefix = shift;
    my $trace = shift;
    my $binlogname = $this->options('binlogname');
    my $suffix = " const";
    
    if (defined $binlogname) {
	if ($this->isStatic()) {
	    $suffix = "";
	}
	my $ret = "bool ${prefix}::shouldLog_" . $binlogname . "(" . 
	    $this->paramsToString(noline=>1, nodefaults=>1) . ")" . $suffix . " {\nreturn ";
	my $lc = $this->logClause();
	if ($lc ne "") {
	    $ret .= "$lc";
	}
	elsif ($this->shouldLog()) {
	    $ret .= "true";
	}
	else {
	    $ret .= "false";
	}
	$ret .= ";\n}\n";
	return $ret;
    }
    else {
	return "";
    }
}

sub toString {
#known accepted flags (passes through all):
#  novirtual
#  noreturn
#  methodprefix
#  rid
#  methodconst
#  prepare
#  body
#  noline
#  noid
#  notype
#  nodefaults
#  paramconst
#  paramref
#  initsel
    my $this = shift;
    my %args = @_;
    my $r = "";
    my $name = $this->name();
    if ($this->isStatic() && !$args{nostatic}) {
	$r .= "static ";
    }
    if (!$args{"novirtual"} && $this->isVirtual()) {
	$r .= "virtual ";
    }
    if (!$args{"noreturn"} && $this->returnType()->toString()) {
	$r .= $this->returnType()->toString() . " ";
    }
    if($args{"methodprefix"}) {
      $r .= $args{"methodprefix"};
    }
    if($args{"methodname"}) {
      $r .= $args{methodname};
      $name = $args{methodname};
    } else {
      if (defined $args{methodprefix} and not $args{methodprefix} =~ /::$/ ) {
        $r .= $this->squashedName();
      }
      else {
        $r .= $this->name() 
      }
    }
    $r .= "(";
    $r .= $this->paramsToString(%args);
    $r .= ")";
    if ($this->isConst() || $args{methodconst}) {
	$r .= " const";
    }
    if (defined $this->throw()) {
      $r .= " ".$this->throw();
    }
    my $string;

    if ($args{body} or $args{usebody}) {
        my $logLevel = $this->getLogLevel($args{traceLevel});
        $logLevel = 0 unless (defined $logLevel);
        my $minLogLevel = 1;

        my $lockingLevel = 1;

        if( defined ($args{locking}) ) {
            $lockingLevel = $args{locking};
        } else {
#            print STDERR "$name : Arg Level LOCKING=off\n";
            $lockingLevel = -1;
        }

        #my $lockingLevel = $this->getLockingLevel($args{locking}); # SHYOO : modified.
        #$lockingLevel = 1 unless (defined $lockingLevel); # SHYOO
        if (defined $this->options('minLogLevel')) {
            $minLogLevel = $this->options('minLogLevel');
        }

        if ($args{initsel} or $args{prepare} or $args{add_selectors} or $args{selectorVar} or $lockingLevel >= 0 or $args{fingerprint}) { # SHYOO
        #if ($args{initsel} or $args{prepare} or $args{add_selectors} or $args{selectorVar} or $args{locking} or $args{fingerprint}) {
            $r .= " { ";
        }
        if ($args{initsel} and $this->isStatic()) {
            $r .= "\n initializeSelectors(); \n";
        }
        my $setuplogging = 0;
        my $prep = "";
        if ($args{prepare}) {
            $prep .= "PREPARE_FUNCTION";
            if ($Mace::Compiler::Globals::MACE_TIME) {
                $prep = "MaceTime _curtime = 0;";
            }
        }
        if ($args{add_selectors}) {
            $setuplogging = 1;
            my $sel = $args{add_selectors};
            $prep .= qq/\nADD_SELECTORS("${sel}::${name}");\n/;
        }
        elsif ($args{selectorVar}) {
            $setuplogging = 2;
            my $selectorVar = $this->options('selectorVar');
            $prep .= qq{
              #define selector selector_$selectorVar
              #define selectorId selectorId_$selectorVar
              ADD_LOG_BACKING
            };
        }
        if ($lockingLevel >= 0) { # SHYOO
            $prep .= "mace::AgentLock __lock($lockingLevel);\n";
        }
	my $suffix = "";
	my $logName = $this->options('binlogname');
	my $paramList = $this->paramsToString(noline => 1,
					      notype => 1,
					      nodefaults => 1);
	
	if (defined ($logName) and not $args{nologs} and $logLevel >= $minLogLevel) {
	    $prep .= "bool __test = shouldLog_$logName($paramList);\n";
	    $suffix = "(__test)";
	}
#	else {
#	    $suffix = "(false)";
#	}
	
        ###if ($args{fingerprint} and $this->isConst()) {
        ###    $prep .= "mace::ScopedFingerprint __fingerprint(std::string(\"[const \") + selector + std::string(\"]\"));\n";
        ###}
        if ($args{fingerprint}) {
             $prep .= "mace::ScopedFingerprint __fingerprint(selector);\n";
	    
#	    if ($this->logClause() ne "") {

#${\$this->logClause()};\n";
#	    }
#	    elsif (!$this->shouldLog()) {
#		$suffix = "(false)";
#	    }
            $prep .= "mace::ScopedStackExecution __defer${suffix};\n";
            if ($logLevel > 2 and not $this->isConst()) {
                $prep .= "mace::ScopedStackExecution::addDefer(this);\n";
            }
        }
        if ($setuplogging and not $args{nologs}) {
            if ($logLevel >= $minLogLevel) {
                my $trace = $logLevel > 0 ? "true" : "false";
#		if (!$this->shouldLog()) {
#		    $trace = "false";
#		}
                my $traceg1 = $logLevel > 1 ? "true" : "false";
#		if ($args{fingerprint} and not $this->isConst()) {
#		if ($this->logClause() ne "") {
		if (defined ($logName)) {
		    $trace = "__test";
		}
#		    $prep .= "bool __test = ${\$this->logClause()};\n";
#		}
		$prep .= qq{\nScopedLog __scoped_log(selector, 0, selectorId->compiler, true, $traceg1, $trace && mace::LogicalClock::instance().shouldLogPath(), PIP);\n};
                my $fnName = $this->name();
		
                if ($args{binarylog} and 
#		    not $this->messageField() and 
		    $this->doStructuredLog()) {
# and $this->shouldLog()) {
                    my $paramlist = $this->paramsToString(noline => 1,
							  notype => 1,
							  nodefaults => 1);
		    if ($this->messageField()) {
			$paramlist = "";
		    }
                    my $binlogname = $this->options('binlogname');
		    $prep .= "if (mace::LogicalClock::instance().shouldLogPath()) {\n";
#		    if ($this->logClause() ne "") {
#			$prep .= "if ${\$this->logClause()} {\n";
			$prep .= "if ($trace) {\n";
#		    }
		    $prep .= "Log::binaryLog(selectorId->compiler, ${binlogname}Dummy($paramlist), 0); \n";
#		    if ($this->logClause() ne "") {
			$prep .= "}\n";
#		    }
		    $prep .= "}\n";
                } elsif (not $args{notextlog}) {
                    $prep .= qq/\nif(!macecompiler(0).isNoop()) {\n/;
                    $prep .= qq/macecompiler(0) << "$fnName(" /;
                    for my $p ($this->params()) {
                        my $pname = $p->name();
                        if (not $p->flags('message')) {
                            $prep .= qq/<< "[$pname=";
                                                                           mace::printItem(macecompiler(0), &$pname);
                                                                           macecompiler(0) << "]" /;
                        } elsif ($logLevel > 1) {
                            $prep .= qq/<< "[$pname=" << $pname << "]" /;
                        } else {
                            my $ptype = $p->type()->type();
                            $prep .= qq/<< "[$pname=$ptype]" /;
                        }
                    }
                    $prep .= qq/<< ")" << Log::endl;
                                                               }
                    /;
                }

            }
        }
        $r .= " \n$prep\n";
        if ($args{"body"}) {
            $r .= "\n" . $this->body();
        }
        elsif ($args{"usebody"}) {
            $r .= "\n" . $args{"usebody"};
        }
        if ($setuplogging == 2) {
            $r .= "
                   #undef selector
                   #undef selectorId
                  ";
        }
        #if ($args{initsel} or $args{prepare} or $args{add_selectors} or $args{selectorVar} or $args{locking} or $args{fingerprint}) {
        if ($args{initsel} or $args{prepare} or $args{add_selectors} or $args{selectorVar} or $lockingLevel >= 0 or $args{fingerprint}) { #SHYOO
            $r .= "\n}\n";
        }
    }
    return $r;
} # toString

sub matchedParams {
  my $this = shift;
  my $other = shift;

  my @p = $this->params();
  while(scalar(@p) > $other->count_params()) {
    pop(@p);
  }
  return @p;
}

sub paramsToString {
  my $this = shift;
  my %args = @_;
  my $r .= join(", ", map { $_->toString(%args) } $this->params());
  if ($args{"rid"}) {
    if ($this->count_params()) {
      $r .= ", ";
    }
    $r .= "registration_uid_t rid";
    $r .= " = -1" unless($args{nodefaults});
  }
  return $r;
}

sub optionsToString {
    my $this = shift;
    my $r = "[ ";
    while (my ($k, $v) = each(%{$this->options()}) ) {
	$r .= "$k=$v; ";
    }
    $r .= "]";
    return $r;
}

sub eq {
    my $this = shift;
    my $other = shift;
    my $regId = shift || 0;
    if ($this->name() ne $other->name()) {
	return 0;
    }
    my @p = $this->params();
    my @op = $other->params();
    if (scalar(@p) != scalar(@op)) {
        if($regId && scalar(@p) == scalar(@op)+1) {
          return $this->eqSub($other);
        } elsif($regId && scalar(@p)+1 == scalar(@op)) {
          return $other->eqSub($this);
        }
	return 0;
    }
    for my $i (0..(scalar(@p) - 1)) {
	if (not $p[$i]->eq($op[$i])) {
	    return 0;
	}
    }
    return 1;
} # eq

sub eqSub {
    my $this = shift;
    my $other = shift;
    my @p = $this->params();
    my @op = $other->params();
    return 0 unless($p[-1]->type->type eq "registration_uid_t");
    for my $i (0..(scalar(@p) - 2)) {
	if (not $p[$i]->eq($op[$i])) {
	    return 0;
	}
    }
    return 1;
} # eq

sub serialRemap {
#returns true if the remapping of this method replaces the original
  my $this = shift;
  for my $p ($this->params()) {
    return 1 if($p->typeSerial());
  }
  return 0;
} # serialRemap

sub messageField {
#returns true if the method contains a Message field
  my $this = shift;
  for my $p ($this->params()) {
    return 1 if($p->type()->type() eq "Message");
  }
  return 0;
}

sub getSerialForms {
  my $this = shift;
  my @messages = @_;

  my @r;
  my $t = ref_clone($this);
  $t->options('original', $this);
  push(@r, $t);
  my $i = 0;
  for my $p ($this->params()) {
    if($p->typeSerial()) {
      if($p->typeSerial()->type eq 'Message') {
        my @q;
        for my $m (@r) {
          for my $msg (@messages) {
            my $mc = ref_clone($m);
            $mc->params->[$i]->type(ref_clone($p->typeSerial));
            $mc->params->[$i]->type->type($msg);
            $mc->params->[$i]->flags('message', 1);
            $mc->params->[$i]->name($p->name."_deserialized");
            $mc->options('message', $msg);
            push(@q, $mc);
          }
        }
        @r = @q;
      } else {
        for my $m (@r) {
          $m->params->[$i]->type($p->typeSerial);
          $m->params->[$i]->name($p->name."_deserialized");
        }
      }
    }
    $i++;
  }
  return @r;
}

sub containsTransition {
  my $transMethod = shift;
  my @methods = @_;
  my $errMsg = "Matching method ".$transMethod->toString(noline => 1)." in a set of ".scalar(@methods)." methods\n";
  my $candidates_are = "candidates are: ";
  my $found = 0;
  for my $m (@methods) {
    if ($ENV{VERBOSE}) {
        $errMsg .= "note: $candidates_are ".$m->toString(noline => 1)."\n";
    }
    next unless ($transMethod->name() eq $m->name());
    unless ($ENV{VERBOSE}) {
        $errMsg .= "note: $candidates_are ".$m->toString(noline => 1)."\n";
    }
    next unless($transMethod->count_params() eq $m->count_params() || $transMethod->count_params() eq $m->count_params()-1);
    my $match = 1;
    for my $i (0..($transMethod->count_params()-1)) {
      if($transMethod->params()->[$i]->type() and not $transMethod->params()->[$i]->eq($m->params()->[$i])) {
        $errMsg .= "Match failed due to parameter -- found: [".$transMethod->params()->[$i]->toString(noline => 1)."] expected: [".$m->params()->[$i]->toString(noline => 1, nodefaults => 1)."]\n";
        $match = 0;
        last;
      }
    }
    if($transMethod->isConst() and not $m->isConst()) {
      $errMsg .= "Match failed due to const conflict -- method is declared const but candidate method is not\n";
      $match = 0;
    }
    next unless($match);
    if($transMethod->count_params() eq $m->count_params()-1) {
      next unless($m->params->[-1]->type()->type() eq 'registration_uid_t');
    }
    if($found == 0) {
      $found = $m;
    } else {
      $errMsg .= "Match failed due to ambiguity in which method to match\n[ambiguous match] ".$found->toString(noline=>1)."\n[ambigous match] ".$m->toString(noline=>1)."\n";
      $found = 0;
      last;
    }
  }
  if($found) {
    return $found;
  }
  $errMsg .= "No match found.\n";
  # SHYOO : list all method:
  for my $m (@methods) {
      $errMsg .= "  ".$m->toString(noline => 1)."\n";
  }
  return $errMsg;
} # containsTransition

sub squashedName() {
  my $this = shift;
  my $name = $this->name();
  $name =~ tr|-+=<>!*/|mpelgnsd|;
  return $name;
}

sub getParam() {
    my $this = shift;
    my $pName = shift;
    
    for my $p ($this->params()) {
	if ($p->name() =~ /^$pName$/i) {
	    return $p;
	}
    }
    return undef;
}

sub getLogLevel() {
  my $this = shift;
  my $def = shift;
  if (defined($this->options('trace'))) {
      return -1 if ($this->options('trace') eq "off");
      return  0 if ($this->options('trace') eq "manual");
      return  1 if ($this->options('trace') eq "low");
      return  2 if ($this->options('trace') eq "med");
      return  3 if ($this->options('trace') eq "high");
  }
  return $def;
}


sub print_r {
    my $hash = shift;
    my ($space, $newline, $delimiter) = @_;
    $space = "" unless (defined $space);
    $newline = "\n\n\n" unless (defined $newline);
    $delimiter = "\n--------------------------------------------" unless (defined $delimiter);
    my $str = "";

    for (sort keys %{$hash}) {
        my $value = $hash->{$_};
        $str .= "$newline$space$_ == $value$delimiter";
        $str .= recurseErrors($value,$space);
    }
    $str;
}

#------------------------------------------------------------------
sub recurseErrors {
    my $str;
    my ($value,$space) = @_;
    my $ref = ref $value;

    if ($ref eq 'ARRAY') {
        my $i = 0;
        my $isEmpty = 1;
        my @array = @$value;
        $space .= "\t";
        for my $a (@array) {
            if (defined $a) {
                $isEmpty = 0;
                $str = "";
                $str .= "\n$space$_\[$i\] :";
                $str .= recurseErrors($a,$space);
            }
            $i++;
        }
        $str .= "= { }" if ($isEmpty);

    } elsif ($ref eq 'HASH') {
        $space .= "\t";
        for my $k (sort keys %$value) {
            if ( ( ref($value->{$k}) eq 'HASH') || (ref $value->{$k} eq 'ARRAY') ) {
                my $val = $value->{$k};
                $str .= "\n\n$space$k == ";
                $str .= "$val";
            }
            else {
                $str .= "\n$space$k == ";
            }
            $str .= recurseErrors($value->{$k},$space);
      }

      # we have reached a scalar (leaf)
    } elsif ($ref eq '') {
        $str .= "$value";
    }
$str
}
#------------------------------------------------------------------



1;
