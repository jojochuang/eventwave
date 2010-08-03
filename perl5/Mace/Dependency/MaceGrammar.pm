package Mace::Dependency::MaceGrammar;

use strict;

use constant MACE => q[

MaceService: <skip: qr{\s* ((/[*] .*? [*]/|(//[^\n]*\n)|([#]line \s* \d+ \s* ["][^"\r\n]+["])) \s*)*}sx> NonProvidesLine(s?) Provides NonServiceLine(s?) ServiceBlock
{
    my @vars;
    if (scalar(@{$item{Provides}}) or scalar(@{$item{ServiceBlock}})) {
        $arg{vars}->{$arg{name}."Service_dep"} = "SET(".$arg{name}."Service_dep \${ServiceClass_h}" .
               join('', map {" \${${_}ServiceClass_dep}"} @{$item{Provides}}) . 
               join('', map {" \${".@{${_}}[0]."ServiceClass_dep}"} @{$item{ServiceBlock}}) .
               ")\n";
        $arg{vars}->{$arg{name}."Service_tgt_dep"} = "SET(".$arg{name}."Service_tgt_dep ServiceClass_dep" .
               join('', map {" ${_}ServiceClass_dep"} @{$item{Provides}}) . 
               join('', map {" ".@{${_}}[0]."ServiceClass_dep"} @{$item{ServiceBlock}}) . 
               ")\n";
    }
    $arg{vars}->{$arg{name}."Service_sv_dep"} = "SET(".$arg{name}."Service_sv_dep ".$arg{name} .
           join('', map {" \${".@{${_}}[1]."Service_sv_dep}"} @{$item{ServiceBlock}}) .
           ")\n";
    $arg{vars}->{$arg{name}."Service_sv_list"} = "SET(".$arg{name}."Service_sv_list ".
           join('', map {" ".@{${_}}[1]} @{$item{ServiceBlock}}) .
           ")\n";
    $return = 1;
}

ProvidesOrService : 'provides' | 'services'
NonProvidesLine : ...!ProvidesOrService /.*?\n/ 

Provides : 'provides' IdCommaList ';'
{
    $return = $item{IdCommaList};
}
| { $return = []; }

NonServiceLine : ...!'services' /.*?\n/ 

ServiceBlock : 'services' '{' ServiceList 
{
    $return = $item{ServiceList}
}
| { $return = []; }


Id : /[_a-zA-Z][a-zA-Z0-9_]*/
IdCommaList : Id(s /,/)

InlineFinal : 'inline' | 'final' | 
ServiceDefault : Id '(' /[^;]*;/ 
{
    $return = $item{Id}
} 
| Id /[^;]*;/ { $return = ""; }
ServiceItem : InlineFinal Id /[^=;]*=/ ServiceDefault
{
    $return = [ $item{Id}, $item{ServiceDefault}];
}
| InlineFinal Id /[^;]*;/
{
    $return = [ $item{Id}, "" ];
}
ServiceList : ServiceItem(s?)

];

1;
