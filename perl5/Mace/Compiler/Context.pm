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
     'boolean' => "isMulti",
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

sub validateTypeOptions {
    my $this = shift;
    $this->serialize(1);

    for my $subcontext ( $this->subcontexts ) {
        $subcontext->validateTypeOptions();
    }
}

sub toSerialize {
  my $this = shift;
  my $str = shift;
  if($this->serialize()) {
    my $name = $this->name();
    my $s = qq/${\$this->name}.serialize($str);/;
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
        my $s = qq/$prefix ${\$this->name}.deserialize($in);/;
        return $s;
    }
    return '';
}

sub toDeclareString {
#my $contextDeclares = join("\n", map{my $t = $_->className(); my $n = $_->name(); qq/ class ${t};\n${t} $n(); /;} $this->contexts());
    my $this = shift;
    my $t = $this->className();
    my $n = $_->name();

#    my $r = qq/class ${t};/;

    my $r = "";
    if( $this->isMulti == 0 ){
        $r .= "\n${t} $n;\n";
    } else {
        $r .= "mace::map<" . $_->paramType->className() . "," . $_->className() . "> " . $_->name() . ";\n";
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
    my $serializeFields = "";
    my $deserializeFields = "";
    foreach( $this->ContextVariables ){
        $contextVariableDeclaration .= $_->toString(nodefaults => 1, semi => 0) . ";\n";
    }
    foreach( $this->ContextTimers ){
        $contextTimerDeclaration .= $_->toString($serviceName, traceLevel => $args{traceLevel} ) . ";\n";
    }
    foreach( $this->subcontexts ){
        if( $_->{isMulti} == 0 ){
            $subcontextDeclaration .= $_->className() . " " . $_->name() . ";\n";
        }else{
            $subcontextDeclaration .= "mace::map<" . $_->paramType->className() . "," . $_->className() . "> " . $_->name() . ";\n";
        }
    }
      $serializeFields = join("", map{qq/mace::serialize(__str, &${\$_->name()});\n/} $this->subcontexts(),$this->ContextVariables(), $this->ContextTimers()  );
      $deserializeFields = join("", map{qq/serializedByteSize += mace::deserialize(__in, &${\$_->name()});\n/} $this->subcontexts(),$this->ContextVariables(), $this->ContextTimers());
    my $maptype="";
    my $keytype="";
    my $callParams="";
    my $serializeMethods = "";
    if ($this->serialize()) {
        my $serializeBody = qq/
            $serializeFields
        /;
        my $deserializeBody = qq/
              int serializedByteSize = 0;
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

    $r .= qq/
class ${n} : public mace::ContextBaseClass\/*, public mace::PrintPrintable *\/{
public:
    ${n}(const mace::string& contextID="" ): mace::ContextBaseClass(contextID)
    { }
    ${n}( const ${n}& _ctx ) $deepCopy
    { }

    virtual ~${n}() { }
      $serializeMethods

public:
    \/\/ add timers declaration
    $contextTimerDefinition
    $contextTimerDeclaration
    \/\/ add state var declaration
    $contextVariableDeclaration
    \/\/ add child contexts
    $subcontextDeclaration

    \/\/ take snapshot
    void snapshot( const uint64_t& ver ) const {
        ADD_SELECTORS("${n}::snapshot");
        ${n}* _ctx = new ${n}(*this);
        macedbg(1) << "Snapshotting version " << ver << " for this " << this << " value " << _ctx << Log::endl;
        ASSERT( versionMap.empty() || versionMap.back().first < ver );
        versionMap.push_back( std::make_pair(ver, _ctx) );
    }
    void snapshotRelease( const uint64_t& ver ) const {
        ADD_SELECTORS("${n}::snapshotRelease");
        while( !versionMap.empty() && versionMap.front().first < ver ){
            macedbg(1) << "Deleting snapshot version " << versionMap.front().first << " for service " << this << " value " << versionMap.front().second << Log::endl;
            delete versionMap.front().second;
            versionMap.pop_front();
        }
    }
    \/\/ get snapshot using the current event id.
    const ${n}& getSnapshot() const {
            VersionServiceMap::const_iterator i = versionMap.begin();
            \/\/ FIXME: need to use high level event id instead of low level event ticket.
            uint64_t sver = mace::AgentLock::snapshotVersion();
            while (i != versionMap.end()) {
                if (i->first == sver) {
                    break;
                }
                i++;
            }
            if (i == versionMap.end()) {
                Log::err() << "Error reading from snapshot " << mace::AgentLock::snapshotVersion() << " ticket " << Ticket::myTicket() << Log::endl;
                std::cerr << "Error reading from snapshot " << mace::AgentLock::snapshotVersion() << " ticket " << Ticket::myTicket() << std::endl;
                ABORT("Tried to read from snapshot, but snapshot not available!");
            }
            return *(i->second);
    }

    \/\/ FIXME: Support checking only immediate child contexts...
    bool checkValidTransition( const mace::string& nextContextName ){
        \/\/ if this context class has subclass, and the prefix of nextContextName matches my context name
        $checkSubcontextPrefix
        \/\/ or, this context has 'downgradeto' context and it matches nextContextName
        $checkDowngradeTo

        return false;
    }
private:
    typedef std::deque<std::pair<uint64_t, const ${n}* > > VersionServiceMap;
    mutable VersionServiceMap versionMap;
    
};
    /;
    # XXX: if migration takes place, should it take the snapshot of the previous snapshot?
    return $r;
}

1;
