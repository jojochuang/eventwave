# 
# MaceCompiler.pm : part of the Mace toolkit for building distributed systems
# 
# Copyright (c) 2007, Charles Killian, James W. Anderson, Adolfo Rodriguez, Dejan Kostic
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
package Mace::Compiler::MaceCompiler;

use strict;

use Mace::Compiler::Type;
use Mace::Compiler::TypeOption;
use Mace::Compiler::Param;
use Mace::Compiler::Method;
use Mace::Compiler::ServiceImpl;
use Mace::Compiler::ServiceVar;
use Mace::Compiler::AutoType;
use Mace::Compiler::RoutineObject;
use Mace::Compiler::Transition;
use Mace::Compiler::TypeDef;
use Mace::Compiler::GeneratedOn;
use Mace::Compiler::Grammar;
use Mace::Compiler::MaceRecDescent;
use Mace::Compiler::Guard;
use Mace::Compiler::Timer;
use Mace::Compiler::Detect;
use Mace::Compiler::Query;
use Mace::Compiler::Properties::SetVariable;
use Mace::Compiler::Properties::Quantification;
use Mace::Compiler::Properties::SetSetExpression;
use Mace::Compiler::Properties::ElementSetExpression;
use Mace::Compiler::Properties::Equation;
use Mace::Compiler::Properties::JoinExpression;
use Mace::Compiler::Properties::Property;
use Mace::Compiler::Properties::NonBExpression;

use Mace::Compiler::ParseTreeObject::BraceBlock;
use Mace::Compiler::ParseTreeObject::Expression;
use Mace::Compiler::ParseTreeObject::MethodTerm;
use Mace::Compiler::ParseTreeObject::ParsedAbort;
use Mace::Compiler::ParseTreeObject::ParsedAssertMsg;
use Mace::Compiler::ParseTreeObject::ParsedAssert;
use Mace::Compiler::ParseTreeObject::ParsedBinaryAssignOp;
use Mace::Compiler::ParseTreeObject::ParsedCatches;
use Mace::Compiler::ParseTreeObject::ParsedCatch;
use Mace::Compiler::ParseTreeObject::ParsedDefaultCase;
use Mace::Compiler::ParseTreeObject::ParsedDoWhile;
use Mace::Compiler::ParseTreeObject::ParsedElseIf;
use Mace::Compiler::ParseTreeObject::ParsedElseIfs;
use Mace::Compiler::ParseTreeObject::ParsedElse;
use Mace::Compiler::ParseTreeObject::ParsedExpectStatement;
use Mace::Compiler::ParseTreeObject::ParsedExpression;
use Mace::Compiler::ParseTreeObject::ParsedFCall;
use Mace::Compiler::ParseTreeObject::ParsedForLoop;
use Mace::Compiler::ParseTreeObject::ParsedForUpdate;
use Mace::Compiler::ParseTreeObject::ParsedForVar;
use Mace::Compiler::ParseTreeObject::ParsedIf;
use Mace::Compiler::ParseTreeObject::ParsedLogging;
use Mace::Compiler::ParseTreeObject::ParsedLValue;
use Mace::Compiler::ParseTreeObject::ParsedOutput;
use Mace::Compiler::ParseTreeObject::ParsedPlusPlus;
use Mace::Compiler::ParseTreeObject::ParsedReturn;
use Mace::Compiler::ParseTreeObject::ParsedSwitchCase;
use Mace::Compiler::ParseTreeObject::ParsedSwitchCases;
use Mace::Compiler::ParseTreeObject::ParsedSwitchConstant;
use Mace::Compiler::ParseTreeObject::ParsedSwitch;
use Mace::Compiler::ParseTreeObject::ParsedMacro;
use Mace::Compiler::ParseTreeObject::ParsedTryCatch;
use Mace::Compiler::ParseTreeObject::ParsedVar;
use Mace::Compiler::ParseTreeObject::ParsedWhile;
use Mace::Compiler::ParseTreeObject::PropertyItem;
use Mace::Compiler::ParseTreeObject::StatementBlock;
use Mace::Compiler::ParseTreeObject::StatementOrBraceBlock;
use Mace::Compiler::ParseTreeObject::SemiStatement;
use Mace::Compiler::ParseTreeObject::ScopedId;

use Mace::Util qw(:all);

use Parse::RecDescent;

$::RD_ERRORS = 1; # Make sure the parser dies when it encounters an error
$::RD_WARN   = 1; # Enable warnings. This will warn on unused rules &c.
$::RD_HINT   = 1; # Give out hints to help fix problems.
# $::RD_TRACE  = 1;


use Class::MakeMethods::Template::Hash
    (
    'new --and_then_init' => 'new',
    'object' => ['parser' => { class => "Parse::RecDescent" }],
    'hash --get_set_items' => 'using',
#     'object' => ['class' => { class => "Mace::Compiler::ServiceImpl" }],
    );

sub init {
    my $this = shift;
    my $p = Mace::Compiler::MaceRecDescent->new();
    $this->parser($p);
} # init

sub parse {
    my $this = shift;
    my $in = shift;
    my $file = shift;

    $this->processUsing($in);

    my @linemap;
    my @filemap;
    my @offsetmap;

    Mace::Compiler::MInclude::getLines($file, $in, \@linemap, \@filemap, \@offsetmap);

    $this->parser()->{local}{linemap} = \@linemap;
    $this->parser()->{local}{filemap} = \@filemap;
    $this->parser()->{local}{offsetmap} = \@offsetmap;

    my $t = join("", @$in);

    $Mace::Compiler::Grammar::text = $t;
    # open(OUT, ">", "/tmp/foo");
    # print OUT $t;
    # close(OUT);
    my $svName = $file;
    $svName =~ s|^.*/||;
    $svName =~ s|[.].*||;
    $this->parser()->{local}{servicename} = $svName;
    my $sc = $this->parser()->PrintError($t, 1, $file) || die "syntax error\n";
    my @defers = ();
    $Mace::Compiler::Grammar::text = $t;
    $sc->parser($this->parser());
    $sc->origMacFile($t);
    push(@defers, $this->findDefers($t));
    $sc->validate(@defers);
    #$this->class($sc);
    return $sc;
} # parse

sub processUsing {
  my $this = shift;
  my $t = shift;

  my $line = 1;
  for (@$t) {
    if ($_ =~ m|^\s*using\s+namespace|) {
        Mace::Compiler::Globals::error("bad_using", " ", $line, "'using namespace' declarations are not supported");
    }
    
    if ($_ =~ m|^\s*using\s+(.*)::(\w+);\s*|) {
	$this->using($2,$1);
    }
    $line++;
  }

  #my @l = split(/\n/, $$t);
  for my $l (@$t) {
      my %using = %{$this->using()};
      while (my ($k, $v) = each(%using)) {
	  if ($l =~ m|^\s*#|) {
	      next;
	  }
	  $l =~ s|^(\s*using\s+${v}::${k};)|/* $1 */|m;
	  $l =~ s|([^:])\b($k)\b|${1}${v}::${k}|g;
      }
  }
  #$$t = join("\n", @l) . "\n";
}

sub findDefers {
    my $this = shift;
    my $t = shift;

    my @r = ();

    open(IN, "<", \$t) or die;
    while(<IN>) {
        if ($_ =~ m|\sdefer_(.*?)\(|) {
            push(@r, $1);
        }
    }
    close(IN);
    return @r;
}

1;
