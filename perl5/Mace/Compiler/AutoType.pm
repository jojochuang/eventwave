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
use Switch 'Perl6';

my %messageNums;

use constant {
    FLAG_NONE           => 0,
    FLAG_ASYNC          => 1,
    FLAG_SYNC           => 2,
    FLAG_TARGET_ASYNC   => 3,
    FLAG_TARGET_SYNC    => 4,
    FLAG_SNAPSHOT       => 5,
    FLAG_DOWNCALL       => 6,
    FLAG_UPCALL         => 7,
    FLAG_TIMER          => 8,
    FLAG_APPUPCALL      => 9,
    FLAG_APPUPCALLRPC   => 10,
    FLAG_CONTEXT        => 11, # other messages necessary for context mace
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

sub toDeferredDeclarationString {
    my $this = shift;

    my $name = $this->name();
    my $str = qq/typedef mace::multimap<uint64_t, DeferralContainer_$name> Deferred_$name;
                Deferred_$name deferred_queue_$name;
                pthread_mutex_t deliverMutex_$name;
                /;
}

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
	    if(scalar(@{$this->fields})) {
		$s .= q{ : };
	    }
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

  my $fieldsOne = join("", map { ", " . $_->name() . '(_data_store_->' . $_->name() . ')' } $this->fields());
  my $structFields = join("", map { '_data_store_->' . $_->name() . " = _orig." . $_->name() . ";\n" } $this->fields());
  if(scalar(@{$this->fields()})) {
    my $fieldsTwoA= join(", ", map { $_->type->toString(paramconst=>1, paramref=>1).' my_'.$_->name() } $this->fields());
    my $fieldsTwoB= join(", ", map { $_->name.'(my_'.$_->name().')' } $this->fields());
    $constructorTwo = qq{$msgName($fieldsTwoA) : _data_store_(NULL), serializedByteSize(0), $fieldsTwoB {}};
  }
  my $fields = "\n".join('', map { $_->type()->toString(paramconst=>1, paramref=>1).' '.$_->name().";\n" } $this->fields());
  my $fieldPrint = join(qq{\n__out << ", ";\n}, grep(/./, map{ $_->toPrint("__out") } $this->fields()) );
  my $serializeFields = join("\n", map{ $_->toSerialize("str") } $this->fields());
  my $deserializeFields = join("\n", map{ $_->toDeserialize("__mace_in", prefix => "serializedByteSize += ", 'idprefix' => '_data_store_->') } $this->fields());
  my $sqlizeBody = Mace::Compiler::SQLize::generateBody(\@{$this->fields()}, 0, 1);
  
  my $s = qq/
    class ${servicescope}$msgName : public Message, public mace::PrintPrintable {
      private:
      ${msgName}_struct* _data_store_;
      mutable size_t serializedByteSize;
      mutable std::string serializedCache;
      public:
      $msgName() : _data_store_(new ${msgName}_struct()), serializedByteSize(0) $fieldsOne {}
      $constructorTwo
      $msgName(const $msgName& _orig) : _data_store_(new ${msgName}_struct()), serializedByteSize(0) $fieldsOne {
        $structFields
      }
      virtual ~$msgName() { delete _data_store_; _data_store_ = NULL; }
      $fields
      static const uint8_t messageType = $messagenum;
      static uint8_t getMsgType() { return messageType; }
      uint8_t getType() const { return ${msgName}::getMsgType(); }
      std::string toString() const { return mace::PrintPrintable::toString(); }
      void print(std::ostream& __out) const {
        __out << "${msgName}(";
        $fieldPrint 
        __out << ")";
      }
      size_t getSerializedSize() const {
	if (serializedByteSize == 0 && serializedCache.empty()) {
	  serialize(serializedCache);
	}
	return serializedByteSize;
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

      std::string serializeStr() const {
	if (serializedCache.empty()) {
	  serialize(serializedCache);
	}
	return serializedCache;
      }
      void deserializeStr(const std::string& __s) throw (mace::SerializationException) {
	serializedCache = __s;
	Serializable::deserializeStr(__s);
      }
    };
  /;
  return $s;
}
sub toWrapperName {
    my $this = shift;
    my $ptype = shift;

    given( $this->method_type() ){
        when Mace::Compiler::AutoType::FLAG_UPCALL {
            #my $ptype = $this->name;
            return "__deliver_wrapper_fn_$ptype";
        }
    }
}
sub toRealHandlerName {
    my $this = shift;
    my $ptype = shift;

    #my $uniqid = $this->transitionNum;
    #my $pname = $this->method->name;
    given( $this->method_type() ){
        when Mace::Compiler::AutoType::FLAG_UPCALL {
            #my $ptype = $this->name;
            return "__deliver_fn_$ptype";
        }
    }
}
sub createRealUpcallHandler {
    my $this = shift;
    my $pname = shift;
    
    my $adMethod = shift;
    my $adWrapperMethod = shift;

    my $this_subs_name = (caller(0))[3];
    my $upcall_param = "param";
    my $adWrapperName = $this->toWrapperName($pname);
    my $adName = $this->toRealHandlerName($pname);
    my @newMsg;
    foreach( $this->fields() ){
        given( $_->name ){
            when /^(__real_dest|__real_regid|__event|__msgcount)$/ { }
            default{ push @newMsg,  "${upcall_param}.$_->{name}"; }
        }
    }
    my $msgObj = join("", map{"," . $_ } @newMsg  );
    my $ptype = $this->name(); 
    my $adBody = qq#
        ASSERTMSG( contextMapping.getHead() == Util::getMaceAddr(), "This message is supposed to be received by the local head node. But this physical node is not head node.");
        // TODO: need to check that this message comes from one of the internal physical nodes.
        mace::AgentLock lock( mace::AgentLock::WRITE_MODE );
        {
            /*mace::string buf;
            mace::serialize(buf,&${upcall_param});
            mace::HierarchicalContextLock hl( he, buf );
            storeHeadLog(hl, he );*/
        }
        //ScopedLock sl( mace::ContextBaseClass::headMutex ); //ScopedLock sl( deliverMutex_$pname );

        deferred_queue_${pname}.insert( mace::pair<uint64_t, DeferralContainer_${pname} >( ${upcall_param}.__event, DeferralContainer_${pname}( ${upcall_param}.__real_dest $msgObj, ${upcall_param}.__real_regid ) )  );
        lock.downgrade( mace::AgentLock::NONE_MODE );
    #;
    my $adReturnType = Mace::Compiler::Type->new(type=>"void",isConst=>0,isConst1=>0,isConst2=>0,isRef=>0);
    my $adParamType = Mace::Compiler::Type->new( type => "$ptype", isConst => 1,isRef => 1 );
    my @adParam;
    push @adParam, Mace::Compiler::Param->new( name => "$upcall_param", type => $adParamType );
    $$adMethod = Mace::Compiler::Method->new( name => $adName, body => $adBody, returnType=> $adReturnType, params => @adParam);

    my @adWrapperParam;
    my $adWrapperParamType = Mace::Compiler::Type->new( type => "void*", isConst => 0,isRef => 0 );
    push @adWrapperParam, Mace::Compiler::Param->new( name => "__param", type => $adWrapperParamType );
    my $adWrapperBody = qq/
        $ptype* __p = ($ptype*)__param;
        $adName ( *__p  );
        delete __p;
    /;

    $$adWrapperMethod = Mace::Compiler::Method->new( name => $adWrapperName, body => $adWrapperBody, returnType=> $adReturnType, params => @adWrapperParam);
}
sub toRoutineMessageHandler {
    my $this = shift;
    my $p = shift;
    my $pname = shift;
    my $hasContexts = shift;
    my $method = shift;

    if( $hasContexts == 0 ){ return ""; }
    my $sync_upcall_func = "target_routine_" . $pname;
    my $sync_upcall_param = $p->name();
    #bsang: copy returnValue Message
    my @rparams;
    foreach( $this->fields() ){
        given( $_->name() ){
            when "returnValue"{ push @rparams, "returnValueStr"; }
            when "event"{ push @rparams, "ThreadStructure::myEvent()"; }
            when "seqno" { push @rparams, "msgseqno"; }
            default { push @rparams, "$sync_upcall_param.$_->{name}"; }
        }
    }
    my $responseMessage = $this->name . " startCtxResponse(" . join(",", @rparams) . ");";
    my $snapshotBody = "";
    #chuangw: find the corresponding routine
    my $nsnapshots = keys( %{ $method->snapshotContextObjects()} );
    my $snapshotCounter;
    my @targetParams;
    foreach( $this->fields() ){
        given( $_->name ){
            when (/^(srcContextID|snapshotContextIDs|seqno|returnValue|event)$/) {}
            default { push @targetParams,  ($sync_upcall_param . "." . $_->name ) }
        }
    }
    for($snapshotCounter=0;$snapshotCounter<$nsnapshots;$snapshotCounter++){
        $snapshotBody .= qq/
            mace::string snapshotContext${snapshotCounter} = getContextSnapshot(ThreadStructure::getCurrentContext(),  ${sync_upcall_param}.snapshotContextIDs[${snapshotCounter}]); /;
        push @targetParams,  "snapshotContext${snapshotCounter}";
    }
    my $targetParamsStr = join(", ", @targetParams);
    my $seg1;
    my $returnValueType = $method->returnType->type;
    if($returnValueType eq 'void'){
        $seg1 = qq/${sync_upcall_func}(${targetParamsStr}); /; 
    }else{
        $seg1 = qq/$returnValueType returnValue = ${sync_upcall_func} (${targetParamsStr});
                   mace::serialize(returnValueStr, &returnValue);/;
    }
    my $apiBody = qq#
    mace::AgentLock::nullTicket();
    //if( !ackUpdateRespond(source, $sync_upcall_param.srcContextID, $sync_upcall_param.seqno) ) return;

    ThreadStructure::setEventContextMappingVersion ( $sync_upcall_param.event.eventContextMappingVersion );
    if( contextMapping.getNodeByContext($sync_upcall_param.startContextID) == Util::getMaceAddr() ){
        ThreadStructure::setEvent( $sync_upcall_param.event );
        $snapshotBody
        mace::string returnValueStr;
        $seg1
        mace::serialize(returnValueStr, &(ThreadStructure::myEvent() ) );

        uint32_t msgseqno = 1; //getNextSeqno( $sync_upcall_param.srcContextID) ;
        $responseMessage
        const MaceKey srcNode( mace::ctxnode, source.getMaceAddr() );
        downcall_route( srcNode ,  startCtxResponse ,__ctx);
    }else{
        mace::ScopedContextRPC::wakeupWithValue( $sync_upcall_param.event.eventID, $sync_upcall_param.returnValue );
    }
    #;
    return $apiBody;
}
sub toTargetRoutineMessageHandler {
    my $this = shift;
    my $p = shift;
    my $pname = shift;
    my $hasContexts = shift;
    my $method = shift;

    if( $hasContexts == 0 ){ return ""; }
    my $ptype = $this->name();
    my $sync_upcall_param = $p->name();
    my $this_subs_name = (caller(0))[3];
    my $apiBody = "// Generated by ${this_subs_name}() line: " . __LINE__;
    my $returnValueType = $method->returnType->type;
    my $fnParamsStr = join(",", map{ $sync_upcall_param . "." . $_->name  } $method->params() );
    my $seg1 = "";
    if($returnValueType eq 'void'){
        $seg1 = qq/sync_${pname}(${fnParamsStr});/; 
    }else{
        $seg1 = qq/$returnValueType returnValue = sync_${pname} (${fnParamsStr});
            mace::serialize(returnValueStr, &returnValue); /;
    }
    #bsang: copy returnValue Message
    my @rparams;
    foreach( $this->fields() ){
        given ($_->name){
            when "returnValue" { push @rparams, "returnValueStr"; }
            when "seqno" { push @rparams, "msgseqno"; }
            default { push @rparams, ($sync_upcall_param . "." . $_->name ); }
        }
    }
    my $rcopyparam = qq#
        uint32_t msgseqno = 1; //getNextSeqno($sync_upcall_param.srcContextID);
        $ptype pcopy(# . join(",", @rparams) . ");
        /*mace::string buf;
        mace::serialize(buf, &pcopy);
        __internal_unAck[ $sync_upcall_param.srcContextID ][ msgseqno ] = buf;*/
    ";

    $apiBody .= qq#
        mace::AgentLock::nullTicket();
        //if( !ackUpdateRespond(source, $sync_upcall_param.srcContextID, $sync_upcall_param.seqno) ) return;

        ThreadStructure::setEventContextMappingVersion ( $sync_upcall_param.event.eventContextMappingVersion );
        if( contextMapping.getNodeByContext($sync_upcall_param.targetContextID) == Util::getMaceAddr() ){
            ThreadStructure::setEvent( $sync_upcall_param.event );

            ThreadStructure::ScopedContextID sc( $sync_upcall_param.targetContextID );
            // make sure I'm not holding agent lock
            mace::ContextBaseClass* thisContext = getContextObjByID( $sync_upcall_param.targetContextID, false );
            ThreadStructure::setMyContext( thisContext );
            mace::ContextLock __contextLock( *thisContext, mace::ContextLock::WRITE_MODE); // acquire context lock. 
            ThreadStructure::insertEventContext( ThreadStructure::getCurrentContext() );
            mace::string returnValueStr;
            $seg1
            mace::serialize(returnValueStr, &(ThreadStructure::myEvent() ) );
            $rcopyparam // event has finished at the target context. Respond to start context.
            const MaceKey srcNode( mace::ctxnode, source.getMaceAddr() ); 
            downcall_route( srcNode ,  pcopy ,__ctx);
        }else{
            mace::ScopedContextRPC::wakeupWithValue( $sync_upcall_param.event.eventID , $sync_upcall_param.returnValue );
        }
    #;
    return $apiBody;
}

sub toApplicationUpcallHandler {
    my $this = shift;
}

1;
