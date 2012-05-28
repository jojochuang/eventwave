#
# ServiceImpl.pm : part of the Mace toolkit for building distributed systems
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
package Mace::Compiler::ServiceImpl;

use Data::Dumper;

#TODO: hashState default implementation in ServiceClass!

use strict;
use Class::MakeMethods::Utility::Ref qw( ref_clone );
use Mace::Compiler::ClassCache;
use Mace::Compiler::SQLize;
use Switch 'Perl6';

use Class::MakeMethods::Template::Hash
    (
     'new' => 'new',

     #[[[The following structures are all storing state as its being parsed

     'string' => 'name',
     'string' => 'header',
     'array'  => 'provides',
     'string'  => 'attributes', #Stored as comma separated list
     'string' => 'registration',
     'string' => 'trace',
     'boolean' => 'macetime',
     'number' => 'locking',   # service-wide locking
     'array' => 'logObjects',
     'hash --get_set_items' => 'wheres',
     'number' => 'queryLine',
     'boolean' => 'logService',
     'string' => 'queryArg',
     'string' => 'queryFile',
     'string' => 'localAddress',
     'hash --get_set_items'   => 'selectors',
     'array_of_objects' => ["constants" => { class => "Mace::Compiler::Param" }],
     'array' => "constants_includes",
     'array_of_objects' => ["constructor_parameters" => { class => "Mace::Compiler::Param" }],
     'array_of_objects' => ["service_variables" => { class => "Mace::Compiler::ServiceVar" }],
     'array'  => 'states',
     'array_of_objects' => ['typedefs' => { class => "Mace::Compiler::TypeDef" }],
     'array_of_objects' => ["state_variables" => { class => "Mace::Compiler::Param" }],
     'array_of_objects' => ["structuredLogs" => { class => "Mace::Compiler::Method" }],
#     'array_of_objects' => ["queries" => { class => "Mace::Compiler::Query" }],
     'array_of_objects' => ["timers" => { class => "Mace::Compiler::Timer" }],
     'array_of_objects' => ["auto_types" => { class => "Mace::Compiler::AutoType" }],
     'array_of_objects' => ["messages" => { class => "Mace::Compiler::AutoType" }],
     'array_of_objects' => ["detects" => { class => "Mace::Compiler::Detect" }],
     'array_of_objects' => ["contexts" => { class => "Mace::Compiler::Context" }],

     #These are the parsed Methods for remapping
     'array_of_objects' => ["usesDowncalls" => { class => "Mace::Compiler::Method" }],
     'array_of_objects' => ["usesUpcalls" => { class => "Mace::Compiler::Method" }],
     'array_of_objects' => ["implementsUpcalls" => { class => "Mace::Compiler::Method" }],
     'array_of_objects' => ["implementsDowncalls" => { class => "Mace::Compiler::Method" }],

     #These are methods added for asynchrony
     'array_of_objects' => ["asyncMethods" => { class => "Mace::Compiler::Method" }],
     'array_of_objects' => ["asyncHelperMethods" => { class => "Mace::Compiler::Method" }],
     'array_of_objects' => ["asyncDispatchMethods" => { class => "Mace::Compiler::Method" }],

		 #These are methods added for synchronized calls
		 'array_of_objects' => ["syncMethods" => { class => "Mace::Compiler::Method"}], 
		 'array_of_objects' => ["syncHelperMethods" => { class => "Mace::Compiler::Method"}],

		 #These are methods added for contexted routine calls
		 'array_of_objects' => ["routineHelperMethods" => { class => "Mace::Compiler::Method"}],

		 #'hash' => "transitionSnapshotContexts", 

     'array_of_objects' => ["routines" => { class => "Mace::Compiler::Method" }],
     'array_of_objects' => ["routineObjects" => { class => "Mace::Compiler::RoutineObject" }],
     'array_of_objects' => ["transitions" => { class => "Mace::Compiler::Transition" }],
     'number' => "transitionEnd",
     'string' => "transitionEndFile",
     'hash --get_set_items' => 'rawTransitions',
     'array_of_objects' => ["safetyProperties" => { class => "Mace::Compiler::Properties::Property" }],
     'array_of_objects' => ["livenessProperties" => { class => "Mace::Compiler::Properties::Property" }],

     #End state from parse]]]

     'array' => 'ignores',
     'array' => 'deferNames',

     'hash --get_set_items' => 'selectorVars',
     'array_of_objects' => ['upcallDeferMethods' => { class => "Mace::Compiler::Method" }],
     'array_of_objects' => ['downcallDeferMethods' => { class => "Mace::Compiler::Method" }],
     'array_of_objects' => ['routineDeferMethods' => { class => "Mace::Compiler::Method" }],


     #These are the API methods this service is providing - upcalls and downcalls for transitions
     'array_of_objects' => ['providedMethods' => { class => "Mace::Compiler::Method" }],
     'array_of_objects' => ['usesHandlerMethods' => { class => "Mace::Compiler::Method" }],
     'array_of_objects' => ['timerMethods' => { class => "Mace::Compiler::Method" }],
     'array_of_objects' => ['timerHelperMethods' => { class => "Mace::Compiler::Method" }],
     #These are the API methods this service is providing - public interface calls
     'array_of_objects' => ['providedMethodsAPI' => { class => "Mace::Compiler::Method" }],
     'array_of_objects' => ['usesHandlerMethodsAPI' => { class => "Mace::Compiler::Method" }],
     #These are the API methods this service is providing - private serial forms only
     'array_of_objects' => ['providedMethodsSerials' => { class => "Mace::Compiler::Method" }],
     'array_of_objects' => ['usesHandlerMethodsSerials' => { class => "Mace::Compiler::Method" }],

     #These are the aspect transition methods.
     'array_of_objects' => ["aspectMethods" => { class => "Mace::Compiler::Method" }],
     'array_of_objects' => ["onChangeVars" => { class => "Mace::Compiler::Param" }],

     'array' => 'usesHandlers',
     'hash_of_arrays' => ['usesHandlerNames' => 'string'],

     #These are the upcalls this service may make -- a unified list and a per-handler list
     'array_of_objects' => ['providedHandlerMethods' => { class => "Mace::Compiler::Method" }],
     'array_of_objects' => ['providedHandlers' => { class => "Mace::Compiler::ServiceClass" }],

     #These are the downcalls this service may make -- a unified list and a per-serviceclass list
     'array_of_objects' => ['usesClassMethods' => { class => "Mace::Compiler::Method" }],
     'hash_of_arrays' => ['usesClasses' => { class => "Mace::Compiler::Method" }],

     #This stack of guard methods is used during parsing to parse guard blocks
     'array_of_objects' => ['guards' => { class => 'Mace::Compiler::Guard' }],

     'object' => ['parser' => { class => "Parse::RecDescent" }],

     'string' => "origMacFile",
     'string' => "annotatedMacFile",

     'array' => "downcall_registrations",

     'boolean' => 'addFailureRecoveryHack',

     'object' => ['asyncExtraField' => { class => "Mace::Compiler::AutoType" }],
    );
my %transitionNameMap;

sub toString {
    my $this = shift;
    my $s =
	"Service: ".$this->name()."\n"
	    . "Provides: ".join(', ', $this->provides())."\n"
		. "Trace Level: ".$this->trace()."\n"
		    ;

    $s .= "Selectors { \n";
    while ( my ($selector, $selstring) = each(%{$this->selectors()}) ) {
	$s .= "  $selector = $selstring\n";
    }
    $s .= "}\n";

    $s .= "Constants { \n";
    $s .= join("", map { "  ".$_->toString().";\n" } $this->constants());
    $s .= "}\n";

    $s .= "Constructor Parameters { \n";
    $s .= join("", map { "  ".$_->toString().";\n" } $this->constructor_parameters());
    $s .= "}\n";

    $s .= "States { " . join(', ', $this->states()) . " }\n";

    $s .= "Service Variables { \n";
    $s .= join("", map { "  ".$_->toString().";\n" } $this->service_variables());
    $s .= "}\n";

    $s .= "Typedefs { \n";
    while ( my ($id, $type) = each(%{$this->typedefs()}) ) {
	$s .= "  $id => ".$type->toString()."\n";
    }
    $s .= "}\n";

    $s .= "State Variables { \n";
    $s .= join("", map { "  ".$_->toString(nodefaults => 1).";\n" } $this->state_variables());
    $s .= "}\n";

    $s .= "Auto Types { \n";
    $s .= join("", map { "  ".$_->toString().";\n" } $this->auto_types());
    $s .= "}\n";

    $s .= "Messages { \n";
    $s .= join("", map { "  ".$_->toString().";\n" } $this->messages());
    $s .= "}\n";

    $s .= "Uses Upcalls { \n";
    $s .= join("", map { "  ".$_->toString().";\n" } $this->usesUpcalls());
    $s .= "}\n";

    $s .= "Uses Downcalls { \n";
    $s .= join("", map { "  ".$_->toString().";\n" } $this->usesDowncalls());
    $s .= "}\n";

    $s .= "Implements Upcalls { \n";
    $s .= join("", map { "  ".$_->toString().";\n" } $this->implementsUpcalls());
    $s .= "}\n";

    $s .= "Implements Downcalls { \n";
    $s .= join("", map { "  ".$_->toString().";\n" } $this->implementsDowncalls());
    $s .= "}\n";

    $s .= "Routines { \n";
    $s .= join("", map { "  ".$_->toString().";\n" } $this->routines());
    $s .= "}\n";

    $s .= "Routine Objects { \n";
    $s .= join("", map { "  ".$_->toString().";\n" } $this->routineObjects());
    $s .= "}\n";

    $s .= "Transitions { \n";
    $s .= join("", map { "  ".$_->toString().";\n" } $this->transitions());
    $s .= "}\n";

    return $s;
}

sub printHFile {
    my $this = shift;
    my $outfile = shift;

    my $servicename = $this->name();

    my $r = Mace::Compiler::GeneratedOn::generatedOnHeader("$servicename header file");
    print $outfile $r;

    print $outfile <<END;

#ifndef ${servicename}_header
#define ${servicename}_header

END

    $this->printIncludesH($outfile);
    $this->printUsingH($outfile);
    $this->printIncludeBufH($outfile);

    print $outfile <<END;
    namespace ${servicename}_namespace {

        void load_protocol();

END
    #  $this->printConstantsH($outfile);
    $this->printSelectorConstantsH($outfile);

    $this->printAutoTypeForwardDeclares($outfile);
    $this->printTypeDefs($outfile);

    my $messageDeclares = join("", map {$_->toForwardDeclare()} $this->messages());
    print $outfile qq{
	//Message Declarations
	$messageDeclares
    };
    my @contexts = $this->contexts();
    my $contextForwardDeclares = $this->printContextForwardDeclaration( \@contexts );
    print $outfile qq{
	//Context Forward Declarations
	$contextForwardDeclares
    };

    print $outfile "\nclass ${servicename}Service;\n";
    print $outfile "typedef ${servicename}Service ServiceType;\n";
    print $outfile "typedef std::deque<std::pair<uint64_t, const ServiceType*> > VersionServiceMap;\n";
    print $outfile "typedef mace::map<int, ${servicename}Service const *, mace::SoftState> _NodeMap_;\n";
    print $outfile "typedef mace::map<MaceKey, int, mace::SoftState> _KeyMap_;\n";

		#bsang: print defined public classes on a physical node
		print $outfile "mace::map<mace::string, mace::string> returnValueMapping;\n";
		print $outfile "std::map<mace::string, pthread_cond_t*> awaitingReturnMapping;\n";

    print $outfile qq/static const char* __SERVICE__ __attribute((unused)) = "${servicename}";\n/;
    print $outfile qq/mace::ContextMapping contextMapping;\n/;
    $this->printAutoTypes($outfile);
    $this->printContextClasses($outfile, \@contexts );
    $this->printDeferTypes($outfile);
    $this->printService($outfile);
    print $outfile $this->generateMergeClasses();
    $this->printRoutineObjects($outfile);
    $this->printMessages($outfile);
    $this->printTimerClasses($outfile);

#    print $outfile "\nclass ${servicename}Dummy;\n";
#    $this->printDummyClass($outfile);
#    $this->printTimerDummyClasses($outfile);
    $this->printStructuredLogDummies($outfile);
    print $outfile <<END;
    }
#endif
END

} # printHFile

sub printContextForwardDeclaration {
    my $this = shift;
    my $contexts = shift;
    my $r = ""; #class mace::ContextBaseClass;\n";

    my @subcontexts;
    foreach my $context( @{$contexts} ) {
        #print $outfile $context->toString($this->name()."Service",traceLevel => $this->traceLevel()) . "\n";
        $r .= "class $context->{className};\n";
        push @subcontexts,$context->subcontexts();
    }
    if( @subcontexts != 0 ){
        $r .= $this->printContextForwardDeclaration(\@subcontexts);
    }
    return $r;
}

sub printStructuredLogDummies {
    my $this = shift;
    my $outfile = shift;

    for my $log ($this->structuredLogs()) {
	if ($log->doStructuredLog()) {
	    $this->printStructuredLogMemoryDummy($log, $outfile, 0);
	}
    }

    for my $at ($this->auto_types()) {
	for my $m ($at->methods()) {
	    if ($m->doStructuredLog()) {
		$this->printStructuredLogDummy($m, $outfile, 0);
	    }
	}
    }

    for my $slog (grep(!($_->name =~ /^(un)?register.*Handler$/), $this->providedMethods()), @{$this->aspectMethods()}, @{$this->usesHandlerMethods()}, @{$this->timerMethods()}) {
#	if (not $slog->messageField() and (defined $slog->options('transitions') or scalar(grep {$_ eq $slog->name} $this->ignores()))) {
	if ($slog->doStructuredLog()) {
	    #&& $slog->shouldLog()) {
	    $this->printStructuredLogDummy($slog, $outfile, 0);
	}
    }
    for my $slog (@{$this->usesClassMethods()}) {
	if ($slog->doStructuredLog()) {
	    #&& $slog->shouldLog()) {
	    $this->printStructuredLogDummy($slog, $outfile, 0);
	}
    }
    for my $slog (@{$this->providedHandlerMethods()}) {
	if ($slog->doStructuredLog()) {
	    #&& $slog->shouldLog()) {
	    $this->printStructuredLogDummy($slog, $outfile, 0);
	}
    }
    for my $slog ($this->routines()) {
	if ($slog->doStructuredLog()) {
	    #&& $slog->shouldLog()) {
	    $this->printStructuredLogDummy($slog, $outfile, 1);
	}
    }
}

sub printStructuredLogMemoryDummy {
    my $this = shift;
    my $log = shift;
    my $outfile = shift;
    my $ll = shift;

    if ($log->messageField() or $log->getLogLevel($this->traceLevel()) <= $ll) {
        return;
    }

    my $name = $this->name();
    my $logName = (defined $log->options('binlogname')) ? $log->options('binlogname') : $log->name();
    my $shortName = (defined $log->options('binlogshortname')) ? $log->options('binlogshortname') : $log->name();
    my $longName = (defined $log->options('binloglongname')) ? $log->options('binloglongname') : $log->name();
    #print "DEBUG: Printing $name -- $logName Dummy -- ".$log->getLogLevel($this->traceLevel())."\n";
    my $className = "class ${logName}Dummy : public mace::BinaryLogObject, public mace::PrintPrintable";
    my $param;
    my $pname;
    my $printBody = qq{out << "$shortName(";\n};
#    my $serialBody = "";
    my $constructor1 = "${logName}Dummy() ";
    my @constructor1initlist;
    my $constructor2 = "${logName}Dummy(";
    my @constructor2varlist;
    my @constructor2initlist;
    my $destructorBody = "";

    print $outfile "$className {\n";
    print $outfile "protected:\n";
    print $outfile "static mace::LogNode* rootLogNode;\n";
    print $outfile "public:\n";

    for $param ($log->params()) {
	$pname = $param->name();
	my $ptype = $param->type()->type();
	print $outfile "$ptype $pname;\n";
#	print $outfile "$newType $pname;\n";
	$printBody .= qq{out << "[$pname=";
mace::printItem(out, &$pname);
out << "]";
};
	if (!@{$this->logObjects()}) {
	    # if there are no objects to log (no queries block), then
	    # log everything
	    $param->shouldLog(1);
	}
#        $serialBody .= "mace::serialize(__str, &$pname);\n";
        push @constructor1initlist, "_$pname(new $ptype()), $pname(*_$pname)";
        push @constructor2varlist, "$ptype ___$pname";
        push @constructor2initlist, "$pname(___$pname)";
#        $destructorBody .= "if (_$pname != NULL) { delete _$pname; _$pname = NULL; }\n";
    }

    if ($log->count_params()) {
        $constructor1 .= ": ". join(", ", @constructor1initlist) . " { }\n";
        $constructor2 .= join(", ", @constructor2varlist). ") : ". join(", ", @constructor2initlist) . " { }\n";;
    } else {
        $constructor1 .= " { }\n";
        $constructor2 = "";
    }

    print $outfile <<END;

    const std::string& getLogType() const {
        static std::string type = "${name}_${logName}";
	return type;
    }

    const std::string& getLogDescription() const {
        static const std::string desc = "${name}::${longName}";
        return desc;
    }

    LogClass getLogClass() const {
        return SERVICE_BINLOG;
    }

    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }

    $constructor2

    ~${logName}Dummy() {
    }

    void serialize(std::string& __str) const {
    }

    int deserialize(std::istream& is) throw(mace::SerializationException) {
	int bytes = 0;
	return bytes;
    }
END
    my $body;
#    for $param ($log->params()) {
#	$pname = $param->name();
#	$body .= "bytes += mace::deserialize(is, _$pname);\n";
#    }
#    $body .= "return bytes;\n}\n";
    $body .= "void print(std::ostream& out) const {\n";
    $body .= qq~$printBody out << ")";\n}\n~;
    print $outfile $body;
    my $sqlizeBody = Mace::Compiler::SQLize::generateBody(\@{$log->params()}, 0, 0);

    print $outfile <<END;
    void sqlize(mace::LogNode* __node) const {
	$sqlizeBody
    }
    };
END
}

sub printStructuredLogDummy {
    my $this = shift;
    my $log = shift;
    my $outfile = shift;
    my $ll = shift;

#    if ($log->messageField() or $log->getLogLevel($this->traceLevel()) <= $ll) {
#        return;
#    }

    if ($log->getLogLevel($this->traceLevel()) <= $ll) {
        return;
    }

    my $name = $this->name();
    my $logName = (defined $log->options('binlogname')) ? $log->options('binlogname') : $log->name();
    my $shortName = (defined $log->options('binlogshortname')) ? $log->options('binlogshortname') : $log->name();
    my $longName = (defined $log->options('binloglongname')) ? $log->options('binloglongname') : $log->name();
    #print "DEBUG: Printing $name -- $logName Dummy -- ".$log->getLogLevel($this->traceLevel())."\n";
    my $className = "class ${logName}Dummy : public mace::BinaryLogObject, public mace::PrintPrintable";
    my $param;
    my $pname;
    my $printBody = qq{out << "$shortName(";\n};
#    my $serialBody = "";
    my $constructor1 = "${logName}Dummy() ";
    my @constructor1initlist;
    my $constructor2 = "${logName}Dummy(";
    my @constructor2varlist;
    my @constructor2initlist;
    my $destructorBody = "";

    print $outfile "$className {\n";
    print $outfile "protected:\n";
    print $outfile "static mace::LogNode* rootLogNode;\n";
    print $outfile "public:\n";

    if (!$log->messageField()) {
	for $param ($log->params()) {
	    $pname = $param->name();
	    my $ptype = $param->type()->type();
	    print $outfile "$ptype* _$pname;\n";
	    my $const = "";
	    my $numStars = ($ptype =~ tr/\*//);
	    my $newType = "const $ptype&";

	    if ($numStars > 0) {
		$ptype =~ /([^*]+)[*]*/;
		$newType = $1;
		for (my $i = 0; $i < $numStars; $i++) {
		    $newType .= " const*";
		}
		$newType .= " const&";
	    }
	    print $outfile "$newType $pname;\n";
	    $printBody .= qq{out << "[$pname=";
			     mace::printItem(out, &$pname);
			     out << "]";
			 };
	    if (!@{$this->logObjects()}) {
		# if there are no objects to log (no queries block), then
		# log everything
		$param->shouldLog(1);
	    }
#        $serialBody .= "mace::serialize(__str, &$pname);\n";
	    push @constructor1initlist, "_$pname(new $ptype()), $pname(*_$pname)";
	    push @constructor2varlist, "$newType ___$pname";
	    push @constructor2initlist, "_$pname(NULL), $pname(___$pname)";
	    $destructorBody .= "if (_$pname != NULL) { delete _$pname; _$pname = NULL; }\n";
	}
    }
    if ($log->count_params() and !$log->messageField()) {
        $constructor1 .= ": ". join(", ", @constructor1initlist) . " { }\n";
        $constructor2 .= join(", ", @constructor2varlist). ") : ". join(", ", @constructor2initlist) . " { }\n";;
    } else {
        $constructor1 .= " { }\n";
        $constructor2 = "";
    }

    print $outfile <<END;

    const std::string& getLogType() const {
        static std::string type = "${name}_${logName}";
	return type;
    }

    const std::string& getLogDescription() const {
        static const std::string desc = "${name}::${longName}";
        return desc;
    }

    LogClass getLogClass() const {
        return SERVICE_BINLOG;
    }

    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }

    $constructor1

    $constructor2

    ~${logName}Dummy() {
        $destructorBody
    }

    void serialize(std::string& __str) const {
    }

    int deserialize(std::istream& is) throw(mace::SerializationException) {
	int bytes = 0;
	return bytes;
    }
END
    my $body;
#    for $param ($log->params()) {
#	$pname = $param->name();
#	$body .= "bytes += mace::deserialize(is, _$pname);\n";
#    }
#    $body .= "return bytes;\n}\n";
    $body .= "void print(std::ostream& out) const {\n";
    $body .= qq~$printBody out << ")";\n}\n~;
    print $outfile $body;
    my $sqlizeBody;

    if (!$log->messageField()) {
	$sqlizeBody = Mace::Compiler::SQLize::generateBody(\@{$log->params()}, 0, 0);
    }
    else {
	my @emptyArr;
	$sqlizeBody = Mace::Compiler::SQLize::generateBody(\@emptyArr, 0, 0);
    }

    print $outfile <<END;
    void sqlize(mace::LogNode* __node) const {
	$sqlizeBody
    }
    };
END
}

sub printDeferTypes {
    my $this = shift;
    my $outfile = shift;
    print $outfile <<EOF;
    //BEGIN Mace::Compiler::ServiceImpl::printDeferTypes
EOF

    for my $m ($this->upcallDeferMethods(), $this->downcallDeferMethods(), $this->routineDeferMethods()) {
	print $outfile generateDeferType($m);
    }
    print $outfile <<EOF;
    //END Mace::Compiler::ServiceImpl::printDeferTypes
EOF

}

sub generateDeferType {
    my $m = shift;
    my $n = getVarFromMethod($m);
    my $type = "__DeferralArgsFor${n}";
    my $r = "struct $type {\n";
    $r .= "uint64_t __calltime;\n";
    $r .= "$type() : __calltime(TimeUtil::timeu()) { };\n";
    if ($m->count_params()) {
	$r .= ("$type(\n" .
	       join(", ", map{$_->toString(paramconst => 1, paramref=> 1)}
		    $m->params()) .") : __calltime(TimeUtil::timeu()), " .
	       join(", ", map{$_->name()."(".$_->name().")"} $m->params()) .
	       "{ }\n");
	$r .= join("\n", map{$_->type()->type()." ".$_->name().";"} $m->params());
    }
    $r .= "};\n";
    return $r;
}

sub generateProcessDefer {
    my $type = shift;
    my @marr = @_;
    if (scalar(@marr) == 0) {
	return "";
    }
    if ($type) {
	$type .= "_";
    }
    my $r = "";
    $r .= "while (" . join(" || ", map { "!__deferralArgList_" . getVarFromMethod($_) . ".empty()" } @marr) . ") {
uint64_t _firstcall = std::numeric_limits<uint64_t>::max();
";
    for my $m (@marr) {
	my $varm = getVarFromMethod($m);
	my $vl = "__deferralArgList_${varm}";
	$r .= "if (!$vl.empty()) { _firstcall = std::min(_firstcall, $vl.front().__calltime); }\n";
    }

    for my $m (@marr) {
	my $varm = getVarFromMethod($m);
	my $vl = "__deferralArgList_${varm}";
	$r .= "if (!$vl.empty() && _firstcall == $vl.front().__calltime) {\n";
	if ($m->count_params()) {
	    $r .= "__DeferralArgsFor${varm}& a = __deferralArgList_${varm}.front();\n";
	}
	$r .= $type . $m->name() . "(" . join(", ", map { "a." . $_->name() } $m->params()) . ");
__deferralArgList_${varm}.pop_front();
}\n";
    }
    $r .= "}\n";
    return $r;
}

sub generateAddDefer {
    my $this = shift;
    my $type = shift;
    my $methods = shift;
    my $name = $this->name();
    if ($type) {
	$type .= "_";
    }

    # Note: add defer to the parameters included in per-method. it has two types - up / downcall.
    return map{"void ".$_->toString(noreturn=>1,nodefaults=>1,methodprefix=>"${name}Service::defer_${type}",
						 noid=> 0, novirtual => 1).
						     " { mace::ScopedStackExecution::addDefer(this); __deferralArgList_".
							 getVarFromMethod($_).".push_back(__DeferralArgsFor".getVarFromMethod($_)."(".
						     join(",", map{ $_->toString(notype=>1, nodefaults=>1, noline=>1) } $_->params()).")); }"
			} @$methods;
}

sub printCCFile {
    my $this = shift;
    my $outfile = shift;

    my $servicename = $this->name();

    my $serviceVariableString = '';
    #  my $serviceVariableString = join("\n", map{my $sv=$_->service; qq{#include "$sv.h"
    #                                                                 using ${sv}_namespace::${sv}Service;}} $this->service_variables());
    my $timerDelete = join("\n", map{my $t = $_->name(); "delete &$t;"} $this->timers());
    my $unregisterInstance = join("\n", map{ qq/mace::ServiceFactory<${_}ServiceClass>::unregisterInstance("${\$this->name}", this);/ } $this->provides());
    my $modelCheckSafety = join("\n", map{"// ${\$_->toString()}
      ${\$_->toMethod(nostatic=>1, methodprefix=>$servicename.qq/Service::/)}"    } $this->safetyProperties);
    my $modelCheckLiveness = join("\n", map{"// ${\$_->toString()}
      ${\$_->toMethod(nostatic=>1, methodprefix=>$servicename.qq/Service::/)}"    } $this->livenessProperties);

    my $r = Mace::Compiler::GeneratedOn::generatedOnHeader("$servicename main source file");
    my $sqlizeBody = Mace::Compiler::SQLize::generateBody(\@{$this->state_variables()}, 1, 1);

    my $incSimBasics = "";
    if ($this->count_safetyProperties() or $this->count_livenessProperties()) {
        $incSimBasics = qq/#include "SimulatorBasics.h"/;
    }

    print $outfile $r;
    print $outfile <<END;
    //BEGIN Mace::Compiler::ServiceImpl::printCCFile
#include "mace.h"
#include "NumberGen.h"
$incSimBasics
#include "$servicename.h"
#include "$servicename-macros.h"
#include "Enum.h"
#include "Log.h"
#include "ScopedLock.h"
#include "MaceTime.h"
#include "ScopedLog.h"
#include "ScopedSerialize.h"
#include "pip_includer.h"
#include "AsyncDispatch.h"
#include "lib/MaceTime.h"
#include "lib/ServiceFactory.h"
#include "lib/ServiceConfig.h"
#include <boost/algorithm/string.hpp>
#include "lib/SysUtil.h"

    bool operator==(const mace::map<int, mace::map<int, ${servicename}_namespace::${servicename}Service*, mace::SoftState>::const_iterator, mace::SoftState>::const_iterator& lhs, const mace::map<int, ${servicename}_namespace::${servicename}Service*, mace::SoftState>::const_iterator& rhs) {
        return lhs->second == rhs;
    }
    bool operator==(const mace::map<int, ${servicename}_namespace::${servicename}Service*, mace::SoftState>::const_iterator& lhs, const mace::map<int, mace::map<int, ${servicename}_namespace::${servicename}Service*, mace::SoftState>::const_iterator, mace::SoftState>::const_iterator& rhs) {
        return lhs == rhs->second;
    }
END
    print $outfile "namespace mace {\ntemplate<typename T> mace::LogNode* mace::SimpleLogObject<T>::rootLogNode = NULL;\n}\n";
    print $outfile <<END;
    namespace ${servicename}_namespace {
    mace::LogNode* ${servicename}Service::rootLogNode = NULL;
//    mace::LogNode* ${servicename}Dummy::rootLogNode = NULL;
        //Selector Constants
END

    $this->printSelectorConstantsCC($outfile);

    print $outfile <<END;
	//Change Tracker (optional)
END
    $this->printChangeTracker($outfile);

    print $outfile <<END;

	//service variable includes and uses
	    $serviceVariableString

	    //Transition and Guard Implementations
END

    $this->printTransitions($outfile);

    print $outfile <<END;

	//Structured Logging Functions
END
    $this->printStructuredLogs($outfile);

    print $outfile <<END;
    // logging funcs
END
    $this->shouldLogFuncsBody($outfile);

    print $outfile <<END;

	//Auto Type Methods
END
    $this->defineAutoTypeMethods($outfile);

    print $outfile <<END;

	//Routines
END

    $this->printRoutines($outfile);

    print $outfile <<END;

	//Timer Demux (and utility timer)
END

    $this->printTimerDemux($outfile);

    my $getMessageNameCases = join("\n", map{my $n = $_->name; qq{case ${n}::messageType: return "${servicename}::$n";}} $this->messages());
    my $getStateNameCases = join("\n", map{qq/case $_: return "${servicename}::$_";/} $this->states());
    my $traceStateChange = ($this->traceLevel() > 0)? q{Log::logf(selectorId, "FSM: state changed to %s", getStateName(state));}:"";
#    my $printStateVars = join("\n", map { $_ . " __out << std::endl;" } (grep(/./, map { $_->toPrint("__out") } $this->state_variables())));
    my $printNodeStateVars = join("\n", map { $_->toPrintNode("__printer") } $this->state_variables());
    my $printStateVars = join("\n", map { $_ . " __out << std::endl;" } (grep(/./, map { $_->toPrint("__out",0) } $this->state_variables())));
    my $printState_StateVars = join("\n", grep(/./, map { $_->toPrintState("__out") } $this->state_variables()));
    my $serializeStateVars = "mace::serialize(__str, &state);\n" . join("\n", (grep(/./, map { $_->toSerialize("__str") } $this->state_variables())));
    my $serializeContexts = join("\n", (grep(/./, map { $_->toSerialize("__str") } $this->contexts())));
    my $deserializeContexts = join("\n", (grep(/./, map { $_->toDeserialize("__in", prefix => "serializedByteSize += ") } $this->contexts())));
    my $deserializeStateVars = "serializedByteSize += mace::deserialize(__in, &_actual_state);\n" . join("\n", (grep(/./, map { $_->toDeserialize("__in", prefix => "serializedByteSize += ") } $this->state_variables())));
#    my $printScheduledTimers = join("\n", map { $_->toPrint("__out")." __out << std::endl;" } $this->timers());
    my $printNodeScheduledTimers = join("\n", map { $_->toPrintNode("__printer") } $this->timers());
    my $printScheduledTimers = join("\n", map { $_->toPrint("__out", 0)." __out << std::endl;" } $this->timers());
    my $printState_ScheduledTimers = join("\n", map { $_->toPrintState("__out") } $this->timers());
    my $serializeScheduledTimers = join("\n", map { $_->toSerialize("__str") } $this->timers());
    my $deserializeScheduledTimers = join("\n", map { $_->toDeserialize("__in", prefix => "serializedByteSize += ") } $this->timers());
    my $printLowerServices = join("\n", map { unless($_->intermediate()) {" << _".$_->name()} else {""} } $this->service_variables());
    my $printState_LowerServices = join("\n", map { $_->toPrintState("__out") } $this->service_variables());

    # Note : deferred calls are handled in here...
    my $deferralCalls = "";
    $deferralCalls .= generateProcessDefer("upcall", $this->upcallDeferMethods());
    $deferralCalls .= generateProcessDefer("downcall", $this->downcallDeferMethods());
    $deferralCalls .= generateProcessDefer("", $this->routineDeferMethods());

    my $processDeferred = "void ${servicename}Service::processDeferred() { $deferralCalls }";
    if ($this->traceLevel() > 2) {
        $processDeferred = qq~void ${servicename}Service::processDeferred() {
            $deferralCalls
	    ~;
	    if ($this->logService()) {
		my $clause = $this->wheres->{$servicename};
		my $logStr = "Log::binaryLog(logid, *this);\n";

		if (defined($clause)) {
		    $logStr = "if $clause {\n" . $logStr . "}\n";
		}
		$logStr = "if (mace::LogicalClock::instance().shouldLogPath()) {\n" . $logStr . "}\n";
		$processDeferred .= qq~static const log_id_t logid = Log::getId("SNAPSHOT::${servicename}");
		// log to both text and binary logs for now until we come up with a good solution
		~;
		$processDeferred .= $logStr;
	    }
	    $processDeferred .= "}\n";
#        } ~;
    }
    my $code_getCurrentMode;
    my $code_snapshotVersion;
    my $code_WRITE_MODE;
    my $code_READ_MODE;
    if(  @{ $this->contexts() }   ) {
        $code_getCurrentMode = "mace::ContextBaseClass::globalContext.getCurrentMode()";
        $code_snapshotVersion = "mace::ContextBaseClass::globalContext.getSnapshotVersion()";
        $code_WRITE_MODE = "mace::ContextLock::WRITE_MODE";
        $code_READ_MODE = "mace::ContextLock::READ_MODE";
    }else{
        $code_getCurrentMode = "mace::AgentLock::getCurrentMode()";
        $code_snapshotVersion = "mace::AgentLock::snapshotVersion()";
        $code_WRITE_MODE = "mace::AgentLock::WRITE_MODE";
        $code_READ_MODE = "mace::AgentLock::READ_MODE";
    }

    my $accessorMethods = qq#
        const ServiceType::state_type& ${servicename}Service::read_state() const {
            int currentMode = $code_getCurrentMode;
            if (USING_RWLOCK || currentMode == $code_WRITE_MODE) { 
                return state;
            }
            else if (currentMode == $code_READ_MODE) {
                VersionServiceMap::const_iterator i = versionMap.begin();
                uint64_t sver = $code_snapshotVersion;
                while (i != versionMap.end()) {
                    if (i->first == sver) {
                        break;
                    }
                    i++;
                }
                if (i == versionMap.end()) {
                    Log::err() << "Error reading from snapshot " << $code_getCurrentMode << " ticket " << ThreadStructure::myTicket() << Log::endl;
                    std::cerr << "Error reading from snapshot " << $code_getCurrentMode << " ticket " << ThreadStructure::myTicket() << std::endl;
                    ABORT("Tried to read from snapshot, but snapshot not available!");
                }
                return i->second->state;
            }
            else {
                ABORT("Invalid attempt to access state from NONE_MODE!");
            }
        }

    #;
    $accessorMethods .= join("\n",
      map {
      my $n = $_->name();
      if( $n =~ m/^__internal_/ ){
        qq//
      }else{
          my $t = $_->type()->toString(paramconst => 1, paramref => 1);
      qq#
        $t ${servicename}Service::read_$n() const {
            int currentMode = $code_getCurrentMode;
            if (USING_RWLOCK || currentMode == $code_WRITE_MODE) { 
                return $n;
            }
            else if (currentMode == $code_READ_MODE) {
                VersionServiceMap::const_iterator i = versionMap.begin();
                uint64_t sver = $code_snapshotVersion;
                while (i != versionMap.end()) {
                    if (i->first == sver) {
                        break;
                    }
                    i++;
                }
                if (i == versionMap.end()) {
                    Log::err() << "Error reading from snapshot " << $code_getCurrentMode << " ticket " << ThreadStructure::myTicket() << Log::endl;
                    std::cerr << "Error reading from snapshot " << $code_getCurrentMode << " ticket " << ThreadStructure::myTicket() << std::endl;
                    ABORT("Tried to read from snapshot, but snapshot not available!");
                }
                return i->second->$n;
            }
            else {
                ABORT("Invalid attempt to access state from NONE_MODE!");
            }
        }
      #
      }
      } $this->state_variables()
    );

    print $outfile <<END;

    //Load Protocol

END

    $this->printLoadProtocol($outfile);

    print $outfile <<END;

    //Constructors
END

    $this->printConstructor($outfile);
    my $updateInternalContextMethod="";
    my $requestContextMigrationMethod= "";
    # chuangw: FIXME: update context id, not MaceKey
    if($Mace::Compiler::Globals::supportFailureRecovery && scalar( @{ $this->contexts() } )> 0 && $this->addFailureRecoveryHack() ) {
        $updateInternalContextMethod = qq#

        // assuming this method is called to resume from a previous process, XXX: is there any other use for serializing service class?
        // update internal message buffer using the old 
        /*ScopedLock sl(mace::ContextBaseClass::__internal_ContextMutex);
        if( __internal_unAck.find( oldNode ) != __internal_unAck.end() ){
            __internal_unAck[ newNode ] = __internal_unAck[ oldNode ];
            __internal_unAck.erase( oldNode );
        }
        if( __internal_receivedSeqno.find( oldNode ) != __internal_receivedSeqno.end() ){
            __internal_receivedSeqno[ newNode ] = __internal_receivedSeqno[ oldNode ];
            __internal_receivedSeqno.erase( oldNode );
        }
        if( __internal_lastAckedSeqno.find( oldNode ) != __internal_lastAckedSeqno.end() ){
            __internal_lastAckedSeqno[ newNode ] = __internal_lastAckedSeqno[ oldNode ];
            __internal_lastAckedSeqno.erase( oldNode );
        }
        if( __internal_msgseqno.find( oldNode ) != __internal_msgseqno.end() ){
            __internal_msgseqno[ newNode ] = __internal_msgseqno[ oldNode ];
            __internal_msgseqno.erase( oldNode );
        }*/
    #;
        $requestContextMigrationMethod = qq#
            ADD_SELECTORS("${servicename}Service::requestContextMigration");
            // ignore if I'm not head node
            if( ContextMapping::getHead() != localAddress() ) return;

            // create a migration event
            mace::HighLevelEvent he( mace::HighLevelEvent::ASYNCEVENT );
            mace::string buf; // chuangw: head stores this incoming message.
            mace::serialize(buf,&contextID);
            mace::serialize(buf,&destNode);
            mace::serialize(buf,&isRoot);
            mace::HierarchicalContextLock hl( he, buf );
            ScopedLock sl( mace::ContextBaseClass::__internal_ContextMutex ); // protect internal structure
            if( isRoot ){
                ABORT("Not implemented yet....");
            }else{
            }
            mace::string globalContextID = "";
            ContextMigrationRequest msg( contextID, destNode, isRoot, he.eventID, globalContextID );
            // send to global... ( another assumption: global context does not migrate )
            downcall_route( ContextMapping::getNodeByContext( globalContextID ) , msg);
        #;
    }

    print $outfile <<END;

	//Destructor
	    ${servicename}Service::~${servicename}Service() {
		$timerDelete
                $unregisterInstance
		}

    // Methods for snapshotting...
    void ${servicename}Service::snapshot(const uint64_t& ver) const {
        ADD_SELECTORS("${servicename}Service::snapshot");
        //Assumes state is locked.
        ${servicename}Service* _sv = new ${servicename}Service(*this);
        macedbg(1) << "Snapshotting version " << ver << " for this " << this << " value " << _sv << Log::endl;
        ASSERT(versionMap.empty() || versionMap.back().first < ver);
        versionMap.push_back(std::make_pair(ver,_sv));
    }
    void ${servicename}Service::snapshotRelease(const uint64_t& ver) const {
        ADD_SELECTORS("${servicename}Service::snapshot");
        //Assumes state is locked.
        while (!versionMap.empty() && versionMap.front().first < ver) {
            macedbg(1) << "Deleting snapshot version " << versionMap.front().first << " for service " << this << " value " << versionMap.front().second << Log::endl;
            delete versionMap.front().second;
            versionMap.pop_front();
        }
    }

    $accessorMethods

    //Auxiliary Methods (dumpState, print, serialize, deserialize, processDeferred, getMessageName, changeState, getStateName)
    void ${servicename}Service::dumpState(LOGLOGTYPE& logger) const {
        logger << "state_dump: " << *this << std::endl;
        return;
    }

    void ${servicename}Service::printNode(mace::PrintNode& __pr, const std::string& name) const {
        mace::PrintNode __printer(name, "${servicename}Service");
        const char* __pr_stateName = getStateName(state);
        mace::printItem(__printer, "state", &__pr_stateName);
        $printNodeStateVars
        $printNodeScheduledTimers
        __pr.addChild(__printer);
        return;
    }

    void ${servicename}Service::print(std::ostream& __out) const {
        __out << "state=" << getStateName(state) << std::endl;
        $printStateVars
        $printScheduledTimers
        __out << std::endl;
        if(_printLower) {
            __out $printLowerServices << std::endl;
        }
        return;
    }
    void ${servicename}Service::printState(std::ostream& __out) const {
        __out << "state=" << getStateName(state) << std::endl;
        $printState_StateVars
        $printState_ScheduledTimers
        __out << std::endl;
        if(_printLower) {
            $printState_LowerServices
            }
        return;
    }

    void ${servicename}Service::sqlize(mace::LogNode* __node) const {
        $sqlizeBody
    }

    void ${servicename}Service::serialize(std::string& __str) const {
        $serializeStateVars
        $serializeContexts
        $serializeScheduledTimers
        mace::serialize( __str, &__local_address );
        return;
    }

    int ${servicename}Service::deserialize(std::istream& __in) throw(SerializationException){
        int serializedByteSize = 0;
        $deserializeStateVars
        $deserializeContexts
        $deserializeScheduledTimers

        MaceKey oldLocalAddress;
        serializedByteSize += mace::deserialize(__in, &oldLocalAddress);
        updateInternalContext( oldLocalAddress, __local_address );

        return serializedByteSize;
    }
    void ${servicename}Service::updateInternalContext(const mace::MaceKey& oldNode, const mace::MaceKey& newNode){
        $updateInternalContextMethod
    }
    void ${servicename}Service::requestContextMigration(const mace::string& contextID, const mace::MaceKey& destNode, const bool isRoot){
        $requestContextMigrationMethod
    }

    $processDeferred
    const char* ${servicename}Service::getMessageName(uint8_t messageType) const {
        switch(messageType) {
            $getMessageNameCases
            default: ASSERT(false); return "INVALID MESSAGE NUMBER";
        }
    }
    void ${servicename}Service::changeState(state_type stateNum, int selectorId) {
        _actual_state = stateNum;
        $traceStateChange
    }
    const char* ${servicename}Service::getStateName(state_type state) const {
        switch(static_cast<uint64_t>(state)) {
            $getStateNameCases
            default: ASSERT(false); return "INVALID STATE NUMBER";
        }
    }

    //API demux (provides -- registration methods, maceInit/maceExit/maceResume special handling)
END

    $this->printAPIDemux($outfile);
    $this->printAsyncDemux($outfile);
		$this->printSyncDemux($outfile);
    $this->printAspectDemux($outfile);
    $this->printHandlerRegistrations($outfile);

    print $outfile <<END;

    //Handler demux (uses handlers)
END

    $this->printHandlerDemux($outfile);

    print $outfile <<END;

    //Downcall helpers (uses)
END

    $this->printDowncallHelpers($outfile);

    print $outfile <<END;

    //Upcall helpers (provides handlers)
END

    $this->printUpcallHelpers($outfile);

    print $outfile <<END;

    //Async helpers
END

    my $name = $this->name();
    map {
        print $outfile $_->toString(methodprefix=>"${name}Service::", body => 1,selectorVar => 1);
    } $this->asyncHelperMethods(), $this->asyncDispatchMethods(),  $this->syncHelperMethods(), $this->routineHelperMethods(), $this->timerHelperMethods();

    print $outfile <<END;

    //Serial Helper Demux
END

    $this->printSerialHelperDemux($outfile);

    print $outfile <<END;

    //Model checking safety methods
    $modelCheckSafety

    //Model checking liveness methods
    $modelCheckLiveness

    } // end namespace

    //END Mace::Compiler::ServiceImpl::printCCFile
END
} # printCCFile

sub printConstantsFile {
    my $this = shift;
    my $outfile = shift;

    my $servicename = $this->name();

    my $r = Mace::Compiler::GeneratedOn::generatedOnHeader("$servicename constants header file");
    print $outfile $r;

    my $constantsIncludes = join("", $this->constants_includes());

    print $outfile <<END;
#ifndef ${servicename}_constants_h
#define ${servicename}_constants_h

#include "MaceBasics.h"
$constantsIncludes

    namespace ${servicename}_namespace {
END

    $this->printConstantsH($outfile);

    print $outfile <<END;

    } //end namespace ${servicename}_namespace

#endif // ${servicename}_constants_h
END
}

sub printConstantsH {
    my $this = shift;
    my $outfile = shift;

    my $servicename = $this->name();

    print $outfile <<END;
    //BEGIN: Mace::Compiler::ServiceImpl::printConstantsH
END

    foreach my $constant ($this->constants()) {
	my $conststr = $constant->toString();
	print $outfile <<END;
	    static const $conststr;
END
    }

    print $outfile <<END;
    //END: Mace::Compiler::ServiceImpl::printConstantsH
END
}

sub printSelectorConstantsH {
    my $this = shift;
    my $outfile = shift;

    my $servicename = $this->name();

    print $outfile <<END;
    //BEGIN: Mace::Compiler::ServiceImpl::printSelectorConstantsH
END

    while (my ($sv, $s) = each(%{$this->selectorVars()})) {
        #        const char selector_${sv}[] = $s;
        print $outfile <<END;
            const std::string selector_${sv} = $s;
END
    }

    print $outfile <<END;
    //END: Mace::Compiler::ServiceImpl::printSelectorConstantsH
END
}

sub printSelectorConstantsCC {
    my $this = shift;
    my $outfile = shift;

    my $servicename = $this->name();

    print $outfile <<END;
    //BEGIN: Mace::Compiler::ServiceImpl::printSelectorConstantsCC
END

    while (my ($sv, $s) = each(%{$this->selectorVars()})) {
	#        const char selector_${sv}[] = $s;
	print $outfile <<END;
	    //const std::string selector_${sv};
	    const LogIdSet* ${servicename}Service::selectorId_${sv};
END
    }

    print $outfile <<END;
    //END: Mace::Compiler::ServiceImpl::printSelectorConstantsCC
END
}

sub printIncludesH {
    my $this = shift;
    my $outfile = shift;

    my $servicename = $this->name();

    print $outfile <<END;
    //BEGIN: Mace::Compiler::ServiceImpl::printIncludesH
END

    my $undefCurtime = "";
    #  if ($this->macetime()) {
    #      $undefCurtime = '#undef curtime';
    #  }

    print $outfile <<END;
#include "lib/mace.h"
#include "lib/mace_constants.h"
#include "Enum.h"
//#include "lib/Util.h"
#include "lib/TimeUtil.h"
#include <map> //only include if can make upcalls
#include "lib/mace-macros.h"
    $undefCurtime
#include "lib/Log.h"
#include "lib/MethodMap.h" // only need this for sql logging of method calls
#include "lib/ScopedLog.h"
#include "lib/SimpleLogObject.h"
#include "lib/ScopedStackExecution.h"
#include "lib/BinaryLogObject.h"
#include "lib/Serializable.h"
#include "lib/ScopedFingerprint.h"
#include "${servicename}-constants.h"
#include "lib/ContextBaseClass.h"
#include "lib/ContextLock.h"
#include "lib/ContextMapping.h"
#include "HighLevelEvent.h"
#include "HierarchicalContextLock.h"

END

    if (scalar(@{$this->auto_types()}) || scalar(@{$this->messages()})) {
	if (scalar(@{$this->messages()})) {
	    print $outfile <<END;
#include "lib/Message.h"
END
	}
    }

    if ($this->macetime()) {
	print $outfile <<END;
#include "lib/MaceTime.h"
END
    }

    foreach my $scProvided ($this->provides()) {
	print $outfile <<END;
#include "${scProvided}ServiceClass.h"
END
    }
    foreach my $scUsed ($this->service_variables()) {
	print $outfile $scUsed->returnSCInclude();
    }
    if ($this->isDynamicRegistration() || grep($_->registration(), $this->service_variables())) {
        print $outfile qq{#include "DynamicRegistration.h"\n};
    }

    print $outfile <<END;
    //END: Mace::Compiler::ServiceImpl::printIncludesH
END
}

sub printUsingH {
    my $this = shift;
    my $outfile = shift;

    print $outfile <<END;
    //BEGIN: Mace::Compiler::ServiceImpl::printUsingH
           using mace::BinaryLogObject;
           using mace::Serializable;
           using mace::SerializationException;
           using mace::ContextMapping;
END

    if (scalar(@{$this->auto_types()}) || scalar(@{$this->messages()})) {
	if (scalar(@{$this->messages()})) {
	    print $outfile <<END;
		    using mace::Message;
END
	}
    }

    if ($this->macetime()) {
	print $outfile <<END;
	using mace::MaceTime;
END
    }

    print $outfile <<END;
    //END: Mace::Compiler::ServiceImpl::printUsingH
END

}

sub printIncludeBufH {
    my $this = shift;
    my $outfile = shift;

    print $outfile <<END;
    //BEGIN: Mace::Compiler::ServiceImpl::printIncludeBufH
END

    print $outfile $this->header()."\n";

    print $outfile <<END;
    //END: Mace::Compiler::ServiceImpl::printIncludeBufH
END

}

sub printAutoTypeForwardDeclares {
    my $this = shift;
    my $outfile = shift;

    print $outfile <<END;
    //BEGIN: Mace::Compiler::ServiceImpl::printAutoTypeForwardDeclares
END

    foreach my $at ($this->auto_types()) {
	print $outfile "  ".$at->toForwardDeclare();
    }

    print $outfile <<END;
    //END: Mace::Compiler::ServiceImpl::printAutoTypeForwardDeclares
END

}

sub printTypeDefs {
    my $this = shift;
    my $outfile = shift;

    print $outfile <<END;
    //BEGIN: Mace::Compiler::ServiceImpl::printTypeDefs
END

    foreach my $td ($this->typedefs()) {
	print $outfile "  ".$td->toString()."\n";
    }

    print $outfile <<END;
    //END: Mace::Compiler::ServiceImpl::printTypeDefs
END

}

sub printRoutineObjects {
    my $this = shift;
    my $outfile = shift;

    print $outfile <<END;
    //BEGIN: Mace::Compiler::ServiceImpl::printRoutineObjects
END

    map { print $outfile $_->toString.";\n"; } $this->routineObjects();

    print $outfile <<END;
    //END: Mace::Compiler::ServiceImpl::printRoutineObjects
END

}

sub printAutoTypes {
    my $this = shift;
    my $outfile = shift;

    print $outfile <<END;
    //BEGIN: Mace::Compiler::ServiceImpl::printAutoTypes
END

    foreach my $at ($this->auto_types()) {
	print $outfile "  ".$at->toAutoTypeString(tracelevel=>$this->traceLevel())."\n";
    }

    print $outfile <<END;
    //END: Mace::Compiler::ServiceImpl::printAutoTypes
END

}

sub defineAutoTypeMethods {
    my $this = shift;
    my $outfile = shift;

    print $outfile <<END;
    //BEGIN: Mace::Compiler::ServiceImpl::defineAutoTypeMethods
END

    foreach my $at ($this->auto_types()) {
	print $outfile "  ".$at->defineAutoTypeMethods(scopedlog=>$this->traceLevel(), logparams=>$this->traceLevel())."\n";
    }

    print $outfile <<END;
    //END: Mace::Compiler::ServiceImpl::defineAutoTypeMethods
END

}

sub printMessages {
    my $this = shift;
    my $outfile = shift;

    print $outfile <<END;
    //BEGIN: Mace::Compiler::ServiceImpl::printMessages
END

    my $messagenum = 0;
    for my $at ($this->messages()) {
        $at->setNumber(\$messagenum);
    }

    for my $at (sort { $a->messageNum() <=> $b->messageNum() } $this->messages()) {
	print $outfile "  ".$at->toMessageString("")."\n";
    }

    print $outfile <<END;
    //END: Mace::Compiler::ServiceImpl::printMessages
END

}

sub printTimerClasses {
    my $this = shift;
    my $outfile = shift;

    print $outfile <<END;
    //BEGIN: Mace::Compiler::ServiceImpl::printTimerClasses
END

    my $lockType = "AgentLock";
    if( @{ $this->contexts() } && $Mace::Compiler::Globals::useContextLock){
        $lockType = "ContextLock";
    }

    foreach my $timer ($this->timers()) {
	print $outfile $timer->toString($this->name()."Service",
					traceLevel => $this->traceLevel(),
                                        locktype => $lockType
                                        )."\n";
    }

    print $outfile <<END;
    //END: Mace::Compiler::ServiceImpl::printTimerClasses
END

}

sub printContextClass {
    my $this = shift;
    my $outfile = shift;
    my $contexts = shift;

    my @subcontexts;
    foreach my $context( @{$contexts} ) {
        push @subcontexts,$context->subcontexts();
    }
    if( @subcontexts != 0 ){ # chuangw: print child contexts first because compiler is stupid.
        $this->printContextClass($outfile, \@subcontexts);
    }
    foreach my $context( @{$contexts} ) {
        print $outfile $context->toString($this->name()."Service",traceLevel => $this->traceLevel()) . "\n";
    }
}

sub printContextClasses {
    my $this = shift;
    my $outfile = shift;
    my $contexts = shift;

    print $outfile <<EOF;
    //BEGIN: Mace::Compiler::ServiceImpl::printContextClasses
EOF
    $this->printContextClass($outfile, $contexts );

    print $outfile <<EOF;
    //EOF: Mace::Compiler::ServiceImpl::printContextClasses
EOF
}

sub printTimerDummyClasses {
    my $this = shift;
    my $outfile = shift;

    print $outfile <<END;
    //BEGIN: Mace::Compiler::ServiceImpl::printTimerClasses
END

    foreach my $timer ($this->timers()) {
        print $outfile $timer->toStringDummy($this->name()."Dummy",
                                        traceLevel => $this->traceLevel())."\n";
    }

    print $outfile <<END;
    //END: Mace::Compiler::ServiceImpl::printTimerClasses
END

}


sub isDynamicRegistration {
    my $this = shift;
    return !(($this->registration() eq "") or
	     ($this->registration() eq "static") or
	     ($this->registration() eq "unique"));
}

sub matchStateChange {
    my $this = shift;
    my $l = shift;
    $$l =~ s|\bstate\s*=\s*(\w+)\s*;|state_change($1);|g;
    return $l;
}				# matchStateChange

sub getVarFromMethod {
    my $method = shift;
    my $msig = $method->toString(noreturn=>1, novirtual=>1, noid=>1, nodefaults=>1, noline=>1);
    $msig =~ s/\W/_/g;
    return $msig;
}

sub printDummyClass {
    my $this = shift;
    my @state_variables_cloned;
    foreach my $var ($this->state_variables()) {
        if($var->flags('serialize') || $var->flags('dump')){
           my $clonedVar = ref_clone($var);
           my $type = $clonedVar->type();
           $type->isRef(0);
           push(@state_variables_cloned, $clonedVar);
        }
    }

    my $outfile = shift;
    my $name = $this->name();
    my $servicename = $this->name();
    my $getStateNameCases = join("\n", map{qq/case $_: return "${servicename}::$_";/} $this->states());
    my $timerMethods .= join("\n", map{$_->toString().";"} $this->timerMethods());
    my $timerDeclares = join("\n", map{my $t = $_->name(); qq/ class ${t}_MaceTimer;\n${t}_MaceTimer &$t; /;} $this->timers());
    my $statestring = 'enum _state_type { '.join(',', $this->states())."};\ntypedef Enum<_state_type> state_type;\n";
    my $stateVariables = join("\n", map{$_->toString(nodefaults => 1).";"} $this->state_variables(), $this->onChangeVars()); #nonTimer -> state_var
    my $stateVariablesCloned = join("\n", map{$_->toString(nodefaults => 1).";"} @state_variables_cloned, $this->onChangeVars()); #nonTimer -> state_var
    my $registrationDeclares = join("\n", map{my $n = $_->name(); "typedef std::map<int, $n* > maptype_$n;
                                                                 maptype_$n map_$n;"} $this->providedHandlers);

    my $derives = join(", ", map{"public virtual $_"} (map{"${_}ServiceClass"} $this->provides() ), ($this->usesHandlers()) );

    my $registration = "";
    my $allocateRegistration = "";
    my $downcallRegistration = "";
    if ($this->isDynamicRegistration()) {
      my $regType = $this->registration();
      $registration = ", public virtual DynamicRegistrationServiceClass<$regType>";
      $allocateRegistration = "registration_uid_t allocateRegistration($regType const & object, registration_uid_t rid);
                               void freeRegistration(registration_uid_t, registration_uid_t);
                               bool getRegistration($regType & object, registration_uid_t regId);
                               ";
      $registrationDeclares .= "\nstd::map<registration_uid_t, $regType> _regMap;
                                  ";
    }
    if ($this->count_downcall_registrations()) {
        $downcallRegistration .= qq/void downcall_freeRegistration(registration_uid_t freeRid, registration_uid_t rid = -1);
        /;
        for my $r ($this->downcall_registrations()) {
            $downcallRegistration .= qq/registration_uid_t downcall_allocateRegistration($r const & object, registration_uid_t rid = -1);
            bool downcall_getRegistration($r & object, registration_uid_t rid = -1);
            /;
        }
    }


    print $outfile <<END;
    //BEGIN: Mace::Compiler::ServiceImpl::printDummyClass
END

    print $outfile <<END;
	class ${name}Dummy:public BaseMaceService, public BinaryLogObject, $derives
{
  private:
    int __inited;

  protected:
    $statestring
    static mace::LogNode* rootLogNode;

  public:
        //Constructor
        ${name}Dummy();
        //Destructor
        virtual ~${name}Dummy();

    const char* getStateName(state_type state) const {
      switch(static_cast<uint64_t>(state)) {
        $getStateNameCases
         default: ASSERT(false); return "INVALID STATE NUMBER";
      }
    }

    const std::string& getLogType() const {
	static std::string type = "${name}";
        return type;
    }

    const std::string& getLogDescription() const {
        static const std::string desc = "SNAPSHOT::${name}";
        return desc;
    }

    LogClass getLogClass() const {
        return STATE_DUMP;
    }

    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }

  public:
    void print(std::ostream& __out) const;
    void printState(std::ostream& logger) const;
    void sqlize(mace::LogNode* node) const;
    void serialize(std::string& __str) const {};
    int deserialize(std::istream& is) throw(SerializationException);

    //State Variables
    $stateVariablesCloned

  protected:
    state_type _actual_state;
    const state_type& state;

    //Timer Vars
    $timerDeclares

    //Timer Methods
    $timerMethods
  };
END
}

sub shouldLogFuncsBody {
    my $this = shift;
    my $out = shift;
    for my $slog ($this->structuredLogs(),
		  grep(!($_->name =~ /^(un)?register.*Handler$/),
		       $this->providedMethods()),
		  @{$this->aspectMethods()}, @{$this->usesHandlerMethods()},
		  @{$this->timerMethods()},
		  @{$this->usesClassMethods()},
		  @{$this->providedHandlerMethods()},
		  $this->routines()) {
	print $out $slog->shouldLogFuncBody($this->name()."Service", $this->traceLevel());
    }
}

sub shouldLogFuncs {
    my $this = shift;
    my $ret = "";

    for my $slog ($this->structuredLogs(),
		  grep(!($_->name =~ /^(un)?register.*Handler$/),
		       $this->providedMethods()),
		  @{$this->aspectMethods()}, @{$this->usesHandlerMethods()},
		  @{$this->timerMethods()},
		  @{$this->usesClassMethods()},
		  @{$this->providedHandlerMethods()},
		  $this->routines()) {
	$ret .= $slog->shouldLogFunc();
    }
    return $ret;
}

sub printService {
    my $this = shift;
    my $outfile = shift;

    my $name = $this->name();
    my $statestring = 'enum _state_type { '.join(',', $this->states())."};\ntypedef Enum<_state_type> state_type;\n";
    my $transitionDeclarations = join("\n", map{$_->toTransitionDeclaration().";\n".$_->toGuardDeclaration().";"} $this->transitions());
    my $publicRoutineDeclarations = join("\n", map{$_->toString().";"} grep($_->isStatic, $this->routines()));
    my $routineDeclarations = join("\n", map{$_->toString().";"} grep(!$_->isStatic, $this->routines()));
    if ($this->traceLevel() > 1) {
      $routineDeclarations .= "\n".join("\n", grep(/./, map{if($_->returnType()->type() ne "void") { $_->toString(methodprefix=>"__mace_log_").";"}} $this->routines()));
    }
    my $defer_routineDeclarations = join("\n", map{"void ".$_->toString(noreturn=>1, methodprefix=>'defer_').";"} $this->routineDeferMethods());
    my $stateVariables = join("\n", map{$_->toString(nodefaults => 1, mutable => 1).";"} $this->state_variables(), $this->onChangeVars()); #nonTimer -> state_var
    my $providedMethodDeclares = join("\n", map{$_->toString('nodefaults' => 1).";"} $this->providedMethodsAPI());
    my $usedHandlerDeclares = join("\n", map{$_->toString('nodefaults' => 1).";"} $this->usesHandlerMethodsAPI());
    my $serviceVars = join("\n", map{$_->toServiceVarDeclares()} $this->service_variables());
    my $constructorParams = join("\n", map{$_->toString('nodefaults' => 1).';'} $this->constructor_parameters());
    my $timerDeclares = join("\n", map{my $t = $_->name(); qq/ class ${t}_MaceTimer;\n${t}_MaceTimer &$t; /;} $this->timers());
    # chuangw: a temporary hack
    my $contextDeclares = join("\n", map{ $_->toDeclareString(); } $this->contexts());
    my $timerMethods = join("\n", map{$_->toString().";"} $this->timerMethods());
    my $timerHelperMethods = join("\n", map{$_->toString().";"} $this->timerHelperMethods());
    my $asyncMethods = join("\n", map{$_->toString().";"} $this->asyncMethods());
    my $asyncHelperMethods = join("\n", map{$_->toString().";"} $this->asyncHelperMethods(), $this->asyncDispatchMethods());
    my $syncMethods = join("\n",  map{$_->toString().";"} $this->syncMethods());
    my $syncHelperMethods = join("\n",  map{$_->toString().";"} $this->syncHelperMethods());
    my $routineHelperMethods = join("\n",  map{$_->toString().";"} $this->routineHelperMethods());
    my $providesSerialDeclares = join("\n", map{$_->toString("noid" => 0).";"} $this->providedMethodsSerials());
    my $usesHandlersSerialDeclares = join("\n", map{$_->toString("noid" => 0).";"} $this->usesHandlerMethodsSerials());
    my $downcallHelperMethods = join("\n", map{$_->toString("methodprefix"=>'downcall_', "noid" => 0, "novirtual" => 1).";"} $this->usesClassMethods());
    my $defer_downcallHelperMethods = join("\n", map{"void ".$_->toString(noreturn=>1, methodprefix=>'defer_downcall_', noid => 0, novirtual => 1).";"} $this->downcallDeferMethods());
    my $upcallHelperMethods = join("\n", map{$_->toString('methodprefix'=>'upcall_', "noid" => 0, "novirtual" => 1).";"} $this->providedHandlerMethods());
    my $defer_upcallHelperMethods = join("\n", map{"void ".$_->toString(noreturn=>1,methodprefix=>'defer_upcall_', noid=> 0, novirtual => 1).";"} $this->upcallDeferMethods());
    my $derives = join(", ", map{"public virtual $_"} (map{"${_}ServiceClass"} $this->provides() ), ($this->usesHandlers()) );
    my $constructor = $name."Service(".join(", ", (map{$_->serviceclass."ServiceClass& __".$_->name} grep(not($_->intermediate()), $this->service_variables)), (map{$_->type->toString()." _".$_->name} $this->constructor_parameters()), "bool ___shared = true" ).");";
    $constructor .= "\n${name}Service(const ${name}Service& other);";
    my $accessorMethods = "const state_type& read_state() const;\n";
    $accessorMethods .= join("\n", map { my $n = $_->name();if( $n =~ m/^__internal_/ ){ qq// }else { my $t = $_->type()->toString(paramconst => 1, paramref => 1); qq/ $t read_$n() const; / } } $this->state_variables());

    my $registrationDeclares = join("\n", map{my $n = $_->name(); "typedef std::map<int, $n* > maptype_$n;
                                                                 maptype_$n map_$n;"} $this->providedHandlers);
    my $changeTrackerDeclare = ($this->count_onChangeVars())?"class __ChangeTracker__;":"";
    my $changeTrackerFriend = ($this->count_onChangeVars())?"friend class __ChangeTracker__;":"";
    my $mergeDeclare = join("\n", map { "class $_;" } $this->mergeClasses());
    my $mergeFriend = join("\n", map { "friend class $_;" } $this->mergeClasses());
    my $autoTypeFriend = join("\n", map { my $n = $_->name(); "friend class $n;"} $this->auto_types());
    my $mergeMethods = $this->declareMergeMethods();
    my $onChangeDeclares = join("\n", map{$_->toString('nodefaults' => 1).";"} $this->aspectMethods());
    my $sLogs = join("\n", map {my $n = $_->toString(); "$n;"} $this->structuredLogs());
    my $shouldLogFuncs = $this->shouldLogFuncs();
    my $modelCheckSafety = join("\n", map{"// ${\$_->toString()}
                                         ${\$_->toMethodDeclare()}"    } $this->safetyProperties);
    my $modelCheckLiveness = join("\n", map{"// ${\$_->toString()}
                                           ${\$_->toMethodDeclare()}"    } $this->livenessProperties);
    my $callSafetyProperties = join("", map{"if(!${\$_->toMethodCall()}) { maceerr << \"Safety property ${\$_->name}: failed\" << Log::endl; description = \"${name}::${\$_->name}\"; return false; } else\n"} $this->safetyProperties()) . "{ maceout << \"Safety Properties: check\" << Log::endl; return true; }";
    my $callLivenessProperties = join("", map{"if(!${\$_->toMethodCall()}) { maceout << \"Liveness property ${\$_->name}: failed\" << Log::endl; description = \"${name}::${\$_->name}\"; return false; } else\n"} $this->livenessProperties()) . "{ maceout << \"Liveness Properties: check\" << Log::endl; return true; }";
    my $registration = "";
    my $allocateRegistration = "";
    my $downcallRegistration = "";
    if ($this->isDynamicRegistration()) {
      my $regType = $this->registration();
      $registration = ", public virtual DynamicRegistrationServiceClass<$regType>";
      $allocateRegistration = "registration_uid_t allocateRegistration($regType const & object, registration_uid_t rid);
                               void freeRegistration(registration_uid_t, registration_uid_t);
                               bool getRegistration($regType & object, registration_uid_t regId);
                               ";
      $registrationDeclares .= "\nstd::map<registration_uid_t, $regType> _regMap;
                                  ";
    }
    if ($this->count_downcall_registrations()) {
        $downcallRegistration .= qq/void downcall_freeRegistration(registration_uid_t freeRid, registration_uid_t rid = -1);
        /;
        for my $r ($this->downcall_registrations()) {
            $downcallRegistration .= qq/registration_uid_t downcall_allocateRegistration($r const & object, registration_uid_t rid = -1);
            bool downcall_getRegistration($r & object, registration_uid_t rid = -1);
            /;
        }
    }

    my $deferVars = "";
    for my $m ($this->upcallDeferMethods(), $this->downcallDeferMethods(), $this->routineDeferMethods()) {
	my $n = getVarFromMethod($m);
	$deferVars .= "mace::deque<__DeferralArgsFor${n}, mace::SoftState> __deferralArgList_${n};\n";
    }

    my $selectorIdInits = "";
    while (my ($sv, $s) = each(%{$this->selectorVars()})) {
	$selectorIdInits .= qq/
	    static const LogIdSet* selectorId_${sv}; /;
    }

    print $outfile <<END;
    //BEGIN: Mace::Compiler::ServiceImpl::printService
END

    print $outfile <<END;
    $changeTrackerDeclare
    class ServiceTester;
    class ${name}Service : public BaseMaceService, public virtual mace::PrintPrintable, public virtual Serializable, public virtual BinaryLogObject, $derives $registration
{
  private:
    $changeTrackerFriend
    friend class ServiceTester;
    $mergeFriend
    $autoTypeFriend
    int __inited;
  protected:
    $statestring
    static mace::LogNode* rootLogNode;
    mutable VersionServiceMap versionMap;

END

    $this->printComputeAddress($outfile);

    print $outfile <<END;
  public:
    //Constructor
    $constructor
    //Destructor
    virtual ~${name}Service();

    //Methods for snapshotting
    void snapshot(const uint64_t& ver) const;
    void snapshotRelease(const uint64_t& ver) const;

    void updateInternalContext(const mace::MaceKey& oldNode, const mace::MaceKey& newNode);
    void requestContextMigration(const mace::string& contextID, const mace::MaceKey& destNode, const bool isRoot);
  private:

    $accessorMethods

  public:
    //Misc.

    const std::string& getLogType() const {
        static std::string type = "${name}";
        return type;
    }

    const std::string& getLogDescription() const {
        static const std::string desc = "SNAPSHOT::${name}";
        return desc;
    }

    LogClass getLogClass() const {
        return STATE_DUMP;
    }

    mace::LogNode*& getChildRoot() const {
      return rootLogNode;
    }

    $selectorIdInits

  protected:
    void dumpState(LOGLOGTYPE& logger) const;
    void processDeferred();
    const char* getStateName(state_type state) const;
    const char* getMessageName(uint8_t msgNum) const;
    void changeState(state_type stateNum, int selectorId);
    $shouldLogFuncs
    $sLogs
  public:
    void printNode(mace::PrintNode& __printer, const std::string& name) const;
    void print(std::ostream& logger) const;
    void printState(std::ostream& logger) const;
    void sqlize(mace::LogNode* node) const;

    void serialize(std::string& str) const;
    int deserialize(std::istream& is) throw(SerializationException);

    //Provided Methods (calls into this service from a higher layer)
    $providedMethodDeclares

    //Used Handlers (calls into this service from a lower layer)
    $usedHandlerDeclares

    //Registration Methods (for dynamic registration)
    $allocateRegistration

  protected:
    state_type _actual_state;
    const state_type& state;
    //XXX: Do we still need fsm_hint?
    //XXX: Generate utility_timer_ as needed.

    //Constructor Parameter (Variables)
    $constructorParams

    //ServiceVariables and Registration UIDs
    $serviceVars

    //Aspect Methods
    $onChangeDeclares

    //Registration Typedefs and Maps
    $registrationDeclares

    //State Variables
    $stateVariables

    //Timer Vars
    $timerDeclares

    //Context Declaration
    $contextDeclares

    //Timer Methods
    $timerMethods

    //Timer Helper Methods
    $timerHelperMethods

    //Async Helper Methods
    $asyncMethods

    //Async Helper Methods
    $asyncHelperMethods

    //Sync Methods
    $syncMethods

    //Sync Helper Methods
    $syncHelperMethods

    //Routine Helper Methods
    $routineHelperMethods

    //Merge Class Declarations
    $mergeDeclare

    //Downcall and Upcall helper methods
    $downcallRegistration
    $downcallHelperMethods
    $upcallHelperMethods

    //Serialized form Method Helpers
    $providesSerialDeclares
    $usesHandlersSerialDeclares

    //Transition and Guard Method Declarations
    $transitionDeclarations

    //Routines
    $routineDeclarations

    //Deferal Variables
    $deferVars

    //Local Address
    MaceKey __local_address;
    MaceKey downcall_localAddress() const;
    const MaceKey& downcall_localAddress(const registration_uid_t& rid) const;

    //Defer methods
    $defer_downcallHelperMethods
    $defer_upcallHelperMethods
    $defer_routineDeclarations

    //Pre and Post Transition Demux Method Declarations
    $mergeMethods

  public:
    $publicRoutineDeclarations

    static bool checkSafetyProperties(mace::string& description, const _NodeMap_& _nodes_, const _KeyMap_& _keys_) {
        ADD_SELECTORS("${name}::checkSafetyProperties");
        maceout << "Testing safety properties" << Log::endl;
        $callSafetyProperties
    }

    static bool checkLivenessProperties(mace::string& description, const _NodeMap_& _nodes_, const _KeyMap_& _keys_) {
        ADD_SELECTORS("${name}::checkLivenessProperties");
        maceout << "Testing liveness properties" << Log::endl;
        $callLivenessProperties
    }

  protected:
    static _NodeMap_::const_iterator castNode(const mace::MaceKey& key, const _NodeMap_& _nodes_, const _KeyMap_& _keys_) {
        ADD_SELECTORS("${name}::castNode::MaceKey");
        if (key.isNullAddress()) { return _nodes_.end(); }
        if (key.addressFamily() != IPV4) {
            macedbg(0) << "Casting " << key << Log::endl;
            if (_keys_.empty()) { return _nodes_.end(); macedbg(0) << "keys empty, end" << Log::endl; }
            if (key.addressFamily() != _keys_.begin()->first.addressFamily()) { return _nodes_.end(); macedbg(0) << "address family mismatch, end" << Log::endl; }
            _KeyMap_::const_iterator i = _keys_.find(key);
            if (i == _keys_.end()) { return _nodes_.end(); macedbg(0) << "key not found, end" << Log::endl; }
            macedbg(0) << "Returning node " << i->second << Log::endl;
            return _nodes_.find(i->second);
        }
        return _nodes_.find(key.getMaceAddr().local.addr-1);
    }

    static _NodeMap_::const_iterator castNode(const NodeSet::const_iterator& iter, const _NodeMap_& _nodes_, const _KeyMap_& _keys_) {
        if((*iter).isNullAddress()) { return _nodes_.end(); }
        return castNode(*iter, _nodes_, _keys_);
    }

    static _NodeMap_::const_iterator castNode(const mace::map<int, _NodeMap_::const_iterator, mace::SoftState>::const_iterator& iter, const _NodeMap_& _nodes_, const _KeyMap_& _keys_) {
        return iter->second;
    }

    static _NodeMap_::const_iterator castNode(const _NodeMap_::const_iterator& iter, const _NodeMap_& _nodes_, const _KeyMap_& _keys_) {
        return iter;
    }

    //Model Checking Safety Properties
    $modelCheckSafety

    //Model Checking Liveness Properties
    $modelCheckLiveness
    };
END

    print $outfile <<END;
//END: Mace::Compiler::ServiceImpl::printService
END

} # printService

sub varIsClosure {
    my $this = shift;
    my $var = shift;

    return ($var =~ /[^.()*]+\*/);
} # varIsClosure

sub splitVar {
    my $this = shift;
    my $var = shift;
    # NOTE: this will not match function pointers!
    $var =~ /([^.()*]+)(\*|(\([^.()]*\)(\s+const)?))?(\.([^.]*))?/;
    my $firstVar = $1;
    if (defined($3)) {
	$firstVar .= $3;
    }
    return ($firstVar, $6)
} # splitVar

sub compareName {
    my $this = shift;
    my $matchVar = shift;
    my $targetVar = shift;
    my $match = shift;

#    print("$targetVar $matchVar\n");
    if ($match) {
	return ($targetVar =~ /^$matchVar/i);
    }
    else {
	return lc($targetVar) eq lc($matchVar);
#	return ($targetVar =~ /^$matchVar$/i);
    }

} # compareName

sub computeLogObjects {
    my $this = shift;
    my $path = Mace::Util::findPath("mql", @Mace::Compiler::Globals::INCLUDE_PATH);
    if ($path eq "") {
	Mace::Compiler::Globals::error('bad path', $this->queryFile(), $this->queryLine, "Can't find mql in search path.  Make sure to add \"INCLUDE_DIRECTORY(<PATH_TO_MQL>)\" to \$MACE_HOME/services/CMakeLists-service.txt");
	return;
    }
    my $arg = $this->queryArg();
    $arg =~ s/\"/\\\"/g;
    my $output = `$path/mql -m \"$arg\"`;
    my $val = $? >> 8;
    if ($val != 0) {
	Mace::Compiler::Globals::error('mql error', $this->queryFile(),
				       $this->queryLine, "$output");
    }
    else {
	my @logObjs = split(/\n/, $output);
	my $pushWheres = 0;

	for my $var (@logObjs) {
	    if ($var eq "---") {
		$pushWheres = 1;
	    }
	    elsif (!$pushWheres) {
		$this->push_logObjects($var);
	    }
	    else {
		# split the line around the "-"
		# format is objectName - clause
		$var =~ /([^-]*) - (.*)/;
		my $existingWhere = $this->wheres->{$1};
		if (defined($existingWhere)) {
		    $this->wheres($1, "(".$existingWhere." || ".$2.")");
		}
		else {
		    $this->wheres($1, $2);
		}
	    }
	}
    }
}

sub validateLogObjects {
    my $this = shift;
    my @handlerMatches = grep(!($_->name =~ /^(un)?register.*Handler$/),
			      $this->providedMethods());
    # valid children for all log objects
    my %autoVars = (node => '1', time => '1', type => '1', tid => '1');

    if (!@{$this->logObjects()}) {
	# if there are no objects from queries, log everything
	for my $slog (@handlerMatches, @{$this->aspectMethods()},
		      @{$this->usesHandlerMethods()}, @{$this->timerMethods()},
		      @{$this->usesClassMethods()},
		      @{$this->providedHandlerMethods()}, @{$this->routines()}) {
	    # log all method calls
	    $slog->shouldLog(1);
	}
	# log the service
	$this->logService(1);

	for my $var ($this->state_variables()) {
	    # log all state variables
	    $var->shouldLog(1);
	}

	for my $slog ($this->structuredLogs()) {
	    # log all structured logs
	    $slog->shouldLog(1);
	}
	for my $at ($this->auto_types()) {
            my %registeredMethods;

	    # log all auto type methods
	    for my $m ($at->methods()) {
		$m->shouldLog(1);
		$m->doStructuredLog($m->getLogLevel($this->traceLevel()) > 0);
		my $logName = $m->squashedName();
                my $binlogname = $at->name() . "_" . $logName;
                if (defined($registeredMethods{$binlogname})) {
                    my $bn = $binlogname;
                    $binlogname = $binlogname . $registeredMethods{$binlogname};
                    $registeredMethods{$bn}++;
                }
                else {
                    $registeredMethods{$binlogname} = 2;
                }
		$m->options('binlogname', $binlogname);
		my $longName = $m->toString(nodefaults => 1, novirtual => 1, noreturn => 1, noline => 1);
		$longName =~ s/\n/ /g;
		$m->options('binloglongname', $longName);
	    }
	}
	for my $t ($this->timers()) {
	    # log all timer events
	    $t->shouldLog(1);
	}
	return;
    }
    for my $var ($this->logObjects()) {
	my $globalFind = 0;
	my @subVars = $this->splitVar($var);
#	print "first: $subVars[0] second $subVars[1]\n";
	my $closure = $this->varIsClosure($var);
	my $object = $subVars[0];
	my $varName = $subVars[1];

	if ($object eq "graph" && $varName eq "stack") {
	    # need to log all method calls
	    for my $slog (@handlerMatches, @{$this->aspectMethods()},
			  @{$this->usesHandlerMethods()}, @{$this->timerMethods()},
			  @{$this->usesClassMethods()},
			  @{$this->providedHandlerMethods()}, @{$this->routines()}) {
		my $longName = $slog->options('binloglongname');
		$slog->setLogOpts(1, $this->wheres->{$longName});
	    }
	    next;
	}
	if ($this->compareName($object, $this->name(), $closure)) {
	    # Matched service, check state variables
	    my $found = 0;
	    if (!defined($varName)) {
		# no child specified, add all state variables
		$found = 1;
		$globalFind = 1;
		$this->logService(1);
		for my $subVar ($this->state_variables()) {
		    $subVar->shouldLog(1);
		}
	    }
	    else {
		if ($autoVars{$varName}) {
		    $found = 1;
		    $globalFind = 1;
		    $this->logService(1);
		}
		else {
		    for my $subVar ($this->state_variables()) {
			if ($subVar->name() =~ /^$varName$/i) {
			    $found = 1;
			    $globalFind = 1;
			    $this->logService(1);
			    $subVar->shouldLog(1);
			    last;
			}
		    }
		}
	    }
	    if (!$found) {
		# signal error
		Mace::Compiler::Globals::error('invalid query',
					       $this->queryFile(),
					       $this->queryLine(),
					       "No state variable $varName in service $object");
	    }
	    else {
		if (!$closure) {
		    # we found a match, can't match anything else so go to next
		    # var
		    next;
		}
	    }
	}
	my $outerFound = 0;
	# Search structured log methods
	for my $slog ($this->structuredLogs()) {
	    if ($this->compareName($object, $slog->name(), $closure)) {
		# Matched a structured log
		$outerFound = 1;

		if (!defined($varName)) {
		    # no child specified, add all params
		    $globalFind = 1;
		    # this is set in validate
		    $slog->setLogOpts(1, $this->wheres->{$slog->name()});
		    for my $param ($slog->params()) {
			$param->shouldLog(1);
		    }
		    if (!$closure) {
			# we found a match, can't match anything else so go to
			# next var
			last;
		    }
		}
		else {
		    my $param = $slog->getParam($varName);
		    my $slogName = $slog->name();

		    if ($autoVars{$varName} || defined($param)) {
			$globalFind = 1;
			# this is set in validate
			$slog->setLogOpts(1, $this->wheres->{$slog->name()});
			if (defined($param)) {
			    $param->shouldLog(1);
			}
			if (!$closure) {
			    # we found a match, can't match anything else so go to
			    # next var
			    last;
			}
		    }
		    else {
			# signal error
			Mace::Compiler::Globals::error('invalid query', $this->queryFile(), $this->queryLine(), "No parameter named $varName in structured log $slogName");
			  next;
		    }
		}
	    }
	}
	if ($outerFound && !$closure) {
	    # go to next var
	    next;
	}
	$outerFound = 0;
	# Search function prototype methods
	for my $slog (@handlerMatches, @{$this->aspectMethods()},
		      @{$this->usesHandlerMethods()}, @{$this->timerMethods()},
		      @{$this->usesClassMethods()},
		      @{$this->providedHandlerMethods()}, @{$this->routines()}) {
	    my $longName = $slog->options('binloglongname');
	    if ($slog->doStructuredLog() &&
		$this->compareName($object, $longName, $closure)) {
		# Matched a function prototype
		$outerFound = 1;

		if (!defined($varName)) {
		    # no child specified, add all params
		    $globalFind = 1;
		    $slog->setLogOpts(1, $this->wheres->{$longName});
		    for my $param ($slog->params()) {
			$param->shouldLog(1);
		    }
		    if (!$closure) {
			# we found a match, can't match anything else so go to
			# next var
			last;
		    }
		}
		else {
		    my $param = $slog->getParam($varName);

		    if ($autoVars{$varName} || defined($param)) {
			$globalFind = 1;
			$slog->setLogOpts(1, $this->wheres->{$longName});
			if (defined($param)) {
			    $param->shouldLog(1);
			}
			if (!$closure) {
			    # we found a match, can't match anything else so go to
			    # next var
			    last;
			}
		    }
		    else {
			# signal error
			Mace::Compiler::Globals::error('invalid query', $this->queryFile(), $this->queryLine(), "No parameter named $varName in method $longName");
		    }
		}
	    }
	}
	if (!$globalFind) {
	    # nothing left to match, must be an error
	    Mace::Compiler::Globals::error('invalid query',
					   $this->queryFile(),
					   $this->queryLine(),
					   "No match for $var");
	    next;
	}
    }
} # validateLogObjects

sub addContextMigrationMessages {
    my $this = shift;
    my $msg = shift;
    # generate message types used for handling context migration
    for( @{$msg} ){
        my $msgtype = Mace::Compiler::AutoType->new(name=> $_->{name}, line=>__LINE__, filename => __FILE__,
        method_type=>Mace::Compiler::AutoType::FLAG_CONTEXT, special_call=>"special"
        );
        for( @{ $_->{param} } ){
            my $t = Mace::Compiler::Type->new(type => $_->{type} );
            my $p = Mace::Compiler::Param->new(name=> $_->{name}, filename=>__FILE__, line=>__LINE__, type=>$t);
            $p->type->isConst(0);
            $p->type->isConst1(0);
            $p->type->isConst2(0);
            $p->type->isRef(0);
            $msgtype->push_fields($p);
        }
        $this->push_messages( $msgtype );
    }

}

sub locateChildContextObj {
    my $this = shift;

    my $context = shift;
    my $contextDepth = shift;
    my $parentContext = shift;

    my $declareContextObj;
    my $getContextObj;

    my $declareParams = "";
    my $contextName = $_->{name};
    if( $_->isMulti() ) {
        if( scalar( @{ $_->paramType->key()} )  == 1  ){
            my $keyType = ${ $_->paramType->key() }[0]->type->type();
            $getContextObj = qq#
            $keyType keyVal = boost::lexical_cast<$keyType>( ctxStr${contextDepth}[1] );
            contextDebugID = contextDebugIDPrefix+ "$contextName\[" + boost::lexical_cast<mace::string>(keyVal)  + "\]";
            if( $parentContext -> $contextName.find( keyVal ) == $parentContext ->$contextName.end() ){
                ScopedLock sl( mace::ContextBaseClass::newContextMutex );
                if( $parentContext -> $contextName.find( keyVal ) == $parentContext ->$contextName.end() ){
                    $parentContext -> $contextName [ keyVal ] = $_->{className} ( contextDebugID, ticket );
                }
                sl.unlock();
            }
            contextDebugIDPrefix = contextDebugID;
            
            #;
            $declareContextObj = "&($parentContext -> $contextName [ keyVal ] )";

        } elsif (scalar( $_->paramType->key() ) > 1 ){
            my $paramid=1;
            my @params;
            my @paramid;
            for( @{ $_->paramType->key() } ){
                my $keyType = $_->type->type();
                push @params, "$keyType param$paramid = boost::lexical_cast<$keyType>( ctxStr${contextDepth}[$paramid] )";
                push @paramid, "param$paramid";
                $paramid++;
            }
            my $ctxParamClassName = $_->paramType->className();
            # declare parameters of the _ index
            $declareParams = join(";\n", @params) . ";";
            $getContextObj = qq"
            $ctxParamClassName keyVal(" .join(",", @paramid) . ");
            " . qq#
            contextDebugID = contextDebugIDPrefix+ "$contextName\[" + boost::lexical_cast<mace::string>(keyVal)  + "\]";
            if( $parentContext -> $contextName.find( keyVal ) == $parentContext -> $contextName.end() ){
                ScopedLock sl( mace::ContextBaseClass::newContextMutex );
                if( $parentContext -> $contextName.find( keyVal ) == $parentContext -> $contextName.end() ){
                    $parentContext -> $contextName [ keyVal ] = $_->{className} ( contextDebugID, ticket );
                }
                sl.unlock();
            }
            contextDebugIDPrefix = contextDebugID;
            
            #;
            $declareContextObj = "&($parentContext -> $contextName [ keyVal ] )";
        }
    }else{
        $getContextObj = qq#
            contextDebugID = contextDebugIDPrefix + "${contextName}::";
            if( $parentContext -> $contextName == NULL ){
                ScopedLock sl( mace::ContextBaseClass::newContextMutex );
                if( $parentContext -> $contextName == NULL ){
                    $parentContext -> $contextName = new $_->{className} ( contextDebugID, ticket );
                }
                sl.unlock();
            }
            contextDebugIDPrefix = contextDebugID;
        #;
        $declareContextObj = "$parentContext -> $contextName";
    }
    my @condstr;
    my $nextContextDepth = $contextDepth+1;
    for( @{ $_->subcontexts()} ){
        push @condstr, $this->locateChildContextObj( $_ , $nextContextDepth, "parentContext$contextDepth"  );
    }
    my $subcontextConditionals = join("else ", @condstr);
    # FIXME: need to deal with the condition when a _ is allowed to downgrade to non-subcontexts.
    my $tokenizeSubcontext = "";
    if( scalar( @{ $_->subcontexts()} ) ){
        $tokenizeSubcontext= qq/
        std::vector<std::string> ctxStr$nextContextDepth;
        boost::split(ctxStr$nextContextDepth, ctxStrs[$nextContextDepth], boost::is_any_of("[,]") ); /;
    }
    my $s = qq/if( ctxStr${contextDepth}[0] == "$context->{name}" ){
        $declareParams
        $getContextObj

        $context->{className}* parentContext$contextDepth = $declareContextObj;
        ctxobj = dynamic_cast<mace::ContextBaseClass*>(parentContext$contextDepth);
        if( ctxStrsLen == $nextContextDepth )
            return ctxobj;
        $tokenizeSubcontext
        $subcontextConditionals
    }
    /;
    return $s;
}
sub locateSubcontexts {
    my $this = shift;

    my $context = shift;
    my $contextDepth = shift;
    my $parentContext = shift;

    my $declareContextObj;

    my $declareParams = "";
    if( $_->isMulti() ) {
        if( scalar( @{ $_->paramType->key()} )  == 1  ){
            my $keyType = ${ $_->paramType->key() }[0]->type->type();
            $declareContextObj = "$_->{name} [ boost::lexical_cast<$keyType>( ctxStr${contextDepth}[1] ) ]";

        } elsif (scalar( $_->paramType->key() ) > 1 ){
            my $paramid=1;
            my @params;
            my @paramid;
            for( @{ $_->paramType->key() } ){
                my $keyType = $_->type->type();
                push @params, "$keyType param$paramid = boost::lexical_cast<$keyType>( ctxStr${contextDepth}[$paramid] )";
                push @paramid, "param$paramid";
                $paramid++;
            }
            my $ctxParamClassName = $_->paramType->className();
            # declare parameters of the context index
            $declareParams = join(";\n", @params) . ";";
            $declareContextObj .= "$_->{name} [ $ctxParamClassName (" .join(",", @paramid) . ") ]";
        }
        $declareContextObj = "&($parentContext -> $declareContextObj )";
    }else{
        $declareContextObj = "$parentContext -> $_->{name} ";
    }
    my @condstr;
    my $nextContextDepth = $contextDepth+1;
    for( @{ $context->subcontexts()} ){
        push @condstr, $this->locateSubcontexts( $_, $nextContextDepth, "parentContext$contextDepth"  );
    }
    my $subcontextConditionals = join("else ", @condstr);
    # FIXME: need to deal with the condition when a context is allowed to downgrade to non-subcontexts.
    my $tokenizeSubcontext = "";
    if( scalar( @{ $context->subcontexts()} ) ){
        $tokenizeSubcontext= qq/
        std::vector<std::string> ctxStr$nextContextDepth;
        boost::split(ctxStr$nextContextDepth, ctxStrs[$contextDepth], boost::is_any_of("[,]") ); /;
    }
    my $s = qq/if( ctxStr${contextDepth}[0] == "$_->{name}" ){
        $declareParams
        $_->{className}* parentContext$contextDepth = $declareContextObj;
        sobj = dynamic_cast<mace::Serializable*>(parentContext$contextDepth);
        $tokenizeSubcontext
        $subcontextConditionals
    }
    /;
    return $s;
}

sub addContextMigrationTransitions {
    my $this = shift;
    my $handlers = shift;
    # generate message handler for handling context migration


    my $ptype1 = Mace::Compiler::Type->new(isConst=>1, isConst1=>1, isConst2=>0, type=>'MaceKey', isRef=>1);
    my $param1 = Mace::Compiler::Param->new(filename=>__FILE__,hasDefault=>0,name=>'src',type=>$ptype1,line=>__LINE__);
    my $param2 = Mace::Compiler::Param->new(filename=>__FILE__,hasDefault=>0,name=>'dest',type=>$ptype1,line=>__LINE__);

    for( @{ $handlers } ){
        my $ptype2 = Mace::Compiler::Type->new(isConst=>1, isConst1=>1, isConst2=>0, type=>$_->{param}, isRef=>1);

        my $param3 = Mace::Compiler::Param->new(filename=>__FILE__,hasDefault=>0,name=>'msg',type=>$ptype2,line=>__LINE__);
        my $g = Mace::Compiler::Guard->new( 
            file => __FILE__,
            guardStr => 'true',
            type => 'state_var',
            state_expr => Mace::Compiler::ParseTreeObject::StateExpression->new(type=>'null'),
            line => __LINE__

        );
        my $rtype = Mace::Compiler::Type->new();
        my $m = Mace::Compiler::Method->new(
            body => $_->{body}, #$item{MethodTerm}->toString()
            throw => undef,
            filename => __FILE__,
            isConst => 0, #scalar(@{$item[-4]}),
            isUsedVariablesParsed => 0,
            isStatic => 0, #scalar(@{$item[1]}),
            name => "deliver",
            returnType => $rtype,#$item{MethodReturnType},
            line => __LINE__, #$item{FileLineEnd}->[0],
            targetContextObject => "__internal" , # should be "__internal" context
            );
        $m->push_params( $param1 );
        $m->push_params( $param2 );
        $m->push_params( $param3 );

        # chuangw: assuming the lower level service is Trasnport
        my $t = Mace::Compiler::Transition->new(name => "deliver", #$item{Method}->name(), 
            startFilePos => -1, #($thisparser->{local}{update} ? -1 : $item{StartPos}),
            columnStart => -1,  #$item{StartCol}, 
            type => "upcall", 
            method => $m,
            startFilePos => -1,
            columnStart => '-1',
            transitionNum => 0 # what is this number used for??
        );
        $t->push_guards( $g );
        $this->push_transitions( $t);
    }


}
sub addContextMigrationHelper {
    my $this = shift;
=begin
/*
// chuangw: TODO: I don't need these internal structures....
    // wait for earlier events to finish // msg.eventId

    // we're accessing the internal structure as well as context structure
    ScopedLock sl(mace::ContextBaseClass::__internal_ContextMutex );

    mace::string ctxSnapshot;
    Serializable* sobj = findContextByID(msg.ctxId);
    mace::serialize( ctxSnapshot, sobj );

    // release the internal structure which are not used after migration.
    // __internal_msgseqno, __internal_lastAckedSeqno, __internal_receivedSeqno, __internal_unAck
    mace::map<mace::string, uint32_t>::iterator imsgseqno_it;
    mace::map<mace::string, uint32_t>::iterator ilastAckedSeqno_it;
    mace::map<mace::string, mace::map<uint32_t, uint8_t> >::iterator ireceivedSeqno_it;
    mace::map<mace::string, mace::map<uint32_t, mace::string> >::iterator iunAck_it;

    //MaceKey dummyNode = MaceKey::null;
    mace::string dummyContext = "";
    if( (imsgseqno_it= __internal_msgseqno.find( dummyContext ) ) != __internal_msgseqno.end() ){
        mace::serialize( ctxSnapshot, &(imsgseqno_it->second) );
        __internal_msgseqno.erase( imsgseqno_it );
    }else{
        maceerr<<"Unexpected! "<<Log::endl;
    }
    if( (ilastAckedSeqno_it= __internal_lastAckedSeqno.find( dummyContext ) ) != __internal_lastAckedSeqno.end() ){
        mace::serialize( ctxSnapshot, &(ilastAckedSeqno_it->second) );
        __internal_lastAckedSeqno.erase( ilastAckedSeqno_it );
    }else{
        maceerr<<"Unexpected! "<<Log::endl;
    }
    if( (ireceivedSeqno_it= __internal_receivedSeqno.find( dummyContext ) ) != __internal_receivedSeqno.end() ){
        mace::serialize( ctxSnapshot, &(ireceivedSeqno_it->second) );
        __internal_receivedSeqno.erase( ireceivedSeqno_it );
    }else{
        maceerr<<"Unexpected! "<<Log::endl;
    }
    if( (iunAck_it= __internal_unAck.find( dummyContext ) ) != __internal_unAck.end() ){
        mace::serialize( ctxSnapshot, &(iunAck_it->second) );
        __internal_unAck.erase( iunAck_it );
    }else{
        maceerr<<"Unexpected! "<<Log::endl;
    }


    downcall_route( msg.dest, TransferContext( msg.ctxId, ctxSnapshot, msg.eventId ) );
*/
=cut
=begin
    /*mace::map<mace::string, uint32_t>::iterator imsgseqno_it;
    mace::map<mace::string, uint32_t>::iterator ilastAckedSeqno_it;
    mace::map<mace::string, mace::map<uint32_t, uint8_t> >::iterator ireceivedSeqno_it;
    mace::map<mace::string, mace::map<uint32_t, mace::string> >::iterator iunAck_it;

    mace::string dummyContext = "";
    if( (imsgseqno_it= __internal_msgseqno.find( dummyContext ) ) == __internal_msgseqno.end() ){
        mace::deserialize( ctxSnapshot, &(__internal_msgseqno[ dummyContext] ) );
        __internal_msgseqno.erase( imsgseqno_it );
    }else{
        maceerr<<"Unexpected! "<<Log::endl;
    }
    if( (ilastAckedSeqno_it= __internal_lastAckedSeqno.find( dummyContext ) ) == __internal_lastAckedSeqno.end() ){
        mace::deserialize( ctxSnapshot, &(__internal_lastAckedSeqno[ dummyContext] ) );
        __internal_lastAckedSeqno.erase( ilastAckedSeqno_it );
    }else{
        maceerr<<"Unexpected! "<<Log::endl;
    }
    if( (ireceivedSeqno_it= __internal_receivedSeqno.find(dummyContext ) ) == __internal_receivedSeqno.end() ){
        mace::deserialize( ctxSnapshot, &(__internal_receivedSeqno[ dummyContext] ) );
        __internal_receivedSeqno.erase( ireceivedSeqno_it );
    }else{
        maceerr<<"Unexpected! "<<Log::endl;
    }
    if( (iunAck_it= __internal_unAck.find(dummyContext ) ) == __internal_unAck.end() ){
        mace::deserialize( ctxSnapshot, &(__internal_unAck[ dummyContext] ) );
        __internal_unAck.erase( iunAck_it );
    }else{
        maceerr<<"Unexpected! "<<Log::endl;
    }

    downcall_route( ContextMapping::getHead(), ReportContextMigration(msg.ctxId, msg.eventId) ); */

=cut
    my @handlerContextMigrate = (
        {
            param => "ContextMigrationRequest",
            body => qq#{
    // Assuming one migration event takes place at a time.
    mace::AgentLock::nullTicket();
    ScopedLock sl( mace::ContextBaseClass::__internal_ContextMutex ); // protect internal structure
    mace::ContextBaseClass *thisContext = getContextObjByID( msg.nextHop, msg.eventId );
    ThreadStructure::setTicket( msg.eventId );
    if( msg.nextHop == msg.ctxId ){
        if( msg.isRoot ){
            ABORT("Not implemented");
        }else{

        }
        mace::string contextData;
        copyContextData( msg.ctxId, msg.eventId, contextData );
        downcall_route(msg.dest , TransferContext(msg.ctxId,contextData, msg.eventId, src) );

        // erase the context from this node.
        eraseContextData( msg.ctxId );
        // TODO: update my local context mapping
        /*mace::list<mace::string> tmpCtxList;
        tmpCtxList.push_back( msg.ctxId );
        ContextMapping::updateMapping( localAddress(), tmpCtxList );*/
        ContextMapping::updateMapping( localAddress(), msg.ctxId );
    }else{
        if( thisContext->isLocalCommittable()  ){ // ignore DAG case.
            thisContext->addNewChild( msg.ctxId, msg.eventId );
            sl.unlock();

            mace::ContextLock( *thisContext, mace::ContextLock::NONE_MODE );
            sl.lock();
            const mace::set< mace::string >* subcontexts = thisContext->getChildContextID();
            for( mace::set<mace::string>::const_iterator subctxIter= subcontexts->begin(); subctxIter != subcontexts->end(); subctxIter++ ){
                if( subctxIter->compare( msg.ctxId ) == 0 ) continue; // deal with the target context differently.
                // TODO: if child contexts are located on the same node, queue the message on the async event queue...
                const mace::string& nextHop  = *subctxIter; // prepare messages sent to the child contexts
                ContextMigrationRequest nextmsg(msg.ctxId, msg.dest, msg.isRoot, msg.eventId,  nextHop );
                mace::MaceKey nextHopNode = mace::ContextMapping::getNodeByContext( nextHop );
                downcall_route( nextHopNode, nextmsg);
                /*mace::string buf;
                mace::serialize(buf, &nextmsg);
                __internal_unAck[ nextHop ][ msgseqno ] = buf;*/
            }
        }
        // if the this context is the immediate parent of the target context...
        if( thisContext->isImmediateParentOf( msg.ctxId ) ){
            mace::ContextBaseClass::migrationTicket = msg.eventId; // set up a flag...
            mace::ContextBaseClass::migrationContext = msg.ctxId;
            downcall_route(msg.dest , ContextMigrationRequest(msg.ctxId,msg.dest, msg.isRoot,msg.eventId, msg.ctxId ) );
            
        }

    }

            }#
        },
        {
            param => "ContextMigrationResponse",
            body => qq#{
    mace::AgentLock::nullTicket();
    pthread_mutex_lock( &mace::ContextBaseClass::__internal_ContextMutex );
    // TODO: update the entire subtree?
    mace::ContextMapping::updateMapping( dest, msg.ctxId );
    mace::ContextBaseClass::migrationTicket = 0;

    // notify the later events to proceed.
    pthread_cond_broadcast(&mace::ContextBaseClass::migrateContextCond);
    pthread_mutex_unlock( &mace::ContextBaseClass::__internal_ContextMutex );
    // notify the head that this event finished.
    downcall_route( ContextMapping::getHead() , __event_commit(ContextMapping::getHeadContext(), msg.eventId, false ));
    }
    #
       },
        {
        # chuangw: FIXME: incorrect here
            param => "TransferContext",
            body => qq#{
    mace::AgentLock::nullTicket();
    mace::string ctxSnapshot;
    Serializable *sobj;
    // wait for earlier events to finish
    
    // traverse the context structure
    sobj = findContextByID( msg.ctxId );
    // create object using name string
    mace::deserialize( ctxSnapshot, sobj );


    // update my local context mapping
    ContextMapping::updateMapping( localAddress(), msg.ctxId );
    // local commit.

    // notify the parent context node
    downcall_route( msg.parentContextNode, ContextMigrationResponse(msg.ctxId, msg.eventId  ) );
    // commit the childnodes.
    mace::ContextBaseClass *thisContext = getContextObjByID( msg.ctxId, msg.eventId );
    if( thisContext->isLocalCommittable()  ){ // ignore DAG case.
        mace::ContextLock( *thisContext, mace::ContextLock::NONE_MODE );
// chuangw: FIXME: use three mutex locks at the same time....wow
        ScopedLock sl( mace::ContextBaseClass::__internal_ContextMutex ); // protect internal structure
        const mace::set< mace::string>* subcontexts = thisContext->getChildContextID();
        for( mace::set<mace::string>::iterator subctxIter= subcontexts->begin(); subctxIter != subcontexts->end(); subctxIter++ ){
            if( subctxIter->compare( msg.ctxId ) == 0 ) continue; // deal with the target context differently.
            // TODO: if child contexts are located on the same node, queue the message on the async event queue...
            //const mace::string& nextHop  = *subctxIter; // prepare messages sent to the child contexts
            //ContextMigrationRequest nextmsg( );
            //mace::MaceKey nextHopNode = mace::ContextMapping::getNodeByContext( nextHop );
            //downcall_route( nextHopNode, nextmsg);
            /*mace::string buf;
            mace::serialize(buf, &nextmsg);
            __internal_unAck[ nextHop ][ msgseqno ] = buf;*/
        }
    }
}#
        },
        {
            param => "ReportContextMigration",
            body => qq#{
    // commit the migration event
    mace::AgentLock::nullTicket();
    if( ContextMapping::getHead() == localAddress() ){
        // send messages to all nodes( except the src of this message ) to update context mapping
        for( std::set<MaceKey>::iterator nodeit = ContextMapping::getAllNodes().begin();
            nodeit != ContextMapping::getAllNodes().end(); nodeit ++ ){
            downcall_route( *nodeit, ContextMappingUpdate( msg.ctxId, src )) ;
        }
    }else{
        maceerr<< "ReportContextMigration message should go to head only" << Log::endl;
    }
            }#
        },
        {
            param => "ContextMappingUpdate",
            body => qq#{
    mace::AgentLock::nullTicket();
    mace::list<mace::string> tmpCtxList;
    tmpCtxList.push_back( msg.ctxId );
    ContextMapping::updateMapping(msg.node, tmpCtxList );
            }#
        },
        {
            param => "HeadEvent",
            body => qq#{
    mace::AgentLock lock(mace::AgentLock::WRITE_MODE);
    if( ContextMapping::getHead() == localAddress() ){
        mace::HighLevelEvent he( msg.event.eventType );
        mace::string buf; // chuangw: TODO: I'm not sure what this is used for.
        mace::serialize( buf, &msg );
        mace::HierarchicalContextLock h1(he,buf);
        switch( msg.event.eventType ){
            case mace::HighLevelEvent::STARTEVENT:{
                downcall_route( ContextMapping::getNodeByContext(""), __msg_maceInit( he.eventID ) );
                break;
                }
            case mace::HighLevelEvent::ENDEVENT:{
                /*
                downcall_route( ContextMapping::getNodeByContext(""), __msg_maceExit( he.eventID ) );*/
                break;
                }
            case mace::HighLevelEvent::TIMEREVENT:{
                // chuangw: I think this means the event is committing.
                break;
                }
            case mace::HighLevelEvent::ASYNCEVENT:{
                // chuangw: I think this means the event is committing.
                break;
                }
            case mace::HighLevelEvent::UPCALLEVENT:{
                // chuangw: I think this means the event is committing.
                break;
                }
            case mace::HighLevelEvent::DOWNCALLEVENT:{
                // chuangw: I think this means the event is committing.
                break;
                }
            case mace::HighLevelEvent::MIGRATIONEVENT:{
            // TODO: update context mapping
            // and then serialize context context, and copy to the destination node.
                break;
                }
            case mace::HighLevelEvent::UNDEFEVENT:{
                break;
                }
        }
    }
            }#
        },
        {
            param => "__event_commit",
            body => qq#{
    mace::AgentLock::nullTicket();
    if( msg.ctxID == ContextMapping::getHeadContext() ){
        // TODO: do global commit
        // hl.commit();
        return;
    }
    if( msg.isresponse ){
        ThreadStructure::setTicket( msg.ticket );
        pthread_mutex_lock( &mace::ContextBaseClass::eventCommitMutex );
        pthread_cond_signal( mace::ContextBaseClass::eventCommitConds[msg.ticket] );
        pthread_mutex_unlock( &mace::ContextBaseClass::eventCommitMutex );
    }else{
        ThreadStructure::setTicket( msg.ticket );
        mace::ContextBaseClass *thisContext = getContextObjByID( msg.ctxID, msg.ticket );
        mace::ContextLock cl( *thisContext, mace::ContextLock::NONE_MODE );
        // downgrade context to NONE mode
        downcall_route( src, __event_commit( msg.ctxID, msg.ticket, true ) );
    }
            }#
        },{
            param => "__none_event",
            body => qq#{
            // TODO: chuangw: unfinished
        mace::AgentLock::nullTicket();
        mace::ContextBaseClass *thisContext = getContextObjByID( msg.ctxID, msg.ticket );
        mace::ContextLock cl( *thisContext, mace::ContextLock::NONE_MODE );
        // send to all child contexts of this context

            }#
        },
        {
            param => "__event_snapshot",
            body => qq#{
    // store the snapshot
    mace::AgentLock::nullTicket();
    pthread_mutex_lock(&mace::ContextBaseClass::eventSnapshotMutex );
    std::pair< uint64_t, mace::string > key( msg.ticket, msg.ctxID );
    std::map<mace::string, mace::string>& snapshots = mace::ContextBaseClass::eventSnapshotStorage[ key ];
    snapshots[ msg.snapshotContextID ] = msg.snapshot;
    // if the event is waiting in the target context, notify it.
    std::map<uint64_t, pthread_cond_t*>::iterator condIt = mace::ContextBaseClass::eventSnapshotConds.find( msg.ticket );
    if( condIt !=  mace::ContextBaseClass::eventSnapshotConds.end() ){
        pthread_cond_signal( condIt->second );
    }
    pthread_mutex_unlock(&mace::ContextBaseClass::eventSnapshotMutex );
            }#
        }

    );
    my @msgContextMigrateRequest = (
        {
            name => "ContextMigrationRequest",
            param => [ {type=>"mace::string",name=>"ctxId"}, {type=>"MaceKey",name=>"dest"}, {type=>"bool",name=>"isRoot" }, {type=>"uint64_t",name=>"eventId" }, {type=>"mace::string",name=>"nextHop" }   ]
        },
        {
            name => "ContextMigrationResponse",
            param => [ {type=>"mace::string",name=>"ctxId"},  {type=>"uint64_t",name=>"eventId" }   ]
        },
        {
            name => "TransferContext",
            param => [ {type=>"mace::string",name=>"ctxId"}, {type=>"mace::string",name=>"checkpoint"}, {type=>"uint64_t",name=>"eventId" }, {type=>"MaceKey",name=>"parentContextNode" }   ]
        },
        {
            name => "ReportContextMigration",
            param => [ {type=>"mace::string",name=>"ctxId"}, {type=>"uint64_t",name=>"eventId" }    ]
        },
        {
            name => "ContextMappingUpdate",
            param => [ {type=>"mace::string",name=>"ctxId"}, {type=>"MaceKey",name=>"node"}   ]
        },
        { #chuangw This message is not exclusive to migration 
            name => "HeadEvent",
            param => [ {type=>"mace::HighLevelEvent",name=>"event"}   ]
        },
        { #chuangw This message is not exclusive to migration 
            name => "__event_commit",
            param => [ {type=>"mace::string",name=>"ctxID"}, {type=>"uint64_t",name=>"ticket"}, {type=>"bool",name=>"isresponse"}   ]
        },
        { #chuangw This message is not exclusive to migration 
            name => "__event_snapshot",
            param => [ {type=>"uint64_t",name=>"ticket"}, {type=>"mace::string",name=>"ctxID"}, {type=>"mace::string",name=>"snapshotContextID"}, {type=>"mace::string",name=>"snapshot"}   ]
        },{ #chuangw This message is not exclusive to migration 
            name => "__none_event",
            param => [ {type=>"uint64_t",name=>"ticket"}, {type=>"mace::string",name=>"ctxID"}   ]
        }

    );

    $this->addContextMigrationMessages( \@msgContextMigrateRequest );
    $this->addContextMigrationTransitions(\@handlerContextMigrate);

}
sub validate_fillAsyncHandler {
    my $this = shift;
    my $m = shift;
    my $ref_transitionNum = shift;

    if( @{ $this->contexts } == 0 ){
        return;
    }

    if( not $Mace::Compiler::Globals::supportFailureRecovery ){
        Mace::Compiler::Globals::error("bad_context", $this->filename(), $this->line(), "Failure recovery must be turned.");
    }elsif( not $this->addFailureRecoveryHack()  ){
        Mace::Compiler::Globals::error("bad_context", $this->filename(), $this->line(), "This service does not use Transport service.");
    }
#chuangw: implement async call redirect
# when an async_foo call is processed via validate_findAsyncTransitions, a corresponding message __async_at_1_foo is generated
# implicitly. A upcll handler responsible for this message is also created.
# In here, when we find such a handler, we create __async_fn_1_foo() and __async_head_fn_1_foo() helper method 

    # check if the parameter is the message generated from async/routines/timer/downcall/upcall
    my $isDerivedFromMethodType = 0;
                    
    my $p;
    my $message;
    CHECKPARAMETER: for my $param ($m->params()) {
        next if (not $param->flags("message"));
        for my $msg ($this->messages() ){
            if( $param->type->type() eq $msg->name() and $msg->special_call eq "special" ){
                $isDerivedFromMethodType = $msg->method_type;
                $p = $param;
                $message = $msg;
                last CHECKPARAMETER;
            }
        }
    }
    if( $isDerivedFromMethodType > 0 ){
        if( not $Mace::Compiler::Globals::supportFailureRecovery ){
            Mace::Compiler::Globals::error("bad_context", $this->filename(), $this->line(), "Failure recovery must be turned on.");
        }elsif ( scalar( @{ $this->contexts() } )== 0 ){
            Mace::Compiler::Globals::error("bad_context", $this->filename(), $this->line(), "No context is defined in the service.");
        }elsif( not $this->addFailureRecoveryHack()  ){
            Mace::Compiler::Globals::error("bad_context", $this->filename(), $this->line(), "This service does not use Transport service.");
        }
    }else{
        return;
    }
    my $apiBody = $m->body();
    if( $m->name eq 'messageError' ){
        if( $isDerivedFromMethodType == Mace::Compiler::AutoType::FLAG_CONTEXT ){ 
            # create empty transition handler, because for these special messages, only deliver() handlers are defined,
            # messageError handlers are not defined, but compiler generates annoying warnings that should not display to the users.
        }
    }elsif( $m->name eq "deliver" ){
        if( $isDerivedFromMethodType == Mace::Compiler::AutoType::FLAG_ASYNC ){
           $apiBody = $this->asyncCallHandlerHack(  $p, $message );
        }elsif( $isDerivedFromMethodType == Mace::Compiler::AutoType::FLAG_SYNC ){
            $apiBody = $this->routineCallHandlerHack( $p,  $message,  $m->returnType->name);
        }elsif( $isDerivedFromMethodType == Mace::Compiler::AutoType::FLAG_TARGET_SYNC ){
            $apiBody = $this->targetRoutineCallHandlerHack( $p,  $message);
        }elsif( $isDerivedFromMethodType == Mace::Compiler::AutoType::FLAG_SNAPSHOT ){
            $apiBody = $this->snapshotSyncCallHandlerHack( $p, $message );
        }elsif( $isDerivedFromMethodType == Mace::Compiler::AutoType::FLAG_CONTEXT ){ # do nothing 
            return;
        }

    }
    # add a new transition and make a copy of the method
    my $helper = Mace::Compiler::Method->new(
        body => $apiBody, 
        throw => undef,
        filename => $m->filename,
        isConst => 0, 
        isUsedVariablesParsed => 0,
        isStatic => 0, 
        name => $m->name,
        returnType => $m->returnType,
        line => $m->line,
        );
    # chuangw: don't ContextLock on async/sync call message handler.
    $helper->options('nocontext',1);
    foreach( $m->params ){
        my $dp = ref_clone( $_ );
        $dp->hasDefault(0);
        $helper->push_params( $dp );
    }
    my $t = Mace::Compiler::Transition->new(name => $m->name(), #$item{Method}->name(), 
    startFilePos => -1, #($thisparser->{local}{update} ? -1 : $item{StartPos}),
    columnStart => -1,  #$item{StartCol}, 
    type => "upcall", 
    method => $helper,
    startFilePos => -1,
    columnStart => '-1',
    
    transitionNum => $$ref_transitionNum++,
    );
    my $guardfunc = Mace::Compiler::Guard->new( 
        file => __FILE__,
        guardStr => 'true',
        type => 'state_var',
        state_expr => Mace::Compiler::ParseTreeObject::StateExpression->new(type=>'null'),
        line => __LINE__
    );
    $t->push_guards( $guardfunc );
    $this->push_transitions( $t );
}
#chuangw: create several helpers that are used for context'ed services.
sub createContextUtilHelpers {
    my $this = shift;

    my @helpers = (
        {
            return => {type=>"uint32_t",const=>0,ref=>0},
            param => [ {type=>"mace::string",name=>"ctxId", const=>1, ref=>1} ],
            name => "getNextSeqno",
            body => qq#{
        mace::map<mace::string, uint32_t>::iterator seqnoIt = __internal_msgseqno.find(ctxId);
        if(seqnoIt == __internal_msgseqno.end() ){
            seqnoIt->second = 1;
            return 1;
        }else{
            uint32_t& msgseqno = seqnoIt->second;
            __internal_msgseqno[ctxId]++;
            return msgseqno;
        }
    }
            #,
        },{
            return => {type=>"void",const=>0,ref=>0},
            param => [ {type=>"mace::string",name=>"thisContextID", const=>1, ref=>1}, {type=>"mace::set<mace::string>",name=>"snapshotContextIDs", const=>1, ref=>1}, {type=>"uint64_t",name=>"ticket", const=>1, ref=>0},{type=>"uint16_t",name=>"nsnapshots", const=>1, ref=>0} ],

            name => "asyncPrep",
            body => qq#
    {
        // FIXME: chuangw: i don't have to to make snapshot taking work. will come back later.
        ThreadStructure::pushContext( thisContextID );
        ThreadStructure::setTicket( ticket );
        // wait for snapshots
        pthread_mutex_lock( &mace::ContextBaseClass::eventSnapshotMutex  );
        std::pair< uint64_t, mace::string > key( ticket, thisContextID );
        while( mace::ContextBaseClass::eventSnapshotStorage[ key ].size() < nsnapshots /* waiting for some snapshots to arrive */ ){
            // add cond variable to a public static map
            pthread_cond_t cond;
            pthread_cond_init( &cond, NULL );
            mace::ContextBaseClass::eventSnapshotConds[ ticket ] = &cond;
            pthread_cond_wait(&cond , &mace::ContextBaseClass::eventSnapshotMutex);
            macedbg(1)<<thisContextID<<" received snapshot number: "<< mace::ContextBaseClass::eventSnapshotStorage[ key ].size() <<Log::endl;
        }
        // copy the snapshot
        pthread_mutex_unlock( &mace::ContextBaseClass::eventSnapshotMutex);

        for( mace::set<mace::string>::iterator ssIt= snapshotContextIDs.begin();
            ssIt != snapshotContextIDs.end(); ssIt++ ){
            mace::ContextBaseClass *thisContext = getContextObjByID( *ssIt, ticket );
            std::pair<uint64_t, mace::string> key( ticket, thisContextID );
            thisContext->setSnapshot( ticket, mace::ContextBaseClass::eventSnapshotStorage[key][ *ssIt ] );
        }
    }
    #,
        },{
            return => {type=>"void",const=>0,ref=>0},
            param => [ {type=>"mace::ContextBaseClass*",name=>"thisContext", const=>0, ref=>0},{type=>"uint64_t",name=>"ticket", const=>1, ref=>1},{type=>"mace::set<mace::string>",name=>"snapshotContextIDs", const=>1, ref=>1} ],
            name => "asyncFinish",
            body => qq#
    {
        mace::ContextLock( *thisContext, mace::ContextLock::NONE_MODE );
        ThreadStructure::popContext(  );
        /*for( mace::set<mace::string>::iterator vcIt=snapshotContextIDs.begin();vcIt!=snapshotContextIDs.end();vcIt++){
            mace::MaceKey node = mace::ContextMapping::getNodeByContext( *vcIt );
            __event_commit msg( *vcIt, ticket, false );

            pthread_mutex_lock( &mace::ContextBaseClass::eventCommitMutex );
            downcall_route( node, msg );
            pthread_cond_t cond;
            pthread_cond_init( &cond, NULL );
            mace::ContextBaseClass::eventCommitConds[ ticket ] = &cond;
            pthread_cond_wait( &cond, &mace::ContextBaseClass::eventCommitMutex );
            
            pthread_mutex_unlock( &mace::ContextBaseClass::eventCommitMutex );
        }*/
        // inform head node this event is ready to do global commit
        downcall_route( ContextMapping::getHead() , __event_commit(ContextMapping::getHeadContext(), ticket, false ));
    }
    #,
        },{
            return => {type=>"bool",const=>0,ref=>0},
            param => [ {type=>"MaceKey",name=>"source", const=>1, ref=>1},{type=>"mace::string",name=>"lastHop", const=>1, ref=>1},{type=>"uint32_t",name=>"seqno", const=>1, ref=>0} ],
            name => "ackUpdateRespond",
            body => qq#
    {
        ScopedLock sl( mace::ContextBaseClass::__internal_ContextMutex ); // protect internal structure

        uint32_t& lastAcked = __internal_lastAckedSeqno[ lastHop ];
        mace::map< uint32_t, uint8_t>& receivedSeqno = __internal_receivedSeqno[lastHop];

        if( seqno <= lastAcked ){ 
            downcall_route( source, __internal_Ack( lastAcked, lastHop ) ); // send back the last acknowledge sequence number 
            return false;
        }
        // update received seqno queue & lastAckseqno
        receivedSeqno[ seqno ] = 1;
        uint32_t expectedSeqno = lastAcked+1;

        while( expectedSeqno == receivedSeqno.begin()->first ){ // erase the first sequence number not acknowledged
            receivedSeqno.erase( receivedSeqno.begin() );
            lastAcked++;
            expectedSeqno++;
        }

        downcall_route( source, __internal_Ack( lastAcked, lastHop  ) ); // always send ack before processing message
        return true;
    }
    #,
        },{
            return => {type=>"mace::string",const=>0,ref=>0},
            param => [ {type=>"mace::vector<mace::string>",name=>"allContextIDs", const=>1, ref=>1} ],
            name => "getStartContext",
            body => qq#{
// find the longest common prefix
// Notice that this only works for tree but not DAG hierarchy.
    if( allContextIDs.size() == 0 )
        return mace::string("");

    size_t pos = 0;
    bool sameChar = true;
    do{
        char compChar;
        if( allContextIDs[0].size() > pos ){
            compChar = allContextIDs[0][pos];
        }else{
            break;
        }
        for( mace::vector<mace::string>::const_iterator it = allContextIDs.begin(); it != allContextIDs.end(); it++ ){
            if( it->size() < pos ){
                sameChar = false;
                break;
            }else if( (*it)[pos] != compChar ){
                sameChar = false;
                break;
            }
        }
        if( sameChar )
            pos++;
    }while( sameChar == true );

    return allContextIDs[0].substr(0, pos);
}
#,
        },{
            return => {type=>"Serializable*",const=>0,ref=>0},
            param => [ {type=>"mace::string",name=>"contextID", const=>1, ref=>1} ],
            name => "findContextByID",
            body => "{\n" . $this->generateSerializeContextCode() . "\n}\n",
        },{
            return => {type=>"mace::ContextBaseClass*",const=>0,ref=>0},
            param => [ {type=>"mace::string",name=>"contextID", const=>1, ref=>1}, {type=>"uint64_t",name=>"ticket", const=>1, ref=>0} ],
            name => "getContextObjByID",
            body => "{\n" . $this->generateGetContextCode() . "\n}\n",
        },{
            return => {type=>"void",const=>0,ref=>0},
            param => [ {type=>"mace::string",name=>"contextID", const=>1, ref=>1}, {type=>"uint64_t",name=>"ticket", const=>1, ref=>0}, {type=>"mace::string",name=>"s", const=>0, ref=>1}, ],
            name => "copyContextData",
            body => qq#{
                mace::ContextBaseClass *thisContext = getContextObjByID( contextID, ticket );
                mace::serialize(s, thisContext );
                // TODO: may have to serialize the previous context snapshots.

                // TODO: copy other internal structure?
            }#,
        },{
            return => {type=>"void",const=>0,ref=>0},
            param => [ {type=>"mace::string",name=>"contextID", const=>1, ref=>1} ],
            name => "eraseContextData",
            body => qq#{
                //mace::ContextBaseClass *thisContext = getContextObjByID( contextID, 0 );
                // TODO: erase the context object
            }#,
        },{
            return => {type=>"void",const=>0,ref=>0},
            param => [ {type=>"mace::HierarchicalContextLock",name=>"hl", const=>1, ref=>1},{type=>"mace::HighLevelEvent",name=>"he", const=>1, ref=>1} ],
            name => "storeHeadLog",
            body => qq#{
                // chuangw: FIXME: I commented out the code because it does not run properly.
                /*mace::string logStr;
                mace::serialize(logStr, &__internal_receivedSeqno);
                mace::serialize(logStr, &__internal_lastAckedSeqno);
                mace::serialize(logStr, &__internal_msgseqno);
                mace::serialize(logStr, &__internal_unAck);
                mace::serialize(logStr, &he);
                mace::serialize(logStr, &hl);
                sl.unlock();
                std::ofstream logFile;
                logFile.open("HeadLog.txt");
                logFile << logStr;
                logFile.close();
                sl.lock();
                */
            }#,
        },{
            return => {type=>"void",const=>0,ref=>0},
            param => [ {type=>"__asyncExtraField",name=>"extra", const=>1, ref=>1},{type=>"mace::string",name=>"thisContextID", const=>1, ref=>1},{type=>"mace::ContextBaseClass*",name=>"thisContext", const=>1, ref=>1} ],
            name => "sendAsyncSnapshot",
            body => qq#{
            mace::set<mace::string>::iterator snapshotIt = extra.snapshotContextIDs.find( thisContextID );
            ThreadStructure::setTicket( extra.ticket );
            if( snapshotIt != extra.snapshotContextIDs.end() ){
                mace::ContextLock( *thisContext, mace::ContextLock::READ_MODE );// get read lock
                //const mace::ContextBaseClass ctxSnapshot = thisContext->getSnapshot();
                mace::string snapshot;// get snapshot
                mace::serialize(snapshot, thisContext );
                // send to the target context node.
                __event_snapshot msg( extra.ticket,extra.targetContextID, *snapshotIt, snapshot );
                downcall_route( ContextMapping::getNodeByContext( extra.targetContextID ), msg );
            }
            mace::ContextLock( *thisContext, mace::ContextLock::NONE_MODE );
            }#,
        },{
            return => {type=>"void",const=>0,ref=>0},
            param => [ {type=>"mace::ContextBaseClass*",name=>"thisContext", const=>0, ref=>1},{type=>"mace::set<mace::string>*",name=>"subcontexts", const1=>1, ref=>1},{type=>"__asyncExtraField",name=>"extra", const=>1, ref=>1},{type=>"bool",name=>"isTarget", const=>1, ref=>0} ],
            name => "asyncEventCheck",
            body => qq#{
      mace::AgentLock lock(mace::AgentLock::WRITE_MODE);

        // chuangw: FIXME: potential deadlock. will fix it later.
        if( mace::ContextBaseClass::migrationTicket > 0 && mace::ContextBaseClass::migrationTicket < extra.ticket && 
            extra.nextHop == mace::ContextBaseClass::migrationContext ){
            // A migration event is taking place. Wait for the migration to complete.
            pthread_cond_wait( &mace::ContextBaseClass::migrateContextCond, &mace::ContextBaseClass::__internal_ContextMutex );
            ASSERTMSG( mace::ContextBaseClass::migrationTicket == 0,"migration ticket is supposed to be zero after the migration completes!" );
        }
        thisContext = getContextObjByID( extra.nextHop, extra.ticket );
        ThreadStructure::setMyContext( thisContext );
        if( !isTarget ){
            thisContext->addNewChild( extra.targetContextID, extra.ticket );
        }
        
        subcontexts = thisContext->getChildContextID();
    }#,
        }
    );
    foreach( @helpers ){
        my $returnType = Mace::Compiler::Type->new(type=>$_->{return}->{type},isConst=>$_->{return}->{const},isConst1=>0,isConst2=>0,isRef=>$_->{return}->{ref});
        my @params;
        foreach( @{$_->{param} } ){
            my $type;
            if( defined $_->{const} ){
                $type = Mace::Compiler::Type->new(type=>$_->{type},isConst=>$_->{const},isConst2=>0,isRef=>$_->{ref});
            }elsif (defined $_->{const1} ){
                $type = Mace::Compiler::Type->new(type=>$_->{type},isConst1=>$_->{const1},isConst2=>0,isRef=>$_->{ref});
            }
            my $field = Mace::Compiler::Param->new(name=>$_->{name}, type=>$type);
            push @params, $field;
        }
        my $method = Mace::Compiler::Method->new(name=>$_->{name},  returnType=>$returnType, body=>$_->{body});
        $method->params(@params);

        $this->push_syncHelperMethods($method);
    }
}
sub validate_replaceMaceInitExit {
    my $this = shift;

    my @oldTransitionMethod;
    my @methodMessage;
    foreach my $transition ($this->transitions()) { # find maceInit() where state==init
        my $m = $transition->method;
        next if ($transition->type() ne 'downcall' or ( $m->name ne 'maceInit' and $m->name ne 'maceExit'));

        # replace the old maceInit with our own
        my $eventType; 
        if( $m->name() eq "maceInit" ){ $eventType = "STARTEVENT"; }
        elsif( $m->name() eq "maceExit" ) { $eventType = "ENDEVENT"; }
        my $oldMaceInitBody = $transition->method->body();
        my $hackBody = qq#
        {
            //mace::AgentLock lock(mace::AgentLock::WRITE_MODE);
            mace::AgentLock::nullTicket();

            ThreadStructure::setTicket( msg.ticket );
            ThreadStructure::setMyContext( &mace::ContextBaseClass::globalContext );
            mace::ContextLock __contextLock0(mace::ContextBaseClass::globalContext, mace::ContextLock::WRITE_MODE);
            
            $oldMaceInitBody

            // downgrade to none and commit locally & globally

            const mace::set< mace::string >* subcontexts = ThreadStructure::myContext()->getChildContextID();

            macedbg(1)<< ThreadStructure::getCurrentContext() <<": sending commit messages to child context:"<< Log::endl;
            macedbg(1)<< "-->" <<*subcontexts <<"<--" <<Log::endl;
            pthread_mutex_lock( &mace::ContextBaseClass::eventCommitMutex );
            for( mace::set<mace::string>::iterator subctxIter= subcontexts->begin(); subctxIter != subcontexts->end(); subctxIter++ ){
                // TODO: if child contexts are located on the same node, queue the message on the async event queue...
                const mace::string& nextHop  = *subctxIter; // prepare messages sent to the child contexts
                __event_commit nextmsg( nextHop, msg.ticket, false );
                mace::MaceKey nextHopNode = mace::ContextMapping::getNodeByContext( nextHop );
                downcall_route( nextHopNode, nextmsg);
                /*mace::string buf;
                mace::serialize(buf, &nextmsg);
                __internal_unAck[ nextHop ][ msgseqno ] = buf;*/
            }
            pthread_cond_t cond;
            pthread_cond_init( &cond, NULL );
            mace::ContextBaseClass::eventCommitConds[ msg.ticket ] = &cond;
            uint32_t no_ctx = subcontexts->size();
            uint32_t receive_counter = 0;
            while(receive_counter < no_ctx){
                pthread_cond_wait( &cond, &mace::ContextBaseClass::eventCommitMutex );
                receive_counter++;
            }
            mace::ContextBaseClass::eventCommitConds.erase( msg.ticket );
            
            pthread_mutex_unlock( &mace::ContextBaseClass::eventCommitMutex );

            __contextLock0.downgrade( mace::ContextLock::NONE_MODE );
            downcall_route( ContextMapping::getHead() , __event_commit(ContextMapping::getHeadContext(),msg.ticket , false ));
        }
        #;
        my $newMaceInitBody = qq#
            //test
            mace::HighLevelEvent he( mace::HighLevelEvent::$eventType );
            downcall_route( mace::ContextMapping::getHead(), HeadEvent(he) );
        #;
        $transition->method->body( $newMaceInitBody );
        my %hackmsg = (
            name => "__msg_" . $m->name,
            param => [ {type=>"uint64_t",name=>"ticket"}   ]
        );
        my %hackmethod = (param=>"__msg_" . $m->name, body=>$hackBody);
        push @methodMessage, \%hackmsg;
        push @oldTransitionMethod, \%hackmethod;

    }
    $this->addContextMigrationMessages( \@methodMessage );
    $this->addContextMigrationTransitions(\@oldTransitionMethod);
}
sub validate_findRoutines {
    my $this = shift;
    my $ref_routineMessageNames = shift;
    for my $r ($this->routines()) {
        next if (defined $r->targetContextObject and $r->targetContextObject eq "__internal" );
        next if (defined $r->targetContextObject and $r->targetContextObject eq "__anon" );
        next if (defined $r->targetContextObject and $r->targetContextObject eq "__null" );
        $this->createContextRoutineHelperMethod( $r, $ref_routineMessageNames  );
    }
}
sub createContextHelpers {
    my $this = shift;
    if( @{ $this->contexts } == 0 ){
        return;
    }
    if( not $Mace::Compiler::Globals::supportFailureRecovery ){
        Mace::Compiler::Globals::error("bad_context", $this->filename(), $this->line(), "Failure recovery must be turned.");
    }elsif( not $this->addFailureRecoveryHack()  ){
        Mace::Compiler::Globals::error("bad_context", $this->filename(), $this->line(), "This service does not use Transport service.");
    }

    my @asyncMessageNames;
    my @syncMessageNames;
    $this->createAsyncExtraField();
    $this->validate_findDeliverUpcallMethods();
    $this->addContextMigrationHelper();
    $this->validate_replaceMaceInitExit();
    $this->validate_findAsyncTransitions(\@asyncMessageNames);
    $this->validate_findRoutines(\@syncMessageNames);
    $this->validate_findTimerTransitions(\@asyncMessageNames);
    $this->validate_findResenderTimer(\@asyncMessageNames, \@syncMessageNames);
    $this->createSnapShotSyncHelper();
    $this->createContextUtilHelpers();
}

sub validate {
    my $this = shift;
    my @deferNames = @_;
    my $i = 0;


    $this->push_deferNames(@_);

    my $name = $this->name();
    my $attr = $this->attributes();
    if ($attr eq "") {
        $attr = $name;
    } else {
        $attr .= ",$name";
    }
    $this->attributes($attr);
    $Mace::Compiler::Globals::MACE_TIME = $this->macetime();

    $this->push_states('init');
    $this->push_states('exited');
    $this->push_ignores('hashState');
    $this->push_ignores('registerInstance');
    $this->push_ignores('maceReset');
    $this->push_ignores('getLogType');
    $this->push_ignores('localAddress');

    for my $det ($this->detects()) {
        $det->validate($this);
    }

    if ($this->queryFile() ne "") {
        $this->computeLogObjects();
    }

    $this->validate_prepareSelectorTemplates();
    $this->validate_parseProvidedAPIs(); #Note: Provided APIs can update the impl.  (Mace literal blocks)
    my $transitionNum = 0;

    foreach my $transition ($this->transitions()) {
        $transition->transitionNum($transitionNum++);
    }
    $this->validate_parseUsedAPIs(); #Note: Used APIs can update the impl.  (Mace literal blocks)
    $this->validate_fillStructuredLogs();

    $this->createContextHelpers();

    foreach my $message ($this->messages()) {
        $message->validateMessageOptions();
    }

    foreach my $autotype ($this->auto_types()) {
        $autotype->validateAutoTypeOptions();
#        print "VALIDATING autotype ".$autotype->name()." serialized? ".$autotype->serialize()."\n";
# should log all auto type methods
#       for my $slog ($autotype->methods()) {
#           $slog->doStructuredLog($slog->getLogLevel($this->traceLevel()) > 0);
#       }
    }

    foreach my $var ($this->state_variables()) {
        $var->validateTypeOptions({'serialize' => 0, 'recur' => 1});
        my $myhash = $var->type();
#        print $var->name(). " has type ".$var->type()->type()." and is marked for serialization? ".$var->flags('serialize') ."\n";
#        while ( my ($key, $value) = each(%$myhash) ) {
#            print "$key => $value\n";
#        }
    }

    foreach my $context ($this->contexts() ) {
        $context->validateContextOptions();
    }

    # create map autotypestr => autotypeobject
    my %autoTypeMap;
    foreach my $autotype ($this->auto_types()) {
        $autoTypeMap{$autotype->name()} = $autotype;
    }

    # updating state variable serialization flag based on whether or not the type is serializable
    # Specifically, if the type is an auto type, and the type is marked no serialize, then don't try
    foreach my $var ($this->state_variables()) {
        my $type = $var->type()->type();
        if(exists $autoTypeMap{$type} && $autoTypeMap{$type}->serialize() == 0){
            $var->flags('serialize', 0);
        }
    }


#    foreach my $var ($this->state_variables()) {
#        print $var->name(). " has type ".$var->type()->type()." and is marked for serialization? ".$var->flags('serialize') ."\n";
#    }

    for my $m ($this->constructor_parameters()) {
        $m->type()->set_isConst();
    }

#       print "dumping everything\n\n";
#       for my $m ($this->usesDowncalls(), $this->usesUpcalls(), $this->implementsUpcalls(), $this->implementsDowncalls()) {
#           print $m->toString(noline => 1) . "\n";
#       }
#       die "ayeee!!!";

    #This portion handles the method remappings block by removing pristine methods from state,
    #placing them in a remapping list, and replacing them with ones using remapped types
    $this->validate_genericMethodRemapping("usesDowncalls", "usesClassMethods", 0, 1, 0, 1);
    $this->validate_genericMethodRemapping("usesUpcalls", "providedHandlerMethods", 1, 1, 0, 1);
    #print "------------------\n";
    for my $u ($this->usesHandlerMethods() ){
        #print ">>";
        #print Dumper ( $u->params() ) . "\n";
        #print $u->name() . "(" . join(",", map{$_->name(). ":" . $_->type->type() } $u->params()) . ")\n";
    }
    $this->validate_genericMethodRemapping("implementsUpcalls", "usesHandlerMethods", 0, 0, 1, 0);
    #print "------------------\n";
    #for my $u ($this->usesHandlerMethods() ){
    #    print ">>";
    #    #print Dumper ( $u->params() ) . "\n";
    #    print $u->name() . "(" . join(",", map{$_->name(). ":" . $_->type->type() } $u->params()) . ")\n";
    #}
    $this->validate_genericMethodRemapping("implementsDowncalls", "providedMethods", 0, 0, 1, 0);



    $this->validate_setupSelectorOptions("routine", $this->routines());
    $this->validate_setupRoutines(\$i);

    my $multiTypeOption = Mace::Compiler::TypeOption->new(name=>"multi");
    $multiTypeOption->options('yes','yes');
    my @multiTypeOptions = ( $multiTypeOption );
    for my $mh (grep { ! ( $_->messageField() or ! $this->countDeferMatch("upcall_".$_->name())) } $this->providedHandlerMethods()) {
        $this->validate_setBinlogFlags($mh, \$i, "upcall_", $mh->getLogLevel($this->traceLevel()) > 0);
        $this->push_upcallDeferMethods($mh);
    }

    for my $mh (grep { ! ( $_->messageField() or ! $this->countDeferMatch("downcall_".$_->name())) } $this->usesClassMethods()) {
        $this->validate_setBinlogFlags($mh, \$i, "downcall_", $mh->getLogLevel($this->traceLevel()) > 0);
        $this->push_downcallDeferMethods($mh);
    }
    for my $mh (grep { ! ( $_->messageField() or ! $this->countDeferMatch($_->name()) ) } $this->routines()) {
        $this->push_routineDeferMethods($mh);
    }

    for my $timer ($this->timers()) {
        if( not $transitionNameMap{ $timer->name } or $transitionNameMap{ $timer->name }->type ne "scheduler" ){
            Mace::Compiler::Globals::warning("bad_transition", $timer->filename(), $timer->line(), "The timer $timer->{name} is defined, but corresponding scheduler transition is not defined.");
        }

        $timer->validateTypeOptions($this);
        my $v = Mace::Compiler::Type->new('type'=>'void');
        my $timerMethodName= "expire_".$timer->name;
        my $m = Mace::Compiler::Method->new('name' => $timerMethodName, 'body' => '{ }', 'returnType' => $v);
        my $i = 0;
        for my $t ($timer->types()) {
            my $dupet = ref_clone($t);
            $dupet->set_isRef();
            my $p = Mace::Compiler::Param->new(name=>"p$i", type=>$dupet);
            $m->push_params($p);
            $i++;
        }
        #$m->options('timer' => $timer->name, 'timerRecur' => $timer->recur(), 'transitions' => []);
        $m->options('timer' => $timer->name, 'timerRecur' => $timer->recur());

        $this->push_timerMethods($m);
    }

    #this code handles selectors and selectorVars for methods passed to demuxFunction
    $this->validate_setupSelectorOptions("demux", $this->usesHandlerMethods(), $this->providedMethods(), $this->timerMethods(), $this->implementsUpcalls(), $this->implementsDowncalls(), $this->asyncMethods(), $this->syncMethods());

    #this code handles selectors and selectorVars for methods passed to demuxFunction
    $this->validate_setupSelectorOptions("upcall", $this->providedHandlerMethods(), $this->usesUpcalls());

    #this code handles selectors and selectorVars for methods passed to demuxFunction
    $this->validate_setupSelectorOptions("downcall", $this->usesClassMethods(), $this->usesDowncalls());

    #this code handles selectors and selectorVars for methods passed to demuxFunction
    $this->validate_setupSelectorOptions("async", $this->asyncHelperMethods());

    $this->validate_setupSelectorOptions("sync",  $this->syncHelperMethods());

    $this->validate_setupSelectorOptions("routine",  $this->routineHelperMethods());

    $this->validate_setupSelectorOptions("scheduler",  $this->timerHelperMethods());

    for my $method ($this->usesClassMethods(), $this->usesDowncalls()) {
        $this->validate_setBinlogFlags($method, \$i, "", $method->getLogLevel($this->traceLevel()) > 0);
    }


    #This portion validates that transitions match some legal API -- must determine list of timer names before this block.
    #my $transitionNum = 0;
    my $filepos = 0;

    # chuangw: messages from async/sync call were created by validate_findAsyncTransitions and validate_findSyncMethods.
    # now, fill in the respective message handler
    for my $m ($this->usesHandlerMethods()) {
        $this->validate_fillAsyncHandler( $m, \$transitionNum );
    }

    foreach my $transition ($this->transitions()) {
        if ($transition->type() eq 'downcall') {
            $this->validate_fillTransition("downcall", $transition, \$filepos, $this->providedMethods());
        }
        elsif ($transition->type() eq 'upcall') {
            $this->validate_fillTransition("upcall", $transition, \$filepos, $this->usesHandlerMethods());
        }
        elsif ($transition->type() eq 'raw_upcall') {
            $this->validate_fillTransition("raw_upcall", $transition, \$filepos, $this->usesHandlerMethodsAPI());
        }
        elsif ($transition->type() eq 'scheduler') {
            $transition->method->name("expire_".$transition->method->name());
            $this->validate_fillTransition("scheduler", $transition, \$filepos, $this->timerMethods());
        }
        elsif ($transition->type() eq 'async') {
            $this->validate_fillTransition("async", $transition, \$filepos, $this->asyncMethods());
        }
        elsif ($transition->type() eq 'sync') {
                $this->validate_fillTransition("sync",  $transition,  \$filepos,  $this->syncMethods());
        }
        elsif ($transition->type() eq 'aspect') {
            $this->validate_fillAspectTransition($transition, \$filepos);
        }
        else {
            my $ttype = $transition->type();
            Mace::Compiler::Globals::error("bad_transition", $transition->method()->filename(), $transition->method->line(), "Transition type '$ttype' invalid.  Expecting upcall/raw_upcall/downcall/scheduler/async/sync/aspect");
        }
    }
    $this->annotatedMacFile($this->annotatedMacFile() . substr($this->origMacFile(), $filepos));

    for my $p (@{$this->safetyProperties()}, @{$this->livenessProperties()}) {
        $p->validate($this);
    }

    for my $slog (grep(!($_->name =~ /^(un)?register.*Handler$/), $this->providedMethods()), @{$this->aspectMethods()}, @{$this->usesHandlerMethods()}, @{$this->timerMethods()}) {
        $this->validate_setBinlogFlags($slog, \$i, "", ($slog->getLogLevel($this->traceLevel()) > 0 and (defined $slog->options('transitions') or scalar(grep {$_ eq $slog->name} $this->ignores()))));
    }
    $this->validateLogObjects();
} # validate

sub validate_fillStructuredLogs {
    my $this = shift;
    my $name = $this->name();

    for my $slog ($this->structuredLogs()) {
        if (scalar(grep($_->name() eq $slog->name(), $this->structuredLogs())) > 1) {
            Mace::Compiler::Globals::error("bad_structured_log", $slog->filename(), $slog->line(), "Structured log named ".$slog->name()." specified multiple times");
        }
        else {
            my $funcName = $slog->name();
            my $body = "{\nstd::string str;\nstatic int logId = Log::getId(\"${name}::$funcName\");\n";
            my @funcparams;
            for my $param ($slog->params()) {
                my $varName = $param->name();
                push @funcparams, $varName;
            }
            my $clause = $this->wheres->{$slog->name()};
            my $logName = $slog->name();
            $slog->options('binlogname', $logName);
            my $longName = $slog->toString(nodefaults => 1, novirtual => 1, noreturn => 1, noline => 1);
            $longName =~ s/\n/ /g;
            $slog->options('binloglongname', $longName);

            $body .= "if (mace::LogicalClock::instance().shouldLogPath()) {\n";
            if (defined($clause)) {
                $slog->setLogOpts(1, $clause);
            }
#               $body .= "if $clause {\n";
            my $paramList = $slog->paramsToString(notype => 1,
                                                  noline => 1,
                                                  nodefaults => 1);
            $body .= "if (shouldLog_$logName($paramList)) {\n";
#           }
            $body .= "Log::binaryLog(logId, new ${funcName}Dummy(".join(", ", @funcparams)."), 0);\n";
#           if (defined($clause)) {
            $body .= "}\n";
#           }
            $body .= "}\n}";
            $slog->body($body);
            $slog->returnType(Mace::Compiler::Type->new(type => "void"));
            $slog->isConst(1);
        }
        $slog->doStructuredLog($this->traceLevel() > 0);
    }
}


sub createInitReturnValue {
		my $this = shift;
		my $returnType = shift;

		my $initReturnValue = "";

		my $numberIdentifier = "[1-9][0-9]*";
		if($returnType eq 'void'){
		
		}elsif($returnType eq 'int'){
				$initReturnValue = qq/
						int returnValue = 0;
				/;
		}elsif( $returnType =~ /uint($numberIdentifier)_t/){
				$initReturnValue = qq/
						$returnType returnValue = 0;
				/;
		}elsif( $returnType =~ /int($numberIdentifier)_t/){
				$initReturnValue = qq/
						$returnType returnValue = 0;
				/;
		}elsif( $returnType eq 'bool' ){
				$initReturnValue = qq/
						bool returnValue = false;
				/;
		}else{
				$initReturnValue = qq/
						$returnType returnValue;
				/;
		}

		return $initReturnValue;
}
sub generateGetContextCode {
# FIXME: chuangw: consider the case when the context object is not created.
    my $this = shift;
    my @condstr;
    for( @{ $this->contexts() } ){
        push @condstr, $this->locateChildContextObj( $_, 0, "this");
    }
    my $findContextStr = qq@
    mace::ContextBaseClass* ctxobj = NULL;
    if( contextID.empty() ){ // global context id
        return &( mace::ContextBaseClass::globalContext );
    }
    mace::string contextDebugID, contextDebugIDPrefix;
    std::vector<std::string> ctxStrs;
    boost::split(ctxStrs, contextID, boost::is_any_of(":]"), boost::token_compress_on);
    size_t ctxStrsLen = ctxStrs.size();

    std::vector<std::string> ctxStr0;
    boost::split(ctxStr0, ctxStrs[0], boost::is_any_of("[,]") );
    @ . join("else ", @condstr) . 
    qq#
    ASSERTMSG( ctxobj != NULL, "getContextObjByID returns a NULL pointer!");
    return ctxobj;
    #;

    return $findContextStr;
}
sub generateSerializeContextCode {
# FIXME: chuangw: consider the case when the context object is not created.
    my $this = shift;
    my @condstr;
    for( @{ $this->contexts() } ){
        push @condstr, $this->locateSubcontexts( $_, 0, "this" );
    }
    my $findContextStr = qq@
    mace::Serializable* sobj;
    
    std::vector<std::string> snapshotContextIDs;
    boost::split(snapshotContextIDs, contextID, boost::is_any_of(";"), boost::token_compress_on);

    for( std::vector<std::string>::iterator ctxIt= snapshotContextIDs.begin(); ctxIt!= snapshotContextIDs.end(); ctxIt++){
        std::vector<std::string> ctxStrs;
        boost::split(ctxStrs, *ctxIt, boost::is_any_of(":]"), boost::token_compress_on);

        std::vector<std::string> ctxStr0;
        boost::split(ctxStr0, ctxStrs[0], boost::is_any_of("[,]") );
    @ . join("else ", @condstr) . 
    qq#
    }
    return sobj;
    #;

    return $findContextStr;
}

sub createSnapShotSyncHelper {
# chuangw: this subroutine creates snapshot_sync_fn()
    my $this = shift;

    my $returnType = Mace::Compiler::Type->new(type=>"mace::string",isConst=>0,isConst1=>0,isConst2=>0,isRef=>0);
    my @params;
    
    my $srcContextField = Mace::Compiler::Param->new(name=>"srcContextID", type=>$returnType);
    my $snapshotContextField = Mace::Compiler::Param->new(name=>"snapshotContextID",  type=>$returnType);
    my $snapshotField = Mace::Compiler::Param->new(name=>"contextSnapshot",  type=>$returnType);

    push @params,  $srcContextField;
    push @params,  $snapshotContextField;
		
    my $msgName = "__sync_at_snapshot"; 
		my $at = Mace::Compiler::AutoType->new(name=> $msgName, line=>__LINE__, filename => __FILE__, 
            method_type=>Mace::Compiler::AutoType::FLAG_SNAPSHOT, special_call=>"special");
    		
    foreach(@params) {
        my $p= ref_clone($_);
        if( defined $p->type ){
            $p->type->isConst(0);
            $p->type->isConst1(0);
            $p->type->isConst2(0);
            $p->type->isRef(0);
            $at->push_fields($p);
        }
    }
    $at->push_fields($snapshotField);

    my $msgSeqType = Mace::Compiler::Type->new(type=>"uint32_t",isConst=>0,isConst1=>0,isConst2=>0,isRef=>0);
    my $msgSeqField = Mace::Compiler::Param->new(name=>"seqno", type=>$msgSeqType);
    $at->push_fields($msgSeqField);
    $this->push_messages($at);

    my $helperBody;		
    my @paramArray;
    my $copyParam;
    for my $atparam ($at->fields()){
        given( $atparam->name ){
            when "seqno" { push @paramArray, "msgseqno"; }
            default { push @paramArray, $atparam->name; }
        }
    }
    $copyParam = join(",", @paramArray );
    $helperBody = qq#
    {
        mace::string ctxSnapshot;
        
        ScopedLock sl( mace::ContextBaseClass::__internal_ContextMutex );

        const MaceKey& destNode = ContextMapping::getNodeByContext(snapshotContextID);
        if(destNode == downcall_localAddress()){
            sl.unlock();
            ThreadStructure::pushContext(snapshotContextID);
            Serializable* sobj = findContextByID(snapshotContextID);
            mace::serialize( ctxSnapshot, sobj );
            ThreadStructure::popContext();
            return ctxSnapshot;
        }
        mace::string currentContextID = ThreadStructure::getCurrentContext();
        mace::string contextSnapshot;

        uint32_t msgseqno = getNextSeqno(snapshotContextID);
        __sync_at_snapshot pcopy($copyParam);
        /*mace::string buf;
        mace::serialize(buf,  &pcopy);
        __internal_unAck[snapshotContextID][msgseqno] = buf; //pcopy;*/

        sl.unlock();
        pthread_mutex_lock(&mace::ContextBaseClass::awaitingReturnMutex);
        pthread_cond_t contextCond;
        pthread_cond_init( &contextCond, NULL );
        awaitingReturnMapping[currentContextID] = &contextCond;

        downcall_route( destNode, pcopy );
        pthread_cond_wait(&contextCond, &mace::ContextBaseClass::awaitingReturnMutex);
        
        mace::map<mace::string,  mace::string>::iterator ctxSnapshot_iter = returnValueMapping.find(currentContextID);
        if(ctxSnapshot_iter == returnValueMapping.end()){
        }else{
            std::istringstream in(ctxSnapshot_iter->second);
            mace::deserialize(in,  &ctxSnapshot);
        }
        pthread_mutex_unlock( &mace::ContextBaseClass::awaitingReturnMutex );
        return ctxSnapshot;
    }
      #;

    my $methodName= "snapshot_sync_fn";
    my $snapshotMethod = Mace::Compiler::Method->new(name=>$methodName,  returnType=>$returnType, body=>$helperBody);
    $snapshotMethod->params(@params);

    $this->push_syncHelperMethods($snapshotMethod);
}


sub createRoutineTargetHelperMethod {
    my $this = shift;
    my $routine = shift;
    my $callType = "routine";


    my $this_subs_name = (caller(0))[3];
    my $helperBody = "// Generated by ${this_subs_name}() line: " . __LINE__;
    
    my $pname = $routine->name;
    my $name = $this->name();
 
    #my $uniqid = $transition->transitionNum;

    my $returnBody = "";
    my $returnType = $routine->returnType->type;
    my $initReturnValue = $this->createInitReturnValue($returnType);

    if($returnType ne 'void'){
            $returnBody = qq#
                    $initReturnValue
                    return returnValue;
            // Generated by ${this_subs_name}() line: # . __LINE__ . qq/
            /;
    }
    #$origmethod->body($returnBody);
   
    #bsang: we have already add origmethod into sync/async queues in createSync/createAsync methods. But if those
    #methods include snapshots,  we need to add new parameters of snapshot and add new methods into sync queue. 
    #If not,  it's the same as original method. In that case,  we shouldn't add them into sync queue.
    my $flag = 0;
    my $methods = $this->routines();
    foreach(@{ $methods }){
        if($_->name eq $routine->name){
            if(scalar(@{$_->params}) eq scalar(@{$routine->params})){
                $flag = 1;
                last;
            }
        }
    }

    if($flag == 0){
        $this->push_routineHelperMethods($routine);
    }

    # Generate auto-type for the method parameters.
    my $routineMessageName = "__target_${callType}_at_$pname";
    my $at = Mace::Compiler::AutoType->new(name=> $routineMessageName, line=>$routine->line(), filename => $routine->filename(), method_type=>Mace::Compiler::AutoType::FLAG_TARGET_SYNC, special_call=>"special");

    my @fnParams;
    for my $op ($routine->params()) {
        my $p= ref_clone($op);
        if( defined $p->type ){
            $p->type->isConst(0);
            $p->type->isConst1(0);
            $p->type->isConst2(0);
            $p->type->isRef(0);
            $at->push_fields($p);

            push @fnParams, $op->name;
        }
    }
    # bsang:
    # Add one extra field: 'context' of mace::string type
    # Add three params for this AutoType: source context id,  destination context id,  return value type of this synchronized call
    my $contextIDType = Mace::Compiler::Type->new(type=>"mace::string",isConst=>0,isConst1=>0,isConst2=>0,isRef=>0);
    my $ticketType = Mace::Compiler::Type->new(type=>"uint64_t",isConst=>0,isConst1=>0,isConst2=>0,isRef=>0);
    my $srcContextField = Mace::Compiler::Param->new(name=>"srcContextID", type=>$contextIDType);
   	my $startContextField = Mace::Compiler::Param->new(name=>"startContextID", type=>$contextIDType);
    my $targetContextField = Mace::Compiler::Param->new(name=>"targetContextID",  type=>$contextIDType);
    my $returnValueField = Mace::Compiler::Param->new(name=>"returnValue",  type=>$contextIDType);
    my $ticketField = Mace::Compiler::Param->new(name=>"ticket",  type=>$ticketType);
    $at->push_fields($srcContextField);
    $at->push_fields($startContextField);
    $at->push_fields($targetContextField);
    if($routine->returnType->type ne 'void'){
            $at->push_fields($returnValueField);
    }
    $at->push_fields($ticketField);

    # add one more extra field: message sequence number
    # to support automatic packet retransmission & state migration
    my $msgSeqType = Mace::Compiler::Type->new(type=>"uint32_t",isConst=>0,isConst1=>0,isConst2=>0,isRef=>0);
    my $msgSeqField = Mace::Compiler::Param->new(name=>"seqno", type=>$msgSeqType);
    $at->push_fields($msgSeqField);

    # demuxMethod() does not complain about undefined deliver() event handler
    #chuangw: instead of make it an auto_type, make it a message
    $this->push_messages($at);

    # Generate sync_ helper method to call synchronously.

    # chuangw: no need to clone $origmethod.... because $origmethod is already a copy of $transition->method
    my $helpermethod = ref_clone($routine);
    $helpermethod->name("target_${callType}_$pname");

    my $contextNameMapping = qq#mace::string contextID = mace::string("")#;
    $contextNameMapping .= join(qq# + "." #, map{" + " . $_} $routine->targetContextToString() );

    my $paramstring = join(", ", @fnParams);
    my $routine_upcall_func = "sync_${pname}";
    my $routineCall = $routine_upcall_func . "(" . $paramstring . ")";

    my $seg1 = "";
    my $seg2 = "";
    my $seg4 = "";

    my $return = "";
    if( $returnType eq "void" ){
        $seg1 = "";
        $seg2 = qq/
                ThreadStructure::pushContext(contextID);
                $routineCall ;
                ThreadStructure::popContext();
                return; /;
        $seg4 = qq/ /;
        $return = "return;";
    }else{
        $seg1 = $initReturnValue;
 
        $seg2 = qq/
                ThreadStructure::pushContext(contextID);
                returnValue = $routineCall ;
                ThreadStructure::popContext();
                return returnValue; /;
        $seg4 = qq/
                std::istringstream in(returnValue_iter->second);
                mace::deserialize(in,  &returnValue); /;
        $return = "return returnValue;";
    }
		
    my @copyParams;
    for my $atparam ($at->fields()){
        given( $atparam->name ){
            when "srcContextID"{ push @copyParams , "currentContextID"; }
            when "startContextID"{ push @copyParams , "currentContextID";	 }
            when "targetContextID"{ push @copyParams , "contextID"; }
            when "returnValue"{ push @copyParams , "returnValueStr"; }
            when "ticket" { push @copyParams , "ThreadStructure::myTicket()"; }
            when "seqno" { push @copyParams , "msgseqno"; }
            default  { push @copyParams , "$atparam->{name}"; }
        }
    }
    my $copyParam = join(", ", @copyParams);
    $helperBody .= qq#
    {
        $contextNameMapping;
        $seg1
        ScopedLock sl( mace::ContextBaseClass::__internal_ContextMutex );

        const MaceKey& destNode = ContextMapping::getNodeByContext(contextID);
        if(destNode == downcall_localAddress()){
                sl.unlock();
                $seg2
        }
        mace::string currentContextID = ThreadStructure::getCurrentContext();

        uint32_t msgseqno = getNextSeqno(contextID);
        mace::string returnValueStr;
        __target_${callType}_at_$pname pcopy($copyParam);
        /*mace::string buf;
        mace::serialize(buf,  &pcopy);
        __internal_unAck[contextID][msgseqno] = buf; //pcopy;*/

    
        sl.unlock();
        pthread_mutex_lock(&mace::ContextBaseClass::awaitingReturnMutex);
        pthread_cond_t contextCond;
        pthread_cond_init( &contextCond, NULL );
        awaitingReturnMapping[currentContextID] = &contextCond;

        downcall_route( destNode, pcopy );
        pthread_cond_wait(&contextCond, &mace::ContextBaseClass::awaitingReturnMutex);
        
        mace::map<mace::string,  mace::string>::iterator returnValue_iter = returnValueMapping.find(currentContextID);
        if(returnValue_iter == returnValueMapping.end()){
            ABORT("This shouldn't happen! Can't find return value");
        }else{
            $seg4
        }
        pthread_mutex_unlock( &mace::ContextBaseClass::awaitingReturnMutex );
        $return
      }
    #;
    $helpermethod->body($helperBody);
    # FIXME: chuangw: syncHelperMethods?? async calls?
    $this->push_routineHelperMethods($helpermethod);
}

sub createContextRoutineHelperMethod { #chuangw: modified from sync helper
    # FIXME: chuangw: this is not going to be very efficient....the hack should modify the original method instead of duplicating a new method. Creates sync_foo() method
    my $this = shift;

    my $routine = shift;
    #my $origmethod = shift;

    my $routineMessageNames = shift;

    my $at = shift;

    my $pname = $routine->name;
    my $name = $this->name();
    
    my $returnBody = "";
    my $returnType = $routine->returnType->type;
    my $initReturnValue = $this->createInitReturnValue($returnType);

    if($returnType ne 'void'){
        $returnBody = qq/
            $initReturnValue
            return returnValue;
        /;
    }
	# chuangw: TODO. body
    #$routine->body($returnBody);

    # Generate auto-type for the method parameters.
    #my $uniqid = $routine->routineNum;

    my $routineMessageName = "__routine_at_$pname";
    push( @{$routineMessageNames}, $routineMessageName );
    $at = Mace::Compiler::AutoType->new(name=> $routineMessageName, line=>$routine->line(), filename => $routine->filename(), method_type=>Mace::Compiler::AutoType::FLAG_SYNC, special_call=>"special");

    my @targetParams;
    for my $op ($routine->params()) {
        my $p= ref_clone($op);
        if( defined $p->type ){
            $p->type->isConst(0);
            $p->type->isConst1(0);
            $p->type->isConst2(0);
            $p->type->isRef(0);
            $at->push_fields($p);

            push @targetParams, $op->name;
        }
    }
    # bsang:
    # Add one extra field: 'context' of mace::string type
    # Add three params for this AutoType: source context id,  destination context id,  return value type of this synchronized call
    my $contextIDType = Mace::Compiler::Type->new(type=>"mace::string",isConst=>0,isConst1=>0,isConst2=>0,isRef=>0);
    my $ticketType = Mace::Compiler::Type->new(type=>"uint64_t",isConst=>0,isConst1=>0,isConst2=>0,isRef=>0);
    my $snapshotContextIDType = Mace::Compiler::Type->new(type=>"mace::vector<mace::string>",isConst=>0,isConst1=>0,isConst2=>0,isRef=>0);
    my $eventContextsType = Mace::Compiler::Type->new(type=>"mace::set<mace::string>",isConst=>1,isConst1=>0,isConst2=>0,isRef=>1);

    my $srcContextField = Mace::Compiler::Param->new(name=>"srcContextID", type=>$contextIDType);
    # chuangw 'startContextField' not needed
   	my $startContextField = Mace::Compiler::Param->new(name=>"startContextID", type=>$contextIDType);
    my $targetContextField = Mace::Compiler::Param->new(name=>"targetContextID", type=>$contextIDType);
    my $snapshotContextField = Mace::Compiler::Param->new(name=>"snapshotContextIDs", type=>$snapshotContextIDType);
    my $returnValueField = Mace::Compiler::Param->new(name=>"returnValue",  type=>$contextIDType);
    my $eventContextsField = Mace::Compiler::Param->new(name=>"eventContexts",  type=>$eventContextsType);

    # chuangw TODO: add a new field that updates the context of the events
    # chuangw TODO: add a new field that is a list of contexts the event owns.

    my $ticketField = Mace::Compiler::Param->new(name=>"ticket",  type=>$ticketType);
    
    $at->push_fields($srcContextField);
    $at->push_fields($startContextField);
    $at->push_fields($targetContextField);
    $at->push_fields($snapshotContextField);
    $at->push_fields($returnValueField);

    $at->push_fields($ticketField);
    # add one more extra field: message sequence number
    # to support automatic packet retransission & state migration
    my $msgSeqType = Mace::Compiler::Type->new(type=>"uint32_t",isConst=>0,isConst1=>0,isConst2=>0,isRef=>0);
    my $msgSeqField = Mace::Compiler::Param->new(name=>"seqno", type=>$msgSeqType);
    $at->push_fields($msgSeqField);

    # demuxMethod() does not complain about undefined deliver() event handler
    $this->push_messages($at);

    # Generate sync_ helper method to call synchronously.
    my $helpermethod = ref_clone($routine);
    $helpermethod->name("sync_$pname");

    my $srcContextNameMapping = "mace::string srcContextID = ThreadStructure::getCurrentContext()";
    my $targetContextNameMapping = qq#mace::string targetContextID = mace::string("")#;
    my $snapshotContextsNameMapping = qq#mace::vector<mace::string> snapshotContextIDs;\n#;

    $targetContextNameMapping .= join(qq# + "." #, map{" + " . $_} $routine->targetContextToString() );
    my @snapshotContextNameArray;

    $routine->snapshotContextToString( \@snapshotContextNameArray );


    my $nsnapshots = keys( %{$routine->snapshotContextObjects()});
    $snapshotContextsNameMapping .= join("\n", map{ qq#snapshotContextIDs.push_back($_);# }  @snapshotContextNameArray );


    my $routine_upcall_func = $routineMessageName;
    $routine_upcall_func =~ s/^__routine_at/__routine_fn/;
			
    my $helperbody;
    my $snapshotBody = "";

    my $count = 0;
    for($count = 0; $count< $nsnapshots; $count++){
        $snapshotBody .= qq/
                mace::string snapshot${count} = snapshot_sync_fn(currContextID, snapshotContextIDs[${count}]);
        /;
        push @targetParams, "snapshot".${count};
    }

    my $routineCall = "target_routine_" . $pname . "(" . join(", ", @targetParams) . ")";

    my $declareReturnValue = "";
    my $returnReturnValue = "";
    my $localAssignReturnValue = "";
    my $deserializeReturnValue = "";
    if($returnType eq 'void'){
        $returnReturnValue = "return;";
        $localAssignReturnValue = "$routineCall;";
    }else{
        $declareReturnValue = $initReturnValue; #" $returnType returnValue; ";
        $returnReturnValue = "return returnValue;";
        $localAssignReturnValue = "returnValue = $routineCall;";
        $deserializeReturnValue = "mace::deserialize(in,  &returnValue);";
    }

    my $copyParam;
    my @paramArray;
    for my $atparam ($at->fields()){
        given( $atparam->name ){
            when "srcContextID" { push @paramArray, "currContextID"; }
            when "eventContexts" { push @paramArray, "ThreadStructure::getEventContexts()"; }
            when "returnValue" { push @paramArray, "returnValueStr"; }
            when "ticket" { push @paramArray, "ThreadStructure::myTicket()"; }
            when "seqno" { push @paramArray, "msgseqno"; }
            default { push @paramArray, $atparam->name; }
        }
    }
    $copyParam = join(",", @paramArray);

    $helperbody = qq#
    {
        $declareReturnValue
        $srcContextNameMapping;
        $targetContextNameMapping;
        if( !ThreadStructure::isValidContextRequest( targetContextID ) ){
            // chuangw: TODO: if not valid request, throw an exception instead.
            $returnReturnValue
        }
        $snapshotContextsNameMapping;

        mace::vector<mace::string> allContextIDs = snapshotContextIDs;
        allContextIDs.push_back(targetContextID);
        //mace::string startContextID = ContextMapping::getStartContext(allContextIDs);
        mace::string startContextID = getStartContext(allContextIDs);

        mace::string currContextID = ThreadStructure::getCurrentContext();
        mace::string returnValueStr; // chuangw: XXX: not used 
        ScopedLock sl( mace::ContextBaseClass::__internal_ContextMutex );

        maceout<<"before addNewChild"<<Log::endl;
        macedbg(1)<<"before addNewChild"<<Log::endl;
        ThreadStructure::myContext()->addNewChild( startContextID, ThreadStructure::myTicket() );
        const MaceKey& destNode = ContextMapping::getNodeByContext(startContextID);
        // chuangw: The context is on the same physical node, so make a function call directly and return the value.
        if(destNode == downcall_localAddress()){
            sl.unlock();
            ThreadStructure::pushContext(currContextID);
            $snapshotBody
            $localAssignReturnValue;
            ThreadStructure::popContext();
            $returnReturnValue
        }

        uint32_t msgseqno = getNextSeqno(startContextID);
        __routine_at_$pname pcopy($copyParam);
        /*mace::string buf;
        mace::serialize(buf,  &pcopy);
        __internal_unAck[currContextID][msgseqno] = buf; //pcopy;*/


        sl.unlock();
        pthread_mutex_lock(&mace::ContextBaseClass::awaitingReturnMutex);
        pthread_cond_t contextCond;
        pthread_cond_init( &contextCond, NULL );
        awaitingReturnMapping[currContextID] = &contextCond;

        downcall_route( destNode, pcopy );
        pthread_cond_wait(&contextCond, &mace::ContextBaseClass::awaitingReturnMutex);

        mace::map<mace::string,  mace::string>::iterator returnValue_iter = returnValueMapping.find(currContextID);
        if(returnValue_iter == returnValueMapping.end()){
            ABORT("return value not found!!");
        }else{
            // chuangw: TODO: also returns the contexts released/cacquired during the sync call.
            std::istringstream in(returnValue_iter->second);
            $deserializeReturnValue
        }
        pthread_mutex_unlock( &mace::ContextBaseClass::awaitingReturnMutex );
        $returnReturnValue
    }
    #;
    $routine->body($helperbody);

    my $contextLock = "";
    my @currentContextVars = ();
    # chuangw: TODO: enable snapshot context alias...
    my $snapshotContexts = "";
    # chuangw: TODO: enable reading state var
    my $read_state_variable = "";

    if( @{ $this->contexts() } && $Mace::Compiler::Globals::useContextLock){
        $contextLock = $routine->getContextLock();
        $this->printTargetContextVar($routine, \@currentContextVars );
        $this->printSnapshotContextVar($routine, \@currentContextVars );
    }

    my $contextAlias = join("\n", @currentContextVars);
    my $realBody = qq#{
        
        $contextLock
        $read_state_variable
        $contextAlias
        $snapshotContexts

        $helpermethod->{body}

        
    }
    #;
    $helpermethod->body( $realBody );
    $this->push_routineHelperMethods($helpermethod);

    $routine->addSnapshotParams();
    #my $newMethod2 = ref_clone($routine );

    #$newMethod2->returnType($routine->returnType);

    $this->createRoutineTargetHelperMethod( $routine);
}

sub createUpcallHelperMethod {
#chuangw: This subroutine creates a new async call.
    my $this = shift;

    my $transition = shift;
    my $ref_uniqid = shift;

    my $p;
    my $message;
    my $param_counter = 0;
    for my $param ($transition->method->params()) {
        if( $param_counter == 2 ){
        #if ($param->flags("message")) {
            $p = $param;
            last;
        }
        $param_counter++;
    }
    if( not defined $p ){
        Mace::Compiler::Globals::error("bad_message", $transition->method->filename(), $transition->method->line(), "deliver upcall does not have a message field??");
        return;
    }
    for my $msg ($this->messages() ){
        if( $p->type->type() eq $msg->name()){
            $message = $msg;
            last;
        }
    }
    if( not defined $message ){
        Mace::Compiler::Globals::error("bad_message", $transition->method->filename(), $transition->method->line(), "deliver upcall used a message field that is not defined");
        return;
    }

    my $origBody = $transition->method->body();
    if( not defined $this->asyncExtraField() ){
        Mace::Compiler::Globals::error("bad_message", $transition->method->filename(), $transition->method->line(), "can't find the auto-generated autotype '__asyncExtraField'");
        return;
    }
    my $targetContextNameMapping = qq#mace::string targetContextID = mace::string("")#;
    my $snapshotContextsNameMapping = qq#mace::set<mace::string> snapshotContextIDs;\n#;

    $targetContextNameMapping .= join(qq# + "." #, map{" + " . $_} $transition->method->targetContextToString() );

    my @snapshotContextNameArray;

    $transition->method->snapshotContextToString( \@snapshotContextNameArray );

    $snapshotContextsNameMapping .= join("\n", map{ qq#snapshotContextIDs.insert($_);# }  @snapshotContextNameArray );
    my @extraParams;
    foreach( @{ $this->asyncExtraField()->fields() } ){
        given( $_->name ){
            when "ticket" { push @extraParams, "he.getEventID()"; }
            when "lastHop" { push @extraParams, "ContextMapping::getHeadContext()"; }
            when "nextHop" { push @extraParams, "globalContextID"; }
            when "seqno" { push @extraParams, "msgseqno"; }
            when /(targetContextID|snapshotContextIDs)/  { push @extraParams, $_->name; }
        }
    }
    my $uniqid = $$ref_uniqid++;
    my $msgname = $message->name;
    my $async_name = "upcall_deliver_$msgname";
    my $asyncMessageName = "__async_at${uniqid}_${async_name}";
    my @origParams;
    for my $param ($transition->method->params()) {
        push @origParams, $param->name;
    }
    push @origParams, "extra";
    my $createAsyncMessage = "
        __asyncExtraField extra(" . join(",", @extraParams) . ");
        $asyncMessageName pcopy( " . join(",", @origParams) ." );
    ";
    my $wrapperBody = qq#
    if( ContextMapping::getHead() != localAddress() ){
        mace::AgentLock::nullTicket();
        return;
    }

    mace::AgentLock lock( mace::AgentLock::WRITE_MODE );
    mace::HighLevelEvent he( mace::HighLevelEvent::UPCALLEVENT );
    mace::string buf;
    mace::serialize(buf,&$p->{name} );
    mace::HierarchicalContextLock hl( he, buf );
                    
    mace::string globalContextID("");
    $targetContextNameMapping;
    $snapshotContextsNameMapping;
    storeHeadLog(hl, he );

    uint32_t msgseqno = getNextSeqno(globalContextID);

    mace::AgentLock::downgrade( mace::AgentLock::NONE_MODE);

    $createAsyncMessage
    /*mace::string buf;
    mace::serialize(buf, &pcopy);
    __internal_unAck[ globalContextID ][ msgseqno ] = buf;*/
    downcall_route( ContextMapping::getNodeByContext( globalContextID ) , pcopy);
    #;
    $transition->method->body( $wrapperBody );
    ########## create async call
    my $g = Mace::Compiler::Guard->new( 
        file => __FILE__,
        guardStr => 'true',
        type => 'state_var',
        state_expr => Mace::Compiler::ParseTreeObject::StateExpression->new(type=>'null'),
        line => __LINE__
    );
    my $rtype = Mace::Compiler::Type->new();
    my $m = Mace::Compiler::Method->new(
        body => $origBody, 
        throw => $transition->method->throw,
        filename => $transition->method->filename,
        isConst => $transition->method->isConst,
        isUsedVariablesParsed => $transition->method->isUsedVariablesParsed,
        isStatic => $transition->method->isStatic,
        name => $async_name,  
        returnType => $transition->method->returnType,
        line => $transition->method->line, 
        targetContextObject => $transition->method->targetContextObject ,
        );
    for my $param ($transition->method->params()) {
        $m->push_params( $param );
    }

    my $t = Mace::Compiler::Transition->new(name => $m->name, 
        startFilePos => $transition->startFilePos, 
        columnStart => $transition->columnStart,
        type => "async", 
        method => $m,
        startFilePos => $transition->startFilePos,
        columnStart => $transition->columnStart,
        transitionNum => $uniqid
    );
    $t->options('originalTransition','upcall');
    $t->push_guards( $g );
    $this->push_transitions( $t);

}
sub createTimerHelperMethod {
    my $this = shift;
    my $transition = shift;
    my $ref_asyncMessageNames = shift;

    my $helperbody;
    my $pname = $transition->method->name;
    if ($transition->method->targetContextObject() eq '__internal'){
        
        my $helpermethod = ref_clone($transition->method);
        $helpermethod->name("scheduler_$pname");
        my $v = Mace::Compiler::Type->new('type'=>'void');
        $helpermethod->returnType($v);
        my @paramArray;
        for my $atparam ($transition->method->params()){
            push @paramArray, $atparam->name;
        }
        my $params = join(",", @paramArray);
        $helperbody = qq#
        expire_$pname($params);
        #;
        $helpermethod->body($helperbody);
        $this->push_timerHelperMethods($helpermethod);
        return;
    }

    my $name = $this->name();
    
    my $v = Mace::Compiler::Type->new('type'=>'void');
    my $origmethod = $transition->method();
    $origmethod->returnType($v);

    # Generate auto-type for the method parameters.
    my $uniqid = $transition->transitionNum;
    my $timerMessageName = "__async_at${uniqid}_$pname";
    my $at = Mace::Compiler::AutoType->new(name=> $timerMessageName, line=>$origmethod->line(), filename => $origmethod->filename(), method_type=>Mace::Compiler::AutoType::FLAG_ASYNC, special_call=>"special");
    push( @{$ref_asyncMessageNames}, $timerMessageName );
    for my $op ($origmethod->params()) {
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
    $this->push_messages($at);
#------------------------------------------------------------------------------------------------------------------
    # Generate timer_ helper method to call timerhronously.
    my $helpermethod = ref_clone($origmethod);
    $helpermethod->name("scheduler_$pname");
    #print $helpermethod->name() . "\n";
    my $paramstring = $origmethod->paramsToString(notype=>1,noline=>1);

    my $targetContextNameMapping = qq#mace::string targetContextID = mace::string("")#;
    my $snapshotContextsNameMapping = qq#mace::set<mace::string> snapshotContextIDs;\n#;

    $targetContextNameMapping .= join(qq# + "." #, map{" + " . $_} $transition->method->targetContextToString() );

    my @snapshotContextNameArray;

    $transition->method->snapshotContextToString( \@snapshotContextNameArray );

    $snapshotContextsNameMapping .= join("\n", map{ qq#snapshotContextIDs.insert($_);# }  @snapshotContextNameArray );

    my $this_subs_name = (caller(0))[3];
    my $helperBody = "// Generated by ${this_subs_name}() line: " . __LINE__;
    my @extraParams;

    my @copyParams;
    for ( $this->asyncExtraField()->fields() ){
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
    for my $atparam ($at->fields()){
        push @copyParams, "$atparam->{name}";
    }
    my $extraParam = "__asyncExtraField extra(" . join(", ", @extraParams) . ");";
    my $copyParam = join(", ", @copyParams);
    $helperbody = qq#{
        $targetContextNameMapping;
        $snapshotContextsNameMapping;
        mace::string currContextID = ThreadStructure::getCurrentContext();
        
        // send a message to head node
        ScopedLock sl(mace::ContextBaseClass::__internal_ContextMutex );
        const MaceKey& headNode = ContextMapping::getHead();
        uint32_t msgseqno = 1; //getNextSeqno(ContextMapping::getHeadContext());
        $extraParam
        $timerMessageName pcopy($copyParam );

        /*mace::string buf;
        mace::serialize(buf, &pcopy);
        __internal_unAck[ ContextMapping::getHeadContext() ][ msgseqno ] = buf;*/
        downcall_route(headNode,pcopy);
    }
    #;
    $helpermethod->body($helperbody);
    $this->push_timerHelperMethods($helpermethod);
    $transition->options('originalTransition','scheduler');
}
sub createAsyncHelperMethod {
#chuangw: This subroutine creates a message __async_at<transitionNum>_foo
    my $this = shift;

    my $transition = shift;
    my $atref = shift;
    my $origmethod = shift;
    my $asyncMessageNames = shift;

		
    my $pname = $transition->method->name;
    my $name = $this->name();
    
    my $v = Mace::Compiler::Type->new('type'=>'void');
    $origmethod->returnType($v);
    $origmethod->body("");

    # Generate auto-type for the method parameters.
    my $uniqid = $transition->transitionNum;
    my $asyncMessageName = "__async_at${uniqid}_$pname";
    $$atref = Mace::Compiler::AutoType->new(name=> $asyncMessageName, line=>$origmethod->line(), filename => $origmethod->filename(), method_type=>Mace::Compiler::AutoType::FLAG_ASYNC, special_call=>"special");
    my $at = $$atref;
    push( @{$asyncMessageNames}, $asyncMessageName );
    for my $op ($origmethod->params()) {
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
    $this->push_messages($at);
#------------------------------------------------------------------------------------------------------------------
    # Generate async_ helper method to call asynchronously.
    my $helpermethod = ref_clone($origmethod);
    $helpermethod->name("async_$pname");
    my $paramstring = $origmethod->paramsToString(notype=>1,noline=>1);

    my $targetContextNameMapping = qq#mace::string targetContextID = mace::string("")#;
    my $snapshotContextsNameMapping = qq#mace::set<mace::string> snapshotContextIDs;\n#;

    $targetContextNameMapping .= join(qq# + "." #, map{" + " . $_} $transition->method->targetContextToString() );

    my @snapshotContextNameArray;

    $transition->method->snapshotContextToString( \@snapshotContextNameArray );

    $snapshotContextsNameMapping .= join("\n", map{ qq#snapshotContextIDs.insert($_);# }  @snapshotContextNameArray );

    my $helperbody;
    my $this_subs_name = (caller(0))[3];
    my $helperBody = "// Generated by ${this_subs_name}() line: " . __LINE__;
    my @extraParams;

    my @copyParams;
    for ( $this->asyncExtraField()->fields() ){
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
    for my $atparam ($at->fields()){
        push @copyParams, "$atparam->{name}";
    }
    my $extraParam = "__asyncExtraField extra(" . join(", ", @extraParams) . ");";
    my $copyParam = join(", ", @copyParams);
    $helperbody = qq#{
        $targetContextNameMapping;
        $snapshotContextsNameMapping;
        mace::string currContextID = ThreadStructure::getCurrentContext();
        
        // send a message to head node
        ScopedLock sl(mace::ContextBaseClass::__internal_ContextMutex );
        const MaceKey& headNode = ContextMapping::getHead();
        uint32_t msgseqno = 1; //getNextSeqno(ContextMapping::getHeadContext());
        $extraParam
        __async_at${uniqid}_$pname pcopy($copyParam );

        /*mace::string buf;
        mace::serialize(buf, &pcopy);
        __internal_unAck[ ContextMapping::getHeadContext() ][ msgseqno ] = buf;*/
        downcall_route(headNode,pcopy);
    }
    #;
    $helpermethod->body($helperbody);
    $this->push_asyncHelperMethods($helpermethod);

    #$transition->addSnapshotParams();
    # chuangw: TODO: there's no need to create target helper methods for async calls....
    my $newMethod2 = ref_clone($transition->method);
    $newMethod2->returnType($origmethod->returnType);	
    $newMethod2->body("");
    $this->push_asyncMethods($newMethod2);
}


sub validate_findResenderTimer {
    my $this = shift;
    my $ref_asyncMessageNames = shift;
    my $ref_syncMessageNames = shift;

    # after getting async call generated message names, modify resender timer handler method body.
    my $resenderHandler;
    if( defined($transitionNameMap{ "resender_timer" }) &&  $transitionNameMap{ "resender_timer" }->type() eq "scheduler" ){
        $resenderHandler = $transitionNameMap{ "resender_timer" }->method;
    }
   
    if( defined $resenderHandler && ( scalar( @{ $ref_asyncMessageNames} )+scalar( @{ $ref_syncMessageNames} )) > 0 ){
        my $deserializeMessages = join("\n", map{"case " . $_ . "::messageType: msg = new " . $_ . "(); msg->deserializeStr( unAckPacket->second );break;" } @{ $ref_asyncMessageNames},@{ $ref_syncMessageNames} );
        my $resenderHandlerBody = qq#{
         mace::map<mace::string, mace::map<uint32_t, mace::string> >::iterator unAckPeers;
         // FIXME: resender should resend according to the sequence number...
         for(unAckPeers = __internal_unAck.begin(); unAckPeers != __internal_unAck.end(); unAckPeers++){
            for( mace::map<uint32_t, mace::string>::iterator unAckPacket= unAckPeers->second.begin(); unAckPacket != unAckPeers->second.end(); unAckPacket++ ){
                //std::cout<<"resending to "<< unAckPeers->first<< " , seqno="<< unAckPacket->first << std::endl;
                Message *msg;
                switch( Message::getType( unAckPacket->second ) ){
                    $deserializeMessages
                }
                downcall_route( ContextMapping::getNodeByContext(unAckPeers->first), *msg );
                delete msg;
            }
         }
        }#;
        $resenderHandler->body($resenderHandlerBody );
    }
}
sub validate_findDeliverUpcallMethods {
    my $this = shift;

    my $uniqid = @{ $this->transitions() };
    foreach my $transition ($this->transitions()) {
        # build the hash for name->transition mapping
        #$transitionNameMap{ $transition->name } = $transition;
        next if ($transition->type() ne 'upcall' or $transition->name() ne "deliver" );
        next if (defined $transition->method->targetContextObject and $transition->method->targetContextObject eq "__internal" );
        next if (defined $transition->method->targetContextObject and $transition->method->targetContextObject eq "__anon" );
        next if (defined $transition->method->targetContextObject and $transition->method->targetContextObject eq "__null" );

        my $origmethod;
        #unless(ref ($origmethod = Mace::Compiler::Method::containsTransition($transition->method, $this->asyncMethods()))) {
            my $pname = $transition->method->name;
            #$origmethod = ref_clone($transition->method());
            #$this->createUpcallHelperMethod( $transition,,  $origmethod  );
            $this->createUpcallHelperMethod( $transition, \$uniqid );
        #}
    }
}
sub createAsyncExtraField {
    my $this = shift;

    # create AutoType used by async calls. 
    for( $this->auto_types() ){
        if( $_->name() eq "__asyncExtraField" ){
          Mace::Compiler::Globals::error("reserved_autotypes", $_->filename() , $_->line(), "auto type '__asyncExtraField' is a reserved name.");
        }
    }

    my $asyncExtraField = Mace::Compiler::AutoType->new(name=> "__asyncExtraField", line=>__LINE__, filename => __FILE__);
    # bsang:
    # Add three extra fields: 'srcContextID', 'startContext' and 'targetContext' of mace::string type
    # it's used to store the context that the call takes place.
    my $contextIDType = Mace::Compiler::Type->new(type=>"mace::string",isConst=>0,isConst1=>0,isConst2=>0,isRef=>0);
    my $snapshotContextIDType = Mace::Compiler::Type->new(type=>"mace::set<mace::string>",isConst=>0,isConst1=>0,isConst2=>0,isRef=>0);
    my $ticketType = Mace::Compiler::Type->new(type=>"uint64_t",isConst=>0,isConst1=>0,isConst2=>0,isRef=>0);

    my $targetContextField = Mace::Compiler::Param->new(name=>"targetContextID",  type=>$contextIDType);
    my $snapshotContextsField = Mace::Compiler::Param->new(name=>"snapshotContextIDs",  type=>$snapshotContextIDType);
    my $ticketField = Mace::Compiler::Param->new(name=>"ticket",  type=>$ticketType);
    my $lastHopField = Mace::Compiler::Param->new(name=>"lastHop",  type=>$contextIDType); # chuangw: TODO: this is not needed ...
    my $nextHopField = Mace::Compiler::Param->new(name=>"nextHop",  type=>$contextIDType);

    # add one more extra field: message sequence number
    # to support automatic packet retransission & state migration
    my $msgSeqType = Mace::Compiler::Type->new(type=>"uint32_t",isConst=>0,isConst1=>0,isConst2=>0,isRef=>0);
    my $msgSeqField = Mace::Compiler::Param->new(name=>"seqno", type=>$msgSeqType); # chuangw: TODO: this is not needed....
    
    $asyncExtraField->push_fields($targetContextField);
    $asyncExtraField->push_fields($snapshotContextsField);
    $asyncExtraField->push_fields($ticketField);
    $asyncExtraField->push_fields($lastHopField);
    $asyncExtraField->push_fields($nextHopField);
    $asyncExtraField->push_fields($msgSeqField);

    # demuxMethod() does not complain about undefined deliver() event handler
    #chuangw: instead of make it an auto_type, make it a message
    
    $this->push_auto_types($asyncExtraField);
    $this->asyncExtraField( $asyncExtraField );
}
sub validate_findTimerTransitions {
    my $this = shift;
    my $ref_asyncMessageNames = shift;


    foreach my $transition ($this->transitions()) {

        #chuangw: the transition has a properties, context, which specifies
        #how to bind call parameter to the context
        next if ($transition->type() ne 'scheduler');

        # build the hash for name->transition mapping
        $transitionNameMap{ $transition->name } = $transition;

        $this->createTimerHelperMethod( $transition, $ref_asyncMessageNames );
    }
}
sub validate_findAsyncTransitions {
    my $this = shift;
    my $ref_asyncMessageNames = shift;


    foreach my $transition ($this->transitions()) {

        #chuangw: the transition has a properties, context, which specifies
        #how to bind call parameter to the context
        next if ($transition->type() ne 'async');

        # build the hash for name->transition mapping
        $transitionNameMap{ $transition->name } = $transition;

        my $origmethod;
        unless(ref ($origmethod = Mace::Compiler::Method::containsTransition($transition->method, $this->asyncMethods()))) {
            my $at;
            my $pname = $transition->method->name;
            $origmethod = ref_clone($transition->method());
            $this->createAsyncHelperMethod( $transition,\$at,  $origmethod, $ref_asyncMessageNames  );
        }
    }

}

sub validate_prepareSelectorTemplates {
    my $this = shift;
    my $name = $this->name();

    #Replace $service with the service name in parsed selector strings.
    while (my ($t,$selector) = each (%{$this->selectors()})) {
        $selector =~ s/\$service/$name/g;
        $this->selectors($t, $selector);
    }

    #If not set (should be the case!), provide default selectors.
    if (! exists($this->selectors->{'default'})) {
        $this->selectors('default', qq/"${name}::\$function::\$state"/);
    }
    ;
    if (! exists($this->selectors->{'message'})) {
        $this->selectors('message', qq/"${name}::\$function::\$message::\$state"/);
    }
    ;
}

sub validate_parseProvidedAPIs {
    my $this = shift;

    my @provides = Mace::Compiler::ClassCache::getServiceClasses($this->provides());

    #Parse code snips from .mh files.  ProvidesHash prevents double including.
    my %providesHash;
    my %providesNamesHash;
    for my $p (@provides) {
        if ($p->maceLiteral() and not $providesHash{$p->maceLiteral()}) {
            $providesHash{$p->maceLiteral()} = 1;
            $Mace::Compiler::Grammar::text = $p->maceLiteral();
            $this->parser()->Update($p->maceLiteral(), 0, "type" => "provides");
        }
        my $pn = $p->name();
        $pn =~ s/ServiceClass//;
        if ($pn ne "") {
            $providesNamesHash{$pn} = 1;
        }
    }

    my @providesNames = keys(%providesNamesHash);
    $this->provides(@providesNames);

    #Flatten methods.  Only include virtual methods and ignore if it's name is getLogType
    my @providesMethods = map {$_->isVirtual(0); $_} (grep {$_->isVirtual() && $_->name() ne "getLogType"} Mace::Compiler::ClassCache::unionMethods(@provides));
    for my $m (@providesMethods) {
	if ($m->name eq "hashState") {
	    $m->body(qq{{
		static hash_string hasher;
		std::string s = toString();  
		macedbg(0) << s << Log::endl;
		return hasher(s);
	    }});
	}
        elsif ($m->name eq "localAddress") {
            #$m->body($this->localAddress());
            $m->options('trace','off');
            $m->body("\n{ return __local_address; }\n");
        }
#        elsif ($m->name eq "registerInstance") {
#            $m->options('trace','off');
#            my $registerInstance = join("\n", map{ qq/mace::ServiceFactory<${_}ServiceClass>::registerInstance("$name", this);/ } $this->provides());
#            $m->body("\n{\n $registerInstance \n}\n");
#        }
    }

    #Two copies, one for remapped methods, one for the original (and external) API
    #Provided Methods are the API methods of service classes we provide.
    $this->providedMethods(@providesMethods);
    $this->providedMethodsAPI(@providesMethods);

    #providedHandlers is the list of handler classes of the service classes we provide
    my @providesHandlers = Mace::Compiler::ClassCache::getHandlers($this->provides());
    $this->providedHandlers(@providesHandlers);

    #providesHandlersMethods is the flattening of those methods
    my @providesHandlersMethods = Mace::Compiler::ClassCache::unionMethods(@providesHandlers);
    $this->providedHandlerMethods(@providesHandlersMethods);
}

sub validate_parseUsedAPIs {
    my $this = shift;

    my %svClassHash;
    my %svRegHash;
    my %usesHandlersMap = ();
    for my $sv ($this->service_variables()) {
        my $sc = $sv->serviceclass();
        unless($sv->intermediate()) {
            if ($sv->registration()) {
                $svRegHash{$sv->registration()}=1;
            }
            unless (defined($svClassHash{$sc})) {
                my @h = Mace::Compiler::ClassCache::getHandlers($sc);
                for my $h (@h) {
                    if ($sv->doRegister($h->name())) {
                        $usesHandlersMap{$h->name()} = $h;
                    }
                }
                $svClassHash{$sc}=1; # XXX: track handlers!
            }
        }
    }
    my @usesHandlers = values(%usesHandlersMap);
    $this->downcall_registrations(keys(%svRegHash));

    my @serviceVarClasses = keys(%svClassHash);

    my @uses = Mace::Compiler::ClassCache::getServiceClasses(@serviceVarClasses);
    my %usesHash;
    for my $u (@uses) {
        if ($u->maceLiteral() and not $usesHash{$u->maceLiteral()}) {
            $usesHash{$u->maceLiteral()} = 1;
            $Mace::Compiler::Grammar::text = $u->maceLiteral();
            $this->parser()->Update($u->maceLiteral(), 0, "type" => "services");
        }
    }

    $this->usesHandlers(map{$_->name} @usesHandlers);
    my @usesHandlersMethods = map {$_->isVirtual(0); $_} (grep {$_->isVirtual()} Mace::Compiler::ClassCache::unionMethods(@usesHandlers));
    $this->usesHandlerMethods(@usesHandlersMethods);
    $this->usesHandlerMethodsAPI(@usesHandlersMethods);

    my @usesMethods = grep(!($_->name =~ /^((un)?register.*Handler)|(mace(Init|Exit|Resume|Reset))|localAddress|hashState|registerInstance|getLogType$/), Mace::Compiler::ClassCache::unionMethods(@uses));
    $this->usesClassMethods(@usesMethods);

    for my $sv (@serviceVarClasses) {
        my @svc = Mace::Compiler::ClassCache::getServiceClasses($sv);
        my @svcm = Mace::Compiler::ClassCache::unionMethods(@svc);
        my @svcn = map { $_->name(); } @svc;
        $this->usesClasses_push($sv, @svcm);
        my @svch = Mace::Compiler::ClassCache::getHandlers($sv);
        my @svchn = map { $_->name() } @svch;
        $this->usesHandlerNames_push($sv, @svchn);
    }

}

#This portion handles the method remappings block by removing pristine methods from state,
#placing them in a remapping list, and replacing them with ones using remapped types

sub validate_genericMethodRemapping {
    my $this = shift;
    my $methodset = shift;
    my $methodapiset = shift;
    my $requireOPDefault = shift;
    my $allowRemapDefault = shift;
    my $pushOntoSerials = shift;
    my $includeMessageInSerial = shift;

    my $doGrep = 0;

    for my $method ($this->$methodset()) {
        #print "** " . $method->toString(noline=>1) . "\n";
        #print STDERR "DEBUG: ".$method->toString(nobody=>1,noline=>1)."\n";
        my $origmethod;
        unless(ref ($origmethod = Mace::Compiler::Method::containsTransition($method, $this->$methodapiset()))) {
            if($method->options("mhdefaults")) {
              $method->options("delete", 1);
              $doGrep = 1;
            }
            else {
              Mace::Compiler::Globals::error("bad_method_remap", $method->filename(), $method->line(), $origmethod);
            }
            next;
        }
        if (defined $method->options('trace')) {
            $origmethod->options('trace', $method->options('trace'));
        }
        $method->returnType($origmethod->returnType);
        $method->body($origmethod->body);
        $method->isConst($origmethod->isConst);
        my @op = $origmethod->params();
        my $n = 0;
        for my $p ($method->params()) {
            my $op = shift(@op);
            unless($p->hasDefault) {
                $p->hasDefault($op->hasDefault);
                $p->default($op->default);
            }
            if ($allowRemapDefault and $p->hasDefault()) {
                if ($requireOPDefault and not $op->hasDefault()) {
                    my $pstr = $p->toString(noline => 1);
                    my $ostr = $op->toString(noline => 1);
                    Mace::Compiler::Globals::error("bad_method_remap", $p->filename(), $p->line(), "Cannot assign new default to arg $n [$pstr] because API [$ostr] has no default (see Mace/Compiler/ServiceImpl.pm [1])");
                    #[1] : Because we allow and regularly use non-const items as defaults
                    #here, we do not allow you to define default values for parameters
                    #which do not have default values in the API.  The actual
                    #implementation looks to see if the API default parameter is
                    #supplied, and if so, the default specified here is evaluated.  A
                    #"smarter" compiler could "trust" that you know what you are doing,
                    #and if there is no default, just use the one you supply (which will
                    #work as long as its a constant expression).
                    $n++;
                    next;
                }
                if (!$op->hasDefault() || ($p->default ne $op->default) ) {
                    $origmethod->options('remapDefault', 1);
                    $op->flags('remapDefault', $p->default);
                    if ($method->serialRemap) {
                        $method->options('remapDefault', 1);
                        $p->flags('remapDefault', $p->default);
                        $p->default($op->default);
                    }
                }
            }
            if ($p->name =~ /noname_(\d+)/) {
                $p->name($op->name);
            }
            $n++;
        }
        $method->push_params(@op);
        if ($method->serialRemap) {
            my @m = (grep { $origmethod != $_ } @{$this->$methodapiset()});
            if(scalar(@m)) {
                $this->$methodapiset(@m);
            } else {
                my $fn = "clear_".$methodapiset;
                $this->$fn();
            }
            my @serialForms;
            if ($includeMessageInSerial) {
                @serialForms = $method->getSerialForms("Message", map{$_->name()} $this->messages());
            } else{
                @serialForms = $method->getSerialForms(map{$_->name()} $this->messages());
            }
=begin
            for my $sm (@serialForms) {
                print "serialForms: " . $sm->toString(noline=>1) . "\n";
            }
=cut
            map { $_->options('class', $origmethod->options('class')) } @serialForms;
            my $fn = "push_".$methodapiset;
            my $fnS = "push_".$methodapiset."Serials";
            $this->$fn(@serialForms);
            if ($pushOntoSerials) { $this->$fnS(@serialForms); }
        }
    }
    if($doGrep) {
      my @m = grep(!$_->options("delete"), @{$this->$methodset});
      if(scalar(@m)) {
        $this->$methodset(@m);
      } else {
        my $fn = "clear_".$methodset;
        $this->$fn();
      }
    }
=begin
    for my $omethod ($this->$methodapiset()) {
        print "after " . $omethod->toString(noline=>1) . "\n";
        print Dumper( $omethod->options );
    }

    for my $auto_types ( $this->auto_types() ){
        print "auto_types:" . $auto_types->toString() . "\n";
    }
    for my $messages ( $this->messages() ){
        print "messages:" . $messages->toString() . "\n";
    }
=cut
}

sub manageSelectorString {
    my $this = shift;
    my $method = shift;
    my $type = shift;
    my $count = shift;

    if (! defined $method) {
        die("Huh?");
    }

    my $selector;
    if ($method->options('message')) {
        $selector = $this->selectors('message');
        my $msg = $method->options('message');
        $selector =~ s/\$message/$msg/g;
    } else {
        $selector = $this->selectors('default');
    }
    my $fnName = $method->name();
    $selector =~ s/\$function/$fnName/;
    $selector =~ s/\$state/($type)/;
    my $selectorVar = "${fnName}_$type";
    if ($count >= 0) {
        $selectorVar .= "_$count";
    }
    $this->selectorVars($selectorVar,$selector);
    $method->options('selector', $selector);
    $method->options('selectorVar', $selectorVar);
}

#This method creates the selector strings for a set of methods of a given type.
#It specifically sets the selector option (the selector string) and the
#selectorVar option (the variable name for the selector variables.
sub validate_setupSelectorOptions {
    my $this = shift;
    my $type = shift;

    my @methods = @_;

    my $typecount = 0;
    for my $method (@methods) {
        $this->manageSelectorString($method, $type, $typecount);
        $typecount++;
    }

}

sub validate_setBinlogFlags {
    my $this = shift;
    my $method = shift;
    my $i = shift;
    my $prefix = shift;
    my $logThresh = shift;

    $method->options('binlogname', "$prefix".$method->name."$$i");
    $method->options('binlogshortname', $method->name);
    my $longName = $method->toString(nodefaults => 1, novirtual => 1, noreturn => 1, noline => 1);
    $longName =~ s/\n/ /g;
    $method->options('binloglongname', $longName);
    $$i++;

    $method->doStructuredLog($logThresh);
    return 1;
}

sub validate_setupRoutines {
    my $this = shift;
    my $i = shift;


    for my $routine ($this->routines()) {
        my $t = $routine->body();
        $this->matchStateChange(\$t);
        $routine->body($t);
        $routine->options('minLogLevel', 2);
        $this->validate_setBinlogFlags($routine, $i, "", $routine->getLogLevel($this->traceLevel()) > 1);
#        if ($transition->method->name() eq 'getLocalAddress' || $transition->method->name() eq 'localAddress') {
#            Mace::Compiler::Globals::error("bad_transition", $transition->method()->filename(), $transition->method->line(), "Mace now includes a local_address block in lieu of a transition.  You are no longer allowed to define a getLocalAddress transition.\n");
#        } else {
#            my $origmethod;
#            unless(ref ($origmethod = Mace::Compiler::Method::containsTransition($transition->method, $this->providedMethods()))) {
#               Mace::Compiler::Globals::error("bad_transition", $transition->method()->filename(), $transition->method->line(), $origmethod);
#               next;
#            }
#        }
    }
}

sub validate_processMatchedTransition {
    my $this = shift;
    my $transition = shift;
    my $filepos = shift;

    $transition->validate($this->selectors());
    $this->selectorVars($transition->getSelectorVar(), $transition->getSelector());

    if(defined($transition->startFilePos()) and $transition->startFilePos() >= 0) {
        $this->annotatedMacFile($this->annotatedMacFile() . substr($this->origMacFile(), $$filepos, $transition->startFilePos()-$$filepos) . "//" . $transition->toString(noline=>1) . "\n" . (" " x ($transition->columnStart()-1)));
        $$filepos = $transition->startFilePos();
    }

    my $t = $transition->method->body();
    $this->matchStateChange(\$t);
    $transition->method->body($t);

    if ($transition->isOnce()) {
        my $once = "once_".$transition->getTransitionMethodName();
        $this->push_state_variables(Mace::Compiler::Param->new(name => $once,
                    type => Mace::Compiler::Type->new(type => "bool"),
                    hasDefault => 1,
                    default => "false"));
        #$transition->unshift_guards(Mace::Compiler::Guard->new(guardStr => "(!$once)"));
        $transition->unshift_guards(Mace::Compiler::Guard->new(type => "expr", guardStr => "(!$once)"));
    }
    if ($transition->isRaw()) {
        if (defined($this->rawTransitions($transition->name()))) {
            Mace::Compiler::Globals::error("bad_transition", $transition->method()->filename(), $transition->method->line(), "Duplicate raw transition for " . $transition->name());
        }
        $this->rawTransitions($transition->name(), $transition);
    }
}

sub validate_fillTransition {
    my $this = shift;
    my $kind = shift;
    my $transition = shift;
    my $filepos = shift;
    my @methodset = @_;

    # Check for localAddress
    if ($transition->type() eq 'downcall') {
        if ($transition->method->name() eq 'getLocalAddress' || $transition->method->name() eq 'localAddress') {
            Mace::Compiler::Globals::error("bad_transition(".$kind.")", $transition->method()->filename(), $transition->method->line(), "Mace now includes a local_address block in lieu of a transition.  You are no longer allowed to define a getLocalAddress transition.\n");
            return;
        }
    }

    # Check for other errors
    my $origmethod;
    unless(ref ($origmethod = Mace::Compiler::Method::containsTransition($transition->method, @methodset))) {
        Mace::Compiler::Globals::error("bad_transition(".$kind.")", $transition->method()->filename(), $transition->method->line(), $origmethod);
        return;
    }
    $this->fillTransition($transition, $origmethod);
    $this->validate_processMatchedTransition($transition, $filepos);
}

sub validate_fillAspectTransition {
    my $this = shift;
    my $transition = shift;
    my $filepos = shift;

    my $origmethod;
    $transition->method->name('aspect_'.$transition->method->name());
    unless(scalar(@{$transition->options('monitor')}) == scalar(@{$transition->method->params()})) {
        Mace::Compiler::Globals::error("bad_transition", $transition->method()->filename(), $transition->method->line(), "aspect transition parameter mismatch -- same parameters as those to monitor (different number)"); #comparing aspect template count against function count
        return;
    }
    my $err = 0;
    my $pi = 0;
    my $mvars = $transition->options('monitor');
    my @mpars;
    for my $monitorVar (@$mvars) {
#Find state variable for each montiored name
        my $stateType = Mace::Compiler::Type->new(type=>"state_type");
        my $stateParam = Mace::Compiler::Param->new(name=>"state", type=>$stateType);
        my @svar = grep($monitorVar eq $_->name, @{$this->state_variables()}, $stateParam);
        my $fsvar = $svar[0];
        if(scalar(@svar) != 1) {
            Mace::Compiler::Globals::error("bad_transition", $transition->method()->filename(), $transition->method->line(), "aspect transition: variable $monitorVar cannot be found in state variables");
            $err = 1;
            last;
        } else {
#put state variable on the monitor/shadow list
            push(@mpars, $fsvar);
            my @shvar = grep("_MA_".$transition->method->name()."_".$monitorVar eq $_->name, @{$this->onChangeVars()});
            unless(scalar(@shvar)) {
                my $sv = ref_clone($fsvar);
                $sv->name("_MA_".$transition->method->name()."_".$sv->name());
                $sv->flags("originalVar", $fsvar);
                $this->push_onChangeVars($sv);
            }
        }
        if($err) { $err=0; next; }
#test found state variable against type from the method
        if($transition->method->params()->[$pi]->type()) {
            if($transition->method->params()->[$pi]->type->type ne $fsvar->type->type) {
                Mace::Compiler::Globals::error("bad_transition", $transition->method()->filename(), $transition->method->line(), "aspect transition: state variable $monitorVar has type ".$fsvar->type->type." and does not match parameter $pi: ".$transition->method->params()->[$pi]->toString());
                next;
            }
            if(!$transition->method->params()->[$pi]->type->isConst() or !$transition->method->params()->[$pi]->type->isRef()) {
                Mace::Compiler::Globals::error("bad_transition", $transition->method()->filename(), $transition->method->line(), "aspect transition parameters must be const and ref parameters (parameter $pi: ".$transition->method->params()->[$pi]->toString().")");
                next;
            }
        }
        $pi++;
    }

    if($transition->method->returnType->toString()) {
        unless($transition->method->returnType->type()->isVoid()) {
            my $rtype = $transition->method->returnType->type();
            Mace::Compiler::Globals::error("bad_transition", $transition->method()->filename(), $transition->method->line(), "aspect transitions must return 'void', return type: $rtype");
            next;
        }
    } else {
        $transition->method->returnType(Mace::Compiler::Type->new(type => "void"));
    }
    unless(ref ($origmethod = Mace::Compiler::Method::containsTransition($transition->method, $this->aspectMethods()))) {
#add transition.
        my @othermatches;
        if(scalar(@othermatches = grep($_->name eq $transition->method->name, $this->aspectMethods))) {
            Mace::Compiler::Globals::error("bad_transition", $transition->method()->filename(), $transition->method->line(), "aspect transition ".$transition->method->toString()." does not match other aspects with the same name.  Options are:\n".join("\n", @othermatches->toString()));
            next;
        }
        $origmethod = ref_clone($transition->method);
        $origmethod->options('monitor', $transition->options('monitor'));
        $origmethod->body("{ }\n");
        my $i = 0;
        for my $p ($origmethod->params()) {
            unless($p->type()) {
                $p->type(ref_clone($mpars[$i]->type()));
                $p->type->isConst(1);
                $p->type->isRef(1);
            }
            $i++;
        }

        $this->manageSelectorString($origmethod, "demux", -1);

#$a->body("{ return; }"); #XXX What goes here?
# XXX: This allows mutiple aspects of same name with different
# parameter lists to be created, and one of each will execute.
# If that's bad we need to do some extra checking.
        $this->push_aspectMethods($origmethod);
    }
    $this->fillTransition($transition, $origmethod);
    $this->validate_processMatchedTransition($transition, $filepos);
}

sub countDeferMatch {
    my $this = shift;
    my $name = shift;

    return scalar(grep($_ eq $name, $this->deferNames()));
}


sub fillTransition {
    my $this = shift;
    my $transition = shift;
    my $origmethod = shift;
    if ($transition->type() eq 'scheduler') {
        $transition->method->options('timer', $transition->method->name());
    }
    else {
        while (my ($k, $v) = each(%{$origmethod->options})) {
            $transition->method->options($k, $v);
        }
    }

    my $merge = $transition->getMergeType();
    my $lockingType = $transition->getLockingType();

    $transition->method->returnType($origmethod->returnType);
    $transition->method->isConst($origmethod->isConst);
    my $i = 0;
    for my $p ($transition->method->params()) {
      unless($p->type) {
        $p->type($origmethod->params()->[$i]->type());
      }
      $i++;
    }
    $origmethod->options($merge.'transitions', []) unless($origmethod->options($merge.'transitions'));

    push(@{$origmethod->options($merge.'transitions')}, $transition);
}

sub printStructuredLogs {
    my $this = shift;
    my $outfile = shift;
    my $name = $this->name();

    for my $slog ($this->structuredLogs()) {
        if ($slog->doStructuredLog()) {
            my $lname = $slog->name();
            print $outfile "mace::LogNode* ${lname}Dummy::rootLogNode = NULL;\n";
        }
        else {
            $slog->body("{ }\n");
        }
        my $func = $slog->toString(methodprefix => "${name}Service::", body => 1);
        print $outfile <<END;
        $func
END
    }
    for my $slog (grep(!($_->name =~ /^(un)?register.*Handler$/), $this->providedMethods()), @{$this->aspectMethods()}, @{$this->usesHandlerMethods()}, @{$this->timerMethods()}) {
#        if (not $slog->messageField() and $slog->getLogLevel($this->traceLevel()) > 0 and (defined $slog->options('transitions') or scalar(grep {$_ eq $slog->name} $this->ignores()))) {
        if ($slog->doStructuredLog()) {
#&& $slog->shouldLog()) {
            my $lname = (defined $slog->options('binlogname')) ? $slog->options('binlogname') : $slog->name();
            print $outfile "mace::LogNode* ${lname}Dummy::rootLogNode = NULL;\n";
        }
    }
    for my $slog (@{$this->usesClassMethods()}, @{$this->providedHandlerMethods()}) {
#        if (not $slog->messageField() and $slog->getLogLevel($this->traceLevel()) > 0) {
        if ($slog->doStructuredLog()) {
# && $slog->shouldLog()) {
            my $lname = (defined $slog->options('binlogname')) ? $slog->options('binlogname') : $slog->name();
            print $outfile "mace::LogNode* ${lname}Dummy::rootLogNode = NULL;\n";
        }
    }
    for my $slog ($this->routines()) {
#        if (not $slog->messageField() and $slog->getLogLevel($this->traceLevel()) > 1) {
        if ($slog->doStructuredLog()) {
# && $slog->shouldLog()) {
            my $lname = (defined $slog->options('binlogname')) ? $slog->options('binlogname') : $slog->name();
            print $outfile "mace::LogNode* ${lname}Dummy::rootLogNode = NULL;\n";
        }
    }
    for my $type ($this->auto_types()) {
        for my $m ($type->methods()) {
            if ($m->doStructuredLog()) {
                my $lname = $m->options('binlogname');
                print $outfile "mace::LogNode* ${lname}Dummy::rootLogNode = NULL;\n";
            }
        }
    }
}
sub printTargetContextVar {
    my $this = shift;
    my $method = shift;
    my $ref_vararray = shift;

    given( $method->targetContextObject() ){
        when /(__internal|__anon|__null)/ {}
        default {
            $this->printContextVar("target", $method, $method->targetContextObject(), "thisContext" , $ref_vararray );
        }
    }
    #if( $method->targetContextObject() eq "" || $method->targetContextObject() eq  "__internal" ){
    #    return;
    #}

}
sub printSnapshotContextVar {
    my $this = shift;
    my $method = shift;
    my $ref_vararray = shift;

    foreach my $ctx  ( keys %{ $method->snapshotContextObjects()} ) {
        $this->printContextVar("snapshot", $method,$ctx, ${ $method->snapshotContextObjects() }{$ctx} , $ref_vararray );
    }
}


sub printContextVar {
    my $this = shift;
    my $ctxtype = shift;
    my $method = shift;
    my $contextID = shift;
    my $alias = shift;
    my $ref_vararray = shift;

    # read $t->context.  find out context variables
    my @contextScope= split(/::/, $contextID );

    my $regexIdentifier = "[_a-zA-Z][_a-zA-Z0-9_.]*";

    my $currentContextName = "";
    my $contextString = "";

    my $currentContext;
    while( defined (my $contextID = shift @contextScope)  ){
        if ( $contextID =~ /($regexIdentifier)<($regexIdentifier)>/ ) {
            $contextString .= "$1\[$2\]";
            $currentContextName = $1;
        } elsif ($contextID =~ /($regexIdentifier)<([^>]+)>/) {
            my @contextParam = split("," , $2);

            $contextString .= "$1\[ __$1__Context__param( " . join(",", @contextParam) . " ) \]";
            $currentContextName = $1;
        }else{
            $contextString = "*(${contextString}${contextID})";
            $currentContextName = $contextID;
        }
        if( defined( $currentContext) ){
            for ($currentContext->subcontexts() ) {
                if( $_->name() eq $currentContextName ){
                    $currentContext = $_;
                    last;
                }
            }
        }else{
            for ($this->contexts() ) {
                if( $_->name() eq $currentContextName ){
                    $currentContext = $_;
                    last;
                }
            }
            if( not defined $currentContext ){
                Mace::Compiler::Globals::error("bad_context", $method->filename(), $method->line(), "Context '$currentContextName' not found.");
                return;
            }
        }
        if( scalar( @contextScope )>0 ){
=begin
            if( $ctxtype eq "target" ){
                push(@{ $ref_vararray}, "const __${currentContextName}__Context& __${currentContextName}_snapshot __attribute((unused))= $contextString.getSnapshot();");
                for my $var ($currentContext->ContextVariables()) {
                    my $t_name = $var->name();
                    my $t_type = $var->type()->toString(paramref => 1);

                    # Those are the variables to be read if the transition is READ transition.

                    if (!$method->isUsedVariablesParsed()) {
                      # If default parser is used since incontext parser failed, include every variable.
                      if( $Mace::Compiler::Globals::useSnapshot ) {
                        push(@{ $ref_vararray}, "const ${t_type} ${t_name} __attribute((unused)) = __${currentContextName}_snapshot.${t_name};");
                      }
                    } else { # If InContext parser is used, selectively include variable.
                      if(grep $_ eq $t_name, $method->usedStateVariables()) {
                        push(@{ $ref_vararray}, "const ${t_type} ${t_name} __attribute((unused)) = __${currentContextName}_snapshot.${t_name};");
                      } else {
                        push(@{ $ref_vararray}, "//const ${t_type} ${t_name} __attribute((unused)) = __${currentContextName}_snapshot.${t_name};");
                      }
                    }
                }
            }
=cut
            $contextString = $contextString . ".";
        }else{
            if( $ctxtype eq "snapshot" ){
                push(@{ $ref_vararray}, "const $currentContext->{className}& $alias __attribute((unused)) = $contextString.getSnapshot();");
            }elsif( $ctxtype eq "target" ){
                push(@{ $ref_vararray}, "$currentContext->{className}& $alias __attribute((unused)) = $contextString;");
                for my $var ($currentContext->ContextVariables()) {
                    my $t_name = $var->name();
                    my $t_type = $var->type()->toString(paramref => 1);

                    # Those are the variables to be read if the transition is READ transition.

                    if (!$method->isUsedVariablesParsed()) {
                      # If default parser is used since incontext parser failed, include every variable.
                      if( $Mace::Compiler::Globals::useSnapshot ) {
                        push(@{ $ref_vararray}, "${t_type} ${t_name} __attribute((unused)) = $alias.${t_name};");
                      }
                    } else { # If InContext parser is used, selectively include variable.
                      if(grep $_ eq $t_name, $method->usedStateVariables()) {
                        push(@{ $ref_vararray}, "${t_type} ${t_name} __attribute((unused)) = $alias.${t_name};");
                      } else {
                        push(@{ $ref_vararray}, "//${t_type} ${t_name} __attribute((unused)) = $alias.${t_name};");
                      }
                    }
                }
            }
        }
    }

}

sub printTransitions {
    my $this = shift;
    my $outfile = shift;

    my $name = $this->name();

    print $outfile "//BEGIN Mace::Compiler::ServiceImpl::printTransitions\n";

    my $lockType = "AgentLock";
    if( @{ $this->contexts() } && $Mace::Compiler::Globals::useContextLock){
        $lockType = "ContextLock";
    }
    for my $t ($this->transitions()) {
        $t->printGuardFunction($outfile, $this, "methodprefix" => "${name}Service::", "serviceLocking" => $this->locking());

        my @currentContextVars = ();

        $this->printTargetContextVar($t->method(), \@currentContextVars );
        $this->printSnapshotContextVar($t->method(), \@currentContextVars );

        $t->contextVariablesAlias(join("\n", @currentContextVars));


        #global state
        my @usedVar = array_unique($t->method()->usedStateVariables());

        my @declares = ();
# chuangw: temporarily, don't do global state snapshot.
=begin
        # chuangw: declare global context is read state
        if(  @{ $this->contexts() }   ) {
            push @declares, "mace::ContextBaseClass::globalContext.setCurrentMode(mace::ContextLock::READ_MODE);";
        }
        

        for my $var ($this->state_variables()) {
            my $t_name = $var->name();
            my $t_type = $var->type()->toString(paramref => 1);
            if( $t_name =~ m/^__internal_/ ){
                next;
            }

            # Those are the variables to be read if the transition is READ transition.

            if (!$t->method()->isUsedVariablesParsed()) {
              # If default parser is used since incontext parser failed, include every variable.
              if( $Mace::Compiler::Globals::useSnapshot ) {
                push(@declares, "const ${t_type} ${t_name} __attribute((unused)) = read_${t_name}();");
              }
            } else { # If InContext parser is used, selectively include variable.
              if(grep $_ eq $t_name, $t->method()->usedStateVariables()) {
                push(@declares, "const ${t_type} ${t_name} __attribute((unused)) = read_${t_name}();");
              } else {
                push(@declares, "// const ${t_type} ${t_name} = read_${t_name}();");
              }
            }
        }

        if (!$t->method()->isUsedVariablesParsed()) {
          # If default parser is used since incontext parser failed, include every variable.
          if( $Mace::Compiler::Globals::useSnapshot ) {
            push(@declares, "const state_type& state __attribute((unused)) = read_state();");
          }
        } else { # If InContext parser is used, selectively include variable.
          if(grep $_ eq "state", $t->method()->usedStateVariables()) {
            push(@declares, "const state_type& state __attribute((unused)) = read_state();");
          } else {
            push(@declares, "// const state_type& state = read_state();");
          }
        }
=cut

        push(@declares, "// isUsedVariablesParsed = ".$t->method()->isUsedVariablesParsed()."\n");
        push(@declares, "// used variables within transition = @usedVar\n");
        push(@declares, "// Refer to ServiceImpl.pm:printTransitions()\n");
        push(@declares, "__eventContextType = ".$this->locking().";\n");

        #print Dumper(@declares);

        $t->readStateVariable(join("\n", @declares));

        my $onChangeVarsRef = $this->onChangeVars();

        $t->printTransitionFunction($outfile, "methodprefix" => "${name}Service::", "onChangeVars" => $onChangeVarsRef, "serviceLocking" => $this->locking(), locktype => $lockType);
    }
    print $outfile "//END Mace::Compiler::ServiceImpl::printTransitions\n";
}


sub printMethodMapFile {
    my $this = shift;
    my $outFile = shift;
    my $slog = shift;
    my $isSlog = shift;

    if ($slog->doStructuredLog()) {
        if ($isSlog) {
            print $outFile "slog--";
        }
        print $outFile $slog->options('binloglongname')."--".$slog->options('binlogname')."--";
        if ($slog->logClause() ne "") {
            print $outFile $slog->logClause();
        }
        else {
            print $outFile $slog->shouldLog();
        }
        print $outFile "\n";
    }
}

sub printMethodMap {
    my $this = shift;
    my $outfile = shift;
    my $slog = shift;

    if ($slog->doStructuredLog()) {
        print $outfile "Log::binaryLog(mid, MethodMap_namespace::MethodMap(\"".$this->name()."_".$slog->options('binlogname')."\", \"".$slog->options('binloglongname')."\"), 0);\n";
    }
}

sub printRoutines {
    my $this = shift;
    my $outfile = shift;
    my $mmFileName = $this->name().".mm";
    my $methodMapFile;

    open($methodMapFile, ">", $mmFileName) or die;
    my $name = $this->name();

    print $outfile "//BEGIN Mace::Compiler::ServiceImpl::printRoutines\n";
    print $outfile join("\n", $this->generateAddDefer("", my $ref = $this->routineDeferMethods()));

    my $initSelectors = "";
    for my $sv (keys(%{$this->selectorVars()})) {
        $initSelectors .= qq/${name}Service::selectorId_${sv} = new LogIdSet(selector_${sv});
                         /;
    }

    print $outfile qq/
        static void initializeSelectors() {
          static bool _inited = false;
          if (!_inited) {
            log_id_t mid __attribute((unused)) = Log::getId("MethodMap");
            _inited = true;
            $initSelectors
            /;
            for my $slog (grep(!($_->name =~ /^(un)?register.*Handler$/), $this->providedMethods()), @{$this->aspectMethods()}, @{$this->usesHandlerMethods()}, @{$this->timerMethods()}) {
		$this->printMethodMap($outfile, $slog);
		$this->printMethodMapFile($methodMapFile, $slog, 0);
	    }
	    for my $slog (@{$this->usesClassMethods()}) {
		$this->printMethodMap($outfile, $slog);
		$this->printMethodMapFile($methodMapFile, $slog, 0);
	    }
	    for my $slog (@{$this->providedHandlerMethods()}) {
		$this->printMethodMap($outfile, $slog);
		$this->printMethodMapFile($methodMapFile, $slog, 0);
	    }
	    for my $r ($this->routines()) {
		$this->printMethodMap($outfile, $r);
		$this->printMethodMapFile($methodMapFile, $r, 0);
	    }
	    for my $slog ($this->structuredLogs()) {
		$this->printMethodMapFile($methodMapFile, $slog, 1);
	    }
	    for my $type ($this->auto_types()) {
		for my $m ($type->methods()) {
		    $this->printMethodMap($outfile, $m);
		    $this->printMethodMapFile($methodMapFile, $m, 0);
		}
	    }

    print $outfile qq/
          }
        }
    /;

    close $methodMapFile;

    my $lockType = "AgentLock";
    if( @{ $this->contexts() } && $Mace::Compiler::Globals::useContextLock){
        $lockType = "ContextLock";
    }
    my @routineMessageNames;
    for my $r ($this->routines()) {

        my $under = "";
        my $selectorVar = $r->options('selectorVar');
        my $shimroutine = "";
        my $routine = "";
        my $routineLogLevel = $r->getLogLevel($this->traceLevel());
        if ($r->returnType->type() ne "void" and $routineLogLevel > 1) {
          my $fnNameSquashed = $r->squashedName();
          my $paramlist = $r->paramsToString(notype=>1, nodefaults=>1);
          my $rt = $r->returnType->toString();

	      my $type = "\"rv_" . Mace::Util::typeToTable($rt) . "\"";
          $shimroutine = $r->toString("methodprefix" => "${name}Service::", nodefaults => 1, nostatic => 1,
                                      selectorVar => 1, traceLevel => $this->traceLevel, binarylog => 1, initsel => 1,
                                      usebody => qq/
                return mace::logVal(__mace_log_$fnNameSquashed($paramlist), selectorId->compiler, $type);
                    /);
          $under = "__mace_log_";
          $routine = $r->toString("methodprefix" => "${name}Service::${under}", nodefaults => 1, nostatic => 1, selectorVar => 1, nologs => 1, prepare => 1, body => 1, locktype => $lockType);
        }
        else {
          $routine = $r->toString("methodprefix" => "${name}Service::${under}", nodefaults => 1, nostatic => 1, selectorVar => 1, prepare => 1, traceLevel => $this->traceLevel, binarylog => 1, initsel => 1, body => 1, locktype => $lockType);
        }
	print $outfile <<END
            $shimroutine
	    $routine
END
    }
    print $outfile "//END Mace::Compiler::ServiceImpl::printRoutines\n";
} # printRoutines

sub snapshotSyncCallHandlerHack {
    my $this = shift;
    my $p = shift;
    my $message = shift;

    my $sync_upcall_func = "";
    my $sync_upcall_param = "";
    my $paramstring = "";
    my $name = $this->name();

    my $ptype = $p->type->type();
    $sync_upcall_func = $p->type->type();
		$sync_upcall_func =~ s/^__snapshot_sync_at/__snapshot_sync_fn/;
		
    $sync_upcall_param = $p->name();
    $paramstring = $p->type->type() . "(" . $sync_upcall_param . ")";


    my $chooseContextClass = qq#
    Serializable* sobj = findContextByID(snapshotContextID);
    mace::serialize( ctxSnapshot, sobj );
    #; 

    my $rcopyparam="";
		#bsang: copy returnValue Message

    my $apiBody = "";
    my @rmsgfields = $message->fields();
    my @rparams;
    while( @rmsgfields > 1 ){
        my $rparam = shift @rmsgfields;
        if($rparam->name eq "contextSnapshot"){
            push @rparams,  "ctxSnapshot";
        }else{
            push @rparams, ($sync_upcall_param . "." . $rparam->name );
        }
    }
    push @rparams, "msgseqno";

    $rcopyparam = "
        mace::string contextID = $sync_upcall_param.srcContextID;
        uint32_t msgseqno = getNextSeqno(contextID);
    ";
    $rcopyparam .= $p->type->type() . " pcopy(" . join(",", @rparams) . qq#);
        /*mace::string buf;
        mace::serialize(buf, &pcopy);
        __internal_unAck[ contextID ][ msgseqno ] = buf;*/
        // make a copy of the message similar to the original, except the seqno
    #;

    # assuming the first parameter of deliver() is 'src'
    $apiBody .= qq#
    ScopedLock sl( mace::ContextBaseClass::__internal_ContextMutex ); // protect internal structure
		const mace::string& srcContextID = $sync_upcall_param.srcContextID;
		const mace::string& snapshotContextID = $sync_upcall_param.snapshotContextID;
    if( $sync_upcall_param.seqno <= __internal_lastAckedSeqno[srcContextID] ){ 
        // send back the last acknowledge sequence number 
        downcall_route( source, __internal_Ack( __internal_lastAckedSeqno[srcContextID], srcContextID ) ); // always send ack even the pkt has been received
        sl.unlock(); 
    } else {
        // update received seqno queue & lastAckseqno
        __internal_receivedSeqno[srcContextID][ $sync_upcall_param.seqno ] = 1;
        uint32_t expectedSeqno = __internal_lastAckedSeqno[srcContextID]+1;
        while( expectedSeqno == __internal_receivedSeqno[ srcContextID ].begin()->first ){
            __internal_receivedSeqno[srcContextID].erase( __internal_receivedSeqno[srcContextID].begin() );
            __internal_lastAckedSeqno[srcContextID]++;
            expectedSeqno++;
        }

        downcall_route( source, __internal_Ack( __internal_lastAckedSeqno[srcContextID], srcContextID  ) ); // always send ack before processing message

        // update acknowledge sequence number
        // __internal_lastAckedSeqno[srcContextID] = $sync_upcall_param.seqno;
        if( ContextMapping::getNodeByContext($sync_upcall_param.snapshotContextID) == downcall_localAddress() ){
            // mace::serialize(returnValue,  &$sync_upcall_param.snapshotContextID);
            mace::string ctxSnapshot;
            $chooseContextClass
            $rcopyparam
            downcall_route( ContextMapping::getNodeByContext($sync_upcall_param.srcContextID),  pcopy);
        }else if( ContextMapping::getNodeByContext($sync_upcall_param.srcContextID) == downcall_localAddress() ){
            pthread_mutex_lock(&mace::ContextBaseClass::awaitingReturnMutex);
            std::map<mace::string,  pthread_cond_t*>::iterator cond_iter = awaitingReturnMapping.find($sync_upcall_param.srcContextID);
            if(cond_iter != awaitingReturnMapping.end()){
                    returnValueMapping[$sync_upcall_param.srcContextID] = $sync_upcall_param.contextSnapshot;
                    pthread_cond_signal( cond_iter->second );
            }
            pthread_mutex_unlock( &mace::ContextBaseClass::awaitingReturnMutex );
								
        }else{ // sanity check
            maceerr << "Message generated by sync call was sent to the invalid node" << Log::endl;
            maceerr << "I am not the destination node!" << Log::endl;
            ABORT("IMPOSSIBLE MESSAGE DESTINATION");
        }
    }
    #;
    return $apiBody;
}

sub targetRoutineCallHandlerHack {
# chuangw: this subroutine creates deliver( __target_(async|sync)_at?_foo ) 
    my $this = shift;
    my $p = shift;
    my $message = shift;

    my $paramstring = "";
    my $name = $this->name();

    my $ptype = $p->type->type();
    my $numberIdentifier = "[1-9][0-9]*";
    my $methodIdentifier = "[_a-zA-Z][_a-zA-Z0-9]*";
    my $pname;
    my $messageName = $message->name;
    if( $messageName =~ /__target_routine_at_($methodIdentifier)/ ){
            $pname = $1;
    }

    my $returnValueType;

    foreach(@{$this->routines() }){
        if($_->name eq $pname){
            $returnValueType = $_->returnType->type;
            last;
        }
    }
    if( not defined $returnValueType ){
        Mace::Compiler::Globals::error("bad_transition", __FILE__, __LINE__, "Could not find the routine corresponding to the message '$pname'");
        return;
    }

    my $sync_upcall_param = $p->name();
    $paramstring = $p->type->type() . "(" . $sync_upcall_param . ")";

    my $this_subs_name = (caller(0))[3];
    my $apiBody = "// Generated by ${this_subs_name}() line: " . __LINE__;

    my @msgfields = $message->fields();
    my @fnParams;

    foreach( @msgfields ){
        given( $_->name ){
            when (/^(srcContextID|startContextID|targetContextID|seqno|returnValue|ticket)$/) { }
            default { push @fnParams,  ($sync_upcall_param . "." . $_->name ); }
        }
    }
    my $fnParamsStr = join( ", ", @fnParams);
    my $seg1 = "";
    my $seg2 = "";

    if($returnValueType eq 'void'){
        $seg1 = qq/
            ThreadStructure::setTicket( $sync_upcall_param.ticket );
            sync_${pname}(${fnParamsStr}); 
        /; 

        $seg2 = "
            pthread_mutex_lock(&mace::ContextBaseClass::awaitingReturnMutex);
            std::map<mace::string,  pthread_cond_t*>::iterator cond_iter = awaitingReturnMapping.find($sync_upcall_param.srcContextID);
            if(cond_iter != awaitingReturnMapping.end()){
                    pthread_cond_signal( cond_iter->second) ;
            }
            pthread_mutex_unlock( &mace::ContextBaseClass::awaitingReturnMutex );
        ";
    }else{
        $seg1 = qq/
            mace::string returnValueStr;
            $returnValueType returnValue = sync_${pname} (${fnParamsStr});
            mace::serialize(returnValueStr, &returnValue);
        /;

        $seg2 = qq/
            pthread_mutex_lock(&mace::ContextBaseClass::awaitingReturnMutex);
            std::map<mace::string,  pthread_cond_t*>::iterator cond_iter = awaitingReturnMapping.find($sync_upcall_param.srcContextID);
            if(cond_iter != awaitingReturnMapping.end()){
                    returnValueMapping[$sync_upcall_param.srcContextID] = $sync_upcall_param.returnValue;
                    pthread_cond_signal( cond_iter->second );
            }
            pthread_mutex_unlock( &mace::ContextBaseClass::awaitingReturnMutex );
        /;
    }

    my $rcopyparam="";
    #bsang: copy returnValue Message
    my @rmsgfields = $message->fields();
    my @rparams;
    foreach( @rmsgfields ){
        given ($_->name){
            when "returnValue" { push @rparams, "returnValueStr"; }
            when "seqno" { push @rparams, "msgseqno"; }
            default { push @rparams, ($sync_upcall_param . "." . $_->name ); }
        }
    }
    $rcopyparam = qq#
        mace::string contextID = $sync_upcall_param.srcContextID;
        uint32_t msgseqno = getNextSeqno(contextID);
    # . $p->type->type() . " pcopy(" . join(",", @rparams) . ");
        // make a copy of the message similar to the original, except the seqno
        /*mace::string buf;
        mace::serialize(buf, &pcopy);
        __internal_unAck[ contextID ][ msgseqno ] = buf;*/
    ";


    # assuming the first parameter of deliver() is 'src'
    $apiBody .= qq#
    ScopedLock sl( mace::ContextBaseClass::__internal_ContextMutex ); // protect internal structure
		mace::string srcContextID = $sync_upcall_param.srcContextID;
    //std::cout<<"packet($ptype) from "<<source<<" has sequence number "<< $sync_upcall_param.seqno <<" received....lastAckedSeqno="<< __internal_lastAckedSeqno[source]<<std::endl;
    if( $sync_upcall_param.seqno <= __internal_lastAckedSeqno[srcContextID] ){ 
        // send back the last acknowledge sequence number 
        downcall_route( source, __internal_Ack( __internal_lastAckedSeqno[srcContextID], srcContextID ) ); // always send ack even the pkt has been received
        //std::cout<<"packet($ptype) from "<<source<<" has sequence number "<< $sync_upcall_param.seqno <<" was ignored, but acked."<<std::endl;
    } else {
        // update received seqno queue & lastAckseqno
        __internal_receivedSeqno[srcContextID][ $sync_upcall_param.seqno ] = 1;
        uint32_t expectedSeqno = __internal_lastAckedSeqno[srcContextID]+1;
        while( expectedSeqno == __internal_receivedSeqno[srcContextID].begin()->first ){
            __internal_receivedSeqno[srcContextID].erase( __internal_receivedSeqno[srcContextID].begin() );
            __internal_lastAckedSeqno[srcContextID]++;
            expectedSeqno++;
        }
        downcall_route( source, __internal_Ack( __internal_lastAckedSeqno[srcContextID], srcContextID  ) ); // always send ack before processing message
        //std::cout<<"packet($ptype) from "<<source<<" has sequence number "<< $sync_upcall_param.seqno <<" processed nominally"<<std::endl;
        if( ContextMapping::getNodeByContext($sync_upcall_param.targetContextID) == downcall_localAddress() ){
            sl.unlock();
            $seg1
            sl.lock();
            $rcopyparam // event has finished at the target context. Respond to start context.
            downcall_route( ContextMapping::getNodeByContext($sync_upcall_param.srcContextID),  pcopy);
        }else if( ContextMapping::getNodeByContext($sync_upcall_param.srcContextID) == downcall_localAddress() ){
            $seg2		
        }else{ // sanity check
            maceerr << "Message generated by sync call was sent to the invalid node" << Log::endl;
            maceerr << "I am not the destination node!" << Log::endl;
            ABORT("IMPOSSIBLE MESSAGE DESTINATION");
        }

        
    }
    #;
    return $apiBody;
}

sub routineCallHandlerHack {
    my $this = shift;
    my $p = shift;
    my $message = shift;
    my $returnValueType = shift;

    my $pname = "";
    my $sync_upcall_func = "";
    my $sync_upcall_param = "";
    my $paramstring = "";
    my $name = $this->name();

    my $ptype = $p->type->type();

    my $numberIdentifier = "[1-9][0-9]*";
    my $methodIdentifier = "[_a-zA-Z][_a-zA-Z0-9]*";

    my $messageName = $message->name;
    if( $messageName =~ /__routine_at_($methodIdentifier)/ ){
            $pname = $1;
    }
    $sync_upcall_func = "target_routine_" . $pname;

    $sync_upcall_param = $p->name();
    $paramstring = $p->type->type() . "(" . $sync_upcall_param . ")";

    my @msgfields = $message->fields();
    my @targetParams;

    foreach( @msgfields ){
        given( $_->name ){
            when (/^(srcContextID|startContextID|targetContextID|snapshotContextIDs|seqno|returnValue|ticket)$/) {}
            default { 
                    push @targetParams,  ($sync_upcall_param . "." . $_->name )
            }
        }
    }

    my $destContextNode = "ContextMapping::getNodeByContext( $sync_upcall_param.targetContextID )";
		#bsang: copy returnValue Message
    my @rmsgfields = $message->fields();
    my @rparams;
    while( @rmsgfields > 1 ){
        my $rparam = shift @rmsgfields;
        if($rparam->name eq "returnValue"){
            push @rparams,  "returnValueStr";
        }else{
            push @rparams, ($sync_upcall_param . "." . $rparam->name );
        }
    }
    push @rparams, "msgseqno";
=begin_obsoleted
    if(__internal_msgseqno.find($sync_upcall_param.srcContextID) == __internal_msgseqno.end() ){
        msgseqno = 1;
        __internal_msgseqno[$sync_upcall_param.srcContextID] = msgseqno;
    }else{
        msgseqno = ++__internal_msgseqno[$sync_upcall_param.srcContextID];
    }
=cut
    my $rparamstr = $p->type->type() . " pcopy(" . join(",", @rparams) . ");";
    my $rcopyparam = qq#
        uint32_t msgseqno = getNextSeqno( $sync_upcall_param.srcContextID) ;
        $rparamstr
        /*mace::string buf;
        mace::serialize(buf, &pcopy);
        __internal_unAck[ $sync_upcall_param.srcContextID ][ msgseqno ] = buf;*/
        // make a copy of the message similar to the original, except the seqno
    #;

    my $snapshotBody = "";
    #chuangw: find the corresponding routine
    my $method;
    for( $this->routines() ){
        if( $_->name eq $pname ){
            $method = $_;
        }
    }

    my $nsnapshots = keys( %{ $method->snapshotContextObjects()} );
    my $snapshotCounter;
    for($snapshotCounter=0;$snapshotCounter<$nsnapshots;$snapshotCounter++){
        $snapshotBody .= qq/
            mace::string snapshotContext${snapshotCounter} = snapshot_sync_fn(ThreadStructure::getCurrentContext(),  ${sync_upcall_param}.snapshotContextIDs[${snapshotCounter}]); /;
        push @targetParams,  "snapshotContext${snapshotCounter}";
    }
    my $targetParamsStr = join(", ", @targetParams);
    my $seg1 = "";
    my $seg2 = "";

    if($returnValueType eq 'void'){
        $seg1 = 
            qq/ mace::string returnValueStr;
                ${sync_upcall_func}(${targetParamsStr});
            /; 

        $seg2 = 
           "pthread_mutex_lock(&mace::ContextBaseClass::awaitingReturnMutex);
            std::map<mace::string,  pthread_cond_t*>::iterator cond_iter = awaitingReturnMapping.find($sync_upcall_param.srcContextID);
            if(cond_iter != awaitingReturnMapping.end()){
                pthread_cond_signal( cond_iter->second) ;
            }
            pthread_mutex_unlock( &mace::ContextBaseClass::awaitingReturnMutex ); ";
    }else{
        $seg1 = 
        qq/ mace::string returnValueStr;
            $returnValueType returnValue = ${sync_upcall_func} (${targetParamsStr});
            serialize(returnValueStr, &returnValue); /;

        $seg2 = 
        qq/ pthread_mutex_lock(&mace::ContextBaseClass::awaitingReturnMutex);
            std::map<mace::string,  pthread_cond_t*>::iterator cond_iter = awaitingReturnMapping.find($sync_upcall_param.srcContextID);
            if(cond_iter != awaitingReturnMapping.end()){
                returnValueMapping[$sync_upcall_param.srcContextID] = $sync_upcall_param.returnValue;
                pthread_cond_signal(  cond_iter->second ) ;
            }
            pthread_mutex_unlock( &mace::ContextBaseClass::awaitingReturnMutex ); /;
    }
    # assuming the first parameter of deliver() is 'src'
    my $apiBody = qq#
    mace::AgentLock::nullTicket();
    //if( !ackUpdateRespond(source, $sync_upcall_param.srcContextID, $sync_upcall_param.seqno) ) return;
    ScopedLock sl( mace::ContextBaseClass::__internal_ContextMutex ); // protect internal structure

    if( ContextMapping::getNodeByContext($sync_upcall_param.startContextID) == downcall_localAddress() ){
        sl.unlock();
        $snapshotBody
        $seg1
        sl.lock();
        $rcopyparam
        downcall_route( ContextMapping::getNodeByContext($sync_upcall_param.srcContextID),  pcopy);
    }else if( ContextMapping::getNodeByContext($sync_upcall_param.srcContextID) == downcall_localAddress() ){
        sl.unlock();
        $seg2		
    }else{ // sanity check
        maceerr << "Message generated by sync call was sent to the invalid node" << Log::endl;
        maceerr << "I am not the destination node!" << Log::endl;
        ABORT("IMPOSSIBLE MESSAGE DESTINATION");
    }
    #;
    return $apiBody;
}

sub asyncCallHandlerHack {
    my $this = shift;
    my $p = shift;
    my $message = shift;
	
    my $pname = "";
    my $async_upcall_func = "";
    my $async_upcall_param = "";
    my $async_head_eventhandler = "";
    my $paramstring = "";
    my $name = $this->name();
    my $ptype = $p->type->type();

    my $this_subs_name = (caller(0))[3];
    #bsang: extract this aync call's original name
    my $numberIdentifier = "[1-9][0-9]*";
    my $methodIdentifier = "[_a-zA-Z][_a-zA-Z0-9]*";

    my $messageName = $message->name();

    if($messageName =~ /__async_at($numberIdentifier)_($methodIdentifier)/){
        $pname = $2;
    }else{
        Mace::Compiler::Globals::error('async error', __FILE__,
				       __LINE__, "can't find the async transition using message name '$messageName'");
    }
    my $target_async_upcall_func = "target_async_" . $pname;

    $async_head_eventhandler = $ptype;
    $async_head_eventhandler =~ s/^__async_at/__async_head_fn/;

    $async_upcall_param = $p->name();
    $paramstring = "${ptype}(" . $async_upcall_param . ")";

    my @extraParams;
    if( not defined $this->asyncExtraField() ){
        Mace::Compiler::Globals::error("bad_message", __FILE__, __LINE__, "can't find the auto-generated autotype '__asyncExtraField'");
        return;
    }
    foreach( @{ $this->asyncExtraField()->fields() } ){
        given( $_->name ){
            when "ticket" { push @extraParams, "he.getEventID()"; }
            when "lastHop" { push @extraParams, "$async_upcall_param.extra.nextHop"; }
            when "nextHop" { push @extraParams, "globalContextID"; }
            when "seqno" { push @extraParams, "msgseqno"; }
            when /(targetContextID|snapshotContextIDs)/  { push @extraParams, "$async_upcall_param.extra." . $_->name; }
        }
    }
    my @origParams;
    for my $param ($message->fields()) {
        given( $param->name ){
            when "extra" { push @origParams, "extra"; }
            default { push @origParams, "$async_upcall_param." . $param->name; }
        }
    }
    my $extraField = "__asyncExtraField extra(" . join(",", @extraParams) . ");";
    my $headMessage = "$ptype pcopy(" . join(",", @origParams) . ");";
    my $nsnapshots = keys( %{ $transitionNameMap{ $pname }->getSnapshotContexts()} );
    my $snapshotCounter;

#--------------------------------------------------------------------------------------
    my @nextHopMsgParams;
    my @nextExtraParams;

    foreach( $message->fields() ){
        given( $_->name ){
            when "extra" { push @nextHopMsgParams, "nextextra"; }
            default { 
                    push @nextHopMsgParams,  "$async_upcall_param.$_->{name}";
            }
        }
    }
    foreach( @{ $this->asyncExtraField()->fields() } ){
        given( $_->name ){
            #when "ticket" { push @nextExtraParams, "he.getEventID()"; }
            when "lastHop" { push @nextExtraParams, "$async_upcall_param.extra.nextHop"; }
            when "nextHop" { push @nextExtraParams, "nextHop"; }
            when "seqno" { push @nextExtraParams, "msgseqno"; }
            when /(targetContextID|snapshotContextIDs|ticket)/  { push @nextExtraParams, "$async_upcall_param.extra.$_->{name}"; }
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
    if( defined $transitionNameMap{ $pname }->options('originalTransition') and $transitionNameMap{ $pname }->options('originalTransition') eq "scheduler" ){
        foreach( $message->fields() ){
            given( $_->name ){
                when "extra" {}
                default { push @asyncMethodParams, "const_cast<" . $_->type->type . "&>($async_upcall_param.$_->{name})";  }
            }
        }
        $startAsyncMethod = "expire_" . $pname . "(" . join(", ", @asyncMethodParams ) . ");";
        $eventType = "TIMEREVENT";
    }else{
        foreach( $message->fields() ){
            given( $_->name ){
                when "extra" {}
                default { push @asyncMethodParams,  "$async_upcall_param.$_->{name}"; }
            }
        }
        $startAsyncMethod = $pname . "(" . join(", ", @asyncMethodParams ) . ");";
        $eventType = "ASYNCEVENT";
    }

#--------------------------------------------------------------------------------------
    my $headWork = "";
    if( defined $transitionNameMap{ $pname }->options('originalTransition') and $transitionNameMap{ $pname }->options('originalTransition') eq "upcall" ){
        $headWork = qq#
    ASSERT( thisContextID != ContextMapping::getHeadContext() );
        #;
    }else{
        $headWork = qq#
    if( thisContextID == ContextMapping::getHeadContext() ){
        mace::AgentLock lock( mace::AgentLock::WRITE_MODE );

        mace::HighLevelEvent he( mace::HighLevelEvent::$eventType );
        mace::string buf;
        mace::serialize(buf,&$async_upcall_param);
        mace::HierarchicalContextLock hl( he, buf );
                        
        storeHeadLog(hl, he );

        // make a copy of the message similar to the original, except the seqno & ticket
        mace::string globalContextID("");
        uint32_t msgseqno = getNextSeqno(globalContextID);

        mace::AgentLock::downgrade( mace::AgentLock::NONE_MODE);

        $extraField
        $headMessage
        /*mace::string buf;
        mace::serialize(buf, &pcopy);
        __internal_unAck[ globalContextID ][ msgseqno ] = buf;*/
        downcall_route( ContextMapping::getNodeByContext( globalContextID ) , pcopy); // does it matter if messages are not sent in order?
        return;
    }
        #;
    }
#--------------------------------------------------------------------------------------
    my $apiBody = "// Generated by ${this_subs_name}() line: " . __LINE__;
    $apiBody .= qq#
    //if( ! ackUpdateRespond(source, $async_upcall_param.extra.lastHop, $async_upcall_param.extra.seqno) ) return;
    const mace::string& thisContextID = $async_upcall_param.extra.nextHop;
    $headWork
    bool isTarget = false;
    if( thisContextID == $async_upcall_param.extra.targetContextID ){
        isTarget = true;
    }
    const mace::set< mace::string >* subcontexts;
    // mkaing sure messages are coming in order...
    mace::ContextBaseClass *thisContext;

    asyncEventCheck(thisContext, subcontexts, $async_upcall_param.extra, isTarget );
    
    if( isTarget ){
        asyncPrep(thisContextID,   $async_upcall_param.extra.snapshotContextIDs, $async_upcall_param.extra.ticket, $nsnapshots);
        $startAsyncMethod 
        asyncFinish( thisContext, $async_upcall_param.extra.ticket,$async_upcall_param.extra.snapshotContextIDs );// after the prev. call finishes, do distribute-collect
    }else{ // not in target context
        if( thisContext->isLocalCommittable()  ){ // ignore DAG case.
            sendAsyncSnapshot( $async_upcall_param.extra, thisContextID, thisContext);
        }else{
            // increment number of received messages from parent contexts.
            ABORT("multiple parent contexts is not supported yet");
        }
    }
    if( thisContext->isLocalCommittable()  ){ // ignore DAG case.
        // chuangw: suggestion: versionize childContextID.
        for( mace::set<mace::string>::iterator subctxIter= subcontexts->begin(); subctxIter != subcontexts->end(); subctxIter++ ){
            // TODO: if child contexts are located on the same node, queue the message on the async event queue...
            const mace::string& nextHop  = *subctxIter; // prepare messages sent to the child contexts
            $prepareNextHopMessage
            mace::MaceKey nextHopNode = mace::ContextMapping::getNodeByContext( nextHop );
            downcall_route( nextHopNode, nextmsg);
            /*mace::string buf;
            mace::serialize(buf, &nextmsg);
            __internal_unAck[ nextHop ][ msgseqno ] = buf;*/
        }
    }else{
        // increment number of received messages from parent contexts.
        ABORT("multiple parent contexts is not supported yet");
    }
        #;
     return $apiBody;
=begin
            //AsyncDispatch::enqueueEvent(this, (AsyncDispatch::asyncfunc)&${name}_namespace::${name}Service::$async_head_eventhandler,(void*)new  $paramstring );
=cut
}
sub demuxDowncallContextHack {
#chuangw: hack downcall transition to support context'ed service composition
# In the original Mace, a downcall is simply a function call to the lower level service in the same physical node.
# However, when downcall transition supports full-contexts, the call may actually take place at other physical node.
# 
# The solution: 
#   When transition enters this service, start a new event as if it's a direct sync call.
    my $this = shift;
    my $m = shift;

    return "";
}

# chuangw: FIXME: demuxMethod() is crappy now. Need to reorganize the code
sub demuxMethod {
    my $this = shift;
    my $outfile = shift;
    my $m = shift;
    my $transitionType = shift;
    my $name = $this->name();

    my $locking = -1;
    if (defined ($m->options("transitions"))) {
        my $t = $this->checkTransitionLocking($m, "transitions");
        $locking = ($locking > $t ? $locking : $t);
    }
    if (defined ($m->options("pretransitions"))) {
        my $t = $this->checkTransitionLocking($m, "pretransitions");
        $locking = ($locking > $t ? $locking : $t);
    }
    if (defined ($m->options("posttransitions"))) {
        my $t = $this->checkTransitionLocking($m, "posttransitions");
        $locking = ($locking > $t ? $locking : $t);
    }

    if ( $m->name eq 'maceInit' ||
         $m->name eq 'maceResume' ||
         $m->name eq 'maceExit' ||
         $m->name eq 'hashState' ||
	 $m->name eq 'registerInstance' ||
         $m->name eq 'maceReset') {
        # Exclusive locking if the transition is of these types, regardless of any other specification.
        $locking = 1;
    }

    # Demux locking should borrow from its

    #print STDERR "[ServiceImpl.pm demuxMethod()]            " . $m->name . "  locking = " . $locking."\n";

    my $apiBody = "";
    my $apiTail = "";

    if( $transitionType eq 'downcall' and scalar( @{ $this->contexts() } ) > 0  ){
        # if this service is not a Transport service and this service is fullcontext
        my $isTransportService = 0;
        map{ if( $_ eq "Transport" ) { $isTransportService = 1; } } $this->provides();

        if( $isTransportService == 0 ){
            $apiBody .= $this->demuxDowncallContextHack($m);
        }
        # 
    } # downcall

    # chuangw: TODO: reschedule resender_timer
    if ($m->name eq 'maceInit' || $m->name eq 'maceResume' ) {
        my $initServiceVars = join("\n", map{my $n = $_->name(); qq/
            _$n.maceInit();
            if ($n == -1) {
                $n  = NumberGen::Instance(NumberGen::HANDLER_UID)->GetVal();
            }
                                             /;
                                         } grep(not($_->intermediate()), $this->service_variables()));

        my $initResenderTimer = "";
        if($Mace::Compiler::Globals::supportFailureRecovery && scalar( @{ $this->contexts() } )> 0 && $this->addFailureRecoveryHack() ) {
            $initResenderTimer = "//resender_timer.schedule(params::get<uint32_t>(\"FIRST_RESEND_TIME\", 1000*1000) );";
        }
        my $registerHandlers = "";
        for my $sv ($this->service_variables()) {
            my $svn = $sv->name();
            for my $h ($this->usesHandlerNames($sv->serviceclass)) {
                if ($sv->doRegister($h)) {
                    if ($m->getLogLevel($this->traceLevel()) > 0) {
                        $registerHandlers .= qq{macecompiler(0) << "Registering handler with regId " << $svn << " and type $h for service variable $svn" << Log::endl;
                                            };
                    }
                    $registerHandlers .= qq{_$svn.registerHandler(($h&)*this, $svn);
                                        };
                }
            }
        }
        $apiBody .= "
        if(__inited++ == 0) {
            //TODO: start utility timer as necessary
                $initServiceVars
                $initResenderTimer
                $registerHandlers
                ";
    } # maceInit & maceResume
    elsif ($m->name eq 'maceExit') {
        my $stopTimers = join("\n", map{my $t = $_->name(); "$t.cancel();"} $this->timers());
        my $exitServiceVars = join("\n", map{my $n = $_->name(); qq{_$n.maceExit();}} grep(not($_->intermediate()), $this->service_variables()));
        my $unregisterHandlers = "";
        for my $sv ($this->service_variables()) {
            my $svn = $sv->name();
            for my $h ($this->usesHandlerNames($sv->serviceclass)) {
                if ($sv->doRegister($h)) {
                    $unregisterHandlers .= qq{_$svn.unregisterHandler(($h&)*this, $svn);
                              };
                }
            }
        } # $this->service_variables()

        $apiBody .= "
        if(--__inited == 0) {
            ";
        $apiTail .= "
            //TODO: stop utility timer as necessary
            _actual_state = exited;
            $stopTimers
            $unregisterHandlers
            $exitServiceVars
                ";
    } # maceExit
    elsif ($m->name eq 'maceReset') {
        my $stopTimers = join("\n", map{my $t = $_->name(); "$t.cancel();"} $this->timers());
        my $resetServiceVars = join("\n", map{my $n = $_->name(); qq{_$n.maceReset();}} grep(not($_->intermediate()), $this->service_variables()));
        my $clearHandlers = "";
        for my $h ($this->providedHandlers()) {
            my $hname = $h->name();
            $clearHandlers .= "map_${hname}.clear();\n";
        }

        my $resetVars = "";
        for my $var ($this->state_variables(), $this->onChangeVars()) {
            if (!$var->flags("reset")) {
            next;
            }
            my $head = "";
            my $tail = "";
            my $init = $var->name();
            my $depth = 0;
            for my $size ($var->arraySizes()) {
            $head .= "for(int i$depth = 0; i$depth < $size; i$depth++) {\n";
            $init .= "[i$depth]";
            $tail .= "}\n";
            }
            $init .= " = " . $var->getDefault() . ";\n";
            $resetVars .= "$head $init $tail";
        }

        $apiTail .= "
        //TODO: stop utility timer as necessary
            _actual_state = init;
            $stopTimers
            $clearHandlers
            $resetServiceVars
            $resetVars
            __inited = 0;
            ";

    } # maceReset

    if (defined($m->options("pretransitions")) || defined($m->options("posttransitions"))) {
	$apiBody .= "Merge_" . $m->options("selectorVar") . " __merge(" .
	    join(", ", ("this", map{$_->name()} $m->params())) . ");\n";
    }

    if (  $m->name() =~ m/^(maceInit|maceExit)$/ ) { 
        # FIXME: this hack should only be applied when the service supports context.
        if($Mace::Compiler::Globals::supportFailureRecovery && scalar( @{ $this->contexts() } )> 0 && $this->addFailureRecoveryHack() ) {
            $apiBody .= qq#if( mace::ContextMapping::getNodeByContext("") == localAddress() ){
            #;
        }
    }
    if (defined $m->options('transitions')) {
        #print Dumper($m->options('transitions'));
        $apiBody .= qq/ if(state == exited) {
            ${\$m->body()}
        } else
            /;
        $apiBody .= $this->checkGuardFireTransition($m, "transitions", "else");

        #TODO: Fell Through No Processing
    } elsif (!scalar(grep {$_ eq $m->name} $this->ignores() )) {
	# $Mace::Compiler::Globals::filename = $this->filename();
        my $tname = $m->name;
        if($transitionType eq "scheduler") {
          $tname = substr($tname, 7);
        }
        my @messages = ();
        for my $p ($m->params()) {
            if ($p->flags("message")) {
            push(@messages, $p->type()->type());
            }
        }
        if (scalar(@messages)) {
            $tname .= "(" . join(",", @messages) . ")";
        }

        Mace::Compiler::Globals::warning('undefined', $this->transitionEndFile(), $this->transitionEnd(), "Transition $transitionType ".$tname." not defined!", $this->transitionEndFile());
            $this->annotatedMacFile($this->annotatedMacFile . "\n//$transitionType ".$m->toString(noline=>1, nodefaults=>1, methodname=>$tname)." {\n//ABORT(\"Not Implemented\");\n// }\n");
        my $mn = $m->name;
        if ($m->getLogLevel($this->traceLevel()) > 0) {
            $apiBody .= qq{macecompiler(1) << "COMPILER RUNTIME NOTICE: $mn called, but not implemented" << Log::endl;\n};
        }
    }
    my $resched = "";

    if ($m->options('timer')) {
        my $timer = $m->options('timer');
        #TODO Pip Stuff
        if ($m->options('timerRecur')) {
            my $recur = $m->options('timerRecur');
            my $pstring = join("", map{", ".$_->name} $m->params());
            $resched .= qq~ $timer.reschedule($recur$pstring);
                  ~;
        }
    }
    $apiBody .= "{\n";
    if ($m->getLogLevel($this->traceLevel()) > 0 and !scalar(grep {$_ eq $m->name} $this->ignores() )) {
        $apiBody .= qq{macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;\n};
    }
    $apiBody .= $resched .  $m->body() . "\n}\n";
    if (  $m->name() =~ m/^(maceInit|maceExit)$/ ) { 
        if($Mace::Compiler::Globals::supportFailureRecovery && scalar( @{ $this->contexts() } )> 0 && $this->addFailureRecoveryHack() ) {
            $apiBody .= qq@
            }
            @; #if( mace::ContextMapping::getNodeByContext("") == localAddress() )
        }
    }
    $apiBody .= $apiTail;
    if ($m->name eq 'maceInit' || $m->name eq 'maceExit'|| $m->name eq 'maceResume') {
	$apiBody .= "\n}\n";
    }

    my $lockType = "AgentLock";
    if( @{ $this->contexts() } && $Mace::Compiler::Globals::useContextLock){
        $lockType = "ContextLock";
    }

    print $outfile $m->toString(methodprefix => "${name}Service::", nodefaults => 1, prepare => 1,
                               selectorVar => 1, traceLevel => $this->traceLevel(), binarylog => 1,
                               locking => $locking, fingerprint => 1, usebody=>$apiBody,
                               locktype => $lockType
                               );

    for my $el ("pre", "post") {
        if ($m->options($el . "transitions")) {
            print $outfile $m->toString("methodprefix" => "${name}Service::_${el}_", "nodefaults" => 1,
                                 "usebody" => $this->checkGuardFireTransition($m, "${el}transitions"),
                                 selectorVar => 1, nologs => 1
                                 );
            #$m->toString(methodprefix => "${name}Service::_${el}_", nodefaults => 1
            #                           );
        }
    }

}

sub mergeClasses {
    my $this = shift;
    my @r = ();
    for my $m ($this->providedMethods(), $this->usesHandlerMethods(), $this->timerMethods()) {
	if ($m->options("pretransitions") or $m->options("posttransitions")) {
	    my $name = "Merge_" . $m->options("selectorVar");
	    push(@r, $name);
	}
    }
    return @r;
}

sub generateMergeClasses {
    my $this = shift;
    my $c = "//BEGIN Mace::Compiler::ServiceImpl::generateMergeClasses\n";
    for my $m ($this->providedMethods(), $this->usesHandlerMethods(), $this->timerMethods()) {
	if ($m->options("pretransitions") or $m->options("posttransitions")) {
            my $svName = $this->name();
	    my $name = "Merge_" . $m->options("selectorVar");
	    $c .= "class ${svName}Service::$name {\n";
	    $c .= "private:\n";
	    $c .= $this->name() . "Service* sv;\n";
	    $c .= join("\n", map {$_->toString(nodefaults=>1) . ";"} $m->params()) . "\n";
	    $c .= "public:\n";
	    $c .= "$name(" . join(", ", ($this->name() . "Service* sv", map{$_->toString} $m->params())) . ") : ";
	    $c .= join(", ", ("sv(sv)", map{$_->name . "(" . $_->name . ")"} $m->params())) . " {\n";
	    if ($m->options("pretransitions")) {
		$c .= "sv->_pre_" . $m->name() . "(" . join(",", map{$_->name()} $m->params()) . ");\n";
	    }
	    $c .= "}\n";
	    $c .= "virtual ~$name() {\n";
	    if ($m->options("posttransitions")) {
		$c .= "sv->_post_" . $m->name() . "(" . join(",", map{$_->name()} $m->params()) . ");\n";
	    }
	    $c .= "}\n";
	    $c .= "}; // class $name\n\n";
	}
    }
    $c .= "//END Mace::Compiler::ServiceImpl::generateMergeClasses\n";
    return $c;
}

sub declareMergeMethods {
    my $this = shift;
    my $r = "";
    for my $m ($this->providedMethods(), $this->usesHandlerMethods(), $this->timerMethods()) {
	for my $el ("pre", "post") {
	    if ($m->options("${el}transitions")) {
		$r .= $m->toString("methodprefix" => "_${el}_", "nodefaults" => 1) . ";\n";
	    }
	}
    }
    return $r;
}

sub checkGuardFireTransition {

    my $this = shift;
    my $m = shift;
    my $key = shift;
    my $else = shift || "";

    my $r = "";
    #print $m->name() . "==>" . $m->optionsToString() . "\n";
    map {
        #print Dumper( $_ );
	my $guardCheck = $_->getGuardMethodName()."(".join(",", map{$_->name} $m->matchedParams($_->method)).")";
	my $transitionCall = $_->getTransitionMethodName()."(".join(",", map{$_->name} $m->matchedParams($_->method)).")";
	my $setOnce = "";
	if ($_->isOnce()) {
	    $setOnce = "once_".$_->getTransitionMethodName()." = true;";
	}
	my $return = '';
	my $returnend = '';
	if (!$m->returnType->isVoid()) {
            if($_->method()->getLogLevel($this->traceLevel) > 1) {
		my $rt = $m->returnType->toString();
		my $type = "\"rv_" . Mace::Util::typeToTable($rt) . "\"";
		#$return = "$rt __ret =";
		#$returnend = ";\nLog::binaryLog(selectorId->compiler, mace::SimpleLogObject<" . $rt . " >(" . $type . ", __ret));\nreturn __ret;\n";
                $return = 'return mace::logVal(';
                $returnend = ", selectorId->compiler, $type)";
            }
            else {
              $return = 'return';
            }
	}
        my $called = "";
        if ($_->method()->getLogLevel($this->traceLevel) > 1) {
            $called = qq/macecompiler(1) << "Firing Transition ${\$_->toString()}" << Log::endl;\n/;
        }

	my $resched = "";
	if ($m->options('timer')) {
	    my $timer = $m->options('timer');
	    #TODO Pip Stuff
	    if ($m->options('timerRecur')) {
		my $recur = $m->options('timerRecur');
		my $pstring = join("", map{", ".$_->name} $m->params());
		$resched = qq{$timer.reschedule($recur$pstring);
			   };
	    }
	}

	$r .= qq/ if($guardCheck) {
                $called
		$setOnce
		    $resched
		    $return $transitionCall$returnend;
	    } $else
	    /;
    } @{$m->options($key)};

    return $r;

}

# Needs to start by assuming service specified locking (default on).
#
# Locking options: exclusive, shared, none
# Concern: what if not all transitions of the same type specify the same kind of locking.
#
# ANS: Need to grab the highest lock level of any transition.
#
# Plan for execution: Can go from none to any type, and a higher type to a lower type, but not v/v.
#
# Yoo : Now it takes service-wide global locking type over no-locking specified transition.
#       Since demux function takes service-wide global locking, it causes error.
#       Please check with the previous version.

sub checkTransitionLocking {
    my $this = shift;
    my $m = shift;
    my $key = shift;
    my $else = shift || "";

    my $r = -1;
    map {
        $r = ($r >= $_->getLockingType($this->locking())) ? $r : $_->getLockingType($this->locking());
        #print STDERR "[ServiceImpl.pm checkTransitionLocking()] ".$_->name()."  locking = ".$r."\n";
    } @{$m->options($key)};

    return $r;
}

sub printAPIDemux {
    my $this = shift;
    my $outfile = shift;

    my $name = $this->name();

    print $outfile "//BEGIN Mace::Compiler::ServiceImpl::printAPIDemux\n";
    for my $m (grep(!($_->name =~ /^(un)?register.*Handler$/), $this->providedMethods())) {

        $this->demuxMethod($outfile, $m, "downcall");

    }
    print $outfile "//END Mace::Compiler::ServiceImpl::printAPIDemux\n";
}

sub printAsyncDemux {
    my $this = shift;
    my $outfile = shift;

    my $name = $this->name();

    print $outfile "//BEGIN Mace::Compiler::ServiceImpl::printAsyncDemux\n";
    for my $m ($this->asyncMethods()) {

        $this->demuxMethod($outfile, $m, "async");

    }
    print $outfile "//END Mace::Compiler::ServiceImpl::printAsyncDemux\n";
}

sub printSyncDemux {
		my $this = shift;
		my $outfile = shift;
		my $name = $this->name();

		print $outfile "//BEGIN Mace::Compiler::ServiceImpl::printSyncDemux\n";
		for my $m ($this->syncMethods()) {
				$this->demuxMethod($outfile,  $m,  "sync");
		}
		print $outfile "//END Mace::Compiler::ServiceImpl::printSyncDemux\n";

}

sub printAspectDemux {
    my $this = shift;
    my $outfile = shift;

    my $name = $this->name();

    print $outfile "//BEGIN Mace::Compiler::ServiceImpl::printAspectDemux\n";
    for my $m ($this->aspectMethods()) {
        $this->demuxMethod($outfile, $m, "aspect");
    }
    print $outfile "//END Mace::Compiler::ServiceImpl::printAspectDemux\n";
}

sub printHandlerRegistrations {
    my $this = shift;
    my $outfile = shift;

    my $name = $this->name();

    print $outfile "//BEGIN Mace::Compiler::ServiceImpl::printHandlerRegistrations\n";
    my $isUniqueReg = ($this->registration() eq "unique");

    for my $h ($this->providedHandlers()) {
        my $hname = $h->name();

	my $assertUnique = "";
	if ($isUniqueReg) {
	    $assertUnique = "ASSERT(map_${hname}.empty());";
	}

	print $outfile <<END;
	registration_uid_t ${name}Service::registerHandler(${hname}& handler, registration_uid_t regId) {
	    if(regId == -1) { regId = NumberGen::Instance(NumberGen::HANDLER_UID)->GetVal(); }
	    $assertUnique
            ASSERT(map_${hname}.find(regId) == map_${hname}.end());
	    map_${hname}[regId] = &handler;
	    return regId;
	}

	void ${name}Service::registerUniqueHandler(${hname}& handler) {
	    ASSERT(map_${hname}.empty());
	    map_${hname}[-1] = &handler;
	}

	void ${name}Service::unregisterHandler(${hname}& handler, registration_uid_t regId) {
	    ASSERT(map_${hname}[regId] == &handler);
	    map_${hname}.erase(regId);
	}
END
    }
    if ($this->isDynamicRegistration()) {
        my $regType = $this->registration();
        print $outfile qq/
        registration_uid_t ${name}Service::allocateRegistration($regType const & object, registration_uid_t regId) {
            std::ostringstream out;
            out << object << regId;
            MaceKey hashed(sha32,out.str());
            registration_uid_t retval = hashed.getNthDigit(0,32);
            _regMap[retval] = object;
        /;

        for my $h ($this->providedHandlers()) {
            my $hname = $h->name();
            print $outfile qq/
            {
                maptype_${hname}::const_iterator i = map_${hname}.find(regId);
                maptype_${hname}::const_iterator j = map_${hname}.find(retval);
                ASSERT(j == map_${hname}.end() || (i != map_${hname}.end() && i->second == j->second));
                if (i != map_${hname}.end()) {
                    map_${hname}[retval] = i->second;
                }
            }
            /;
        }

        print $outfile qq/
            return retval;
        }
        void ${name}Service::freeRegistration(registration_uid_t regId, registration_uid_t baseRid) {
            ASSERT(_regMap.find(regId) != _regMap.end());
            _regMap.erase(regId);
        /;

        for my $h ($this->providedHandlers()) {
            my $hname = $h->name();
            print $outfile qq/
                ASSERT(map_${hname}.find(baseRid) != map_${hname}.end());
                ASSERT(map_${hname}[regId] == map_${hname}[baseRid]);
                map_${hname}.erase(regId);
            /;
        }

        print $outfile qq/
        }

        bool ${name}Service::getRegistration($regType & object, registration_uid_t regId) {
            if (_regMap.find(regId) != _regMap.end()) {
                object = _regMap[regId];
                return true;
            }
            return false;
        }
        /;
    }
    print $outfile "//END Mace::Compiler::ServiceImpl::printHandlerRegistrations\n";
}

sub printHandlerDemux {
    my $this = shift;
    my $outfile = shift;

    my $name = $this->name();

    print $outfile "//BEGIN Mace::Compiler::ServiceImpl::printHandlerDemux\n";
    #print Dumper( $this->usesHandlerMethods()  );
    for my $m ($this->usesHandlerMethods()) {
        #print Dumper( $m->options() );
#        print "DEBUG-DEMUX: ".$m->toString(noline=>1)."\n";
        $this->demuxMethod($outfile, $m, "upcall");

        #print "upcall: " . $m->name() . "(" . join(",", map{$_->name(). ":" . $_->type->type() } $m->params()) . ")\n";
    }
    print $outfile "//END Mace::Compiler::ServiceImpl::printHandlerDemux\n";
}

sub printTimerDemux {
    my $this = shift;
    my $outfile = shift;

    my $name = $this->name();

    print $outfile "//BEGIN Mace::Compiler::ServiceImpl::printTimerDemux\n";
    for my $m ($this->timerMethods()) {
        $this->demuxMethod($outfile, $m, "scheduler");
    }
    print $outfile "//END Mace::Compiler::ServiceImpl::printTimerDemux\n";
}

sub printChangeTracker {
    my $this = shift;
    my $outfile = shift;

    print $outfile "//BEGIN Mace::Compiler::ServiceImpl::printChangeTracker\n";
    if ($this->count_onChangeVars()) {

	my $name = $this->name();
        my $ctVarsCheck = "";
        for my $asp ($this->aspectMethods()) {
          my $aname = $asp->name();
          $ctVarsCheck .= "if(" . join("||", map{ "(sv->$_ != sv->_MA_${aname}_$_)" } @{$asp->options('monitor')}) . ") {
                            somethingChanged = true;
                            sv->$aname(".join(",", map { "sv->_MA_${aname}_$_" } @{$asp->options('monitor')}).");
                            ".join("\n", map{ "if(sv->$_ != sv->_MA_${aname}_$_) { sv->_MA_${aname}_$_ = sv->$_; } " } @{$asp->options('monitor')})."
                           }
                           ";
        }


	print $outfile <<END;
	class __ChangeTracker__ {
	  private:
	    //Pointer to the service for before/after inspection
		${name}Service* sv;
	    //Copies of the variables initial conditions for 'var' method variables
	      public:
		__ChangeTracker__(${name}Service* service) : sv(service) {}
	    ~__ChangeTracker__() {
              bool somethingChanged = false;
              do {
                somethingChanged = false;
		$ctVarsCheck
              } while(somethingChanged);
		}
	};
END
    }
    print $outfile "//END Mace::Compiler::ServiceImpl::printChangeTracker\n";
}

sub printSerialHelperDemux {
    my $this = shift;
    my $outfile = shift;

    my $name = $this->name();

    print $outfile "//BEGIN Mace::Compiler::ServiceImpl::printSerialHelperDemux\n";
    for my $m ($this->implementsUpcalls(), $this->implementsDowncalls()) {
	if ($m->serialRemap) {
        #print "printSerialHelperDemux:" . $m->toString() . "\n";
	    $this->demuxSerial($outfile, $m);
	}
    }
    print $outfile "//END Mace::Compiler::ServiceImpl::printSerialHelperDemux\n";
}

sub demuxSerial {
    my $this = shift;
    my $outfile = shift;
    my $m = shift;
    my $name = $this->name();

    my $fnName = $m->name();

    my $return = '';
    my $vreturn = "return;";
    if (!$m->returnType->isVoid()) {
	$return = 'return';
	$vreturn = "";
    }

    my $apiBody = qq{//TODO: try/catch Serialize
		     };
    my $rawt = $this->rawTransitions($fnName);
    if ($rawt) {
        my $rawm = $rawt->getTransitionMethodName();
        for my $sv ($this->service_variables()) {
            if ($sv->raw()) {
                my $rid = $sv->registrationUid();
                my $lock = "";
                if ($this->locking() > -1) {
                    $lock = "mace::AgentLock __rawlock(".$this->locking().");";
                }
#chuangw: TODO
# if the service uses contexts, it should use ContextLock instead of AgentLock,
# but I am not sure when demuxSerial is called so I do not plan to change this part of code now.
                $apiBody .= "if (rid == $rid) {
  $lock
  $return $rawm(".$m->paramsToString(notype=>1, nodefaults=>1).");
  $vreturn
}\n";
	    }
	}
    }

    for my $p ($m->params()) {
        if ($p->typeSerial and $p->typeSerial->type ne 'Message') {
            my $dstype = $p->type()->type();
            my $typeSerial = $p->typeSerial()->type();
            my $pname = $p->name();
            $apiBody .= qq{
 $typeSerial ${pname}_deserialized;
 ScopedDeserialize<$dstype, $typeSerial> __sd_$pname(${pname}, ${pname}_deserialized);
                        };
        }
    }
    my $msgDeserialize = "$return $fnName(".join(",", map{$_->name.(($_->typeSerial)?"_deserialized":"")}$m->params()).");\n";
    for my $p ($m->params()) {
        if ($p->typeSerial and $p->typeSerial->type eq 'Message') {
            my $pname = $p->name();
            my $msgTraceNum = "//TODO -- trace num\n";
            my $msgTrace = "//TODO -- trace msg\n";
            my $body = $m->body();
            my $msgDeserializeTmp = qq/
uint8_t msgNum_$pname = Message::getType($pname);
$msgTraceNum
switch(msgNum_$pname) {
/;
            for my $msg ($this->messages()) {
                my $msgName = $msg->name;
                $msgDeserializeTmp .= qq/
                    case ${msgName}::messageType: {
                        ${msgName} ${pname}_deserialized;
                        ${pname}_deserialized.deserializeStr($pname);
                        $msgTrace
                            $msgDeserialize
                        }
                    break;
                /;
            }
            $msgDeserializeTmp .= qq/ default: {
                maceerr << "FELL THROUGH NO PROCESSING -- INVALID MESSAGE NUMBER" << Log::endl;
                $body
                    ABORT("INVALID MESSAGE NUMBER");
            }
              break;
          /;
            $msgDeserializeTmp .= "}\n";
            $msgDeserialize = $msgDeserializeTmp;
        }
    }
    $apiBody .= $msgDeserialize;
    unless($m->returnType->isVoid()) {
        $apiBody .= qq/\nABORT("Should never reach here - should have returned value from call to serialized form");\n/;
    }

    print $outfile $m->toString("methodprefix" => "${name}Service::", "nodefaults" => 1, usebody => $apiBody,
                                notextlog => 1, selectorVar => 1, traceLevel => $this->traceLevel());

}

sub printDowncallHelpers {
    my $this = shift;
    my $outfile = shift;

    my $name = $this->name();

    print $outfile "//BEGIN Mace::Compiler::ServiceImpl::printDowncallHelpers\n";

    print $outfile join("\n", $this->generateAddDefer("downcall", my $ref = $this->downcallDeferMethods()));

    if ($this->count_downcall_registrations()) {
        print $outfile qq/void ${name}Service::downcall_freeRegistration(registration_uid_t freeRid, registration_uid_t rid) {
            /;

        my @regSv = grep($_->registration(), $this->service_variables());
        if (scalar(@regSv) == 1) {
            my $svname = $regSv[0]->name();
            print $outfile qq/if (rid == -1) {
                                rid = $svname;
                              }
                             /;
            #print $outfile "// DEBUG:: ".$regSv[0]."\n";
        }

        for my $sv (@regSv) {
            my $svname = $sv->name();
            print $outfile qq/if (rid == $svname) {
                                ASSERT(_registered_$svname.find(freeRid) != _registered_$svname.end());
                                _d_$svname.freeRegistration(freeRid, rid);
                                _registered_$svname.erase(freeRid);
                              }
                             /;
        }

        print $outfile qq/
        }
        /;
    }
    for my $r ($this->downcall_registrations()) {

        print $outfile qq/
          registration_uid_t ${name}Service::downcall_allocateRegistration($r const & object, registration_uid_t rid) {
            /;

        my @regSv = grep($_->registration() eq $r, $this->service_variables());
        if (scalar(@regSv) == 1) {
            my $svname = $regSv[0]->name();
            print $outfile qq/if (rid == -1) {
                                rid = $svname;
                              }
                             /;
        }

        for my $sv (@regSv) {
            my $svname = $sv->name();
            print $outfile qq+if (rid == $svname) {
                                registration_uid_t newrid = _d_$svname.allocateRegistration(object, rid);
                                //ASSERT(_registered_$svname.find(newrid) == _registered_$svname.end());
                                _registered_$svname.insert(newrid);
                                return newrid;
                              }
                             +;
        }

        print $outfile qq/
            ABORT("allocateRegistration called on invalid registration_uid_t");
          }
          bool ${name}Service::downcall_getRegistration($r & object, registration_uid_t rid) {
            /;

        if (scalar(@regSv) == 1) {
            my $svname = $regSv[0]->name();
            print $outfile qq/if (rid == -1) {
                                rid = $svname;
                              }
                             /;
        }
        for my $sv (@regSv) {
            my $svname = $sv->name();
            print $outfile qq/if (_registered_$svname.find(rid) != _registered_$svname.end()) {
                                ASSERT(_d_$svname.getRegistration(object, rid));
                                return true;
                              }
                             /;
        }

        print $outfile qq/
            return false;
          }
        /;

    }

    #localAddress downcall helper method
    my $svAddr = "";
    my $svVal = "";
    my $svCheck = "MaceKey tmp = MaceKey::null;";
    my $svOne = "";
    my $num = 0;
    for my $sv ($this->service_variables) {
        if (not $sv->intermediate() ) {
            $num++;
            my $svn = $sv->name();
            $svOne = "return _$svn.localAddress();";
            $svCheck .= qq/
                if (tmp.isNullAddress()) {
                    tmp = _$svn.localAddress();
                }
                else {
                    MaceKey tmp2 = _$svn.localAddress();
                    ASSERTMSG(tmp2.isNullAddress() || tmp == tmp2, "Requesting lower level address from service $name, but lower level service $svn does not return same address as another service.  If this occurs due to default computing a local address you may need a local_address block to disambiguate.  Otherwise, either you are using incompatible lower level services, or you need to specify a service to ask for the local address from by passing in the service parameter.");
                } /;
            $svAddr .= qq/
                if (&rid == &$svn) {
                    return _$svn.localAddress();
                } /;
            $svVal .= qq/
                if (rid == $svn) {
                    return _$svn.localAddress();
                } /;
        }
    }
    if ($num == 1) {
        $svCheck = $svOne;
    } else {
        $svCheck .= "
            return tmp;"
    }

    print $outfile qq/
        MaceKey ${name}Service::downcall_localAddress() const {
            $svCheck
        }
        const MaceKey& ${name}Service::downcall_localAddress(const registration_uid_t& rid) const {
            $svAddr
            $svVal
            return MaceKey::null;
        }
    /;


    #downcall helper methods
    for my $m ($this->usesClassMethods()) {
        my $origmethod = $m;
        my $serialize = "";
        my $checkDefer = "";
        my $defaults = "";
        if ($m->options('original')) {
            #TODO: try/catch Serialization
            $origmethod = $m->options('original');
            my @oparams = $origmethod->params();
            for my $p ($m->params()) {
                my $op = shift(@oparams);
                if (! $op->type->eq($p->type)) {
                    my $optype = $op->type->type();
                    my $opname = $op->name;
                    my $ptype = $p->type->type();
                    my $pname = $p->name;
                    $serialize .= qq{ $optype $opname;
                                      ScopedSerialize<$optype, $ptype> __ss_$pname($opname, $pname);
                                  };
                }
            }
        }
        if ($m->options('remapDefault')) {
            for my $p ($m->params()) {
                if ($p->flags('remapDefault')) {
                    my $pn = $p->name();
                    my $pd = $p->default();
                    my $pd2 = $p->flags('remapDefault');
                    $defaults .= qq{ if($pn == $pd) { $pn = $pd2; }
                                 };
                }
            }
        }
        my @matchedServiceVars;
        for my $sv ($this->service_variables) {
            if (not $sv->intermediate() and ref Mace::Compiler::Method::containsTransition($origmethod, $this->usesClasses($sv->serviceclass))) {
                push(@matchedServiceVars, $sv);
            }
        }
        if (scalar(@matchedServiceVars) == 1) {
            my $rid = $m->params()->[-1]->name();
            my $svn = $matchedServiceVars[0]->name();
            $defaults .= qq{ if($rid == -1) { $rid = $svn; }
                         };
        }
        my $callString = "";
        for my $sv (@matchedServiceVars) {
            my $rid = $m->params()->[-1]->name();
            my $callm = $origmethod->name."(".join(",", map{$_->name} $origmethod->params()).")";
            my $svname = $sv->name;
            my $regtest = "";
            if ($sv->registration()) {
                $regtest = qq{ || _registered_$svname.find($rid) != _registered_$svname.end()};
            }
            my $return = (!$m->returnType->isVoid())?"return":"";
            $callString .= qq/if($rid == $svname$regtest) {
                $return _$svname.$callm;
            } else
            /;
        }
        #TODO: Logging, etc.
        $callString .= qq/{ ABORT("Did not match any registration uid!"); }/;
=begin
        $checkDefer = "
        if( mace::AgentLock::getCurrentMode() == mace::AgentLock::NONE_MODE ){ // defer this message until event commits
            
        }else{
            $defaults
            $callString
        }
        ";
=cut
        my $routine = $m->toString("methodprefix"=>"${name}Service::downcall_", "noid" => 0, "novirtual" => 1, "nodefaults" => 1, selectorVar => 1, binarylog => 1, traceLevel => $this->traceLevel(), usebody => "
                $serialize
                $defaults
                $callString
        ");
        print $outfile $routine;
    }
    print $outfile "//END Mace::Compiler::ServiceImpl::printDowncallHelpers\n";
}

sub printUpcallHelpers {
    my $this = shift;
    my $outfile = shift;

    my $name = $this->name();

    print $outfile "//BEGIN Mace::Compiler::ServiceImpl::printUpcallHelpers\n";

    print $outfile join("\n", $this->generateAddDefer("upcall", my $ref = $this->upcallDeferMethods()));

    for my $m ($this->providedHandlerMethods()) {
        my $origmethod = $m;
        my $serialize = "";
        my $defaults = "";
        if ($m->options('original')) {
            #TODO: try/catch Serialization
            $origmethod = $m->options('original');
            my @oparams = $origmethod->params();
            for my $p ($m->params()) {
                my $op = shift(@oparams);
                if (! $op->type->eq($p->type)) {
                    my $optype = $op->type->type();
                    my $opname = $op->name;
                    my $ptype = $p->type->type();
                    my $pname = $p->name;
                    $serialize .= qq{ $optype $opname;
                                      ScopedSerialize<$optype, $ptype> __ss_$pname($opname, $pname);
                                  };
                }
            }
        }
        if ($m->options('remapDefault')) {
            for my $p ($m->params()) {
                if ($p->flags('remapDefault')) {
                    my $pn = $p->name();
                    my $pd = $p->default();
                    my $pd2 = $p->flags('remapDefault');
                    $defaults .= qq{ if($pn == $pd) { $pn = $pd2; }
                                 };
                }
            }
        }
        my $callString = "";

        my @handlerArr = @{$m->options('class')};
        unless(scalar(@handlerArr) == 1) {
            Mace::Compiler::Globals::error("ambiguous_upcall", $m->filename(), $m->line(), "Too many possible Handler types for this method (see Mace::Compiler::ServiceImpl [2])");
            #[2] : In the present implementation, if an upcall could map to more than
            #one handler type, we do not support it.  In theory, we could have a
            #stratgegy where we search the upcall maps in a given order, upcalling to
            #the first one we find.  Especially since if they had the same rid, they
            #should refer to the same bond at least.  However, for simplicity, for
            #now we just drop it as an error.
            next;
        }
        my $handler = shift(@handlerArr);
        my $hname = $handler->name;
        my $mname = $m->name;
        my $body = $m->body;
        my $rid = $m->params()->[-1]->name();
        my $return = '';
        if (!$m->returnType->isVoid()) {
            $return = 'return';
        }
        my $callm = $origmethod->name."(".join(",", map{$_->name} $origmethod->params()).")";
        my $iterator = "iterator";
        if ($m->isConst()) {
            $iterator = "const_iterator"
        }
        if ($this->registration() eq "unique") {
            $callString .= qq{
                          ASSERT(map_${hname}.size() <= 1);
                          maptype_${hname}::$iterator iter = map_${hname}.begin();
                          if(iter == map_${hname}.end()) {
                              maceWarn("No $hname registered with uid %"PRIi32" for upcall $mname!", $rid);
                              $body
                              }
                          else {
                              $return iter->second->$callm;
                          }
                      };
        }
        else {
            $callString .= qq{maptype_${hname}::$iterator iter = map_${hname}.find($rid);
                          if(iter == map_${hname}.end()) {
                              maceWarn("No $hname registered with uid %"PRIi32" for upcall $mname!", $rid);
                              $body
                              }
                          else {
                              $return iter->second->$callm;
                          }
                      };
        }
        my $routine = $m->toString("methodprefix"=>"${name}Service::upcall_", "noid" => 0, "novirtual" => 1, "nodefaults" => 1, selectorVar => 1, binarylog => 1, traceLevel => $this->traceLevel(), usebody => "
                $serialize
                $defaults
                $callString
        ");
        print $outfile $routine;
    }
    print $outfile "//END Mace::Compiler::ServiceImpl::printUpcallHelpers\n";
}

sub printDummyConstructor {
    my $this = shift;
    my $outfile = shift;

    my $name = $this->name();
    my @svo = grep( not($_->intermediate), $this->service_variables());

    #TODO: utility_timer
    my $constructors = "${name}Dummy::${name}Dummy() : \n//(\nBaseMaceService(), __inited(0)";
#    my $constructors = "${name}Dummy::${name}Dummy(".join(", ", (map{$_->type->toString()." _".$_->name} $this->constructor_parameters()) ).") : \n//(\nBaseMaceService(), __inited(0)";
    $constructors .= ", _actual_state(init), state(_actual_state)";
    map{ my $timer = $_->name(); $constructors .= ",\n$timer(*(new ${timer}_MaceTimer(this)))"; } $this->timers();
    $constructors .= qq|{
    }
    |;

    print $outfile $constructors;
    print $outfile "//END Mace::Compiler::ServiceImpl::printDummyConstructor\n";
}

sub printLoadProtocol {
    my $this = shift;
    my $outfile = shift;

    my $name = $this->name();

    print $outfile "//BEGIN Mace::Compiler::ServiceImpl::printLoadProtocol\n";

    foreach my $scProvided ($this->provides()) {
        print $outfile "${scProvided}ServiceClass& configure_new_${name}_${scProvided}(bool ___shared);\n";
    }

    my $attrs = $this->attributes();
    print $outfile "\n  void load_protocol() {\n";
    print $outfile qq/StringSet attr = mace::makeStringSet("$attrs", ",");\n/;

    foreach my $scProvided ($this->provides()) {
        print $outfile qq/mace::ServiceFactory<${scProvided}ServiceClass>::registerService(&configure_new_${name}_${scProvided}, "$name");\n/;
        print $outfile qq/mace::ServiceConfig<${scProvided}ServiceClass>::registerService("$name", attr);\n/;
    }

    print $outfile "  }\n";

    print $outfile "//END Mace::Compiler::ServiceImpl::printLoadProtocol\n";
}

sub printConstructor {
    my $this = shift;
    my $outfile = shift;

    my $name = $this->name();
    my @svo = grep( not($_->intermediate), $this->service_variables());
    my @svp = grep( not($_->intermediate or $_->final), $this->service_variables());

    print $outfile "//BEGIN Mace::Compiler::ServiceImpl::printConstructor\n";
    foreach my $scProvided ($this->provides()) {
        my $realMethod = "real_new_${name}_$scProvided";
	print $outfile "${scProvided}ServiceClass& $realMethod(".join(", ", (map{$_->serviceclass."ServiceClass& ".$_->name} @svo), (map{$_->toString("nodefaults" => 1)} $this->constructor_parameters()), "bool ___shared" ).") {\n";
#	print $outfile "return *(new ${name}Service(".join(",", (map{$_->name} @svp, $this->constructor_parameters)).") );\n";
	print $outfile "return *(new ${name}Service(".join(",", (map{$_->name} @svp, $this->constructor_parameters), "___shared")."));\n";
        print $outfile "}\n";
    }


    #TODO: utility_timer
    my $constructors = "${name}Service::${name}Service(".join(", ", (map{$_->serviceclass."ServiceClass& __".$_->name} @svo), (map{$_->type->toString()." _".$_->name} $this->constructor_parameters()), "bool ___shared" ).") : \n//(\nBaseMaceService(), __inited(0)";
    $constructors .= ", _actual_state(init), state(_actual_state)";
    map{
        my $n = $_->name();
        $constructors .= ",\n$n(_$n)";
    } $this->constructor_parameters();
    map{
        my $n = $_->name();
        my $rid = $_->registrationUid();
        $constructors .= ",\n_$n(__$n), $n($rid)";
        if ($_->registration()) {
            my $regType = $_->registration(); $constructors .= ",\n_d_$n(dynamic_cast<DynamicRegistrationServiceClass<$regType>& >(_$n))";
        }
    } @svo;
    map{
        my $n = $_->name();
        my $default = "";
        if ($_->hasDefault()) {
            $default = $_->default();
        }
        $constructors .= ",\n$n($default)";
    } $this->state_variables(), $this->onChangeVars(); #nonTimer => state_Var
    map{ my $timer = $_->name(); $constructors .= ",\n$timer(*(new ${timer}_MaceTimer(this)))"; } $this->timers();
    my $registerInstance = "
    if (___shared) {
    ".join("\n", map{ qq/mace::ServiceFactory<${_}ServiceClass>::registerInstance("$name", this);/ } $this->provides())."
    }
    ServiceClass::addToServiceList(*this);
    ";
    my $propertyRegister = "";
    if ($this->count_safetyProperties() or $this->count_livenessProperties()) {
        $propertyRegister = qq/
            if (macesim::SimulatorFlags::simulated()) {
                static bool defaultTest = params::get<bool>("AutoTestProperties", 1);
                static bool testThisService = params::get<bool>("AutoTestProperties.$name", defaultTest);
                if (testThisService) {
                    static int testId = NumberGen::Instance(NumberGen::TEST_ID)->GetVal();
                    macesim::SpecificTestProperties<${name}Service>::registerInstance(testId, this);
                }
            }
        /;
    }
    $constructors .= ", __local_address(MaceKey::null)";
    $constructors .= qq|\n{
	initializeSelectors();
        __local_address = computeLocalAddress();
        $registerInstance
        $propertyRegister
        ADD_SELECTORS("${name}::(constructor)");
        macedbg(1) << "Created queued instance " << this << Log::endl;
    }
    //)
    |;

    $constructors .= "${name}Service::${name}Service(const ${name}Service& _sv) : \n//(\nBaseMaceService(false), __inited(_sv.__inited)";
    $constructors .= ", _actual_state(_sv.state), state(_actual_state)";
    map{
        my $n = $_->name();
        $constructors .= ",\n$n(_sv.$n)";
    } $this->constructor_parameters();
    map{
        my $n = $_->name();
        my $rid = $_->registrationUid();
        $constructors .= ",\n_$n(_sv._$n), $n(_sv.$n)";
        # if ($_->registration()) {
        #     my $regType = $_->registration(); $constructors .= ",\n_d_$n(dynamic_cast<DynamicRegistrationServiceClass<$regType>& >(_$n))";
        # }
    } @svo;
    map{
        my $n = $_->name();
        $constructors .= ",\n$n(_sv.$n)";
    } $this->state_variables(), $this->onChangeVars(); #nonTimer => state_Var
#    map{ my $timer = $_->name(); $constructors .= ",\n$timer(_sv.$timer)"; } $this->timers(); # Note: timer sv pointer will point to "main" service, not this copy...
    map{ my $timer = $_->name(); $constructors .= ",\n$timer(*(new ${timer}_MaceTimer(this)))"; } $this->timers(); # These pointers are new copies - don't share data...  Would probably prefer not to have them at all?
    $constructors .= qq|{
        ADD_SELECTORS("${name}::(constructor)");
        macedbg(1) << "Created non-queued instance " << this << Log::endl;
    }
    //)
    |;

    print $outfile $constructors;
    print $outfile "//END Mace::Compiler::ServiceImpl::printConstructor\n";
}

sub traceLevel {
    my $this = shift;
    if ($Mace::Compiler::Globals::traceOverride > -2) {
        return $Mace::Compiler::Globals::traceOverride;
    }
    if ($this->trace eq 'off') {
        return -1;
    }
    if ($this->trace eq 'manual') {
        return 0;
    }
    if ($this->trace eq 'low') {
        return 1;
    }
    if ($this->trace eq 'med') {
        return 2;
    }
    if ($this->trace eq 'high') {
        return 3;
    }
}

sub printDummyFactory {
    my $this = shift;
    my $body = shift;
    my $factories = shift;
    my $log = shift;

    my $name = $this->name();
    my $logName = (defined $log->options('binlogname')) ? $log->options('binlogname') : $log->name();

    if (not $log->messageField()) {
        if ($log->getLogLevel($this->traceLevel()) > 0) {
            $$body .= "mapper.addFactory(\"${name}_${logName}\", &${logName}DummyFactory);\n";
            $$factories .= "mace::BinaryLogObject* ${logName}DummyFactory() {\n";
            $$factories .= "return new ${logName}Dummy();\n";
            $$factories .= "}\n";
        }
    }
}

sub printDummyInitCCFile {
    my $this = shift;
    my $outfile = shift;
    my $name = $this->name();
    my $body = "";
    my $factories = "";

    $body .= "mapper.addFactory(\"${name}\", &${name}DummyFactory);\n";
    $factories .= "mace::BinaryLogObject* ${name}DummyFactory() {\n";
    $factories .= "return new ${name}Dummy();\n";
    $factories .= "}\n";
    for my $log ($this->structuredLogs()) {
        $this->printDummyFactory(\$body, \$factories, $log);
    }
    if ($this->traceLevel() > 0) {
        for my $log (grep(!($_->name =~ /^(un)?register.*Handler$/), $this->providedMethods()), @{$this->aspectMethods()}, @{$this->usesHandlerMethods()}, @{$this->timerMethods()}, @{$this->usesClassMethods()}, @{$this->providedHandlerMethods()}) {
            $this->printDummyFactory(\$body, \$factories, $log);
        }
    }
    if ($this->traceLevel() > 1) {
        for my $log ($this->routines()) {
            $this->printDummyFactory(\$body, \$factories, $log);
        }
    }

    print $outfile <<END;
#ifndef ${name}_dummy_init_h
#define ${name}_dummy_init_h
    #include "DummyServiceMapper.h"
    #include "${name}.h"
    using mace::DummyServiceMapper;

    namespace ${name}_namespace {
      $factories
      void init() __attribute__((constructor));
      void init() {
        DummyServiceMapper mapper;
END

    print $outfile $body;
    print $outfile <<END;
      }
    }
#endif // ${name}_dummy_init_h
END
}

sub printInitHFile {
    my $this = shift;
    my $outfile = shift;
    my $name = $this->name();

    my @svp = grep( not($_->intermediate or $_->final), $this->service_variables());

    my $r = Mace::Compiler::GeneratedOn::generatedOnHeader("$name init declaration file");
    print $outfile $r;

    print $outfile <<END;
#ifndef ${name}_init_h
#define ${name}_init_h

    #include "${name}-constants.h"
END
    $this->printIncludeBufH($outfile);

    foreach my $scProvided ($this->provides()) {
        print $outfile <<END;
#include "${scProvided}ServiceClass.h"
END
    }
    foreach my $scUsed ($this->service_variables()) {
        print $outfile $scUsed->returnSCInclude();
    }
    print $outfile <<END;

    namespace ${name}_namespace {
END
    foreach my $scProvided ($this->provides()) {
        print $outfile "${scProvided}ServiceClass& new_${name}_$scProvided(".join(", ", (map{my $svline = $_->line(); my $svfile = $_->filename(); qq{\n#line $svline "$svfile"\n}.$_->serviceclass."ServiceClass& ".$_->name." = ".$_->serviceclass."ServiceClass::NULL_\n// __INSERT_LINE_HERE__\n"} @svp), (map{$_->toString()} $this->constructor_parameters()) ).");\n";
	print $outfile "${scProvided}ServiceClass& private_new_${name}_$scProvided(".join(", ", (map{my $svline = $_->line(); my $svfile = $_->filename(); qq{\n#line $svline "$svfile"\n}.$_->serviceclass."ServiceClass& ".$_->name." = ".$_->serviceclass."ServiceClass::NULL_\n// __INSERT_LINE_HERE__\n"} @svp), (map{$_->toString()} $this->constructor_parameters()) ).");\n";

        if ($this->count_constructor_parameters() and scalar(@svp)) {
            print $outfile "${scProvided}ServiceClass& new_${name}_$scProvided(";
            my @p = $this->constructor_parameters();
            my $p1 = shift(@p);
            print $outfile $p1->type->toString()." ".$p1->name.", ";
            print $outfile join(", ", (map{$_->toString()} @p), (map{my $svline = $_->line(); my $svfile = $_->filename(); qq{\n#line $svline "$svfile"\n}.$_->serviceclass."ServiceClass& ".$_->name." = ".$_->serviceclass."ServiceClass::NULL_\n// __INSERT_LINE_HERE__\n"} @svp) );
            print $outfile ");\n";
	    print $outfile "${scProvided}ServiceClass& private_new_${name}_$scProvided(";
	    #my @p = $this->constructor_parameters();
	    #my $p1 = shift(@p);
	    print $outfile $p1->type->toString()." ".$p1->name.", ";
	    print $outfile join(", ", (map{$_->toString()} @p), (map{my $svline = $_->line(); my $svfile = $_->filename(); qq{\n#line $svline "$svfile"\n}.$_->serviceclass."ServiceClass& ".$_->name." = ".$_->serviceclass."ServiceClass::NULL_\n// __INSERT_LINE_HERE__\n"} @svp) );
	    print $outfile ");\n";
        }
    }

    print $outfile <<END;
} //end namespace
#endif // ${name}_init_h
END
}

sub printInitCCFile {
    my $this = shift;
    my $outfile = shift;
    my $name = $this->name();
    my @svo = grep( not($_->intermediate), $this->service_variables());
    my @svp = grep( not($_->intermediate or $_->final), $this->service_variables());

    my $r = Mace::Compiler::GeneratedOn::generatedOnHeader("$name init source file");
    print $outfile $r;

    print $outfile <<END;
  #include "${name}-init.h"
  #include "params.h"
  #include "ServiceConfig.h"
END
    print $outfile join("", map{my $sv=$_->service; qq{#include "$sv-init.h"\n}} grep($_->service && $_->service ne "auto", $this->service_variables()));
    print $outfile <<END;
  namespace ${name}_namespace {
END
    foreach my $scProvided ($this->provides()) {
        my $realMethod = "real_new_${name}_$scProvided";
	print $outfile "${scProvided}ServiceClass& $realMethod(".join(", ", (map{$_->serviceclass."ServiceClass& ".$_->name} @svo), (map{$_->toString("nodefaults" => 1)} $this->constructor_parameters()), "bool ___shared" ).");\n";
        print $outfile "${scProvided}ServiceClass& new_${name}_$scProvided(".join(", ", (map{$_->serviceclass."ServiceClass& _".$_->name} @svp), (map{$_->toString("nodefaults" => 1)} $this->constructor_parameters()) ).") {\n";
	$this->printInitStuff($outfile, $realMethod, 1);
	print $outfile "}\n";
	print $outfile "${scProvided}ServiceClass& private_new_${name}_$scProvided(".join(", ", (map{$_->serviceclass."ServiceClass& _".$_->name} @svp), (map{$_->toString("nodefaults" => 1)} $this->constructor_parameters()) ).") {\n";
	$this->printInitStuff($outfile, $realMethod, 0);
	print $outfile "}\n";

        if ($this->count_constructor_parameters() and scalar(@svp)) {
            print $outfile "${scProvided}ServiceClass& new_${name}_$scProvided(";
            my @p = $this->constructor_parameters();
            my $p1 = shift(@p);
            print $outfile $p1->type->toString()." ".$p1->name.", ";
            print $outfile join(", ", (map{$_->toString("nodefaults"=>1)} @p), (map{$_->serviceclass."ServiceClass& _".$_->name} @svp) );
            print $outfile ") {\n";
	    $this->printInitStuff($outfile, $realMethod, 1);
	    print $outfile "}\n";
	    print $outfile "${scProvided}ServiceClass& private_new_${name}_$scProvided(";
	    #my @p = $this->constructor_parameters();
	    #my $p1 = shift(@p);
	    print $outfile $p1->type->toString()." ".$p1->name.", ";
	    print $outfile join(", ", (map{$_->toString("nodefaults"=>1)} @p), (map{$_->serviceclass."ServiceClass& _".$_->name} @svp) );
	    print $outfile ") {\n";
	    $this->printInitStuff($outfile, $realMethod, 0);
            print $outfile "}\n";
        }

        print $outfile "${scProvided}ServiceClass& configure_new_${name}_$scProvided(bool ___shared) {\n";

        print $outfile "if (___shared) { return new_${name}_$scProvided(); }
                        else { return private_new_${name}_$scProvided(); }\n";
        print $outfile "}\n";
    }
    print $outfile <<END;
  } //end namespace
END
}

sub printInitStuff {
    my $this = shift;
    my $outfile = shift;
    my $realMethod = shift;
    my $shared = shift;
    my $name = $this->name();
    my @svo = grep( not($_->intermediate), $this->service_variables());
    my @svp = grep( not($_->intermediate or $_->final), $this->service_variables());

    for (my $i = $this->count_service_variables()-2; $i >= 0; $i--) {
        my $s1 = $this->service_variables()->[$i];
        my $s1n = $this->service_variables()->[$i]->name();
        my @joins;
        for (my $j = $this->count_service_variables()-1; $j > $i; $j--) {
            my $s2 = $this->service_variables()->[$j];
            my $s2n = $this->service_variables()->[$j]->name();
            if ($s2->service and grep($s1n eq $_, $s2->constructionparams())) {
                if ($s2->final) {
                    @joins = [ 'true' ];
                    last;
                }
                elsif ($s2->intermediate) {
                    push @joins, "later_dep_$s2n";
                }
                else {
                    push @joins, "(&_".$s2n." == &".$s2->serviceclass."ServiceClass::NULL_)";
                }
            }
        }
        if ($s1->intermediate()) {
            if (@joins) {
                print $outfile "const bool later_dep_$s1n = ". join(' || ', @joins) . ";\n";
            }
            else {
                Mace::Compiler::Globals::error("invalid_service", $s1->filename, $s1->line(), "'intermediate' may only be applied to services which are used later in the services block; $s1n is not used later!");
            }
        }
    }

    for my $sv ($this->service_variables()) {
        my $svline = $sv->line();
        my $svfile = $sv->filename();
        my $name = $this->name();
#        if ($sv->service() or $sv->doDynamicCast()) {
	    print $outfile qq{\n#line $svline "$svfile"\n};
	    if ($sv->intermediate) {
		print $outfile $sv->serviceclass."ServiceClass& ${\$sv->name} = (later_dep_${\$sv->name}) ? ".$sv->toNewMethodCall()." : ".$sv->serviceclass."ServiceClass::NULL_;\n";
	    } elsif ($sv->final) { # or $sv->service eq "auto") {
		print $outfile $sv->serviceclass."ServiceClass& ${\$sv->name} = ".$sv->toNewMethodCall($name).";\n";
	    } else {
		print $outfile $sv->serviceclass."ServiceClass& ${\$sv->name} = (&_${\$sv->name} == &".$sv->serviceclass."ServiceClass::NULL_) ? ".$sv->toNewMethodCall($name)." : _${\$sv->name};\n";
	    }
	    print $outfile qq{\n// __INSERT_LINE_HERE__\n};
#	}
#	else {
#	    print $outfile qq{\n#line $svline "$svfile"\n};
#	    print $outfile $sv->serviceclass."ServiceClass& ${\$sv->name} = _${\$sv->name};\n";
#	    print $outfile qq{\n// __INSERT_LINE_HERE__\n};
#	}
    }

    print $outfile "return $realMethod(".join(", ", (map{$_->name} @svo), (map{ "(".$_->name." == ".$_->default()." ? mace::ServiceConfig<void*>::get<".$_->type->type.">(\"${\$this->name}.${\$_->name}\", ${\$_->name}) : ${\$_->name})" } $this->constructor_parameters()), $shared).");\n";

}

sub printMacrosFile {
    my $this = shift;
    my $outfile = shift;
    my $name = $this->name();

    my $r = Mace::Compiler::GeneratedOn::generatedOnHeader("$name macros file");
    print $outfile $r;

    my $undefCurtime = "";
    if ($this->macetime()) {
        #      $undefCurtime = '#undef curtime';
    }

    print $outfile <<END;
#ifndef ${name}_macros_h
#define ${name}_macros_h

#include "lib/mace-macros.h"
$undefCurtime

#define state_change(s) changeState(s, selectorId->log)
END

    for my $m ($this->providedHandlerMethods()) {
        my $fnName = $m->name;
        my $clName = $m->options('class')->[0]->name();
        print $outfile <<END;
    #define typeof_upcall_$fnName $clName
    #define map_typeof_upcall_$fnName map_$clName
END
    }

    print $outfile <<END;

#endif //${name}_macros_h
END
}

sub printComputeAddress() {
    my $this = shift;
    my $outfile = shift;

    if (defined($this->localAddress()) or $this->count_service_variables()) {

        print $outfile "
        MaceKey computeLocalAddress() const {
        ";

        if ($this->localAddress() ne "") {
            print $outfile $this->localAddress();
        } else {
            print $outfile "return downcall_localAddress();";
        }
    }

    print $outfile "
    }
    ";
}

# sub sortByLine {
#     my $this = shift;
#     my $func = shift;
#     my $ref = $this->$func();
#     my @sorted = sort {
#       if ($a->includedline() == $b->includedline()) {
#           return $a->line() <=> $b->line();
#       }
#       else {
#           return $a->includedline() <=> $b->includedline();
#       }
#     } @$ref;
#     $this->$func(@sorted);
# }

sub array_unique
{
    my %seen = ();
    @_ = grep { ! $seen{ $_ }++ } @_;
}

sub print_snapshotsHash {
		my $this = shift;

		my $transitionSnapshotContexts = $this->transitionSnapshotContexts();

		print "-----------------------------------------\n";
		while( my($key,  $value) = each(%{$transitionSnapshotContexts})){
				print "key: ".$key."  value: ".$value."\n";
		}
		print "-----------------------------------------\n";
}

1;
