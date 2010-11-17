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
      'object' => ["parsed_var" => { class => "Mace::Compiler::ParseTreeObject::ParsedVar"}],

    );

sub toString {
    my $this = shift;

    my $type = $this->type();

    #print "SemiStatement.Type = ".$type."\n";

    switch ($type) {
        case "enum" { return $this->enum(); }
        case "parsed_return" { return $this->parsed_return()->toString(); }
        case "parsed_if" { return $this->parsed_if()->toString(); }
        case "parsed_var" { return $this->parsed_var()->toString(); }
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
