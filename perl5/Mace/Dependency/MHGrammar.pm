package Mace::Dependency::MHGrammar;

use strict;

use constant MH => q[

NonServiceClassLine : ...!'serviceclass' /.*?\n/ 

NonHandlerLine : ...!'handlers' /.*?\n/ 

Id : /[_a-zA-Z][a-zA-Z0-9_]*/

IdCommaList : Id(s /,/)

ServiceClassExtend : ':' <commit> IdCommaList
{
    $return = $item{IdCommaList};
}
| { $return = []; }

Handlers : 'handlers' IdCommaList ';' 
{
    $return = $item{IdCommaList};
}
| { $return = []; }

ServiceClassBody : 'serviceclass' Id ServiceClassExtend '{' NonHandlerLine(s?) Handlers
{
    if (scalar(@{$item{ServiceClassExtend}}) or scalar(@{$item{Handlers}})) {
        $arg{vars}->{$item{Id}."ServiceClass_dep"} = "SET(".$item{Id}."ServiceClass_dep \${".$item{Id}."ServiceClass_h} \${ServiceClass_h}" .
             join('', map {" \${${_}ServiceClass_dep}"} @{$item{ServiceClassExtend}}) .
             join('', map {" \${${_}Handler_dep}"} @{$item{Handlers}}) .
             ")\n";
    }
}

ServiceClass : <skip: qr{\s* ((/[*] .*? [*]/|(//[^\n]*\n)|([#]line \s* \d+ \s* ["][^"\r\n]+["])) \s*)*}sx> NonServiceClassLine(s?) ServiceClassBody[%arg](?)

];

1;
