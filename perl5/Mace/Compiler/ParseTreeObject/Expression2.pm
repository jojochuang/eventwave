# 
# Expression2.pm : part of the Mace toolkit for building distributed systems
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
package Mace::Compiler::ParseTreeObject::Expression2;

use strict;
use Switch;

use Class::MakeMethods::Template::Hash
    (
     'new' => 'new',
     'scalar' => 'type',
     'scalar' => 'number',
     'scalar' => 'string',
     'scalar' => 'quoted_string',
     'object' => ["typecast" => { class => "Mace::Compiler::Type" }],
#     'scalar' => 'typecast',
     'object' => ["scoped_id" => { class => "Mace::Compiler::ParseTreeObject::ScopedId" }],
     'object' => ["array_ind_or_function_parts" => { class => "Mace::Compiler::ParseTreeObject::ArrayIndOrFunctionParts" }],
     'object' => ["expr1" => { class => "Mace::Compiler::ParseTreeObject::Expression1" }],
    );

sub toString {
    my $this = shift;

    switch ($this->type()) {
        case "number" { return $this->number(); }
        case "array_func" { return $this->scoped_id()->toString().$this->array_ind_or_function_parts()->toString(); }
        case "string" { return "'".$this->string()."'"; }
        case "quoted_string" { return $this->quoted_string(); }
        case "typecast" { return "(".$this->typecast()->type().")" . $this->expr1()->toString(); }
        case "expr1" { return "(".$this->expr1()->toString().")"; }
        case "scoped_id" { return $this->scoped_id()->toString(); }
        else { return "Expression2:NOT-PARSED"; }
    }
}


1;
