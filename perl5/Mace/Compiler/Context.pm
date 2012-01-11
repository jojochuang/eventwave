# 
# Context.pm : part of the Mace toolkit for building distributed systems
# 
# Copyright (c) 2011, Wei-Chiu Chuang
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
     'object' => ["keyType" => { class => "Mace::Compiler::Type"}],
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
        $r .= "\n${t} $n();\n";
    } else {
        my $keyType = $_->keyType();
        $r .= "mace::map<" . $keyType->name() . "," . $_->className() . "> " . $_->name() . ";\n";
    }
    return $r;
}

sub toString {
    my $this = shift;
    my $serviceName = shift;
    my %args = @_;
    my $r;
    my $n = $this->className();

    my $subcontextDeclaration = "";
    #my $subcontextDefinition = "";
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
        #$subcontextDefinition .= $_->toString($serviceName, traceLevel => $args{traceLevel}) . ";\n";
        if( $_->{isMulti} == 0 ){
            $subcontextDeclaration .= $_->className() . " " . $_->name() . ";\n";
        }else{
            my $keyType = $_->keyType();
            $subcontextDeclaration .= "mace::map<" . $keyType->name() . "," . $_->className() . "> " . $_->name() . ";\n";
        }
    }
      $serializeFields = join("", map{qq/mace::serialize(__str, &${\$_->name()});\n/} $this->subcontexts(),$this->ContextVariables(), $this->ContextTimers()  );
      $deserializeFields = join("", map{qq/serializedByteSize += mace::deserialize(__in, &${\$_->name()});\n/} $this->subcontexts(),$this->ContextVariables(), $this->ContextTimers());
    my $serializeBody = qq/
        \/\/mace::serialize(__str, &);
    /;
    my $deserializeBody = qq/
      \/\/return mace::deserialize(__in, &nextScheduledTime);
    /;
    my $maptype="";
    my $keytype="";
	$serializeBody = qq/
          \/*
          uint32_t sz = timerData.size();
          mace::serialize(__str, &sz);
          for(${maptype}::const_iterator i = timerData.begin(); i != timerData.end(); i++) {
            $keytype key = i->first;
            mace::serialize(__str, &key);
	    TimerData* td __attribute((unused)) = i->second;
        *\/
	    $serializeFields
          \/\/}
	/;
    my $callParams="";
	$deserializeBody = qq/
          int serializedByteSize = 0;
          \/\/uint32_t sz;
          \/\/serializedByteSize += sizeof(sz);
          \/\/mace::deserialize(__in, &sz);

          \/\/for(size_t i = 0; i < sz; i++) {
            \/\/$keytype key;
            \/\/serializedByteSize += mace::deserialize(__in, &key);
            \/\/;
	    $deserializeFields
	    \/\/TimerData* td = new TimerData($callParams);
            \/\/timerData[key] = td;
          \/\/}
          return serializedByteSize;
	/;
    my $serializeMethods = "";
    if ($this->serialize()) {
	$serializeMethods = qq/
              void serialize(std::string& __str) const {
                $serializeBody
              }
              int deserialize(std::istream& __in)  throw (mace::SerializationException){
                $deserializeBody
              }
/;
    }

    $r .= qq/class ${n} : public mace::ContextBaseClass\/*, public mace::PrintPrintable *\/{
            public:
              ${n}(\/*$serviceName *a *\/)
                 
              {
	      }

	      virtual ~${n}() {
	      }
              $serializeMethods

          public:
            \/\/ FIXME: add timers declaration
            $contextTimerDefinition
            $contextTimerDeclaration
            \/\/ FIXME: add state var declaration
            $contextVariableDeclaration
            \/\/ FIXME: add your child context
            $subcontextDeclaration
    

};
    /;
    return $r;
}

1;
