# 
# SemiStatement.pm : part of the Mace toolkit for building distributed systems
# 
# Copyright (c) 2010, Sunghwan Yoo, Charles Killian
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
package Mace::Compiler::ParseTreeObject::SemiStatement;

use strict;
use Switch;
#use base qw{Mace::Compiler::ParseTreeObject::PropertyItem};

use Class::MakeMethods::Template::Hash
    (
      'new' => 'new',
      'scalar' => 'type',
      'array' => 'stmts',

      'scalar' => 'enum',
      'object' => ["parsed_return" => { class => "Mace::Compiler::ParseTreeObject::ParsedReturn"}],
      'object' => ["parsed_if" => { class => "Mace::Compiler::ParseTreeObject::ParsedIf"}],
      'object' => ["parsed_for_loop" => { class => "Mace::Compiler::ParseTreeObject::ParsedForLoop"}],
      'object' => ["parsed_do_while" => { class => "Mace::Compiler::ParseTreeObject::ParsedDoWhile"}],
      'object' => ["parsed_while" => { class => "Mace::Compiler::ParseTreeObject::ParsedWhile"}],
      'object' => ["parsed_logging" => { class => "Mace::Compiler::ParseTreeObject::ParsedLogging"}],
      'object' => ["parsed_switch" => { class => "Mace::Compiler::ParseTreeObject::ParsedSwitch"}],
      'object' => ["parsed_try_catch" => { class => "Mace::Compiler::ParseTreeObject::ParsedTryCatch"}],
      'object' => ["parsed_macro" => { class => "Mace::Compiler::ParseTreeObject::ParsedMacro"}],
      'object' => ["parsed_expect_stmt" => { class => "Mace::Compiler::ParseTreeObject::ParsedExpectStatement"}],
      'object' => ["parsed_assert_msg" => { class => "Mace::Compiler::ParseTreeObject::ParsedAssertMsg"}],
      'object' => ["parsed_assert" => { class => "Mace::Compiler::ParseTreeObject::ParsedAssert"}],
      'object' => ["parsed_abort" => { class => "Mace::Compiler::ParseTreeObject::ParsedAbort"}],
      'object' => ["parsed_var" => { class => "Mace::Compiler::ParseTreeObject::ParsedVar"}],
      'object' => ["parsed_fcall" => { class => "Mace::Compiler::ParseTreeObject::ParsedFCall"}],
      'object' => ["parsed_binary_assign_op" => { class => "Mace::Compiler::ParseTreeObject::ParsedBinaryAssignOp"}],
      'object' => ["parsed_plus_plus" => { class => "Mace::Compiler::ParseTreeObject::ParsedPlusPlus"}],
      'scalar' => 'parsed_control_flow',
      'object' => ["parsed_output" => { class => "Mace::Compiler::ParseTreeObject::ParsedOutput"}],
    );

sub toString {
    my $this = shift;

    my $type = $this->type();

    #print "SemiStatement.Type = ".$type."\n";

    switch ($type) {
        case "enum" { return $this->enum(); }
        case "parsed_return" { return $this->parsed_return()->toString(); }
        case "parsed_if" { return $this->parsed_if()->toString(); }
        case "parsed_for_loop" { return $this->parsed_for_loop()->toString(); }
        case "parsed_do_while" { return $this->parsed_do_while()->toString(); }
        case "parsed_while" { return $this->parsed_while()->toString(); }
        case "parsed_logging" { return $this->parsed_logging()->toString(); }
        case "parsed_switch" { return $this->parsed_switch()->toString(); }
        case "parsed_try_catch" { return $this->parsed_try_catch()->toString(); }
        case "parsed_macro" { return $this->parsed_macro()->toString(); }
        case "parsed_expect_stmt" { return $this->parsed_expect_stmt()->toString(); }
        case "parsed_assert_msg" { return $this->parsed_assert_msg()->toString(); }
        case "parsed_assert" { return $this->parsed_assert()->toString(); }
        case "parsed_abort" { return $this->parsed_abort()->toString(); }
        case "parsed_var" { return $this->parsed_var()->toString(); }
        case "parsed_fcall" { return $this->parsed_fcall()->toString().";"; }
        case "parsed_binary_assign_op" { return $this->parsed_binary_assign_op()->toString().";"; }
        case "parsed_plus_plus" { return $this->parsed_plus_plus()->toString().";"; }
        case "parsed_control_flow" { return $this->parsed_control_flow().";"; }
        case "parsed_output" { return $this->parsed_output()->toString(); }
        else { return "SemiStatement:NOT-PARSED"; }
    }

#    return "SemiStatement:NOT-PARSED";

#    return $this->stmt();

#    return "SEMI-STATEMENT";
#    if( $this->type() == 0 ) {
#        return $this->parsed_return()->toString();
#    } else {
#        return "null";
#    }
}

1;
