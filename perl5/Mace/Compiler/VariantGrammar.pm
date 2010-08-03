package Mace::Compiler::VariantGrammar;

use strict;
use Mace::Compiler::Grammar;
use Mace::Compiler::CommonGrammar;

use constant VARIANT => Mace::Compiler::CommonGrammar::COMMON . q[

VariantsKeyword : /\bvariants\b/ 

Variants : /\bvariants\b/ Id(s /,/) ';' { push(@{$thisparser->{local}{variants}}, @{$item[2]}); }

CopyLookaheadStringLine : FileLine CopyLookaheadString[rule=>$arg{rule}]
{
    $return = "";
    if ($item{CopyLookaheadString} ne "") {
        $return .= "#line ".($item{FileLine}->[0])." \"".$item{FileLine}->[1]."\"\n";
        $return .= $item{CopyLookaheadString};
    }
}

Preamble : CopyLookaheadStringLine[rule=>'VariantsKeyword'] Variants 
{
    $thisparser->{local}{preamble} = $item{CopyLookaheadStringLine} . "\n";
    my $svname = $thisparser->{local}{servicename};
    for my $variant (@{$thisparser->{local}{variants}}) {

        my $preamble = $thisparser->{local}{preamble};
        $preamble =~ s/service\s+$svname\s*;/service $variant;/s;

        if (not defined $thisparser->{local}{linemap}->[$thisline]) {
            print "ERROR at line $thisline\n";
        }

        $thisparser->{local}{"variant:$variant"} = $preamble;
        $thisparser->{local}{"variant:$variant"} .= "#line ".($thisparser->{local}{linemap}->[$thisline])." \"".$thisparser->{local}{filemap}->[$thisline].qq/"\n/;
    }
}
| <error>

VariantFile : <skip: qr{(\xef\xbb\xbf)?\s* ((/[*] .*? [*]/|(//[^\n]*\n)|([#]line \s* \d+ \s* ["][^"\r\n]+["])) \s*)*}sx>
    {
        $thisparser->{local}{servicename} = $arg[0];
        $thisparser->{local}{variants} = [ $arg[0] ];
    }
    Preamble Block(s) StartPos 
    {
        $return = $thisparser->{local}{variants};
    }
| 
    {
        my $lastLine = "";
        my $lastMsg = "";
        for my $i (@{$thisparser->{errors}}) {
            if ($i->[1] ne $lastLine || $i->[0] ne $lastMsg) {
                Mace::Compiler::Globals::error('invalid syntax', $thisparser->{local}{filemap}->[$i->[1]], $thisparser->{local}{linemap}->[$i->[1]], $i->[0]);
                $lastLine = $i->[1];
                $lastMsg = $i->[0];
            }
        }
        $thisparser->{errors} = undef;
    }

Block : VariantBlock | CopyBlock

CopyBlock : CopyLookaheadStringLine[rule=>'VariantList'] 
{
    for my $variant (@{$thisparser->{local}{variants}}) {
        $thisparser->{local}{"variant:$variant"} .= $item{CopyLookaheadStringLine} . "\n";
    }
}

VariantList : /\bvariant/ '<' Id(s /,/) '>' { $return = $item[3]; }

VariantBlock : VariantList '{' StartPos FileLine SemiStatement(s?) EndPos '}' 
{
    my $subst = substr($Mace::Compiler::Grammar::text, $item{StartPos}, 1 + $item{EndPos} - $item{StartPos});
    for my $variant (@{$item{VariantList}}) {
        $thisparser->{local}{"variant:$variant"} .= "\n#line ".($item{FileLine}->[0])." \"".$item{FileLine}->[1]."\"\n";
        $thisparser->{local}{"variant:$variant"} .= $subst . "\n";
    }
}

GetVariant : {
    $return = $thisparser->{local}{"variant:".$arg[0]};
}

]; # VARIANT grammar

1;
