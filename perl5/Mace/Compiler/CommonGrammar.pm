# 
# CommonGrammar.pm : part of the Mace toolkit for building distributed systems
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
package Mace::Compiler::CommonGrammar;

use strict;
use Mace::Compiler::Grammar;

use constant COMMON => q{

Word : /\S*/
LookaheadWord : ...!<matchrule: $arg{rule}>[%arg] Word
LookaheadString : LookaheadWord[%arg](s?)
CopyLookaheadString : StartPos LookaheadString[%arg] EndPos
{
  $return = substr($Mace::Compiler::Grammar::text, $item{StartPos},
      1 + $item{EndPos} - $item{StartPos});
}
ToEnd : Word(s?)

StartPos : // { $thisoffset }
| <error>

EndPos : { $prevoffset }
Line : '' { $thisline }
Column : { $thiscolumn }
FileLine : '' { 
    my $line = 0;
    while (defined $thisparser->{local}{offsetmap}->[$line] and $thisparser->{local}{offsetmap}->[$line] <= $thisoffset) {
        $line++;
    }
    $line--;
    if ($line <= 0) {
        confess("Line $line < 0 : thisline $thisline thisoffset $thisoffset");
    }
    # if (not defined $thisparser->{local}{linemap}->[$thisline]) {
    #     print "WARNING: offsetline $line thisline $thisline\n";
    # }
    #if (not defined $thisparser->{local}{linemap}->[$line]) {
    #    # $return = [ 0, "error", $thisline ];
    #    open(OUT, ">", "/tmp/foo");
    #    print OUT "Thisline: $thisline prevline $prevline\n";
    #    my $i = 0;
    #    for my $l (@{$thisparser->{local}{linemap}}) {
    #        print OUT "$i - $l - ".$thisparser->{local}{filemap}->[$i]."\n";
    #        $i++;
    #    }
    #    print OUT "File::\n";
    #    print OUT $Mace::Compiler::Grammar::text;
    #    print OUT "Remaining::\n$text\n";
    #    close(OUT);
    #    confess("Invalid line $thisline");
    #} else {
        $return = [ $thisparser->{local}{linemap}->[$line], $thisparser->{local}{filemap}->[$line], $line ]; 
    #}
    }
FileLineEnd : { 
    my $line = 0;
    while (defined $thisparser->{local}{offsetmap}->[$line] and $thisparser->{local}{offsetmap}->[$line] < $prevoffset) {
        $line++;
    }
    $line--;
    # if (not defined $thisparser->{local}{linemap}->[$prevline]) {
    #     print "WARNING: offsetline $line prevline $prevline\n";
    # }
    # if (not defined $thisparser->{local}{linemap}->[$line]) {
    #     # $return = [ 0, "error", $prevline ];
    #     open(OUT, ">", "/tmp/foo");
    #     print OUT "prevline: $prevline\n";
    #     my $i = 0;
    #     for my $l (@{$thisparser->{local}{linemap}}) {
    #         print OUT "$i - $l - ".$thisparser->{local}{filemap}->[$i]."\n";
    #         $i++;
    #     }
    #     print OUT "File::\n";
    #     print OUT $Mace::Compiler::Grammar::text;
    #     print OUT "Remaining::\n$text\n";
    #     close(OUT);
    #     confess("Invalid line $prevline");
    # } else {
        $return = [ $thisparser->{local}{linemap}->[$line], $thisparser->{local}{filemap}->[$line], $line ]; 
    # }
    }

Id : /[_a-zA-Z][a-zA-Z0-9_]*/

SemiStatementToken : m|[^;{}][^;{}/]*|

SemiStatementBegin : SemiStatementToken(s)

BraceBlockFoo : '{' SemiStatementFoo(s?) '}' { $return = $item[2]; }

BraceBlock : '{' SemiStatement(s?) '}' 
{ 
    my $node = Mace::Compiler::ParseTreeObject::BraceBlock->new();
    $node->not_null(scalar(@{$item[2]}));

    if (scalar(@{$item[2]})) {
        print "BraceBlock {{ \n";

        for my $statement (@{$item[2]}) {
            if( ref($statement) ne "" ) {
                print "  SEMI-STATEMENTS[o]: ".$statement->toString()."\n";
            } else {
                print "  SEMI-STATEMENTS[s]: $statement\n";
            }
        }
        # 결과가 "Hash"로 나온다는 의미는, 올바르게 Parse 되었음을 의미한다.

        #$node->semi_statements_foo(@{$item[2]});
        $node->semi_statements(@{$item[2]});

        print "BraceBlock }} \n";

    } else {
        print "BraceBlock { }\n";
    }
    $return = $node;
    #$return = $item[2];    # original
}


Enum : /enum\s/ Id '{' SemiStatementBegin '}'

ParsedExpression : Expression
    {
        my $node = Mace::Compiler::ParseTreeObject::ParsedExpression->new(expr=>$item{Expression});
        if( ref($item{Expression}) ne "" ) {
            print "ParsedExpression[o]: ".$item{Expression}->toString()."\n";
        } else {
            print "ParsedExpression[s]: $item{Expression}\n";
        }
        $return = $node;
    }

#ParsedReturn : /return\b/ ';' {$return = "VOID RETURN";}
#| /return\b/ ParsedExpression ';' {$return = "NON-VOID RETURN ( ".$item{ParsedExpression}." )";}

# FIXME : ParsedExpression 오브젝트화
ParsedReturn : /return\b/ ';' 
    {
        my $node = Mace::Compiler::ParseTreeObject::ParsedReturn->new(type=>0);
        $return = $node;
    }
| /return\b/ ParsedExpression ';' 
    {
        my $node = Mace::Compiler::ParseTreeObject::ParsedReturn->new(type=>1, parsed_expr=>$item{ParsedExpression});
        $return = $node;
    }

# FIXME : Parameter String화 된 것을 수정.
# ->toString()을 해도 Expression까지 받아오는 경우가 있으므로, 한 번 더 toString을 할 필요가 있다.
# 여기에 대해서는, Parameter에 대해 추가적인 파싱을 추가함으로서 처리하도록 하자.
ParsedVar : StaticToken(?) Parameter[%arg, initializerOk => 1] 
{ 
  if (scalar(@{$item[1]})) {
    my $node = Mace::Compiler::ParseTreeObject::ParsedVar->new(is_static=>1, parameter=>$item{Parameter}->toString(noline => 1));
    print "ParsedVar[st]: ".$item{Parameter}->toString(noline => 1)."\n";
    $return = $node;
  } else {
    my $node = Mace::Compiler::ParseTreeObject::ParsedVar->new(is_static=>0, parameter=>$item{Parameter}->toString(noline => 1));
    print "ParsedVar[xst]: ".$item{Parameter}->toString(noline => 1)."\n";
    $return = $node;
  }
}
#{ $return = "VARIABLE DECL: ".$item{Parameter}->toString(noline => 1); 
#  if (scalar(@{$item[1]})) {
#    $return .= " (STATIC)";
#  }
#}
| <error>

ParsedElse: /else\b/ <commit> StatementOrBraceBlock
    {
        my $node = Mace::Compiler::ParseTreeObject::ParsedElse->new(null=>0, stmt_or_block=>$item{StatementOrBraceBlock});
        print "ParsedElse: ".$node->toString()."\n";
        $return = $node;
    }
#    { $return = "ELSE { ".$item{StatementOrBraceBlock}." }"; }
| <error?> <reject>
|   {
      my $node = Mace::Compiler::ParseTreeObject::ParsedElse->new(null=>1);
      print "ParsedElseIfs: {}\n";
      $return = $node;
    }
#| { $return = ""; }

ElseAndIf: /else\b/ /if\b/

ParsedElseIfs: ...ElseAndIf <commit> ParsedElseIf ParsedElseIfs
    { 
      my $node = Mace::Compiler::ParseTreeObject::ParsedElseIfs->new(null=>0, parsed_else_if=>$item{ParsedElseIf}, parsed_else_ifs=>$item{ParsedElseIfs});
      print "ParsedElseIfs: ".$node->toString()."\n";
      $return = $node;
    }
#    { $return = $item{ParsedElseIf};
#      if ($item{ParsedElseIfs} ne "") {
#        $return .= " ".$item{ParsedElseIfs}; 
#      }
#    }
| <error?> <reject>
|   {
      my $node = Mace::Compiler::ParseTreeObject::ParsedElseIfs->new(null=>1);
      print "ParsedElseIfs: {}\n";
      $return = $node;
    }
#| { $return = ""; }

ParsedElseIf: ElseAndIf <commit> '(' ParsedExpression ')' StatementOrBraceBlock
    {
        my $node = Mace::Compiler::ParseTreeObject::ParsedElseIf->new(type=>"parsed_expression", parsed_expr=>$item{ParsedExpression}, stmt_or_block=>$item{StatementOrBraceBlock});
        print "ParsedElseIf[1]: ".$node->toString()."\n";
        $return = $node;
    }
#    { $return = "ELSE IF ( ".$item{ParsedExpression}." ) THEN { ".$item{StatementOrBraceBlock}." }"; }
| ElseAndIf <commit> '(' ExpressionOrAssignLValue ')' StatementOrBraceBlock
    {
        my $node = Mace::Compiler::ParseTreeObject::ParsedElseIf->new(type=>"expression_or_assign_lvalue", expr_or_assign=>$item{ExpressionOrAssignLValue}, stmt_or_block=>$item{StatementOrBraceBlock});
        print "ParsedElseIf[2]: ".$node->toString()."\n";
        $return = $node;
    }
#    { $return = "ELSE IF[LVAL] ( ".$item{ExpressionOrAssignLValue}." ) THEN { ".$item{StatementOrBraceBlock}." }"; }
| <error>

ParsedIf : /if\b/ '(' ParsedExpression ')' StatementOrBraceBlock ParsedElseIfs ParsedElse
    {
      my $node = Mace::Compiler::ParseTreeObject::ParsedIf->new(type=>"parsed_expression", parsed_expr=>$item{ParsedExpression}, stmt_or_block=>$item{StatementOrBraceBlock}, parsed_else_ifs=>$item{ParsedElseIfs}, parsed_else=>$item{ParsedElse});
      print "ParsedIf[1]: ".$node->toString()."\n";
      print "  ParsedExpression: ".$item{ParsedExpression}->toString()."\n";
      print "  StatementOrBraceBlock: ".$item{StatementOrBraceBlock}->toString()."\n";
      $return = $node;
    }
| /if\b/ '(' ExpressionOrAssignLValue ')' StatementOrBraceBlock ParsedElseIfs ParsedElse
    {
      my $node = Mace::Compiler::ParseTreeObject::ParsedIf->new(type=>"expression_or_assign_lvalue", expr_or_assign=>$item{ExpressionOrAssignLValue}, stmt_or_block=>$item{StatementOrBraceBlock}, parsed_else_ifs=>$item{ParsedElseIfs}, parsed_else=>$item{ParsedElse});
      print "ParsedIf[2]: ".$node->toString()."\n";
      $return = $node;
    }
#    { $return = "IF ( ".$item{ParsedExpression}." ) THEN { ".$item{StatementOrBraceBlock}." }"; 
#      if ($item{ParsedElseIfs} ne "") {
#        $return .= " ".$item{ParsedElseIfs};
#      } 
#      if ($item{ParsedElse} ne "") {
#        $return .= " ".$item{ParsedElse};
#      }
#    }
#| /if\b/ '(' ExpressionOrAssignLValue ')' StatementOrBraceBlock ParsedElseIfs ParsedElse
#    { $return = "IF[LVAL] ( ".$item{ExpressionOrAssignLValue}." ) THEN { ".$item{StatementOrBraceBlock}." }"; 
#      if ($item{ParsedElseIfs} ne "") {
#        $return .= " ".$item{ParsedElseIfs};
#      } 
#      if ($item{ParsedElse} ne "") {
#        $return .= " ".$item{ParsedElse};
#      }
#    }
| <error>

ParsedDoWhile : /do\b/ <commit> StatementOrBraceBlock /while\b/ '(' ParsedExpression ')' (';')(?)
{ $return = "DO-WHILE: EXEC { ".$item{StatementOrBraceBlock}." } COND: ".$item{ParsedExpression}; }

ParsedWhile : /while\b/ <commit> '(' ParsedExpression ')' StatementOrBraceBlock
{ $return = "WHILE: EXEC { ".$item{StatementOrBraceBlock}." } COND: ".$item{ParsedExpression}; }

ParsedAbort : 'ABORT' '(' QuotedString ')' ';'
{ $return = "ABORT: ".$item{QuotedString}; }
| <error>

ParsedAssertMsg : 'ASSERTMSG' '(' Expression ',' QuotedString ')' ';'
{ $return = "ASSERTION WITH ERRMSG: cond: ".$item{Expression}. " errmsg: ".$item{QuotedString}; }
| <error>

ParsedAssert : 'ASSERT' '(' Expression ')' ';'
{ $return = "ASSERTION: ".$item{Expression}; }
| <error>

ParsedFCall : ExpressionLValue[parseFunctionCall => 1]
{ $return = "FUNCTION CALL: ".$item{ExpressionLValue}; }
| <error>

ParsedLValue : ParsedPlusPlus | ParsedBinaryAssignOp | ExpressionLValue
| <error>

#| ScopedId '[' Expression ']' { $return = $item{ScopedId} . '[' . $item{Expression} . ']'; }

ParsedBinaryAssignOp : ExpressionLValue AssignBinaryOp Expression CheckSemi[%arg]
{ $return = "BINARY ASSIGNMENT OP: LVALUE= ".$item{ExpressionLValue}." OP: ".$item{AssignBinaryOp}." RVALUE= ".$item{Expression}; }
| ExpressionLValue AssignBinaryOp <commit> ParsedLValue CheckSemi[%arg]
{ $return = "BINARY ASSIGNMENT OP RHS-LV: LVALUE= ".$item{ExpressionLValue}." OP: ".$item{AssignBinaryOp}." RVALUE= ".$item{ParsedLValue}; }
| <uncommit> <defer: print "ParsedBinaryAssignOp failed.";> <error?> <error>

ParsedPlusPlus : ExpressionLValue '++' 
{ $return = "POSTINCREMENT: LVALUE= ".$item{ExpressionLValue}; }
| '++' ExpressionLValue
{ $return = "PREINCREMENT: LVALUE= ".$item{ExpressionLValue}; }
| ExpressionLValue '--' 
{ $return = "POSTDECREMENT: LVALUE= ".$item{ExpressionLValue}; }
| '--' ExpressionLValue
{ $return = "PREDECREMENT: LVALUE= ".$item{ExpressionLValue}; }



ParsedForVar : ParsedVar | ParsedBinaryAssignOp | {$return = ""; }

ParsedForUpdate : ParsedPlusPlus | ParsedBinaryAssignOp | {$return = ""; }

ParsedForLoop : /for\b/ '(' ParsedForVar ';' Expression ';' ParsedForUpdate ')' StatementOrBraceBlock
{
    $return = "FOR: VAR( ". $item{ParsedForVar} ." ) TEST( ".$item{Expression}." ) UPDATE( ".$item{ParsedForUpdate}." ) EXEC { ".$item{StatementOrBraceBlock}." }";
}

OutputStream : 'maceout' | 'maceerr' | 'macewarn' | 'macedbg' '(' Number ')' {$return = "macedbg(".$item{Number}.")";} | 'cout' | 'cerr' | 'std::cout' | 'std::cerr' | <error>
OutputOperator : '<<' | <error>

ParsedLogging : OutputStream <commit> OutputOperator Expression ';'
{ $return = "LOGGING: Stream: ".$item{OutputStream}." Value: ".$item{Expression}; }

ParsedOutput : ExpressionLValue OutputOperator <commit> Expression ';'
{ $return = "OUTPUT: Stream: ".$item{ExpressionLValue}." Value: ".$item{Expression}; }

ParsedDefaultCase : 'default' <commit> ':' SemiStatement(s?)
{ $return = "DEFAULT EXEC {".join(" :: ", @{$item[-1]})."}"; }
| <error?> <reject>
| { $return = ""; }

ParsedSwitchConstant : Number | Character | ScopedId

ParsedSwitchCase : 'case' ParsedSwitchConstant ':' SemiStatement(s?)
{ $return = "CASE ( ".$item{ParsedSwitchConstant}." ) EXEC {".join(" :: ", @{$item[-1]})."}"; }

ParsedSwitchCases : ...'case' <commit> ParsedSwitchCase ParsedSwitchCases
{ $return = $item{ParsedSwitchCase}.($item{ParsedSwitchCases} ne "" ? " ".$item{ParsedSwitchCases} : ""); }
| <error?><reject>
| { $return = ""; }

ParsedSwitch : 'switch' '(' Expression ')' '{' ParsedSwitchCases ParsedDefaultCase '}' (';')(?)
{ $return = "SWITCH EXPRESSION( ".$item{Expression}." ) ".$item{ParsedSwitchCases}." ".$item{ParsedDefaultCase}; }

ParsedMacro : '#' <commit> /[^\n]+/
{ $return = "PREPROCESSOR MACRO: ".$item[1].$item[3]; }
| <error?> <error>

ParsedControlFlow : 'break' | 'continue'

ParsedExpectStatement : 'EXPECT' '(' Expression ')' '{' StatementBlock '}'
{ $return = "EXPECT BLOCK COND: ".$item{Expression}." EXEC: { ".$item{StatementBlock}."}"; }
| 'EXPECT' '(' Expression ')' SemiStatement <error: You need a semi-colon after an EXPECT condition, or an opening brace to start a success block.>
| 'EXPECT' <commit> '(' Expression ')' ';'
{ $return = "EXPECT COND: ".$item{Expression}; }
| <error>

ParsedCatch : 'catch' '(' ParsedVar <commit> ')' '{' StatementBlock '}' 
{ $return = "CATCH TYPE: ".$item{ParsedVar}." EXEC { ".$item{StatementBlock}." }"; }
| 'catch' <commit> '(' '...' ')' '{' StatementBlock '}'
{ $return = "CATCH ARBITRARY EXEC { ".$item{StatementBlock}." }"; }
| <error?> <error>

ParsedCatches : .../catch\b/ <commit> ParsedCatch ParsedCatches
{ $return = $item{ParsedCatch} . ( $item{ParsedCatches} ne "" ? " ".$item{ParsedCatches} : ""); }
| <error?> <reject>
| { $return = "" }

ParsedTryCatch : 'try' <commit> '{' StatementBlock '}' .../catch\b/ ParsedCatches
{ $return = "TRY/CATCH : EXEC { ".$item{StatementBlock}." } ".$item{ParsedCatches}; }
| <error>

StatementOrBraceBlock : '{' <commit> StatementBlock '}'
    {
        my $node = Mace::Compiler::ParseTreeObject::StatementOrBraceBlock->new(type=>"statement_block", stmt_block=>$item{StatementBlock});
        if( ref($item{StatementBlock}) ne "" ) {
            print "StatementOrBraceBlock[o]: ".$item{StatementBlock}->toString()."\n";
        } else {
            print "StatementOrBraceBlock[s]: $item{StatementBlock}\n";
        }
        $return = $node;
    }
| SemiStatement
    {
        my $node = Mace::Compiler::ParseTreeObject::StatementOrBraceBlock->new(type=>"semi_statement", semi_stmt=>$item{SemiStatement});
        if( ref($item{Expression}) ne "" ) {
            print "StatementOrBraceBlock[o]: ".$item{SemiStatement}->toString()."\n";
        } else {
            print "StatementOrBraceBlock[s]: $item{SemiStatement}\n";
        }
        $return = $node;
    }
#{ $return = $item{StatementBlock}; }
#| SemiStatement
| <error?> <error>

StatementBlock : SemiStatement(s?) .../\}/
    {
        my $node = Mace::Compiler::ParseTreeObject::StatementBlock->new();
        $node->not_null(scalar(@{$item[1]}));

        if (scalar(@{$item[1]})) {
            print "  StatementBlock {{ \n";

            for my $statement (@{$item[1]}) {
                if( ref($statement) ne "" ) {
                    print "    SEMI-STATEMENTS[o]: ".$statement->toString()."\n";
                } else {
                    print "    SEMI-STATEMENTS[s]: $statement\n";
                }
            }

            $node->semi_statements(@{$item[1]});

            print "  StatementBlock }} \n";

        } else {
            print "  StatementBlock { }\n";
        }

        $return = $node;
    }
#{ $return = join(" :: ", @{$item[1]}); }

SemiStatement : Enum ';' 
    {
        my $node = Mace::Compiler::ParseTreeObject::SemiStatement->new(type=>"enum", enum=>$item{Enum});
        print "SemiStatement[Enum]: ".$node->toString()."\n";
        $return = $node;
    }
| .../return\b/ <commit> ParsedReturn 
    {
        my $node = Mace::Compiler::ParseTreeObject::SemiStatement->new(type=>"parsed_return", parsed_return=>$item{ParsedReturn});
        print "SemiStatement[ParsedReturn]: ".$node->toString()."\n";
        $return = $node;
    }
| .../if\b/ <commit> ParsedIf
    {
        my $node = Mace::Compiler::ParseTreeObject::SemiStatement->new(type=>"parsed_if", parsed_if=>$item{ParsedIf});
        print "SemiStatement[ParsedIf]: ".$node->toString()."\n";
        $return = $node;
    }
| .../for\b/ <commit> ParsedForLoop
| .../do\b/ <commit> ParsedDoWhile
| .../while\b/ <commit> ParsedWhile
| ...OutputStream <commit> ParsedLogging
| .../switch\b/ <commit> ParsedSwitch
| .../try\b/ <commit> ParsedTryCatch
| .../#/ <commit> ParsedMacro
| .../EXPECT\b/ <commit> ParsedExpectStatement
| .../ASSERTMSG\b/ <commit> ParsedAssertMsg
| .../ASSERT\b/ <commit> ParsedAssert
| .../ABORT\b/ <commit> ParsedAbort
| /assert\b/ <commit> <error?: Please use ASSERT rather than assert>
| /abort\b/ <commit> <error?: Please use ABORT rather than abort>
| /drand48\b/ <commit> <error?: Please use RandomUtil rather than drand48>
| /random\b/ <commit> <error?: Please use RandomUtil rather than random>
| <error?> <reject>
| ParsedVar[semi=>1, arrayok=>1]
    {
        my $node = Mace::Compiler::ParseTreeObject::SemiStatement->new(type=>"parsed_var", parsed_var=>$item{ParsedVar});
        print "SemiStatement[ParsedVar]: ".$node->toString()."\n";
        $return = $node;
    }
| ParsedFCall ';' { $return = $item[1]; }
| ParsedBinaryAssignOp[semi=>1] { $return = $item[1]; }
| ParsedPlusPlus ';' { $return = $item[1]; }
| ParsedControlFlow ';' { $return = $item[1]; }
| ParsedOutput
| StartPos SemiStatementBegin BraceBlock(?) (';')(?) EndPos { print "ERR (line $thisline): GENERIC SEMI-STATEMENT: ".substr($Mace::Compiler::Grammar::text, $item{StartPos}, 1+$item{EndPos}-$item{StartPos})."\n"; } <error: Generic Semi-Statement on $thisline>
| <defer: Mace::Compiler::Globals::warning('unusual', $thisparser->{local}{filemap}->[$thisline], $thisparser->{local}{linemap}->[$thisline], "Bare Brace Block Found")> BraceBlock (';')(?) { $return = "UNUSUAL BARE BRACEBLOCK"; }
| <error>

SemiStatementFoo : Enum ';' 
| SemiStatementBegin BraceBlockFoo(?) (';')(?) 
| <defer: Mace::Compiler::Globals::warning('unusual', $thisparser->{local}{filemap}->[$thisline], $thisparser->{local}{linemap}->[$thisline], "Bare Brace Block Found")> BraceBlockFoo (';')(?) 
| <error>

MethodDecl : VirtualMethod | Method

VirtualMethod : 'virtual' Method
{
    $item{Method}->isVirtual(1);
    $return = $item{Method};
}

MethodTermFoo : StartPos FileLineEnd BraceBlockFoo EndPos
{
    my $startline = "";
    my $endline = "";
    #if(defined($Mace::Compiler::Globals::filename) and $Mace::Compiler::Globals::filename ne '') {
      $startline = "\n#line ".$item{FileLineEnd}->[0]." \"".$item{FileLineEnd}->[1]."\"\n";
      $endline = "\n// __INSERT_LINE_HERE__\n";
    #}

    for my $statement (@{$item{BraceBlockFoo}}) {
        print "PARSED STATEMENT: $statement\n";
    }

    $return = $startline.substr($Mace::Compiler::Grammar::text, $item{StartPos},
		     1 + $item{EndPos} - $item{StartPos}).$endline;
}

MethodTerm : StartPos FileLineEnd BraceBlock EndPos
{
    my $startline = "";
    my $endline = "";
    #if(defined($Mace::Compiler::Globals::filename) and $Mace::Compiler::Globals::filename ne '') {
      $startline = "\n#line ".$item{FileLineEnd}->[0]." \"".$item{FileLineEnd}->[1]."\"\n";
      $endline = "\n// __INSERT_LINE_HERE__\n";
    #}

#    for my $statement (@{$item{BraceBlock}}) {
#        print "PARSED STATEMENT: $statement\n";
#    }

    print "MethodTerm {{\n";
    #print $item{BraceBlock}->toStringFoo();
    print $item{BraceBlock}->toString()."\n";
    print "MethodTerm }}\n";

    # 즉 현재 $return 들은 디버그 메시지를 반환한다.
    # 이것이 "Real결과"를 반환하도록 수정해야 한다.
    # 궁극적으로는 아래의 라인을 위의 $item{BraceBlock}->toString()으로 대치해야 한다.

    $return = $startline.substr($Mace::Compiler::Grammar::text, $item{StartPos},
		     1 + $item{EndPos} - $item{StartPos}).$endline;
}
| '=' '0' ';' { $return = "0" }
| ';' { $return = "" }
| <reject:!$arg{forceColon}> ':' { $return = "" }

#FIXME: 현재 Expression1 에 해당하는 부분이 스트링으로 대치되어 있음. 이를 더 파고들도록 추후 수정 요망.
# 이게 문제는 아닌가??
# 이것 때문에 .mh에서 생성되는 파일들이 제대로 컴파일되지 못하는 경우가 있음..
Expression : StartPos Expression1 EndPos
{
    my $node = Mace::Compiler::ParseTreeObject::Expression->new();

    $node->expr(substr($Mace::Compiler::Grammar::text, $item{StartPos}, 1 + $item{EndPos} - $item{StartPos}));

    $return = $node;

#    $return = substr($Mace::Compiler::Grammar::text, $item{StartPos},
#		     1 + $item{EndPos} - $item{StartPos});
}

AssignBinaryOp : '+=' | '-=' | '<<=' | '>>=' | '|=' | '&=' | '=' ...!'=' | '%=' | <error>

PrePostAssignOp : '++' | '--' | <error>

BinaryOp : '*' | '/' | '+' ...!/[+=]/ | '<<' ...!'=' | '>>' ...!'=' | '!=' | '==' | '<=' | '>=' | '<' | '>' | '||' | '|' | '&&' | '&' | '^' | '.' | '->' | '-' ...!/[-=]/ | '%' ...!'=' | <error>

UnaryOp : '!' | '~' | '*' | '&' | 'new' | 'delete' | <error>

# Assume - operators have usual conventions on r/w (+, -, ++, +=, ...)

ExpressionOrAssignLValue : StartPos ExpressionOrAssignLValue1 EndPos
{ 
    $return = substr($Mace::Compiler::Grammar::text, $item{StartPos},
		     1 + $item{EndPos} - $item{StartPos});
}

ExpressionOrAssignLValue1 : ExpressionLValue1 PrePostAssignOp | PrePostAssignOp ExpressionLValue1 | ExpressionLValue1 AssignBinaryOp Expression1 | ExpressionLValue1 | <error>

ExpressionLValue : 
# StartPos ExpressionLValue1 EndPos <reject: (not $arg{parseFunctionCall}) or ($item{ExpressionLValue1} eq "FUNCTION_CALL")> { print "ERR (FC): ".substr($Mace::Compiler::Grammar::text, $item{StartPos}, 1 + $item{EndPos} - $item{StartPos})."\n"; } <error: Expecting function and not function, but parsed expression.>
#| 
StartPos ExpressionLValue1 EndPos <commit> <reject: $arg{parseFunctionCall} and not ($item{ExpressionLValue1} eq "FUNCTION_CALL")>
{
    $return = substr($Mace::Compiler::Grammar::text, $item{StartPos},
		     1 + $item{EndPos} - $item{StartPos});
    # if ($arg{parseFunctionCall} && ! ($item{ExpressionLValue1} eq "FUNCTION_CALL")) {
    #     print "Expression $return parsed, but not recognized as a function call!\n";
    #     $return = undef;
    # }
}
| <error?: Parsed Expression LValue, but Required Function Call> <error>

ExpressionLValue1 : ExpressionLValue2 '.' <commit> ExpressionLValue1
| '*' <commit> ExpressionLValue1
| ExpressionLValue2 '->' <commit> ExpressionLValue1
| ExpressionLValue2 '?' <commit> ExpressionLValue1 ':' ExpressionLValue1
| ExpressionLValue2
| <error>

ExpressionLValue2: <reject>
| ScopedId ( '[' <commit> Expression1 ']' )(s)
| ScopedId '(' Expression1(s? /,/) ')' { $return = "FUNCTION_CALL"; }
| ScopedId '(' <commit> ExpressionOrAssignLValue1(s /,/) ')' { $return = "FUNCTION_CALL"; }
| ScopedId
| <error>

#Changed to Expression1 to allow unary operators before things like my.foo
Expression1 : UnaryOp <commit> Expression1
| Expression2 BinaryOp <commit> Expression1
| Expression2 '?' <commit> Expression1 ':' Expression1
| Expression2
| <error>

QuotedString : <skip:'\s*'> 
               /"           #Opening Quote
                [^"\\\\]*     #Any number of characters not a quote or slash
                (           #Group: 1
                  \\\\        #Followed by a slash
                  .         #Any character
                  [^"\\\\]*   #Any number of characters not a quote or slash
                )*          #1: Repeated any number of times
                "           #Closing quote
               /sx

Number : /0x[a-fA-F0-9]+(LL)?/ | /-?\d+LL/ | /-?\d+(\.\d+)?/ | <error>

Character : /'\\?.'/ | <error>

ParenOrBrace : '(' | '[' | <error>

ArrayIndOrFunction : '(' Expression1(s? /,/) ')'
| '[' Expression1 ']'
| <error>

ArrayIndOrFunctionParts : ...ParenOrBrace <commit> ArrayIndOrFunction ArrayIndOrFunctionParts
| <error?> <reject>
| 

Expression2 : Number
| ScopedId ...ParenOrBrace <commit> ArrayIndOrFunctionParts
| ..."'" <commit> "'" /[^\']*/ "'"
| ...'"' <commit> QuotedString
| '(' Type ')' Expression1
| '(' <commit> Expression1 ')'
| ScopedId
| <error>

TypeOptions : <reject: !$arg{typeopt}> '__attribute((' <commit> TypeOption(s /,/) '))' 
{ 
  $return = $item[4];
} | { $return = []; }
TypeOption : <rulevar: %opt>
TypeOption : FileLine Id '(' TypeOptionParamList['options'=>\%opt] ')' 
{
  $return = Mace::Compiler::TypeOption->new(name => $item{Id}, line => $item{FileLine}->[0], file => $item{FileLine}->[1]);
  $return->options(%opt);
} | <error>
TypeOptionParamList : 
( 
  Id '=' <commit> Expression 
  { $arg{options}->{$item{Id}} = $item{Expression}->toString() }
#  { $arg{options}->{$item{Id}} = $item{Expression} }
| Expression 
  { $arg{options}->{$item{Expression}->toString()} = $item{Expression}->toString() } 
#  { $arg{options}->{$item{Expression}} = $item{Expression} } 
)(s? /;/) (';')(?) ...')' | <error>

ArraySizes : <reject: !$arg{arrayok}> ArraySize(s) | { $return = []; }
ArraySize : '[' Expression ']' { $return = $item{Expression}->toString(); } | <error>
#ArraySize : '[' Expression ']' { $return = $item{Expression}; } | <error>

CheckSemi : <reject: !$arg{semi}> ';' <commit> | <reject: $arg{semi}> | <error>

Parameter : ...Type ParameterType[%arg]
| <reject:!defined($arg{typeOptional})> ParameterId[%arg]
| <error>

ParameterType : <reject: $arg{declareonly}> Type FileLineEnd Id ArraySizes[%arg] TypeOptions[%arg] '=' Expression CheckSemi[%arg]
{ 
    my $p = Mace::Compiler::Param->new(name => $item{Id},
                                       type => $item{Type},
                                       hasDefault => 1,
                                       filename => $item{FileLineEnd}->[1],
                                       line => $item{FileLineEnd}->[0],
                                       default => $item{Expression}->toString());
#                                       default => $item{Expression});
    $p->typeOptions(@{$item{TypeOptions}});
    $p->arraySizes(@{$item{ArraySizes}});
    $return = $p;
}
| <reject: $arg{declareonly}> Type FileLineEnd Id ArraySizes[%arg] TypeOptions[%arg] '=' <commit> ExpressionOrAssignLValue CheckSemi[%arg]
{ 
    my $p = Mace::Compiler::Param->new(name => $item{Id},
                                       type => $item{Type},
                                       hasDefault => 1,
                                       filename => $item{FileLineEnd}->[1],
                                       line => $item{FileLineEnd}->[0],
                                       default => $item{ExpressionOrAssignLValue});
    $p->typeOptions(@{$item{TypeOptions}});
    $p->arraySizes(@{$item{ArraySizes}});
    $return = $p;
}
| <reject: !$arg{mustinit}> <commit> <error>
| <reject: !defined($arg{initializerOk})> Type FileLineEnd Id ArraySizes[%arg] '(' Expression(s? /,/) ')' CheckSemi[%arg]
{
    my $p = Mace::Compiler::Param->new(name => $item{Id},
                                       type => $item{Type},
                                       hasDefault => 1,
                                       filename => $item{FileLineEnd}->[1],
                                       line => $item{FileLineEnd}->[0],
                                       default => $item{Type}->type()."(".join(", ", @{$item[-3]}).")");
    $p->arraySizes(@{$item{ArraySizes}});
    $return = $p;
}
| <reject: !defined($arg{initializerOk})> Type FileLineEnd Id ArraySizes[%arg] '(' <commit> ExpressionOrAssignLValue(s? /,/) ')' CheckSemi[%arg]
{
    my $p = Mace::Compiler::Param->new(name => $item{Id},
                                       type => $item{Type},
                                       hasDefault => 1,
                                       filename => $item{FileLineEnd}->[1],
                                       line => $item{FileLineEnd}->[0],
                                       default => $item{Type}->type()."(".join(", ", @{$item[-3]}).")");
    $p->arraySizes(@{$item{ArraySizes}});
    $return = $p;
}
| Type FileLineEnd Id <commit> ArraySizes[%arg] TypeOptions[%arg] CheckSemi 
{
    #print "Param1 type ".$item{Type}->toString()."\n";
    my $p = Mace::Compiler::Param->new(name => $item{Id},
				       type => $item{Type},
                                       filename => $item{FileLineEnd}->[1],
                                       line => $item{FileLineEnd}->[0],
				       hasDefault => 0);
    $p->typeOptions(@{$item{TypeOptions}});
    $p->arraySizes(@{$item{ArraySizes}});

    $return = $p;
}
| <reject: !$arg{declareonly}> <commit> <error>
| <reject:!defined($arg{mapOk})> Type FileLineEnd DirArrow[direction => $arg{usesOrImplements}] Type 
{
    #print "Param2 type ".$item{Type}->toString()."\n";
    my $p = Mace::Compiler::Param->new(name => "noname_".$thisrule->{'local'}{'paramnum'}++,
				       type => $item[5],
                                       typeSerial => $item[2],
                                       filename => $item{FileLineEnd}->[1],
                                       line => $item{FileLineEnd}->[0],
				       hasDefault => 0);

    $return = $p;
}
| Type FileLineEnd ('=' Expression)(?) <reject:!defined($arg{noIdOk})>
{
    #print "Param2 type ".$item{Type}->toString()."\n";
    my $p = Mace::Compiler::Param->new(name => "noname_".$thisrule->{'local'}{'paramnum'}++,
				       type => $item{Type},
                                       filename => $item{FileLineEnd}->[1],
                                       line => $item{FileLineEnd}->[0],
				       hasDefault => scalar(@{$item[3]}));

    if ($p->hasDefault()) {
	$p->default(${$item[3]}[0]);
    }
    $return = $p;
}
| <error?> <error>

ParameterId : Id FileLineEnd <reject:!defined($arg{typeOptional})>
{
    #print "Param2 type ".$item{Type}->toString()."\n";
    my $p = Mace::Compiler::Param->new(name => $item{Id},
				       #type => $item{Type},
                                       filename => $item{FileLineEnd}->[1],
                                       line => $item{FileLineEnd}->[0],
				       hasDefault => 0);

    $return = $p;
}
| <error>

ATTypeDef : /typedef\s/ FileLine Type Id ';'
{
    $return = Mace::Compiler::TypeDef->new(name=>$item{Id}, type=>$item{Type}, line => $item{FileLine}->[0], filename => $item{FileLine}->[1]);
}
        | <error>

AutoType : Id FileLine TypeOptions[typeopt => 1] '{' ATTypeDef(s?) Parameter[typeopt => 1, semi => 1](s?) Constructor[className => $item{Id}](s?) Method[staticOk=>1](s?) '}' (';')(?) 
{
  my $at = Mace::Compiler::AutoType->new(name => $item{Id},
					 line => $item{FileLine}->[0],
					 filename => $item{FileLine}->[1],
					 );
  $at->typeOptions(@{$item{TypeOptions}});
  $at->typedefs(@{$item[5]});
  $at->fields(@{$item[6]});
  $at->constructors(@{$item[7]});
  $at->methods(@{$item[8]});
  for my $m (@{$item[7]}) {
    if($m->name ne $item{Id}) {
      Mace::Compiler::Globals::error("bad_auto_type",  $item{FileLine}->[1], $item{FileLine}->[0], "Constructor name does not match auto_type name");
    }
  }
  my $key = "service";
  if (defined($arg{key})) {
      $key = $arg{key};
  }
  $thisparser->{'local'}{$key}->push_auto_types($at);
}
| <error>

#XXX: reject
DirArrow : '<-' <commit> <reject: $arg{direction} eq "uses"> | '->' <commit> <reject: $arg{direction} eq "implements">

KeyEqVal : Id '=' Id { $return = [ $item[1], $item[-1] ] }

MethodOptions : '[' KeyEqVal(s /;/) (';')(?) ']' { $return = $item[2];}

InitializerItem : ScopedId '(' Expression(s? /,/) ')'
InitializerList : StartPos FileLineEnd ':' InitializerItem(s /,/) EndPos 
{
    my $startline = "";
    my $endline = "";
    #if(defined($Mace::Compiler::Globals::filename) and $Mace::Compiler::Globals::filename ne '') {
      $startline = "\n#line ".$item{FileLineEnd}->[0]." \"".$item{FileLineEnd}->[1]."\"\n";
      $endline = "\n// __INSERT_LINE_HERE__\n";
    #}
    $return = $startline.substr($Mace::Compiler::Grammar::text, $item{StartPos},
		     1 + $item{EndPos} - $item{StartPos}).$endline;
}
| {$return = ""}

Constructor : <reject:defined($arg{className})> <commit> /\b$thisparser->{'local'}{'classname'}\b/ '(' Parameter(s? /,/) ')' InitializerList MethodTerm
{
    my $t = Mace::Compiler::Type->new(type => "");
    my $m = Mace::Compiler::Method->new(name => $thisparser->{'local'}{'classname'},
					returnType => $t,
					body => $item{InitializerList}.$item{MethodTerm});

    if (scalar(@{$item[5]})) {
	$m->params(@{$item[5]});
    }

    $return = $m;
}
| <reject:!defined($arg{className})> <commit> /\b$arg{className}\b/ '(' Parameter(s? /,/) ')' InitializerList MethodTerm
{
    my $t = Mace::Compiler::Type->new(type => "");
    my $m = Mace::Compiler::Method->new(name => $arg{className},
					returnType => $t,
					body => $item{InitializerList}.$item{MethodTerm});

    if (scalar(@{$item[5]})) {
	$m->params(@{$item[5]});
    }

    $return = $m;
}
| <error>


Destructor : ('virtual')(?) '~' /\b$thisparser->{'local'}{'classname'}\b/ '(' ')' MethodTerm
{
    my $t = Mace::Compiler::Type->new(type => "");
    my $m = Mace::Compiler::Method->new(name => '~' . $thisparser->{'local'}{'classname'},
					returnType => $t,
					body => $item{MethodTerm});
    if (defined($item[1])) {
	$m->isVirtual(1);
    }
    $return = $m;
}

ThrowType : Type { $return = $item{Type}->toString() } | "..."
Throws : 'throw' '(' ThrowType ')'
{
  $return = 'throw('.$item{ThrowType}.')';
}

#MethodReturnType : <reject:$arg{noReturn}> Type | <reject:!$arg{noReturn}> { $return = Mace::Compiler::Type->new(); } | <error>
MethodReturnType : Type ...!'(' { $return = $item{Type} } | <reject:!$arg{noReturn}> { $return = Mace::Compiler::Type->new(); } | <error>

MethodOperator : '==' | '<=' | '>=' | '<' | '>' | '=' | '!=' | '+' | '*' | '/' | '->' | '-'
MethodName : /operator\b/ <commit> MethodOperator { $return = "operator".$item{MethodOperator}; } | Id | <error>
StaticToken : /static\b/

Method : StaticToken(?) <reject:!$arg{staticOk} and scalar(@{$item[1]})> MethodReturnType[%arg] MethodName FileLineEnd '(' Parameter[%arg](s? /,/) ')' ConstToken(?) Throws(?) MethodOptions(?) MethodTerm[forceColon => $arg{forceColon}]
{
    # print $item{MethodName}."\n";
    # print "DEBUG:  ".$item{FileLine}->[2]."\n";
    # print "DEBUG1: ".$item{FileLine}->[0]."\n";
    # print "DEBUG2: ".$item{FileLine}->[1]."\n";
    my $m = Mace::Compiler::Method->new(name => $item{MethodName},
					returnType => $item{MethodReturnType},
					isConst => scalar(@{$item[-4]}),
                                        isStatic => scalar(@{$item[1]}),
                                        line => $item{FileLineEnd}->[0],
                                        filename => $item{FileLineEnd}->[1],
					body => $item{MethodTerm});
    if (scalar($item[-3])) {
        $m->throw(@{$item[-3]}[0]);
    }
    if (scalar(@{$item[7]})) {
	$m->params(@{$item[7]});
    }

    if (scalar(@{$item[-2]})) {
	my $ref = ${$item[-2]}[0];
	for my $el (@$ref) {
	    $m->options(@$el);
        #print STDERR "MethodOptions DEBUG:  ".$el->[0]."=".$el->[1]."\n";
	}
    }

    $return = $m;
}
| <error>

PointerType : NonPointerType ConstToken ('*')(s) | NonPointerType ('*')(s) ConstToken ('*')(s) | NonPointerType ('*')(s?) | <error>

NonPointerType : BasicType | StructType | ScopedType | <error>

#XXX-CK: Shouldn't this really be a recursion on Type, not Id?  After all, you can have std::map<> or map<>::iterator . . . 
ScopedId : StartPos TemplateTypeId ('::' TemplateTypeId)(s?) EndPos { $return = substr($Mace::Compiler::Grammar::text, $item{StartPos}, 1 + $item{EndPos} - $item{StartPos}); }
ScopedType : TemplateType ('::' TemplateType)(s?) 

#NOTE: CK -- added ScopedType to Template type to allow ::
#      CK -- Added | Expression since template parameters could be constant expressions
#      CK -- BasicType added to parse primitive types and their modifiers
TemplateTypeId : Id '<' ( ConstToken(?) (PointerType | Number) )(s /,/) '>' | Id | <error>
TemplateType : Id '<' <commit> ( ConstToken(?) (PointerType | Number) )(s /,/) '>' | Id | <error>

ConstToken : /const\b/ 

RefToken : '&'

#NOTE: CK -- added \b to avoid problems parsing things like int8_t.  Also -- removed 'long long'
TypeModifier : /\blong\b/ | /\bsigned\b/ | /\bunsigned\b/ | /\bshort\b/ | <error>
PrimitiveType : /\bint\b/ | /\bdouble\b/ | /\bfloat\b/ | /\bchar\b/ | <error>
BasicType : TypeModifier(0..3) PrimitiveType | TypeModifier(1..3) | <error>

StructType : 'struct' Id 

Type : ConstToken(?) StartPos PointerType EndPos ConstToken(?) RefToken(?)
{
    my $type = substr($Mace::Compiler::Grammar::text, $item{StartPos},
		      1 + $item{EndPos} - $item{StartPos});

    $return = Mace::Compiler::Type->new(type => Mace::Util::trim($type),
 					isConst => (scalar(@{$item[1]}) or scalar(@{$item[-2]})),
 					isRef => scalar(@{$item[-1]}));
}
| <error>

ProtectionToken : /public\b/ | /private\b/ | /protected\b/

EOFile : /^\Z/

}; # COMMON grammar

1;
