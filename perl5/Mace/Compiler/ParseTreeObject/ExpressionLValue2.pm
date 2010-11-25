# 
# ExpressionLValue2.pm : part of the Mace toolkit for building distributed systems
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
package Mace::Compiler::ParseTreeObject::ExpressionLValue2;

use strict;
use Switch;

use Class::MakeMethods::Template::Hash
    (
     'new' => 'new',
     'scalar' => 'type',
     'object' => ["scoped_id" => { class => "Mace::Compiler::ParseTreeObject::ScopedId" }],
      'array_of_objects' => ["array_index" => { class => "Mace::Compiler::ParseTreeObject::ArrayIndex" }],
      'array_of_objects' => ["expr1" => { class => "Mace::Compiler::ParseTreeObject::Expression1" }],
     'boolean' => 'not_null_expr1',
     #'object' => ["expr_or_assign_lvalue1" => { class => "Mace::Compiler::ParseTreeObject::ExpressionOrAssignLValue1" }],
      'array_of_objects' => ["expr_or_assign_lvalue1" => { class => "Mace::Compiler::ParseTreeObject::ExpressionOrAssignLValue1" }],
    );

sub toString {
    my $this = shift;

    switch ($this->type()) {
        case "array" { return $this->scoped_id()->toString() . join("", map { $_->toString() } $this->array_index()); }
        case "fcall" 
            { 
                if( $this->not_null_expr1() ) {
                    return $this->scoped_id()->toString() . "(" .  join(",", map { $_->toString() } $this->expr1()) . ")";
                } else {
                    return $this->scoped_id()->toString() . "()";
                }
            }
        case "fcall_assign" { return $this->scoped_id()->toString() . "(" .  join(",", map { $_->toString() } $this->expr_or_assign_lvalue1()) . ")"; }
        case "scoped_id" { return $this->scoped_id()->toString(); }
        else { return "ExpressionLValue2:NOT-PARSED"; }
    }
}

sub getRef {
    my $this = shift;

    switch ($this->type()) {
        case "fcall" { return "FUNCTION_CALL"; }
        case "fcall_assign" { return "FUNCTION_CALL"; }
        else { return ""; }
    }
}

1;
