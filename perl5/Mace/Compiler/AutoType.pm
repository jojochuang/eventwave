# 
# AutoType.pm : part of the Mace toolkit for building distributed systems
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
package Mace::Compiler::AutoType;
#XXX hoping to consolidate this with others!
use strict;

#use Mace::Compiler::Method;
use Mace::Compiler::SQLize;
use v5.10.1;
use feature 'switch';

my %messageNums;
use Data::Dumper;
use constant {
    FLAG_NONE           => 0,  # user defined messages
    FLAG_ASYNC          => 1,  # messages created from async transition
    FLAG_SYNC           => 2,  # messages created from routines
    FLAG_DOWNCALL       => 3,  # messages created from downcall transition
    FLAG_UPCALL         => 4,  # messages created from upcall transition
    FLAG_TIMER          => 5,  # messages created from timer transition
    FLAG_APPUPCALL      => 6,  # upcall from services into application, return void
    FLAG_CONTEXT        => 7,  # other messages necessary for context mace
    FLAG_DELIVER        => 8,  # messages created from receiving an external message
};

use Class::MakeMethods::Template::Hash 
    (
     'new' => 'new',
     'string' => "name",
     'array_of_objects' => ["typeOptions" => { class => "Mace::Compiler::TypeOption" }],
     'array_of_objects' => ["typedefs" => { class => "Mace::Compiler::TypeDef" }],
     'array_of_objects' => ["fields" => { class => "Mace::Compiler::Param" }],
     'array_of_objects' => ["methods" => { class => "Mace::Compiler::Method" }],
     'array_of_objects' => ["constructors" => { class => "Mace::Compiler::Method" }],
     'number' => 'line',
     'string' => 'filename',
     
#Auto Type Options
     'boolean' => 'serialize',
     'boolean' => 'node',
     'string' => 'scoreType',
     'string' => 'scoreField',
     'boolean' => 'failDetect',
     'boolean' => 'equalComparable',
     'boolean' => 'lessthanComparable',
     'boolean' => 'hashComparable',
     'boolean' => 'isPrivate',
     'number' => 'messageNum',
     'number' => 'method_type', 
     'boolean' => 'defaultConstructor',

     'hash --get_set_items' => 'options',
     
#     'array_of_objects' => ["methods" => { class => "Mace::Compiler::Method" }],
#     'array_of_objects' => ["constructors" => { class => "Mace::Compiler::Method" }],
#     'object' => ["destructor" => { class => "Mace::Compiler::Method" }],
#     'array' => "superclasses",
     );

sub toString {
    my $this = shift;
    my $s = $this->name()." {\n";
    #XXX add option printing?
    $s .= join("", map { "    ".$_->toString().";\n" } $this->fields());
    $s .= "  }";
    return $s;
} # toString

sub toForwardDeclare {
    my $this = shift;
    return "class ".$this->name.";\n";
}

sub validateAutoTypeOptions {
  my $this = shift;
  $this->serialize(1);
  $this->node(0);
  $this->equalComparable(0);
  $this->lessthanComparable(0);
  $this->hashComparable(0);
  $this->isPrivate(0);
  $this->defaultConstructor(1);

  my %processedOptions;

  foreach my $option ($this->typeOptions()) {
    Mace::Compiler::Globals::error('bad_type_option', $option->file(), $option->line(), "Cannot define option ".$option->name()." more than once!") unless(++$processedOptions{$option->name()} == 1);
    if($option->name() eq 'serialize') {
      while(my ($name, $value) = each(%{$option->options()})) {
        if($name eq 'no') {
          $this->serialize(0);
        }
        elsif(! $name eq 'yes') {
          Mace::Compiler::Globals::error('bad_type_option', $option->file(), $option->line(), "Invalid option with name $name and value $value");
        }
      }
    }
    elsif($option->name() eq 'constructor') {
      while(my ($name, $value) = each(%{$option->options()})) {
        if( $name eq "default" ){
          if( $value eq "no" ){
            $this->defaultConstructor(0);
          }
        }
      }
    }
    elsif($option->name() eq 'node') {
      $this->node(1);
      $this->failDetect(0);
      $this->scoreField("0.0");
      $this->scoreType("double");
      while(my ($name, $value) = each(%{$option->options()})) {
        if($name eq 'score') {
          $this->scoreField($value);
          my $fieldFound = 0;
          foreach my $field ($this->fields()) {
            if($field->name() eq $value) {
              $fieldFound = 1;
              $this->scoreType($field->type()->toString());
              last;
            }
          }
          Mace::Compiler::Globals::error('bad_type_option', $option->file(), $option->line(), "Score field '$value' does not match any auto type fields!") unless($fieldFound);
        }
        elsif($name eq 'tracked_services') {
          Mace::Compiler::Globals::warning('unimplemented', $option->file(), $option->line(), "tracked_services not implemented yet");
        }
        elsif($name eq 'fail_detect') {
          $this->failDetect(1) if(!$value eq 'disabled');
        }
        else {
          Mace::Compiler::Globals::error('bad_type_option', $option->file(), $option->line(), "Invalid option with name $name and value $value");
        }
      }
    }
    elsif($option->name() eq 'comparable') {
      while(my ($name, $value) = each(%{$option->options()})) {
        if($name eq 'equals') {
          $this->equalComparable(1);
          if($value ne "default") { 
            #TODO: Implement var list as non-default
            Mace::Compiler::Globals::error('bad_type_option', $option->file(), $option->line(), "non-default equals comparison not yet supported");
          }
        }
        elsif($name eq 'lessthan') {
          $this->lessthanComparable(1);
          $this->equalComparable(1);
          if($value ne "default") { 
            #TODO: Implement var list as non-default
            Mace::Compiler::Globals::error('bad_type_option', $option->file(), $option->line(), "non-default lessthan comparison not yet supported");
          }
        }
        elsif($name eq 'hashof') {
          $this->hashComparable(1);
            #TODO: Implement some hash generator
          Mace::Compiler::Globals::error('bad_type_option', $option->file(), $option->line(), "hashof comparison not yet supported");
        }
        else {
          Mace::Compiler::Globals::error('bad_type_option', $option->file(), $option->line(), "Invalid option with name $name and value $value");
        }
      }
    }
      elsif ($option->name() eq 'private') {
	  $this->isPrivate(1);
	  while(my ($name, $value) = each(%{$option->options()})) {
	      if($name eq 'no') {
		  $this->isPrivate(0);
	      }
	      elsif(! $name eq 'yes') {
		  Mace::Compiler::Globals::error('bad_type_option', $option->file(), $option->line(), "Invalid option with name $name and value $value");
		}
	  }
      }
    else {
      Mace::Compiler::Globals::error('bad_type_option', $option->file(), $option->line(), "Invalid option ".$option->name());
    }
  }

  foreach my $field ($this->fields()) {
    $field->validateTypeOptions({'serialize'=>1});
  }
}

sub setNumber {
  my $this = shift;
  my $last = shift;
  my $name = $this->name();

  if ($this->messageNum() != -1) {
    $$last = $this->messageNum();
  } else {
    $$last++;
    $this->messageNum($$last);
  }
  if ($messageNums{$$last}) {
    Mace::Compiler::Globals::error('message_num_error', $this->filename(), $this->line(), "Message '$name' with number '$$last' duplicates the number for message '".$messageNums{$$last}."'");
  }
  $messageNums{$$last} = $name;

  return $$last;
}

sub setRequestNumber {
  my $this = shift;
  my $last = shift;
  my $name = $this->name();

  $$last++;
  $this->messageNum($$last);

  #if ($messageNums{$$last}) {
  #  Mace::Compiler::Globals::error('message_num_error', $this->filename(), $this->line(), "Message '$name' with number '$$last' duplicates the number for message '".$messageNums{$$last}."'");
  #}
  #$messageNums{$$last} = $name;

  return $$last;
}

sub validateMessageOptions {
  my $this = shift;
  #XXX Need to parse message options

  my %processedOptions;

  $this->serialize(1);
  $this->node(0);
  $this->messageNum(-1);

  foreach my $option ($this->typeOptions()) {
    Mace::Compiler::Globals::error('bad_type_option', $option->file(), $option->line(), "Cannot define option ".$option->name()." more than once!") unless(++$processedOptions{$option->name()} == 1);
    if ($option->name() eq "number") {
      while(my ($name, $value) = each(%{$option->options()})) {
        if($this->messageNum() == -1 and $name =~ /^\d*$/) {
          $this->messageNum($name);
        }
        else {
          Mace::Compiler::Globals::error('bad_type_option', $option->file(), $option->line(), "The number option must be set only to a number, invalid at '$name'");
        }
      }
    }
    else {
      Mace::Compiler::Globals::error('bad_type_option', $option->file(), $option->line(), "Invalid option ".$option->name()." (no options yet supported for messages)");
    }
  }
  foreach my $field ($this->fields()) {
    $field->validateTypeOptions({'serialize'=>0});
  }
}

sub toAutoTypeString {
    my $this = shift;
    my $name = $this->name();
    my %args = @_;
    # for now, auto types should always log all of their fields
    for my $f ($this->fields()) {
	$f->shouldLog(1);
    }
    my $sqlizeBody = Mace::Compiler::SQLize::generateBody(\@{$this->fields()}, 0, 1);
    my $s = "class $name : public mace::PrintPrintable";
    if($this->serialize()) { $s .= ", public mace::Serializable"; }
    $s .= " {\n";
    my $initSerialize = "";
    if($this->serialize()) {
	$s .= "private:
    mutable size_t serializedByteSize;
    ";
	$initSerialize = "serializedByteSize(0)";
	if ($this->node() || $this->count_fields()) {
	    $initSerialize .= ",";
	}
    }

    if($this->node()) {
      my $scoreType = $this->scoreType();
      my $scoreField = $this->scoreField();
      $s .= <<END;
  private:
    MaceKey _id;
  public:
END
      if($this->failDetect()) {
        $s .= <<END;
    uint64_t __d_time;
    uint64_t __d_probe;
END
      }
      $s .= <<END;
    const MaceKey& getId() const { return _id; }
    $scoreType getScore() const { return $scoreField; }
END
    }
    $s .= <<END;
  public:
END
    if ($this->isPrivate()) {
	$s .= "private:\n";
    }

    $s .= join("", map { "    ".$_->toString().";\n" } $this->typedefs());
    
    $s .= join("", map { "    ".$_->toString(nodefaults => 1, mutable => 1).";\n    ".$_->type()->toString()." get_".$_->name()."() const { return ".$_->name()."; }\n" } $this->fields());

    if ($this->isPrivate()) {
	$s .= "public:\n";
    }
    

    if ( $this->defaultConstructor() and ( (not $this->count_fields()) or grep(/0/, map{$_->hasDefault()} $this->fields()))) {
	#Basic Constructor
	if($this->node()) {
	    $s .= "    $name(MaceKey __id = MaceKey()) : $initSerialize _id(__id)";
	    if($this->failDetect) {
		$s .= q{, __d_time(0), __d_probe(0)};
	    }
	    if(scalar(@{$this->fields})) {
		$s .= q{, };
	    }
	} else {
	    $s .= "    $name()";
      $s .= " : $initSerialize ";
	}
	$s .= join(', ', map {
	    $_->name."(".($_->hasDefault() ? $_->default() : "") . ")"
	    } @{$this->fields()} );
	$s .= " {}\n";
    }

    #Constructor with parameters
    if($this->count_fields()) {
      if($this->node()) {
        $s .= "    $name(MaceKey __id";
	if (!grep(/0/, map{$_->hasDefault()} $this->fields())) {
	    $s .= " = MaceKey()";
	}
        if(scalar(@{$this->fields})) {
          $s .= ', ';
        }
      } else {
        $s .= "    $name(";
      }
      $s .= join(', ', map {$_->type->toString(paramconst=>1, paramref=>1) . " _".$_->name().  ($_->hasDefault() ? " = " . $_->default() : "") } @{$this->fields()} );
      $s .= ") ";
      if($this->node()) {
        $s .= ": $initSerialize _id(__id)";
        if($this->failDetect()) {
          $s .= ", __d_time(0), __d_probe(0)";
        }
        if(scalar(@{$this->fields})) {
          $s .= ", ";
        }
      }
      else {
        if(scalar(@{$this->fields})) {
          $s .= ": $initSerialize ";
        }
      }
      $s .= join(', ', map { $_->name."(_".$_->name.")" } @{$this->fields()} );
      $s .= " {}\n";
    }

    my $dobody = 0;
    if ($args{body}) { $dobody = $args{body}; }

    for my $m ($this->constructors) {
      $s .= $m->toString(noreturn => 1, body=>$dobody) . ";\n";
    }

    #Destructor
    $s .= "virtual ~$name() {}\n";

    $s .= join("\n", map { $_->toString(body=>$dobody).";" } $this->methods());
    $s .= join("\n", map { $_->shouldLogFunc()} $this->methods());

    my $tracelevel = 0;
    if (defined($args{tracelevel})) {
        $tracelevel = $args{tracelevel};
    }

    $s .= "\n".join("\n", grep(/./, map{if($_->returnType()->type() ne "void" and $_->getLogLevel($tracelevel) > 1) { $_->toString(methodprefix=>"__mace_log_").";"}} $this->methods()));

    #Print method and state method
    my $nodeString = "";
    my $failDetectString = "";
    my $printNodeString = "";
    my $printNodePrinter = "__${name}Printer";
    if($this->node) {
      $nodeString .= " << _id";
      $printNodeString .= qq{mace::printItem($printNodePrinter, "id", &_id);\n};
      if(scalar(@{$this->fields})) {
        $nodeString .= qq{ << ", "};
      }
      if($this->failDetect) {
        $failDetectString .= qq{<< ", __d_time =" << __d_time << ", __d_probe =" << __d_probe};
      }
    }
    $printNodeString .= join(";\n", grep(/./, map{ $_->toPrintNode($printNodePrinter) } $this->fields()));
    my $printFields = join(qq{\n__out << ", ";\n}, grep(/./, map{ $_->toPrint("__out") } $this->fields()));
    my $printFieldState = join(qq{\n__out << ", ";\n}, grep(/./, map{ $_->toPrintState("__out") } $this->fields()));
    $s .= <<END;
    void printNode(mace::PrintNode& __pr, const std::string& __name) const {
      mace::PrintNode $printNodePrinter(__name, "$name");
      $printNodeString
      __pr.addChild($printNodePrinter);
    }
    void print(std::ostream& __out) const {
      __out << "$name(" $nodeString $failDetectString;
      $printFields
      __out << ")";
    }
    void printState(std::ostream& __out) const {
      __out << "$name(" $nodeString;
      $printFieldState
      __out << ")";
    }
END

    if($this->serialize()) {
      #serialize method
      $s .= <<END;
    void serialize(std::string& str) const {
      serializedByteSize = str.size();
END
      if($this->node()) {
        $s .= <<END;
      mace::serialize(str, &_id);
END
      }
      map { $s .= $_->toSerialize("str")."\n" } $this->fields();

      $s .= <<END;
      serializedByteSize = str.size() - serializedByteSize;
    }
END
      #deserialize method
      $s .= <<END;
    int deserialize(std::istream& __mace_in) throw(mace::SerializationException) {
      serializedByteSize = 0;
END
      if($this->node()) {
        $s .= <<END;
      serializedByteSize += mace::deserialize(__mace_in, &_id);
END
      }
      map { $s .= $_->toDeserialize("__mace_in", prefix => "serializedByteSize += ")."\n" } $this->fields();


      $s .= <<END;
      return serializedByteSize;
    }

    void sqlize(mace::LogNode* __node) const {
	$sqlizeBody
    }
    
    size_t getSerializedSize() const {
      return serializedByteSize;
    }

    int deserializeXML_RPC(std::istream& __mace_in) throw(mace::SerializationException) {
        int __fields = 0;
        std::istream::pos_type __m_offset = __mace_in.tellg();
        mace::SerializationUtil::expectTag(__mace_in, "<struct>");

        std::string tag = mace::SerializationUtil::getTag(__mace_in);
        while (tag == "<member>") {
            __fields++;
            mace::SerializationUtil::expectTag(__mace_in, "<name>");
            std::string __var = mace::KeyTraits<mace::string>::extract(__mace_in);
            mace::SerializationUtil::expectTag(__mace_in, "</name>");
            mace::SerializationUtil::expectTag(__mace_in, "<value>");

END
      if($this->node()) {
        $s .= <<END;
        if (__var == "_id") {
            mace::deserializeXML_RPC(__mace_in, &_id, _id);
        } else
END
      }
      my $cnt_flds = 0;
      map { if ($_->flags('serialize')) { $cnt_flds++; my $n = $_->name(); $s .= qq/if (__var == "$n") {
                                                                      mace::deserializeXML_RPC(__mace_in, & $n, $n);
                                                                  } else
                                                                  /; } } $this->fields();

        $s .= <<END;
            {
                throw(new mace::SerializationException("deserializing $name: unknown field " + __var + " found"));
            }
            mace::SerializationUtil::expectTag(__mace_in, "</value>");
            mace::SerializationUtil::expectTag(__mace_in, "</member>");
            tag = mace::SerializationUtil::getTag(__mace_in);
        }
        if (__fields != $cnt_flds) {
            throw(new mace::SerializationException("deserializing $name: incorrect number of fields found"));
        }
        if (tag != "</struct>") {
            throw mace::SerializationException("error parsing tag: expected </struct>, parsed " + tag);
        }

        //   __mace_in >> skipws;
        return __mace_in.tellg() - __m_offset;
    }

    void serializeXML_RPC(std::string& str) const throw(mace::SerializationException) {
        str.append("<struct>");

END
      if($this->node()) {
        $s .= <<END;
        str.append("<member><name>_id</name><value>");
        mace::serializeXML_RPC(str, &(_id), _id);
        str.append("</value></member>");
END
      }
      map { if ($_->flags("serialize")) { $s .= <<END;
        str.append("<member><name>${\$_->name()}</name><value>");
        mace::serializeXML_RPC(str, &(${\$_->name()}), ${\$_->name()});
        str.append("</value></member>");
END
      } } $this->fields();
      $s .= <<END;

        str.append("</struct>");
    }
END
    }

    if($this->equalComparable()) {
      my $fieldscompare = join("\n", map{ "if(this->".$_->name." != other.".$_->name.") { return false; }" } grep { !$_->flags("notComparable") } $this->fields())."\n";
      $s .= <<END;
    bool operator== (const $name& other) const {
      $fieldscompare
      return true;
    }
    bool operator!= (const $name& other) const {
      return !(*this == other);
    }
END
    }

    if($this->lessthanComparable()) {
      my $fieldscompare = join("\n", map{ "if(this->".$_->name." < other.".$_->name.") { return true; }
                                           if(this->".$_->name." != other.".$_->name.") { return false; }" } grep { !$_->flags("notComparable") } $this->fields())."\n";
      $s .= <<END;
    bool operator< (const $name& other) const {
      $fieldscompare
      return false; //they are actually equal
    }
END
    }

    $s .= "  };";
    return $s;
} # toAutoTypeString

sub defineAutoTypeMethods {
    my $this = shift;
    my %opts = @_;
    my $name = $this->name();
  
    my $s = "";
    for my $m ($this->methods()) {
        my $under = "";
        my $fnName = $m->name();
        my $loglevel = $m->getLogLevel($opts{logparams});
	
	$s .= $m->shouldLogFuncBody($this->name(), $loglevel);
	
        if ($loglevel > 1 and $m->returnType->type() ne "void") {
          my $fnNameSquashed = $m->squashedName();
          my $paramlist = join(",", map{ $_->toString(notype=>1, nodefaults=>1) } $m->params());
	  my $rt = $m->returnType->toString();
	  my $type = "\"rv_" . Mace::Util::typeToTable($rt) . "\"";
	  if ($fnName eq "getMembers") {
	      print "Making binlog body for $fnName dolog is " . $m->doStructuredLog(). "\n";
	  }
          $s .= $m->toString(methodprefix=>"${name}::", nostatic=>1, nodefaults=>1, binarylog=>$m->doStructuredLog(), add_selectors=>$name, traceLevel=>$loglevel, usebody=>qq/
            return mace::logVal(__mace_log_$fnNameSquashed($paramlist), selectorId->compiler, $type);
	    /);
          $under = "__mace_log_";
	  $s .= $m->toString(methodprefix=>"${name}::${under}", nostatic=>1, body=>1, prepare=>1, nodefaults=>1, nologs=>1, traceLevel=>$loglevel, add_selectors=>$name, %opts);
        }
	else {
#	    print "Making void binlog body for $fnName dolog is ".$m->doStructuredLog(). "\n";
	    $s .= $m->toString(methodprefix=>"${name}::${under}", nostatic=>1, body=>1, prepare=>1, nodefaults=>1, binarylog=>$m->doStructuredLog(), traceLevel=>$loglevel, add_selectors=>$name, %opts);
	}
    }
    for my $m ($this->constructors) {
      $s .= $m->toString(methodprefix=>"${name}::", nodefaults=>1, noreturn => 1, body=>1) . "\n";
    }
    return $s;
} # defineAutoTypeMethods

sub toMessageString {
  my $this = shift;
  my $servicename = shift;
  my $messagenum = $this->messageNum();

  my $s;

  $s .= $this->toMessageStructString();
  $s .= $this->toMessageClassString($servicename, $messagenum);

} # toMessageString

sub toMessageStructString {
  my $this = shift;
  my $msgName = $this->name();
  my $fieldStr = "";
  if(scalar(@{$this->fields()})) {
    $fieldStr = "\n" . join("\n", map { $_->toString(nodefaults=>1).';' } $this->fields() ) . "\n";
    given( $this->method_type ){
      when ([FLAG_ASYNC, FLAG_TIMER, FLAG_DELIVER, FLAG_APPUPCALL]){
        if ($this->count_fields() -2 > 0 or $this->method_type == FLAG_APPUPCALL ){
          $fieldStr .= " ${\$this->name}_struct (  ){} \n";
          my $field_params = join(", ", map { my $p = $_->name; $_->type->toString(paramconst=>1, paramref=>1) . " $p" } grep { $_->name ne "extra" and $_->name ne "event" } $this->fields() );
          my $field_init = join(", ", map { my $p = $_->name; "$p( $p )" } grep { $_->name ne "extra" and $_->name ne "event" } $this->fields() );
          $fieldStr .= qq/
          ${\$this->name}_struct ( $field_params ):
            $field_init { }
          /;
        }
      }
    }
  }
  my $s = qq{
    struct ${\$this->name}_struct { $fieldStr };
  };
}

sub toMessageClassString {
  my $this = shift;
  my $servicename = shift;
  my $messagenum = shift;
  my $msgName = $this->name();

  my $servicescope = "";
  if ($servicename ne "") {
    $servicescope = $servicename."Service::";
  }
  # for now, messages should always log all of their fields
  for my $f ($this->fields()) {
      $f->shouldLog(1);
  }
  my $constructorTwo = "";
  my $constructorThree = "";

  my $fieldsOne = join("", map { ", " . $_->name() . '(_data_store_->' . $_->name() . ')' } $this->fields());
  my $structFields = join("", map { '_data_store_->' . $_->name() . " = _orig." . $_->name() . ";\n" } $this->fields());
  if(scalar(@{$this->fields()})) {
    my $fieldsTwoA= join(", ", map { $_->type->toString(paramconst=>1, paramref=>1).' my_'.$_->name() } $this->fields());
    my $fieldsTwoB= join(", ", map { $_->name.'(my_'.$_->name().')' } $this->fields());
    $constructorTwo = qq{$msgName($fieldsTwoA) : _data_store_(NULL), $fieldsTwoB {}};

    given( $this->method_type ){
      when ([FLAG_ASYNC, FLAG_TIMER, FLAG_DELIVER, FLAG_APPUPCALL]){
        my $fieldsTwoC= join(", ", "mace::InternalMessage_type t",
          map { $_->type->toString(paramconst=>1, paramref=>1).' my_'.$_->name() } 
            grep{ $_->name ne "extra" and $_->name ne "event"} $this->fields()   
        );
        my $struct_init = join(", ", 
          map { ' my_'.$_->name() } grep{ $_->name ne "extra" and $_->name ne "event"} $this->fields()   
        );

        my $fieldsTwoD= join(", ", map { $_->name.'(_data_store_->'.$_->name().')' } $this->fields());

        $constructorThree = qq/$msgName($fieldsTwoC) : _data_store_(new ${msgName}_struct( $struct_init )), $fieldsTwoD {
        
        }/;
      }
    }
  }
  my $fields = "\n".join('', map { $_->type()->toString(paramconst=>1, paramref=>1).' '.$_->name().";\n" } $this->fields());
  my $fieldPrint = join(qq{\n__out << ", ";\n}, grep(/./, map{ $_->toPrint("__out") } $this->fields()) );
  my $serializeFields = join("\n", map{ $_->toSerialize("str") } $this->fields());

  my $deserializeFields = join("\n", map{ $_->toDeserialize("__mace_in", prefix => "serializedByteSize += ", 'idprefix' => '_data_store_->') } $this->fields());
  my $sqlizeBody = Mace::Compiler::SQLize::generateBody(\@{$this->fields()}, 0, 1);
  
  my $accessorMethod = "";
  given( $this->method_type() ){
      when ([FLAG_ASYNC, FLAG_TIMER, FLAG_DELIVER]){
        $accessorMethod = qq/__asyncExtraField& getExtra() { return _data_store_->extra; }
                             mace::Event& getEvent() { return _data_store_->event; }/;
      }
      when ([FLAG_SYNC]){
        $accessorMethod = qq/const uint32_t getTargetContextID() { return targetContextID; }
                             mace::Event& getEvent() { return _data_store_->event; }/;
      }
  }

  my $baseClassType = "Message";
  given( $this->method_type() ){
      when ([FLAG_ASYNC, FLAG_TIMER, FLAG_DELIVER]){
        $baseClassType = "mace::AsyncEvent_Message";
      }
      when ([FLAG_APPUPCALL]){
        $baseClassType = "mace::ApplicationUpcall_Message";
      }
      when ([FLAG_NONE]){
        $baseClassType = "Message";
      }
      when ([FLAG_SYNC]){
        $baseClassType = "mace::Routine_Message";
      }
      default{
        $baseClassType = "Message";
      }

  }
  my $s = qq/
    class ${servicescope}$msgName : public $baseClassType, public mace::PrintPrintable {
      private:
      ${msgName}_struct* _data_store_;
      public:
      $msgName() : _data_store_(new ${msgName}_struct()) $fieldsOne {}
      $constructorTwo
      $constructorThree
      $msgName(const $msgName& _orig) : _data_store_(new ${msgName}_struct())  $fieldsOne {
        $structFields
      }
      $msgName& operator=(const $msgName& _orig){
        $structFields
        return *this;
      }
      virtual ~$msgName() { delete _data_store_; _data_store_ = NULL; }
      $fields
      static const uint8_t messageType = $messagenum;
      static uint8_t getMsgType() { return messageType; }
      uint8_t getType() const { return ${msgName}::getMsgType(); }

      $accessorMethod

      std::string toString() const { return mace::PrintPrintable::toString(); }
      void print(std::ostream& __out) const {
        __out << "${msgName}(";
        $fieldPrint 
        __out << ")";
      }
      void serialize(std::string& str) const {
	if (!serializedCache.empty()) {
	  str.append(serializedCache);
	  return;
	}
        uint8_t messaget = messageType;
	size_t initsize = str.size();
        mace::serialize(str, &messaget);
        ${serializeFields}
	if (initsize == 0) {
	  serializedCache = str;
	}
	serializedByteSize = str.size() - initsize;
      }
      int deserialize(std::istream& __mace_in) throw (mace::SerializationException) {
	serializedByteSize = 0;
        uint8_t messaget = 255;
        serializedByteSize += mace::deserialize(__mace_in, &messaget);
        ASSERT(messaget == messageType);
        ${deserializeFields}
        return serializedByteSize;
      }
      
      void sqlize(mace::LogNode* __node) const {
	$sqlizeBody
      }
    };
  /;
  return $s;
}

1;
