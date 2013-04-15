# 
# Method.pm : part of the Mace toolkit for building distributed systems
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
package Mace::Compiler::Method;

use strict;
use Class::MakeMethods::Utility::Ref qw( ref_clone );

use Mace::Compiler::Param;
use Mace::Compiler::Type;
use Mace::Compiler::AutoType;
use Mace::Util qw(:all);
use v5.10.1;
use feature 'switch';


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
     'string' => "logClause",
     'boolean' => 'isUsedVariablesParsed',
     'array' => "usedStateVariables",
     'string' => "targetContextObject", 
     'hash' => "snapshotContextObjects"
     );
#my $regexIdentifier = "[_a-zA-Z][a-zA-Z0-9_.]*";
my $regexIdentifier = "[_a-zA-Z][_a-zA-Z0-9.\(\)]*";

sub validateLocking {
    my $this = shift;
        #if( $this->name eq "make_routing_decision" ){
        #my $x;
        #print $x;
        #}
  if (defined($this->options()->{locking})) {
        # chuangw: force to print traceback
    #print $this->name . ": " . $this->options("locking") . "\n";
    if ($this->options("locking") eq "on") {
        $this->options("locking", 1);
    } elsif ($this->options("locking") eq "write") {
        $this->options("locking", 1);
    } elsif ($this->options("locking") eq "global") {
        $this->options("locking", 1);
    } elsif ($this->options("locking") eq "read") {
        $this->options("locking", 0);
    } elsif ($this->options("locking") eq "anonymous") {
        $this->options("locking", 0);
    } elsif ($this->options("locking") eq "anon") {
        $this->options("locking", 0);
    } elsif ($this->options("locking") eq "none") {
        $this->options("locking", -1);
    } elsif ($this->options("locking") eq "null") {
        $this->options("locking", -1);
    } elsif ($this->options("locking") eq "off") {
        $this->options("locking", -1);
    } else {
        my $l = $this->options("locking");
        Mace::Compiler::Globals::error("bad_routine", $this->filename(), $this->line(),
                                       "Unrecognized method option for locking: $l.  Expected 'write|on|read|off'.");
    }
  }#else{
   # print $this->name . " has no locking defined \n";
  #}
}

sub validate {
    my $this = shift;
    my $contexts = shift;

    given( $this->targetContextObject() ){
        when (/^(__internal|__anon|__null)$/) {}
        default { $this->validateContext($this->targetContextObject(),  $contexts   ); }
    }
    foreach my $ctx  ( keys %{ $this->snapshotContextObjects()} ) {
        $this->validateContext($ctx,  $contexts  );
    }
    $this->validateLocking();
}

sub validateContext {
    my $this = shift;
    my $contextID = shift;
    my $globalContext = shift;

    my @contextScope= split(/::/, $contextID );
    my $currentContextName = "";
    my $currentContext = $globalContext;
    while( defined (my $contextID = shift @contextScope)  ){
        for ($currentContext->subcontexts() ) {
            if( $_->name() eq $currentContextName ){
                $currentContext = $_;
                last;
            }
        }
        if( not defined( $currentContext) ){
            Mace::Compiler::Globals::error("bad_context", $this->filename(), $this->line(), "Context '$currentContextName' not found.");
            return;
        }
        if ( $currentContext->isArray() ){
            if( scalar ( @{ $currentContext->{keyType} } ) == 1 and $contextID =~ /($regexIdentifier)<($regexIdentifier)>/ ) {
                $currentContextName = $1;
            } elsif (scalar ( @{ $currentContext->{keyType} } ) > 1 and $contextID =~ /($regexIdentifier)<([^>]+)>/) {
                $currentContextName = $1;
            }else{
                Mace::Compiler::Globals::error("bad_context", $this->filename(), $this->line(), "Context '$currentContextName' was declared as array, but is not desginated correctly.");
                return;
            }
        }else{
            if( $contextID =~ /($regexIdentifier)/ ) {
                $currentContextName = $contextID;
            }else{
                Mace::Compiler::Globals::error("bad_context", $this->filename(), $this->line(), "Context '$contextID' was declared to be single, non-array, but is designated as context array here.");
                return;
            }
        }
    }
}

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

        if( defined ($this->options('locking')) ) {
            $lockingLevel = $this->options('locking');
        }

        if( defined ($args{locking}) ) {
            $lockingLevel = $args{locking};
            #print STDERR "[Method.pm toString()]                    ".$this->name()."  locking = ".$args{locking}."\n";
        } else {
            $lockingLevel = -1;   # Note: -1 means it will not provide locking mechanism. (AgentLock)
        }

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


        if ($args{initsel} or $args{prepare} or $args{add_selectors} or $args{selectorVar} or $args{locking} or $args{fingerprint}) { #SHYOO
          $r .= "\n" . "// Method.pm:toString()\n";
          $r .= "\n" . "__eventContextType = ".$lockingLevel.";\n";
        }

        my $suffix = "";
        my $logName = $this->options('binlogname');
        my $paramList = $this->paramsToString(noline => 1, notype => 1, nodefaults => 1);
	
	if (defined ($logName) and not $args{nologs} and $logLevel >= $minLogLevel) {
	    $prep .= "bool __test = shouldLog_$logName($paramList);\n";
	    $suffix = "(__test)";
	}
	
        if ($args{fingerprint}) {
            $prep .= "mace::ScopedFingerprint __fingerprint(selector);\n";
	    
            $prep .= "mace::ScopedStackExecution __defer${suffix};\n";
            if ($logLevel > 2 and not $this->isConst()) {
                $prep .= "mace::ScopedStackExecution::addDefer(this);\n";
            }
        }
        if ($setuplogging and not $args{nologs}) {
            #print $this->name . " logLevel = $logLevel , minLogLevel = $minLogLevel \n";
            if ($logLevel >= $minLogLevel) {
                my $trace = $logLevel > 0 ? "true" : "false";
                my $traceg1 = $logLevel > 1 ? "true" : "false";
                if (defined ($logName)) {
                    $trace = "__test";
                }
                $prep .= qq{\nScopedLog __scoped_log(selector, 0, selectorId->compiler, true, $traceg1, $trace && mace::LogicalClock::instance().shouldLogPath(), PIP);\n};
                my $fnName = $this->name();
		
                if ($args{binarylog} and $this->doStructuredLog()) {
                    my $paramlist = $this->paramsToString(noline => 1, notype => 1, nodefaults => 1);
                    if ($this->messageField()) {
                        $paramlist = "";
                    }
                    my $binlogname = $this->options('binlogname');
                    $prep .= qq/
                        if (mace::LogicalClock::instance().shouldLogPath()) {
                            if ($trace) {
                                Log::binaryLog(selectorId->compiler, ${binlogname}Dummy($paramlist), 0); 
                            }
                        }
                    /;
               } elsif (not $args{notextlog}) {
                    $prep .= qq/\nif(!macecompiler(0).isNoop()) {\n/;
                    $prep .= qq/macecompiler(0) << "$fnName(" /;
                    for my $p ($this->params()) {
                        my $pname = $p->name();
                        if (not $p->flags('message')) {
                    		$prep .= qq/<< "[$pname=";
                                            mace::printItem(macecompiler(0), &$pname);
                                            macecompiler(0) << "]" 
                                            /;
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

        # Note : Here starts Method toString()
        #        Demux functions are generated here.
        $r .= qq#
        // Method.pm:toString().
        // If this is a downcall_ demux function, refer ServiceImpl.pm:demuxMethod().
        // For locking, refer ServiceImpl.pm:checkTransitionLocking() and Transition.pm:getLockingType().#;

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

use Data::Dumper;
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
      $errMsg .= "Match failed due to ambiguity in which method to match\n[ambiguous match] ".$found->toString(noline=>1)."\n[ambiguous match] ".$m->toString(noline=>1)."\n";
      $found = 0;
      last;
    }
  }
  if($found) {
    return $found;
  }
  $errMsg .= "No match found.\n";
  # shyoo : list all method:
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

# getContextClass : return classname for given context ID
sub getContextClass{
    my $this = shift;
    my $origContextID = shift;

    my $origContextClass;
    my @contextNameArray;
		
    my @contextScope= split(/::/, $origContextID);
    foreach (@contextScope) {
      if ( $_ =~ /($regexIdentifier)<($regexIdentifier)>/ ) {
          $origContextClass = $1;
      } elsif ($_ =~ /($regexIdentifier)<([^>]+)>/) {
          $origContextClass = $1;
      } elsif ( $_ =~ /($regexIdentifier)/ ) {
          $origContextClass = $1;
      }
    }
    my $contextClass = "__${origContextClass}__Context";

    return $contextClass;
}

sub getContextNameMapping {
    my $this = shift;
    my $origContextID = shift;

    my $ref_match_params;

    my $x = @_;
    $ref_match_params = shift;

    my @contextNameMapping;
    my @contextScope= split(/::/, $origContextID);
    foreach (@contextScope) {
      	if ( $_ =~ /($regexIdentifier)<($regexIdentifier)>/ ) {
          	# check if $1 is a valid context name
                # and if $2 is a valid context mapping key variable.
            my $after_match = $2;
            if( defined $ref_match_params ){
              #print "matched terms passed in\n";
              while (my ($mkey, $mval) = each( %{ $ref_match_params } ) ){
                #my $mval = $ref_match_params->{ $mkey };
                #print "$mkey -> $mval\n";
                $after_match =~ s/\b$mval\b/$mkey/g;
              }
            }
          	push @contextNameMapping, qq# "${1}\[" << $after_match << "\]"#;
        } elsif ($_ =~ /($regexIdentifier)<([^>]+)>/) {
            my $after_match = $2;
            if( defined $ref_match_params ){
              #print "matched terms passed in\n";
              foreach my $mkey ( %{ $ref_match_params } ){
                my $mval = ${ $ref_match_params }[ $mkey ];
                #print "$mkey -> $mval\n";
                $after_match =~ s/$mkey/$mval/g;
              }
            }
            my @contextParam = split("," , $after_match);
            push @contextNameMapping ,qq# "${1}\[" << __$1__Context__param(# . join(",", @contextParam)  . qq#) << "\]"#;
      	} elsif ( $_ =~ /($regexIdentifier)/ ) {
          	push @contextNameMapping, qq# "$1"#;
        }
    }
    return @contextNameMapping;
}

sub targetContextToString {
    my $this= shift;
    my $ref_match_params = shift;
    #print $ref_match_params . "\n";
    return $this->getContextNameMapping($this->targetContextObject(), $ref_match_params );
}

sub snapshotContextToString {
    my $this = shift;
    my $ref_array = shift;
    while( my( $snapshotContextID,  $alias) = each( %{$this->snapshotContextObjects()}) ){
        my @tempContextNameArray = $this->getContextNameMapping($snapshotContextID);
        push @{ $ref_array },  qq/
          std::ostringstream oss;
          oss<</ . join(qq/ << "." << /, @tempContextNameArray);
    }
}

sub generateContextToStringRoutine {
    my $this = shift;
    my %args = @_;

    my $targetContextNameMapping = "";
    if( $this->targetContextObject() ){
      $targetContextNameMapping = "oss<<" . join(qq/ << "." << /, $this->targetContextToString() ) . ";\n";
    }

    my $snapshotContextsName = "";
    if( keys( %{$this->snapshotContextObjects()}) > 0 ){
      #TODO: chuangw: if the routine does not use snapshot contexts, no need to declare extra unused variables/message fields.
      my @snapshotContextNameArray;
      $this->snapshotContextToString( \@snapshotContextNameArray );
      $snapshotContextsName = join("\n", map{ qq#{ $_;\nsnapshotContextNames.push_back( oss.str() );\n}# }  @snapshotContextNameArray );
    }
    return 
     qq/mace::vector< mace::string > snapshotContextNames;
        std::ostringstream oss;
        $targetContextNameMapping
        const mace::string targetContextName = oss.str();
        $snapshotContextsName/;
}
sub generateContextToString {
    my $this = shift;

    my $ref_matched_params;
    $ref_matched_params = shift;

    my $snapshotContextsNameMapping = qq/mace::set<mace::string> snapshotContextIDs;/;
    if( keys( %{$this->snapshotContextObjects()}) > 0 ){
        #TODO: chuangw: if the routine does not use snapshot contexts, no need to declare extra unused variables/message fields.
        my @snapshotContextNameArray;
        $this->snapshotContextToString( \@snapshotContextNameArray );
        $snapshotContextsNameMapping .= join("\n", map{ qq#{ $_; snapshotContextIDs.insert( oss.str() ); }# }  @snapshotContextNameArray );
    }
    my $targetContextNameMapping = "";
    if( $this->targetContextObject() ){
      $targetContextNameMapping .= "oss<<" . join(qq/ << "." << /, $this->targetContextToString($ref_matched_params) ) . ";\n";
    }
    return qq/
        std::ostringstream oss; 
        $targetContextNameMapping
        mace::string targetContextID = oss.str();
        $snapshotContextsNameMapping/;
}
sub createContextRoutineMessage {
    my $this = shift;
    my $messageType = shift;
    my $atref = shift;
    my $routineMessageName = shift;

    my $method_type;
    given ( $messageType ){
      when ("routine") { $method_type = Mace::Compiler::AutoType::FLAG_SYNC; }
      when ("downcall") { $method_type = Mace::Compiler::AutoType::FLAG_DOWNCALL; }
      when ("upcall") { $method_type = Mace::Compiler::AutoType::FLAG_UPCALL; }
    }

    $$atref = Mace::Compiler::AutoType->new(name=> $routineMessageName, line=>$this->line(), filename => $this->filename(), method_type=> $method_type );
    my $at = $$atref;
    # bsang:
    # Add one extra field: 'context' of mace::string type
    # Add three params for this AutoType: source context id,  destination context id,  return value type of this synchronized call
    my $contextIDType = Mace::Compiler::Type->new(type=>"uint32_t",isConst=>0,isConst1=>0,isConst2=>0,isRef=>0);
    my $snapshotContextIDType = Mace::Compiler::Type->new(type=>"mace::vector<uint32_t>",isConst=>0,isConst1=>0,isConst2=>0,isRef=>0);
    my $eventType = Mace::Compiler::Type->new(type=>"mace::Event",isConst=>0,isConst1=>0,isConst2=>0,isRef=>0);

    my $targetContextField = Mace::Compiler::Param->new(name=>"targetContextID", type=>$contextIDType);
    my $snapshotContextField = Mace::Compiler::Param->new(name=>"snapshotContextIDs", type=>$snapshotContextIDType);

    my $eventField = Mace::Compiler::Param->new(name=>"event",  type=>$eventType);
    $at->fields( ($targetContextField, $eventField ) );
    if( keys( %{$this->snapshotContextObjects} ) > 0 ){
        #chuangw: if the routine does not use snapshot contexts, no need to declare extra unused variables/message fields.
        $at->push_fields($snapshotContextField);
    }
    for my $op ($this->params()) {
        my $p= ref_clone($op);
        if( defined $p->type ){
            $p->type->isConst(0);
            $p->type->isConst1(0);
            $p->type->isConst2(0);
            $p->type->isRef(0);
            $at->push_fields($p);
        }
    }
    $at->options('routine', $this );
}
sub createApplicationUpcallInternalMessage {
    my $origmethod  = shift;
    my $mnumber = shift;

    my $at = Mace::Compiler::AutoType->new(name=> "__appupcall_at${mnumber}_" . $origmethod->name , line=> $origmethod->line() , filename => $origmethod->filename() , method_type=>Mace::Compiler::AutoType::FLAG_APPUPCALL);
    # need the event id of the event which initiates upcall transition
    my $eventIDType = Mace::Compiler::Type->new(type => "uint64_t" );
    my $eventIDField = Mace::Compiler::Param->new(name=> "__eventID" , filename=> $origmethod->filename, line=> $origmethod->line , type=>$eventIDType);
    $at->push_fields( ($eventIDField ) );

    foreach( $origmethod->params() ){
        my $p = ref_clone( $_ );
        $p->type->isConst(0);
        $p->type->isConst1(0);
        $p->type->isConst2(0);
        $p->type->isRef(0);
        $at->push_fields( $p );
    }
    return $at;
=begin
    if ( $this->hasContexts() ){
        $this->push_messages( $at );
    }else{
      my $serializeOption = Mace::Compiler::TypeOption->new(name=> "serialize");
      $serializeOption->options("no","no");
      $at->push_typeOptions( $serializeOption );
      my $constructorOption = Mace::Compiler::TypeOption->new(name=> "constructor");
      $constructorOption->options("default","no");
      $at->push_typeOptions( $constructorOption );
      $this->push_auto_types( $at );
    }

    if( $origmethod->returnType->isVoid ){
        # create deferral auto type queue
        my $at = Mace::Compiler::AutoType->new(name=> "DeferralUpcallQueue_${mnumber}_" . $origmethod->name(), line=>$origmethod->line , filename => $origmethod->filename );
        my $serializeOption = Mace::Compiler::TypeOption->new(name=> "serialize");
        $serializeOption->options("no","no");
        $at->push_typeOptions( $serializeOption );
        my $constructorOption = Mace::Compiler::TypeOption->new(name=> "constructor");
        $constructorOption->options("default","no");
        $at->push_typeOptions( $constructorOption );

        for( $origmethod->params() ){
            my $p = $this->createNonConstCopy( $_ );
            $at->push_fields( $p );
        }
        $this->push_auto_types( $at );
    }
    $at->options('appupcall_method', $origmethod );
    $this->createApplicationUpcallInternalMessageProcessor( $origmethod, $at, $mnumber );
=cut
}

sub createContextRoutineHelperMethod {
    my $this = shift;
    my $transitionType = shift;
    my $at = shift;
    my $routineMessageName = shift;
    my $hasContexts = shift;
    my $svName = shift;

    my $pname = $this->name;
    my $returnType = $this->returnType->type;
    my $contextToStringCode = $this->generateContextToStringRoutine();

    my $routineName;
    if( defined $this->options("routine_name") ){
      $routineName = $this->options("routine_name");
    }else{
      $routineName = "routine_" . $pname;
    }

    my $applicationInterfaceCheck = "";
    my $enterInnerService = "";
    if( $transitionType eq "downcall" or $transitionType eq "upcall" ){
      $enterInnerService = "enterInnerService(targetContextName);";
    }
    my $scopedCall;
    if( $transitionType eq "downcall" ){
        my $eventType = "DOWNCALLEVENT";
        if( $this->name eq "maceInit" ){
          $eventType = "STARTEVENT";
        }elsif ($this->name eq "maceExit" ){
          $eventType = "ENDEVENT";
        }
        my $svPointerConstCast = "";
        my $svPointer = "this";
        if( $this->isConst() == 1 ){
          $svPointerConstCast = "${svName}Service *self = const_cast<${svName}Service *>( this );";
          $svPointer = "self";
        }
        $applicationInterfaceCheck = 
       qq#$svPointerConstCast
          __ServiceStackEvent__ _sse( mace::Event::$eventType, $svPointer, targetContextName );#;
    }

    if( $transitionType eq "routine" ){
      $scopedCall = "__ScopedRoutine__";
    }else{
      $scopedCall = "__ScopedTransition__";
    }

    my $routineCall = "$routineName(" . join(", ", map { $_->name; } $this->params()) . ")";

    my $returnReturnValue = "";
    my $deserializeReturnValue = "";
    my $callAndReturn;
    if($returnType eq 'void'){
        $callAndReturn = qq/$routineCall;
        return;/;
    }else{
        $returnReturnValue = "return returnValue;";
        $deserializeReturnValue = qq#$returnType returnValue;
        rpc.get(returnValue);#;
        $callAndReturn = qq/return $routineCall;/;
    }
    my $localCall = 
     qq!$scopedCall p( this, targetContextID, snapshotContextIDs );
        $callAndReturn!;
    my $returnRPC = "";
    if( $hasContexts > 0 ){ # The context can be in a remote node. Send RPC request
        my @paramArray;
        for my $atparam ($at->fields()){
            given( $atparam->name ){
                when ("response") { push @paramArray, "false"; }
                when ("targetContextID") { push @paramArray, "targetContextID"; }
                when ("event") { push @paramArray, "ThreadStructure::myEvent()" }
                default { push @paramArray, $atparam->name; }
            }
        }
        my $copyParam = join(",", @paramArray);
        $localCall = "const MaceAddr& destAddr = mace::ContextMapping::getNodeByContext( currentMapping, targetContextID);
        if( destAddr == Util::getMaceAddr() ){
            $localCall
        }";
        $returnRPC = 
         qq#$routineMessageName msgStartCtx($copyParam);
            mace::ScopedContextRPC rpc;
            downcall_route( MaceKey( mace::ctxnode, destAddr ), msgStartCtx  ,__ctx);
            $deserializeReturnValue
            rpc.get( ThreadStructure::myEvent() );
            $returnReturnValue#;
    }
    my $helperbody = qq#
      $contextToStringCode
      $applicationInterfaceCheck
      $enterInnerService
      const mace::ContextMapping& currentMapping = contextMapping.getSnapshot();
      uint32_t targetContextID = currentMapping.findIDByName( targetContextName );

      mace::vector< uint32_t > snapshotContextIDs;
      for_each( snapshotContextNames.begin(), snapshotContextNames.begin(), mace::addSnapshotContextID(currentMapping, snapshotContextIDs  ) );
      acquireContextLocks(targetContextID, snapshotContextIDs);
      mace::AccessLine al( instanceUniqueID, targetContextID, currentMapping );
      $localCall
      $returnRPC
    #;
    $this->body($helperbody);
}

sub createRoutineDowngradeHelperMethod {
    my $this = shift;

    my $pname = $this->name;
    my $this_subs_name = (caller(0))[3];
    my $helperBody = "// Generated by ${this_subs_name}() line: " . __LINE__ . qq/
      downgradeCurrentContext();
    /;
    my $helpermethod = ref_clone($this);
    $helpermethod->name("downgrade_$pname");
    my $returnType = $this->returnType->type;

    my $routineCall = "${pname}(" . join(", ", map{ $_->name() } $this->params() ) . ")";
    if( $returnType eq "void" ){
      $helperBody .= "$routineCall;";
    }else{
      $helperBody .= "return $routineCall;";
    }

    $helpermethod->body($helperBody);

    return $helpermethod;
}

sub printTargetContextVar {
    my $this = shift;
    my $ref_vararray = shift;
    my $contexts = shift;

    given( $this->targetContextObject() ){
        when (/(__internal|__anon|__null)/) {}
        default {
            $this->printContextVars("target", $this->targetContextObject(), "thisContext" , $ref_vararray, $contexts );
        }
    }
}
sub printSnapshotContextVar {
    my $this = shift;
    my $ref_vararray = shift;
    my $contexts = shift;

    foreach my $ctx  ( keys %{ $this->snapshotContextObjects()} ) {
        $this->printContextVars("snapshot", $ctx, ${ $this->snapshotContextObjects() }{$ctx} , $ref_vararray, $contexts );
    }
}
sub printContextVar {
    my $this = shift;
    my $ctxtype = shift;
    my $alias = shift;
    my $currentContext = shift;
    my $contextString = shift;
    my $ref_vararray = shift;

    if( $ctxtype eq "snapshot" ){
        push(@{ $ref_vararray}, "const $currentContext->{className}& $alias __attribute((unused)) = $contextString ->getSnapshot();");
    }elsif( $ctxtype eq "target" ){
        my $constancy = "";
        if( defined $this->options('locking') && $this->options('locking') == 0 ){
            $constancy = "const ";
        } elsif( $this->isConst() == 1 ){
            $constancy = "const ";
        }
        push(@{ $ref_vararray}, "$constancy $currentContext->{className}& $alias __attribute((unused)) = static_cast<$constancy $currentContext->{className}&>( *ThreadStructure::myContext() );");
        for my $var ($currentContext->ContextVariables()) {
            my $t_name = $var->name();
            my $t_type = $var->type()->toString(paramref => 1);
            # Those are the variables to be read if the transition is READ transition.
            if (!$this->isUsedVariablesParsed()) {
              # XXX: chuangw: when compiling .vmac files, for some reason, Globals::useSnapshot is false instead of true...

              # If default parser is used since incontext parser failed, include every variable.
              push(@{ $ref_vararray}, "$constancy ${t_type} ${t_name} __attribute((unused)) = $alias.${t_name};");
            } else { # If InContext parser is used, selectively include variable.
              if(grep $_ eq $t_name, $this->usedStateVariables()) {
                push(@{ $ref_vararray}, "$constancy ${t_type} ${t_name} __attribute((unused)) = $alias.${t_name};");
              } else {
                push(@{ $ref_vararray}, "//$constancy ${t_type} ${t_name} __attribute((unused)) = $alias.${t_name};");
              }
            }
        }
    }
}

sub printContextVars {
    my $this = shift;
    my $ctxtype = shift;
    my $contextID = shift;
    my $alias = shift;
    my $ref_vararray = shift;
    my $contexts = shift;

    # read $t->context.  find out context variables
    my @contextScope= split(/::/, $contextID );
    my $currentContextName = "";
    my $contextString = "";

    my $currentContext = $contexts; 
    if( scalar( @contextScope ) == 0 ){
        $contextString = "(*globalContext)";
        $this->printContextVar( $ctxtype, $alias, $currentContext, $contextString , $ref_vararray );
    }
    while( defined (my $contextID = shift @contextScope)  ){
        if ( $contextID =~ /($regexIdentifier)<($regexIdentifier)>/ ) {
            $contextString .= "$1\[$2\]";
            $currentContextName = $1;
        } elsif ($contextID =~ /($regexIdentifier)<([^>]+)>/) {
            my @contextParam = split("," , $2);

            $contextString .= "$1\[ __$1__Context__param( " . join(",", @contextParam) . " ) \]";
            $currentContextName = $1;
        }else{
            $contextString = "(*${contextString}${contextID})";
            $currentContextName = $contextID;
        }
        for ($currentContext->subcontexts() ) {
            if( $_->name() eq $currentContextName ){
                $currentContext = $_;
                last;
            }
        }
        if( not defined( $currentContext) ){
            Mace::Compiler::Globals::error("bad_context", $this->filename(), $this->line(), "Context '$currentContextName' not found.");
            return;
        }
        if( scalar( @contextScope )>0 ){
            $contextString = $contextString . ".";
        }else{
            $this->printContextVar( $ctxtype, $alias, $currentContext, $contextString , $ref_vararray );
        }
    }

}
sub toMessageTypeName {
    my $this = shift;
    my $type = shift;

    #my $uniqid = $this->transitionNum;
    my $uniqid = shift;

    my $pname = $this->options("base_name");

    given( $type ){
        when ("async") {return "__async_at${uniqid}_$pname" }
        when ("scheduler") {return "__scheduler_at${uniqid}_$pname" }
        when ("upcall_deliver") {
            my $ptype = ${ $this->params }[2]->type->type;
            return "__deliver_at_$ptype"; 
        }
        when ("upcall") {
            return "__upcall_at${uniqid}_$pname"; 
        }
        when ("downcall") {
            return "__downcall_at${uniqid}_$pname"; 
        }
    }
}
sub createUpcallDeliverMessage {
    my $this = shift;

    my $atref = shift;
    my $service_messages = shift;

    my $asyncMessageName = $this->options("upcall_msgname");
    $$atref = Mace::Compiler::AutoType->new(name=> $asyncMessageName, line=>$this->line(), filename => $this->filename(), method_type=>Mace::Compiler::AutoType::FLAG_DELIVER);
    my $at = $$atref;

    # flatten the message in the method
    my $fieldCount = 0;
    my $msgt;

    # Add source field
    # Add dest field
    # Add message field parameters
    # Add rid field
    # Add extra field

    for my $op ($this->params()) {
        if( $fieldCount == 2 ){
           # find this message
           map { $msgt = $_ if $_->name eq $op->type->type } ( grep { $_->method_type == Mace::Compiler::AutoType::FLAG_NONE} @{ $service_messages } );
        }else{
            my $p= ref_clone($op);
            if( defined $p->type ){
                $p->name( "__" . $op->name); # prepend a prefix to avoid naming conflict.
                $p->type->isConst(0);
                $p->type->isConst1(0);
                $p->type->isConst2(0);
                $p->type->isRef(0);
                $at->push_fields($p);
            }
        }
        $fieldCount++;
    }
    die unless defined $msgt;
    for my $op ($msgt->fields()) {
        my $p= ref_clone($op);
        if( $p->name ne "extra" and defined $p->type ){
            $p->type->isConst(0);
            $p->type->isConst1(0);
            $p->type->isConst2(0);
            $p->type->isRef(0);
            $at->push_fields($p);
        }
    }
    my $extraFieldType = Mace::Compiler::Type->new(type=>"__asyncExtraField",isConst=>0,isConst1=>0,isConst2=>0,isRef=>0);
    my $extraField = Mace::Compiler::Param->new(name=>"extra",  type=>$extraFieldType);
    $at->push_fields($extraField);

    my $eventFieldType = Mace::Compiler::Type->new(type=>"mace::Event",isConst=>0,isConst1=>0,isConst2=>0,isRef=>0);
    my $eventField = Mace::Compiler::Param->new(name=>"event",  type=>$eventFieldType);
    $at->push_fields($eventField);
}
sub createSchedulerMessage {
    my $this = shift;

    my $ref_msgHash = shift;
    my $atref = shift;

    my $asyncMessageName = $this->options("scheduler_msgname");
    $$atref = Mace::Compiler::AutoType->new(name=> $asyncMessageName, line=>$this->line(), filename => $this->filename(), method_type=>Mace::Compiler::AutoType::FLAG_TIMER);
    my $at = $$atref;

    for my $op ($this->params()) {
        my $p= ref_clone($op);
        if( defined $p->type ){
            $p->type->isConst(0);
            $p->type->isConst1(0);
            $p->type->isConst2(0);
            $p->type->isRef(0);
            $at->push_fields($p);
        }
    }
    my $extraFieldType = Mace::Compiler::Type->new(type=>"__asyncExtraField",isConst=>0,isConst1=>0,isConst2=>0,isRef=>0);
    my $extraField = Mace::Compiler::Param->new(name=>"extra",  type=>$extraFieldType);
    $at->push_fields($extraField);

    my $eventFieldType = Mace::Compiler::Type->new(type=>"mace::Event",isConst=>0,isConst1=>0,isConst2=>0,isRef=>0);
    my $eventField = Mace::Compiler::Param->new(name=>"event",  type=>$eventFieldType);
    $at->push_fields($eventField);
}
sub createAsyncMessage {
    my $this = shift;

    my $ref_msgHash = shift;
    my $atref = shift;

    my $asyncMessageName = $this->options("async_msgname"); 
    $$atref = Mace::Compiler::AutoType->new(name=> $asyncMessageName, line=>$this->line(), filename => $this->filename(), method_type=>Mace::Compiler::AutoType::FLAG_ASYNC);
    my $at = $$atref;

    for my $op ($this->params()) {
        my $p= ref_clone($op);
        if( defined $p->type ){
            $p->type->isConst(0);
            $p->type->isConst1(0);
            $p->type->isConst2(0);
            $p->type->isRef(0);
            $at->push_fields($p);
        }
    }
    my $extraFieldType = Mace::Compiler::Type->new(type=>"__asyncExtraField",isConst=>0,isConst1=>0,isConst2=>0,isRef=>0);
    my $extraField = Mace::Compiler::Param->new(name=>"extra",  type=>$extraFieldType);
    $at->push_fields($extraField);

    my $eventFieldType = Mace::Compiler::Type->new(type=>"mace::Event",isConst=>0,isConst1=>0,isConst2=>0,isRef=>0);
    my $eventField = Mace::Compiler::Param->new(name=>"event",  type=>$eventFieldType);
    $at->push_fields($eventField);
}
sub createAsyncHelperMethod {
#chuangw: This subroutine creates helper method and demux method for the async transition
    my $this = shift;
    my $at = shift;
    my $extra = shift;

    my $helpermethod = shift; # output

    my $pname = $this->name;
    # It is needed to specify the return type of async transition method's, because compiler doesn't know it from matching interface specification.
    my $asyncMessageName = $this->options("async_msgname"); #$this->toMessageTypeName( ); 

#------------------------------------------------------------------------------------------------------------------
    # Generate async_foo helper method. The user uses this helper method to create an async event

    my $transitions;
    my $pretransitions;
    my $posttransitions;
    
    # chuangw: temporarily remove references to transitions to avoid recursive cloning
    $transitions = $this->options("transitions");
    $this->options("transitions", undef);
    $pretransitions = $this->options("pretransitions");
    $this->options("pretransitions", undef);
    $posttransitions = $this->options("posttransitions");
    $this->options("posttransitions", undef);

    $$helpermethod = ref_clone($this);
    #$$helpermethod->validateLocking( );
    $$helpermethod->name("async_$pname");

    # restore demux method...
    $this->options("transitions", $transitions);
    $this->options("pretransitions", $pretransitions);
    $this->options("posttransitions", $posttransitions);

    my $contextToStringCode = $this->generateContextToString();

    my @extraParams;
    for ( $extra->fields() ){
        given( $_->name ){
            when ("isRequest") { push @extraParams, "true";}
            default  { push @extraParams, "$_"; }
        }
    }
    my @routemsg_copyParams;
    map {push @routemsg_copyParams, "$_->{name}"}  $at->fields() ;
    my $routemsg_extraParam = "__asyncExtraField extra(" . join(", ", @extraParams) . ");";
    my $routemsg_copyParam = join(", ", @routemsg_copyParams);

    my @copyParams;
    push @copyParams, "mace::imsg";
    map {push @copyParams, "$_->{name}"}  grep{ $_->name ne "extra" and $_->name ne "event" } $at->fields() ;
    my $copyParam = join(", ", @copyParams);

    my $this_subs_name = (caller(0))[3];

    my $targetContextNameMapping = "";
    if( $this->targetContextObject() ){
      my $ref_matched_params;
      $targetContextNameMapping = "oss<<" . join(qq/ << "." << /, $this->targetContextToString($ref_matched_params) ) . ";\n";
    }
    my $helperbody = qq#{
        // Generated by ${this_subs_name}() file: # . __FILE__ . qq# line: # . __LINE__ . qq#
        // send a message to head node to create an event
        static const bool no_payload = params::get<bool>("EVENTREQ_PAYLOAD", false );
        if( no_payload ){
          $contextToStringCode
          mace::Event event(  ThreadStructure::myEvent().getEventID() );
          $routemsg_extraParam
          $asyncMessageName pcopy($routemsg_copyParam );
          extra.isRequest = false;
          requestRouteEvent( extra, event, pcopy );
        }else{
          std::ostringstream oss;
          $targetContextNameMapping  
          $asyncMessageName *pcopy = new $asyncMessageName($copyParam );
          pcopy->getExtra().targetContextID = oss.str();
          pcopy->getExtra().isRequest = true;
          SEND_EVENTREQUEST( contextMapping.getHead(), $asyncMessageName, pcopy );
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
    my $pname = $this->name;
    my $v = Mace::Compiler::Type->new('type'=>'void');
    $this->returnType($v);
    # Generate timer helper method. This method is called when timer goes off.

    my $transitions;
    my $pretransitions;
    my $posttransitions;
    
    # chuangw: temporarily remove references to transitions to avoid recursive cloning
    $transitions = $this->options("transitions");
    $this->options("transitions", undef);
    $pretransitions = $this->options("pretransitions");
    $this->options("pretransitions", undef);
    $posttransitions = $this->options("posttransitions");
    $this->options("posttransitions", undef);


    my $helpermethod = ref_clone($this);
    #$helpermethod->validateLocking();
    my $helperName = $pname;
    $helperName =~ s/^expire_/scheduler_/;
    $helpermethod->name($helperName);

    # restore demux method...
    $this->options("transitions", $transitions);
    $this->options("pretransitions", $pretransitions);
    $this->options("posttransitions", $posttransitions);

    if ($this->targetContextObject() eq '__internal' ){
        my $v = Mace::Compiler::Type->new('type'=>'void');
        $helpermethod->returnType($v);
        my @paramArray;
        for my $atparam ($this->params()){
            push @paramArray, $atparam->name;
        }
        my $params = join(",", @paramArray);
        $helperbody = qq#
        expire_$pname($params);
        #;
        $helpermethod->body($helperbody);
        return $helpermethod;
    }

    # change the variable name
    if( defined $this->options('transitions') ){
      for my $txn ( @{ $this->options('transitions') }) {
        my $nparams = $txn->method->count_params();
        for my $n ( 0 .. $nparams -1 ){
          my $org_name = ${ $txn->method->params() }[ $n ]->name() ;

          ${ $helpermethod->params() }[ $n ]->name( $org_name );
        }
      }
    }

    # Generate auto-type for the method parameters.
    my $timerMessageName = $this->options("scheduler_msgname"); 
    $this->options('originalTransition','scheduler');
#------------------------------------------------------------------------------------------------------------------
    my $contextToStringCode = $this->generateContextToString();

    my $this_subs_name = (caller(0))[3];
    my $helperBody = "// Generated by ${this_subs_name}() line: " . __LINE__;
    my @extraParams;

    my @copyParams;
    for ( $extra->fields() ){
        given( $_->name ){
            when ("isRequest") { push @extraParams, "true";}
            default  { push @extraParams, "$_"; }
        }
    }
    push @copyParams, "mace::imsg";
    map {push @copyParams, "$_->{name}"}  grep{ $_->name ne "extra" and $_->name ne "event" } $helpermethod->params() ;
    my $copyParam = join(", ", @copyParams);


    $helperbody = qq#{
        $contextToStringCode
        $timerMessageName *pcopy = new $timerMessageName($copyParam );
        pcopy->getExtra().targetContextID = targetContextID;
        pcopy->getExtra().isRequest = true;
        SEND_EVENTREQUEST( contextMapping.getHead(), $timerMessageName, pcopy );
    }
    #;
    $helpermethod->body($helperbody);
    return $helpermethod;
}
sub redirectTransportMessage {
    my $this = shift;

    my $helperbody;
    my $pname = $this->name;
    my $v = Mace::Compiler::Type->new('type'=>'void');
    $this->returnType($v);
}
sub toRealHeadHandlerName {
    my $this = shift;
    my $type = shift;
    my $uniqid = shift;

    my $pname = $this->options("base_name"); #$this->name;
    given( $type ){
        when ("async") {return "__async_head_fn${uniqid}_$pname" }
        when ("scheduler") {return "__scheduler_head_fn${uniqid}_$pname" }
        when ("upcall_deliver") {
            my $ptype = ${ $this->params }[2]->type->type;
            return "__deliver_head_fn_$ptype";
        }
        when ("upcall") { return "__upcall__head_fn_${uniqid}_$pname"; }
        when ("downcall") { return "__downcall_head_fn_${uniqid}_$pname"; }
    }
}
sub toRealHandlerName {
    my $this = shift;
    my $type = shift;
    my $uniqid = shift;

    my $pname = $this->options("base_name"); #$this->name;
    given( $type ){
        when ("async") {return "__async_fn${uniqid}_$pname" }
        when ("scheduler") {return "__scheduler_fn${uniqid}_$pname" }
        when ("upcall_deliver") {
            my $ptype = ${ $this->params }[2]->type->type;
            return "__deliver_fn_$ptype";
        }
        when ("upcall") { return "__upcall_fn_${uniqid}_$pname"; }
        when ("downcall") { return "__downcall_fn_${uniqid}_$pname"; }
    }
}
sub createRealTransitionHeadHandler {
    my $this = shift;
    my $transitionType = shift;
    my $message = shift;
    my $name = shift;
    my $extra = shift;

    my $adMethod = shift; #output

    my $pname = $this->options("base_name");#$this->name();
    my $ptype = $message->name(); 
    my $this_subs_name = (caller(0))[3];
    my $messageName = $message->name();
    my $adName = $this->options("event_handler");
    my $adHeadName = $this->options("event_head_handler");
    my $async_upcall_param = "param";

    if( not defined $extra ){
        Mace::Compiler::Globals::error("bad_message", __FILE__, __LINE__, "can't find the auto-generated autotype '__asyncExtraField'");
        return;
    }
    my @origParams;
    for my $param ($message->fields()) {
        given( $param->name ){
            when ("extra") { push @origParams, "newExtra"; }
            when ("event") { push @origParams, "ThreadStructure::myEvent()"; }
            default { push @origParams, "$async_upcall_param ->" . $_; }
        }
    }
    my $headMessage = "$ptype pcopy(" . join(",", @origParams) . ");";
#--------------------------------------------------------------------------------------
    my @asyncMethodParams;
    my $startAsyncMethod;
    my $eventType = "";
    given( $transitionType ){
      when ("async") { $eventType = "ASYNCEVENT"; }
      when ("scheduler") { $eventType = "TIMEREVENT"; }
      when ("upcall") { $eventType = "UPCALLEVENT"; }
    }
#--------------------------------------------------------------------------------------
    my $adBody = "// Generated by ${this_subs_name}() line: " . __LINE__;
    
    if( defined $this->options('transitions') ){
      $adBody .= qq#
        $messageName *$async_upcall_param = ($messageName*)p;
        ASSERTMSG( $async_upcall_param ->extra.isRequest == true, "Not head!" );

        if( mace::Event::isExit ) {
          wasteTicket();
          return;
        }
        mace::ContextMapping const& snapshotMapping __attribute((unused)) = asyncHead( $async_upcall_param ->getEvent(), $async_upcall_param ->extra, mace::Event::$eventType );
        $async_upcall_param ->getExtra().isRequest  = false;
        EXEC_EVENT( $async_upcall_param );
      #;
    }else{
      $adBody .= qq/wasteTicket();/;
    }
    my $adReturnType = Mace::Compiler::Type->new(type=>"void",isConst=>0,isConst1=>0,isConst2=>0,isRef=>0);
    my $adParamType = Mace::Compiler::Type->new( type => "void*", isConst => 0,isRef => 0 );
    $$adMethod = Mace::Compiler::Method->new( name => $adHeadName, body => $adBody, returnType=> $adReturnType);
    $$adMethod->push_params( Mace::Compiler::Param->new( name => "p", type => $adParamType ) );

}
sub createRealTransitionHandler {
    my $this = shift;
    my $transitionType = shift;
    my $message = shift;
    my $name = shift;
    my $extra = shift;

    my $adMethod = shift; #output

    my $pname = $this->options("base_name");
    my $ptype = $message->name(); 
    my $this_subs_name = (caller(0))[3];
    my $messageName = $message->name();
    my $adName = $this->options("event_handler");
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
    my @asyncMethodParams;
    my $startAsyncMethod;
    if( $transitionType eq "scheduler" ){
        map{ push @asyncMethodParams,  "const_cast<" . $_->type->type . "&>($async_upcall_param.$_->{name})" if ($_->name ne "extra" and $_->name ne "event") ; } $message->fields();
        $startAsyncMethod = "expire_" . $pname . "(" . join(", ", @asyncMethodParams ) . ");";
    }elsif( $transitionType eq "upcall" ){
        my $origUpcallMessage = ${ $this->params }[2]->type->type;
        my @asyncParam;
        my @upcallParam;
        my $fieldCount = 0;
        # fields: src, dest, rid, <original message fields>
        my $count_msgfields = $message->count_fields();
        #print "count_msgfields: $count_msgfields\n";
        foreach( $message->fields() ){
          if( $fieldCount <= 1 ){
              push @asyncParam, "$async_upcall_param." . $_->name;
          }elsif ( $fieldCount >= 3  and $fieldCount < $count_msgfields-2 ){
              push @upcallParam, "$async_upcall_param." . $_->name;
          }
          $fieldCount++;
        }
        push @asyncParam, "$origUpcallMessage(" . join(",", @upcallParam ) . " )";
        $startAsyncMethod = "$pname(" . join(",", @asyncParam) . ");";
    }elsif( $transitionType eq "async" ){
        map{ push @asyncMethodParams,  "$async_upcall_param.$_->{name}" if ($_->name ne "extra" and $_->name ne "event") ; } $message->fields();
        $startAsyncMethod = $pname . "(" . join(", ", @asyncMethodParams ) . ");";
    }
#--------------------------------------------------------------------------------------
    my $adBody = "// Generated by ${this_subs_name}() line: " . __LINE__ . qq#
      __beginRemoteMethod( $async_upcall_param.event );
      __ScopedTransition__ st( this, $async_upcall_param.extra );
      $startAsyncMethod 
    #;
    my $adReturnType = Mace::Compiler::Type->new(type=>"void",isConst=>0,isConst1=>0,isConst2=>0,isRef=>0);
    my $adParamType = Mace::Compiler::Type->new( type => "$ptype", isConst => 1,isRef => 1 );
    my $adParamType2 = Mace::Compiler::Type->new( type => "MaceAddr", isConst => 1,isRef => 1 );
    $$adMethod = Mace::Compiler::Method->new( name => $adName, body => $adBody, returnType=> $adReturnType);
    $$adMethod->push_params( Mace::Compiler::Param->new( name => "$async_upcall_param", type => $adParamType ) );
    $$adMethod->push_params( Mace::Compiler::Param->new( name => "source", type => $adParamType2 ) );

}
1;
