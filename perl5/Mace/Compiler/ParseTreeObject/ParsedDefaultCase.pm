# 
# ParsedDefaultCase.pm : part of the Mace toolkit for building distributed systems
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
package Mace::Compiler::ParseTreeObject::ParsedDefaultCase;

use strict;
use v5.10.1;
use feature 'switch';

use Class::MakeMethods::Template::Hash
    (
      'new' => 'new',
      'scalar' => 'type',
      'boolean' => 'not_null',
      'array_of_objects' => ["semi_statements" => { class => "Mace::Compiler::ParseTreeObject::SemiStatement" }],
    );

sub toString {
    my $this = shift;

    given ($this->type()) {
        when ("default")
            {
                if ($this->not_null()) {
                    return "default: ".join(";", map { $_->toString() } $this->semi_statements());
                } else {
                    return "default: ";
                }
            }
        when ("null") { return ""; }
        default { return "StatementOrBraceBlock:NOT-PARSED"; }
    }
}


sub usedVar {
    my $this = shift;
    my @array = ();

    my $type = $this->type();

    given ($type) {
        when ("default")
            { 
                if( $this->not_null() ) {
                    for my $stmt (@{$this->semi_statements()}) {
                        @array = (@array, $stmt->usedVar());
                    }
                } else {
                    @array = ();
                }
            }
        default {  @array = (); }
    }

    return @array;
}

1;
