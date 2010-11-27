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
#        print "BraceBlock {{ \n";

#        for my $statement (@{$item[2]}) {
#            if( ref($statement) ne "" ) {
#                print "  SEMI-STATEMENTS[o]: ".$statement->toString()."\n";
#            } else {
#                print "  SEMI-STATEMENTS[s]: $statement\n";
#            }
#        }

        $node->semi_statements(@{$item[2]});

#        print "BraceBlock }} \n";

    }# else {
#        print "BraceBlock { }\n";
#   }
    $return = $node;
    #$return = $item[2];    # original
}


Enum : /enum\s/ Id '{' SemiStatementBegin '}'

ParsedExpression : Expression
    {
        my $node = Mace::Compiler::ParseTreeObject::ParsedExpression->new(expr=>$item{Expression});
#        if( ref($item{Expression}) ne "" ) {
#            print "ParsedExpression[o]: ".$item{Expression}->toString()."\n";
#        } else {
#            print "ParsedExpression[s]: $item{Expression}\n";
#        }
        $return = $node;
    }

#ParsedReturn : /return\b/ ';' {$return = "VOID RETURN";}
#| /return\b/ ParsedExpression ';' {$return = "NON-VOID RETURN ( ".$item{ParsedExpression}." )";}

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

# FIXME(shyoo) : Parameters should be handled to process read_ variables.
ParsedVar : StaticToken(?) Parameter[%arg, initializerOk => 1] 
{ 
  if (scalar(@{$item[1]})) {
    my $node = Mace::Compiler::ParseTreeObject::ParsedVar->new(is_static=>1, is_semi=>$arg{semi}, parameter=>$item{Parameter}->toString(noline => 1));
    #print "ParsedVar[static]: ".$item{Parameter}->toString(noline => 1)."\n";
    $return = $node;
  } else {
    my $node = Mace::Compiler::ParseTreeObject::ParsedVar->new(is_static=>0, is_semi=>$arg{semi}, parameter=>$item{Parameter}->toString(noline => 1));
    #print "ParsedVar[nostatic]: ".$item{Parameter}->toString(noline => 1)."\n";
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
        $return = $node;
    }
#    { $return = "ELSE { ".$item{StatementOrBraceBlock}." }"; }
| <error?> <reject>
|   {
      my $node = Mace::Compiler::ParseTreeObject::ParsedElse->new(null=>1);
      $return = $node;
    }
#| { $return = ""; }

ElseAndIf: /else\b/ /if\b/

ParsedElseIfs: ...ElseAndIf <commit> ParsedElseIf ParsedElseIfs
    { 
      my $node = Mace::Compiler::ParseTreeObject::ParsedElseIfs->new(null=>0, parsed_else_if=>$item{ParsedElseIf}, parsed_else_ifs=>$item{ParsedElseIfs});
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
      $return = $node;
    }
#| { $return = ""; }

ParsedElseIf: ElseAndIf <commit> '(' ParsedExpression ')' StatementOrBraceBlock
    {
        my $node = Mace::Compiler::ParseTreeObject::ParsedElseIf->new(type=>"parsed_expression", parsed_expr=>$item{ParsedExpression}, stmt_or_block=>$item{StatementOrBraceBlock});
        $return = $node;
    }
#    { $return = "ELSE IF ( ".$item{ParsedExpression}." ) THEN { ".$item{StatementOrBraceBlock}." }"; }
| ElseAndIf <commit> '(' ExpressionOrAssignLValue ')' StatementOrBraceBlock
    {
        my $node = Mace::Compiler::ParseTreeObject::ParsedElseIf->new(type=>"expression_or_assign_lvalue", expr_or_assign=>$item{ExpressionOrAssignLValue}, stmt_or_block=>$item{StatementOrBraceBlock});
        $return = $node;
    }
#    { $return = "ELSE IF[LVAL] ( ".$item{ExpressionOrAssignLValue}." ) THEN { ".$item{StatementOrBraceBlock}." }"; }
| <error>

ParsedIf : /if\b/ '(' ParsedExpression ')' StatementOrBraceBlock ParsedElseIfs ParsedElse
    {
      my $node = Mace::Compiler::ParseTreeObject::ParsedIf->new(type=>"parsed_expression", parsed_expr=>$item{ParsedExpression}, stmt_or_block=>$item{StatementOrBraceBlock}, parsed_else_ifs=>$item{ParsedElseIfs}, parsed_else=>$item{ParsedElse});
#      print "ParsedIf[1]: ".$node->toString()."\n";
#      print "  ParsedExpression: ".$item{ParsedExpression}->toString()."\n";
#      print "  StatementOrBraceBlock: ".$item{StatementOrBraceBlock}->toString()."\n";
      $return = $node;
    }
| /if\b/ '(' ExpressionOrAssignLValue ')' StatementOrBraceBlock ParsedElseIfs ParsedElse
    {
      my $node = Mace::Compiler::ParseTreeObject::ParsedIf->new(type=>"expression_or_assign_lvalue", expr_or_assign=>$item{ExpressionOrAssignLValue}, stmt_or_block=>$item{StatementOrBraceBlock}, parsed_else_ifs=>$item{ParsedElseIfs}, parsed_else=>$item{ParsedElse});
#      print "ParsedIf[2]: ".$node->toString()."\n";
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
    { 
        my $node = Mace::Compiler::ParseTreeObject::ParsedDoWhile->new(stmt_or_block=>$item{StatementOrBraceBlock}, parsed_expr=>$item{ParsedExpression});
        $return = $node;
    }
#{ $return = "DO-WHILE: EXEC { ".$item{StatementOrBraceBlock}." } COND: ".$item{ParsedExpression}; }

ParsedWhile : /while\b/ <commit> '(' ParsedExpression ')' StatementOrBraceBlock
    {
        my $node = Mace::Compiler::ParseTreeObject::ParsedWhile->new(parsed_expr=>$item{ParsedExpression}, stmt_or_block=>$item{StatementOrBraceBlock});
        $return = $node;
    }
#{ $return = "WHILE: EXEC { ".$item{StatementOrBraceBlock}." } COND: ".$item{ParsedExpression}; }

ParsedAbort : 'ABORT' '(' QuotedString ')' ';'
    {
        my $node = Mace::Compiler::ParseTreeObject::ParsedAbort->new(quoted_string=>$item{QuotedString});
        $return = $node;
    }
#{ $return = "ABORT: ".$item{QuotedString}; }
| <error>

ParsedAssertMsg : 'ASSERTMSG' '(' Expression ',' QuotedString ')' ';'
    { 
        my $node = Mace::Compiler::ParseTreeObject::ParsedAssertMsg->new(expr=>$item{Expression}, quoted_string=>$item{QuotedString});
        $return = $node;
    }
#{ $return = "ASSERTION WITH ERRMSG: cond: ".$item{Expression}. " errmsg: ".$item{QuotedString}; }
| <error>

ParsedAssert : 'ASSERT' '(' Expression ')' ';'
    {
        my $node = Mace::Compiler::ParseTreeObject::ParsedAssert->new(expr=>$item{Expression});
        $return = $node;
    }
#{ $return = "ASSERTION: ".$item{Expression}; }
| <error>

ParsedFCall : ExpressionLValue[parseFunctionCall => 1]
    { 
        my $node = Mace::Compiler::ParseTreeObject::ParsedFCall->new(expr_lvalue=>$item{ExpressionLValue});
        $return = $node;
    }
#{ $return = "FUNCTION CALL: ".$item{ExpressionLValue}; }
| <error>


ParsedLValue : ParsedPlusPlus 
    {
        my $node = Mace::Compiler::ParseTreeObject::ParsedLValue->new(type=>"parsed_plus_plus", parsed_plus_plus=>$item{ParsedPlusPlus});
        $return = $node;
    }
| ParsedBinaryAssignOp 
    {
        my $node = Mace::Compiler::ParseTreeObject::ParsedLValue->new(type=>"parsed_binary_assign_op", parsed_binary_assign_op=>$item{ParsedBinaryAssignOp});
        $return = $node;
    }
| ExpressionLValue
    {
        my $node = Mace::Compiler::ParseTreeObject::ParsedLValue->new(type=>"expression_lvalue", parsed_expr_lvalue=>$item{ExpressionLValue});
        $return = $node;
    }
#ParsedLValue : ParsedPlusPlus | ParsedBinaryAssignOp | ExpressionLValue
| <error>

#| ScopedId '[' Expression ']' { $return = $item{ScopedId} . '[' . $item{Expression} . ']'; }

ParsedBinaryAssignOp : ExpressionLValue AssignBinaryOp Expression CheckSemi[%arg]
    {
        print "ParsedBinaryAssignOp[expression]\n";
        my $node = Mace::Compiler::ParseTreeObject::ParsedBinaryAssignOp->new(type=>"expression", expr_lvalue=>$item{ExpressionLValue}, assign_binary_op=>$item{AssignBinaryOp}, expr=>$item{Expression}, check_semi=>$item{CheckSemi});
        $return = $node;
    }
#{ $return = "BINARY ASSIGNMENT OP: LVALUE= ".$item{ExpressionLValue}." OP: ".$item{AssignBinaryOp}." RVALUE= ".$item{Expression}; }
| ExpressionLValue AssignBinaryOp <commit> ParsedLValue CheckSemi[%arg]
    {
        print "ParsedBinaryAssignOp[parsed_lvalue]\n";
        my $node = Mace::Compiler::ParseTreeObject::ParsedBinaryAssignOp->new(type=>"parsed_lvalue", expr_lvalue=>$item{ExpressionLValue}, assign_binary_op=>$item{AssignBinaryOp}, parsed_lvalue=>$item{ParsedLValue}, check_semi=>$item{CheckSemi});
        $return = $node;
    }
#{ $return = "BINARY ASSIGNMENT OP RHS-LV: LVALUE= ".$item{ExpressionLValue}." OP: ".$item{AssignBinaryOp}." RVALUE= ".$item{ParsedLValue}; }
| <uncommit> <defer: print "ParsedBinaryAssignOp failed.";> <error?> <error>

ParsedPlusPlus : ExpressionLValue '++' 
    {
        my $node = Mace::Compiler::ParseTreeObject::ParsedPlusPlus->new(type=>"post++", expr_lvalue=>$item{ExpressionLValue});
        $return = $node;
    }
#{ $return = "POSTINCREMENT: LVALUE= ".$item{ExpressionLValue}; }
| '++' ExpressionLValue
    {
        my $node = Mace::Compiler::ParseTreeObject::ParsedPlusPlus->new(type=>"pre++", expr_lvalue=>$item{ExpressionLValue});
        $return = $node;
    }
#{ $return = "PREINCREMENT: LVALUE= ".$item{ExpressionLValue}; }
| ExpressionLValue '--' 
    {
        my $node = Mace::Compiler::ParseTreeObject::ParsedPlusPlus->new(type=>"post--", expr_lvalue=>$item{ExpressionLValue});
        $return = $node;
    }
#{ $return = "POSTDECREMENT: LVALUE= ".$item{ExpressionLValue}; }
| '--' ExpressionLValue
    {
        my $node = Mace::Compiler::ParseTreeObject::ParsedPlusPlus->new(type=>"pre--", expr_lvalue=>$item{ExpressionLValue});
        $return = $node;
    }
#{ $return = "PREDECREMENT: LVALUE= ".$item{ExpressionLValue}; }


ParsedForVar : ParsedVar 
    {
        my $node = Mace::Compiler::ParseTreeObject::ParsedForVar->new(type=>"parsed_var", parsed_var=>$item{ParsedVar});
        $return = $node;
    }
| ParsedBinaryAssignOp 
    {
        my $node = Mace::Compiler::ParseTreeObject::ParsedForVar->new(type=>"parsed_binary_assign_op", parsed_binary_assign_op=>$item{ParsedBinaryAssignOp});
        $return = $node;
    }
|
    {
        my $node = Mace::Compiler::ParseTreeObject::ParsedForVar->new(type=>"null");
        $return = $node;
    }
#ParsedForVar : ParsedVar | ParsedBinaryAssignOp | {$return = ""; }

ParsedForUpdate : ParsedPlusPlus 
    {
        my $node = Mace::Compiler::ParseTreeObject::ParsedForUpdate->new(type=>"parsed_plus_plus", parsed_plus_plus=>$item{ParsedPlusPlus});
        $return = $node;
    }
| ParsedBinaryAssignOp 
    {
        my $node = Mace::Compiler::ParseTreeObject::ParsedForUpdate->new(type=>"parsed_binary_assign_op", parsed_binary_assign_op=>$item{ParsedBinaryAssignOp});
        $return = $node;
    }
|
    {
        my $node = Mace::Compiler::ParseTreeObject::ParsedForUpdate->new(type=>"null");
        $return = $node;
    }
#ParsedForUpdate : ParsedPlusPlus | ParsedBinaryAssignOp | {$return = ""; }

ParsedForLoop : /for\b/ '(' ParsedForVar ';' Expression ';' ParsedForUpdate ')' StatementOrBraceBlock
    {
        my $node = Mace::Compiler::ParseTreeObject::ParsedForLoop->new(parsed_for_var=>$item{ParsedForVar}, expr=>$item{Expression}, parsed_for_update=>$item{ParsedForUpdate}, stmt_or_block=>$item{StatementOrBraceBlock});
        $return = $node;
    }
#{
#    $return = "FOR: VAR( ". $item{ParsedForVar} ." ) TEST( ".$item{Expression}." ) UPDATE( ".$item{ParsedForUpdate}." ) EXEC { ".$item{StatementOrBraceBlock}." }";
#}

OutputStream1 : 'maceout' | 'maceerr' | 'macewarn' | 'macedbg' '(' Number ')' {$return = "macedbg(".$item{Number}.")";} | 'cout' | 'cerr' | 'std::cout' | 'std::cerr' | <error>

OutputStream : StartPos OutputStream1 EndPos
{ 
    $return = substr($Mace::Compiler::Grammar::text, $item{StartPos},
             1 + $item{EndPos} - $item{StartPos});
}

OutputOperator1 : '<<' | <error>

OutputOperator : StartPos OutputOperator1 EndPos
{ 
    $return = substr($Mace::Compiler::Grammar::text, $item{StartPos},
             1 + $item{EndPos} - $item{StartPos});
}

ParsedLogging : OutputStream <commit> OutputOperator Expression ';'
    {
        my $node = Mace::Compiler::ParseTreeObject::ParsedLogging->new(output_stream=>$item{OutputStream}, output_operator=>$item{OutputOperator}, expr=>$item{Expression});
        $return = $node;
    }
#{ $return = "LOGGING: Stream: ".$item{OutputStream}." Value: ".$item{Expression}; }

ParsedOutput : ExpressionLValue OutputOperator <commit> Expression ';'
    {
        my $node = Mace::Compiler::ParseTreeObject::ParsedOutput->new(expr_lvalue=>$item{ExpressionLValue}, output_operator=>$item{OutputOperator}, expr=>$item{Expression});
        $return = $node;
    }
#{ $return = "OUTPUT: Stream: ".$item{ExpressionLValue}." Value: ".$item{Expression}; }

ParsedDefaultCase : 'default' <commit> ':' SemiStatement(s?)
    {
        my $node = Mace::Compiler::ParseTreeObject::ParsedDefaultCase->new(type=>"default", semi_statements=>$item[-1]);
        $return = $node;
    }
#{ $return = "DEFAULT EXEC {".join(" :: ", @{$item[-1]})."}"; }
| <error?> <reject>
|
    {
        my $node = Mace::Compiler::ParseTreeObject::ParsedDefaultCase->new(type=>"null");
        $return = $node;
    }
#| { $return = ""; }

ParsedSwitchConstant : Number 
    {
        my $node = Mace::Compiler::ParseTreeObject::ParsedSwitchConstant->new(type=>"number", val=>$item{Number});
        $return = $node;
    }
| Character 
    {
        my $node = Mace::Compiler::ParseTreeObject::ParsedSwitchConstant->new(type=>"character", val=>$item{Character});
        $return = $node;
    }
| ScopedId
    {
        my $node = Mace::Compiler::ParseTreeObject::ParsedSwitchConstant->new(type=>"scoped_id", scoped_id=>$item{ScopedId});
        $return = $node;
    }
#ParsedSwitchConstant : Number | Character | ScopedId

ParsedSwitchCase : 'case' ParsedSwitchConstant ':' SemiStatement(s?)
    {
        my $node = Mace::Compiler::ParseTreeObject::ParsedSwitchCase->new(parsed_switch_constant=>$item{ParsedSwitchConstant}, semi_statements=>$item[-1]);
        $return = $node;
    }
#{ $return = "CASE ( ".$item{ParsedSwitchConstant}." ) EXEC {".join(" :: ", @{$item[-1]})."}"; }

ParsedSwitchCases : ...'case' <commit> ParsedSwitchCase ParsedSwitchCases
    {
        my $node = Mace::Compiler::ParseTreeObject::ParsedSwitchCases->new(type=>"case", parsed_switch_case=>$item{ParsedSwitchCase}, parsed_switch_cases=>$item{ParsedSwitchCases});
        $return = $node;
    }
#{ $return = $item{ParsedSwitchCase}.($item{ParsedSwitchCases} ne "" ? " ".$item{ParsedSwitchCases} : ""); }
| <error?><reject>
|
    {
        my $node = Mace::Compiler::ParseTreeObject::ParsedSwitchCases->new(type=>"null");
        $return = $node;
    }
#| { $return = ""; }

ParsedSwitch : 'switch' '(' Expression ')' '{' ParsedSwitchCases ParsedDefaultCase '}' (';')(?)
    { 
        my $node = Mace::Compiler::ParseTreeObject::ParsedSwitch->new(expr=>$item{Expression}, parsed_switch_cases=>$item{ParsedSwitchCases}, parsed_default_case=>$item{ParsedDefaultCase});
        $return = $node;
    }
#{ $return = "SWITCH EXPRESSION( ".$item{Expression}." ) ".$item{ParsedSwitchCases}." ".$item{ParsedDefaultCase}; }

ParsedMacro : '#' <commit> /[^\n]+/
    {
        my $node = Mace::Compiler::ParseTreeObject::ParsedMacro->new(item=>$item[3]);
        $return = $node;
    }
#{ $return = "PREPROCESSOR MACRO: ".$item[1].$item[3]; }
| <error?> <error>

ParsedControlFlow : 'break' | 'continue'

ParsedExpectStatement : 'EXPECT' '(' Expression ')' '{' StatementBlock '}'
    {
        my $node = Mace::Compiler::ParseTreeObject::ParsedExpectStatement->new(type=>"stmt_block", expr=>$item{Expression}, stmt_block=>$item{StatementBlock});
        $return = $node;
    }
#{ $return = "EXPECT BLOCK COND: ".$item{Expression}." EXEC: { ".$item{StatementBlock}."}"; }
| 'EXPECT' '(' Expression ')' SemiStatement <error: You need a semi-colon after an EXPECT condition, or an opening brace to start a success block.>
| 'EXPECT' <commit> '(' Expression ')' ';'
    {
        my $node = Mace::Compiler::ParseTreeObject::ParsedExpectStatement->new(type=>"expr", expr=>$item{Expression});
        $return = $node;
    }
#{ $return = "EXPECT COND: ".$item{Expression}; }
| <error>

ParsedCatch : 'catch' '(' ParsedVar <commit> ')' '{' StatementBlock '}' 
    {
        my $node = Mace::Compiler::ParseTreeObject::ParsedCatch->new(type=>"parsed_var", parsed_var=>$item{ParsedVar}, stmt_block=>$item{StatementBlock});
        $return = $node;
    }
#{ $return = "CATCH TYPE: ".$item{ParsedVar}." EXEC { ".$item{StatementBlock}." }"; }
| 'catch' <commit> '(' '...' ')' '{' StatementBlock '}'
    {
        my $node = Mace::Compiler::ParseTreeObject::ParsedCatch->new(type=>"...", stmt_block=>$item{StatementBlock});
        $return = $node;
    }
#{ $return = "CATCH ARBITRARY EXEC { ".$item{StatementBlock}." }"; }
| <error?> <error>

ParsedCatches : .../catch\b/ <commit> ParsedCatch ParsedCatches
    {
        my $node = Mace::Compiler::ParseTreeObject::ParsedCatches->new(type=>"catch", parsed_catch=>$item{ParsedCatch}, parsed_catchs=>$item{ParsedCatchs});
        $return = $node;
    }
#{ $return = $item{ParsedCatch} . ( $item{ParsedCatches} ne "" ? " ".$item{ParsedCatches} : ""); }
| <error?> <reject>
|
    {
        my $node = Mace::Compiler::ParseTreeObject::ParsedCatches->new(type=>"null");
        $return = $node;
    }
#| { $return = "" }

ParsedTryCatch : 'try' <commit> '{' StatementBlock '}' .../catch\b/ ParsedCatches
    {
        my $node = Mace::Compiler::ParseTreeObject::ParsedTryCatch->new(stmt_block=>$item{StatementBlock}, parsed_catchs=>$item{ParsedCatchs});
        $return = $node;
    }
#{ $return = "TRY/CATCH : EXEC { ".$item{StatementBlock}." } ".$item{ParsedCatches}; }
| <error>

StatementOrBraceBlock : '{' <commit> StatementBlock '}'
    {
        my $node = Mace::Compiler::ParseTreeObject::StatementOrBraceBlock->new(type=>"statement_block", stmt_block=>$item{StatementBlock});
#        if( ref($item{StatementBlock}) ne "" ) {
#            print "StatementOrBraceBlock[o]: ".$item{StatementBlock}->toString()."\n";
#        } else {
#            print "StatementOrBraceBlock[s]: $item{StatementBlock}\n";
#        }
        $return = $node;
    }
| SemiStatement
    {
        my $node = Mace::Compiler::ParseTreeObject::StatementOrBraceBlock->new(type=>"semi_statement", semi_stmt=>$item{SemiStatement});
#        if( ref($item{Expression}) ne "" ) {
#            print "StatementOrBraceBlock[o]: ".$item{SemiStatement}->toString()."\n";
#        } else {
#            print "StatementOrBraceBlock[s]: $item{SemiStatement}\n";
#        }
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
            $node->semi_statements(@{$item[1]});
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
    {
        my $node = Mace::Compiler::ParseTreeObject::SemiStatement->new(type=>"parsed_for_loop", parsed_for_loop=>$item{ParsedForLoop});
        print "SemiStatement[ParsedForLoop]: ".$node->toString()."\n";
        $return = $node;
    }
| .../do\b/ <commit> ParsedDoWhile
    {
        my $node = Mace::Compiler::ParseTreeObject::SemiStatement->new(type=>"parsed_do_while", parsed_do_while=>$item{ParsedDoWhile});
        print "SemiStatement[ParsedDoWhile]: ".$node->toString()."\n";
        $return = $node;
    }
| .../while\b/ <commit> ParsedWhile
    {
        my $node = Mace::Compiler::ParseTreeObject::SemiStatement->new(type=>"parsed_while", parsed_while=>$item{ParsedWhile});
        print "SemiStatement[ParsedWhile]: ".$node->toString()."\n";
        $return = $node;
    }
| ...OutputStream <commit> ParsedLogging
    {
        my $node = Mace::Compiler::ParseTreeObject::SemiStatement->new(type=>"parsed_logging", parsed_logging=>$item{ParsedLogging});
        print "SemiStatement[ParsedLogging]: ".$node->toString()."\n";
        $return = $node;
    }
| .../switch\b/ <commit> ParsedSwitch
    {
        my $node = Mace::Compiler::ParseTreeObject::SemiStatement->new(type=>"parsed_switch", parsed_switch=>$item{ParsedSwitch});
        print "SemiStatement[ParsedSwitch]: ".$node->toString()."\n";
        $return = $node;
    }
| .../try\b/ <commit> ParsedTryCatch
    {
        my $node = Mace::Compiler::ParseTreeObject::SemiStatement->new(type=>"parsed_try_catch", parsed_try_catch=>$item{ParsedTryCatch});
        print "SemiStatement[ParsedTryCatch]: ".$node->toString()."\n";
        $return = $node;
    }
| .../#/ <commit> ParsedMacro
    {
        my $node = Mace::Compiler::ParseTreeObject::SemiStatement->new(type=>"parsed_macro", parsed_macro=>$item{ParsedMacro});
        print "SemiStatement[ParsedMacro]: ".$node->toString()."\n";
        $return = $node;
    }
| .../EXPECT\b/ <commit> ParsedExpectStatement
    {
        my $node = Mace::Compiler::ParseTreeObject::SemiStatement->new(type=>"parsed_expect_stmt", parsed_expect_stmt=>$item{ParsedExpectStatement});
        print "SemiStatement[ParsedExpectStatement]: ".$node->toString()."\n";
        $return = $node;
    }
| .../ASSERTMSG\b/ <commit> ParsedAssertMsg
    {
        my $node = Mace::Compiler::ParseTreeObject::SemiStatement->new(type=>"parsed_assert_msg", parsed_assert_msg=>$item{ParsedAssertMsg});
        print "SemiStatement[ParsedAssertMsg]: ".$node->toString()."\n";
        $return = $node;
    }
| .../ASSERT\b/ <commit> ParsedAssert
    {
        my $node = Mace::Compiler::ParseTreeObject::SemiStatement->new(type=>"parsed_assert", parsed_assert=>$item{ParsedAssert});
        print "SemiStatement[ParsedAssert]: ".$node->toString()."\n";
        $return = $node;
    }
| .../ABORT\b/ <commit> ParsedAbort
    {
        my $node = Mace::Compiler::ParseTreeObject::SemiStatement->new(type=>"parsed_abort", parsed_abort=>$item{ParsedAbort});
        print "SemiStatement[ParsedAbort]: ".$node->toString()."\n";
        $return = $node;
    }
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
| ParsedFCall ';' #{ $return = $item[1]; }
    {
        my $node = Mace::Compiler::ParseTreeObject::SemiStatement->new(type=>"parsed_fcall", parsed_fcall=>$item{ParsedFCall});
        print "SemiStatement[ParsedFCall]: ".$node->toString()."\n";
        $return = $node;
    }
| ParsedBinaryAssignOp[semi=>1] #{ $return = $item[1]; }
    {
        my $node = Mace::Compiler::ParseTreeObject::SemiStatement->new(type=>"parsed_binary_assign_op", parsed_binary_assign_op=>$item{ParsedBinaryAssignOp});
        print "SemiStatement[ParsedBinaryAssignOp]: ".$node->toString()."\n";
        $return = $node;
    }
| ParsedPlusPlus ';' #{ $return = $item[1]; }
    {
        my $node = Mace::Compiler::ParseTreeObject::SemiStatement->new(type=>"parsed_plus_plus", parsed_plus_plus=>$item{ParsedPlusPlus});
        print "SemiStatement[ParsedPlusPlus]: ".$node->toString()."\n";
        $return = $node;
    }
| ParsedControlFlow ';' #{ $return = $item[1]; }
    {
        my $node = Mace::Compiler::ParseTreeObject::SemiStatement->new(type=>"parsed_control_flow", parsed_control_flow=>$item{ParsedControlFlow});
        print "SemiStatement[ParsedControlFlow]: ".$node->toString()."\n";
        $return = $node;
    }
| ParsedOutput
    {
        my $node = Mace::Compiler::ParseTreeObject::SemiStatement->new(type=>"parsed_output", parsed_output=>$item{ParsedOutput});
        print "SemiStatement[ParsedOutput]: ".$node->toString()."\n";
        $return = $node;
    }
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

#    for my $statement (@{$item{BraceBlockFoo}}) {
#        print "PARSED STATEMENT: $statement\n";
#    }

#
    if(defined($arg{methodName})) 
    {
        print "| ".$arg{methodName}." {\n";
        print $item{BraceBlock}->toString()."\n";
        print "| }\n";
        print "|\n";
    } else {
        print "| Undefined {\n";
        print $item{BraceBlock}->toString()."\n";
        print "| }\n";
        print "|\n";
    }

    # FIXME(shyoo) : $return should be replaced with $item{BraceBlock}->toString().

    $return = $item{BraceBlock}->toString();

#    $return = $startline.substr($Mace::Compiler::Grammar::text, $item{StartPos},
#		     1 + $item{EndPos} - $item{StartPos}).$endline;
}
| '=' '0' ';' { $return = "0" }
| ';' { $return = "" }
| <reject:!$arg{forceColon}> ':' { $return = "" }

Expression : Expression1
#Expression : StartPos Expression1 EndPos
    {
        $return = Mace::Compiler::ParseTreeObject::Expression->new(expr1=>$item{Expression1});
#    my $node = Mace::Compiler::ParseTreeObject::Expression->new();
#    $node->expr(substr($Mace::Compiler::Grammar::text, $item{StartPos}, 1 + $item{EndPos} - $item{StartPos}));
#    $return = $node;

#    $return = substr($Mace::Compiler::Grammar::text, $item{StartPos},
#		     1 + $item{EndPos} - $item{StartPos});
    }

AssignBinaryOp1 : '+=' | '-=' | '<<=' | '>>=' | '|=' | '&=' | '=' ...!'=' | '%=' | <error>

AssignBinaryOp : StartPos AssignBinaryOp1 EndPos
{ 
    $return = substr($Mace::Compiler::Grammar::text, $item{StartPos},
             1 + $item{EndPos} - $item{StartPos});
}

PrePostAssignOp : '++' | '--' | <error>

BinaryOp : '*' | '/' | '+' ...!/[+=]/ | '<<' ...!'=' | '>>' ...!'=' | '!=' | '==' | '<=' | '>=' | '<' | '>' | '||' | '|' | '&&' | '&' | '^' | '.' | '->' | '-' ...!/[-=]/ | '%' ...!'=' | <error>

UnaryOp : '!' | '~' | '*' | '&' | 'new' | 'delete' | <error>

# Assume - operators have usual conventions on r/w (+, -, ++, +=, ...)

ExpressionOrAssignLValue : StartPos ExpressionOrAssignLValue1 EndPos
    {
        $return = Mace::Compiler::ParseTreeObject::ExpressionOrAssignLValue->new(expr_or_assign_lvalue1=>$item{ExpressionOrAssignLValue1});
#        $return = Mace::Compiler::ParseTreeObject::ExpressionOrAssignLValue->new(expr_or_assign_lvalue1_scalar=>substr($Mace::Compiler::Grammar::text, $item{StartPos}, 1 + $item{EndPos} - $item{StartPos}));
    }
#{ 
#    $return = substr($Mace::Compiler::Grammar::text, $item{StartPos},
#		     1 + $item{EndPos} - $item{StartPos});
#}


ExpressionOrAssignLValue1 : ExpressionLValue1 PrePostAssignOp 
    {
        $return = Mace::Compiler::ParseTreeObject::ExpressionOrAssignLValue1->new(type=>"post_op", expr_lvalue1=>$item{ExpressionLValue1}, prepost_assign_op=>$item{PrePostAssignOp});
    }
| PrePostAssignOp ExpressionLValue1 
    {
        $return = Mace::Compiler::ParseTreeObject::ExpressionOrAssignLValue1->new(type=>"pre_op", prepost_assign_op=>$item{PrePostAssignOp}, expr_lvalue1=>$item{ExpressionLValue1});
    }
| ExpressionLValue1 AssignBinaryOp Expression1 
    {
        $return = Mace::Compiler::ParseTreeObject::ExpressionOrAssignLValue1->new(type=>"assign_op", expr_lvalue1=>$item{ExpressionLValue1}, assign_binary_op=>$item{AssignBinaryOp}, expr1=>$item{Expression1});
    }
| ExpressionLValue1 
    {
        $return = Mace::Compiler::ParseTreeObject::ExpressionOrAssignLValue1->new(type=>"expr_lvalue1", expr_lvalue1=>$item{ExpressionLValue1});
    }
| <error>

ExpressionLValue : 
# StartPos ExpressionLValue1 EndPos <reject: (not $arg{parseFunctionCall}) or ($item{ExpressionLValue1} eq "FUNCTION_CALL")> { print "ERR (FC): ".substr($Mace::Compiler::Grammar::text, $item{StartPos}, 1 + $item{EndPos} - $item{StartPos})."\n"; } <error: Expecting function and not function, but parsed expression.>
#| 
StartPos ExpressionLValue1 EndPos <commit> <reject: $arg{parseFunctionCall} and not ($item{ExpressionLValue1}->getRef() eq "FUNCTION_CALL")>
    {
        #print "ExpressionLValue1->getRef() : ".$item{ExpressionLValue1}->getRef()."\n";
        my $node = Mace::Compiler::ParseTreeObject::ExpressionLValue->new(expr_lvalue1=>$item{ExpressionLValue1});
        $return = $node;
    }
#{
#    $return = substr($Mace::Compiler::Grammar::text, $item{StartPos},
#		     1 + $item{EndPos} - $item{StartPos});
#    # if ($arg{parseFunctionCall} && ! ($item{ExpressionLValue1} eq "FUNCTION_CALL")) {
#    #     print "Expression $return parsed, but not recognized as a function call!\n";
#    #     $return = undef;
#    # }
#}
| <error?: Parsed Expression LValue, but Required Function Call> <error>

ExpressionLValue1 : ExpressionLValue2 '.' <commit> ExpressionLValue1
    {
        #print "ExpressionLValue1: ".$item{ExpressionLValue2}->toString()." . ".$item[-1]->toString()."\n";
        $return = Mace::Compiler::ParseTreeObject::ExpressionLValue1->new(type=>"dot", expr_lvalue2=>$item{ExpressionLValue2}, expr_lvalue1=>$item[-1]);
    }
| '*' <commit> ExpressionLValue1
    {
        $return = Mace::Compiler::ParseTreeObject::ExpressionLValue1->new(type=>"star", expr_lvalue1=>$item[-1]);
    }
| ExpressionLValue2 '->' <commit> ExpressionLValue1
    {
        $return = Mace::Compiler::ParseTreeObject::ExpressionLValue1->new(type=>"arrow", expr_lvalue2=>$item{ExpressionLValue2}, expr_lvalue1=>$item[-1]);
    }
| ExpressionLValue2 '?' <commit> ExpressionLValue1 ':' ExpressionLValue1
    {
        $return = Mace::Compiler::ParseTreeObject::ExpressionLValue1->new(type=>"question", expr_lvalue2=>$item{ExpressionLValue2}, expr_lvalue1a=>$item[-3], expr_lvalue1b=>$item[-1] );
    }
| ExpressionLValue2
    {
        $return = Mace::Compiler::ParseTreeObject::ExpressionLValue1->new(type=>"expr_lvalue2", expr_lvalue2=>$item{ExpressionLValue2});
    }
| <error>
#ExpressionLValue1 : ExpressionLValue2 '.' <commit> ExpressionLValue1
#| '*' <commit> ExpressionLValue1
#| ExpressionLValue2 '->' <commit> ExpressionLValue1
#| ExpressionLValue2 '?' <commit> ExpressionLValue1 ':' ExpressionLValue1
#| ExpressionLValue2
#| <error>

ArrayIndex : '[' <commit> Expression1 ']'
    {
        $return = Mace::Compiler::ParseTreeObject::ArrayIndex->new(expr1=>$item{Expression1});
    }
| <error>

ExpressionLValue2: <reject>
#| ScopedId ( '[' <commit> Expression1 ']' )(s)
| ScopedId ...'[' ArrayIndex(s)
    {
        my $node = Mace::Compiler::ParseTreeObject::ExpressionLValue2->new(type=>"array", scoped_id=>$item{ScopedId});
        $node->array_index(@{$item[3]});
        print "ExpressionLValue2[ARRAY]: ".$node->toString()."\n";
        $return = $node;
    }
| ScopedId '(' Expression1(s? /,/) ')'# { $return = "FUNCTION_CALL"; }
    {
        my $node = Mace::Compiler::ParseTreeObject::ExpressionLValue2->new(type=>"fcall", scoped_id=>$item{ScopedId});

        $node->not_null_expr1(scalar(@{$item[3]}));

        if (scalar(@{$item[3]})) {
            $node->expr1(@{$item[3]});
        }
        print "ExpressionLValue2[F-CALL]: ".$node->toString()."\n";
        $return = $node;
    }
| ScopedId '(' <commit> ExpressionOrAssignLValue1(s /,/) ')'# { $return = "FUNCTION_CALL"; }
    {
        my $node = Mace::Compiler::ParseTreeObject::ExpressionLValue2->new(type=>"fcall_assign", scoped_id=>$item{ScopedId}, expr_or_assign_lvalue1=>@{$item[-2]} );
        print "ExpressionLValue2[F-CALL]: ".$node->toString()."\n";
        $return = $node;
    }
| ScopedId
    {
        $return = Mace::Compiler::ParseTreeObject::ExpressionLValue2->new(type=>"scoped_id", scoped_id=>$item{ScopedId});
    }
| <error>
#ExpressionLValue2: <reject>
#| ScopedId ( '[' <commit> Expression1 ']' )(s)
#| ScopedId '(' Expression1(s? /,/) ')' { $return = "FUNCTION_CALL"; }
#| ScopedId '(' <commit> ExpressionOrAssignLValue1(s /,/) ')' { $return = "FUNCTION_CALL"; }
#| ScopedId
#| <error>


#Changed to Expression1 to allow unary operators before things like my.foo
Expression1 : UnaryOp <commit> Expression1
    {
        $return = Mace::Compiler::ParseTreeObject::Expression1->new(type=>"unary_op", unary_op=>$item{UnaryOp}, expr1=>$item{Expression1} );
#        print "Expression1[unary_op] : ".$return->toString()."\n";
    }
| Expression2 BinaryOp <commit> Expression1
    {
        $return = Mace::Compiler::ParseTreeObject::Expression1->new(type=>"binary_op", expr2=>$item{Expression2}, binary_op=>$item{BinaryOp}, expr1=>$item{Expression1} );
#        print "Expression1[binary_op] : ".$return->toString()."\n";
    }
| Expression2 '?' <commit> Expression1 ':' Expression1
    {
        $return = Mace::Compiler::ParseTreeObject::Expression1->new(type=>"question", expr2=>$item{Expression2}, expr1=>$item[-3], expr1a=>$item[-1] );
#        print "Expression1[question] : ".$return->toString()."\n";
    }
| Expression2
    {
        $return = Mace::Compiler::ParseTreeObject::Expression1->new(type=>"expr2", expr2=>$item{Expression2} );
#        print "Expression1[expr2] : ".$return->toString()."\n";
    }
| <error>
#Expression1 : UnaryOp <commit> Expression1
#| Expression2 BinaryOp <commit> Expression1
#| Expression2 '?' <commit> Expression1 ':' Expression1
#| Expression2
#| <error>

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
    {
        my $node = Mace::Compiler::ParseTreeObject::ArrayIndOrFunction->new(type=>"func");

        $node->not_null_expr1_list(scalar(@{$item[2]}));

        if (scalar(@{$item[2]})) {
            $node->expr1_list(@{$item[2]});
        }
        $return = $node;
    }
| '[' Expression1 ']'
    {
        $return = Mace::Compiler::ParseTreeObject::ArrayIndOrFunction->new(type=>"array", expr1=>$item{Expression1});
    }
| <error>

ArrayIndOrFunctionParts : ...ParenOrBrace <commit> ArrayIndOrFunction ArrayIndOrFunctionParts
    {
        $return = Mace::Compiler::ParseTreeObject::ArrayIndOrFunctionParts->new(not_null=>1, array_ind_or_function=>$item{ArrayIndOrFunction}, array_ind_or_function_parts=>$item{ArrayIndOrFunctionParts});
    }
| <error?> <reject>
| 
    {   
        $return = Mace::Compiler::ParseTreeObject::ArrayIndOrFunctionParts->new(not_null=>0);
    }

Expression2 : Number
    {
        $return = Mace::Compiler::ParseTreeObject::Expression2->new(type=>"number", number=>$item{Number} );
    }
| ScopedId ...ParenOrBrace <commit> ArrayIndOrFunctionParts
    {
        $return = Mace::Compiler::ParseTreeObject::Expression2->new(type=>"array_func", scoped_id=>$item{ScopedId}, array_ind_or_function_parts=>$item{ArrayIndOrFunctionParts} );
    }
| ..."'" <commit> "'" /[^\']*/ "'"
    {
        $return = Mace::Compiler::ParseTreeObject::Expression2->new(type=>"string", string=>$item[-2] );
    }
| ...'"' <commit> QuotedString
    {
        $return = Mace::Compiler::ParseTreeObject::Expression2->new(type=>"quoted_string", quoted_string=>$item[-1] );
    }
| '(' Type ')' Expression1
    {
        $return = Mace::Compiler::ParseTreeObject::Expression2->new(type=>"typecast", typecast=>$item{Type}, expr1=>$item{Expression1} );
    }
| '(' <commit> Expression1 ')'
    {
        $return = Mace::Compiler::ParseTreeObject::Expression2->new(type=>"expr1", expr1=>$item{Expression1} );
    }
| ScopedId
    {
        $return = Mace::Compiler::ParseTreeObject::Expression2->new(type=>"scoped_id", scoped_id=>$item{ScopedId} );
    }
| <error>
#Expression2 : Number
#| ScopedId ...ParenOrBrace <commit> ArrayIndOrFunctionParts
#| ..."'" <commit> "'" /[^\']*/ "'"
#| ...'"' <commit> QuotedString
#| '(' Type ')' Expression1
#| '(' <commit> Expression1 ')'
#| ScopedId
#| <error>

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
                                       default => $item{ExpressionOrAssignLValue}->toString());
#                                       default => $item{ExpressionOrAssignLValue});
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
                                       default => $item{Type}->type()."(".join(", ",map { $_->toString() } @{$item[-3]}).")");
#                                       default => $item{Type}->type()."(".join(", ", @{$item[-3]}).")");
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
                                       default => $item{Type}->type()."(".join(", ", map { $_->toString() } @{$item[-3]}).")");
#                                       default => $item{Type}->type()."(".join(", ", @{$item[-3]}).")");
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

Method : StaticToken(?) <reject:!$arg{staticOk} and scalar(@{$item[1]})> MethodReturnType[%arg] MethodName FileLineEnd '(' Parameter[%arg](s? /,/) ')' ConstToken(?) Throws(?) MethodOptions(?) MethodTerm[forceColon => $arg{forceColon}, methodName => $item{MethodName}]
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
ScopedId : StartPos TemplateTypeId ('::' TemplateTypeId)(s?) EndPos 
    {
        my $node = Mace::Compiler::ParseTreeObject::ScopedId->new(val=>substr($Mace::Compiler::Grammar::text, $item{StartPos}, 1 + $item{EndPos} - $item{StartPos}));
        $return = $node;
    }
#{ $return = substr($Mace::Compiler::Grammar::text, $item{StartPos}, 1 + $item{EndPos} - $item{StartPos}); }
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
