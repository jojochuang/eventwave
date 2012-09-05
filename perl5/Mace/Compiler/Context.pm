# 
# Context.pm : part of the Mace toolkit for building distributed systems
# 
# Copyright (c) 2012, Wei-Chiu Chuang
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


package Mace::Compiler::Context;

use strict;
use Mace::Compiler::Type;
use Mace::Compiler::Timer;
use Mace::Compiler::Param;
use Mace::Compiler::ContextParam;

use Mace::Util qw(:all);

use Class::MakeMethods::Template::Hash
    (
     'new' => 'new',
     'string' => "name",
     'string' => "className",
     'boolean' => 'serialize',
     'array_of_objects' => ["subcontexts" => {class =>"Mace::Compiler::Context"}],
     'array_of_objects' => ["ContextVariables" => { class => "Mace::Compiler::Param" }],
     'array_of_objects' => ["ContextTimers" => { class => "Mace::Compiler::Timer" }],
     'boolean' => "isArray",
     'object' => ["paramType" => { class => "Mace::Compiler::ContextParam" } ],
     'array' => 'downgradeto',
     );

sub isValidRepresentation {
    my $this = shift;
    my $contextStr = shift;   # = 
    # strip leaveonly  context ame

    for my $subcontext ( $this->subcontexts ) {
        $subcontext->isValidRepresentation($contextStr);
    }
}

sub validateContextOptions {
    my $this = shift;
    my $sv = shift;
    $this->serialize(1);

    for my $var ( $this->ContextVariables() ){
        $var->validateTypeOptions({'serialize' => 0, 'recur' => 1});
    }
    for my $timer ( $this->ContextTimers() ){
        $timer->validateTypeOptions($sv);
    }

    for my $subcontext ( $this->subcontexts ) {
        $subcontext->validateContextOptions();
    }
}

sub toSerialize {
  my $this = shift;
  my $str = shift;
  if($this->serialize()) {
    my $name = $this->name();
    my $s;
    if( $this->isArray() ){
        $s = qq/${\$this->name}.serialize($str);/;
    }else{
        $s = qq/${\$this->name}-> serialize($str);/;
    }
    return $s;
  }
  return '';
}

sub toDeserialize {
    my $this = shift;
    my $in = shift;
    my %opt = @_;
    my $prefix = "";
    if($opt{prefix}) { $prefix = $opt{prefix}; }
    if ($this->serialize()) {
        my $name = $this->name();
        my $s;
        if( $this->isArray() ){
            $s = qq/$prefix ${\$this->name}.deserialize($in);/;
        }else{
            $s = qq/$prefix ${\$this->name}-> deserialize($in);/;
        }
        return $s;
    }
    return '';
}

sub toDeclareString {
    my $this = shift;
    my $t = $this->className();
    my $n = $_->name();

    my $r = "";
    if( $this->isArray == 0 ){
        $r .= "mutable ${t} *$n;\n";
    } else {
        $r .= "mutable mace::map<" . $_->paramType->className() . "," . $_->className() . "> " . $_->name() . ";\n";
    }
    return $r;
}
use Data::Dumper;
sub toString {
    my $this = shift;
    my $serviceName = shift;
    my %args = @_;
    my $r = $this->paramType->toString();
    my $n = $this->className();

    my $subcontextDeclaration = "";
    my $contextVariableDeclaration = "";
    my $contextTimerDeclaration = "";
    my $contextTimerDefinition = "";
    my $deserializeFields = "";
    foreach( $this->ContextVariables ){
        $contextVariableDeclaration .= $_->toString(nodefaults => 1, semi => 0) . ";\n";
    }
    foreach( $this->ContextTimers ){
        $contextTimerDeclaration .= $_->toString($serviceName, traceLevel => $args{traceLevel}, isContextTimer => 1 ) . ";\n";
    }
    foreach( $this->subcontexts ){
        if( $_->{isArray} == 0 ){
            $subcontextDeclaration .= $_->className() . "* " . $_->name() . ";\n";
        }else{
            $subcontextDeclaration .= "mace::map<" . $_->paramType->className() . "," . $_->className() . "> " . $_->name() . ";\n";
        }
    }
      my $serializeSubContexts = join("", map{
        if( $_->isArray() ){
            qq/mace::serialize(__str, &${\$_->name()});\n/
        }else{
            qq/mace::serialize(__str, ${\$_->name()});\n/
        }
    } $this->subcontexts() );

      my $serializeFields = 
          join("\n", (grep(/./, map { $_->toSerialize("__str") } $this->ContextVariables()))) . 
          join("\n", map { $_->toSerialize("__str") } $this->ContextTimers());

      my $deserializeSubContexts = join("", map{
        if( $_->isArray() ){
            qq/serializedByteSize += mace::deserialize(__in, &${\$_->name()});\n/
        }else{
            qq/serializedByteSize += mace::deserialize(__in, ${\$_->name()});\n/
        }
    } $this->subcontexts() );
      $deserializeFields = 
          join("\n", (grep(/./, map { $_->toDeserialize("__in", prefix => "serializedByteSize += ") } $this->ContextVariables()))) . 
          join("\n", map { $_->toDeserialize("__in", prefix => "serializedByteSize += " ) } $this->ContextTimers());
    my $maptype="";
    my $keytype="";
    my $callParams="";
    my $serializeMethods = "";
    if ($this->serialize()) {
        my $serializeBody = qq/
            $serializeSubContexts
            $serializeFields
        /;
        my $deserializeBody = qq/
              int serializedByteSize = 0;
              $deserializeSubContexts
              $deserializeFields
              return serializedByteSize;
        /;
        $serializeMethods = qq/
              void serialize(std::string& __str) const {
                $serializeBody
              }
              int deserialize(std::istream& __in)  throw (mace::SerializationException){
                $deserializeBody
              }
/;
    }
    # XXX: deep copy do not include child contexts.
    # only do deep copy when there are at least one timers or variables.
    my $deepCopy="";
    if( @{$this->ContextTimers(), $this->ContextVariables()} > 0 ){
        $deepCopy = ":\n" . join(",\n", map{ "${\$_->name()}(_ctx.${\$_->name()})" } $this->ContextTimers(),$this->ContextVariables()   );
    }

    my $checkDowngradeTo = join("\nels", map{ "if ($_ .compare(nextContextName)==0 ) { return true;  }" } $this->downgradeto() );
    my $checkSubcontextPrefix="";
    if( @{ $this->subcontexts() } > 0 ){
        $checkSubcontextPrefix = "if( nextContextName.compare( 0, contextID.size(), contextID.c_str()  ) == 0 ){  }\n";
    }

    $r .= qq#
class ${n} : public mace::ContextBaseClass /*, public mace::PrintPrintable */{
public:
    // add timers declaration
    $contextTimerDefinition
    $contextTimerDeclaration
    // add state var declaration
    $contextVariableDeclaration
    // add child contexts
    $subcontextDeclaration
public:
    ${n}(const mace::string& contextID="$this->{name}", const uint64_t ticket = 1 ): 
        mace::ContextBaseClass(contextID, ticket)
    { }
    ${n}( const ${n}& _ctx ) $deepCopy
    { }

    virtual ~${n}() { }
      $serializeMethods

    void snapshot( const uint64_t& ver ) const {
        ${n}* _ctx = new ${n}(*this);
        mace::ContextBaseClass::snapshot( ver, _ctx );
    }
    // get snapshot using the current event id.
    const ${n}& getSnapshot() const {
        return static_cast< const ${n}& >(  mace::ContextBaseClass::getSnapshot()  );
    }

    void setSnapshot(const uint64_t ver, const mace::string& snapshot){
        std::istringstream in( snapshot );
        ${n} *obj = new ${n} (this->contextID,1  );
        mace::deserialize(in, obj);
        versionMap.push_back( std::make_pair(ver, obj) );
    }

    // FIXME: Support checking only immediate child contexts...
    bool checkValidTransition( const mace::string& nextContextName ){
        // if this context class has subclass, and the prefix of nextContextName matches my context name
        $checkSubcontextPrefix
        // or, this context has 'downgradeto' context and it matches nextContextName
        $checkDowngradeTo
        return false;
    }
private:
};
    #;
    # XXX: if migration takes place, should it take the snapshot of the previous snapshot?
    return $r;
}

sub locateChildContextObj {
    my $this = shift;
    my $contextDepth = shift;
    my $parentContext = shift;

    my $declareContextObj;
    my $getContextObj;

    my $declareParams = "";
    my $contextName = $this->{name};
    if( $this->isArray() ) {
        my $keys = $this->paramType->count_key();
        if( $keys  == 1  ){
            my $keyType = ${ $this->paramType->key() }[0]->type->type();
            $getContextObj = qq#
            $keyType keyVal = boost::lexical_cast<$keyType>( ctxStr${contextDepth}[1] );
            contextDebugID = contextDebugIDPrefix+ "$contextName\[" + boost::lexical_cast<mace::string>(keyVal)  + "\]";
            if( ${parentContext}->${contextName}.find( keyVal ) == ${parentContext}->${contextName}.end() ){
                ASSERTMSG( mace::AgentLock::getCurrentMode() == mace::AgentLock::WRITE_MODE, "It requires in AgentLock::WRITE_MODe to create a new context object!" );
                mace::map<$keyType , $this->{className}> & ctxobj = const_cast<mace::map<$keyType ,$this->{className}> &>( ${parentContext}->${contextName} ) ;
                ctxobj [ keyVal ] = $this->{className} ( contextDebugID, eventID );
            }
            contextDebugIDPrefix = contextDebugID;
            
            #;
            $declareContextObj = "&(${parentContext}->${contextName} [ keyVal ] )";

        } elsif ( $keys > 1 ){
            my $paramid=1;
            my @params;
            my @paramid;
            for( @{ $this->paramType->key() } ){
                my $keyType = $_->type->type();
                push @params, "$keyType param$paramid = boost::lexical_cast<$keyType>( ctxStr${contextDepth}[$paramid] )";
                push @paramid, "param$paramid";
                $paramid++;
            }
            my $ctxParamClassName = $this->paramType->className();
            # declare parameters of the _ index
            $declareParams = join(";\n", @params) . ";";
            $getContextObj = qq"
            $ctxParamClassName keyVal(" .join(",", @paramid) . ");
            " . qq#
            contextDebugID = contextDebugIDPrefix+ "$contextName\[" + boost::lexical_cast<mace::string>(keyVal)  + "\]";
            if( ${parentContext}->${contextName}.find( keyVal ) == ${parentContext}->${contextName}.end() ){
                ASSERTMSG( mace::AgentLock::getCurrentMode() == mace::AgentLock::WRITE_MODE, "It requires in AgentLock::WRITE_MODe to create a new context object!" );
                mace::map<$ctxParamClassName , $this->{className}> & ctxobj = const_cast<mace::map<$ctxParamClassName ,$this->{className}> &>( ${parentContext}->${contextName} ) ;
                ctxobj [ keyVal ] = $this->{className} ( contextDebugID, eventID );
            }
            contextDebugIDPrefix = contextDebugID;
            
            #;
            $declareContextObj = "&(${parentContext}->${contextName} [ keyVal ] )";
        }
    }else{
        $getContextObj = qq#
            contextDebugID = contextDebugIDPrefix + "${contextName}";
            if( ${parentContext}->${contextName} == NULL ){
                ASSERTMSG( mace::AgentLock::getCurrentMode() == mace::AgentLock::WRITE_MODE, "It requires in AgentLock::WRITE_MODe to create a new context object!" );
                $this->{className} *& ctxobj = const_cast<$this->{className} *&>( ${parentContext}->${contextName} );
                ctxobj = new $this->{className} ( contextDebugID, eventID );
            }
            contextDebugIDPrefix = contextDebugID + "::";
        #;
        $declareContextObj = "${parentContext}->${contextName}";
    }
    my $nextContextDepth = $contextDepth+1;
    my $subcontextConditionals = join("else ", map{ $_->locateChildContextObj( $nextContextDepth, "parentContext$contextDepth"  )}$this->subcontexts());
    # FIXME: need to deal with the condition when a _ is allowed to downgrade to non-subcontexts.
    my $tokenizeSubcontext = "";
    if( $this->count_subcontexts() ){
        $tokenizeSubcontext= qq/
        std::vector<std::string> ctxStr$nextContextDepth;
        boost::split(ctxStr$nextContextDepth, ctxStrs[$nextContextDepth], boost::is_any_of("[,]") ); /;
    }
    my $s = qq/if( ctxStr${contextDepth}[0] == "$this->{name}" ){
        $declareParams
        $getContextObj

        $this->{className}* parentContext$contextDepth = $declareContextObj;
        ctxobj = dynamic_cast<mace::ContextBaseClass*>(parentContext$contextDepth);
        if( ctxStrsLen == $nextContextDepth ) return ctxobj;
        $tokenizeSubcontext
        $subcontextConditionals
    }
    /;
    return $s;
}
1;
