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
use Mace::Util qw(:all);
use Switch 'Perl6';

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
     'string' => "startContextObject", 
     'hash' => "snapshotContextObjects"
     );
my $regexIdentifier = "[_a-zA-Z][a-zA-Z0-9_.]*";

sub validate {
    my $this = shift;
    my $contexts = shift;

    given( $this->targetContextObject() ){
        when /^(__internal|__anon|__null)$/ {}
        default { $this->validateContext($this->targetContextObject(),  $contexts   ); }
    }
    foreach my $ctx  ( keys %{ $this->snapshotContextObjects()} ) {
        $this->validateContext($ctx,  $contexts  );
    }
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
        # Note : create READ or WRITE lock.
        if( not defined $args{locktype} ){
        }elsif( $args{locktype} eq "AgentLock" ){
            if( $lockingLevel >= 0 ){
                $prep .= "mace::AgentLock __lock($lockingLevel);\n";
            }
        }elsif ( $args{locktype} eq "ContextLock" ){
        }else{
            Mace::Compiler::Globals::error("bad_lock_type", $this->filename(), $this->line(),
                                   "Unrecognized lock type '" .  $args{locktype}. "'.  Expected 'AgentLock|ContextLock'.");
        }

        if ($args{initsel} or $args{prepare} or $args{add_selectors} or $args{selectorVar} or $args{locking} or $args{fingerprint}) { #SHYOO
          $r .= "\n" . "// Method.pm:toString()\n";
          $r .= "\n" . "__eventContextType = ".$lockingLevel.";\n";
        }

				my $suffix = "";
				my $logName = $this->options('binlogname');
				my $paramList = $this->paramsToString(noline => 1,
						notype => 1, nodefaults => 1);
	
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
            if ($logLevel >= $minLogLevel) {
                my $trace = $logLevel > 0 ? "true" : "false";
                my $traceg1 = $logLevel > 1 ? "true" : "false";
						if (defined ($logName)) {
		    				$trace = "__test";
						}
						$prep .= qq{\nScopedLog __scoped_log(selector, 0, selectorId->compiler, true, $traceg1, $trace && mace::LogicalClock::instance().shouldLogPath(), PIP);\n};
            my $fnName = $this->name();
		
            if ($args{binarylog} and
                $this->doStructuredLog()) {
            
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

sub getContextLock{
    my $this = shift;
    my $prep = "";
    # chuangw: support context-level locking
    # FIXME: chuangw: 04/11/12 This part of code is messy.... Need to clean up some time.

    if( $this->name() eq "error"){ 
        # hack.... if error() upcall is unimplemented, it does not have lockingLevel,
        # but it would still be called whenever tcp connection broken, and then the ticket is not used and then deadlock
=begin
        if( not defined $args{locking} ){
            $args{locking} = 1; # for safety, if unimplemented or unspecified, use WRITE_MODE
        }else{
            $prep .= qq#//locking=" .$args{locking}.";\n#;
        }
=cut
    }
    if($this->targetContextObject){
        
        if( $this->targetContextObject eq "__internal" ){
            # if manipulating the internal context, we almost always change something.
            $prep .= qq/ mace::ContextLock __contextLock0(mace::ContextBaseClass::__internal_Context, mace::ContextLock::WRITE_MODE); /;
        }else{
            $prep .= "//chuangw: TODO: this is not needed... getContextObjByID is already called ";
=begin
            my @contextScope= split(/::/, $this->targetContextObject);
            # initializes context class if not exist
            my $contextString = "this->";
            my $contextLockCount = 1;
            
            my $contextIDParam = "";
            my $contextDebugIDOSS = qq/ std::ostringstream contextDebugID;
                contextDebugID/;
            my $contextDebugID = "";

            while( defined (my $contextID = shift @contextScope)  ){
                if ( $contextID =~ /($regexIdentifier)<($regexIdentifier)>/ ) {
                    $contextDebugID .=qq# << "${1}[" << ${2} << "]"#;
                    $prep .= qq/
    $contextIDParam
    if( ${contextString}$1.find( $2 ) == ${contextString}$1.end() ){
        $contextDebugIDOSS $contextDebugID;
        ScopedLock sl( mace::ContextBaseClass::newContextMutex );
        if( ${contextString}$1.find( $2 ) == ${contextString}$1.end() ) {
            ${contextString}$1\[$2\] = __$1__Context( contextDebugID.str(), ThreadStructure::myTicket() );
        }
    }
                    /;
                    $contextID = "${1}\[ ${2}  \]";
                    $contextString = $contextString . $contextID;
                } elsif ($contextID =~ /($regexIdentifier)\<([^>]+)\>/) {
                  my @contextParam = split("," , $2);

                  my $contextIDParam .= qq/__$1__Context__param $1_param(/ . join(",", @contextParam)  . qq/);
                  /;

                    $contextDebugID .= qq#<< "${1}\[" << $1_param << "\]"#;
                    $prep .= qq/
    $contextIDParam
    if( ${contextString}$1.find( $1_param ) == ${contextString}$1.end() ){
        $contextDebugIDOSS $contextDebugID;
        ScopedLock sl( mace::ContextBaseClass::newContextMutex );
        if( ${contextString}$1.find( $1_param ) == ${contextString}$1.end() ) {
            ${contextString}$1\[ $1_param \] = __$1__Context(contextDebugID.str(), ThreadStructure::myTicket() );
        }
    }
                    /;
                    $contextID = "$1 [ $1_param ]";
                    $contextString = $contextString . $contextID;
                }else{
                    $contextDebugID .= qq/<< "$contextID"/;
                    $prep .= qq/
    $contextIDParam
    if( ${contextString}${contextID} == NULL ){
        $contextDebugIDOSS $contextDebugID;
        ScopedLock sl( mace::ContextBaseClass::newContextMutex );
        if( ${contextString}${contextID} == NULL ){
            ${contextString}${contextID} = new __${contextID}__Context ( contextDebugID.str(), ThreadStructure::myTicket() );
        }
    }
                    /;
                    $contextString = "*(${contextString}${contextID})";
                }

                if( @contextScope == 0 ){
                    $prep .= qq/
                                    mace::ContextLock __contextLock${contextLockCount}($contextString, mace::ContextLock::WRITE_MODE);
                            /;
                }else{
                    $contextString = $contextString . ".";
                }
                $contextLockCount++;
            }
            $prep .= qq#
                // Push current contextID into thread's contextID stack
                $contextIDParam
                $contextDebugIDOSS $contextDebugID;
                ThreadStructure::pushContext(contextDebugID.str());
            #;
=cut
        }

    }
    return $prep;
}

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
        # FIXME: chuangw: multi-dimensional context?
          $origContextClass = $1;
      } elsif ( $_ =~ /($regexIdentifier)/ ) {
          $origContextClass = $1;
      }
    }
    my $contextClass = "__${origContextClass}__Context";

    return $contextClass;
}
sub addSnapshotParams {
    my $this = shift;

    my @params = $this->params;
    my $snapshotContextDec = "";
    my $snapshotContextType = Mace::Compiler::Type->new(type=>"mace::string",isConst=>1,isConst1=>0,isConst2=>0,isRef=>1);
    my $contextCount = 1;
            
    while (my ($_contextID,  $alias) = each(%{$this->snapshotContextObjects() })){
        my $snapshotContextName = "snapshotContext" . $contextCount; 
        my $snapshotContextField = Mace::Compiler::Param->new(name=>$snapshotContextName,  type=>$snapshotContextType);
        $this->push_params( $snapshotContextField );

        $contextCount = $contextCount+1;
        # FIXME: chuangw: broken code.
        my $contextClass = $this->getContextClass($_contextID);
        $snapshotContextDec .= qq/
            $contextClass $alias;
            {
                std::istringstream in($snapshotContextName);
                mace::deserialize(in,  &$alias);
            }
        /;
    }

    my $newBody = $snapshotContextDec . $this->body();
    $this->body( $newBody );
}
sub getContextNameMapping {
    my $this = shift;
    my $origContextID = shift;

    my @contextNameMapping;
    my @contextScope= split(/::/, $origContextID);
    foreach (@contextScope) {
      	if ( $_ =~ /($regexIdentifier)<($regexIdentifier)>/ ) {
          	# check if $1 is a valid context name
         	 	# and if $2 is a valid context mapping key variable.
          	push @contextNameMapping, qq# "${1}\[" + boost::lexical_cast<mace::string>(${2}) + "\]"#;
        } elsif ($_ =~ /($regexIdentifier)<([^>]+)>/) {
            my @contextParam = split("," , $2);
            push @contextNameMapping ,qq# "${1}\[" + boost::lexical_cast<mace::string>(__$1__Context__param(# . join(",", @contextParam)  . qq#) ) + "\]"#;
      	} elsif ( $_ =~ /($regexIdentifier)/ ) {
          	push @contextNameMapping, qq# "$1"#;
        }
    }
    return @contextNameMapping;
}

sub targetContextToString {
    my $this= shift;
    return $this->getContextNameMapping($this->targetContextObject() );
}
sub snapshotContextToString {
    my $this = shift;
    my $ref_array = shift;
    while( my( $snapshotContextID,  $alias) = each( %{$this->snapshotContextObjects()}) ){
        my @tempContextNameArray = $this->getContextNameMapping($snapshotContextID);
        push @{ $ref_array },  qq#mace::string("")# . join(qq# + "." #, map{" + " . $_} @tempContextNameArray);
    }
}

sub generateContextToString {
    my $this = shift;
    my %args = @_;

    my $snapshotContextsNameMapping="";
    my $declareAllContexts="";
    if( $args{"allcontexts"} ){
        $declareAllContexts = qq/mace::vector<mace::string> allContextIDs/;
        $snapshotContextsNameMapping = qq#mace::vector<mace::string> snapshotContextIDs;\n#;
    }
    my $nsnapshots = keys( %{$this->snapshotContextObjects()});
    if( $args{"snapshotcontexts"} ){
        $snapshotContextsNameMapping = qq#mace::set<mace::string> snapshotContextIDs;\n#;
    }
    if( $nsnapshots > 0 ){
        #TODO: chuangw: if the routine does not use snapshot contexts, no need to declare extra unused variables/message fields.
        my @snapshotContextNameArray;
        $this->snapshotContextToString( \@snapshotContextNameArray );
        if( $args{"allcontexts"} ){
            $declareAllContexts .= qq/ = snapshotContextIDs/;
            $snapshotContextsNameMapping .= join("\n", map{ qq#snapshotContextIDs.push_back($_);# }  @snapshotContextNameArray );
        }else{
            $snapshotContextsNameMapping .= join("\n", map{ qq#snapshotContextIDs.insert($_);# }  @snapshotContextNameArray );
        }
    }
    if( $args{"allcontexts"} ){
        $declareAllContexts .= qq/;
        allContextIDs.push_back(targetContextID);
        mace::string startContextID = getStartContext(allContextIDs); /;
    }
    my $targetContextNameMapping =qq#mace::string targetContextID = mace::string("")# . join(qq# + "." #, map{" + " . $_} $this->targetContextToString() );

    return qq/
        $targetContextNameMapping;
        $snapshotContextsNameMapping
        $declareAllContexts
    /;
}

sub createContextRoutineHelperMethod{
    my $this = shift;
    my $at = shift;
    my $routineMessageName = shift;
    my $hasContexts = shift;

    my $pname = $this->name;
    my $returnType = $this->returnType->type;
    my $contextToStringCode = $this->generateContextToString(allcontexts=>1);

    my @targetParams = ("startContextID","targetContextID","ThreadStructure::getEventContexts()");
    my $count = 0;
    my $snapshotBody = "";
    my $nsnapshots = keys( %{ $this->snapshotContextObjects()} );
    for($count = 0; $count< $nsnapshots; $count++){
        $snapshotBody .= qq/
                mace::string snapshot${count} = getContextSnapshot(currContextID, snapshotContextIDs[${count}]); /;
        push @targetParams, "snapshot".${count};
    }
    map { push @targetParams, $_->name; } $this->params();
    my $routineCall = "target_routine_" . $pname . "(" . join(", ", @targetParams) . ")";

    my $returnReturnValue = "";
    my $deserializeReturnValue = "";
    my $callAndReturn;
    if($returnType eq 'void'){
        $returnReturnValue = "return;";
        $callAndReturn = qq/$routineCall;
        return;/;
    }else{
        $returnReturnValue = "return returnValue;";
        $deserializeReturnValue = qq#$returnType returnValue;
        rpc.get(returnValue);#;
        $callAndReturn = qq/return $routineCall;/;
    }
    my $localCall = qq#;
        sl.unlock();
        $snapshotBody
        $callAndReturn#;
    my $returnRPC = "";
    if( $hasContexts > 0 ){
        my @paramArray;
        for my $atparam ($at->fields()){
            given( $atparam->name ){
                when "srcContextID" { push @paramArray, "currContextID"; }
                when "eventContexts" { push @paramArray, "ThreadStructure::getEventContexts()"; }
                when "returnValue" { push @paramArray, qq/mace::string("")/; }
                when "ticket" { push @paramArray, "ThreadStructure::myTicket()"; }
                when "seqno" { push @paramArray, "msgseqno"; }
                default { push @paramArray, $atparam->name; }
            }
        }
        my $copyParam = join(",", @paramArray);
        $localCall = "const MaceAddr& destAddr = contextMapping.getNodeByContext(startContextID);
        if( destAddr == Util::getMaceAddr() ){
            $localCall
        }";
        $returnRPC = qq#
            uint32_t msgseqno = getNextSeqno(startContextID);
            $routineMessageName msgStartCtx($copyParam);
            /*mace::string buf;
            mace::serialize(buf,  &msgStartCtx);
            __internal_unAck[currContextID][msgseqno] = buf; */

            sl.unlock();
            const MaceKey destNode( mace::ctxnode, destAddr );
            mace::map<uint8_t, mace::set<mace::string> > uncommittedContexts;
            mace::ScopedContextRPC rpc( currContextID );
            downcall_route( MaceKey( mace::ctxnode, destAddr ), msgStartCtx  ,__ctx);
            rpc.get( uncommittedContexts );
            $deserializeReturnValue
            ThreadStructure::setEventContexts( uncommittedContexts );
            $returnReturnValue
        #;
    }
    my $helperbody = qq#
    {
        $contextToStringCode
        ThreadStructure::checkValidContextRequest( targetContextID );
        mace::string currContextID = ThreadStructure::getCurrentContext();
        ScopedLock sl( mace::ContextBaseClass::__internal_ContextMutex );
        
        $localCall
        $returnRPC
    }
    #;
    $this->body($helperbody);
    $this->addSnapshotParams();
}
sub createRoutineTargetHelperMethod {
    my $this = shift;
    my $at = shift;
    my $routineMessageName = shift;
    my $hasContexts = shift;

    my $this_subs_name = (caller(0))[3];
    my $helperBody = "// Generated by ${this_subs_name}() line: " . __LINE__;
    my $pname = $this->name;
    my $returnType = $this->returnType->type;
    # Generate target_routine_foo helper method to call synchronously.
    my $helpermethod = ref_clone($this);
    $helpermethod->name("target_routine_$pname");
    # Add extra parameters to this helper function
    my $contextIDType = Mace::Compiler::Type->new(type=>"mace::string",isConst=>1,isConst1=>0,isConst2=>0,isRef=>1);
    my $startContextField = Mace::Compiler::Param->new(name=>"startContextID",  type=>$contextIDType);
    my $targetContextField = Mace::Compiler::Param->new(name=>"targetContextID",  type=>$contextIDType);
    my $eventContextsType = Mace::Compiler::Type->new(type=>"mace::map<uint8_t, mace::set<mace::string> >",isConst=>1,isConst1=>0,isConst2=>0,isRef=>1);
    my $eventContextsField = Mace::Compiler::Param->new(name=>"eventContexts",  type=>$eventContextsType);

    @{$helpermethod->params()} = ( $startContextField, $targetContextField, $eventContextsField, @{$helpermethod->params()} );

    my $routineCall = "sync_${pname}(" . join(", ", map{ $_->name() } $this->params() ) . ")";
    my $seg1 = "";
    my $seg2 = "";
    my $return = "";
    my $returnRPCValue = "";
    if( $returnType eq "void" ){
        $seg2 = qq# $routineCall ; #;
        $return = "return;";
    }else{
        $seg1 = "$returnType returnValue;
                rpc.get(returnValue);";
        $seg2 = ""; 
        $return = "return $routineCall;";
        $returnRPCValue = "return returnValue;";
    }
    my $localCall = qq#
        sl.unlock();
        ThreadStructure::ScopedContextID sc(targetContextID);
        ThreadStructure::setEventContexts(eventContexts);
        mace::ContextLock __contextLock( *(ThreadStructure::myContext() ), mace::ContextLock::WRITE_MODE); // acquire context lock. 
        $seg2
        $return
    #;
    my $returnRPC= "";
    if( $hasContexts > 0 ){
        my @copyParams;
        for my $atparam ($at->fields()){
            given( $atparam->name ){
                when "srcContextID"{ push @copyParams , "currentContextID"; }
                when "eventContexts" { push @copyParams, "eventContexts"; }
                when "startContextID"{ push @copyParams , "startContextID"; }
                when "targetContextID"{ push @copyParams , "targetContextID"; }
                when "returnValue"{ push @copyParams , "returnValueStr"; }
                when "ticket" { push @copyParams , "ThreadStructure::myTicket()"; }
                when "seqno" { push @copyParams , "msgseqno"; }
                default  { push @copyParams , "$atparam->{name}"; }
            }
        }
        my $copyParam = join(", ", @copyParams);
        $localCall = "const MaceAddr& destAddr = contextMapping.getNodeByContext(targetContextID);
        if( destAddr == Util::getMaceAddr() ){
            $localCall
        }";
        $returnRPC = qq#
        const mace::string& currentContextID = ThreadStructure::getCurrentContext();

        uint32_t msgseqno = getNextSeqno(targetContextID);
        mace::string returnValueStr;
        $routineMessageName pcopy($copyParam);
        sl.unlock();
        mace::ScopedContextRPC rpc( currentContextID );
        downcall_route( MaceKey( mace::ctxnode, destAddr ), pcopy ,__ctx );
        mace::map<uint8_t, mace::set<mace::string> > uncommittedContexts;
        $seg1
        rpc.get(uncommittedContexts);
        ThreadStructure::setEventContexts( uncommittedContexts ); 
        $returnRPCValue
        #;
    }
    $helperBody .= qq#
    {
        ScopedLock sl( mace::ContextBaseClass::__internal_ContextMutex );
        $localCall
        $returnRPC
      }
    #;
    $helpermethod->body($helperBody);
    return $helpermethod;
}
1;
