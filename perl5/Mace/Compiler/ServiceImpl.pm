#
# ServiceImpl.pm : part of the Mace toolkit for building distributed systems
#
# Copyright (c) 2012, We-Chiu Chuang, Bo Sang, Charles Killian, James W. Anderson, Adolfo Rodriguez, Dejan Kostic
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
use v5.10.1;
use feature 'switch';

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
     'array_of_objects' => ["asyncLocalWrapperMethods" => { class => "Mace::Compiler::Method" }],

     #These are context helper methods 
     'array_of_objects' => ["contextHelperMethods" => { class => "Mace::Compiler::Method"}],

     #These are methods added for contexted routine calls
     'array_of_objects' => ["routineHelperMethods" => { class => "Mace::Compiler::Method"}],

     #These are methods added for contexted down/up calls
     'array_of_objects' => ["downcallHelperMethods" => { class => "Mace::Compiler::Method"}],
     'array_of_objects' => ["upcallHelperMethods" => { class => "Mace::Compiler::Method"}],

     'array_of_objects' => ["appUpcallDispatchMethods" => { class => "Mace::Compiler::Method"}],


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
     # chuangw: deprecated??
     'array_of_objects' => ['guards' => { class => 'Mace::Compiler::Guard' }],

     'object' => ['parser' => { class => "Parse::RecDescent" }],

     'string' => "origMacFile",
     'string' => "annotatedMacFile",

     'array' => "downcall_registrations",

     'object' => ['asyncExtraField' => { class => "Mace::Compiler::AutoType" }],

     'boolean' => 'useTransport',
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

my $context_count;
sub hasContexts {
    my $this = shift;

    if( not defined $context_count  ){
        $context_count = ${ $this->contexts() }[0]->count_subcontexts();
    }

    return $context_count;
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

    print $outfile qq/static const char* __SERVICE__ __attribute((unused)) = "${servicename}";\n/;
    print $outfile qq/mace::ContextMapping contextMapping;\n/;
    print $outfile qq/pthread_mutex_t getContextObjectMutex = PTHREAD_MUTEX_INITIALIZER;\n/;
    print $outfile qq/pthread_mutex_t ContextObjectCreationMutex = PTHREAD_MUTEX_INITIALIZER;\n/;
    print $outfile qq/pthread_cond_t ContextObjectCreationCond = PTHREAD_COND_INITIALIZER;\n/;
    print $outfile qq/mace::ContextEventRecord contextEventRecord;\n/;
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
#include "HeadEventDispatch.h"
#include "lib/MaceTime.h"
#include "lib/ServiceFactory.h"
#include "lib/ServiceConfig.h"
#include <boost/algorithm/string.hpp>
#include "lib/SysUtil.h"
#include "lib/ScopedContextRPC.h"

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
	// When entering the service stack, create event
END
    $this->printServiceStackEvent($outfile);

    $this->printScopedRoutinePrep($outfile);

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
    my $serializeContexts = join("\n", (grep(/./, map { $_->toSerialize("__str") } $this->contexts() )));
    my $deserializeContexts = join("\n", (grep(/./, map { $_->toDeserialize("__in", prefix => "serializedByteSize += ") }  $this->contexts()  )));
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
    my $accessorMethods = "";
    my $deleteSingleContextObject = join("\n", map { "delete $_->{name};" } grep( !$_->isArray(), ${ $this->contexts() }[0], ${ $this->contexts() }[0]->subcontexts() ) );
 

    print $outfile <<END;

    //Load Protocol

END

    $this->printLoadProtocol($outfile);

    print $outfile <<END;

    //Constructors
END

    $this->printConstructor($outfile);

    my $remoteAllocateGlobalContext = "";
    my $sendAllocateContextObjectmsg;
    if( $this->hasContexts() ){
        $sendAllocateContextObjectmsg = "

            const MaceAddr nullAddr = SockUtil::NULL_MACEADDR;
            // make a copy because contextMapping is shared among threads and it will be sent out by AllocateContextObject message
            // The purpose of sending AllocateContextObject is to send the updated context map

            mace::map< uint32_t, mace::string > contextSet; // empty set
            AllocateContextObject allocateCtxMsg( nullAddr, contextSet, ThreadStructure::myEvent().eventID, *ctxmapCopy, 0 );
            const mace::map < MaceAddr,uint32_t >& physicalNodes = contextMapping.getAllNodes(); 
            for( mace::map<MaceAddr, uint32_t>::const_iterator nodeIt = physicalNodes.begin(); nodeIt != physicalNodes.end(); nodeIt ++ ){ // chuangw: this message has to be sent to all nodes of the same logical node to update the context mapping.
              ASYNCDISPATCH( nodeIt->first, __ctx_dispatcher, AllocateContextObject, allocateCtxMsg )
            }
        ";
      $remoteAllocateGlobalContext = qq#
        mace::map< uint32_t, mace::string > contextSet;
        contextSet[ newMappingReturn.second ] =  globalContextID ;
        AllocateContextObject allocateCtxMsg( newMappingReturn.first, contextSet, he.eventID, *ctxmapCopy, 0 );
        const mace::MaceKey destNode( mace::ctxnode,  newMappingReturn.first );
        downcall_route( destNode , allocateCtxMsg , __ctx );
        #;
    }else{
      $sendAllocateContextObjectmsg = "";
      $remoteAllocateGlobalContext = qq#ABORT("The global context should be on the same node as the head node, for non-context'ed service!");#;
    }
    my $mutexDestroy = qq/
    pthread_mutex_destroy(&eventRequestBufferMutex);/;

    print $outfile <<END;


	//Destructor
	    ${servicename}Service::~${servicename}Service() {
		$timerDelete
    $deleteSingleContextObject
                $unregisterInstance
                $mutexDestroy
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
    void ${servicename}Service::notifyNewContext( const uint8_t serviceID ) {
        ADD_SELECTORS("${servicename}Service::notifyNewContext");
        // no need to lock -- this is called when ContextLock is in WRITE_MODE
        //ASSERTMSG( contextMapping.getHead() == Util::getMaceAddr(), "Only head node can call notifyNewContext" );
        ASSERTMSG( mace::ContextBaseClass::headContext.getCurrentMode() == mace::ContextLock::WRITE_MODE, "notifyNewContext() must be called only when head node is in ContextLock::WRITE_MODE" );

        mace::HighLevelEvent& he = ThreadStructure::myEvent();

        if( serviceID == instanceUniqueID ) { return; }
        if( he.eventType == mace::HighLevelEvent::STARTEVENT ){
          const mace::string globalContextID = "";
          // if it's a start event, the head has to create a mapping to global context
          // to prevent race condition, the global context of every service in the composition has to be created explicitly in the first event (that is, maceInit)

          std::pair< mace::MaceAddr, uint32_t > newMappingReturn = contextMapping.newMapping( globalContextID );
          const mace::ContextMapping* ctxmapCopy =  contextMapping.snapshot(  ) ; // create ctxmap snapshot
          ASSERT( ctxmapCopy != NULL );
          contextEventRecord.createContextEntry( globalContextID, newMappingReturn.second, he.eventID );
          he.setSkipID( instanceUniqueID, newMappingReturn.second, he.eventID );

          if( newMappingReturn.first == Util::getMaceAddr() ){ // the new context co-locates with the head
            mace::ContextBaseClass *globalContext = createContextObject( globalContextID, newMappingReturn.second );
            ASSERT( globalContext != NULL );
          }else{
            $remoteAllocateGlobalContext
          }
          return;
        }

        ASSERTMSG( !contextMapping.hasSnapshot( ), "The new context is not created in this service, why does it have this version of context mapping?" );
        const mace::ContextMapping* ctxmapCopy =  contextMapping.snapshot(  ) ; // create ctxmap snapshot
        ASSERT( ctxmapCopy != NULL );

        $sendAllocateContextObjectmsg
    }
    void ${servicename}Service::notifyNewEvent( const uint8_t serviceID ) {
        ADD_SELECTORS("${servicename}Service::notifyNewEvent");

        if( serviceID == instanceUniqueID ) { return; }
        // no need to lock -- this is called when ContextLock is in WRITE_MODE
        //ASSERTMSG( contextMapping.getHead() == Util::getMaceAddr(), "Only head node can call notifyNewEvent" );
        ASSERTMSG( mace::ContextBaseClass::headContext.getCurrentMode() == mace::ContextLock::WRITE_MODE, "notifyNewEvent() must be called only when head node is in ContextLock::WRITE_MODE" );

        mace::HighLevelEvent& he = ThreadStructure::myEvent();

        if( he.getEventType() == mace::HighLevelEvent::MIGRATIONEVENT ){
          // if it's a migration event and is not initiated in this service, don't update context event record
          // because the migration event will not enter this service at all.
          return;
        }

        // If the event is not created in this service, it is guaranteed the all the contexts in this service will be
        // explicitly downgraded by this event. So all later events entering this service should wait for this event
        // i.e. It is as if the event in this service starts from the global context
        const mace::string globalContext = ""; 

        contextEventRecord.updateContext( globalContext, he.eventID, he.getSkipIDStorage( instanceUniqueID ) );
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

        return serializedByteSize;
    }
END

    $this->printCtxMapUpdate($outfile);
    
    print $outfile <<END;
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
    # FIXME: some of them do not need PREPARE_FUNCTION
    map {
        #print $_->toString(methodprefix=>"${name}Service::", body => 1,selectorVar => 1, prepare => 1, nodefaults=>1) . "\n";
        #print $_->toString(noline=>1) . "\n";
        print $outfile $_->toString(methodprefix=>"${name}Service::", body => 1,selectorVar => 1, prepare => 1, nodefaults=>1);
    } $this->asyncHelperMethods(), $this->routineHelperMethods(), $this->timerHelperMethods(), $this->downcallHelperMethods(), $this->upcallHelperMethods(), $this->appUpcallDispatchMethods();
    map {
        #print $_->toString(noline=>1) . "\n";
        print $outfile $_->toString(methodprefix=>"${name}Service::", body => 1,selectorVar => 1, prepare => 0, nodefaults=>1);
    } $this->asyncLocalWrapperMethods(), $this->contextHelperMethods();
    map {
        #print $_->toString(noline=>1) . "\n";
        print $outfile $_->toString(methodprefix=>"${name}Service::", body => 1,selectorVar => 1, prepare => 0, nodefaults=>1, traceLevel=>1);
    } $this->asyncDispatchMethods() ;

    print $outfile <<END;

    //Serial Helper Demux
END

    $this->printSerialHelperDemux($outfile);

    my $applicationUpcallDeferralQueue="";
    my $hnumber = 1;
    for my $m ( $this->providedHandlerMethods() ){
        if( !$m->returnType->isVoid ){
            $hnumber++;
            next;
        }
        my $serialize = "";
        my @serializedParamName;
        if ($m->options('original')) {
            #TODO: try/catch Serialization
            my $sorigmethod = $m->options('original');
            my @oparams = $sorigmethod->params();
            for my $p ($m->params()) {
                my $op = shift(@oparams);
                if (! $op->type->eq($p->type)) {
                    my $optype = $op->type->type();
                    my $opname = $op->name;
                    my $ptype = $p->type->type();
                    my $pname = $p->name;
                    $serialize .= qq{ $optype $opname;
                                      ScopedSerialize<$optype, $ptype > __ss_$pname($opname, it->second.$pname);
                                  };
                    push @serializedParamName, $opname;
                }else{
                    push @serializedParamName, "it->second." . $op->name;
                }
            }
        }else{
            map{ push @serializedParamName, "it->second." . $_->name() } $m->params() ;
        }
        my @handlerArr = @{$m->options('class')};
        my $handler = $handlerArr[0];
        my $hname = $handler->name;
        my $iterator = "iterator";
        my $mname = $m->name;
        my $rid = $m->params()->[-1]->name();
        if ($m->isConst()) {
            $iterator = "const_iterator"
        }
        my $body = $m->body;
        my $callm = $m->name."(".join(",", @serializedParamName ).")";
        $applicationUpcallDeferralQueue .= qq#{
            std::pair< Deferred_${hnumber}_${mname}::iterator, Deferred_${hnumber}_${mname}::iterator >  range = deferred_queue_${hnumber}_${mname}.equal_range( myTicket );
            Deferred_${hnumber}_$m->{name}::iterator it;
            for( it = range.first; it != range.second; it++ ){
              $serialize
                maptype_${hname}::$iterator iter = map_${hname}.find( it->second.$rid );
                if(iter == map_${hname}.end()) {
                    //maceWarn("No $hname registered with uid %"PRIi32" for upcall $mname!", it->second.$rid );
                    $body
                    }
                else {
                    iter->second->$callm;
                }
            }
            deferred_queue_${hnumber}_${mname}.erase( range.first , range.second );
        }
        #;
        $hnumber ++;
    }

    print $outfile <<END;

    //Model checking safety methods
    $modelCheckSafety

    //Model checking liveness methods
    $modelCheckLiveness
      
        void ${name}Service::downgradeEventContext( ){
          ADD_SELECTORS("${servicename}Service::downgradeEventContext");

          mace::HighLevelEvent& myEvent = ThreadStructure::myEvent();
          const uint64_t myTicket = myEvent.getEventID();
          uint8_t commitInitiatorServiceID = 0;
          if( myEvent.eventType == mace::HighLevelEvent::ENDEVENT ){
            commitInitiatorServiceID = ThreadStructure::getServiceInstance();
          }
          ThreadStructure::ScopedServiceInstance si( instanceUniqueID );
          ThreadStructure::ScopedContextID sc( ContextMapping::getHeadContext() );
          // (1) move the block/write/read lines down to the bottom of the context hierarchy.
          // send the commit message to the read-line cut 

          switch( myEvent.eventType ){
            case mace::HighLevelEvent::NEWCONTEXTEVENT:
              return;
              break;
            case mace::HighLevelEvent::ENDEVENT:
              if( commitInitiatorServiceID != instanceUniqueID ){
                return;
              }
              break;
            case mace::HighLevelEvent::STARTEVENT:
              return;
              break;
          }
          // if new-context-event, all contexts will be entered, no need to commit contexts again
          bool enteredService = ThreadStructure::isEventEnteredService();
          const mace::ContextMapping& snapshotMapping = contextMapping.getSnapshot();
          mace::ReadLine rl( snapshotMapping ); 
          if( !enteredService && rl.getCut().empty() ){ // this means the event did not enter this service.
            
            mace::vector< uint32_t > nextHops;
            uint32_t globalContextID = snapshotMapping.findIDByName("");
            nextHops.push_back( globalContextID );
            __event_commit_context commit_msg( nextHops, myTicket, myEvent.eventType, myEvent.eventContextMappingVersion, myEvent.eventSkipID, false, false, 0 );
            ASYNCDISPATCH( mace::ContextMapping::getNodeByContext(  snapshotMapping, globalContextID ), __ctx_dispatcher , __event_commit_context , commit_msg )
          }else{

            mace::map< mace::MaceAddr , mace::vector< uint32_t > > nextHops;
            for( mace::list< uint32_t >::const_iterator cutIt = rl.getCut().begin(); cutIt != rl.getCut().end(); cutIt ++ ){
              const uint32_t childContextID = *cutIt;
              const mace::MaceAddr& nextHopAddr = mace::ContextMapping::getNodeByContext( snapshotMapping, childContextID );
              nextHops[ nextHopAddr ].push_back( childContextID );
            }
            mace::map< mace::MaceAddr , mace::vector< uint32_t > >::iterator addrIt;
            for( addrIt = nextHops.begin(); addrIt != nextHops.end(); addrIt++ ){

              __event_commit_context commit_msg( addrIt->second, myTicket, myEvent.eventType, myEvent.eventContextMappingVersion, myEvent.eventSkipID, false, false, 0 );
              ASYNCDISPATCH( addrIt->first, __ctx_dispatcher , __event_commit_context , commit_msg )
            }
          }
        }

        void ${name}Service::commitEvent( const uint64_t myTicket ){
          ADD_SELECTORS("${servicename}Service::commitEvent");
          ThreadStructure::ScopedServiceInstance si( instanceUniqueID );
          ThreadStructure::ScopedContextID sc( ContextMapping::getHeadContext() );
          mace::HighLevelEvent& myEvent = ThreadStructure::myEvent();
          macedbg(1)<<"This service is ready to commit globally the event "<< myEvent <<Log::endl;
          // (2.2) upcalls into the application
          $applicationUpcallDeferralQueue
          // (3) notify the next event(if there's any being blocked) to proceed the application upcalls
          std::map<uint64_t, pthread_cond_t*>::iterator it = appUpcallCond.find( myEvent.eventID );
          if( it != appUpcallCond.end() ){
            ScopedLock sl( appUpcallMutex );
            pthread_cond_signal( it->second );
          }
 
        }
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
#include "lib/ReadLine.h"
#include "lib/AccessLine.h"
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

    foreach my $timer ($this->timers()) {
	print $outfile $timer->toString($this->name()."Service",
					traceLevel => $this->traceLevel())."\n";
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
    map { push @subcontexts, $_->subcontexts() } @{$contexts};
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
    uint8_t instanceUniqueID;

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
    my $declareDeferralUpcallQueue = "";
    my $hnumber = 1;

    for( $this->providedHandlerMethods() ){
        my $name = $_->name;
        if( $_->returnType->isVoid ){
            $declareDeferralUpcallQueue .= qq#typedef std::multimap<uint64_t, DeferralUpcallQueue_${hnumber}_$name> Deferred_${hnumber}_$name;
                Deferred_${hnumber}_$name deferred_queue_${hnumber}_$name;
                #;
        }
        $hnumber++;
    }
    my $defer_routineDeclarations = join("\n", map{"void ".$_->toString(noreturn=>1, methodprefix=>'defer_').";"} $this->routineDeferMethods());
    my $stateVariables = join("\n", map{$_->toString(nodefaults => 1, mutable => 1).";"} $this->state_variables(), $this->onChangeVars()); #nonTimer -> state_var
    my $providedMethodDeclares = join("\n", map{
      #if( $_->name ne "localAddress" ){
      #  $_->isConst(0);
      #}
      $_->toString('nodefaults' => 1).";"
    } $this->providedMethodsAPI());
    my $usedHandlerDeclares = join("\n", map{$_->toString('nodefaults' => 1).";"} $this->usesHandlerMethodsAPI());
    my $serviceVars = join("\n", map{$_->toServiceVarDeclares()} $this->service_variables());
    my $constructorParams = join("\n", map{$_->toString('nodefaults' => 1).';'} $this->constructor_parameters());
    my $timerDeclares = join("\n", map{my $t = $_->name(); qq/ class ${t}_MaceTimer;\n${t}_MaceTimer &$t; /;} $this->timers());
    # chuangw: a temporary hack
    my $contextDeclares = join("\n", map{ $_->toDeclareString(); } ($this->contexts(),${ $this->contexts() }[0]->subcontexts() )  );
    #my $contextDeclares = join("\n", map{ $_->toDeclareString(); } ($this->contexts(), $this->contexts()->subcontexts() )  );
    my $timerMethods = join("\n", map{$_->toString().";"} $this->timerMethods());
    my $timerHelperMethods = join("\n", map{$_->toString().";"} $this->timerHelperMethods());
    my $asyncMethods = join("\n", map{$_->toString().";"} $this->asyncMethods());
    my $asyncHelperMethods = join("\n", map{$_->toString().";"} $this->asyncHelperMethods(), $this->asyncDispatchMethods(), $this->asyncLocalWrapperMethods());
    my $appUpcallHelperMethods = join("\n", map{$_->toString().";"} $this->appUpcallDispatchMethods() );
    
    my $contextHelperMethods = join("\n",  map{$_->toString().";"} $this->contextHelperMethods());
    my $routineHelperMethods = join("\n",  map{$_->toString().";"} $this->routineHelperMethods());
    my $providesSerialDeclares = join("\n", map{$_->toString("noid" => 0).";"} $this->providedMethodsSerials());
    my $usesHandlersSerialDeclares = join("\n", map{$_->toString("noid" => 0).";"} $this->usesHandlerMethodsSerials());
    my $downcallHelperMethods = join("\n", map{$_->toString("methodprefix"=>'downcall_', "noid" => 0, "novirtual" => 1).";"} $this->usesClassMethods());
    my $ctxdowncallHelperMethods = join("\n", map{$_->toString().";"} $this->downcallHelperMethods());
    my $defer_downcallHelperMethods = join("\n", map{"void ".$_->toString(noreturn=>1, methodprefix=>'defer_downcall_', noid => 0, novirtual => 1).";"} $this->downcallDeferMethods());
    my $upcallHelperMethods = join("\n", map{$_->toString('methodprefix'=>'upcall_', "noid" => 0, "novirtual" => 1).";"} $this->providedHandlerMethods());
    my $ctxupcallHelperMethods = join("\n", map{$_->toString().";"} $this->upcallHelperMethods());
    my $defer_upcallHelperMethods = join("\n", map{"void ".$_->toString(noreturn=>1,methodprefix=>'defer_upcall_', noid=> 0, novirtual => 1).";"} $this->upcallDeferMethods());
    my $derives = join(", ", map{"public virtual $_"} (map{"${_}ServiceClass"} $this->provides() ), ($this->usesHandlers()) );
    my $constructor = $name."Service(".join(", ", (map{$_->serviceclass."ServiceClass& __".$_->name} grep(not($_->intermediate()), $this->service_variables)), (map{$_->type->toString()." _".$_->name} $this->constructor_parameters()), "bool ___shared = true" ).");";
    $constructor .= "\n${name}Service(const ${name}Service& other);";
    my $accessorMethods = "";
    #my $accessorMethods = "const state_type& read_state() const;\n";
    #$accessorMethods .= join("\n", map { my $n = $_->name();if( $n =~ m/^__internal_/ ){ qq// }else { my $t = $_->type()->toString(paramconst => 1, paramref => 1); qq/ $t read_$n() const; / } } $this->state_variables());

    my $registrationDeclares = join("\n", map{my $n = $_->name(); "typedef std::map<int, $n* > maptype_$n;
                                                                 maptype_$n map_$n;
                                                                 std::set< int > apphandler_$n;
                                                                 "} $this->providedHandlers);
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
    class __ServiceStackEvent__;
    class __ScopedRoutinePrep__;
    class ServiceTester;
    class ${name}Service : public BaseMaceService, public virtual mace::PrintPrintable, public virtual Serializable, public virtual BinaryLogObject, $derives $registration
{
  private:
    $changeTrackerFriend
    friend class __ServiceStackEvent__;
    friend class ServiceTester;
    friend class __ScopedRoutinePrep__;
    $mergeFriend
    $autoTypeFriend
    int __inited;
    uint8_t instanceUniqueID;
    pthread_mutex_t eventRequestBufferMutex;
    mace::hash_map< uint32_t, mace::pair<mace::string, mace::string > > unfinishedEventRequest;
    mutable pthread_mutex_t appUpcallMutex;
    mutable std::map<uint64_t, pthread_cond_t*> appUpcallCond;
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
    void notifyNewContext( const uint8_t serviceID ) ;
    void notifyNewEvent( const uint8_t serviceID ) ;

    void loadContextMapping(const mace::map<MaceAddr,mace::list<mace::string > >& servContext);
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

    // Deferral upcall queue
    $declareDeferralUpcallQueue
    //State Variables
    $stateVariables

    //Timer Vars
    $timerDeclares

    mace::hash_map< uint32_t, mace::ContextBaseClass*, mace::SoftState > ctxobjIDMap;
    mace::hash_map< mace::string, mace::ContextBaseClass*, mace::SoftState > ctxobjNameMap;
    //Context Declaration
    $contextDeclares

    //Timer Methods
    $timerMethods

    //Timer Helper Methods
    $timerHelperMethods

    //Async Methods
    $asyncMethods

    //Async Helper Methods
    $asyncHelperMethods

    //Context Helper Methods
    $contextHelperMethods

    //Routine Helper Methods
    $routineHelperMethods

    //Merge Class Declarations
    $mergeDeclare

    //Downcall and Upcall helper methods
    $downcallRegistration
    $downcallHelperMethods
    $upcallHelperMethods
    $ctxdowncallHelperMethods
    $ctxupcallHelperMethods

    // Helper methods for deferred upcalls into application
    $appUpcallHelperMethods

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

    void downgradeEventContext( );
    void commitEvent( const uint64_t myTicket );

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
        method_type=>Mace::Compiler::AutoType::FLAG_CONTEXT);
        for( @{ $_->{param} } ){
            my $t = Mace::Compiler::Type->new(type => $_->{type} );
            my $p = Mace::Compiler::Param->new(name=> $_->{name}, filename=>__FILE__, line=>__LINE__, type=>$t);
            $p->type->isConst(0);
            $p->type->isConst1(0);
            $p->type->isConst2(0);
            $p->type->isRef(0);
            $msgtype->push_fields($p);
        }
        #if( $this->hasContexts == 0 ){
        #    $this->push_auto_types( $msgtype );
        #}else{
           $this->push_messages( $msgtype );
        #}
    }

}


sub addContextMigrationTransitions {
    my $this = shift;
    my $handlers = shift;
    # generate message handler for handling context migration

    my $transitionNum = $this->count_transitions();

    my $ptype1 = Mace::Compiler::Type->new(isConst=>1, isConst1=>1, isConst2=>0, type=>'MaceKey', isRef=>1);
    my $param1 = Mace::Compiler::Param->new(filename=>__FILE__,hasDefault=>0,name=>'src',type=>$ptype1,line=>__LINE__);
    my $param2 = Mace::Compiler::Param->new(filename=>__FILE__,hasDefault=>0,name=>'dest',type=>$ptype1,line=>__LINE__);

    my $ptype3 = Mace::Compiler::Type->new(isConst=>1, isConst1=>1, isConst2=>0, type=>'MaceAddr', isRef=>1);
    my $param3 = Mace::Compiler::Param->new(filename=>__FILE__,hasDefault=>0,name=>'src',type=>$ptype3,line=>__LINE__);
    my $adReturnType = Mace::Compiler::Type->new(type=>"void",isConst=>0,isConst1=>0,isConst2=>0,isRef=>0);
    for( @{ $handlers } ){
        # create wrapper func
        my $adName;
        if( defined( $_->{func} ) ){
          $adName = "__ctx_helper_fn_" . $_->{func};
        }else{
          $adName = "__ctx_helper_fn_" . $_->{param};
        }
        my $adParamType = Mace::Compiler::Type->new( type => "$_->{param}", isConst => 1,isRef => 1 );
        my $adMethod = Mace::Compiler::Method->new( name => $adName, 
          body => "{
            $_->{body}
            //mace::AgentLock::checkTicketUsed();
          }", returnType=> $adReturnType);
        my $msgParam = Mace::Compiler::Param->new( name => "msg", type => $adParamType );
        $adMethod->push_params( $msgParam );
        if( !defined( $_->{func} ) ){
          $adMethod->push_params( $param3 );
        }
        $this->push_asyncDispatchMethods( $adMethod  );

        next if( not $this->hasContexts() and not $this->useTransport() ); # if no contexts are defined, don't define deliver upcall transition because the service may not have used Transport
        next if( defined $_->{func} );
        my $apiBody = qq/
            $adName( msg, src.getMaceAddr()  );
        /;
        my $rtype = Mace::Compiler::Type->new();
        my $m = Mace::Compiler::Method->new(
            body => $apiBody, #$item{MethodTerm}->toString()
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
        $m->push_params( $msgParam );
        # chuangw: don't ContextLock on the message handler
        $m->options('nocontext',1);
        # chuangw: assuming the lower level service is Trasnport
        my $t = Mace::Compiler::Transition->new(name => "deliver", #$item{Method}->name(), 
            startFilePos => -1, #($thisparser->{local}{update} ? -1 : $item{StartPos}),
            columnStart => -1,  #$item{StartCol}, 
            type => "upcall", 
            method => $m,
            startFilePos => -1,
            columnStart => '-1',
            transitionNum => $transitionNum++ 
        );
        $this->push_transitions( $t);
    }
}
sub addContextHandlers {
    my $this = shift;

    my $name = $this->name();
    my $eventRoute = "";
    if( $this->hasContexts()  ){
      $eventRoute = "
        ___ctx.route( destNode, eventreq.first, __ctx );
      ";
    }else{
      $eventRoute = "";
    }
    my $sendAllocateContextObjectmsg;
    if( $this->hasContexts() == 0 ){
        $sendAllocateContextObjectmsg = "";
    }else{
        $sendAllocateContextObjectmsg = "
const mace::ContextMapping* ctxmapCopy =  contextMapping.snapshot(  ) ; // create ctxmap snapshot
mace::map< uint32_t, mace::string > emptyContextSet;

AllocateContextObject allocateCtxMsg( newHead, emptyContextSet, newEvent.getEventID(), *ctxmapCopy, 0 );
// send message to the new head about the latest context mapping
ASYNCDISPATCH( newHead , __ctx_dispatcher, AllocateContextObject , allocateCtxMsg );

const mace::map < MaceAddr,uint32_t >& physicalNodes = contextMapping.getAllNodes(); 
for( mace::map<MaceAddr, uint32_t>::const_iterator nodeIt = physicalNodes.begin(); nodeIt != physicalNodes.end(); nodeIt ++ ){ // chuangw: this message has to be sent to all nodes of the same logical node to update the context mapping.
  ASYNCDISPATCH( nodeIt->first, __ctx_dispatcher, AllocateContextObject, allocateCtxMsg )
}
            ";
    }
    my @handlerContext = (
        {
            param => "__event_create",
            body  => qq#{
              if( mace::HighLevelEvent::isExit ) {
                mace::AgentLock::nullTicket();
                return;
              }
              __event_create_head m(msg.extra, msg.counter, src);
              HeadEventDispatch::HeadEventTP::executeEvent( this, (HeadEventDispatch::eventfunc)&${name}_namespace::${name}Service::__ctx_dispatcher, (void*) new __event_create_head(m) );
            }#
        },{
            param => "__event_create_head",
            body  => qq#{
              if( mace::HighLevelEvent::isExit ) {
                mace::AgentLock::nullTicket();
                return;
              }
              asyncHead( msg.extra, mace::HighLevelEvent::ASYNCEVENT );

              const MaceAddr& targetContextAddr = contextMapping.getNodeByContext( msg.extra.targetContextID );
              __event_create_response response( ThreadStructure::myEvent(), msg.counter, targetContextAddr );
              ASYNCDISPATCH( msg.src, __ctx_dispatcher, __event_create_response, response );
            }#
        },{
            param => "__event_create_response",
            body  => qq#{
              mace::AgentLock::nullTicket();
              // read from buffer
              
              ScopedLock sl( eventRequestBufferMutex );
              maceout<<"Event "<< msg.event.eventID << ", counter = "<< msg.counter <<" is sent to "<< msg.targetAddress <<Log::endl;
              mace::hash_map< uint32_t, mace::pair<mace::string, mace::string > >::iterator ueIt = unfinishedEventRequest.find( msg.counter );
              ASSERT( ueIt != unfinishedEventRequest.end() );
              mace::pair< mace::string, mace::string >& eventreq = ueIt->second;
              eventreq.first.erase(  eventreq.first.size() - eventreq.second.size() );
              __asyncExtraField extra;
              mace::deserialize( eventreq.second, &extra);
              extra.event = msg.event;
              extra.isRequest = false;
              mace::string extra_str;
              mace::serialize( extra_str , &extra );
              eventreq.first.append( extra_str );

              const mace::MaceKey destNode( mace::ctxnode, msg.targetAddress  );
              $eventRoute
              //___ctx.route( destNode, eventreq.first, __ctx );
              unfinishedEventRequest.erase( ueIt );
              sl.unlock();
            }#
        },{
            param => "__event_exit_committed",
            body  => qq#{
              // this message is supposed to be received by non-head nodes.
              mace::AgentLock::nullTicket();
              // if the main thread is blocking in maceExit(), wake it up
              mace::HighLevelEvent::proceedExit();
              // if maceExit() has not been called at this node....?
            }#
        },{
            param => "__event_enter_context",
            body => qq#{
    mace::AgentLock::nullTicket();
    ThreadStructure::setEvent( msg.event );
    for( mace::vector< uint32_t >::const_iterator ctxidIt = msg.contextIDs.begin(); ctxidIt != msg.contextIDs.end(); ctxidIt++ ){
      mace::ContextBaseClass * thisContext = getContextObjByID( *ctxidIt );
      mace::ContextLock __contextLock( *thisContext, mace::ContextLock::WRITE_MODE); // acquire context lock. 
    }
            }#
        },{
            param => "__event_commit",
            body => qq#{
    /* the commit msg is sent to head, head send to global context and goes down the entire context tree to downgrade the line.
    after that, the head performs commit which effectively releases deferred messages and application upcalls */
    mace::AgentLock::nullTicket();
    //ASSERT( contextMapping.getHead() == Util::getMaceAddr() );
    HeadEventDispatch::HeadEventTP::commitEvent( msg.eventID, msg.eventType, msg.eventMessageCount );
            }#
        },{
            param => "__event_commit_context",
            body => qq#{
    mace::AgentLock::nullTicket();

    mace::HighLevelEvent currentEvent( msg.eventID );
    ThreadStructure::setEvent( currentEvent );
    if( msg.isresponse ){
        pthread_mutex_lock( &mace::ContextBaseClass::eventCommitMutex );
        pthread_cond_signal( mace::ContextBaseClass::eventCommitConds[msg.eventID] );
        pthread_mutex_unlock( &mace::ContextBaseClass::eventCommitMutex );
        return;
    }
    ThreadStructure::setEventContextMappingVersion ( msg.eventContextMappingVersion );
    ThreadStructure::ScopedServiceInstance si( instanceUniqueID );
    ThreadStructure::myEvent().eventSkipID = msg.eventSkipID;
    const mace::ContextMapping& snapshotMapping = contextMapping.getSnapshot();
    mace::vector< uint32_t >::const_iterator nextHopIt;
    mace::map< mace::MaceAddr , mace::vector< uint32_t > > nextHops;
    for(  nextHopIt = msg.nextHops.begin(); nextHopIt != msg.nextHops.end(); nextHopIt++ ){
      const uint32_t thisContextID = *nextHopIt;

      if( msg.hasException && msg.exceptionContextID == thisContextID ){ continue; }

      mace::ContextBaseClass * thisContext = getContextObjByID( thisContextID);
      mace::ContextLock cl( *thisContext, mace::ContextLock::NONE_MODE );
      
      const mace::set< uint32_t > & subcontexts = mace::ContextMapping::getChildContexts( snapshotMapping, thisContextID );
      for( mace::set< uint32_t >::const_iterator subctxIter= subcontexts.begin(); subctxIter != subcontexts.end(); subctxIter++ ){
        const uint32_t nextHop = *subctxIter;
        const mace::MaceAddr& nextHopAddr = mace::ContextMapping::getNodeByContext( snapshotMapping, nextHop );
        ASSERT( nextHopAddr != SockUtil::NULL_MACEADDR );
        nextHops[ nextHopAddr ].push_back( nextHop );
      }
    }
    mace::map< mace::MaceAddr , mace::vector< uint32_t > >::iterator addrIt;
    for( addrIt = nextHops.begin(); addrIt != nextHops.end(); addrIt++ ){
      __event_commit_context commitMsg( addrIt->second, msg.eventID,ThreadStructure::myEvent().eventType, msg.eventContextMappingVersion, msg.eventSkipID, false, msg.hasException, msg.exceptionContextID );
      ASYNCDISPATCH( addrIt->first , __ctx_dispatcher, __event_commit_context , commitMsg );
    }
            }#
        },
        {
            param => "__event_snapshot",
            body => qq#{
    // store the snapshoeventt
    mace::AgentLock::nullTicket();
    pthread_mutex_lock(&mace::ContextBaseClass::eventSnapshotMutex );
    std::pair< uint64_t, mace::string > key( msg.event.eventID, msg.ctxID );
    std::map<mace::string, mace::string>& snapshots = mace::ContextBaseClass::eventSnapshotStorage[ key ];
    snapshots[ msg.snapshotContextID ] = msg.snapshot;
    // if the event is waiting in the target context, notify it.
    std::map<uint64_t, pthread_cond_t*>::iterator condIt = mace::ContextBaseClass::eventSnapshotConds.find( msg.event.eventID );
    if( condIt !=  mace::ContextBaseClass::eventSnapshotConds.end() ){
        pthread_cond_signal( condIt->second );
    }
    pthread_mutex_unlock(&mace::ContextBaseClass::eventSnapshotMutex );
            }#
        },{
            param => "__event_downgrade_context",
            body => qq#{
        mace::AgentLock::nullTicket();
        if( msg.isresponse ){
          mace::ScopedContextRPC::wakeup( msg.eventID );
        }else{
          mace::HighLevelEvent currentEvent( msg.eventID );
          ThreadStructure::setEvent( currentEvent );
    // XXX: make sure I'm not holding any lock
          mace::ContextBaseClass *thisContext = getContextObjByName( msg.contextID);
          mace::ContextLock cl( *thisContext, mace::ContextLock::READ_MODE );
          __event_downgrade_context dgmsg( "", msg.eventID, true );
        }

            }#
        },{
            param => "__event_evict",
            body => qq#{ // this message is received by the head.
        mace::AgentLock alock( mace::AgentLock::WRITE_MODE );
        
        // TODO: determine the contexts on the node
        mace::list< mace::string > contexts;
        // use the latest context mapping version
        contextMapping.getContextsOfNode( src, contexts );

        // TODO: call requestContextMigration() to migrate the contexts
        for( mace::list< mace::string >::iterator ctxIt = contexts.begin(); ctxIt != contexts.end(); ctxIt++ ){
          // app.getServiceObject()->requestContextMigration( serviceID, migctxIt->first, migctxIt->second, false );
          requestContextMigration( instanceUniqueID, *ctxIt,src, false );
        }

        // go to the lower services

        alock.downgrade( mace::AgentLock::NONE_MODE );
            }#
        },{
            param => "__event_new_head_ready",
            body => qq#{
mace::AgentLock lock( mace::AgentLock::WRITE_MODE ); // global lock is used to ensure new events are created in order
// TODO: make sure it's the old head

// create 'head migration' event. This event contains the new context mapping where the new head is the head
mace::HighLevelEvent& newEvent = ThreadStructure::myEvent( );
newEvent.newEventID( mace::HighLevelEvent::HEADMIGRATIONEVENT );
lock.downgrade( mace::AgentLock::NONE_MODE );

{
  mace::ContextLock c_lock( mace::ContextBaseClass::headContext, mace::ContextLock::WRITE_MODE );

  newEvent.initialize(  );

  // update context mapping information
  const MaceAddr newHead = src;

  contextMapping.newHead( newHead );

  // this node will also likely inform the scheduler the address change of the logical node.

  // inform the change
  $sendAllocateContextObjectmsg

  // set a flag to indicate future event requests to this old head should be forward to the new head
  // --> set head status to "migrating"
  // --> set the head migrating event id
  HeadEventDispatch::HeadMigration::setState( HeadEventDispatch::HeadMigration::HEAD_STATE_MIGRATING );
  HeadEventDispatch::HeadMigration::setMigrationEventID( newEvent.getEventID() );
  HeadEventDispatch::HeadMigration::setNewHead( newHead );



  c_lock.downgrade( mace::ContextLock::NONE_MODE );
}
            }#
        },{
            param => "__event_routine_return",
            body => qq#{
mace::AgentLock::nullTicket();

ThreadStructure::setEventContextMappingVersion ( msg.event.eventContextMappingVersion );
mace::ScopedContextRPC::wakeupWithValue( msg.event.eventID, msg.returnValue );
            }#
        }
        
        
    );
    my @msgContextMessage = (
        { 
            name => "__event_create",
            param => [ {type=>"__asyncExtraField",name=>"extra"}, {type=>"uint64_t",name=>"counter"}   ]
        },
        { 
            name => "__event_create_head",
            param => [ {type=>"__asyncExtraField",name=>"extra"}, {type=>"uint64_t",name=>"counter"}, {type=>"MaceAddr",name=>"src"}   ]
        },
        {
            name => "__event_create_response",
            param => [ {type=>"mace::HighLevelEvent",name=>"event"}, {type=>"uint32_t",name=>"counter"}, {type=>"MaceAddr",name=>"targetAddress"}   ]
        },
        { 
            name => "__event_exit_committed",
            param => [    ]
        },
        { 
            name => "__event_enter_context",
            param => [ {type=>"mace::HighLevelEvent",name=>"event"}, {type=>"mace::vector< uint32_t >",name=>"contextIDs"}   ]
        },
        { 
            name => "__event_commit",
            #param => [ {type=>"mace::HighLevelEvent",name=>"event"}   ]
            param => [ {type=>"uint64_t",name=>"eventID"}, {type=>"int8_t",name=>"eventType"}, {type=>"uint32_t",name=>"eventMessageCount"}   ]
        },
        { 
            name => "__event_commit_context",
            param => [ {type=>"mace::vector< uint32_t >",name=>"nextHops"}, {type=>"uint64_t",name=>"eventID"}, {type=>"int8_t",name=>"eventType"}, {type=>"uint64_t",name=>"eventContextMappingVersion"}, {type=>"mace::map< uint8_t, mace::map< uint32_t, uint64_t> >",name=>"eventSkipID"}, {type=>"bool",name=>"isresponse"}, {type=>"bool",name=>"hasException"}, {type=>"uint32_t",name=>"exceptionContextID"}   ]
        },
        {
            name => "__event_snapshot",
            param => [ {type=>"mace::HighLevelEvent",name=>"event"}, {type=>"mace::string",name=>"ctxID"}, {type=>"mace::string",name=>"snapshotContextID"}, {type=>"mace::string",name=>"snapshot"}   ]
        },
        {
            name => "__event_downgrade_context",
            param => [ {type=>"mace::string",name=>"contextID"}, {type=>"uint64_t",name=>"eventID"}, {type=>"bool",name=>"isresponse"}   ]
        },
        {
            name => "__event_evict",
            param => [    ]
        },
        {
            name => "__event_new_head_ready",
            param => [    ]
        },
        {
            name => "__event_routine_return",
            param => [ {type=>"mace::string",name=>"returnValue"}, {type=>"mace::HighLevelEvent",name=>"event"}   ]
        }
    );
    $this->addContextMigrationMessages( \@msgContextMessage );
    $this->addContextMigrationTransitions(\@handlerContext );
}
sub addContextMigrationHelper {
    my $this = shift;
    #my $hasContexts = shift;

    return if( $this->hasContexts() == 0 );
    my @handlerContextMigrate = (
        {
          param => "AllocateContextObject", 
          body => qq#{
          mace::AgentLock alock( mace::AgentLock::WRITE_MODE );
          // Context mapping is shared process-wide. Protect context mapping structure with AgentLock

          mace::HighLevelEvent currentEvent( msg.eventID );
          ThreadStructure::setEvent( currentEvent );

          ThreadStructure::setEventContextMappingVersion();
          if( contextMapping.getHead() == Util::getMaceAddr() ){
            ASSERTMSG( contextMapping.hasSnapshot( msg.eventID )  , "This physical node is the head node but yet it does not have this version of snapshot!" );
          }else{
            ASSERTMSG( !contextMapping.hasSnapshot( msg.eventID ) , "This physical node is not supposed to have this version of snapshot when migration event starts!" );
            contextMapping.snapshotInsert( msg.eventID, msg.contextMapping );
            contextMapping = msg.contextMapping; 
          }  

          if( msg.destNode == Util::getMaceAddr() ){ 
            for( mace::map< uint32_t, mace::string >::const_iterator ctxIt = msg.ContextID.begin(); ctxIt != msg.ContextID.end(); ctxIt++ ){
              mace::ContextBaseClass *thisContext = createContextObject( ctxIt->second, ctxIt->first ); // create context object
              ASSERTMSG( thisContext != NULL, "createContextObject() returned NULL!");
              ASSERTMSG( thisContext->getNowServing() == msg.eventID, "Context already exist!" );
            }

            if( msg.eventType == 1 ){
              AllocateContextObjectResponse response( src, msg.eventID );
              ASYNCDISPATCH( src, __ctx_dispatcher, AllocateContextObjectResponse, response )
            }
          }
          alock.downgrade( mace::AgentLock::NONE_MODE );
  }#
        },
        {
          param => "AllocateContextObjectResponse", 
          body => qq#{

          //ASSERT( contextMapping.getHead() == Util::getMaceAddr() );

          // wake up the head to proceed with dynamic context migration
          ScopedLock sl( ContextObjectCreationMutex );

          pthread_cond_signal( &ContextObjectCreationCond  );

          sl.unlock();
          mace::AgentLock::nullTicket();
  }#
        },
        {
            param => "ContextMigrationRequest",
            body => qq#{
            // TODO: update context mapping.
    ASSERT( !msg.rootOnly || (msg.nextHops.size() == 1 && msg.nextHops[0].compare( msg.ctxId ) == 0 ) );
    mace::AgentLock alock( mace::AgentLock::WRITE_MODE );
    ASSERT( contextMapping.hasSnapshot( msg.prevContextMapVersion ) ); // make sure this node has the previous version of context mapping
    alock.downgrade( mace::AgentLock::NONE_MODE );

    ThreadStructure::setEvent( msg.event );
    mace::HighLevelEvent& migrationEvent = ThreadStructure::myEvent();
    ThreadStructure::ScopedServiceInstance si( instanceUniqueID );
    
    // set event context mapping version to use the old mapping (before migration )
    ThreadStructure::setEventContextMappingVersion( msg.prevContextMapVersion );
    const mace::ContextMapping& ctxmapSnapshot = contextMapping.getSnapshot() ;

    mace::vector< mace::string >::const_iterator nextHopIt;
    bool isRoot = false;
    mace::map< mace::MaceAddr , mace::vector< mace::string > > nextHops;
    for( nextHopIt = msg.nextHops.begin(); nextHopIt != msg.nextHops.end(); nextHopIt ++ ){
      const mace::string& thisContextID = *nextHopIt;
      if( isRoot == false && thisContextID == msg.ctxId ){ isRoot = true;}

      mace::ContextBaseClass *thisContext = getContextObjByName( thisContextID); // assuming context object already exists and this operation does not create new object.
      mace::string contextData;
      mace::ContextLock ctxlock( *thisContext, mace::ContextLock::WRITE_MODE );
      copyContextData( thisContext, contextData );
      TransferContext m( thisContextID, thisContext->getID(),contextData, msg.event.getEventID(), src, false);
      const mace::MaceKey destNode( mace::ipv4, msg.dest  );
      downcall_route( destNode , m  );

      // If the entire context subtree will be migrated, send message to child contexts
      if( ! msg.rootOnly ){
        ctxlock.downgrade( mace::ContextLock::NONE_MODE );
        eraseContextData( thisContext );// erase the context from this node.
        const mace::set< uint32_t > & subcontexts = mace::ContextMapping::getChildContexts( ctxmapSnapshot, thisContextID );
        for( mace::set< uint32_t >::const_iterator subctxIter= subcontexts.begin(); subctxIter != subcontexts.end(); subctxIter++ ){
          const mace::string& nextHop  = mace::ContextMapping::getNameByID( ctxmapSnapshot, *subctxIter);
          const mace::MaceAddr& nextHopAddr = mace::ContextMapping::getNodeByContext( ctxmapSnapshot, *subctxIter );
          ASSERT( nextHopAddr != SockUtil::NULL_MACEADDR );
          nextHops[ nextHopAddr ].push_back( nextHop );
        }
      }
    }

    if( msg.rootOnly ){
      ASSERT( isRoot );
      ThreadStructure::ScopedContextID sc( msg.ctxId );
      eventFinish();
      mace::ContextBaseClass *thisContext = getContextObjByName( msg.ctxId);
      eraseContextData( thisContext );// erase the context from this node.
    }else{
      mace::map< mace::MaceAddr , mace::vector< mace::string > >::iterator addrIt;
      for( addrIt = nextHops.begin(); addrIt != nextHops.end(); addrIt++ ){
          ContextMigrationRequest nextmsg(msg.ctxId, msg.dest, msg.rootOnly, msg.event.getEventID(), msg.prevContextMapVersion, addrIt->second );
          ASYNCDISPATCH( addrIt->first , __ctx_dispatcher, ContextMigrationRequest , nextmsg );
      }
      if( isRoot ){
        __event_commit commitRequest( migrationEvent.eventID, migrationEvent.eventType, migrationEvent.eventMessageCount  );
        ASYNCDISPATCH( contextMapping.getHead(), __ctx_dispatcher , __event_commit , commitRequest )
      }
    }

  }#
        },
        {
            param => "TransferContext",
            body => qq#{
    mace::AgentLock alock( mace::AgentLock::WRITE_MODE);
    /*if( msg.isresponse ){
      mace::ScopedContextRPC::wakeup(msg.eventId);
      return;
    }*/
    
    mace::ContextBaseClass* thisContext = getContextObjByName(msg.ctxId);
    
    alock.downgrade( mace::AgentLock::NONE_MODE );

    ThreadStructure::ScopedServiceInstance si( instanceUniqueID );
    ThreadStructure::myEvent().eventID = msg.eventId;
    ThreadStructure::myEvent().setSkipID( instanceUniqueID , msg.ctxNId, msg.eventId );
    ASSERT( thisContext->getNowServing() == msg.eventId );
    // create object using name string
    mace::deserialize( msg.checkpoint, thisContext );

    // local commit.
    // notice that the same event has also already downgraded the original context object copy.
    mace::ContextLock c_lock( *thisContext, mace::ContextLock::WRITE_MODE );
    c_lock.downgrade( mace::ContextLock::NONE_MODE );
    
    /*mace::string dummyContextData;
    TransferContext m(msg.ctxId, dummyContextData , msg.eventId, msg.parentContextNode,  true);
    ASYNCDISPATCH( src , __ctx_dispatcher , TransferContext , m )*/
}#
        },

    );
    my @msgContextMigrateRequest = (
        {
            name => "AllocateContextObject",
            param => [ {type=>"MaceAddr",name=>"destNode"}, {type=>"mace::map< uint32_t, mace::string >",name=>"ContextID"}, {type=>"uint64_t",name=>"eventID" }, {type=>"mace::ContextMapping",name=>"contextMapping"}, {type=>"int8_t", name=>"eventType"}  ]
        },
        {
            name => "AllocateContextObjectResponse",
            param => [ {type=>"MaceAddr",name=>"destNode"}, {type=>"uint64_t",name=>"eventID" } ]
        },
        {
            name => "ContextMigrationRequest",
            param => [ {type=>"mace::string",name=>"ctxId"}, {type=>"MaceAddr",name=>"dest"}, {type=>"bool",name=>"rootOnly" }, {type=>"mace::HighLevelEvent",name=>"event" }, {type=>"uint64_t",name=>"prevContextMapVersion" }, {type=>"mace::vector< mace::string >",name=>"nextHops" }   ]
        },
        {
            name => "TransferContext",
            param => [ {type=>"mace::string",name=>"ctxId"}, {type=>"uint32_t",name=>"ctxNId"}, {type=>"mace::string",name=>"checkpoint"}, {type=>"uint64_t",name=>"eventId" }, {type=>"MaceAddr",name=>"parentContextNode" }, {type=>"bool",name=>"isresponse" }   ]
        },
        
    );

    $this->addContextMigrationMessages( \@msgContextMigrateRequest );
    $this->addContextMigrationTransitions(\@handlerContextMigrate);
=begin

    // notify the parent context node --->>>??
    //ContextMigrationResponse response(msg.ctxId, msg.eventId  );
        {
            name => "ContextMigrationResponse",
            param => [ {type=>"mace::string",name=>"ctxId"},  {type=>"uint64_t",name=>"eventId" }   ]
        },
        {
            param => "ContextMigrationResponse",
            body => qq#{
            /* FIXME: not need at all? */
    /*
    mace::AgentLock::nullTicket();
    pthread_mutex_lock( &mace::ContextBaseClass::__internal_ContextMutex );
    // TODO: update the entire subtree?
    contextMapping.updateMapping( src, msg.ctxId );
    mace::ContextBaseClass::migrationTicket = 0;

    // notify the later events to proceed.
    pthread_cond_broadcast(&mace::ContextBaseClass::migrateContextCond);
    pthread_mutex_unlock( &mace::ContextBaseClass::__internal_ContextMutex );
    // notify the head that this event finished.
    __event_commit commitMsg( ThreadStructure::myEvent() );
    */
    }
    #
       },

=cut
}
# fill in those message handler where message is generated automatically because of fullcontext code.
#chuangw: create several helpers that are used for context'ed services.
sub createContextUtilHelpers {
    my $this = shift;

    my $sendAsyncSnapshot_Body;
    my $sendAllocateContextObjectmsg;
    if( $this->hasContexts() == 0 ){
        $sendAllocateContextObjectmsg = qq!
            const mace::string globalContextName = "";
            createContextObject( globalContextName , 1 ); // global context is the first context, so id=1
        !;

        $sendAsyncSnapshot_Body = "{}";
    }else{
        
        $sendAllocateContextObjectmsg = "
            if( newMappingReturn.first == Util::getMaceAddr() ){
              createContextObject( extra.targetContextID  , newMappingReturn.second  ); // global context is the first context, so id=1
            }
            mace::map< uint32_t, mace::string > contextSet;
            contextSet[ newMappingReturn.second ] =  extra.targetContextID;
            AllocateContextObject allocateCtxMsg( newMappingReturn.first, contextSet, newEvent.eventID, *ctxmapCopy, 0 );
            const mace::map < MaceAddr,uint32_t >& physicalNodes = contextMapping.getAllNodes(); 
            for( mace::map<MaceAddr, uint32_t>::const_iterator nodeIt = physicalNodes.begin(); nodeIt != physicalNodes.end(); nodeIt ++ ){ // chuangw: this message has to be sent to all nodes of the same logical node to update the context mapping.
              if( nodeIt->first == Util::getMaceAddr() ) continue;
              ASYNCDISPATCH( nodeIt->first, __ctx_dispatcher, AllocateContextObject, allocateCtxMsg )
            }
            ";
        $sendAsyncSnapshot_Body = qq#{
            ThreadStructure::myEvent().eventID = extra.event.eventID;
            mace::set<mace::string>::iterator snapshotIt = extra.snapshotContextIDs.find( thisContextID );
            if( snapshotIt != extra.snapshotContextIDs.end() ){
                mace::ContextLock ctxlock( *thisContext, mace::ContextLock::READ_MODE );// get read lock
                mace::string snapshot;// get snapshot
                mace::serialize(snapshot, thisContext );
                // send to the target context node.
                __event_snapshot msg( extra.event,extra.targetContextID, *snapshotIt, snapshot );

                ASYNCDISPATCH( contextMapping.getNodeByContext( extra.targetContextID ) , __ctx_dispatcher , __event_snapshot , msg )
                ctxlock.downgrade( mace::ContextLock::NONE_MODE );
            }else{
                mace::ContextLock ctxlock( *thisContext, mace::ContextLock::NONE_MODE );// get read lock
            }
          }#;
    }
    my @helpers = (
        {
            return => {type=>"void",const=>0,ref=>0},
            param => [ {type=>"__asyncExtraField",name=>"extra", const=>0, ref=>1}, {type=>"mace::Serializable",name=>"msg", const=>0, ref=>1} ],
            name => "requestNewEvent",
            body => qq#
    {
        static uint32_t counter = 0;
        mace::string msg_str;
        mace::string extra_str;
        mace::serialize(msg_str, &msg);
        mace::serialize(extra_str, &extra);
        ScopedLock sl( eventRequestBufferMutex );
        uint32_t req_counter = counter;
        ASSERT( unfinishedEventRequest.find(req_counter) == unfinishedEventRequest.end() );
        unfinishedEventRequest[req_counter] =  mace::pair<mace::string,mace::string>(msg_str, extra_str);
        counter ++;
        sl.unlock();
        maceout<<"sending out event creation request. "<< extra<< ", counter = "<< req_counter << Log::endl;
        __event_create req( extra, req_counter );
        ASYNCDISPATCH( contextMapping.getHead(), __ctx_dispatcher, __event_create, req );
    }
    #,
        },{
            return => {type=>"void",const=>0,ref=>0},
            #param => [ {type=>"mace::string",name=>"targetContextID", const=>1, ref=>1}, {type=>"mace::set<mace::string>",name=>"snapshotContextIDs", const=>1, ref=>1} ],
            param => [ {type=>"__asyncExtraField",name=>"extra", const=>1, ref=>1}],

            name => "eventPrep",
            body => qq#
    {
        // FIXME: chuangw: i don't have to to make snapshot taking work. will come back later.
        ThreadStructure::setEvent( extra.event );
        ThreadStructure::pushContext( extra.targetContextID );
        ThreadStructure::insertEventContext( extra.targetContextID );
        mace::ContextBaseClass * thisContext = getContextObjByName( extra.targetContextID );
        ThreadStructure::setMyContext( thisContext );
        if( !extra.snapshotContextIDs.empty()  ){
          size_t nsnapshots = extra.snapshotContextIDs.size();
          uint64_t ticket = ThreadStructure::myTicket();
          // wait for snapshots
          pthread_mutex_lock( &mace::ContextBaseClass::eventSnapshotMutex  );
          std::pair< uint64_t, mace::string > key( ticket, extra.targetContextID );
          while( mace::ContextBaseClass::eventSnapshotStorage[ key ].size() < nsnapshots /* waiting for some snapshots to arrive */ ){
              // add cond variable to a public static map
              pthread_cond_t cond;
              pthread_cond_init( &cond, NULL );
              mace::ContextBaseClass::eventSnapshotConds[ ticket ] = &cond;
              pthread_cond_wait(&cond , &mace::ContextBaseClass::eventSnapshotMutex);
              macedbg(1)<<extra.targetContextID<<" received snapshot number: "<< mace::ContextBaseClass::eventSnapshotStorage[ key ].size() <<Log::endl;
          }
          // copy the snapshot
          pthread_mutex_unlock( &mace::ContextBaseClass::eventSnapshotMutex);

          for( mace::set<mace::string>::const_iterator ssIt= extra.snapshotContextIDs.begin(); ssIt != extra.snapshotContextIDs.end(); ssIt++ ){
              mace::ContextBaseClass *ssContext = getContextObjByName( *ssIt ); // XXX: make sure I'm not holding any lock??
              std::pair<uint64_t, mace::string> key( ticket, extra.targetContextID );
              ssContext->setSnapshot( ticket, mace::ContextBaseClass::eventSnapshotStorage[key][ *ssIt ] );
          }
        }
        mace::ContextLock __contextLock( *thisContext , mace::ContextLock::WRITE_MODE); // acquire context lock. 
    }
    #,
        },{
            return => {type=>"void",const=>0,ref=>0},
            name => "eventFinish",
            body => qq#
    {
      // inform the head to commit before downgrade contexts
      mace::HighLevelEvent& currentEvent = ThreadStructure::myEvent();
      // if call in a start or end event, it doesn't mean the event is finished
      if( currentEvent.eventType != mace::HighLevelEvent::STARTEVENT &&
        currentEvent.eventType != mace::HighLevelEvent::ENDEVENT ){
        __event_commit commitRequest( currentEvent.eventID, currentEvent.eventType, currentEvent.eventMessageCount  );
        ASYNCDISPATCH( contextMapping.getHead(), __ctx_dispatcher , __event_commit , commitRequest )
      }

      // inform head node this event is ready to do global commit
      const mace::set< mace::string >& contexts = ThreadStructure::getCurrentServiceEventContexts();
      if( contexts.find( ThreadStructure::getCurrentContext() ) != contexts.end() ){
        downgradeCurrentContext();
      }
      globalDowngradeEventContext(); // downgrade all remaining contexts that the event has
      // remove redundant information
      // the head just need event ID and event message count
      /*for( mace::HighLevelEvent::EventContextType::iterator evCtxIt = currentEvent.eventContexts.begin(); evCtxIt != currentEvent.eventContexts.end(); evCtxIt++){
        evCtxIt->second.clear();
      }
      for( mace::HighLevelEvent::SkipRecordType::iterator evSkipIt = currentEvent.eventSkipID.begin(); evSkipIt != currentEvent.eventSkipID.end(); evSkipIt++){
        evSkipIt->second.clear();
      }*/

      ThreadStructure::popContext( );
        
    }
    #,
        },{
            return => {type=>"void",const=>0,ref=>0},
            param => [ {type=>"uint32_t",name=>"targetContextID", const=>1, ref=>0}, {type=>"mace::vector<uint32_t>",name=>"snapshotContextIDs", const=>1, ref=>1} ],
            name => "acquireContextLocks",
            flag => ["methodconst" ],
            body => qq#{
  mace::map< MaceAddr, mace::vector< uint32_t > > ancestorContextNodes;
  acquireContextLocksCommon(contextMapping, targetContextID, snapshotContextIDs, ancestorContextNodes );

  for( mace::map< MaceAddr, mace::vector< uint32_t > >::iterator nodeIt = ancestorContextNodes.begin(); nodeIt != ancestorContextNodes.end(); nodeIt ++ ){
    __event_enter_context ssctx_msg( ThreadStructure::myEvent(), nodeIt->second );
    CONST_ASYNCDISPATCH( nodeIt->first, __ctx_dispatcher , __event_enter_context , ssctx_msg )
  }
}
#,
        },{
            return => {type=>"mace::ContextBaseClass*",const=>0,ref=>0},
            param => [ {type=>"uint32_t",name=>"contextID", const=>1, ref=>0} ],
            name => "getContextObjByID",
            flag => ["methodconst" ],
            body => "{\n" . $this->generateGetContextByIDCode() . "\n}\n",
        },{
            return => {type=>"mace::ContextBaseClass*",const=>0,ref=>0},
            param => [ {type=>"mace::string",name=>"contextName", const=>1, ref=>1} ],
            name => "getContextObjByName",
            flag => ["methodconst" ],
            body => "{\n" . $this->generateGetContextByNameCode() . "\n}\n",
        },{
            return => {type=>"mace::ContextBaseClass*",const=>0,ref=>0},
            param => [ {type=>"mace::string",name=>"contextName", const=>1, ref=>1}, {type=>"uint32_t",name=>"contextID", const=>1, ref=>0} ],
            name => "createContextObject",
            body => "{\n" . $this->generateCreateContextCode() . "\n}\n",
        },{
            return => {type=>"void",const=>0,ref=>0},
            param => [ {type=>"mace::ContextBaseClass*",name=>"thisContext", const=>0, ref=>0}, {type=>"mace::string",name=>"s", const=>0, ref=>1}, ],
            name => "copyContextData",
            body => qq#{
                mace::serialize(s, thisContext );
            }#,
        },{
            return => {type=>"void",const=>0,ref=>0},
            param => [ {type=>"mace::ContextBaseClass*",name=>"thisContext", const=>0, ref=>0} ],
            name => "eraseContextData",
            body => qq#{
                // chuangw: this is a no-op function now, because it doesn't really matter if the context is just left there
                // In the future (i.e. post PLDI '13 submission), this function will do:
                // (1) erase the context object
                // (2) remove the context object from ctxobjIDMap & ctxobjNameMap
                // (3) remove from the parent context
            }#,
        },{
            return => {type=>"void",const=>0,ref=>0},
            param => [ {type=>"mace::HierarchicalContextLock",name=>"hl", const=>1, ref=>1},{type=>"mace::HighLevelEvent",name=>"he", const=>1, ref=>1} ],
            name => "storeHeadLog",
            body => qq#{
                // chuangw: FIXME: I commented out the code because it does not run properly.
                /*mace::string logStr;
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
            body => $sendAsyncSnapshot_Body,
        },{
            return => {type=>"void",const=>0,ref=>0},
            param => [ {type=>"__asyncExtraField",name=>"extra", const=>1, ref=>1},{type=>"int8_t",name=>"eventType", const=>1, ref=>0} ],
            #param => [ {type=>"mace::Serializable",name=>"msg", const=>1, ref=>1},{type=>"__asyncExtraField",name=>"extra", const=>1, ref=>1},{type=>"int8_t",name=>"eventType", const=>1, ref=>0} ],
            name => "asyncHead",
            body => qq#{
        mace::HighLevelEvent& newEvent = ThreadStructure::myEvent( );

        mace::AgentLock lock( mace::AgentLock::WRITE_MODE ); // global lock is used to ensure new events are created in order
        newEvent.newEventID( eventType );
        lock.downgrade( mace::AgentLock::NONE_MODE );

        { // Release global AgentLock. Acquire head context lock to allow paralellism
          mace::ContextLock c_lock( mace::ContextBaseClass::headContext, mace::ContextLock::WRITE_MODE );

          newEvent.initialize(  );

          bool contextExist = contextMapping.hasContext( extra.targetContextID );
          if( contextExist ){
            contextEventRecord.updateContext( extra.targetContextID, newEvent.eventID, newEvent.getSkipIDStorage( instanceUniqueID ) );
          }else{// create a new context
            mace::HighLevelEvent::setLastContextMappingVersion( newEvent.eventID );
            newEvent.eventContextMappingVersion = newEvent.eventID;
            std::pair< mace::MaceAddr, uint32_t > newMappingReturn = contextMapping.newMapping( extra.targetContextID );
            // make a copy because contextMapping is shared among threads and it will be sent out by AllocateContextObject message
            const mace::ContextMapping* ctxmapCopy =  contextMapping.snapshot(  ) ; // create ctxmap snapshot
            ASSERT( ctxmapCopy != NULL );
            contextEventRecord.createContextEntry( extra.targetContextID, newMappingReturn.second, newEvent.eventID );
            newEvent.setSkipID( instanceUniqueID, newMappingReturn.second, newEvent.eventID );

            // notify other services about the new context
            BaseMaceService::globalNotifyNewContext( instanceUniqueID );

            $sendAllocateContextObjectmsg
          }

          // notify other services about this event
          BaseMaceService::globalNotifyNewEvent( instanceUniqueID );
                          
          /*mace::string buf;
          mace::serialize(buf,&msg);
          mace::HierarchicalContextLock hl( newEvent, buf );
          storeHeadLog(hl, newEvent );*/
          c_lock.downgrade( mace::ContextLock::NONE_MODE );
        }

    }#,
        },{
            return => {type=>"void",const=>0,ref=>0},
            param => [ {type=>"mace::string",name=>"contextID", const=>1, ref=>1} ],
            name => "downgradeContext",
            body => qq#{
// TODO: 
//(1) assert: the event has acquired the context before.
const mace::set< mace::string >& eventContexts = ThreadStructure::getCurrentServiceEventContexts();
ASSERTMSG( eventContexts.find( contextID ) != eventContexts.end(), "The event does not have the context" );   
mace::AccessLine::checkDowngradeContext( contextID, contextMapping.getSnapshot() );
//(2) figure out the physical address of the context
//(3) if it's local, call it. If not, send message and wait for response
__event_downgrade_context dgmsg( ThreadStructure::getCurrentContext(), ThreadStructure::myEvent().eventID, false );
SYNCCALL( contextMapping.getNodeByContext( contextID ), __ctx_helper_fn___event_downgrade_context, __event_downgrade_context, dgmsg )
ThreadStructure::removeEventContext( ThreadStructure::getCurrentContext() );

    }#,
        },{
            return => {type=>"void",const=>0,ref=>0},
            param => [ {type=>"mace::string",name=>"targetContextID", const=>1, ref=>1} ],
            flag => ["methodconst" ],
            name => "enterInnerService",
            body => qq#{
      mace::vector< uint32_t > nextHops;
      const mace::ContextMapping& snapshotMapping = contextMapping.getSnapshot();
      const mace::string globalContextName("");
      uint32_t globalContextID = snapshotMapping.findIDByName( globalContextName );
      nextHops.push_back( globalContextID );
      if( !ThreadStructure::isEventEnteredService() && targetContextID != globalContextName ){
          // Since it is the first transition of this service,
          // it has to downgrade higher-level contexts before entering the call.
          // this is similar to async calls
          mace::HighLevelEvent& he = ThreadStructure::myEvent();
            uint32_t targetContextNID = snapshotMapping.findIDByName( targetContextID );
          __event_commit_context commit_msg( nextHops, he.eventID, he.eventType, he.eventContextMappingVersion, he.eventSkipID, false, true, targetContextNID );
          CONST_ASYNCDISPATCH( mace::ContextMapping::getNodeByContext( snapshotMapping, globalContextID ), __ctx_dispatcher , __event_commit_context , commit_msg )
      }
    }#,
        },{
            return => {type=>"void",const=>0,ref=>0},
            param => [ {type=>"mace::HighLevelEvent",name=>"event", const=>1, ref=>1}, {type=>"uint32_t",name=>"targetContextID", const=>1, ref=>1}, {type=>"mace::vector<uint32_t>",name=>"snapshotContextIDs", const=>1, ref=>1} ],
            flag => ["methodconst" ],
            name => "__begin_remote_routine",
            body => $this->hasContexts()? qq#{
    mace::AgentLock::nullTicket();
    ThreadStructure::setEvent( event );
    ThreadStructure::pushServiceInstance( instanceUniqueID ); 
    }#:"",
        },{
            return => {type=>"void",const=>0,ref=>0},
            param => [ {type=>"uint32_t",name=>"targetContextID", const=>1, ref=>1}, {type=>"mace::string",name=>"returnValueStr", const=>0, ref=>1} ],
            flag => ["methodconst" ],
            name => "__finish_remote_routine",
            body => $this->hasContexts()? qq#{
    mace::serialize(returnValueStr, &(ThreadStructure::myEvent() ) );

    __event_routine_return startCtxResponse(returnValueStr, ThreadStructure::myEvent());
    const mace::ContextMapping& snapshotMapping = contextMapping.getSnapshot();
    const MaceAddr& destAddr = mace::ContextMapping::getNodeByContext( snapshotMapping, targetContextID );
    const MaceKey srcNode( mace::ctxnode, destAddr );
    $this->{name}Service *self = const_cast<$this->{name}Service *>( this );
    self->downcall_route( srcNode ,  startCtxResponse ,__ctx);
    ThreadStructure::popServiceInstance( ); 
    }#:"",
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
            if( defined $_->{default} ){
              $field->default( $_->{default} );
            }
            push @params, $field;
        }
        my $method = Mace::Compiler::Method->new(name=>$_->{name},  returnType=>$returnType, body=>$_->{body});
        if( defined $_->{flag} ){
            for ( @{ $_->{flag} } ){
                when ("methodconst") {
                  $method->isConst(1); 
                }
            }
        }
        $method->params(@params);

        $this->push_contextHelperMethods($method);
    }
=begin
    my $getNextSeqno_Body;
        $getNextSeqno_Body = "{return 1;}";
        $getNextSeqno_Body = qq#{
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
            #;
{
            return => {type=>"uint32_t",const=>0,ref=>0},
            param => [ {type=>"mace::string",name=>"ctxId", const=>1, ref=>1} ],
            name => "getNextSeqno",
            body => $getNextSeqno_Body,
        },    my $ackUpdateRespond_Body;
        $ackUpdateRespond_Body = qq#{return true;}#;
        $ackUpdateRespond_Body = qq#
    {
        /**
        this helper function responds to the sender node an acknowledgement message
        */

        uint32_t& lastAcked = __internal_lastAckedSeqno[ lastHop ];
        mace::map< uint32_t, uint8_t>& receivedSeqno = __internal_receivedSeqno[lastHop];

        if( seqno <= lastAcked ){ 
            downcall_route( source, __internal_Ack( lastAcked, lastHop ) ,__ctx ); // send back the last acknowledge sequence number 
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

        downcall_route( source, __internal_Ack( lastAcked, lastHop  ) ,__ctx ); // always send ack before processing message
        return true;
    }
    #;
{
            return => {type=>"bool",const=>0,ref=>0},
            param => [ {type=>"MaceKey",name=>"source", const=>1, ref=>1},{type=>"mace::string",name=>"lastHop", const=>1, ref=>1},{type=>"uint32_t",name=>"seqno", const=>1, ref=>0} ],
            name => "ackUpdateRespond",
            body => $ackUpdateRespond_Body,
        },
=cut
}
=begin
sub validate_replaceMaceInitExit {
    my $this = shift;

    my @oldTransitionMethod;
    my @methodMessage;
    my @maceInitExitTransitions;
    my $hasMaceInit = 0;
    my $hasMaceExit = 0;
    foreach my $transition ($this->transitions()) { # find maceInit() where state==init
        my $m = $transition->method;
        next if ($transition->type() ne 'downcall' or ( $m->name ne 'maceInit' and $m->name ne 'maceExit'));
        next if (defined $m->options("merge"));

        push @maceInitExitTransitions, $transition;
        if( $m->name eq "maceInit" ){
          $hasMaceInit = 1 ;
          #$m->validateLocking();
        }
        if( $m->name eq "maceExit" ){
          $hasMaceExit = 1 ;
          #$m->validateLocking();
        }
    }
    if( $hasMaceInit == 0 ){
        #print "No maceInit is defined. Add dummy maceInit transition\n";
        my $mret = Mace::Compiler::Type->new(type=>"void",isConst=>0,isConst1=>0,isConst2=>0,isRef=>0);
        my $m = Mace::Compiler::Method->new( body => "{}", name=>"maceInit", filename=>__FILE__, line=>__LINE__, returnType=>$mret, targetContextObject=>"" );
        my $txnnum = $this->count_transitions( );
        my $t = Mace::Compiler::Transition->new(name => "maceInit", type=>"downcall", method=>$m, transitionNum =>$txnnum);
        push @maceInitExitTransitions, $t;
        $this->push_transitions( $t );
    }
    if( $hasMaceExit == 0 ){
        #print "No maceExit is defined. Add dummy maceExit transition\n";
        my $mret = Mace::Compiler::Type->new(type=>"void",isConst=>0,isConst1=>0,isConst2=>0,isRef=>0);
        my $m = Mace::Compiler::Method->new( body => "{}", name=>"maceExit", filename=>__FILE__, line=>__LINE__ , returnType=>$mret, targetContextObject=>"" );
        my $txnnum = $this->count_transitions( );
        my $t = Mace::Compiler::Transition->new(name => "maceExit", type=>"downcall", method=>$m, transitionNum =>$txnnum);
        push @maceInitExitTransitions, $t;
        $this->push_transitions( $t );
    }
    
    foreach my $transition ( @maceInitExitTransitions ){
        my $m = $transition->method;
        # replace the old maceInit with our own
        my $eventType; 
        my $checkFirstDemuxMethod;
        my $commitEvent;
        if( $m->name() eq "maceInit" ){ 
            $eventType = "STARTEVENT"; 
            $checkFirstDemuxMethod = "ThreadStructure::isFirstMaceInit()";
            $commitEvent = qq!
            if( ThreadStructure::isOuterMostTransition() ){
                HeadEventDispatch::HeadEventTP::commitEvent( myEvent.eventID, myEvent.eventType, myEvent.eventMessageCount ); // commit
            }!;
        } elsif( $m->name() eq "maceExit" ) { 
            $eventType = "ENDEVENT"; 
            $checkFirstDemuxMethod = "ThreadStructure::isFirstMaceExit()";
            $commitEvent = qq//;
        }

        my $origBody = $transition->method->body();
        $this->matchStateChange(\$origBody);

        my $origLockingAnnotation = $transition->method->options("locking");
        #chuangw: temporary workaround
        #$transition->method->validateLocking();

        my @currentContextVars = ();
        $transition->method->printTargetContextVar(\@currentContextVars, ${ $this->contexts() }[0] );
        $transition->method->printSnapshotContextVar(\@currentContextVars, ${ $this->contexts() }[0] );
        my $contextVariablesAlias = join("\n", @currentContextVars);
        $transition->method->options("locking", $origLockingAnnotation);

        my $returnToHead; # update event after the maceInit of this service
        if( $this->hasContexts() ){
          $returnToHead = qq#
            if( contextMapping.getHead() == Util::getMaceAddr() ){
              // do nothing
            }else{
              // send event
              __msg_$m->{name}_response callMsg( ThreadStructure::myEvent() );
              downcall_route( MaceKey( mace::ctxnode, src ), callMsg, __ctx );
            }
          #;
        }else{
          $returnToHead = "";
        }

        my $newBody = qq#
        {
            mace::string globalContextID = "";
            mace::ContextBaseClass * currentContextObject;
            mace::AgentLock alock(mace::AgentLock::WRITE_MODE); // Use agentlock to make sure earlier migration event is executed in order.
            if( contextMapping.getHead() != Util::getMaceAddr() ){ //set event/context mapping
              ThreadStructure::setEvent( msg.event );
              //contextMapping.snapshotInsert( msg.event.eventID, msg.contextMapping );
            }
            currentContextObject = getContextObjByName( globalContextID );

            alock.downgrade( mace::AgentLock::NONE_MODE );
            ThreadStructure::setMyContext( currentContextObject );
            //eventPrep
            ThreadStructure::ScopedServiceInstance si( instanceUniqueID );
            ThreadStructure::ScopedContextID sc( globalContextID );
            ThreadStructure::insertEventContext( globalContextID);
            mace::ContextLock __contextLock( *currentContextObject , mace::ContextLock::WRITE_MODE); // acquire context lock. 

            $contextVariablesAlias

            PREPARE_FUNCTION
            $origBody

            eventFinish();

            // TODO: send response/ return to head
            $returnToHead
        }
        #;
        my $newBody_response = qq#
        {
            //ASSERTMSG( contextMapping.getHead() == Util::getMaceAddr(), "This message is supposed to be received by the head node" );

            mace::string eventStr;
            mace::serialize( eventStr, &msg.event );
            mace::ScopedContextRPC::wakeupWithValue( msg.event.eventID, eventStr );
        }
        #;

        my $targetContextString = ""; # if the transition declares a different context other than global context, it should emit error.
        #join(".", $transition->method->targetContextToString() ) ;
        #print $transition->method->name() . "-->" . $targetContextString . "-->" .  $transition->method->targetContextObject() . "\n";

        my $newMaceInitBody = qq#
            const mace::string targetContextID("$targetContextString");
            mace::set< mace::string > snapshotContextIDs;
            if( $checkFirstDemuxMethod ){ // this is the first maceInit/maceExit demux method executed. If so, create new event. Similar to asyncHead()
              ThreadStructure::newTicket();
              __asyncExtraField extra( targetContextID, snapshotContextIDs, ThreadStructure::myEvent(), true );
              asyncHead( extra, mace::HighLevelEvent::$eventType );
            }

            mace::HighLevelEvent& myEvent = ThreadStructure::myEvent( );
            __msg_$m->{name} callMsg( myEvent, contextMapping );
            {
              SYNCCALL_EVENT( contextMapping.getNodeByContext( targetContextID ), __ctx_helper_fn___msg_$m->{name} , __msg_$m->{name},  callMsg)
            }
        #;
        $transition->method->body( $newMaceInitBody );
        my %hackmsg = (
            name => "__msg_" . $m->name,
            param => [ {type=>"mace::HighLevelEvent",name=>"event"}, {type=>"mace::ContextMapping",name=>"contextMapping"}   ]
        );
        my %hackmsg_response = (
            name => "__msg_" . $m->name . "_response",
            param => [ {type=>"mace::HighLevelEvent",name=>"event"}   ]
        );
        #my $downcallParam = Mace::Compiler::AutoType->new(name=> "__param_" . $m->name , line=> $transition->method->line(), filename => $transition->method->filename() );
        #$this->push_auto_types($downcallParam);

        my %hackmethod = (param=>"__msg_" . $m->name, body=>$newBody);
        my %hackmethod_response = (param=>"__msg_" . $m->name . "_response", body=>$newBody_response);
        push @methodMessage, \%hackmsg;
        push @methodMessage, \%hackmsg_response;

        push @oldTransitionMethod, \%hackmethod;
        push @oldTransitionMethod, \%hackmethod_response;
    }
    $this->addContextMigrationMessages( \@methodMessage );
    $this->addContextMigrationTransitions(\@oldTransitionMethod);
}
=cut
sub validate_findRoutines {
    my $this = shift;
    my $ref_routineMessageNames = shift;
    my $uniqid = 1;
    for my $r ($this->routines()) {
        next if (defined $r->targetContextObject and $r->targetContextObject eq "__internal" );
        next if (defined $r->targetContextObject and $r->targetContextObject eq "__anon" );
        next if (defined $r->targetContextObject and $r->targetContextObject eq "__null" );
        $this->createContextRoutineHelperMethod( $r, $ref_routineMessageNames, $uniqid++  );
    }
}
# chuangw: TODO: this will have to be extended to create deferral queue for every upcall/downcalls for all services
sub processApplicationUpcalls {
    my $this = shift;
    # for each such upcall transition, create msg/auto_type using the parameters of the transition
    my $mcounter = 1;
    foreach ($this->providedHandlerMethods() ){
        $this->createApplicationUpcallInternalMessage( $_, $mcounter );
        $this->createApplicationUpcallInternalMessageResponse( $_, $mcounter );
        $mcounter ++;
    }
}
sub createContextHelpers {
    my $this = shift;
    if( not $Mace::Compiler::Globals::useFullContext ){
        Mace::Compiler::Globals::error("bad_context", __FILE__, __LINE__ , "Failure recovery must be turned on.");
    }
    my @asyncMessageNames;
    my @syncMessageNames;

    $this->createAsyncExtraField();
    $this->createContextUtilHelpers();

    $this->createDeferredMessageDispatcher( );
    # TODO: support contexts for aspect/raw_upcall transition?
}
# chuangw: the local async dispatcher provides a centralized handler for same physical-node messages.
# The centralized handler provides type checking (via message id), which is safer than directly typecasting
# the void* pointer into a particular message object type.
#
# In essence, this is similar to the demux method of upcall_deliver( )
sub createLocalAsyncDispatcher {
    my $this = shift;
    my $adWrapperBody = "
      Message *msg = static_cast< Message * >( __param );
      switch( msg->getType()  ){
    ";
    PROCMSG: for my $msg ( $this->messages() ){
      # create wrapper func
      my $mname = $msg->{name};
      my $call = "";
      given( $msg->method_type ){
        when (Mace::Compiler::AutoType::FLAG_NONE)        { next PROCMSG; }
        when (Mace::Compiler::AutoType::FLAG_ASYNC)       { $call = $this->asyncCallLocalHandler($msg );}
        when (Mace::Compiler::AutoType::FLAG_SYNC)        { next PROCMSG; }
        #when (Mace::Compiler::AutoType::FLAG_SNAPSHOT)    { $adName = ""; } 
        when (Mace::Compiler::AutoType::FLAG_SNAPSHOT)    { next PROCMSG; } 
        when (Mace::Compiler::AutoType::FLAG_DOWNCALL)    { next PROCMSG; } # not used?
        when (Mace::Compiler::AutoType::FLAG_RELAYMSG)    { $call = $this->routeRelayMessageLocalHandler( $msg ); }
        when (Mace::Compiler::AutoType::FLAG_UPCALL)      { next PROCMSG; } # not used?
        when (Mace::Compiler::AutoType::FLAG_TIMER)       { $call = $this->schedulerCallLocalHandler( $msg ); } # not used?
        when (Mace::Compiler::AutoType::FLAG_APPUPCALL)   { $call = $this->deliverAppUpcallLocalHandler( $msg ); }
        when (Mace::Compiler::AutoType::FLAG_APPUPCALLRPC){ next PROCMSG; } # not used?
        when (Mace::Compiler::AutoType::FLAG_APPUPCALLREP){ $call = $this->deliverAppUpcallResponseLocalHandler( $msg ); }
        when (Mace::Compiler::AutoType::FLAG_CONTEXT)     { $call = "
          $mname* __msg = static_cast<$mname* >(msg);
          __ctx_helper_fn_$mname ( *__msg, Util::getMaceAddr() );
          delete __msg;
          ";}
        
      }

      $adWrapperBody .= qq/
        case ${mname}::messageType: {
          $call
        }
        break;
      /;
=begin
      $adWrapperBody .= qq/
        case ${mname}::messageType: {
          $mname* __p = ($mname*)__param;
          $adName ( *__p, Util::getMaceAddr()   );
          delete __p;
        }
        break;
      /;
=cut
    }
    $adWrapperBody .= qq/
        default:
          { ABORT("No matched message type is found" ); }
      }
    /;

    my $adWrapperName = "__ctx_dispatcher";
    my $adReturnType = Mace::Compiler::Type->new(type=>"void",isConst=>0,isConst1=>0,isConst2=>0,isRef=>0);
    my $adWrapperParamType = Mace::Compiler::Type->new( type => "void*", isConst => 0,isRef => 0 );
    my $adWrapperParam = Mace::Compiler::Param->new( name => "__param", type => $adWrapperParamType );
    my @adWrapperParams = ( $adWrapperParam );
        my $adWrapperMethod = Mace::Compiler::Method->new( name => $adWrapperName, body => $adWrapperBody, returnType=> $adReturnType, params => @adWrapperParams);
        $this->push_asyncLocalWrapperMethods( $adWrapperMethod  );

}
sub createDeferredMessageDispatcher {
    my $this = shift;
    
    my $adWrapperBody ="";
        my $usesRouteDowncall = 0;
        map{ 
          if( $_->serialRemap() and $_->name eq "route"){
            $usesRouteDowncall = 1;
          }
        } $this->usesDowncalls();
    if( $this->useTransport() and $usesRouteDowncall ){
      $adWrapperBody = "
        switch( message->getType()  ){
      ";
      for( grep{ $_->method_type == Mace::Compiler::AutoType::FLAG_NONE} $this->messages()  ){
        # create wrapper func
        my $mname = $_->{name};
        $adWrapperBody .= qq/
          case ${mname}::messageType: {
            $mname* msgptr = ($mname*)message;
            downcall_route ( dest, *msgptr, rid );
          }
          break;
        /;
      }
      $adWrapperBody .= qq/
          default:
            { ABORT("No matched message type is found" ); }
        }
      /;
    }

    my $adWrapperName = "dispatchDeferredMessages";
    my $adReturnType = Mace::Compiler::Type->new(type=>"void",isConst=>0,isConst1=>0,isConst2=>0,isRef=>0);
    my $paramType1 = Mace::Compiler::Type->new( type => "MaceKey", isConst => 1,isRef => 1 );
    my $paramType2 = Mace::Compiler::Type->new( type => "Message*", isConst => 0,isRef => 0 );
    my $paramType3 = Mace::Compiler::Type->new( type => "registration_uid_t", isConst => 1,isRef => 0 );
    my $param1 = Mace::Compiler::Param->new( name => "dest", type => $paramType1 );
    my $param2 = Mace::Compiler::Param->new( name => "message", type => $paramType2 );
    my $param3 = Mace::Compiler::Param->new( name => "rid", type => $paramType3 );
    my @adWrapperParams = ( $param1, $param2, $param3 );
    my $adWrapperMethod = Mace::Compiler::Method->new( name => $adWrapperName, body => $adWrapperBody, returnType=> $adReturnType );
    $adWrapperMethod->push_params( @adWrapperParams );
    $this->push_asyncLocalWrapperMethods( $adWrapperMethod  );

}
sub validate_completeTransitionDefinition {
    my $this = shift;
    my $kind = shift;
    my $transition = shift;
    my @methodset = @_;
    my $origmethod;
    unless(ref ($origmethod = Mace::Compiler::Method::containsTransition($transition->method, @methodset))) {
        Mace::Compiler::Globals::error("bad_transition(".$kind.")", $transition->method()->filename(), $transition->method->line(), $origmethod);
        return;
    }
    $this->completeTransitionDefinition($transition, $origmethod);
}
# completes return type, constancy and parameter types
sub completeTransitionDefinition {
    my $this = shift;
    my $transition = shift;
    my $origmethod = shift;

    $transition->method->returnType($origmethod->returnType);
    $transition->method->isConst($origmethod->isConst);
    #$transition->method->isConst(0);
    my $i = 0;
    for my $p ($transition->method->params()) {
      unless($p->type) {
        $p->type($origmethod->params()->[$i]->type());
      }
      $i++;
    }
}

sub validate {
    my $this = shift;
    my @deferNames = @_;
    my $i = 0;

    if( $this->count_contexts() == 0 ){ # this is possible if state_variables block is not declared.
        my $context = Mace::Compiler::Context->new(name => "globalContext",className =>"global_Context", isArray => 0);
        my $contextParamType = Mace::Compiler::ContextParam->new(className => "" );
        $context->paramType( $contextParamType );
        $this->push_contexts($context);
    }

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
    $this->push_ignores('requestContextMigration');
    $this->push_ignores('evict');

    for my $det ($this->detects()) {
        $det->validate($this);
    }

    for my $m ($this->routines()) {
        $m->validate( $this->contexts() ) ;
    }

    if ($this->queryFile() ne "") {
        $this->computeLogObjects();
    }
    my @providesMethods;
    my @providesHandlers;
    my @providesHandlersMethods;
    
    my @orig_usesClassMethods;
    my @orig_usesHandlerMethods;

    $this->validate_prepareSelectorTemplates();
    $this->validate_parseProvidedAPIs(\@providesMethods, \@providesHandlers, \@providesHandlersMethods); #Note: Provided APIs can update the impl.  (Mace literal blocks)
    my $transitionNum = 0;

    foreach my $transition ($this->transitions()) { # set a number for each transition
        $transition->transitionNum($transitionNum++);
    }
    $this->validate_parseUsedAPIs( \@orig_usesClassMethods, \@orig_usesHandlerMethods); #Note: Used APIs can update the impl.  (Mace literal blocks)

    #chuangw: I don't quite understand this, but: after validate_parseUsedAPIs(), the implementsUpcalls() array is populated with upcalls
    # defined in the service class.
    my $implementsDeliverHandler= 0;
    map{ 
      if( $_->serialRemap() and $_->name eq "deliver"){
        $implementsDeliverHandler= 1;
      }
    } $this->implementsUpcalls();
    
    my $usesRouteDowncall = 0;
    map{ 
      if( $_->serialRemap() and $_->name eq "route"){
        $usesRouteDowncall = 1;
      }
    } $this->usesDowncalls();

    $this->useTransport(1) if( $implementsDeliverHandler );

    $this->validate_fillStructuredLogs();

    $this->providedMethods(@providesMethods);
    $this->providedMethodsAPI(@providesMethods);

    #providedHandlers is the list of handler classes of the service classes we provide
    $this->providedHandlers(@providesHandlers  );

    # restore usesClassMethods and usesHandlerMethods
    $this->usesClassMethods( @orig_usesClassMethods );
    $this->usesHandlerMethods( @orig_usesHandlerMethods );

    # transform context'ed transitions into basic Mace transitions
    $this->createContextHelpers();

    $this->validate_findAsyncMethods();

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
        $context->validateContextOptions($this);
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
    $this->validate_genericMethodRemapping("usesDowncalls", "usesClassMethods", requireOPDefault=>0, allowRemapDefault=>1, pushOntoSerials=>0, includeMessageInSerial=>1, internalRemapOnly=>0);
    $this->validate_genericMethodRemapping("usesUpcalls", "providedHandlerMethods", requireOPDefault=>1, allowRemapDefault=>1, pushOntoSerials=>0, includeMessageInSerial=>1, internalRemapOnly=>0);

    $this->validate_genericMethodRemapping("implementsUpcalls", "usesHandlerMethods", requireOPDefault=>0, allowRemapDefault=>0, pushOntoSerials=>1, includeMessageInSerial=>0, internalRemapOnly=>0);
    $this->validate_genericMethodRemapping("implementsDowncalls", "providedMethods", requireOPDefault=>0, allowRemapDefault=>0, pushOntoSerials=>1, includeMessageInSerial=>0, internalRemapOnly=>0);

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
    $this->validate_setupSelectorOptions("demux", $this->usesHandlerMethods(), $this->providedMethods(), $this->timerMethods(), $this->implementsUpcalls(), $this->implementsDowncalls(), $this->asyncMethods());

    #this code handles selectors and selectorVars for methods passed to demuxFunction
    $this->validate_setupSelectorOptions("upcall", $this->providedHandlerMethods(), $this->usesUpcalls(),$this->upcallHelperMethods(),$this->appUpcallDispatchMethods() );

    #this code handles selectors and selectorVars for methods passed to demuxFunction
    $this->validate_setupSelectorOptions("downcall", $this->usesClassMethods(), $this->usesDowncalls(),$this->downcallHelperMethods() );

    #this code handles selectors and selectorVars for methods passed to demuxFunction
    $this->validate_setupSelectorOptions("async", $this->asyncHelperMethods(), $this->asyncDispatchMethods(), $this->asyncLocalWrapperMethods());

    $this->validate_setupSelectorOptions("context",  $this->contextHelperMethods());

    $this->validate_setupSelectorOptions("scheduler",  $this->timerHelperMethods());

    for my $method ($this->usesClassMethods(), $this->usesDowncalls()) {
        $this->validate_setBinlogFlags($method, \$i, "", $method->getLogLevel($this->traceLevel()) > 0);
    }

    #This portion validates that transitions match some legal API -- must determine list of timer names before this block.

    my $filepos = 0;
    #print "size of asyncMethods: " . $this->count_asyncMethods() . "\n";
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
        elsif ($transition->type() eq 'aspect') {
            $this->validate_fillAspectTransition($transition, \$filepos);
        }
        else {
            my $ttype = $transition->type();
            Mace::Compiler::Globals::error("bad_transition", $transition->method()->filename(), $transition->method->line(), "Transition type '$ttype' invalid.  Expecting upcall/raw_upcall/downcall/scheduler/async/sync/aspect");
        }
    }

    for my $p (@{$this->safetyProperties()}, @{$this->livenessProperties()}) {
        $p->validate($this);
    }
# chuangw TODO: look at each of providedMethods, usesHandlerMethods, usesHandlerMethodsAPI, timerMethods, asyncMethods and aspect transition
    $this->generateInternalTransitions();

# the second pass generates several messages and transitions ( upcall_deliver, upcall_messageError, etc)
# do remapping one more time 
    # providedHandlerMethods is the handler method api of the upper service
    #chuangw: in the first pass remapping, usesHandlerMethods contains the original handler parameter type.
    # usesHandlerMethods is the handler method this service implements
    # implementsUpcalls is the remapping rules defined in this service
    my @logicalUsesHandler =  $this->usesHandlerMethods();

    $this->clear_usesHandlerMethods(  );

    # generate remapped message deliver transitions 
    if( $this->useTransport() or $this->hasContexts() ){
      map{
        $this->push_usesHandlerMethods( $_ );
      } grep{ $_->name eq "deliver" or $_->name eq "messageError" } @orig_usesHandlerMethods;

      my @transportUpcalls;
      my @otherUpcalls;
      map{
        # remove every non-deliver()/non-messageError() methods
        if( $_->name eq "deliver" or $_->name eq "messageError" ){
          push @transportUpcalls, $_;
        }else{
          push @otherUpcalls, $_;
        }
      } $this->implementsUpcalls();

      $this->implementsUpcalls(@transportUpcalls);

      $this->validate_genericMethodRemapping("implementsUpcalls", "usesHandlerMethods", requireOPDefault=>0, allowRemapDefault=>0, pushOntoSerials=>1, includeMessageInSerial=>0, internalRemapOnly=>1);
      map{ 
        $this->push_implementsUpcalls($_);
      }@otherUpcalls;
    }

    $this->validate_setupSelectorOptions("routine",  $this->routineHelperMethods());

    $this->validate_setupSelectorOptions("demux", @logicalUsesHandler);
    $this->validate_setupSelectorOptions("async", $this->asyncDispatchMethods);
    $this->validate_setupSelectorOptions("async", $this->asyncHelperMethods);
    $this->validate_setupSelectorOptions("async", $this->asyncLocalWrapperMethods);
    $this->validate_setupSelectorOptions("scheduler", $this->timerHelperMethods);
    $this->validate_setupSelectorOptions("upcall", $this->upcallHelperMethods);
    $this->validate_setupSelectorOptions("upcall", $this->appUpcallDispatchMethods);
    $this->validate_setupSelectorOptions("downcall", $this->downcallHelperMethods);

    foreach( @logicalUsesHandler ){
      $this->push_usesHandlerMethods( $_ );
    }

    # do fill_Transition one more time 
    # only the upcall transitions containing auto-generated messages are processed
    $transitionNum = 0;
    foreach my $transition   ($this->transitions() ) {
      $transition->transitionNum($transitionNum++); # set transition number for auto-generated transitions
    }
    if( $this->useTransport() or $this->hasContexts() ){
      # If this service has contexts or uses transport service, then some automatically-generated 
      # upcall_deliver transitions need to be validated 
      # (excluding user-created message delivery transitions, because they are already validated.
      foreach my $transition ( grep {$_->type() eq 'upcall' and $_->name eq "deliver"} $this->transitions()) {
        my $msgType = ${ $transition->method->params() }[2]->type->type;
        next if scalar( grep { $_->method_type == Mace::Compiler::AutoType::FLAG_NONE and $_->name eq $msgType } $this->messages() );
        $this->validate_fillTransition("upcall", $transition, \$filepos, $this->usesHandlerMethods());
      }
    }

    $this->annotatedMacFile($this->annotatedMacFile() . substr($this->origMacFile(), $filepos));

    for my $slog (grep(!($_->name =~ /^(un)?register.*Handler$/), $this->providedMethods()), @{$this->aspectMethods()}, @{$this->usesHandlerMethods()}, @{$this->timerMethods()}) {
        $this->validate_setBinlogFlags($slog, \$i, "", ($slog->getLogLevel($this->traceLevel()) > 0 and (defined $slog->options('transitions') or scalar(grep {$_ eq $slog->name} $this->ignores()))));
    }
    $this->validateLogObjects();
} # validate

sub generateInternalTransitions{
  my $this = shift;
  my %messagesHash = ();
  my $uniqid = 0;

  $this->generateAsyncInternalTransitions( \$uniqid, \%messagesHash );
  $this->generateSchedulerInternalTransitions( \$uniqid, \%messagesHash );
  $this->generateUpcallTransportDeliverInternalTransitions( \$uniqid, \%messagesHash );
  $this->createTransportRouteRelayMessages();
  $this->generateUpcallInternalTransitions( \$uniqid, \%messagesHash );
  $this->generateDowncallInternalTransitions( \$uniqid, \%messagesHash );
  $this->generateAspectInternalTransitions( \$uniqid, \%messagesHash );
  $this->processApplicationUpcalls();

  my @syncMessageNames;
  $this->validate_findRoutines(\@syncMessageNames);

  $this->addContextMigrationHelper();
  $this->addContextHandlers();
  $this->createSnapShotSyncHelper();
  foreach my $message ( grep{ $_->method_type != Mace::Compiler::AutoType::FLAG_NONE }$this->messages()) {
      $message->validateMessageOptions();
  }
  $this->createMessageHandlers();
  $this->createLocalAsyncDispatcher( );
}
sub generateAsyncInternalTransitions {
  my $this = shift;
  
  my $ref_uniqid = shift;
  my $ref_messagesHash = shift;

  my $uniqid = $$ref_uniqid;
  foreach my $asyncMethod ( $this->asyncMethods() ){
    # TOdO: post-transitions and pre-transitions? What to do with the contexts? They are declared in interface, so they shouldn't know the internals.
    # TODO: validate all transitions of the same method access the same context
    my $at;
    my $adMethod;
    my $adHeadMethod;
    $asyncMethod->options("base_name", $asyncMethod->name() );
    $asyncMethod->options("async_msgname", $asyncMethod->toMessageTypeName("async",$uniqid ) );
    $asyncMethod->options("event_handler", $asyncMethod->toRealHandlerName("async",$uniqid ) );
    $asyncMethod->options("event_head_handler", $asyncMethod->toRealHeadHandlerName("async",$uniqid ) );
    $asyncMethod->createAsyncMessage( $ref_messagesHash, \$at);
    $this->createAsyncMessageHandler($asyncMethod);
    $this->push_messages($at); 
    my $helpermethod;
    $asyncMethod->createAsyncHelperMethod( $at, $this->asyncExtraField(), \$helpermethod );
    $this->push_asyncHelperMethods($helpermethod);
    $asyncMethod->createRealTransitionHandler( "async",  $at, $this->name(), $this->asyncExtraField() , \$adMethod);
    $this->push_asyncHelperMethods($adMethod);
    $asyncMethod->createRealTransitionHeadHandler( "async",  $at, $this->name(), $this->asyncExtraField() , \$adHeadMethod);
    $this->push_asyncHelperMethods($adHeadMethod);
    next if( not defined $asyncMethod->options("transitions") );
    $uniqid ++;
  }
}
sub generateSchedulerInternalTransitions {
  my $this = shift;
  
  my $ref_uniqid = shift;
  my $ref_messagesHash = shift;

  my $uniqid = $$ref_uniqid;
  foreach my $schedulerMethod ( $this->timerMethods() ){
    my $at;
    my $adMethod;
    my $adHeadMethod;
    my $basename = $schedulerMethod->name();
    $basename =~ s/^expire_//;
    $schedulerMethod->options("base_name", $basename );
    $schedulerMethod->options("scheduler_msgname", $schedulerMethod->toMessageTypeName("scheduler",$uniqid ) );
    $schedulerMethod->options("event_handler", $schedulerMethod->toRealHandlerName("scheduler",$uniqid ) );
    $schedulerMethod->options("event_head_handler", $schedulerMethod->toRealHeadHandlerName("scheduler",$uniqid ) );
    $schedulerMethod->createSchedulerMessage( $ref_messagesHash, \$at);
    $this->createSchedulerMessageHandler($schedulerMethod);
    $this->push_messages($at); 
    
    $schedulerMethod->createRealTransitionHandler( "scheduler",  $at, $this->name(), $this->asyncExtraField(), \$adMethod );
    $this->push_timerHelperMethods($adMethod);
    $schedulerMethod->createRealTransitionHeadHandler( "scheduler",  $at, $this->name(), $this->asyncExtraField(), \$adHeadMethod );
    $this->push_timerHelperMethods($adHeadMethod);

    my $helpermethod = $schedulerMethod->createTimerHelperMethod($at, $this->asyncExtraField() ); # create scheduler_foo()
    $this->push_timerHelperMethods($helpermethod);
    next if( not defined $schedulerMethod->options("transitions") );
    $uniqid ++;
  }
}
sub generateUpcallTransportDeliverInternalTransitions {
  my $this = shift;
  
  my $ref_uniqid = shift;
  my $ref_messagesHash = shift;

  my $uniqid = $$ref_uniqid;

  return unless $this->useTransport() or $this->hasContexts();

  foreach my $upcallMethod ( grep { $_->name eq "deliver" } $this->usesHandlerMethods() ){
    #deal with transport upcall deliver handler
    my $at;
    my $adMethod;
    my $adHeadMethod;
    my $basename = $upcallMethod->name();

    # TODO: copy the $upcallMethod( deliver( src, dest, foo ) to __deliver( src, dest, foo )

    $upcallMethod->options("base_name", $basename );
    $upcallMethod->options("upcall_msgname", $upcallMethod->toMessageTypeName("upcall_deliver",$uniqid ) );
    $upcallMethod->options("event_handler", $upcallMethod->toRealHandlerName("upcall_deliver",$uniqid ) );
    $upcallMethod->options("event_head_handler", $upcallMethod->toRealHeadHandlerName("upcall_deliver",$uniqid ) );
    my $service_messages = \@{ $this->messages() };
    $upcallMethod->createUpcallMessage( \$at, $service_messages );
    $this->createUpcallDeliverMessageHandler($upcallMethod);
    $this->push_messages($at); 
    
    $upcallMethod->createRealTransitionHandler( "upcall",  $at, $this->name(), $this->asyncExtraField(), \$adMethod );
    $upcallMethod->createRealTransitionHeadHandler( "upcall",  $at, $this->name(), $this->asyncExtraField(), \$adHeadMethod );
    $this->push_upcallHelperMethods($adMethod);
    $this->push_upcallHelperMethods($adHeadMethod);

    $this->createUpcallMessageRedirectHandler( $upcallMethod );
    $upcallMethod->redirectTransportMessage( ); 

    next if( not defined $upcallMethod->options("transitions") );
    $uniqid ++;
  }
}
sub generateUpcallInternalTransitions {
  my $this = shift;
  
  my $ref_uniqid = shift;
  my $ref_messagesHash = shift;

  my $uniqid = $$ref_uniqid;

  foreach my $upcallMethod ( grep { $_->name ne "deliver" and $_->name ne "messageError" and $_->name ne "error" } $this->usesHandlerMethods() ){
    $this->generateServiceCallTransitions("upcall", $upcallMethod, $uniqid );
    $uniqid ++;
  }
}

sub generateDowncallInternalTransitions {
  my $this = shift;
  
  my $ref_uniqid = shift;
  my $ref_messagesHash = shift;

  my $uniqid = $$ref_uniqid;

  my @specialDowncalls = ("maceInit", "maceResume", "maceExit", "maceReset");

  for my $downcallMethod (grep(!($_->name =~ /^(un)?register.*Handler$/), $this->providedMethods())) {
    if( $downcallMethod->name eq "maceInit" ){

    }elsif( $downcallMethod->name eq "maceExit" ){

    }
    #next if( $downcallMethod->name eq "localAddress");
    #next if( $downcallMethod->name eq "hashState");
    next if (scalar(grep {$_ eq $downcallMethod->name} $this->ignores() ));
    #next if (scalar(grep {$_ eq $downcallMethod->name} @specialDowncalls ));
    $this->generateServiceCallTransitions("downcall", $downcallMethod, $uniqid );
    $uniqid ++;
  }
}
sub generateServiceCallTransitions {
    my $this = shift;
    my $transitionType = shift;
    my $demuxMethod = shift;
    my $uniqid = shift;

    $demuxMethod->options("base_name", $demuxMethod->name() );
    $demuxMethod->options( $transitionType . "_msgname", $demuxMethod->toMessageTypeName($transitionType,$uniqid ) );
    $demuxMethod->options("event_handler", $demuxMethod->toRealHandlerName("upcall",$uniqid ) );
    $demuxMethod->options("event_head_handler", $demuxMethod->toRealHeadHandlerName("upcall",$uniqid ) );

    my $helpermethod = Mace::Compiler::Method->new( name=>$demuxMethod->name(), returnType=>$demuxMethod->returnType, isVirtual=>$demuxMethod->isVirtual, isStatic=>$demuxMethod->isStatic, isConst=>$demuxMethod->isConst, throw=>$demuxMethod->throw, line=>$demuxMethod->line, filename=>$demuxMethod->filename, doStructuredLog=>$demuxMethod->doStructuredLog, shouldLog=>$demuxMethod->shouldLog, logClause=>$demuxMethod->logClause, isUsedVariablesParsed=>$demuxMethod->isUsedVariablesParsed, targetContextObject=>$demuxMethod->targetContextObject, body=>"" );
    $helpermethod->params( @{ $demuxMethod->params } ); 
    $helpermethod->usedStateVariables( @{ $demuxMethod->usedStateVariables } );

    $demuxMethod->name("demux_${transitionType}_" . $demuxMethod->options("base_name") );
    if( $transitionType eq "downcall" ){
      $this->push_downcallHelperMethods( $helpermethod );
    }elsif( $transitionType eq "upcall" ){
      $this->push_upcallHelperMethods( $helpermethod );
    }
    my $at;
    my $routineMessageName = $demuxMethod->options( $transitionType . "_msgname" );
    $helpermethod->options("routine_name", $demuxMethod->name() );
    $demuxMethod->options("routine_name", $demuxMethod->name() );

    $demuxMethod->createContextRoutineMessage($transitionType, \$at, $routineMessageName);
    $this->push_messages($at);
    if( $this->hasContexts() > 0 ){
        $this->createUpDowncallMessageHandler( $transitionType, $demuxMethod, $at );
    }else{
        #$this->push_auto_types($at);
    }
    $helpermethod->createContextRoutineHelperMethod( $transitionType,  $at, $routineMessageName, $this->hasContexts(), $this->name );

    $this->generateSpecialTransitions( $helpermethod );
}
sub generateSpecialTransitions {
    my $this = shift;
    my $helpermethod = shift;

    if( $helpermethod->name eq "maceInit" || $helpermethod->name eq "maceResume" ){
        my $registerInstanceUID = "instanceUniqueID = static_cast<uint8_t>(NumberGen::Instance(NumberGen::SERVICE_INSTANCE_UID)->GetVal());";
        my $initServiceVars = join("\n", map{my $n = $_->name(); qq/
            _$n.maceInit();
            if ($n == -1) {
                $n  = NumberGen::Instance(NumberGen::HANDLER_UID)->GetVal();
            }
                                             /;
                                         } grep(not($_->intermediate()), $this->service_variables()));

        my $initResenderTimer = "";
        if($Mace::Compiler::Globals::useFullContext && $this->hasContexts() ){
            $initResenderTimer = "//resender_timer.schedule(params::get<uint32_t>(\"FIRST_RESEND_TIME\", 1000*1000) );";
        }
        my $registerHandlers = "";
        for my $sv ($this->service_variables()) {
            my $svn = $sv->name();
            for my $h ($this->usesHandlerNames($sv->serviceclass)) {
                if ($sv->doRegister($h)) {
                    if ($helpermethod->getLogLevel($this->traceLevel()) > 0) {
                        $registerHandlers .= qq{macecompiler(0) << "Registering handler with regId " << $svn << " and type $h for service variable $svn" << Log::endl;
                                            };
                    }
                    $registerHandlers .= qq{_$svn.registerHandler(($h&)*this, $svn, false);
                                        };
                }
            }
        }
        # chuangw: Only one physical node in a logical node will create STARTEVENT.
        my $apiBody = "
        if(__inited++ == 0) {
            //TODO: start utility timer as necessary
                $registerInstanceUID
                ThreadStructure::ScopedServiceInstance si( instanceUniqueID ); 
                $initServiceVars
                $initResenderTimer
                $registerHandlers
                if( mace::ContextMapping::getHead( contextMapping ) == Util::getMaceAddr() ){
                  $helpermethod->{body}
                }
        }";
      $helpermethod->body( $apiBody );
    }elsif ( $helpermethod->name eq "maceExit" ){
        my $stopTimers = join("\n", map{my $t = $_->name(); "$t.cancel();"} $this->timers());
        
        my $cleanupServices = "";
        for my $sv ($this->service_variables()) {
            my $svn = $sv->name();

            if( $svn eq "__ctx" and $sv->serviceclass eq "Transport" ){
              $cleanupServices .= qq@
              if( ThreadStructure::isOuterMostTransition() ){
                if( mace::ContextMapping::getHead(contextMapping) == Util::getMaceAddr() ){
                  mace::HighLevelEvent& myEvent = ThreadStructure::myEvent();
                  HeadEventDispatch::HeadEventTP::commitEvent( myEvent.eventID, myEvent.eventType, myEvent.eventMessageCount ); 
                  // wait to confirm the event is committed.
                  // remind other physical nodes the exit event has committed.
                  const mace::map< MaceAddr, uint32_t >& nodes = contextMapping.getAllNodes(); 
                  for( mace::map< MaceAddr, uint32_t >::const_iterator nodeIt = nodes.begin(); nodeIt != nodes.end(); nodeIt ++ ){
                    if( nodeIt->first == Util::getMaceAddr() ) continue;
                    __event_exit_committed msg;
                    ASYNCDISPATCH( nodeIt->first, __ctx_dispatcher, __event_exit_committed, msg )
                  }
                }else{
                  // wait for exit event to commit.
                  mace::HighLevelEvent::waitExit();
                }
              }
              @;
            }

            for my $h ($this->usesHandlerNames($sv->serviceclass)) {
                if ($sv->doRegister($h)) {
                    $cleanupServices .= qq{_$svn.unregisterHandler(($h&)*this, $svn);\n};
                }
            }

            if( not $sv->intermediate() ){
              $cleanupServices .= qq{_$svn.maceExit();\n};
            }

            #join("\n", map{my $n = $_->name(); qq{_$n.maceExit();}} grep(not($_->intermediate()), $this->service_variables()));
        } # $this->service_variables()

        my $apiBody = "
        if(--__inited == 0) {
            ThreadStructure::ScopedServiceInstance si( instanceUniqueID ); 

            if( mace::ContextMapping::getHead( contextMapping ) == Util::getMaceAddr() ){
              $helpermethod->{body}
            }

            //TODO: stop utility timer as necessary
            _actual_state = exited;
            $stopTimers
            $cleanupServices
        } ";

      $helpermethod->body( $apiBody );
    } elsif ( $helpermethod->name eq "maceReset" ){
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

        my $apiTail = "
            $helpermethod->{body}
            //TODO: stop utility timer as necessary
            _actual_state = init;
            $stopTimers
            $clearHandlers
            $resetServiceVars
            $resetVars
            __inited = 0;
            instanceUniqueID = 0;
            ";

        $helpermethod->body( $apiTail );
    }}
sub generateAspectInternalTransitions {
  my $this = shift;
  
  my $ref_uniqid = shift;
  my $ref_messagesHash = shift;

  my $uniqid = $$ref_uniqid;
  foreach my $aspectMethod ( $this->aspectMethods() ){

  }
}
sub createMessageHandlers {
  my $this = shift;
  return unless ($this->hasContexts() or $this->useTransport());
  PROCMSG: for my $msg ( $this->messages() ){
    # chuangw: Some auto-generated messages already has delivery handlers defined, but not all. Here are the rest that needs to be handled.
    my $handlerBody;
    my $mname = $msg->{name};
    given( $msg->method_type ){
      when (Mace::Compiler::AutoType::FLAG_NONE)        { next PROCMSG; }
      when (Mace::Compiler::AutoType::FLAG_ASYNC)       { next PROCMSG; } 
      when (Mace::Compiler::AutoType::FLAG_SYNC)        { $handlerBody = $msg->toRoutineMessageHandler($this->hasContexts(), $msg->options('routine') ) }
      when (Mace::Compiler::AutoType::FLAG_SNAPSHOT)    { $handlerBody = $this->snapshotSyncCallHandlerHack( "msg", $msg ); } 
      when (Mace::Compiler::AutoType::FLAG_DOWNCALL)    { next PROCMSG; } 
      when (Mace::Compiler::AutoType::FLAG_RELAYMSG)    { $handlerBody = $this->routeRelayMessageHandler( $msg ); }
      when (Mace::Compiler::AutoType::FLAG_UPCALL  )    { next PROCMSG; }
      when (Mace::Compiler::AutoType::FLAG_TIMER)       { next PROCMSG; } 
      when (Mace::Compiler::AutoType::FLAG_APPUPCALL)   { $handlerBody = $this->deliverAppUpcallMessageHandler( $msg ); }
      when (Mace::Compiler::AutoType::FLAG_APPUPCALLRPC){ next PROCMSG; } # not used?
      when (Mace::Compiler::AutoType::FLAG_APPUPCALLREP){ $handlerBody = $this->deliverAppUpcallResponseMessageHandler( $msg ); }
      when (Mace::Compiler::AutoType::FLAG_CONTEXT)     { next PROCMSG; } 
      
    }

    $this->createMessageHandler( $mname, $handlerBody, "" ); 
  }
}
sub createAsyncMessageHandler {
    my $this = shift;
    my $m = shift;

    # TODO: this is necessary only if Transport is used
    return if (not $this->useTransport() );
    my $event_handler = $m->options("event_handler");
    my $event_head_handler = $m->options("event_head_handler");
    my $name = $this->name();
    my $ptype = $m->options("async_msgname");

    my $deliverBody = "
if( msg.extra.isRequest ){
  HeadEventDispatch::HeadEventTP::executeEvent( this, (HeadEventDispatch::eventfunc)&${name}_namespace::${name}Service::$event_head_handler, (void*) new $ptype(msg) );
}else{
  $event_handler ( msg , source.getMaceAddr() );
}
//mace::AgentLock::checkTicketUsed(); 
    ";
    my $messageErrorBody = "//mace::AgentLock::checkTicketUsed();";
    $this->createMessageHandler($m->options("async_msgname"), $deliverBody, $messageErrorBody );
}
sub createSchedulerMessageHandler {
    my $this = shift;
    my $m = shift;

    # TODO: this is necessary only if Transport is used
    return if (not $this->useTransport() );
    my $event_handler = $m->options("event_handler");
    my $event_head_handler = $m->options("event_head_handler");
    my $name = $this->name();
    my $ptype = $m->options("scheduler_msgname");
    my $deliverBody = "
if( msg.extra.isRequest ){
  HeadEventDispatch::HeadEventTP::executeEvent( this, (HeadEventDispatch::eventfunc)&${name}_namespace::${name}Service::$event_head_handler, (void*) new $ptype(msg) );
}else{
  $event_handler ( msg , source.getMaceAddr() );
}
//mace::AgentLock::checkTicketUsed(); 
    ";
    my $messageErrorBody = "//mace::AgentLock::checkTicketUsed();";
    $this->createMessageHandler($m->options("scheduler_msgname"), $deliverBody, $messageErrorBody );
}
sub createUpcallMessageRedirectHandler {
    my $this = shift;
    my $m = shift;

    # TODO: this is necessary only if Transport is used
    return if (not $this->useTransport() );
    my $event_head_handler = $m->options("event_head_handler");
    my $msgtype = ${ $m->params }[2]->type->type;
    my $name = $this->name();
    my $ptype = $m->options("upcall_msgname");
    my $origmsg;
    my $redirectmsg;
    map { $origmsg = $_ if $_->name eq $msgtype } ( grep { $_->method_type == Mace::Compiler::AutoType::FLAG_NONE} $this->messages() );
    map { $redirectmsg = $_ if $_->name eq $ptype }( grep { $_->method_type == Mace::Compiler::AutoType::FLAG_UPCALL} $this->messages() );
    my @msgparams;
    my $param_source = ${ $m->params }[0]->name;
    my $param_destination = ${ $m->params }[1]->name;
    my $param_rid = ${ $m->params }[3]->name;

    my @params = ($param_source, $param_destination, $param_rid );
    my $param_msg = ${ $m->params }[2]->name;
    map { push @params, "$param_msg." . $_->name } @{ $origmsg->fields() };
    push @params, "extra";

    my $contextToStringCode = $m->generateContextToString();
    my $deliverRedirectBody = "
ThreadStructure::ScopedServiceInstance si( instanceUniqueID );
if( ThreadStructure::isOuterMostTransition()&& !mace::HighLevelEvent::isExit ){
  $contextToStringCode
  mace::HighLevelEvent dummyEvent( static_cast<uint64_t>(0) );
  __asyncExtraField extra(targetContextID, snapshotContextIDs, dummyEvent, true);
  $ptype __msg( " . join(",", @params ) . " );
  HeadEventDispatch::HeadEventTP::executeEvent( this, (HeadEventDispatch::eventfunc)&${name}_namespace::${name}Service::$event_head_handler, (void*) new $ptype( __msg) );
  return;
  //mace::AgentLock::checkTicketUsed(); 
}
    ";
    $m->options("redirect", $deliverRedirectBody );
}
sub createUpcallDeliverMessageHandler {
    my $this = shift;
    my $m = shift;

    # TODO: this is necessary only if Transport is used
    return if (not $this->useTransport() );
    my $event_handler = $m->options("event_handler");
    my $deliverBody = "
ASSERT( !msg.extra.isRequest );
$event_handler ( msg , source.getMaceAddr() );
//mace::AgentLock::checkTicketUsed(); 
    ";
    my $messageErrorBody = "//mace::AgentLock::checkTicketUsed();";
    $this->createMessageHandler($m->options("upcall_msgname"), $deliverBody, $messageErrorBody );
}
sub createUpDowncallMessageHandler {
    my $this = shift;
    my $transitionType = shift;
    my $m = shift;
    my $message = shift;
    
    # TODO: this is necessary only if Transport is used
    return if (not $this->useTransport() );
    my $deliverBody = $message->toRoutineMessageHandler($this->hasContexts(), $message->options('routine') );
    my $messageErrorBody = "//mace::AgentLock::checkTicketUsed();";
    $this->createMessageHandler($m->options( $transitionType . "_msgname"), $deliverBody, $messageErrorBody );
}
sub createMessageHandler {
  my $this = shift;
  my $msgtype = shift;
  my $deliverBody = shift;
  my $messageErrorBody = shift;

    my $voidType = Mace::Compiler::Type->new( type => "void"  );

    # add a new transition and make a copy of the method
    my $deliverMethod = Mace::Compiler::Method->new(
        body => $deliverBody, 
        throw => undef,
        #filename => $m->filename,
        isConst => 0, 
        isUsedVariablesParsed => 0,
        isStatic => 0, 
        name => "deliver",
        returnType => $voidType,
        #line => $m->line,
        );
    # chuangw: don't ContextLock on async/sync call message handler.
    $deliverMethod->options('nocontext',1);

    my $deliverMaceKeyType = Mace::Compiler::Type->new(type=>"MaceKey",isConst=>1,isConst1=>0,isConst2=>0,isRef=>1);
    my $deliverMessageType = Mace::Compiler::Type->new(type=>$msgtype,isConst=>1,isConst1=>0,isConst2=>0,isRef=>1);
    my $deliverRegistrationType = Mace::Compiler::Type->new(type=>"registration_uid_t",isConst=>0,isConst1=>0,isConst2=>0,isRef=>0);
    my $deliverParam1 = Mace::Compiler::Param->new(name => "source", type => $deliverMaceKeyType);
    my $deliverParam2 = Mace::Compiler::Param->new(name => "destination", type => $deliverMaceKeyType);
    my $deliverParam3 = Mace::Compiler::Param->new(name => "msg", type => $deliverMessageType);
    my $deliverParam4 = Mace::Compiler::Param->new(name => "rid", type => $deliverRegistrationType);
    $deliverMethod->push_params( ($deliverParam1, $deliverParam2, $deliverParam3, $deliverParam4) );

    my $t = Mace::Compiler::Transition->new(name=> $deliverMethod->name,
    startFilePos => -1, #($thisparser->{local}{update} ? -1 : $item{StartPos}),
    columnStart => -1,  #$item{StartCol}, 
    type => "upcall", 
    method => $deliverMethod,
    startFilePos => -1,
    columnStart => '-1',
    );
    $this->push_transitions( $t );

    return $t;

    #chuangw: don't add default messageError transition handler.
=begin
    # add a new transition and make a copy of the method
    my $messageErrorMethod = Mace::Compiler::Method->new(
        body => $messageErrorBody, 
        throw => undef,
        filename => $m->filename,
        isConst => 0, 
        isUsedVariablesParsed => 0,
        isStatic => 0, 
        name => "messageError",
        returnType => $voidType,
        line => $m->line,
        );
    # chuangw: don't ContextLock on async/sync call message handler.
    $messageErrorMethod->options('nocontext',1);

    my $messageErrorMaceKeyType = Mace::Compiler::Type->new(type=>"MaceKey",isConst=>1,isConst1=>0,isConst2=>0,isRef=>1);
    my $messageErrorErrorType = Mace::Compiler::Type->new(type=>"TransportError::type",isConst=>0,isConst1=>0,isConst2=>0,isRef=>0);
    my $messageErrorMessageType = Mace::Compiler::Type->new(type=>$m->options("async_msgname"),,isConst=>1,isConst1=>0,isConst2=>0,isRef=>1);
    my $messageErrorRegistrationType = Mace::Compiler::Type->new(type=>"registration_uid_t",isConst=>0,isConst1=>0,isConst2=>0,isRef=>0);
    my $messageErrorParam1 = Mace::Compiler::Param->new(name => "dest", type => $messageErrorMaceKeyType);
    my $messageErrorParam2 = Mace::Compiler::Param->new(name => "errorCode", type => $messageErrorErrorType);
    my $messageErrorParam3 = Mace::Compiler::Param->new(name => "msg", type => $messageErrorMessageType);
    my $messageErrorParam4 = Mace::Compiler::Param->new(name => "rid", type => $messageErrorRegistrationType);
    $messageErrorMethod->push_params( ($messageErrorParam1, $messageErrorParam2, $messageErrorParam3, $messageErrorParam4) );

    my $t2 = Mace::Compiler::Transition->new(name => $messageErrorMethod->name, 
    startFilePos => -1, #($thisparser->{local}{update} ? -1 : $item{StartPos}),
    columnStart => -1,  #$item{StartCol}, 
    type => "upcall", 
    method => $messageErrorMethod,
    startFilePos => -1,
    columnStart => '-1',
    );
    $this->push_transitions( $t2 );
=cut
}
sub validate_findAsyncMethods {
    my $this = shift;
    my $name = $this->name();

    my $uniqid = 0;
    foreach my $transition ($this->transitions()) {
        if ($transition->type() eq 'async') {
            my $origmethod;
            unless(ref ($origmethod = Mace::Compiler::Method::containsTransition($transition->method, $this->asyncMethods()))) {
                my $pname = $transition->method->name;

                $origmethod = ref_clone($transition->method());
                my $v = Mace::Compiler::Type->new('type'=>'void');
                $origmethod->returnType($v);
                $origmethod->body("");
                $this->push_asyncMethods($origmethod);

            }
        }
    }

}

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

sub generateGetContextByIDCode {
    my $this = shift;

    my $findContextStr = qq@
    ScopedLock sl(getContextObjectMutex);
    mace::hash_map< uint32_t, mace::ContextBaseClass*, mace::SoftState >::const_iterator cpIt = ctxobjIDMap.find( contextID );
    if( cpIt == ctxobjIDMap.end() ){
      maceerr<<"context ID "<< contextID << " not found! Available context objects are: ";
      for( mace::hash_map< uint32_t, mace::ContextBaseClass*, mace::SoftState >::const_iterator it = ctxobjIDMap.begin(); it!= ctxobjIDMap.end(); it++){
        maceerr<< it->first << " ==> " << it->second->contextID ;
      }
      maceerr<< Log::endl;
      ABORT( "context id not found" );
    }

    return cpIt->second;
    @;

    return $findContextStr;
}
sub generateGetContextByNameCode {
    my $this = shift;

    my $findContextStr = qq@
    ScopedLock sl(getContextObjectMutex);
    mace::hash_map< mace::string, mace::ContextBaseClass*, mace::SoftState >::const_iterator cpIt = ctxobjNameMap.find( contextName );
    if( cpIt == ctxobjNameMap.end() ){
      maceerr<<"context name "<< contextName << " not found! Available context objects are: ";
      for( mace::hash_map< mace::string, mace::ContextBaseClass*, mace::SoftState >::const_iterator it = ctxobjNameMap.begin(); it!= ctxobjNameMap.end(); it++){
        maceerr<< it->first << " ==> " << it->second->contextID;
      }
      maceerr<< Log::endl;
      ABORT( "context name not found" );
    }
    return cpIt->second;
    @;

    return $findContextStr;
}
sub generateCreateContextCode {
    my $this = shift;

    my $condstr= "";
    if( $this->hasContexts()  ){
        $condstr = "size_t ctxStrsLen = ctxStrs.size();\n";
    }
    $condstr .= join("else ", map{ $_->locateChildContextObj( 0, "self"); } ${ $this->contexts() }[0]->subcontexts() );

    my $globalContextClassName = ${ $this->contexts()}[0]->className();

    my $findContextStr = qq@
    mace::hash_map< mace::string, mace::ContextBaseClass*, mace::SoftState >::const_iterator cpIt = ctxobjNameMap.find( contextName );
    ASSERT ( cpIt == ctxobjNameMap.end()  );

    $this->{name}Service *self = const_cast<$this->{name}Service *>( this );
    uint64_t eventID = ThreadStructure::myEvent().eventID;
    mace::ContextBaseClass* ctxobj = NULL;
    if( contextName.empty() ){ // global context id
        ASSERT( self->globalContext == NULL );
        if( mace::AgentLock::getCurrentMode() != mace::AgentLock::WRITE_MODE &&
          mace::ContextBaseClass::headContext.getCurrentMode() != mace::ContextLock::WRITE_MODE ){
          ABORT("It requires in AgentLock::WRITE_MODE or head node write lock to create a new context object!" );
        }
        // TODO: calculate the parent context id
        const mace::ContextMapping& snapshotMapping = contextMapping.getSnapshot();
        mace::vector< uint32_t > parentContextIDs;
        uint32_t parentID = contextID;
        while( (parentID = snapshotMapping.getParentContextID( parentID ) ) != 0 ){
          parentContextIDs.push_back( parentID );
        }
        ScopedLock sl(getContextObjectMutex);
        self->globalContext = new $globalContextClassName(contextName, eventID, instanceUniqueID, contextID, parentContextIDs );
        self->ctxobjNameMap[ contextName ] = self->globalContext;
        self->ctxobjIDMap[ contextID ] = self->globalContext;
        return self->globalContext ;
    }
    mace::string contextDebugID, contextDebugIDPrefix;
    std::vector<std::string> ctxStrs;
    boost::split(ctxStrs, contextName, boost::is_any_of("."), boost::token_compress_on);

    std::vector<std::string> ctxStr0;
    boost::split(ctxStr0, ctxStrs[0], boost::is_any_of("[,]") );
    $condstr
    ASSERTMSG( ctxobj != NULL, "createContextObject returns a NULL pointer!");
    return ctxobj;
    @;

    return $findContextStr;
}
sub createSnapShotSyncHelper {
# chuangw: this subroutine creates getContextSnapshot()
    my $this = shift;

    my $snapshotType = Mace::Compiler::Type->new(type=>"mace::map<uint32_t, mace::string>",isConst=>0,isConst1=>0,isConst2=>0,isRef=>0);
    my $returnType = Mace::Compiler::Type->new(type=>"void",isConst=>0,isConst1=>0,isConst2=>0,isRef=>0);
    my $contextIDType = Mace::Compiler::Type->new(type=>"mace::string",isConst=>1,isConst1=>0,isConst2=>0,isRef=>1);
    my $contextIDVectorType = Mace::Compiler::Type->new(type=>"mace::vector< uint32_t >",isConst=>1,isConst1=>0,isConst2=>0,isRef=>1);
    my $msgContextIDType = Mace::Compiler::Type->new(type=>"uint32_t",isConst=>0,isConst1=>0,isConst2=>0,isRef=>0);
    my $msgSnapshotContextIDType = Mace::Compiler::Type->new(type=>"mace::vector<uint32_t>",isConst=>0,isConst1=>0,isConst2=>0,isRef=>0);
    my $responseType = Mace::Compiler::Type->new(type=>"bool",isConst=>0,isConst1=>0,isConst2=>0,isRef=>0);
    
    my $targetContextField = Mace::Compiler::Param->new(name=>"targetContextID", type=>$msgContextIDType);
    my $snapshotContextField = Mace::Compiler::Param->new(name=>"snapshotContextID",  type=>$contextIDVectorType);
    my $msgSnapshotContextField = Mace::Compiler::Param->new(name=>"snapshotContextID",  type=>$msgSnapshotContextIDType);

    my $msgName = "__sync_at_snapshot"; 
    my $at = Mace::Compiler::AutoType->new(name=> $msgName, line=>__LINE__, filename => __FILE__, 
            method_type=>Mace::Compiler::AutoType::FLAG_SNAPSHOT);
    my $snapshotField = Mace::Compiler::Param->new(name=>"contextSnapshot",  type=>$snapshotType);
    my $msgSeqType = Mace::Compiler::Type->new(type=>"uint32_t",isConst=>0,isConst1=>0,isConst2=>0,isRef=>0);
    my $msgSeqField = Mace::Compiler::Param->new(name=>"seqno", type=>$msgSeqType);
    my $eventIDType = Mace::Compiler::Type->new(type=>"uint64_t",isConst=>0,isConst1=>0,isConst2=>0,isRef=>0);
    my $eventIDField = Mace::Compiler::Param->new(name=>"eventID", type=>$eventIDType);
    my $eventMappingVersionField = Mace::Compiler::Param->new(name=>"eventContextMappingVersion", type=>$eventIDType);
    my $responseField = Mace::Compiler::Param->new(name=>"response", type=>$responseType);
    $at->fields( $responseField, $eventIDField, $eventMappingVersionField, $targetContextField, $msgSnapshotContextField, $snapshotField  );
    if( $this->hasContexts() ){
        $this->push_messages($at);
    }else{
        $this->push_auto_types($at);
    }

    my @paramArray;
    my $copyParam;
    for my $atparam ($at->fields()){
        given( $atparam->name ){
            when ("eventID") { push @paramArray, "ThreadStructure::myEvent().eventID"; }
            when ("response") { push @paramArray, "true"; }
            default { push @paramArray, $atparam->name; }
        }
    }
    $copyParam = join(",", @paramArray );
    my $wrapperBody;
    my $helperBody = qq#
    {
      uint32_t nsnapshot = snapshotContextID.size();
      uint32_t receivedSnapshots = 0;
      while( receivedSnapshots < nsnapshot ){
        //uint32_t recvContextID;
        //mace::string recvContextSnapshot;
        //mace::ContextSnapshot::receive(recvContextID, recvContextSnapshot);
        //mace::ContextBaseClass * contextObject = getContextObjByID( recvContextID );
        //mace::deserialize( recvContextSnapshot, contextObject);
        receivedSnapshots++;
      }
    }
      #;
    my $snapshotMethod = Mace::Compiler::Method->new(name=>"getContextSnapshot",  returnType=>$returnType, body=>$helperBody, isConst=>1);
    $snapshotMethod->params( ($snapshotContextField) );
    $this->push_routineHelperMethods($snapshotMethod);
}

sub createRoutineDowngradeHelperMethod {
    my $this = shift;
    my $routine = shift;
    my $uniqid = shift;

    if( defined $routine->options('origtransition') ){
      my $helpermethod = $routine->createRoutineDowngradeHelperMethod();
      $this->push_routineHelperMethods($helpermethod);
    }
}

sub createContextRoutineHelperMethod {
    my $this = shift;
    my $routine = shift;
    my $routineMessageNames = shift;
    my $uniqid = shift;

    my $pname = $routine->name;
    my $returnType = $routine->returnType->type;
    my $routineMessageName = "__routine_at_${pname}_${uniqid}";

    #if( $routine->name eq "make_routing_decision" ){
    #  print "locking: " . Dumper ($routine ) . "\n";
    #}

    my $helpermethod = ref_clone($routine);

    my $at;
    if( $this->hasContexts() > 0 ){
        push( @{$routineMessageNames}, $routineMessageName );
        $routine->createContextRoutineMessage("routine", \$at, $routineMessageName);
        $this->push_messages($at);
    }
    $routine->createContextRoutineHelperMethod( "routine", $at, $routineMessageName, $this->hasContexts(),$this->name  );
    $this->createRoutineDowngradeHelperMethod( $routine, $this->hasContexts, $uniqid);

    $helpermethod->name("routine_$pname");

    my @currentContextVars = ();
    $helpermethod->printTargetContextVar(\@currentContextVars, ${ $this->contexts() }[0] );
    $helpermethod->printSnapshotContextVar(\@currentContextVars, ${ $this->contexts() }[0] );

    my $contextAlias = join("\n", @currentContextVars);

    my $realBody = qq#{
        $contextAlias
        $helpermethod->{body}
    }
    #;
    $this->matchStateChange(\$realBody);
    $helpermethod->body( $realBody );
    $this->push_routineHelperMethods($helpermethod);
}
sub createRouteRelayHandler {
    my $this = shift;
    my $message = shift;
    my $pname = shift;

    my $adMethod;
    $message->createRouteRelayHandler(  $pname, \$adMethod  );
    $this->push_asyncDispatchMethods( $adMethod  );
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
                downcall_route( MaceKey( mace::ctxnode, contextMapping.getNodeByContext(unAckPeers->first) ), *msg ,__ctx );
                delete msg;
            }
         }
        }#;
        $resenderHandler->body($resenderHandlerBody );
    }
}

sub createTransportRouteRelayMessages {
  my $this = shift;

  # For each user-defined messages, create an automatically generated relay message.
  foreach my $message( grep{ $_->method_type == Mace::Compiler::AutoType::FLAG_NONE} $this->messages()  ){
    my $deliverMessageName =  "__relay_at_$message->{name}";
         
    my $deliverat = Mace::Compiler::AutoType->new(name=> $deliverMessageName, line=>$message->line(), filename => $message->filename(), method_type=>Mace::Compiler::AutoType::FLAG_RELAYMSG);

    my $destType = Mace::Compiler::Type->new(type=>"MaceKey",isConst=>0,isConst1=>0,isConst2=>0,isRef=>0);
    my $dest = Mace::Compiler::Param->new( name=> "__real_dest", type=>$destType );
    my $regIdType = Mace::Compiler::Type->new(type=>"registration_uid_t",isConst=>0,isConst1=>0,isConst2=>0,isRef=>0);
    my $regId = Mace::Compiler::Param->new( name=> "__real_regid", type=>$regIdType );
    my $eventType = Mace::Compiler::Type->new(type=>"uint64_t",isConst=>0,isConst1=>0,isConst2=>0,isRef=>0);
    my $event = Mace::Compiler::Param->new( name=> "__event", type=>$eventType );
    my $msgcountType = Mace::Compiler::Type->new(type=>"uint32_t",isConst=>0,isConst1=>0,isConst2=>0,isRef=>0);
    my $msgcount = Mace::Compiler::Param->new( name=> "__msgcount", type=>$eventType );

    $deliverat->push_fields( $dest, $regId, $event, $msgcount   );
    for my $op ($message->fields()) {
        my $mp= ref_clone($op);
        if( defined $mp->type ){
            $mp->type->isConst(0);
            $mp->type->isConst1(0);
            $mp->type->isConst2(0);
            $mp->type->isRef(0);
            $deliverat->push_fields($mp);
        }
    }
    $this->push_messages( $deliverat );
    $this->createRouteRelayHandler($deliverat, $message->{name} );
  }
}
sub createAsyncExtraField {
    my $this = shift;

    # if there are no async transitions, don't do it.
    my $hasAsyncTransition = 0;
    for( $this->transitions() ){
        if(($_->type() eq "async" or
            $_->type() eq "downcall" or
            $_->type() eq "upcall" or
            $_->type() eq "scheduler" )
        ){
            if( defined $_->method->targetContextObject() and
            $_->method->targetContextObject() ne "__internal" and
            $_->method->targetContextObject() ne "" ){
                $hasAsyncTransition ++;
                }
        }
    }
    # create AutoType used by async calls. 
    for( $this->auto_types() ){
        if( $_->name() eq "__asyncExtraField" ){
          Mace::Compiler::Globals::error("reserved_autotypes", $_->filename() , $_->line(), "auto type '__asyncExtraField' is a reserved name.");
        }
    }
    my $contextIDType = Mace::Compiler::Type->new(type=>"mace::string",isConst=>0,isConst1=>0,isConst2=>0,isRef=>0);
    my $snapshotContextIDType = Mace::Compiler::Type->new(type=>"mace::set<mace::string>",isConst=>0,isConst1=>0,isConst2=>0,isRef=>0);
    my $eventType = Mace::Compiler::Type->new(type=>"mace::HighLevelEvent",isConst=>0,isConst1=>0,isConst2=>0,isRef=>0);
    my $isRequestType = Mace::Compiler::Type->new(type=>"bool",isConst=>0,isConst1=>0,isConst2=>0,isRef=>0);

    my $targetContextField = Mace::Compiler::Param->new(name=>"targetContextID",  type=>$contextIDType);
    my $snapshotContextsField = Mace::Compiler::Param->new(name=>"snapshotContextIDs",  type=>$snapshotContextIDType);
    my $eventField = Mace::Compiler::Param->new(name=>"event",  type=>$eventType);
    my $isRequestField = Mace::Compiler::Param->new(name=>"isRequest",  type=>$isRequestType);

    my $asyncExtraField = Mace::Compiler::AutoType->new(name=> "__asyncExtraField", line=>__LINE__, filename => __FILE__ );

    $asyncExtraField->fields( ($targetContextField, $snapshotContextsField, $eventField, $isRequestField ) );
    $this->push_auto_types($asyncExtraField);
    # TODO: chuangw: move asyncExtraField to lib/ because all fullcontext services will use the same auto type.
    $this->asyncExtraField( $asyncExtraField );
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
    my $ref_providesMethods = shift;
    my $ref_providesHandlers = shift;
    my $ref_providesHandlersMethods = shift;

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
    @{ $ref_providesMethods } = map {$_->isVirtual(0); $_} (grep {$_->isVirtual() && $_->name() ne "getLogType"} Mace::Compiler::ClassCache::unionMethods(@provides));
    for my $m (@{ $ref_providesMethods} ) {
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
        } elsif ($m->name eq "requestContextMigration") {

    my $requestContextMigrationMethod= "";
    if( $this->hasContexts() ) {
        $requestContextMigrationMethod = qq#
            //ASSERTMSG( contextMapping.getHead() == Util::getMaceAddr(), "Context migration is requested, but this physical node is not head node." );
            // 1. create ticket to acquire AgentLock
            ThreadStructure::newTicket(); 

            mace::HighLevelEvent& newEvent = ThreadStructure::myEvent( );
            // 2. acquire AgentLock, and then get the event ID. Remember to release AgentLock right after.
            mace::AgentLock alock( mace::AgentLock::WRITE_MODE ); // this lock is used to make sure the event is created in order.
            newEvent.newEventID( mace::HighLevelEvent::MIGRATIONEVENT );
            alock.downgrade( mace::AgentLock::NONE_MODE );

            // 3. acquire the head context lock. Then initializes the migration event
            mace::ContextLock clock( mace::ContextBaseClass::headContext, mace::ContextLock::WRITE_MODE );

            newEvent.initialize(  );

            // 4. Get the latest contextmap snapshot to determine the existence of context.
            //    If it doesn't exist, just store the context and the destination node as the default mapping
            //    so that when the context is created in the future, it will be created at that node.
            const ContextMapping& ctxmapSnapshot = contextMapping.getSnapshot( );
            if( !contextMapping.hasContext( contextID ) ){
              maceout<<"Requested context does not exist. Ignore it but set it as the default mapping when the context is created in the future."<<Log::endl;
              mace::map<mace::MaceAddr ,mace::list<mace::string > > servContext;
              servContext[ destNode ].push_back( contextID );
              contextMapping.loadMapping( servContext );
              clock.downgrade( mace::ContextLock::NONE_MODE );
              HeadEventDispatch::HeadEventTP::commitEvent( newEvent.eventID, newEvent.eventType, newEvent.eventMessageCount ); // commit
              return;
            }
            const MaceAddr& origNode = mace::ContextMapping::getNodeByContext( ctxmapSnapshot, contextID );
            // 5. Ok. Let's roll.
            //    Create a new version of context map. Update the event skip id
            mace::HighLevelEvent::setLastContextMappingVersion( newEvent.eventID );
            const uint64_t prevContextMappingVersion = newEvent.eventContextMappingVersion;
            newEvent.eventContextMappingVersion = newEvent.eventID; // switch to the new context mapping version

            contextEventRecord.updateContext( contextID, newEvent.eventID, newEvent.getSkipIDStorage( instanceUniqueID ) );

            // If rootOnly is true, migrate just one context
            // Otherwise, migrate the entire subtree. All contexts in the subtree will be migrated to the same node.
            mace::map< uint32_t, mace::string > offsprings;
            if( rootOnly ){
              std::pair<bool, uint32_t>  updatedContext = contextMapping.updateMapping( destNode, contextID ); 
              offsprings[ updatedContext.second ] =  contextID;
            }else{ // TODO: also update the mapping of child & all offspring contexts.
              // right now: support migrating the entire context subtree only if they all reside on the same physical node.
              offsprings = ContextMapping::getSubTreeContexts( ctxmapSnapshot, contextID );
              mace::set< mace::string > offspringContextNames;
              for( mace::map< uint32_t, mace::string >::iterator osIt = offsprings.begin(); osIt != offsprings.end(); osIt ++ ){
                offspringContextNames.insert( osIt->second );
              }
              
              contextMapping.updateMapping< mace::set<mace::string> >( destNode, offspringContextNames );
            }
            const mace::ContextMapping* ctxmapCopy = contextMapping.snapshot( ); // after the update, create ctxmap snapshot
            ASSERT( ctxmapCopy != NULL );
            macedbg(1)<<" The new version "<< newEvent.eventContextMappingVersion << " context map: "<< *ctxmapCopy << Log::endl;
             

            // notify other services about the new context
            BaseMaceService::globalNotifyNewContext( instanceUniqueID );
            BaseMaceService::globalNotifyNewEvent( instanceUniqueID );

            // 6. Store this event and arguments for implementing failure recovery
            //    Commented because we are not implementing failure recovery now.
            /*mace::string dummybuf;
            mace::serialize( dummybuf, &newEvent.getEventType() );
            mace::serialize( dummybuf, &serviceID );
            mace::serialize( dummybuf, &contextID );
            mace::serialize( dummybuf, &destNode );
            mace::serialize( dummybuf, &rootOnly );
            mace::HierarchicalContextLock hl(newEvent, dummybuf );*/

            // 7. get the list of nodes belonging to the same logical node after the migration
            //    Send message to them to tell them a new context map is available, and create the new context object
            const mace::map < MaceAddr, uint32_t >& physicalNodes = contextMapping.getAllNodes(); 
            macedbg(1)<< "The logical node is composed of: "<< physicalNodes << Log::endl;
            AllocateContextObject allocateCtxMsg( destNode, offsprings, ThreadStructure::myEvent().eventID, *ctxmapCopy , 1);


            // chuangw: hack. make sure absolutely that the context object is created 
            ScopedLock sl( ContextObjectCreationMutex );
            for( mace::map<MaceAddr, uint32_t>::const_iterator nodeIt = physicalNodes.begin(); nodeIt != physicalNodes.end(); nodeIt ++ ){ // chuangw: this message has to be sent to all nodes of the same logical node to update the context mapping.
              ASYNCDISPATCH( nodeIt->first, __ctx_dispatcher, AllocateContextObject, allocateCtxMsg )
            }
            
            pthread_cond_wait( &ContextObjectCreationCond, &ContextObjectCreationMutex );

            sl.unlock();

            mace::vector< mace::string > nextHops;
            nextHops.push_back( contextID );
            ContextMigrationRequest msg( contextID, destNode, rootOnly, ThreadStructure::myEvent(), prevContextMappingVersion , nextHops );
            ASYNCDISPATCH( origNode , __ctx_dispatcher, ContextMigrationRequest , msg );

            clock.downgrade( mace::ContextLock::NONE_MODE );

        #;
    }else{
        $requestContextMigrationMethod = qq#
          maceerr<<"Single context service does not support migration."<<Log::endl;
          ABORT("Single context service does not support migration.");
        #;
    }
    my $lowerServiceMigrationRequest = join("\n", map{my $n = $_->name(); qq/
        _$n.requestContextMigration( serviceID, contextID, destNode, rootOnly); /;
     } grep( (not($_->intermediate()) and $_->serviceclass ne "Transport"), $this->service_variables()));
        $m->body( qq#
      if( serviceID == instanceUniqueID ){
        $requestContextMigrationMethod
      }else{
        $lowerServiceMigrationRequest
      }
      # );
        } elsif ($m->name eq "evict") {

        my $lowerServiceEvict = join("\n", map{my $n = $_->name(); qq/
            _$n.evict( ); /;
         } grep( (not($_->intermediate()) and $_->serviceclass ne "Transport"), $this->service_variables()));

          $m->body("\n{ 
if( mace::ContextMapping::getHead( contextMapping ) == Util::getMaceAddr() ){ // if head gets SIGTERM, initiates head migration 
  // TODO: decide a new node
  // let the new node to be prepared
  // --> notify the job scheduler. job scheduler tells the new head to stand by.


  // TODO: If there are other contexts shared on the head node, migrate them as well.

  return;
}


__event_evict e;
ASYNCDISPATCH( contextMapping.getHead() , __ctx_dispatcher, __event_evict , e );
$lowerServiceEvict
          }\n");
        }
#        elsif ($m->name eq "registerInstance") {
#            $m->options('trace','off');
#            my $registerInstance = join("\n", map{ qq/mace::ServiceFactory<${_}ServiceClass>::registerInstance("$name", this);/ } $this->provides());
#            $m->body("\n{\n $registerInstance \n}\n");
#        }
    }

    #Two copies, one for remapped methods, one for the original (and external) API
    #Provided Methods are the API methods of service classes we provide.
    $this->providedMethods(@{$ref_providesMethods});
    $this->providedMethodsAPI(@{$ref_providesMethods});

    #providedHandlers is the list of handler classes of the service classes we provide
    @{ $ref_providesHandlers } = Mace::Compiler::ClassCache::getHandlers($this->provides());
    $this->providedHandlers(@{ $ref_providesHandlers } );

    #providesHandlersMethods is the flattening of those methods
    @{ $ref_providesHandlersMethods } = Mace::Compiler::ClassCache::unionMethods(@{ $ref_providesHandlers} );
    $this->providedHandlerMethods(@{ $ref_providesHandlersMethods} );
}

sub validate_parseUsedAPIs {
    my $this = shift;
    my $orig_usesClassMethods = shift;
    my $orig_usesHandlerMethods = shift;

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
    @{ $orig_usesHandlerMethods } = map {$_->isVirtual(0); $_} (grep {$_->isVirtual()} Mace::Compiler::ClassCache::unionMethods(@usesHandlers));
    $this->usesHandlerMethods( @{ $orig_usesHandlerMethods } );
    $this->usesHandlerMethodsAPI( @{ $orig_usesHandlerMethods } );

    #my @usesMethods = grep(!($_->name =~ /^((un)?register.*Handler)|(mace(Init|Exit|Resume|Reset))|localAddress|hashState|registerInstance|getLogType$/), Mace::Compiler::ClassCache::unionMethods(@uses));
    @{ $orig_usesClassMethods } = grep(!($_->name =~ /^((un)?register.*Handler)|(mace(Init|Exit|Resume|Reset))|localAddress|hashState|requestContextMigration|evict|registerInstance|getLogType$/), Mace::Compiler::ClassCache::unionMethods(@uses));
    $this->usesClassMethods( @{ $orig_usesClassMethods } );

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
    my %args = @_;


    my $requireOPDefault = $args{"requireOPDefault"};
    my $allowRemapDefault = $args{"allowRemapDefault"};
    my $pushOntoSerials = $args{"pushOntoSerials"};
    my $includeMessageInSerial = $args{"includeMessageInSerial"};
    my $internalRemapOnly = $args{"internalRemapOnly"};

    my $doGrep = 0;

    #print "size of methodset" . @{ $this->$methodset() } . "\n";

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
            #print "has the transition already-->" . $method->toString(noline=>1) . ", origmethod=" . $origmethod . "\n";
            next;
        }
        if (defined $method->options('trace')) {
            $origmethod->options('trace', $method->options('trace'));
        }
        #print "-->" . $method->toString(noline=>1) . "\n";
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
              if( $internalRemapOnly ){
                @serialForms = $method->getSerialForms("Message", map{$_->name()} 
                  (grep {$_->method_type != Mace::Compiler::AutoType::FLAG_NONE  } $this->messages()) );
              }else{
                @serialForms = $method->getSerialForms("Message", map{$_->name()} $this->messages());
              }
            } else{
              if( $internalRemapOnly ){
              #foreach (grep {$_->method_type != Mace::Compiler::AutoType::FLAG_NONE  } $this->messages()){
              #  print "msg: " . $_->name . "\n";
              #}
                @serialForms = $method->getSerialForms(map{$_->name()} 
                  (grep {$_->method_type != Mace::Compiler::AutoType::FLAG_NONE  } $this->messages()));
                
                #map { print "internal transitions-->" . $_->toString(noline=>1) . "\n"; } @serialForms ;

              }else{
                @serialForms = $method->getSerialForms(map{$_->name()} $this->messages());
              }
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
        #$this->matchStateChange(\$t);
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

    #my @contexts = $this->contexts();
    $transition->validate( $this->contexts()  ,$this->selectors());
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
        #my @svar = grep($monitorVar eq $_->name, @{$this->state_variables()}, $stateParam);
        my @svar = grep($monitorVar eq $_->name, @{ ${ $this->contexts() }[0]->ContextVariables() }, $stateParam);
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

    $this->completeTransitionDefinition($transition, $origmethod);

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

sub printTransitions {
    my $this = shift;
    my $outfile = shift;

    my $name = $this->name();

    print $outfile "//BEGIN Mace::Compiler::ServiceImpl::printTransitions\n";

    my $lockType = "ContextLock"; 
    for my $t ($this->transitions()) {
        my @currentContextVars = ();
        $t->method->printTargetContextVar(\@currentContextVars, ${ $this->contexts() }[0] );
        $t->method->printSnapshotContextVar(\@currentContextVars, ${ $this->contexts() }[0] );
          $t->contextVariablesAlias(join("\n", @currentContextVars));

        $t->printGuardFunction($outfile, $this, "methodprefix" => "${name}Service::", "serviceLocking" => $this->locking());
        #if( $t->type eq "downcall" or $t->type eq "upcall" ){
        #  $t->contextVariablesAlias("");
        #}

        #global state
        my @usedVar = array_unique($t->method()->usedStateVariables());

        my @declares = ();
        push(@declares, "// isUsedVariablesParsed = ".$t->method()->isUsedVariablesParsed()."\n");
        push(@declares, "// used variables within transition = @usedVar\n");
        push(@declares, "// Refer to ServiceImpl.pm:printTransitions()\n");
        push(@declares, "__eventContextType = ".$this->locking().";\n");

        $t->readStateVariable(join("\n", @declares));

        my $onChangeVarsRef = $this->onChangeVars();

        $t->printTransitionFunction($outfile, "methodprefix" => "${name}Service::", "onChangeVars" => $onChangeVarsRef, "serviceLocking" => $this->locking());
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

    my @routineMessageNames;
    for my $r ($this->routines()) {

        my $under = "";
        my $selectorVar = $r->options('selectorVar');
        my $shimroutine = "";
        my $routine = "";
        my $routineLogLevel = $r->getLogLevel($this->traceLevel());
        if ( not $r->returnType->isVoid and $routineLogLevel > 1) {
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
          $routine = $r->toString("methodprefix" => "${name}Service::${under}", nodefaults => 1, nostatic => 1, selectorVar => 1, nologs => 1, prepare => 1, body => 1);
        }
        else {
          $routine = $r->toString("methodprefix" => "${name}Service::${under}", nodefaults => 1, nostatic => 1, selectorVar => 1, prepare => 1, traceLevel => $this->traceLevel, binarylog => 1, initsel => 1, body => 1);
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
    #my $p = shift;
    my $sync_upcall_param = shift;
    my $message = shift;

    my $ptype = $message->name();
    #bsang: copy returnValue Message
    my @rparams;
    for( $message->fields() ){
        given( $_->name ){
            when ("contextSnapshot") { push @rparams, "ctxSnapshot"; }
            default { push @rparams, ($sync_upcall_param . "." . $_ ); }
        }
    }
    my $rcopyparam="$ptype pcopy(" . join(",", @rparams) . qq/); /;

    my $apiBody = qq#
    mace::AgentLock::nullTicket();
    if( $sync_upcall_param.response ){ // this snapshot is delivered to the target context node.
        //mace::ScopedContextRPC::wakeupWithValue( $sync_upcall_param.eventID, $sync_upcall_param.contextSnapshot );
    }else{
        // mace::serialize(returnValue,  &$sync_upcall_param.snapshotContextID);
        /*mace::string ctxSnapshot;
        takeLocalSnapshot( $sync_upcall_param.snapshotContextID );
        $rcopyparam
        const MaceKey srcNode( mace::ctxnode, source.getMaceAddr()  );
        downcall_route( srcNode,  pcopy ,__ctx);*/
    }
    #;
    return $apiBody;
}

=begin
sub routineCallHandlerHack {
    my $this = shift;
    my $p = shift;
    my $message = shift;

    my $method = $message->options('routine');
    return $message->toRoutineMessageHandler($p, $this->hasContexts(), $method);
}
=cut
sub routeRelayMessageHandler {
  my $this = shift;
  my $message = shift;

  my $adName = $this->routeRelayMessageHandlerName( $message );

  return "$adName( msg, source.getMaceAddr()  );";
}
sub routeRelayMessageLocalHandler {
  my $this = shift;
  my $message = shift;

  my $adName = $this->routeRelayMessageHandlerName( $message );
  my $msgname = $message->name();

  return "
$msgname* __msg = static_cast< $msgname *>( msg ) ;
$adName( *__msg, Util::getMaceAddr()  );
delete __msg;
  ";
}
sub routeRelayMessageHandlerName {
  my $this = shift;
  my $message = shift;

  my $hname = $message->name();
  $hname =~ s/__relay_at/__relay_fn/;
  #return $message->toRealHandlerName();#$this->deliverUpcallHandler( $message);
  return "$hname";
}
sub deliverUpcallMessageHandler {
  my $this = shift;
  my $message = shift;
  return $this->deliverUpcallHandler( $message);
}

sub deliverUpcallLocalHandler {
  my $this = shift;
  my $message = shift;
  return $this->deliverUpcallHandler( $message);
}
sub deliverUpcallHandlerHack {
  my $this = shift;
  my $p = shift;
  my $message = shift;
  my $hasContext = shift;
  my $source = shift;

  my $adName = $this->deliverUpcallHandler($message);

  my $upcall_param = $p->name();
  return qq/
        $adName( $upcall_param, $source->{name}.getMaceAddr()  );
    /;
}
sub deliverUpcallHandler {
    my $this = shift;
    my $message = shift;

    my $numberIdentifier = "[1-9][0-9]*";
    my $methodIdentifier = "[_a-zA-Z][_a-zA-Z0-9]*";
    my $pname;
    my $messageName = $message->name();
    if($messageName =~ /__relay_at_($methodIdentifier)/){
        $pname = $1;
    }else{
        Mace::Compiler::Globals::error('upcall error', __FILE__, __LINE__, "can't find the upcall deliver handler using message name '$messageName'");
    }
    my $adName = "__deliver_fn_$pname";
    
    return $adName;
}
sub deliverAppUpcallMessageHandler {
    my $this = shift;
    my $message = shift;

    my $numberIdentifier = "[1-9][0-9]*";
    my $methodIdentifier = "[_a-zA-Z][_a-zA-Z0-9]*";
    my $pname;
    my $mnumber;
    my $messageName = $message->name();
    if($messageName =~ /__appupcall_at($numberIdentifier)_($methodIdentifier)/){
        $mnumber = $1;
        $pname = $2;
    }else{
        Mace::Compiler::Globals::error('upcall error', __FILE__, __LINE__, "The application upcall message name '$messageName' does not match the supposed pattern");
    }
    my $adName = "__appupcall_fn_${mnumber}_$pname";
    
    return "$adName(msg, source.getMaceAddr() );";
}
sub deliverAppUpcallLocalHandler {
    my $this = shift;
    my $message = shift;

    my $numberIdentifier = "[1-9][0-9]*";
    my $methodIdentifier = "[_a-zA-Z][_a-zA-Z0-9]*";
    my $pname;
    my $mnumber;
    my $messageName = $message->name();
    if($messageName =~ /__appupcall_at($numberIdentifier)_($methodIdentifier)/){
        $mnumber = $1;
        $pname = $2;
    }else{
        Mace::Compiler::Globals::error('upcall error', __FILE__, __LINE__, "The application upcall message name '$messageName' does not match the supposed pattern");
    }
    my $adName = "__appupcall_fn_${mnumber}_$pname";
    
    return "
    $message->{name} *__msg = static_cast<$message->{name}*>( msg );
    $adName(*__msg, Util::getMaceAddr() );
    delete __msg;
    ";
}
sub deliverAppUpcallResponseMessageHandler {
    my $this = shift;
    my $message = shift;

    my $numberIdentifier = "[1-9][0-9]*";
    my $methodIdentifier = "[_a-zA-Z][_a-zA-Z0-9]*";
    my $pname;
    my $mnumber;
    my $messageName = $message->name();
    if($messageName =~ /__appupcall_response_at($numberIdentifier)_($methodIdentifier)/){
        $mnumber = $1;
        $pname = $2;
    }else{
        Mace::Compiler::Globals::error('upcall error', __FILE__, __LINE__, "The application upcall message name '$messageName' does not match the supposed pattern");
    }
    my $adName = "__appupcall_response_fn_${mnumber}_$pname";
    
    return "$adName(msg, source.getMaceAddr() );";
}
sub deliverAppUpcallResponseLocalHandler {
    my $this = shift;
    my $message = shift;

    my $numberIdentifier = "[1-9][0-9]*";
    my $methodIdentifier = "[_a-zA-Z][_a-zA-Z0-9]*";
    my $pname;
    my $mnumber;
    my $messageName = $message->name();
    if($messageName =~ /__appupcall_response_at($numberIdentifier)_($methodIdentifier)/){
        $mnumber = $1;
        $pname = $2;
    }else{
        Mace::Compiler::Globals::error('upcall error', __FILE__, __LINE__, "The application upcall message name '$messageName' does not match the supposed pattern");
    }
    my $adName = "__appupcall_response_fn_${mnumber}_$pname";
    
    return "
    $message->{name} *__msg = static_cast<$message->{name}*>( msg );
    $adName(*__msg, Util::getMaceAddr() );
    delete __msg;
    "
}
sub deliverAppUpcallHandlerHack {
    my $this = shift;
    my $p = shift;
    my $message = shift;

    my $numberIdentifier = "[1-9][0-9]*";
    my $methodIdentifier = "[_a-zA-Z][_a-zA-Z0-9]*";
    my $pname;
    my $mnumber;
    my $messageName = $message->name();
    if($messageName =~ /__appupcall_at($numberIdentifier)_($methodIdentifier)/){
        $mnumber = $1;
        $pname = $2;
    }else{
        Mace::Compiler::Globals::error('upcall error', __FILE__, __LINE__, "The application upcall message name '$messageName' does not match the supposed pattern");
    }
    my $responseMessageName = "__appupcall_response_at${mnumber}_${pname}";;
    my $upcallmethod = ${ $this->providedHandlerMethods() }[ $mnumber-1 ];
    my $upcall_param = $p->name();
    my $adName = "__appupcall_fn_${mnumber}_${pname}";
    my $retVal = "";
    my $responseParam;
    if( $upcallmethod->returnType->isVoid() ){
      $responseParam = join(",", "ThreadStructure::myEvent().eventID ", ( map{"$upcall_param.$_->{name}"} grep(!($_->name =~ /^(__eventID|__response)$/) , $message->fields() ) )  );
    }else{
      $responseParam = join(",", "ThreadStructure::myEvent().eventID ", "ret", ( map{"$upcall_param.$_->{name}"} grep(!($_->name =~ /^(__eventID|__response|__return)$/) , $message->fields() ) )  );
    }
    my $apiBody = "";
    if( $upcallmethod->returnType->isVoid() ){
      $apiBody = "$adName( const_cast< $messageName & >($upcall_param), source.getMaceAddr()  );";
    }else{
      $retVal = $upcallmethod->returnType->type . " ret =";
      $apiBody = qq#
        $retVal $adName( const_cast< $messageName & >($upcall_param), source.getMaceAddr()  );
        $responseMessageName response( $responseParam );
        downcall_route( source, response , rid );
      #;
    }
    return $apiBody;
}
sub deliverAppUpcallResponseHandlerHack {
    my $this = shift;
    my $p = shift;
    my $message = shift;

    my $numberIdentifier = "[1-9][0-9]*";
    my $methodIdentifier = "[_a-zA-Z][_a-zA-Z0-9]*";
    my $pname;
    my $mnumber;
    my $messageName = $message->name();
    if($messageName =~ /__appupcall_response_at($numberIdentifier)_($methodIdentifier)/){
        $mnumber = $1;
        $pname = $2;
    }else{
        Mace::Compiler::Globals::error('upcall error', __FILE__, __LINE__, "The application upcall message name '$messageName' does not match the supposed pattern");
    }
    my $rpcBody = "__appupcall_response_fn_${mnumber}_${pname} ( const_cast< $messageName& >( $p->{name} ) , source.getMaceAddr() );";
        #$adName( $upcall_param, $source->{name}.getMaceAddr()  );
    return $rpcBody;
}
sub asyncCallLocalHandler {
  my $this = shift;
  my $message = shift;
  
  my $name = $this->name();
  my $msgname = $message->name();
  my $event_handler = $this->asyncCallHandler( $message->name() );
  my $event_head_handler = $message->name(); 
  $event_head_handler =~ s/^__async_at/__async_head_fn/;

  return "
$msgname* __msg = static_cast< $msgname *>( msg ) ;
if( __msg->extra.isRequest ){
  HeadEventDispatch::HeadEventTP::executeEvent( this, (HeadEventDispatch::eventfunc)&${name}_namespace::${name}Service::$event_head_handler, (void*) __msg );
}else{
  $event_handler ( *__msg , Util::getMaceAddr() );
  delete __msg;
}
  ";
}
sub asyncCallHandlerHack {
  my $this = shift;
  my $p = shift;
  my $message = shift;
  my $source = shift;
  
  my $adName = $this->asyncCallHandler($p->type->type()  );
  my $pname = $p->name();

  return qq/
      $adName( $pname, / . $source->name() . qq/.getMaceAddr()  );
  /;
}
# chuangw:
# Async, timer and upcalls create FLAG_ASYNC type of autotype
sub asyncCallHandler {
    my $this = shift;
    my $ptype = shift;

    my $adName = $ptype;
    $adName =~ s/^__async_at/__async_fn/;
    return $adName;
}

sub schedulerCallLocalHandler {
    my $this = shift;
    my $msg = shift;

    my $name = $this->name();

    my $msgname = $msg->name();
    my $event_handler = $msgname;
    my $event_head_handler = $msgname;
    $event_handler =~ s/^__scheduler_at/__scheduler_fn/;
    $event_head_handler =~ s/^__scheduler_at/__scheduler_head_fn/;

    my $deliverBody = "
$msgname* __msg = static_cast< $msgname *>( msg ) ;
if( __msg->extra.isRequest ){
  HeadEventDispatch::HeadEventTP::executeEvent( this, (HeadEventDispatch::eventfunc)&${name}_namespace::${name}Service::$event_head_handler, (void*)__msg );
}else{
  $event_handler ( *__msg , Util::getMaceAddr() );
  delete __msg;
}
      //mace::AgentLock::checkTicketUsed(); 
    ";

    return $deliverBody;
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

    if( defined $m->options("redirect") ){
      $apiBody .= $m->options("redirect");
    }
=begin
    # chuangw: This part is moved to generateSpecialTransitions subroutine

    # chuangw: TODO: reschedule resender_timer
    if ($m->name eq 'maceInit' || $m->name eq 'maceResume' ) {
        my $registerInstanceUID = "instanceUniqueID = static_cast<uint8_t>(NumberGen::Instance(NumberGen::SERVICE_INSTANCE_UID)->GetVal());";
        my $initServiceVars = join("\n", map{my $n = $_->name(); qq/
            _$n.maceInit();
            if ($n == -1) {
                $n  = NumberGen::Instance(NumberGen::HANDLER_UID)->GetVal();
            }
                                             /;
                                         } grep(not($_->intermediate()), $this->service_variables()));

        my $initResenderTimer = "";
        if($Mace::Compiler::Globals::useFullContext && $this->hasContexts() ){
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
                    $registerHandlers .= qq{_$svn.registerHandler(($h&)*this, $svn, false);
                                        };
                }
            }
        }
        $apiBody .= "
        if(__inited++ == 0) {
            //TODO: start utility timer as necessary
                $registerInstanceUID
                ThreadStructure::ScopedServiceInstance si( instanceUniqueID ); 
                $initServiceVars
                $initResenderTimer
                $registerHandlers
                ";
    } # maceInit & maceResume
    elsif ($m->name eq 'maceExit') {
        my $stopTimers = join("\n", map{my $t = $_->name(); "$t.cancel();"} $this->timers());
        
        my $cleanupServices = "";
        for my $sv ($this->service_variables()) {
            my $svn = $sv->name();

            if( $svn eq "__ctx" and $sv->serviceclass eq "Transport" ){
              $cleanupServices .= qq@
              if( ThreadStructure::isOuterMostTransition() ){
                if( mace::ContextMapping::getHead(contextMapping) == Util::getMaceAddr() ){
                  mace::HighLevelEvent& myEvent = ThreadStructure::myEvent();
                  HeadEventDispatch::HeadEventTP::commitEvent( myEvent.eventID, myEvent.eventType, myEvent.eventMessageCount ); 
                  // wait to confirm the event is committed.
                  // remind other physical nodes the exit event has committed.
                  const mace::map< MaceAddr, uint32_t >& nodes = contextMapping.getAllNodes(); 
                  for( mace::map< MaceAddr, uint32_t >::const_iterator nodeIt = nodes.begin(); nodeIt != nodes.end(); nodeIt ++ ){
                    if( nodeIt->first == Util::getMaceAddr() ) continue;
                    __event_exit_committed msg;
                    ASYNCDISPATCH( nodeIt->first, __ctx_dispatcher, __event_exit_committed, msg )
                  }
                }else{
                  // wait for exit event to commit.
                  mace::HighLevelEvent::waitExit();
                }
              }
              @;
            }

            for my $h ($this->usesHandlerNames($sv->serviceclass)) {
                if ($sv->doRegister($h)) {
                    $cleanupServices .= qq{_$svn.unregisterHandler(($h&)*this, $svn);\n};
                }
            }

            if( not $sv->intermediate() ){
              $cleanupServices .= qq{_$svn.maceExit();\n};
            }

            #join("\n", map{my $n = $_->name(); qq{_$n.maceExit();}} grep(not($_->intermediate()), $this->service_variables()));
        } # $this->service_variables()

        $apiBody .= "
        if(--__inited == 0) {
                ThreadStructure::ScopedServiceInstance si( instanceUniqueID ); 
            ";
        $apiTail .= "
            //TODO: stop utility timer as necessary
            _actual_state = exited;
            $stopTimers
            $cleanupServices
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
            instanceUniqueID = 0;
            ";

    } # maceReset
=cut

    # TODO: get context lock, create events, etc..
    given( $transitionType ){
      when ("async") { }
      when ("scheduler") {}
      when ("downcall") {}
      when ("upcall") {}
      when ("aspect") {}
    }


    if (defined($m->options("pretransitions")) || defined($m->options("posttransitions"))) {
	$apiBody .= "Merge_" . $m->options("selectorVar") . " __merge(" .
	    join(", ", ("this", map{$_->name()} $m->params())) . ");\n";
    }

=begin
    if (  $m->name() =~ m/^(maceInit|maceExit)$/ ) { 
        # FIXME: this hack should only be applied when the service supports context.
        if($Mace::Compiler::Globals::useFullContext && $this->hasContexts() ){  
            $apiBody .= qq/if( mace::ContextMapping::getHead( contextMapping ) == Util::getMaceAddr() ){
            /;
        }
    }
=cut
    if (defined $m->options('transitions')) {
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
        $apiBody .= qq/macecompiler(1) << "RUNTIME NOTICE: no transition fired" << Log::endl;
          ThreadStructure::ScopedServiceInstance si( instanceUniqueID );
          if( ThreadStructure::isOuterMostTransition() ){
            mace::AgentLock::nullTicket();
          }
        /;
    }
    $apiBody .= $resched .  $m->body() . "\n}\n";
=begin
    if (  $m->name() =~ m/^(maceInit|maceExit)$/ ) { 
        if($Mace::Compiler::Globals::useFullContext && $this->hasContexts() ){  
            $apiBody .= qq@
            }
            @; #if( contextMapping.getHead() == Util::getMaceAddr() )
        }
    }
=cut
    $apiBody .= $apiTail;
=begin
    if ($m->name eq 'maceInit' || $m->name eq 'maceExit'|| $m->name eq 'maceResume') {
	$apiBody .= "\n}\n";
    }
=cut

    my $methodprefix = "${name}Service::";
    #if( defined $m->options("prefix") ){
    #  $methodprefix .= $m->options("prefix");
    #}
    print $outfile $m->toString(methodprefix => $methodprefix, nodefaults => 1, prepare => 1,
                               selectorVar => 1, traceLevel => $this->traceLevel(), binarylog => 1,
                               locking => $locking, fingerprint => 1, usebody=>$apiBody);

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
    map {
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
	registration_uid_t ${name}Service::registerHandler(${hname}& handler, registration_uid_t regId, bool isAppHandler = true) {
	    if(regId == -1) { regId = NumberGen::Instance(NumberGen::HANDLER_UID)->GetVal(); }
	    $assertUnique
            ASSERT(map_${hname}.find(regId) == map_${hname}.end());
	    map_${hname}[regId] = &handler;
        if( isAppHandler ){ apphandler_${hname}.insert( regId ); }
	    return regId;
	}

	void ${name}Service::registerUniqueHandler(${hname}& handler, bool isAppHandler = true) {
	    ASSERT(map_${hname}.empty());
	    map_${hname}[-1] = &handler;
        if( isAppHandler ){ apphandler_${hname}.insert( -1 ); }
	}

	void ${name}Service::unregisterHandler(${hname}& handler, registration_uid_t regId) {
	    ASSERT(map_${hname}[regId] == &handler);
	    map_${hname}.erase(regId);
        apphandler_${hname}.erase( regId );
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
#Wei-Chiu: temporary hack
=begin
          $ctVarsCheck .= "if(" . join("||", map{ "(sv->$_ != sv->_MA_${aname}_$_)" } @{$asp->options('monitor')}) . ") {
                            somethingChanged = true;
                            sv->$aname(".join(",", map { "sv->_MA_${aname}_$_" } @{$asp->options('monitor')}).");
                            ".join("\n", map{ "if(sv->$_ != sv->_MA_${aname}_$_) { sv->_MA_${aname}_$_ = sv->$_; } " } @{$asp->options('monitor')})."
                           }
                           ";
=cut
          $ctVarsCheck .= "if(" . join("||", map{ "(sv->globalContext->$_ != sv->_MA_${aname}_$_)" } @{$asp->options('monitor')}) . ") {
                            somethingChanged = true;
                            sv->$aname(".join(",", map { "sv->_MA_${aname}_$_" } @{$asp->options('monitor')}).");
                            ".join("\n", map{ "if(sv->globalContext->$_ != sv->_MA_${aname}_$_) { sv->_MA_${aname}_$_ = sv->globalContext->$_; } " } @{$asp->options('monitor')})."
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

sub printScopedRoutinePrep {
  my $this = shift;
  my $outfile = shift;

  print $outfile "//BEGIN Mace::Compiler::ServiceImpl::printScopedRoutinePrep\n";

	my $name = $this->name();

	print $outfile <<END;
	class __ScopedRoutinePrep__ {
	  private:
		${name}Service const* sv;
    mace::ContextBaseClass *oldContextObject;
	      public:
      __ScopedRoutinePrep__(${name}Service const* service, uint32_t const& targetContextID, mace::vector<uint32_t> const& snapshotContextIDs) : sv(service) {
        sv->getContextSnapshot(snapshotContextIDs);
        mace::ContextBaseClass * contextObject = sv->getContextObjByID( targetContextID );
        oldContextObject = ThreadStructure::myContext();
        ThreadStructure::setMyContext( contextObject );
        ThreadStructure::pushContext( contextObject->contextName );
        ThreadStructure::insertEventContext( contextObject->contextName );
        mace::ContextLock c_lock( *contextObject, mace::ContextLock::WRITE_MODE );
      }
	    ~__ScopedRoutinePrep__() {
        ThreadStructure::popContext( );
        ThreadStructure::setMyContext (oldContextObject);
      }
	};
END
    print $outfile "//END Mace::Compiler::ServiceImpl::printScopedRoutinePrep\n";
}
sub printServiceStackEvent {
  my $this = shift;
  my $outfile = shift;

  print $outfile "//BEGIN Mace::Compiler::ServiceImpl::printServiceStackEvent\n";

	my $name = $this->name();

	print $outfile <<END;
	class __ServiceStackEvent__ {
	  private:
	    //Pointer to the service for before/after inspection
		${name}Service* sv;
	      public:
      __ServiceStackEvent__(const int8_t eventType, ${name}Service* service, const mace::string& targetContextName) : sv(service) {
        bool newEventCondition;
        switch( eventType ){
          case mace::HighLevelEvent::STARTEVENT:
            newEventCondition = ThreadStructure::isFirstMaceInit();
            break;
          case mace::HighLevelEvent::ENDEVENT:
            newEventCondition = ThreadStructure::isFirstMaceExit();
            break;
          default:
            newEventCondition = ThreadStructure::isOuterMostTransition();
        }
        if( newEventCondition && !mace::HighLevelEvent::isExit ){
            //ASSERTMSG(  contextMapping.getHead() == Util::getMaceAddr() , "Downcall transition originates from a non-head node!" );
            ThreadStructure::newTicket();
            __asyncExtraField extra;
            extra.targetContextID = targetContextName;
            sv->asyncHead( extra, mace::HighLevelEvent::DOWNCALLEVENT );
        }
      }
	    ~__ServiceStackEvent__() {
        if( ThreadStructure::isOuterMostTransition() ){
          sv->eventFinish();
        }
		}
	};
END
    print $outfile "//END Mace::Compiler::ServiceImpl::printServiceStackEvent\n";
}
sub printSerialHelperDemux {
    my $this = shift;
    my $outfile = shift;

    my $name = $this->name();

    print $outfile "//BEGIN Mace::Compiler::ServiceImpl::printSerialHelperDemux\n";
    for my $m ($this->implementsUpcalls(), $this->implementsDowncalls()) {
	if ($m->serialRemap) {
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
            $apiBody .= qq/
 $typeSerial ${pname}_deserialized;
 ScopedDeserialize<$dstype, $typeSerial > __sd_$pname(${pname}, ${pname}_deserialized);
			/;
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
            my @demuxMessages;
            if( ( $this->useTransport() or $this->hasContexts() ) and $m->name eq "deliver"  ){
              @demuxMessages = @{ $this->messages() };
            }else{
              @demuxMessages = grep { $_->method_type == Mace::Compiler::AutoType::FLAG_NONE; } @{ $this->messages() };
            }
            #for my $msg ($this->messages()) {
            for my $msg ( @demuxMessages  ) {
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
                maceerr << "FELL THROUGH NO PROCESSING -- INVALID MESSAGE NUMBER: " << msgNum_$pname << Log::endl;
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
        next if $sv->name eq "__ctx" ;
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
    my $usesTransport;
    for( $this->service_variables() ){
         if( $_->serviceclass() eq "Transport" and $_->name ne "__ctx" ){ $usesTransport = 1 ; }
    }
    
    my %messagesHash = ();
    map { $messagesHash{ $_->name() } = $_ } $this->messages();
    for my $m ($this->usesClassMethods()) {
        my $routine="";
        my $appliedTransportRouteHack;
        # if this service uses Transport, and this helper is "downcall_route" and not a special type of message
        # send a different message to local virtual head node instead.
        if($this->hasContexts() and defined $usesTransport and $m->name eq "route" ){
            # TODO: what about downcall_send()??
            my $msgTypeName = ${ $m->params() }[1]->type->type;
            my $msgType = $messagesHash{ $msgTypeName };
            my $redirectMessageTypeName = "__relay_at_" . $msgTypeName;
            my $redirectmsgType = $messagesHash{ $redirectMessageTypeName };
            if( defined $msgType and $msgType->method_type() == Mace::Compiler::AutoType::FLAG_NONE and defined $redirectmsgType ){
                $routine = $this->createTransportRouteHack( $m, $msgType );
                $appliedTransportRouteHack = 1; 
            }
        }
        $routine .= $this->createUsesClassHelper( $m, \%messagesHash );

        print $outfile $m->toString("methodprefix"=>"${name}Service::downcall_", "noid" => 0, "novirtual" => 1, "nodefaults" => 1, selectorVar => 1, binarylog => 1, traceLevel => $this->traceLevel(), usebody => "$routine");
    }
    print $outfile "//END Mace::Compiler::ServiceImpl::printDowncallHelpers\n";
}
sub createTransportRouteHack {
    my $this = shift;
    my $m = shift;
    my $origMessageType = shift;
    die if not $m->options('original');

    my $message = ${ $m->params() }[1];
    my $dest = ${ $m->params() }[0]->name;
    my $rid = ${ $m->params() }[-1]->name;
    my $redirectMessageTypeName = "__relay_at_" . $message->type->type;
    my $adWrapperName = "__deliver_fn_" . $message->type->type;
    my $redirectMessage = $redirectMessageTypeName . " redirectMessage($dest, $rid, currentEvent.eventID, currentEvent.eventMessageCount  " . join("", map{"," . $message->name . "." . $_->name() } $origMessageType->fields() )  . ")";
    my $routine = qq#

        if( ThreadStructure::getCurrentContext() != ContextMapping::getHeadContext() ){
          mace::HighLevelEvent& currentEvent = ThreadStructure::myEvent();
          $redirectMessage;
          currentEvent.eventMessageCount++;
          ASYNCDISPATCH( contextMapping.getHead(), __ctx_dispatcher, $redirectMessageTypeName, redirectMessage )
          return true;
        }
    #;
    return $routine;
}
sub createUsesClassHelper {
    my $this = shift;
    my $m = shift;
    my $ref_messagesHash = shift;

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
                                  ScopedSerialize<$optype, $ptype > __ss_$pname($opname, $pname);
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
    if ( (scalar(@matchedServiceVars) == 1) or
        (scalar(@matchedServiceVars) == 2 and $matchedServiceVars[-1]->name eq "__ctx") # the covert channel for messaging inside the virtual node does not count
    ) {
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

    return "
            $serialize
            $defaults
            $callString
    ";
}

sub createNonConstCopy {
  my ($this, $param) = @_;

  my $p = ref_clone( $param );
  $p->type->isConst(0);
  $p->type->isConst1(0);
  $p->type->isConst2(0);
  $p->type->isRef(0);

  return $p;
}
sub createApplicationUpcallInternalMessageProcessor {
  my ($this, $origmethod, $at, $mnumber) = @_;

  # create relay-handler for this upcall
  my $serialize = "";
  my @serializedParamName;
  my $m = $origmethod;
  my $declareRefVar="";
  if ($m->options('original')) {
      #TODO: try/catch Serialization
      my $sorigmethod = $m->options('original');
      my @oparams = $sorigmethod->params();
      for my $p ($m->params()) {
          my $op = shift(@oparams);
          if (! $op->type->eq($p->type)) {
              my $optype = $op->type->type();
              my $opname = $op->name;
              my $ptype = $p->type->type();
              my $pname = $p->name;
              $serialize .= qq{ $optype $opname;
                                ScopedSerialize<$optype, $ptype > __ss_$pname($opname, msg.$pname);
                            };
              push @serializedParamName, $opname;
          }else{
              push @serializedParamName, "msg." . $op->name;
          }
      }
  }else{
    map { 
      my $varType = $_->type->type;
      my $varName = $_->name;
      $declareRefVar .= "$varType $varName = msg.$varName;\n";
    } (grep { $_->type->isRef() and not ( $_->type->isConst() or $_->type->isConst1() or $_->type->isConst2() ) }$m->params() );

    map{ 
      if( $_->type->isRef() and not ( $_->type->isConst() or $_->type->isConst1() or $_->type->isConst2() ) ){
        push @serializedParamName, $_->name() ;
      }else{
        push @serializedParamName, "msg." . $_->name() ;
      }
    } $m->params() ;
  }

  my @handlerArr = @{$origmethod->options('class')};
  my $handler = $handlerArr[0];
  my $hname = $handler->name;
  my $mname = $origmethod->name;
  my $rid = $origmethod->params()->[-1]->name();
  my $iterator = "iterator";
  if ($origmethod->isConst()) {
      $iterator = "const_iterator"
  }
  my $callm = $origmethod->name."(".join(",",  @serializedParamName).")";

  # chuangw: When an upcall is made to the application, the call is automatically relayed to head node.
  # This routines creates the handler for the relayed message handler at head.

  my $processUpcall;
  if( $origmethod->returnType->isVoid ){
      my $copyparam = join(",", map { "msg.$_->{name}" } grep($_->name ne "__eventID" ,$origmethod->params() ) );
      $processUpcall = qq#
          if( msg.__eventID < mace::HierarchicalContextLock::nextCommitting() ){ 
            // put parameter into the queue
            deferred_queue_${mnumber}_${mname}.insert( std::pair< uint64_t, DeferralUpcallQueue_${mnumber}_${mname} >( msg.__eventID , DeferralUpcallQueue_${mnumber}_${mname}( $copyparam ) ) );
          }else{
            // if this is the earliest uncommitted event, go ahead.
            maptype_${hname}::$iterator iter = map_${hname}.find(msg.$rid);
            if(iter == map_${hname}.end()) {
                maceWarn("No $hname registered with uid %"PRIi32" for upcall $mname!", msg.$rid);
                $origmethod->{body}
            } else {
                $declareRefVar
                iter->second->$callm;
            }
          }
      #;
  }else{
      $processUpcall = qq#
        //ASSERTMSG(   contextMapping.getHead() == Util::getMaceAddr() , "Downcall transition originates from a non-head node!" );
          // block until all previous events commit
          // chuangw: XXX Blocking design is not good.
          if( msg.__eventID < mace::HierarchicalContextLock::nextCommitting() ){
            ScopedLock sl( appUpcallMutex );
            pthread_cond_t cond;
            pthread_cond_init( &cond, NULL );
            uint64_t eventID = ThreadStructure::myEvent().eventID;
            appUpcallCond[ eventID  ] = &cond;
            pthread_cond_wait( &cond, &appUpcallMutex );
            appUpcallCond.erase( eventID );
          } 
          // if this is the earliest uncommitted event, go ahead.
          maptype_${hname}::$iterator iter = map_${hname}.find(msg.$rid);
          if(iter == map_${hname}.end()) {
              maceWarn("No $hname registered with uid %"PRIi32" for upcall $mname!", msg.$rid);
              $origmethod->{body}
          } else {
              $declareRefVar
              return iter->second->$callm;
          }
      #;
  }
  my $headHandlerBody = qq/
    $serialize
    $processUpcall
  /;

  my $adReturnType = $origmethod->returnType; 

  my $adName = "__appupcall_fn_${mnumber}_$origmethod->{name}";
  my $adMethod = Mace::Compiler::Method->new( name => $adName, body => $headHandlerBody, returnType=> $adReturnType, isConst=> $origmethod->isConst);

  my $adParamType = Mace::Compiler::Type->new( type => "$at->{name}", isConst => 1,isRef => 1 );
  my $msgParam = Mace::Compiler::Param->new( name => "msg", type => $adParamType );
  my $ptype3 = Mace::Compiler::Type->new(isConst=>1, isConst1=>1, isConst2=>0, type=>'MaceAddr', isRef=>1);
  my $param3 = Mace::Compiler::Param->new(filename=>$origmethod->filename() ,hasDefault=>0,name=>'src',type=>$ptype3,line=> $origmethod->line());
  $adMethod->params( $msgParam, $param3 );
  $this->push_appUpcallDispatchMethods( $adMethod  );
}
sub createApplicationUpcallInternalResponseMessageProcessor {
  my ($this, $origmethod, $at, $mnumber) = @_;

  # create relay-handler for this upcall
        my $serialize = "";
        my @serializedParamName;
        my $m = $origmethod;
        if ($m->options('original')) {
            #TODO: try/catch Serialization
            my $sorigmethod = $m->options('original');
          #print "$m->{name} has original method " . $sorigmethod->name . "\n";
            my @oparams = $sorigmethod->params();
            for my $p ($m->params()) {
                my $op = shift(@oparams);
                if (! $op->type->eq($p->type)) {
                    my $optype = $op->type->type();
                    my $opname = $op->name;
                    my $ptype = $p->type->type();
                    my $pname = $p->name;
                    $serialize .= qq{ $optype $opname;
                                      ScopedSerialize<$optype, $ptype > __ss_$pname($opname, msg.$pname);
                                  };
                    push @serializedParamName, $opname;
                }else{
                    push @serializedParamName, "msg." . $op->name;
                }
            }
        }else{
            map{ push @serializedParamName, "msg." . $_->name() } $m->params() ;
        }
  my @handlerArr = @{$origmethod->options('class')};
  my $handler = $handlerArr[0];
  my $hname = $handler->name;
  my $mname = $origmethod->name;
  my $rid = $origmethod->params()->[-1]->name();
  my $iterator = "iterator";
  if ($origmethod->isConst()) {
      $iterator = "const_iterator"
  }
  #my $callm = $origmethod->name."(".join(",", map{"msg." . $_->name} $origmethod->params()).")";
  my $callm = $origmethod->name."(".join(",",  @serializedParamName).")";

  my $processUpcall;
  if( $origmethod->returnType->isVoid ){
      my $copyparam = join(",", map { "msg.$_->{name}" } grep($_->name ne "__eventID" ,$origmethod->params() ) );
      $processUpcall = "mace::ScopedContextRPC::wakeup( msg.__eventID );";
  }else{
      $processUpcall = "mace::string serialized_ret;
        mace::serialize( serialized_ret, &msg.__return );
        mace::ScopedContextRPC::wakeupWithValue( msg.__eventID, serialized_ret );";
  }
  my $headHandlerBody = qq/
    $serialize
    $processUpcall
  /;

  #my $adReturnType = $origmethod->returnType; 
  my $adReturnType = Mace::Compiler::Type->new(type=>"void",isConst=>0,isConst1=>0,isConst2=>0,isRef=>0);

  my $adName = "__appupcall_response_fn_${mnumber}_$origmethod->{name}";
  my $adMethod = Mace::Compiler::Method->new( name => $adName, body => $headHandlerBody, returnType=> $adReturnType);

  my $adParamType = Mace::Compiler::Type->new( type => "$at->{name}", isConst => 1,isRef => 1 );
  my $msgParam = Mace::Compiler::Param->new( name => "msg", type => $adParamType );
  my $ptype3 = Mace::Compiler::Type->new(isConst=>1, isConst1=>1, isConst2=>0, type=>'MaceAddr', isRef=>1);
  my $param3 = Mace::Compiler::Param->new(filename=>$origmethod->filename() ,hasDefault=>0,name=>'src',type=>$ptype3,line=> $origmethod->line());
  $adMethod->params( $msgParam, $param3 );
  $this->push_appUpcallDispatchMethods( $adMethod  );
}
sub createApplicationUpcallInternalMessage {
    my $this = shift;
    my $origmethod  = shift;
    my $mnumber = shift;

    my $at = Mace::Compiler::AutoType->new(name=> "__appupcall_at${mnumber}_" . $origmethod->name , line=> $origmethod->line() , filename => $origmethod->filename() , method_type=>Mace::Compiler::AutoType::FLAG_APPUPCALL);
    # need the event id of the event which initiates upcall transition
    my $eventIDType = Mace::Compiler::Type->new(type => "uint64_t" );
    my $eventIDField = Mace::Compiler::Param->new(name=> "__eventID" , filename=> $origmethod->filename, line=> $origmethod->line , type=>$eventIDType);
    $at->push_fields( ($eventIDField ) );

    foreach( $origmethod->params() ){
        my $p = $this->createNonConstCopy( $_ );
        $at->push_fields( $p );
    }

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
    $this->createApplicationUpcallInternalMessageProcessor( $origmethod, $at, $mnumber );
}
sub createApplicationUpcallInternalMessageResponse {
    my $this = shift;
    my $origmethod  = shift;
    my $mnumber = shift;


    # void type'd upcall call does not return and there shouldn't create response message
    if( $origmethod->returnType->isVoid ){
      return;
    }

    my $at = Mace::Compiler::AutoType->new(name=> "__appupcall_response_at${mnumber}_" . $origmethod->name , line=> $origmethod->line() , filename => $origmethod->filename() , method_type=>Mace::Compiler::AutoType::FLAG_APPUPCALLREP);
    # need the event id of the event which initiates upcall transition
    my $eventIDType = Mace::Compiler::Type->new(type => "uint64_t" );
    my $eventIDField = Mace::Compiler::Param->new(name=> "__eventID" , filename=> $origmethod->filename, line=> $origmethod->line , type=>$eventIDType);
    $at->push_fields( ($eventIDField ) ); 
    if( ! $origmethod->returnType->isVoid ){
      my $returnType = Mace::Compiler::Type->new(type => $origmethod->returnType->type );
      my $returnField = Mace::Compiler::Param->new(name=> "__return" , filename=> $origmethod->filename, line=> $origmethod->line , type=>$returnType);
      $at->push_fields( $returnField );
    }

    foreach( $origmethod->params() ){
        my $p = $this->createNonConstCopy( $_ );
        $at->push_fields( $p );
    }

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
    $this->createApplicationUpcallInternalResponseMessageProcessor( $origmethod, $at, $mnumber );
}
sub printUpcallHelpers {
    my $this = shift;
    my $outfile = shift;

    my $name = $this->name();

    print $outfile "//BEGIN Mace::Compiler::ServiceImpl::printUpcallHelpers\n";

    print $outfile join("\n", $this->generateAddDefer("upcall", my $ref = $this->upcallDeferMethods()));

    my $mcounter = 1;
    for my $m ($this->providedHandlerMethods()) {
        my $origmethod = $m;
        my $serialize = "";
        my $defaults = "";
        my @serializedParamName;
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
                                      ScopedSerialize<$optype, $ptype > __ss_$pname($opname, $pname);
                                  };
                    push @serializedParamName, $pname;
                }else{
                    push @serializedParamName, $op->name;
                }
            }
        }else{
            map{ push @serializedParamName, $_->name() } $m->params() ;
        }
        if ($m->options('remapDefault')) {
            for my $p ($m->params()) {
                if ($p->flags('remapDefault')) {
                    my $pn = $p->name();
                    my $pd = $p->default();
                    my $pd2 = $p->flags('remapDefault');

                    #print "$pn $pd $pd2\n";

    #chuangw: a temporary hack.
    # if the service var matches a (global) state variable, get to the global context object
                    my $globalContext = "";
                    for my $globalVar ( @{ ${ $this->contexts() }[0]->ContextVariables() } ){
                      #print $globalVar->name  . " $pd2\n";
                      if( $globalVar->name() eq  $pd2 ){
                        #print " matched\n";
                        $globalContext = "globalContext->";
                        last;
                      }
                    }
                    $defaults .= qq{ if($pn == $pd) { $pn = $globalContext$pd2; }
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
        my $atname = "__appupcall_at${mcounter}_$origmethod->{name}";
        my $deferAction="";
        my $wrapperFunc = "__appupcall_fn_${mcounter}_$origmethod->{name}";
        if ($m->returnType->isVoid()) {
          my @deferMsgParams = ( "ThreadStructure::myEvent().eventID ", @serializedParamName );
          $deferAction=  "$atname msg( " . join(", ", @deferMsgParams  ) . " );
                          SYNCCALL( contextMapping.getHead(), $wrapperFunc , $atname , msg )
                          return;
          ";
        }else{
          my @deferMsgParams = ( "ThreadStructure::myEvent().eventID ", @serializedParamName );
          $deferAction="$m->{returnType}->{type} ret;
                        $atname msg( " . join(", ", @deferMsgParams  ) . " );
                        SYNCCALL_RETURN( contextMapping.getHead() , $wrapperFunc , $atname , msg, ret )
                        return ret;
          ";
        }
        my $deferApplicationHandler = qq#
            if( apphandler_${hname}.count( rid ) > 0 ){
                // An external world application has registered with this upcall.
                // this upcall is going out of the fullcontext world into the outer-world application.
                $deferAction
            }
        #;
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
                $deferApplicationHandler
                $callString
        ");
        print $outfile $routine;
        $mcounter ++;
    }
    print $outfile "//END Mace::Compiler::ServiceImpl::printUpcallHelpers\n";
}
# XXX: chuangw: printDummyConstructor subroutine is not used anywhere.
sub printDummyConstructor {
    my $this = shift;
    my $outfile = shift;

    my $name = $this->name();
    my @svo = grep( not($_->intermediate), $this->service_variables());

    #TODO: utility_timer
    my $constructors = "${name}Dummy::${name}Dummy() : \n//(\nBaseMaceService(), __inited(0), instanceUniqueID(0)";
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
    my $constructors = "${name}Service::${name}Service(".join(", ", (map{$_->serviceclass."ServiceClass& __".$_->name} @svo), (map{$_->type->toString()." _".$_->name} $this->constructor_parameters()), "bool ___shared" ).") : \n//(\nBaseMaceService(), __inited(0),instanceUniqueID(0)";
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

    # Initialize contexts
    map {
      if( $_->isArray ){
        $constructors .= ",\n$_->{name} ( )";
      }else{
        $constructors .= ",\n$_->{name} (NULL)";
      }
    } ${ $this->contexts() }[0], ${ $this->contexts() }[0]->subcontexts();

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
    my $mutexInit = qq/
        pthread_mutex_init(&eventRequestBufferMutex, NULL);
    /;
    $constructors .= ", __local_address(MaceKey::null)";
    $constructors .= qq|\n{
	initializeSelectors();
        this->loadContextMapping( mace::ContextMapping::getInitialMapping( "${name}" ) );
        __local_address = computeLocalAddress();
        $mutexInit
        $registerInstance
        $propertyRegister
        ADD_SELECTORS("${name}::(constructor)");
        macedbg(1) << "Created queued instance " << this << Log::endl;
    }
    //)
    |;

    $constructors .= "${name}Service::${name}Service(const ${name}Service& _sv) : \n//(\nBaseMaceService(false), __inited(_sv.__inited), instanceUniqueID(_sv.instanceUniqueID )";
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
    map {
      if( $_->isArray ){
        $constructors .= ",\n$_->{name} ( _sv.$_->{name} )";
      }else{
        $constructors .= ",\n$_->{name} ( new $_->{className} ( *(_sv.$_->{name}) ) )";
      }
    } ${ $this->contexts() }[0], ${ $this->contexts() }[0]->subcontexts();
    $constructors .= qq|{
        ADD_SELECTORS("${name}::(constructor)");
        macedbg(1) << "Created non-queued instance " << this << Log::endl;
        $mutexInit
    }
    //)
    |;

    print $outfile $constructors;
    print $outfile "//END Mace::Compiler::ServiceImpl::printConstructor\n";
}
sub printCtxMapUpdate {
    my $this = shift;
    my $outfile = shift;

    my $servicename = $this->name();
    print $outfile "//BEGIN Mace::Compiler::ServiceImpl::printCtxMapUpdate\n";

    print $outfile <<END;

    // helper functions for maintaining context mapping
    void ${servicename}Service::loadContextMapping(const mace::map<mace::MaceAddr ,mace::list<mace::string > >& servContext){
        mace::AgentLock lock( mace::AgentLock::WRITE_MODE );
        contextMapping.setDefaultAddress ( Util::getMaceAddr() );
        contextMapping.loadMapping( servContext );
        contextMapping.snapshot( static_cast<uint64_t>( 0 ) );
    }
END
    print $outfile "//END Mace::Compiler::ServiceImpl::printCtxMapUpdate\n";
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
    my $asyncDispatchMacro;
    if( $this->hasContexts() ){
        $asyncDispatchMacro = qq!\\
{\\
  const MaceAddr& destAddr = DEST_ADDR;\\
  if( destAddr == Util::getMaceAddr() ){\\
      macedbg(1)<<"Enqueue a "<< #MSGTYPE <<" message into async dispatch queue: "<< MSG <<Log::endl;\\
      AsyncDispatch::enqueueEvent(this,(AsyncDispatch::asyncfunc)&${name}_namespace::${name}Service::WRAPPERFUNC,(void*)new MSGTYPE(MSG) ); \\
  } else { \\
      const mace::MaceKey destNode( mace::ctxnode,  destAddr ); \\
      downcall_route( destNode , MSG , __ctx ); \\
  }\\
}
!;
    }else{
        $asyncDispatchMacro = qq!\\
macedbg(1)<<"Enqueue a "<< #MSGTYPE <<" message into async dispatch queue: "<< MSG <<Log::endl;\\
AsyncDispatch::enqueueEvent(this,(AsyncDispatch::asyncfunc)&${name}_namespace::${name}Service::WRAPPERFUNC,(void*)new MSGTYPE(MSG) );!;
    }

    my $const_asyncDispatchMacro;
    if( $this->hasContexts() ){
        $const_asyncDispatchMacro = qq!\\
{\\
  const MaceAddr& destAddr = DEST_ADDR;\\
  ${name}_namespace::${name}Service* that = const_cast<${name}_namespace::${name}Service*>( this );\\
  if( destAddr == Util::getMaceAddr() ){\\
      macedbg(1)<<"Enqueue a "<< #MSGTYPE <<" message into async dispatch queue: "<< MSG <<Log::endl;\\
      AsyncDispatch::enqueueEvent(that,(AsyncDispatch::asyncfunc)&${name}_namespace::${name}Service::WRAPPERFUNC,(void*)new MSGTYPE(MSG) ); \\
  } else { \\
      const mace::MaceKey destNode( mace::ctxnode,  destAddr ); \\
      that->downcall_route( destNode , MSG , __ctx ); \\
  }\\
}
!;
    }else{
        $const_asyncDispatchMacro = qq!\\
macedbg(1)<<"Enqueue a "<< #MSGTYPE <<" message into async dispatch queue: "<< MSG <<Log::endl;\\
${name}_namespace::${name}Service* that = const_cast<${name}_namespace::${name}Service*>( this );\\
AsyncDispatch::enqueueEvent(that,(AsyncDispatch::asyncfunc)&${name}_namespace::${name}Service::WRAPPERFUNC,(void*)new MSGTYPE(MSG) );!;
    }


    my $directDispatchMacro;
    if( $this->hasContexts() ){
        $directDispatchMacro = qq!\\
if( DEST_ADDR == Util::getMaceAddr() ){\\
    ThreadStructure::newTicket(); \\
    macedbg(1)<<"Call into global context with message: "<< MSG <<Log::endl;\\
    FUNC( MSG, Util::getMaceAddr() ); \\
} else { \\
    const mace::MaceKey destNode( mace::ctxnode,  DEST_ADDR ); \\
    downcall_route( destNode , MSG , __ctx ); \\
}!;
    }else{
        $directDispatchMacro = qq!\\
ThreadStructure::newTicket(); \\
macedbg(1)<<"Call into global context with message: "<< MSG <<Log::endl;\\
FUNC( MSG, Util::getMaceAddr() ); !;
    }
    my $syncCallMacro;
    if ( $this->hasContexts() ){
        $syncCallMacro = qq!\\
{\\
  const MaceAddr& destAddr = DEST_ADDR;\\
  if( destAddr == Util::getMaceAddr() ){ \\
      WRAPPERFUNC( MSG, Util::getMaceAddr() ); \\
  }else{ \\
      mace::ScopedContextRPC rpc; \\
      downcall_route( MaceKey(mace::ctxnode, destAddr) , MSG  ,__ctx ); \\
  }\\
}!;
    }else{
        $syncCallMacro = qq!\\
WRAPPERFUNC( MSG, Util::getMaceAddr() );!;
    }
    my $syncCallReturnMacro;
    if ( $this->hasContexts() ){
        $syncCallReturnMacro = qq!\\
{\\
  const MaceAddr& destAddr = DEST_ADDR;\\
  if( destAddr == Util::getMaceAddr() ){ \\
      RETURNVAL = WRAPPERFUNC( MSG, Util::getMaceAddr() ); \\
  }else{ \\
      mace::ScopedContextRPC rpc; \\
      downcall_route( MaceKey(mace::ctxnode, destAddr) , MSG  ,__ctx ); \\
      rpc.get( RETURNVAL ); \\
  }\\
}!;
    }else{
        $syncCallReturnMacro = qq!\\
RETURNVAL = WRAPPERFUNC( MSG, Util::getMaceAddr() );!;
    }
    my $const_syncCallReturnMacro;
    if ( $this->hasContexts() ){
        $const_syncCallReturnMacro = qq!\\
{\\
  ${name}_namespace::${name}Service* that = const_cast<${name}_namespace::${name}Service*>( this );\\
  const MaceAddr& destAddr = DEST_ADDR;\\
  if( destAddr == Util::getMaceAddr() ){ \\
      RETURNVAL = that->WRAPPERFUNC( MSG, Util::getMaceAddr() ); \\
  }else{ \\
      mace::ScopedContextRPC rpc; \\
      that->downcall_route( MaceKey(mace::ctxnode, destAddr) , MSG  ,__ctx ); \\
      rpc.get( RETURNVAL ); \\
  }\\
}!;
    }else{
        $const_syncCallReturnMacro = qq!\\
${name}_namespace::${name}Service* that = const_cast<${name}_namespace::${name}Service*>( this );\\
RETURNVAL = that->WRAPPERFUNC( MSG, Util::getMaceAddr() );!;
    }
    my $syncCallEventMacro;
    if ( $this->hasContexts() ){
        $syncCallEventMacro = qq!\\
{\\
  const MaceAddr& destAddr = DEST_ADDR;\\
  if( destAddr == Util::getMaceAddr() ){ \\
      WRAPPERFUNC( MSG, Util::getMaceAddr() ); \\
  }else{ \\
      mace::ScopedContextRPC rpc; \\
      downcall_route( MaceKey(mace::ctxnode, destAddr) , MSG  ,__ctx ); \\
      rpc.get( ThreadStructure::myEvent() ); \\
  }\\
}!;
    }else{
        $syncCallEventMacro = qq!\\
WRAPPERFUNC( MSG, Util::getMaceAddr() );!;
    }

    print $outfile <<END;
#ifndef ${name}_macros_h
#define ${name}_macros_h

#include "lib/mace-macros.h"
$undefCurtime

#define state_change(s) changeState(s, selectorId->log)
// chuangw: DIRECTDISPATCH obsolete?
#define DIRECTDISPATCH( DEST_ADDR , FUNC , MSG ) $directDispatchMacro

#define ASYNCDISPATCH( DEST_ADDR , WRAPPERFUNC , MSGTYPE , MSG ) $asyncDispatchMacro

#define CONST_ASYNCDISPATCH( DEST_ADDR , WRAPPERFUNC , MSGTYPE , MSG ) $const_asyncDispatchMacro

#define SYNCCALL( DEST_ADDR, WRAPPERFUNC , MSGTYPE, MSG ) $syncCallMacro

#define SYNCCALL_RETURN( DEST_ADDR, WRAPPERFUNC , MSGTYPE, MSG, RETURNVAL ) $syncCallReturnMacro

#define CONST_SYNCCALL_RETURN( DEST_ADDR, WRAPPERFUNC , MSGTYPE, MSG, RETURNVAL ) $const_syncCallReturnMacro

#define SYNCCALL_EVENT( DEST_ADDR, WRAPPERFUNC , MSGTYPE, MSG ) $syncCallEventMacro
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

1;
