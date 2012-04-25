package Mace::Dependency::MaceHeaderDependencyRecDescent;
use Parse::RecDescent;

{ my $ERRORS;


package Parse::RecDescent::Mace::Dependency::MaceHeaderDependencyRecDescent;
use strict;
use vars qw($skip $AUTOLOAD  );
@Parse::RecDescent::Mace::Dependency::MaceHeaderDependencyRecDescent::ISA = ();
$skip = '\s*';


{
local $SIG{__WARN__} = sub {0};
# PRETEND TO BE IN Parse::RecDescent NAMESPACE
*Parse::RecDescent::Mace::Dependency::MaceHeaderDependencyRecDescent::AUTOLOAD   = sub
{
    no strict 'refs';
    $AUTOLOAD =~ s/^Parse::RecDescent::Mace::Dependency::MaceHeaderDependencyRecDescent/Parse::RecDescent/;
    goto &{$AUTOLOAD};
}
}

push @Parse::RecDescent::Mace::Dependency::MaceHeaderDependencyRecDescent::ISA, 'Parse::RecDescent';
# ARGS ARE: ($parser, $text; $repeating, $_noactions, \@args)
sub Parse::RecDescent::Mace::Dependency::MaceHeaderDependencyRecDescent::Id
{
	my $thisparser = $_[0];
	use vars q{$tracelevel};
	local $tracelevel = ($tracelevel||0)+1;
	$ERRORS = 0;
    my $thisrule = $thisparser->{"rules"}{"Id"};
    
    Parse::RecDescent::_trace(q{Trying rule: [Id]},
                  Parse::RecDescent::_tracefirst($_[1]),
                  q{Id},
                  $tracelevel)
                    if defined $::RD_TRACE;

    
    my $err_at = @{$thisparser->{errors}};

    my $score;
    my $score_return;
    my $_tok;
    my $return = undef;
    my $_matched=0;
    my $commit=0;
    my @item = ();
    my %item = ();
    my $repeating =  defined($_[2]) && $_[2];
    my $_noactions = defined($_[3]) && $_[3];
    my @arg =    defined $_[4] ? @{ &{$_[4]} } : ();
    my %arg =    ($#arg & 01) ? @arg : (@arg, undef);
    my $text;
    my $lastsep="";
    my $expectation = new Parse::RecDescent::Expectation(q{/[_a-zA-Z][a-zA-Z0-9_]*/});
    $expectation->at($_[1]);
    
    my $thisline;
    tie $thisline, q{Parse::RecDescent::LineCounter}, \$text, $thisparser;

    

    while (!$_matched && !$commit)
    {
        
        Parse::RecDescent::_trace(q{Trying production: [/[_a-zA-Z][a-zA-Z0-9_]*/]},
                      Parse::RecDescent::_tracefirst($_[1]),
                      q{Id},
                      $tracelevel)
                        if defined $::RD_TRACE;
        my $thisprod = $thisrule->{"prods"}[0];
        $text = $_[1];
        my $_savetext;
        @item = (q{Id});
        %item = (__RULE__ => q{Id});
        my $repcount = 0;


        Parse::RecDescent::_trace(q{Trying terminal: [/[_a-zA-Z][a-zA-Z0-9_]*/]}, Parse::RecDescent::_tracefirst($text),
                      q{Id},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $lastsep = "";
        $expectation->is(q{})->at($text);
        

        unless ($text =~ s/\A($skip)/$lastsep=$1 and ""/e and   $text =~ s/\A(?:[_a-zA-Z][a-zA-Z0-9_]*)//)
        {
            
            $expectation->failed();
            Parse::RecDescent::_trace(q{<<Didn't match terminal>>},
                          Parse::RecDescent::_tracefirst($text))
                    if defined $::RD_TRACE;

            last;
        }
        Parse::RecDescent::_trace(q{>>Matched terminal<< (return value: [}
                        . $& . q{])},
                          Parse::RecDescent::_tracefirst($text))
                    if defined $::RD_TRACE;
        push @item, $item{__PATTERN1__}=$&;
        


        Parse::RecDescent::_trace(q{>>Matched production: [/[_a-zA-Z][a-zA-Z0-9_]*/]<<},
                      Parse::RecDescent::_tracefirst($text),
                      q{Id},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $_matched = 1;
        last;
    }


    unless ( $_matched || defined($score) )
    {
        

        $_[1] = $text;  # NOT SURE THIS IS NEEDED
        Parse::RecDescent::_trace(q{<<Didn't match rule>>},
                     Parse::RecDescent::_tracefirst($_[1]),
                     q{Id},
                     $tracelevel)
                    if defined $::RD_TRACE;
        return undef;
    }
    if (!defined($return) && defined($score))
    {
        Parse::RecDescent::_trace(q{>>Accepted scored production<<}, "",
                      q{Id},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $return = $score_return;
    }
    splice @{$thisparser->{errors}}, $err_at;
    $return = $item[$#item] unless defined $return;
    if (defined $::RD_TRACE)
    {
        Parse::RecDescent::_trace(q{>>Matched rule<< (return value: [} .
                      $return . q{])}, "",
                      q{Id},
                      $tracelevel);
        Parse::RecDescent::_trace(q{(consumed: [} .
                      Parse::RecDescent::_tracemax(substr($_[1],0,-length($text))) . q{])}, 
                      Parse::RecDescent::_tracefirst($text),
                      , q{Id},
                      $tracelevel)
    }
    $_[1] = $text;
    return $return;
}

# ARGS ARE: ($parser, $text; $repeating, $_noactions, \@args)
sub Parse::RecDescent::Mace::Dependency::MaceHeaderDependencyRecDescent::ServiceClass
{
	my $thisparser = $_[0];
	use vars q{$tracelevel};
	local $tracelevel = ($tracelevel||0)+1;
	$ERRORS = 0;
    my $thisrule = $thisparser->{"rules"}{"ServiceClass"};
    
    Parse::RecDescent::_trace(q{Trying rule: [ServiceClass]},
                  Parse::RecDescent::_tracefirst($_[1]),
                  q{ServiceClass},
                  $tracelevel)
                    if defined $::RD_TRACE;

    
    my $err_at = @{$thisparser->{errors}};

    my $score;
    my $score_return;
    my $_tok;
    my $return = undef;
    my $_matched=0;
    my $commit=0;
    my @item = ();
    my %item = ();
    my $repeating =  defined($_[2]) && $_[2];
    my $_noactions = defined($_[3]) && $_[3];
    my @arg =    defined $_[4] ? @{ &{$_[4]} } : ();
    my %arg =    ($#arg & 01) ? @arg : (@arg, undef);
    my $text;
    my $lastsep="";
    my $expectation = new Parse::RecDescent::Expectation(q{});
    $expectation->at($_[1]);
    
    my $thisline;
    tie $thisline, q{Parse::RecDescent::LineCounter}, \$text, $thisparser;

    

    while (!$_matched && !$commit)
    {
        local $skip = defined($skip) ? $skip : $Parse::RecDescent::skip;
        Parse::RecDescent::_trace(q{Trying production: [<skip: qr{\s* ((/[*] .*? [*]/|(//[^\n]*\n)|([#]line \s* \d+ \s* ["][^"\r\n]+["])) \s*)*}sx> NonServiceClassLine ServiceClassBody]},
                      Parse::RecDescent::_tracefirst($_[1]),
                      q{ServiceClass},
                      $tracelevel)
                        if defined $::RD_TRACE;
        my $thisprod = $thisrule->{"prods"}[0];
        $text = $_[1];
        my $_savetext;
        @item = (q{ServiceClass});
        %item = (__RULE__ => q{ServiceClass});
        my $repcount = 0;


        

        Parse::RecDescent::_trace(q{Trying directive: [<skip: qr{\s* ((/[*] .*? [*]/|(//[^\n]*\n)|([#]line \s* \d+ \s* ["][^"\r\n]+["])) \s*)*}sx>]},
                    Parse::RecDescent::_tracefirst($text),
                      q{ServiceClass},
                      $tracelevel)
                        if defined $::RD_TRACE; 
        $_tok = do { my $oldskip = $skip; $skip= qr{\s* ((/[*] .*? [*]/|(//[^\n]*\n)|([#]line \s* \d+ \s* ["][^"\r\n]+["])) \s*)*}sx; $oldskip };
        if (defined($_tok))
        {
            Parse::RecDescent::_trace(q{>>Matched directive<< (return value: [}
                        . $_tok . q{])},
                        Parse::RecDescent::_tracefirst($text))
                            if defined $::RD_TRACE;
        }
        else
        {
            Parse::RecDescent::_trace(q{<<Didn't match directive>>},
                        Parse::RecDescent::_tracefirst($text))
                            if defined $::RD_TRACE;
        }
        
        last unless defined $_tok;
        push @item, $item{__DIRECTIVE1__}=$_tok;
        

        Parse::RecDescent::_trace(q{Trying repeated subrule: [NonServiceClassLine]},
                  Parse::RecDescent::_tracefirst($text),
                  q{ServiceClass},
                  $tracelevel)
                    if defined $::RD_TRACE;
        $expectation->is(q{NonServiceClassLine})->at($text);
        
        unless (defined ($_tok = $thisparser->_parserepeat($text, \&Parse::RecDescent::Mace::Dependency::MaceHeaderDependencyRecDescent::NonServiceClassLine, 0, 100000000, $_noactions,$expectation,sub { \@arg }))) 
        {
            Parse::RecDescent::_trace(q{<<Didn't match repeated subrule: [NonServiceClassLine]>>},
                          Parse::RecDescent::_tracefirst($text),
                          q{ServiceClass},
                          $tracelevel)
                            if defined $::RD_TRACE;
            last;
        }
        Parse::RecDescent::_trace(q{>>Matched repeated subrule: [NonServiceClassLine]<< (}
                    . @$_tok . q{ times)},
                      
                      Parse::RecDescent::_tracefirst($text),
                      q{ServiceClass},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $item{q{NonServiceClassLine(s?)}} = $_tok;
        push @item, $_tok;
        


        Parse::RecDescent::_trace(q{Trying repeated subrule: [ServiceClassBody]},
                  Parse::RecDescent::_tracefirst($text),
                  q{ServiceClass},
                  $tracelevel)
                    if defined $::RD_TRACE;
        $expectation->is(q{ServiceClassBody})->at($text);
        
        unless (defined ($_tok = $thisparser->_parserepeat($text, \&Parse::RecDescent::Mace::Dependency::MaceHeaderDependencyRecDescent::ServiceClassBody, 0, 1, $_noactions,$expectation,sub { return [%arg] }))) 
        {
            Parse::RecDescent::_trace(q{<<Didn't match repeated subrule: [ServiceClassBody]>>},
                          Parse::RecDescent::_tracefirst($text),
                          q{ServiceClass},
                          $tracelevel)
                            if defined $::RD_TRACE;
            last;
        }
        Parse::RecDescent::_trace(q{>>Matched repeated subrule: [ServiceClassBody]<< (}
                    . @$_tok . q{ times)},
                      
                      Parse::RecDescent::_tracefirst($text),
                      q{ServiceClass},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $item{q{ServiceClassBody(?)}} = $_tok;
        push @item, $_tok;
        



        Parse::RecDescent::_trace(q{>>Matched production: [<skip: qr{\s* ((/[*] .*? [*]/|(//[^\n]*\n)|([#]line \s* \d+ \s* ["][^"\r\n]+["])) \s*)*}sx> NonServiceClassLine ServiceClassBody]<<},
                      Parse::RecDescent::_tracefirst($text),
                      q{ServiceClass},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $_matched = 1;
        last;
    }


    unless ( $_matched || defined($score) )
    {
        

        $_[1] = $text;  # NOT SURE THIS IS NEEDED
        Parse::RecDescent::_trace(q{<<Didn't match rule>>},
                     Parse::RecDescent::_tracefirst($_[1]),
                     q{ServiceClass},
                     $tracelevel)
                    if defined $::RD_TRACE;
        return undef;
    }
    if (!defined($return) && defined($score))
    {
        Parse::RecDescent::_trace(q{>>Accepted scored production<<}, "",
                      q{ServiceClass},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $return = $score_return;
    }
    splice @{$thisparser->{errors}}, $err_at;
    $return = $item[$#item] unless defined $return;
    if (defined $::RD_TRACE)
    {
        Parse::RecDescent::_trace(q{>>Matched rule<< (return value: [} .
                      $return . q{])}, "",
                      q{ServiceClass},
                      $tracelevel);
        Parse::RecDescent::_trace(q{(consumed: [} .
                      Parse::RecDescent::_tracemax(substr($_[1],0,-length($text))) . q{])}, 
                      Parse::RecDescent::_tracefirst($text),
                      , q{ServiceClass},
                      $tracelevel)
    }
    $_[1] = $text;
    return $return;
}

# ARGS ARE: ($parser, $text; $repeating, $_noactions, \@args)
sub Parse::RecDescent::Mace::Dependency::MaceHeaderDependencyRecDescent::IdCommaList
{
	my $thisparser = $_[0];
	use vars q{$tracelevel};
	local $tracelevel = ($tracelevel||0)+1;
	$ERRORS = 0;
    my $thisrule = $thisparser->{"rules"}{"IdCommaList"};
    
    Parse::RecDescent::_trace(q{Trying rule: [IdCommaList]},
                  Parse::RecDescent::_tracefirst($_[1]),
                  q{IdCommaList},
                  $tracelevel)
                    if defined $::RD_TRACE;

    
    my $err_at = @{$thisparser->{errors}};

    my $score;
    my $score_return;
    my $_tok;
    my $return = undef;
    my $_matched=0;
    my $commit=0;
    my @item = ();
    my %item = ();
    my $repeating =  defined($_[2]) && $_[2];
    my $_noactions = defined($_[3]) && $_[3];
    my @arg =    defined $_[4] ? @{ &{$_[4]} } : ();
    my %arg =    ($#arg & 01) ? @arg : (@arg, undef);
    my $text;
    my $lastsep="";
    my $expectation = new Parse::RecDescent::Expectation(q{<leftop: Id /,/ Id>});
    $expectation->at($_[1]);
    
    my $thisline;
    tie $thisline, q{Parse::RecDescent::LineCounter}, \$text, $thisparser;

    

    while (!$_matched && !$commit)
    {
        
        Parse::RecDescent::_trace(q{Trying production: [<leftop: Id /,/ Id>]},
                      Parse::RecDescent::_tracefirst($_[1]),
                      q{IdCommaList},
                      $tracelevel)
                        if defined $::RD_TRACE;
        my $thisprod = $thisrule->{"prods"}[0];
        $text = $_[1];
        my $_savetext;
        @item = (q{IdCommaList});
        %item = (__RULE__ => q{IdCommaList});
        my $repcount = 0;


        Parse::RecDescent::_trace(q{Trying operator: [<leftop: Id /,/ Id>]},
                  Parse::RecDescent::_tracefirst($text),
                  q{IdCommaList},
                  $tracelevel)
                    if defined $::RD_TRACE;
        $expectation->is(q{})->at($text);

        $_tok = undef;
        OPLOOP: while (1)
        {
          $repcount = 0;
          my  @item;
          
          # MATCH LEFTARG
          
        Parse::RecDescent::_trace(q{Trying subrule: [Id]},
                  Parse::RecDescent::_tracefirst($text),
                  q{IdCommaList},
                  $tracelevel)
                    if defined $::RD_TRACE;
        if (1) { no strict qw{refs};
        $expectation->is(q{Id})->at($text);
        unless (defined ($_tok = Parse::RecDescent::Mace::Dependency::MaceHeaderDependencyRecDescent::Id($thisparser,$text,$repeating,$_noactions,sub { \@arg })))
        {
            
            Parse::RecDescent::_trace(q{<<Didn't match subrule: [Id]>>},
                          Parse::RecDescent::_tracefirst($text),
                          q{IdCommaList},
                          $tracelevel)
                            if defined $::RD_TRACE;
            $expectation->failed();
            last;
        }
        Parse::RecDescent::_trace(q{>>Matched subrule: [Id]<< (return value: [}
                    . $_tok . q{]},
                      
                      Parse::RecDescent::_tracefirst($text),
                      q{IdCommaList},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $item{q{Id}} = $_tok;
        push @item, $_tok;
        
        }


          $repcount++;

          my $savetext = $text;
          my $backtrack;

          # MATCH (OP RIGHTARG)(s)
          while ($repcount < 100000000)
          {
            $backtrack = 0;
            
        Parse::RecDescent::_trace(q{Trying terminal: [/,/]}, Parse::RecDescent::_tracefirst($text),
                      q{IdCommaList},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $lastsep = "";
        $expectation->is(q{/,/})->at($text);
        

        unless ($text =~ s/\A($skip)/$lastsep=$1 and ""/e and   $text =~ s/\A(?:,)//)
        {
            
            $expectation->failed();
            Parse::RecDescent::_trace(q{<<Didn't match terminal>>},
                          Parse::RecDescent::_tracefirst($text))
                    if defined $::RD_TRACE;

            last;
        }
        Parse::RecDescent::_trace(q{>>Matched terminal<< (return value: [}
                        . $& . q{])},
                          Parse::RecDescent::_tracefirst($text))
                    if defined $::RD_TRACE;
        push @item, $item{__PATTERN1__}=$&;
        

            pop @item;
            if (defined $1) {push @item, $item{'Id(s)'}=$1; $backtrack=1;}
            
        Parse::RecDescent::_trace(q{Trying subrule: [Id]},
                  Parse::RecDescent::_tracefirst($text),
                  q{IdCommaList},
                  $tracelevel)
                    if defined $::RD_TRACE;
        if (1) { no strict qw{refs};
        $expectation->is(q{Id})->at($text);
        unless (defined ($_tok = Parse::RecDescent::Mace::Dependency::MaceHeaderDependencyRecDescent::Id($thisparser,$text,$repeating,$_noactions,sub { \@arg })))
        {
            
            Parse::RecDescent::_trace(q{<<Didn't match subrule: [Id]>>},
                          Parse::RecDescent::_tracefirst($text),
                          q{IdCommaList},
                          $tracelevel)
                            if defined $::RD_TRACE;
            $expectation->failed();
            last;
        }
        Parse::RecDescent::_trace(q{>>Matched subrule: [Id]<< (return value: [}
                    . $_tok . q{]},
                      
                      Parse::RecDescent::_tracefirst($text),
                      q{IdCommaList},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $item{q{Id}} = $_tok;
        push @item, $_tok;
        
        }

            $savetext = $text;
            $repcount++;
          }
          $text = $savetext;
          pop @item if $backtrack;

          unless (@item) { undef $_tok; last }
          $_tok = [ @item ];
          last;
        } 

        unless ($repcount>=1)
        {
            Parse::RecDescent::_trace(q{<<Didn't match operator: [<leftop: Id /,/ Id>]>>},
                          Parse::RecDescent::_tracefirst($text),
                          q{IdCommaList},
                          $tracelevel)
                            if defined $::RD_TRACE;
            $expectation->failed();
            last;
        }
        Parse::RecDescent::_trace(q{>>Matched operator: [<leftop: Id /,/ Id>]<< (return value: [}
                      . qq{@{$_tok||[]}} . q{]},
                      Parse::RecDescent::_tracefirst($text),
                      q{IdCommaList},
                      $tracelevel)
                        if defined $::RD_TRACE;

        push @item, $item{'Id(s)'}=$_tok||[];



        Parse::RecDescent::_trace(q{>>Matched production: [<leftop: Id /,/ Id>]<<},
                      Parse::RecDescent::_tracefirst($text),
                      q{IdCommaList},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $_matched = 1;
        last;
    }


    unless ( $_matched || defined($score) )
    {
        

        $_[1] = $text;  # NOT SURE THIS IS NEEDED
        Parse::RecDescent::_trace(q{<<Didn't match rule>>},
                     Parse::RecDescent::_tracefirst($_[1]),
                     q{IdCommaList},
                     $tracelevel)
                    if defined $::RD_TRACE;
        return undef;
    }
    if (!defined($return) && defined($score))
    {
        Parse::RecDescent::_trace(q{>>Accepted scored production<<}, "",
                      q{IdCommaList},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $return = $score_return;
    }
    splice @{$thisparser->{errors}}, $err_at;
    $return = $item[$#item] unless defined $return;
    if (defined $::RD_TRACE)
    {
        Parse::RecDescent::_trace(q{>>Matched rule<< (return value: [} .
                      $return . q{])}, "",
                      q{IdCommaList},
                      $tracelevel);
        Parse::RecDescent::_trace(q{(consumed: [} .
                      Parse::RecDescent::_tracemax(substr($_[1],0,-length($text))) . q{])}, 
                      Parse::RecDescent::_tracefirst($text),
                      , q{IdCommaList},
                      $tracelevel)
    }
    $_[1] = $text;
    return $return;
}

# ARGS ARE: ($parser, $text; $repeating, $_noactions, \@args)
sub Parse::RecDescent::Mace::Dependency::MaceHeaderDependencyRecDescent::NonServiceClassLine
{
	my $thisparser = $_[0];
	use vars q{$tracelevel};
	local $tracelevel = ($tracelevel||0)+1;
	$ERRORS = 0;
    my $thisrule = $thisparser->{"rules"}{"NonServiceClassLine"};
    
    Parse::RecDescent::_trace(q{Trying rule: [NonServiceClassLine]},
                  Parse::RecDescent::_tracefirst($_[1]),
                  q{NonServiceClassLine},
                  $tracelevel)
                    if defined $::RD_TRACE;

    
    my $err_at = @{$thisparser->{errors}};

    my $score;
    my $score_return;
    my $_tok;
    my $return = undef;
    my $_matched=0;
    my $commit=0;
    my @item = ();
    my %item = ();
    my $repeating =  defined($_[2]) && $_[2];
    my $_noactions = defined($_[3]) && $_[3];
    my @arg =    defined $_[4] ? @{ &{$_[4]} } : ();
    my %arg =    ($#arg & 01) ? @arg : (@arg, undef);
    my $text;
    my $lastsep="";
    my $expectation = new Parse::RecDescent::Expectation(q{'serviceclass'});
    $expectation->at($_[1]);
    
    my $thisline;
    tie $thisline, q{Parse::RecDescent::LineCounter}, \$text, $thisparser;

    

    while (!$_matched && !$commit)
    {
        
        Parse::RecDescent::_trace(q{Trying production: ['serviceclass' /.*?\\n/]},
                      Parse::RecDescent::_tracefirst($_[1]),
                      q{NonServiceClassLine},
                      $tracelevel)
                        if defined $::RD_TRACE;
        my $thisprod = $thisrule->{"prods"}[0];
        $text = $_[1];
        my $_savetext;
        @item = (q{NonServiceClassLine});
        %item = (__RULE__ => q{NonServiceClassLine});
        my $repcount = 0;


        Parse::RecDescent::_trace(q{Trying terminal: ['serviceclass']},
                      Parse::RecDescent::_tracefirst($text),
                      q{NonServiceClassLine},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $lastsep = "";
        $expectation->is(q{})->at($text);
        $_savetext = $text;

        if ($text =~ s/\A($skip)/$lastsep=$1 and ""/e and   $text =~ s/\Aserviceclass//)
        {
            $text = $_savetext;
            $expectation->failed();
            Parse::RecDescent::_trace(qq{<<Didn't match terminal>>},
                          Parse::RecDescent::_tracefirst($text))
                            if defined $::RD_TRACE;
            last;
        }
        Parse::RecDescent::_trace(q{>>Matched terminal<< (return value: [}
                        . $& . q{])},
                          Parse::RecDescent::_tracefirst($text))
                            if defined $::RD_TRACE;
        push @item, $item{__STRING1__}=$&;
        $text = $_savetext;

        Parse::RecDescent::_trace(q{Trying terminal: [/.*?\\n/]}, Parse::RecDescent::_tracefirst($text),
                      q{NonServiceClassLine},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $lastsep = "";
        $expectation->is(q{/.*?\\n/})->at($text);
        

        unless ($text =~ s/\A($skip)/$lastsep=$1 and ""/e and   $text =~ s/\A(?:.*?\n)//)
        {
            
            $expectation->failed();
            Parse::RecDescent::_trace(q{<<Didn't match terminal>>},
                          Parse::RecDescent::_tracefirst($text))
                    if defined $::RD_TRACE;

            last;
        }
        Parse::RecDescent::_trace(q{>>Matched terminal<< (return value: [}
                        . $& . q{])},
                          Parse::RecDescent::_tracefirst($text))
                    if defined $::RD_TRACE;
        push @item, $item{__PATTERN1__}=$&;
        


        Parse::RecDescent::_trace(q{>>Matched production: ['serviceclass' /.*?\\n/]<<},
                      Parse::RecDescent::_tracefirst($text),
                      q{NonServiceClassLine},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $_matched = 1;
        last;
    }


    unless ( $_matched || defined($score) )
    {
        

        $_[1] = $text;  # NOT SURE THIS IS NEEDED
        Parse::RecDescent::_trace(q{<<Didn't match rule>>},
                     Parse::RecDescent::_tracefirst($_[1]),
                     q{NonServiceClassLine},
                     $tracelevel)
                    if defined $::RD_TRACE;
        return undef;
    }
    if (!defined($return) && defined($score))
    {
        Parse::RecDescent::_trace(q{>>Accepted scored production<<}, "",
                      q{NonServiceClassLine},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $return = $score_return;
    }
    splice @{$thisparser->{errors}}, $err_at;
    $return = $item[$#item] unless defined $return;
    if (defined $::RD_TRACE)
    {
        Parse::RecDescent::_trace(q{>>Matched rule<< (return value: [} .
                      $return . q{])}, "",
                      q{NonServiceClassLine},
                      $tracelevel);
        Parse::RecDescent::_trace(q{(consumed: [} .
                      Parse::RecDescent::_tracemax(substr($_[1],0,-length($text))) . q{])}, 
                      Parse::RecDescent::_tracefirst($text),
                      , q{NonServiceClassLine},
                      $tracelevel)
    }
    $_[1] = $text;
    return $return;
}

# ARGS ARE: ($parser, $text; $repeating, $_noactions, \@args)
sub Parse::RecDescent::Mace::Dependency::MaceHeaderDependencyRecDescent::Handlers
{
	my $thisparser = $_[0];
	use vars q{$tracelevel};
	local $tracelevel = ($tracelevel||0)+1;
	$ERRORS = 0;
    my $thisrule = $thisparser->{"rules"}{"Handlers"};
    
    Parse::RecDescent::_trace(q{Trying rule: [Handlers]},
                  Parse::RecDescent::_tracefirst($_[1]),
                  q{Handlers},
                  $tracelevel)
                    if defined $::RD_TRACE;

    
    my $err_at = @{$thisparser->{errors}};

    my $score;
    my $score_return;
    my $_tok;
    my $return = undef;
    my $_matched=0;
    my $commit=0;
    my @item = ();
    my %item = ();
    my $repeating =  defined($_[2]) && $_[2];
    my $_noactions = defined($_[3]) && $_[3];
    my @arg =    defined $_[4] ? @{ &{$_[4]} } : ();
    my %arg =    ($#arg & 01) ? @arg : (@arg, undef);
    my $text;
    my $lastsep="";
    my $expectation = new Parse::RecDescent::Expectation(q{'handlers'});
    $expectation->at($_[1]);
    
    my $thisline;
    tie $thisline, q{Parse::RecDescent::LineCounter}, \$text, $thisparser;

    

    while (!$_matched && !$commit)
    {
        
        Parse::RecDescent::_trace(q{Trying production: ['handlers' IdCommaList ';']},
                      Parse::RecDescent::_tracefirst($_[1]),
                      q{Handlers},
                      $tracelevel)
                        if defined $::RD_TRACE;
        my $thisprod = $thisrule->{"prods"}[0];
        $text = $_[1];
        my $_savetext;
        @item = (q{Handlers});
        %item = (__RULE__ => q{Handlers});
        my $repcount = 0;


        Parse::RecDescent::_trace(q{Trying terminal: ['handlers']},
                      Parse::RecDescent::_tracefirst($text),
                      q{Handlers},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $lastsep = "";
        $expectation->is(q{})->at($text);
        

        unless ($text =~ s/\A($skip)/$lastsep=$1 and ""/e and   $text =~ s/\Ahandlers//)
        {
            
            $expectation->failed();
            Parse::RecDescent::_trace(qq{<<Didn't match terminal>>},
                          Parse::RecDescent::_tracefirst($text))
                            if defined $::RD_TRACE;
            last;
        }
        Parse::RecDescent::_trace(q{>>Matched terminal<< (return value: [}
                        . $& . q{])},
                          Parse::RecDescent::_tracefirst($text))
                            if defined $::RD_TRACE;
        push @item, $item{__STRING1__}=$&;
        

        Parse::RecDescent::_trace(q{Trying subrule: [IdCommaList]},
                  Parse::RecDescent::_tracefirst($text),
                  q{Handlers},
                  $tracelevel)
                    if defined $::RD_TRACE;
        if (1) { no strict qw{refs};
        $expectation->is(q{IdCommaList})->at($text);
        unless (defined ($_tok = Parse::RecDescent::Mace::Dependency::MaceHeaderDependencyRecDescent::IdCommaList($thisparser,$text,$repeating,$_noactions,sub { \@arg })))
        {
            
            Parse::RecDescent::_trace(q{<<Didn't match subrule: [IdCommaList]>>},
                          Parse::RecDescent::_tracefirst($text),
                          q{Handlers},
                          $tracelevel)
                            if defined $::RD_TRACE;
            $expectation->failed();
            last;
        }
        Parse::RecDescent::_trace(q{>>Matched subrule: [IdCommaList]<< (return value: [}
                    . $_tok . q{]},
                      
                      Parse::RecDescent::_tracefirst($text),
                      q{Handlers},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $item{q{IdCommaList}} = $_tok;
        push @item, $_tok;
        
        }

        Parse::RecDescent::_trace(q{Trying terminal: [';']},
                      Parse::RecDescent::_tracefirst($text),
                      q{Handlers},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $lastsep = "";
        $expectation->is(q{';'})->at($text);
        

        unless ($text =~ s/\A($skip)/$lastsep=$1 and ""/e and   $text =~ s/\A\;//)
        {
            
            $expectation->failed();
            Parse::RecDescent::_trace(qq{<<Didn't match terminal>>},
                          Parse::RecDescent::_tracefirst($text))
                            if defined $::RD_TRACE;
            last;
        }
        Parse::RecDescent::_trace(q{>>Matched terminal<< (return value: [}
                        . $& . q{])},
                          Parse::RecDescent::_tracefirst($text))
                            if defined $::RD_TRACE;
        push @item, $item{__STRING2__}=$&;
        

        Parse::RecDescent::_trace(q{Trying action},
                      Parse::RecDescent::_tracefirst($text),
                      q{Handlers},
                      $tracelevel)
                        if defined $::RD_TRACE;
        

        $_tok = ($_noactions) ? 0 : do {
    $return = $item{IdCommaList};
};
        unless (defined $_tok)
        {
            Parse::RecDescent::_trace(q{<<Didn't match action>> (return value: [undef])})
                    if defined $::RD_TRACE;
            last;
        }
        Parse::RecDescent::_trace(q{>>Matched action<< (return value: [}
                      . $_tok . q{])},
                      Parse::RecDescent::_tracefirst($text))
                        if defined $::RD_TRACE;
        push @item, $_tok;
        $item{__ACTION1__}=$_tok;
        


        Parse::RecDescent::_trace(q{>>Matched production: ['handlers' IdCommaList ';']<<},
                      Parse::RecDescent::_tracefirst($text),
                      q{Handlers},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $_matched = 1;
        last;
    }


    while (!$_matched && !$commit)
    {
        
        Parse::RecDescent::_trace(q{Trying production: []},
                      Parse::RecDescent::_tracefirst($_[1]),
                      q{Handlers},
                      $tracelevel)
                        if defined $::RD_TRACE;
        my $thisprod = $thisrule->{"prods"}[1];
        $text = $_[1];
        my $_savetext;
        @item = (q{Handlers});
        %item = (__RULE__ => q{Handlers});
        my $repcount = 0;


        Parse::RecDescent::_trace(q{Trying action},
                      Parse::RecDescent::_tracefirst($text),
                      q{Handlers},
                      $tracelevel)
                        if defined $::RD_TRACE;
        

        $_tok = ($_noactions) ? 0 : do { $return = []; };
        unless (defined $_tok)
        {
            Parse::RecDescent::_trace(q{<<Didn't match action>> (return value: [undef])})
                    if defined $::RD_TRACE;
            last;
        }
        Parse::RecDescent::_trace(q{>>Matched action<< (return value: [}
                      . $_tok . q{])},
                      Parse::RecDescent::_tracefirst($text))
                        if defined $::RD_TRACE;
        push @item, $_tok;
        $item{__ACTION1__}=$_tok;
        


        Parse::RecDescent::_trace(q{>>Matched production: []<<},
                      Parse::RecDescent::_tracefirst($text),
                      q{Handlers},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $_matched = 1;
        last;
    }


    unless ( $_matched || defined($score) )
    {
        

        $_[1] = $text;  # NOT SURE THIS IS NEEDED
        Parse::RecDescent::_trace(q{<<Didn't match rule>>},
                     Parse::RecDescent::_tracefirst($_[1]),
                     q{Handlers},
                     $tracelevel)
                    if defined $::RD_TRACE;
        return undef;
    }
    if (!defined($return) && defined($score))
    {
        Parse::RecDescent::_trace(q{>>Accepted scored production<<}, "",
                      q{Handlers},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $return = $score_return;
    }
    splice @{$thisparser->{errors}}, $err_at;
    $return = $item[$#item] unless defined $return;
    if (defined $::RD_TRACE)
    {
        Parse::RecDescent::_trace(q{>>Matched rule<< (return value: [} .
                      $return . q{])}, "",
                      q{Handlers},
                      $tracelevel);
        Parse::RecDescent::_trace(q{(consumed: [} .
                      Parse::RecDescent::_tracemax(substr($_[1],0,-length($text))) . q{])}, 
                      Parse::RecDescent::_tracefirst($text),
                      , q{Handlers},
                      $tracelevel)
    }
    $_[1] = $text;
    return $return;
}

# ARGS ARE: ($parser, $text; $repeating, $_noactions, \@args)
sub Parse::RecDescent::Mace::Dependency::MaceHeaderDependencyRecDescent::ServiceClassBody
{
	my $thisparser = $_[0];
	use vars q{$tracelevel};
	local $tracelevel = ($tracelevel||0)+1;
	$ERRORS = 0;
    my $thisrule = $thisparser->{"rules"}{"ServiceClassBody"};
    
    Parse::RecDescent::_trace(q{Trying rule: [ServiceClassBody]},
                  Parse::RecDescent::_tracefirst($_[1]),
                  q{ServiceClassBody},
                  $tracelevel)
                    if defined $::RD_TRACE;

    
    my $err_at = @{$thisparser->{errors}};

    my $score;
    my $score_return;
    my $_tok;
    my $return = undef;
    my $_matched=0;
    my $commit=0;
    my @item = ();
    my %item = ();
    my $repeating =  defined($_[2]) && $_[2];
    my $_noactions = defined($_[3]) && $_[3];
    my @arg =    defined $_[4] ? @{ &{$_[4]} } : ();
    my %arg =    ($#arg & 01) ? @arg : (@arg, undef);
    my $text;
    my $lastsep="";
    my $expectation = new Parse::RecDescent::Expectation(q{'serviceclass'});
    $expectation->at($_[1]);
    
    my $thisline;
    tie $thisline, q{Parse::RecDescent::LineCounter}, \$text, $thisparser;

    

    while (!$_matched && !$commit)
    {
        
        Parse::RecDescent::_trace(q{Trying production: ['serviceclass' Id ServiceClassExtend '\{' NonHandlerLine Handlers]},
                      Parse::RecDescent::_tracefirst($_[1]),
                      q{ServiceClassBody},
                      $tracelevel)
                        if defined $::RD_TRACE;
        my $thisprod = $thisrule->{"prods"}[0];
        $text = $_[1];
        my $_savetext;
        @item = (q{ServiceClassBody});
        %item = (__RULE__ => q{ServiceClassBody});
        my $repcount = 0;


        Parse::RecDescent::_trace(q{Trying terminal: ['serviceclass']},
                      Parse::RecDescent::_tracefirst($text),
                      q{ServiceClassBody},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $lastsep = "";
        $expectation->is(q{})->at($text);
        

        unless ($text =~ s/\A($skip)/$lastsep=$1 and ""/e and   $text =~ s/\Aserviceclass//)
        {
            
            $expectation->failed();
            Parse::RecDescent::_trace(qq{<<Didn't match terminal>>},
                          Parse::RecDescent::_tracefirst($text))
                            if defined $::RD_TRACE;
            last;
        }
        Parse::RecDescent::_trace(q{>>Matched terminal<< (return value: [}
                        . $& . q{])},
                          Parse::RecDescent::_tracefirst($text))
                            if defined $::RD_TRACE;
        push @item, $item{__STRING1__}=$&;
        

        Parse::RecDescent::_trace(q{Trying subrule: [Id]},
                  Parse::RecDescent::_tracefirst($text),
                  q{ServiceClassBody},
                  $tracelevel)
                    if defined $::RD_TRACE;
        if (1) { no strict qw{refs};
        $expectation->is(q{Id})->at($text);
        unless (defined ($_tok = Parse::RecDescent::Mace::Dependency::MaceHeaderDependencyRecDescent::Id($thisparser,$text,$repeating,$_noactions,sub { \@arg })))
        {
            
            Parse::RecDescent::_trace(q{<<Didn't match subrule: [Id]>>},
                          Parse::RecDescent::_tracefirst($text),
                          q{ServiceClassBody},
                          $tracelevel)
                            if defined $::RD_TRACE;
            $expectation->failed();
            last;
        }
        Parse::RecDescent::_trace(q{>>Matched subrule: [Id]<< (return value: [}
                    . $_tok . q{]},
                      
                      Parse::RecDescent::_tracefirst($text),
                      q{ServiceClassBody},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $item{q{Id}} = $_tok;
        push @item, $_tok;
        
        }

        Parse::RecDescent::_trace(q{Trying subrule: [ServiceClassExtend]},
                  Parse::RecDescent::_tracefirst($text),
                  q{ServiceClassBody},
                  $tracelevel)
                    if defined $::RD_TRACE;
        if (1) { no strict qw{refs};
        $expectation->is(q{ServiceClassExtend})->at($text);
        unless (defined ($_tok = Parse::RecDescent::Mace::Dependency::MaceHeaderDependencyRecDescent::ServiceClassExtend($thisparser,$text,$repeating,$_noactions,sub { \@arg })))
        {
            
            Parse::RecDescent::_trace(q{<<Didn't match subrule: [ServiceClassExtend]>>},
                          Parse::RecDescent::_tracefirst($text),
                          q{ServiceClassBody},
                          $tracelevel)
                            if defined $::RD_TRACE;
            $expectation->failed();
            last;
        }
        Parse::RecDescent::_trace(q{>>Matched subrule: [ServiceClassExtend]<< (return value: [}
                    . $_tok . q{]},
                      
                      Parse::RecDescent::_tracefirst($text),
                      q{ServiceClassBody},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $item{q{ServiceClassExtend}} = $_tok;
        push @item, $_tok;
        
        }

        Parse::RecDescent::_trace(q{Trying terminal: ['\{']},
                      Parse::RecDescent::_tracefirst($text),
                      q{ServiceClassBody},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $lastsep = "";
        $expectation->is(q{'\{'})->at($text);
        

        unless ($text =~ s/\A($skip)/$lastsep=$1 and ""/e and   $text =~ s/\A\{//)
        {
            
            $expectation->failed();
            Parse::RecDescent::_trace(qq{<<Didn't match terminal>>},
                          Parse::RecDescent::_tracefirst($text))
                            if defined $::RD_TRACE;
            last;
        }
        Parse::RecDescent::_trace(q{>>Matched terminal<< (return value: [}
                        . $& . q{])},
                          Parse::RecDescent::_tracefirst($text))
                            if defined $::RD_TRACE;
        push @item, $item{__STRING2__}=$&;
        

        Parse::RecDescent::_trace(q{Trying repeated subrule: [NonHandlerLine]},
                  Parse::RecDescent::_tracefirst($text),
                  q{ServiceClassBody},
                  $tracelevel)
                    if defined $::RD_TRACE;
        $expectation->is(q{NonHandlerLine})->at($text);
        
        unless (defined ($_tok = $thisparser->_parserepeat($text, \&Parse::RecDescent::Mace::Dependency::MaceHeaderDependencyRecDescent::NonHandlerLine, 0, 100000000, $_noactions,$expectation,sub { \@arg }))) 
        {
            Parse::RecDescent::_trace(q{<<Didn't match repeated subrule: [NonHandlerLine]>>},
                          Parse::RecDescent::_tracefirst($text),
                          q{ServiceClassBody},
                          $tracelevel)
                            if defined $::RD_TRACE;
            last;
        }
        Parse::RecDescent::_trace(q{>>Matched repeated subrule: [NonHandlerLine]<< (}
                    . @$_tok . q{ times)},
                      
                      Parse::RecDescent::_tracefirst($text),
                      q{ServiceClassBody},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $item{q{NonHandlerLine(s?)}} = $_tok;
        push @item, $_tok;
        


        Parse::RecDescent::_trace(q{Trying subrule: [Handlers]},
                  Parse::RecDescent::_tracefirst($text),
                  q{ServiceClassBody},
                  $tracelevel)
                    if defined $::RD_TRACE;
        if (1) { no strict qw{refs};
        $expectation->is(q{Handlers})->at($text);
        unless (defined ($_tok = Parse::RecDescent::Mace::Dependency::MaceHeaderDependencyRecDescent::Handlers($thisparser,$text,$repeating,$_noactions,sub { \@arg })))
        {
            
            Parse::RecDescent::_trace(q{<<Didn't match subrule: [Handlers]>>},
                          Parse::RecDescent::_tracefirst($text),
                          q{ServiceClassBody},
                          $tracelevel)
                            if defined $::RD_TRACE;
            $expectation->failed();
            last;
        }
        Parse::RecDescent::_trace(q{>>Matched subrule: [Handlers]<< (return value: [}
                    . $_tok . q{]},
                      
                      Parse::RecDescent::_tracefirst($text),
                      q{ServiceClassBody},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $item{q{Handlers}} = $_tok;
        push @item, $_tok;
        
        }

        Parse::RecDescent::_trace(q{Trying action},
                      Parse::RecDescent::_tracefirst($text),
                      q{ServiceClassBody},
                      $tracelevel)
                        if defined $::RD_TRACE;
        

        $_tok = ($_noactions) ? 0 : do {
    if (scalar(@{$item{ServiceClassExtend}}) or scalar(@{$item{Handlers}})) {
        $arg{vars}->{$item{Id}."ServiceClass_dep"} = "SET(".$item{Id}."ServiceClass_dep \${".$item{Id}."ServiceClass_h} \${ServiceClass_h}" .
             join('', map {" \${${_}ServiceClass_dep}"} @{$item{ServiceClassExtend}}) .
             join('', map {" \${${_}Handler_dep}"} @{$item{Handlers}}) .
             ")\n";
    }
};
        unless (defined $_tok)
        {
            Parse::RecDescent::_trace(q{<<Didn't match action>> (return value: [undef])})
                    if defined $::RD_TRACE;
            last;
        }
        Parse::RecDescent::_trace(q{>>Matched action<< (return value: [}
                      . $_tok . q{])},
                      Parse::RecDescent::_tracefirst($text))
                        if defined $::RD_TRACE;
        push @item, $_tok;
        $item{__ACTION1__}=$_tok;
        


        Parse::RecDescent::_trace(q{>>Matched production: ['serviceclass' Id ServiceClassExtend '\{' NonHandlerLine Handlers]<<},
                      Parse::RecDescent::_tracefirst($text),
                      q{ServiceClassBody},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $_matched = 1;
        last;
    }


    unless ( $_matched || defined($score) )
    {
        

        $_[1] = $text;  # NOT SURE THIS IS NEEDED
        Parse::RecDescent::_trace(q{<<Didn't match rule>>},
                     Parse::RecDescent::_tracefirst($_[1]),
                     q{ServiceClassBody},
                     $tracelevel)
                    if defined $::RD_TRACE;
        return undef;
    }
    if (!defined($return) && defined($score))
    {
        Parse::RecDescent::_trace(q{>>Accepted scored production<<}, "",
                      q{ServiceClassBody},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $return = $score_return;
    }
    splice @{$thisparser->{errors}}, $err_at;
    $return = $item[$#item] unless defined $return;
    if (defined $::RD_TRACE)
    {
        Parse::RecDescent::_trace(q{>>Matched rule<< (return value: [} .
                      $return . q{])}, "",
                      q{ServiceClassBody},
                      $tracelevel);
        Parse::RecDescent::_trace(q{(consumed: [} .
                      Parse::RecDescent::_tracemax(substr($_[1],0,-length($text))) . q{])}, 
                      Parse::RecDescent::_tracefirst($text),
                      , q{ServiceClassBody},
                      $tracelevel)
    }
    $_[1] = $text;
    return $return;
}

# ARGS ARE: ($parser, $text; $repeating, $_noactions, \@args)
sub Parse::RecDescent::Mace::Dependency::MaceHeaderDependencyRecDescent::NonHandlerLine
{
	my $thisparser = $_[0];
	use vars q{$tracelevel};
	local $tracelevel = ($tracelevel||0)+1;
	$ERRORS = 0;
    my $thisrule = $thisparser->{"rules"}{"NonHandlerLine"};
    
    Parse::RecDescent::_trace(q{Trying rule: [NonHandlerLine]},
                  Parse::RecDescent::_tracefirst($_[1]),
                  q{NonHandlerLine},
                  $tracelevel)
                    if defined $::RD_TRACE;

    
    my $err_at = @{$thisparser->{errors}};

    my $score;
    my $score_return;
    my $_tok;
    my $return = undef;
    my $_matched=0;
    my $commit=0;
    my @item = ();
    my %item = ();
    my $repeating =  defined($_[2]) && $_[2];
    my $_noactions = defined($_[3]) && $_[3];
    my @arg =    defined $_[4] ? @{ &{$_[4]} } : ();
    my %arg =    ($#arg & 01) ? @arg : (@arg, undef);
    my $text;
    my $lastsep="";
    my $expectation = new Parse::RecDescent::Expectation(q{'handlers'});
    $expectation->at($_[1]);
    
    my $thisline;
    tie $thisline, q{Parse::RecDescent::LineCounter}, \$text, $thisparser;

    

    while (!$_matched && !$commit)
    {
        
        Parse::RecDescent::_trace(q{Trying production: ['handlers' /.*?\\n/]},
                      Parse::RecDescent::_tracefirst($_[1]),
                      q{NonHandlerLine},
                      $tracelevel)
                        if defined $::RD_TRACE;
        my $thisprod = $thisrule->{"prods"}[0];
        $text = $_[1];
        my $_savetext;
        @item = (q{NonHandlerLine});
        %item = (__RULE__ => q{NonHandlerLine});
        my $repcount = 0;


        Parse::RecDescent::_trace(q{Trying terminal: ['handlers']},
                      Parse::RecDescent::_tracefirst($text),
                      q{NonHandlerLine},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $lastsep = "";
        $expectation->is(q{})->at($text);
        $_savetext = $text;

        if ($text =~ s/\A($skip)/$lastsep=$1 and ""/e and   $text =~ s/\Ahandlers//)
        {
            $text = $_savetext;
            $expectation->failed();
            Parse::RecDescent::_trace(qq{<<Didn't match terminal>>},
                          Parse::RecDescent::_tracefirst($text))
                            if defined $::RD_TRACE;
            last;
        }
        Parse::RecDescent::_trace(q{>>Matched terminal<< (return value: [}
                        . $& . q{])},
                          Parse::RecDescent::_tracefirst($text))
                            if defined $::RD_TRACE;
        push @item, $item{__STRING1__}=$&;
        $text = $_savetext;

        Parse::RecDescent::_trace(q{Trying terminal: [/.*?\\n/]}, Parse::RecDescent::_tracefirst($text),
                      q{NonHandlerLine},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $lastsep = "";
        $expectation->is(q{/.*?\\n/})->at($text);
        

        unless ($text =~ s/\A($skip)/$lastsep=$1 and ""/e and   $text =~ s/\A(?:.*?\n)//)
        {
            
            $expectation->failed();
            Parse::RecDescent::_trace(q{<<Didn't match terminal>>},
                          Parse::RecDescent::_tracefirst($text))
                    if defined $::RD_TRACE;

            last;
        }
        Parse::RecDescent::_trace(q{>>Matched terminal<< (return value: [}
                        . $& . q{])},
                          Parse::RecDescent::_tracefirst($text))
                    if defined $::RD_TRACE;
        push @item, $item{__PATTERN1__}=$&;
        


        Parse::RecDescent::_trace(q{>>Matched production: ['handlers' /.*?\\n/]<<},
                      Parse::RecDescent::_tracefirst($text),
                      q{NonHandlerLine},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $_matched = 1;
        last;
    }


    unless ( $_matched || defined($score) )
    {
        

        $_[1] = $text;  # NOT SURE THIS IS NEEDED
        Parse::RecDescent::_trace(q{<<Didn't match rule>>},
                     Parse::RecDescent::_tracefirst($_[1]),
                     q{NonHandlerLine},
                     $tracelevel)
                    if defined $::RD_TRACE;
        return undef;
    }
    if (!defined($return) && defined($score))
    {
        Parse::RecDescent::_trace(q{>>Accepted scored production<<}, "",
                      q{NonHandlerLine},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $return = $score_return;
    }
    splice @{$thisparser->{errors}}, $err_at;
    $return = $item[$#item] unless defined $return;
    if (defined $::RD_TRACE)
    {
        Parse::RecDescent::_trace(q{>>Matched rule<< (return value: [} .
                      $return . q{])}, "",
                      q{NonHandlerLine},
                      $tracelevel);
        Parse::RecDescent::_trace(q{(consumed: [} .
                      Parse::RecDescent::_tracemax(substr($_[1],0,-length($text))) . q{])}, 
                      Parse::RecDescent::_tracefirst($text),
                      , q{NonHandlerLine},
                      $tracelevel)
    }
    $_[1] = $text;
    return $return;
}

# ARGS ARE: ($parser, $text; $repeating, $_noactions, \@args)
sub Parse::RecDescent::Mace::Dependency::MaceHeaderDependencyRecDescent::ServiceClassExtend
{
	my $thisparser = $_[0];
	use vars q{$tracelevel};
	local $tracelevel = ($tracelevel||0)+1;
	$ERRORS = 0;
    my $thisrule = $thisparser->{"rules"}{"ServiceClassExtend"};
    
    Parse::RecDescent::_trace(q{Trying rule: [ServiceClassExtend]},
                  Parse::RecDescent::_tracefirst($_[1]),
                  q{ServiceClassExtend},
                  $tracelevel)
                    if defined $::RD_TRACE;

    
    my $err_at = @{$thisparser->{errors}};

    my $score;
    my $score_return;
    my $_tok;
    my $return = undef;
    my $_matched=0;
    my $commit=0;
    my @item = ();
    my %item = ();
    my $repeating =  defined($_[2]) && $_[2];
    my $_noactions = defined($_[3]) && $_[3];
    my @arg =    defined $_[4] ? @{ &{$_[4]} } : ();
    my %arg =    ($#arg & 01) ? @arg : (@arg, undef);
    my $text;
    my $lastsep="";
    my $expectation = new Parse::RecDescent::Expectation(q{':'});
    $expectation->at($_[1]);
    
    my $thisline;
    tie $thisline, q{Parse::RecDescent::LineCounter}, \$text, $thisparser;

    

    while (!$_matched && !$commit)
    {
        
        Parse::RecDescent::_trace(q{Trying production: [':' <commit> IdCommaList]},
                      Parse::RecDescent::_tracefirst($_[1]),
                      q{ServiceClassExtend},
                      $tracelevel)
                        if defined $::RD_TRACE;
        my $thisprod = $thisrule->{"prods"}[0];
        $text = $_[1];
        my $_savetext;
        @item = (q{ServiceClassExtend});
        %item = (__RULE__ => q{ServiceClassExtend});
        my $repcount = 0;


        Parse::RecDescent::_trace(q{Trying terminal: [':']},
                      Parse::RecDescent::_tracefirst($text),
                      q{ServiceClassExtend},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $lastsep = "";
        $expectation->is(q{})->at($text);
        

        unless ($text =~ s/\A($skip)/$lastsep=$1 and ""/e and   $text =~ s/\A\://)
        {
            
            $expectation->failed();
            Parse::RecDescent::_trace(qq{<<Didn't match terminal>>},
                          Parse::RecDescent::_tracefirst($text))
                            if defined $::RD_TRACE;
            last;
        }
        Parse::RecDescent::_trace(q{>>Matched terminal<< (return value: [}
                        . $& . q{])},
                          Parse::RecDescent::_tracefirst($text))
                            if defined $::RD_TRACE;
        push @item, $item{__STRING1__}=$&;
        

        

        Parse::RecDescent::_trace(q{Trying directive: [<commit>]},
                    Parse::RecDescent::_tracefirst($text),
                      q{ServiceClassExtend},
                      $tracelevel)
                        if defined $::RD_TRACE; 
        $_tok = do { $commit = 1 };
        if (defined($_tok))
        {
            Parse::RecDescent::_trace(q{>>Matched directive<< (return value: [}
                        . $_tok . q{])},
                        Parse::RecDescent::_tracefirst($text))
                            if defined $::RD_TRACE;
        }
        else
        {
            Parse::RecDescent::_trace(q{<<Didn't match directive>>},
                        Parse::RecDescent::_tracefirst($text))
                            if defined $::RD_TRACE;
        }
        
        last unless defined $_tok;
        push @item, $item{__DIRECTIVE1__}=$_tok;
        

        Parse::RecDescent::_trace(q{Trying subrule: [IdCommaList]},
                  Parse::RecDescent::_tracefirst($text),
                  q{ServiceClassExtend},
                  $tracelevel)
                    if defined $::RD_TRACE;
        if (1) { no strict qw{refs};
        $expectation->is(q{IdCommaList})->at($text);
        unless (defined ($_tok = Parse::RecDescent::Mace::Dependency::MaceHeaderDependencyRecDescent::IdCommaList($thisparser,$text,$repeating,$_noactions,sub { \@arg })))
        {
            
            Parse::RecDescent::_trace(q{<<Didn't match subrule: [IdCommaList]>>},
                          Parse::RecDescent::_tracefirst($text),
                          q{ServiceClassExtend},
                          $tracelevel)
                            if defined $::RD_TRACE;
            $expectation->failed();
            last;
        }
        Parse::RecDescent::_trace(q{>>Matched subrule: [IdCommaList]<< (return value: [}
                    . $_tok . q{]},
                      
                      Parse::RecDescent::_tracefirst($text),
                      q{ServiceClassExtend},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $item{q{IdCommaList}} = $_tok;
        push @item, $_tok;
        
        }

        Parse::RecDescent::_trace(q{Trying action},
                      Parse::RecDescent::_tracefirst($text),
                      q{ServiceClassExtend},
                      $tracelevel)
                        if defined $::RD_TRACE;
        

        $_tok = ($_noactions) ? 0 : do {
    $return = $item{IdCommaList};
};
        unless (defined $_tok)
        {
            Parse::RecDescent::_trace(q{<<Didn't match action>> (return value: [undef])})
                    if defined $::RD_TRACE;
            last;
        }
        Parse::RecDescent::_trace(q{>>Matched action<< (return value: [}
                      . $_tok . q{])},
                      Parse::RecDescent::_tracefirst($text))
                        if defined $::RD_TRACE;
        push @item, $_tok;
        $item{__ACTION1__}=$_tok;
        


        Parse::RecDescent::_trace(q{>>Matched production: [':' <commit> IdCommaList]<<},
                      Parse::RecDescent::_tracefirst($text),
                      q{ServiceClassExtend},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $_matched = 1;
        last;
    }


    while (!$_matched && !$commit)
    {
        
        Parse::RecDescent::_trace(q{Trying production: []},
                      Parse::RecDescent::_tracefirst($_[1]),
                      q{ServiceClassExtend},
                      $tracelevel)
                        if defined $::RD_TRACE;
        my $thisprod = $thisrule->{"prods"}[1];
        $text = $_[1];
        my $_savetext;
        @item = (q{ServiceClassExtend});
        %item = (__RULE__ => q{ServiceClassExtend});
        my $repcount = 0;


        Parse::RecDescent::_trace(q{Trying action},
                      Parse::RecDescent::_tracefirst($text),
                      q{ServiceClassExtend},
                      $tracelevel)
                        if defined $::RD_TRACE;
        

        $_tok = ($_noactions) ? 0 : do { $return = []; };
        unless (defined $_tok)
        {
            Parse::RecDescent::_trace(q{<<Didn't match action>> (return value: [undef])})
                    if defined $::RD_TRACE;
            last;
        }
        Parse::RecDescent::_trace(q{>>Matched action<< (return value: [}
                      . $_tok . q{])},
                      Parse::RecDescent::_tracefirst($text))
                        if defined $::RD_TRACE;
        push @item, $_tok;
        $item{__ACTION1__}=$_tok;
        


        Parse::RecDescent::_trace(q{>>Matched production: []<<},
                      Parse::RecDescent::_tracefirst($text),
                      q{ServiceClassExtend},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $_matched = 1;
        last;
    }


    unless ( $_matched || defined($score) )
    {
        

        $_[1] = $text;  # NOT SURE THIS IS NEEDED
        Parse::RecDescent::_trace(q{<<Didn't match rule>>},
                     Parse::RecDescent::_tracefirst($_[1]),
                     q{ServiceClassExtend},
                     $tracelevel)
                    if defined $::RD_TRACE;
        return undef;
    }
    if (!defined($return) && defined($score))
    {
        Parse::RecDescent::_trace(q{>>Accepted scored production<<}, "",
                      q{ServiceClassExtend},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $return = $score_return;
    }
    splice @{$thisparser->{errors}}, $err_at;
    $return = $item[$#item] unless defined $return;
    if (defined $::RD_TRACE)
    {
        Parse::RecDescent::_trace(q{>>Matched rule<< (return value: [} .
                      $return . q{])}, "",
                      q{ServiceClassExtend},
                      $tracelevel);
        Parse::RecDescent::_trace(q{(consumed: [} .
                      Parse::RecDescent::_tracemax(substr($_[1],0,-length($text))) . q{])}, 
                      Parse::RecDescent::_tracefirst($text),
                      , q{ServiceClassExtend},
                      $tracelevel)
    }
    $_[1] = $text;
    return $return;
}
}
package Mace::Dependency::MaceHeaderDependencyRecDescent; sub new { my $self = bless( {
                 '_AUTOTREE' => undef,
                 'localvars' => '',
                 'startcode' => '',
                 '_check' => {
                               'thisoffset' => '',
                               'itempos' => '',
                               'prevoffset' => '',
                               'prevline' => '',
                               'prevcolumn' => '',
                               'thiscolumn' => ''
                             },
                 'namespace' => 'Parse::RecDescent::Mace::Dependency::MaceHeaderDependencyRecDescent',
                 '_AUTOACTION' => undef,
                 'rules' => {
                              'Id' => bless( {
                                               'impcount' => 0,
                                               'calls' => [],
                                               'changed' => 0,
                                               'opcount' => 0,
                                               'prods' => [
                                                            bless( {
                                                                     'number' => 0,
                                                                     'strcount' => 0,
                                                                     'dircount' => 0,
                                                                     'uncommit' => undef,
                                                                     'error' => undef,
                                                                     'patcount' => 1,
                                                                     'actcount' => 0,
                                                                     'items' => [
                                                                                  bless( {
                                                                                           'pattern' => '[_a-zA-Z][a-zA-Z0-9_]*',
                                                                                           'hashname' => '__PATTERN1__',
                                                                                           'description' => '/[_a-zA-Z][a-zA-Z0-9_]*/',
                                                                                           'lookahead' => 0,
                                                                                           'rdelim' => '/',
                                                                                           'line' => 7,
                                                                                           'mod' => '',
                                                                                           'ldelim' => '/'
                                                                                         }, 'Parse::RecDescent::Token' )
                                                                                ],
                                                                     'line' => undef
                                                                   }, 'Parse::RecDescent::Production' )
                                                          ],
                                               'name' => 'Id',
                                               'vars' => '',
                                               'line' => 7
                                             }, 'Parse::RecDescent::Rule' ),
                              'ServiceClass' => bless( {
                                                         'impcount' => 0,
                                                         'calls' => [
                                                                      'NonServiceClassLine',
                                                                      'ServiceClassBody'
                                                                    ],
                                                         'changed' => 0,
                                                         'opcount' => 0,
                                                         'prods' => [
                                                                      bless( {
                                                                               'number' => 0,
                                                                               'strcount' => 0,
                                                                               'dircount' => 1,
                                                                               'uncommit' => undef,
                                                                               'error' => undef,
                                                                               'patcount' => 0,
                                                                               'actcount' => 0,
                                                                               'items' => [
                                                                                            bless( {
                                                                                                     'hashname' => '__DIRECTIVE1__',
                                                                                                     'name' => '<skip: qr{\\s* ((/[*] .*? [*]/|(//[^\\n]*\\n)|([#]line \\s* \\d+ \\s* ["][^"\\r\\n]+["])) \\s*)*}sx>',
                                                                                                     'lookahead' => 0,
                                                                                                     'line' => 33,
                                                                                                     'code' => 'my $oldskip = $skip; $skip= qr{\\s* ((/[*] .*? [*]/|(//[^\\n]*\\n)|([#]line \\s* \\d+ \\s* ["][^"\\r\\n]+["])) \\s*)*}sx; $oldskip'
                                                                                                   }, 'Parse::RecDescent::Directive' ),
                                                                                            bless( {
                                                                                                     'subrule' => 'NonServiceClassLine',
                                                                                                     'expected' => undef,
                                                                                                     'min' => 0,
                                                                                                     'argcode' => undef,
                                                                                                     'max' => 100000000,
                                                                                                     'matchrule' => 0,
                                                                                                     'repspec' => 's?',
                                                                                                     'lookahead' => 0,
                                                                                                     'line' => 33
                                                                                                   }, 'Parse::RecDescent::Repetition' ),
                                                                                            bless( {
                                                                                                     'subrule' => 'ServiceClassBody',
                                                                                                     'expected' => undef,
                                                                                                     'min' => 0,
                                                                                                     'argcode' => '[%arg]',
                                                                                                     'max' => 1,
                                                                                                     'matchrule' => 0,
                                                                                                     'repspec' => '?',
                                                                                                     'lookahead' => 0,
                                                                                                     'line' => 33
                                                                                                   }, 'Parse::RecDescent::Repetition' )
                                                                                          ],
                                                                               'line' => undef
                                                                             }, 'Parse::RecDescent::Production' )
                                                                    ],
                                                         'name' => 'ServiceClass',
                                                         'vars' => '',
                                                         'line' => 33
                                                       }, 'Parse::RecDescent::Rule' ),
                              'IdCommaList' => bless( {
                                                        'impcount' => 0,
                                                        'calls' => [
                                                                     'Id'
                                                                   ],
                                                        'changed' => 0,
                                                        'opcount' => 0,
                                                        'prods' => [
                                                                     bless( {
                                                                              'number' => 0,
                                                                              'strcount' => 0,
                                                                              'dircount' => 1,
                                                                              'uncommit' => undef,
                                                                              'error' => undef,
                                                                              'patcount' => 1,
                                                                              'actcount' => 0,
                                                                              'op' => [],
                                                                              'items' => [
                                                                                           bless( {
                                                                                                    'expected' => '<leftop: Id /,/ Id>',
                                                                                                    'min' => 1,
                                                                                                    'name' => '\'Id(s)\'',
                                                                                                    'max' => 100000000,
                                                                                                    'leftarg' => bless( {
                                                                                                                          'subrule' => 'Id',
                                                                                                                          'matchrule' => 0,
                                                                                                                          'implicit' => undef,
                                                                                                                          'argcode' => undef,
                                                                                                                          'lookahead' => 0,
                                                                                                                          'line' => 9
                                                                                                                        }, 'Parse::RecDescent::Subrule' ),
                                                                                                    'rightarg' => bless( {
                                                                                                                           'subrule' => 'Id',
                                                                                                                           'matchrule' => 0,
                                                                                                                           'implicit' => undef,
                                                                                                                           'argcode' => undef,
                                                                                                                           'lookahead' => 0,
                                                                                                                           'line' => 9
                                                                                                                         }, 'Parse::RecDescent::Subrule' ),
                                                                                                    'hashname' => '__DIRECTIVE1__',
                                                                                                    'type' => 'leftop',
                                                                                                    'op' => bless( {
                                                                                                                     'pattern' => ',',
                                                                                                                     'hashname' => '__PATTERN1__',
                                                                                                                     'description' => '/,/',
                                                                                                                     'lookahead' => 0,
                                                                                                                     'rdelim' => '/',
                                                                                                                     'line' => 9,
                                                                                                                     'mod' => '',
                                                                                                                     'ldelim' => '/'
                                                                                                                   }, 'Parse::RecDescent::Token' )
                                                                                                  }, 'Parse::RecDescent::Operator' )
                                                                                         ],
                                                                              'line' => undef
                                                                            }, 'Parse::RecDescent::Production' )
                                                                   ],
                                                        'name' => 'IdCommaList',
                                                        'vars' => '',
                                                        'line' => 9
                                                      }, 'Parse::RecDescent::Rule' ),
                              'NonServiceClassLine' => bless( {
                                                                'impcount' => 0,
                                                                'calls' => [],
                                                                'changed' => 0,
                                                                'opcount' => 0,
                                                                'prods' => [
                                                                             bless( {
                                                                                      'number' => 0,
                                                                                      'strcount' => 1,
                                                                                      'dircount' => 0,
                                                                                      'uncommit' => undef,
                                                                                      'error' => undef,
                                                                                      'patcount' => 1,
                                                                                      'actcount' => 0,
                                                                                      'items' => [
                                                                                                   bless( {
                                                                                                            'pattern' => 'serviceclass',
                                                                                                            'hashname' => '__STRING1__',
                                                                                                            'description' => '\'serviceclass\'',
                                                                                                            'lookahead' => -1,
                                                                                                            'line' => 3
                                                                                                          }, 'Parse::RecDescent::Literal' ),
                                                                                                   bless( {
                                                                                                            'pattern' => '.*?\\n',
                                                                                                            'hashname' => '__PATTERN1__',
                                                                                                            'description' => '/.*?\\\\n/',
                                                                                                            'lookahead' => 0,
                                                                                                            'rdelim' => '/',
                                                                                                            'line' => 3,
                                                                                                            'mod' => '',
                                                                                                            'ldelim' => '/'
                                                                                                          }, 'Parse::RecDescent::Token' )
                                                                                                 ],
                                                                                      'line' => undef
                                                                                    }, 'Parse::RecDescent::Production' )
                                                                           ],
                                                                'name' => 'NonServiceClassLine',
                                                                'vars' => '',
                                                                'line' => 1
                                                              }, 'Parse::RecDescent::Rule' ),
                              'Handlers' => bless( {
                                                     'impcount' => 0,
                                                     'calls' => [
                                                                  'IdCommaList'
                                                                ],
                                                     'changed' => 0,
                                                     'opcount' => 0,
                                                     'prods' => [
                                                                  bless( {
                                                                           'number' => 0,
                                                                           'strcount' => 2,
                                                                           'dircount' => 0,
                                                                           'uncommit' => undef,
                                                                           'error' => undef,
                                                                           'patcount' => 0,
                                                                           'actcount' => 1,
                                                                           'items' => [
                                                                                        bless( {
                                                                                                 'pattern' => 'handlers',
                                                                                                 'hashname' => '__STRING1__',
                                                                                                 'description' => '\'handlers\'',
                                                                                                 'lookahead' => 0,
                                                                                                 'line' => 17
                                                                                               }, 'Parse::RecDescent::Literal' ),
                                                                                        bless( {
                                                                                                 'subrule' => 'IdCommaList',
                                                                                                 'matchrule' => 0,
                                                                                                 'implicit' => undef,
                                                                                                 'argcode' => undef,
                                                                                                 'lookahead' => 0,
                                                                                                 'line' => 17
                                                                                               }, 'Parse::RecDescent::Subrule' ),
                                                                                        bless( {
                                                                                                 'pattern' => ';',
                                                                                                 'hashname' => '__STRING2__',
                                                                                                 'description' => '\';\'',
                                                                                                 'lookahead' => 0,
                                                                                                 'line' => 17
                                                                                               }, 'Parse::RecDescent::Literal' ),
                                                                                        bless( {
                                                                                                 'hashname' => '__ACTION1__',
                                                                                                 'lookahead' => 0,
                                                                                                 'line' => 18,
                                                                                                 'code' => '{
    $return = $item{IdCommaList};
}'
                                                                                               }, 'Parse::RecDescent::Action' )
                                                                                      ],
                                                                           'line' => undef
                                                                         }, 'Parse::RecDescent::Production' ),
                                                                  bless( {
                                                                           'number' => 1,
                                                                           'strcount' => 0,
                                                                           'dircount' => 0,
                                                                           'uncommit' => undef,
                                                                           'error' => undef,
                                                                           'patcount' => 0,
                                                                           'actcount' => 1,
                                                                           'items' => [
                                                                                        bless( {
                                                                                                 'hashname' => '__ACTION1__',
                                                                                                 'lookahead' => 0,
                                                                                                 'line' => 21,
                                                                                                 'code' => '{ $return = []; }'
                                                                                               }, 'Parse::RecDescent::Action' )
                                                                                      ],
                                                                           'line' => 21
                                                                         }, 'Parse::RecDescent::Production' )
                                                                ],
                                                     'name' => 'Handlers',
                                                     'vars' => '',
                                                     'line' => 17
                                                   }, 'Parse::RecDescent::Rule' ),
                              'ServiceClassBody' => bless( {
                                                             'impcount' => 0,
                                                             'calls' => [
                                                                          'Id',
                                                                          'ServiceClassExtend',
                                                                          'NonHandlerLine',
                                                                          'Handlers'
                                                                        ],
                                                             'changed' => 0,
                                                             'opcount' => 0,
                                                             'prods' => [
                                                                          bless( {
                                                                                   'number' => 0,
                                                                                   'strcount' => 2,
                                                                                   'dircount' => 0,
                                                                                   'uncommit' => undef,
                                                                                   'error' => undef,
                                                                                   'patcount' => 0,
                                                                                   'actcount' => 1,
                                                                                   'items' => [
                                                                                                bless( {
                                                                                                         'pattern' => 'serviceclass',
                                                                                                         'hashname' => '__STRING1__',
                                                                                                         'description' => '\'serviceclass\'',
                                                                                                         'lookahead' => 0,
                                                                                                         'line' => 23
                                                                                                       }, 'Parse::RecDescent::Literal' ),
                                                                                                bless( {
                                                                                                         'subrule' => 'Id',
                                                                                                         'matchrule' => 0,
                                                                                                         'implicit' => undef,
                                                                                                         'argcode' => undef,
                                                                                                         'lookahead' => 0,
                                                                                                         'line' => 23
                                                                                                       }, 'Parse::RecDescent::Subrule' ),
                                                                                                bless( {
                                                                                                         'subrule' => 'ServiceClassExtend',
                                                                                                         'matchrule' => 0,
                                                                                                         'implicit' => undef,
                                                                                                         'argcode' => undef,
                                                                                                         'lookahead' => 0,
                                                                                                         'line' => 23
                                                                                                       }, 'Parse::RecDescent::Subrule' ),
                                                                                                bless( {
                                                                                                         'pattern' => '{',
                                                                                                         'hashname' => '__STRING2__',
                                                                                                         'description' => '\'\\{\'',
                                                                                                         'lookahead' => 0,
                                                                                                         'line' => 23
                                                                                                       }, 'Parse::RecDescent::Literal' ),
                                                                                                bless( {
                                                                                                         'subrule' => 'NonHandlerLine',
                                                                                                         'expected' => undef,
                                                                                                         'min' => 0,
                                                                                                         'argcode' => undef,
                                                                                                         'max' => 100000000,
                                                                                                         'matchrule' => 0,
                                                                                                         'repspec' => 's?',
                                                                                                         'lookahead' => 0,
                                                                                                         'line' => 23
                                                                                                       }, 'Parse::RecDescent::Repetition' ),
                                                                                                bless( {
                                                                                                         'subrule' => 'Handlers',
                                                                                                         'matchrule' => 0,
                                                                                                         'implicit' => undef,
                                                                                                         'argcode' => undef,
                                                                                                         'lookahead' => 0,
                                                                                                         'line' => 23
                                                                                                       }, 'Parse::RecDescent::Subrule' ),
                                                                                                bless( {
                                                                                                         'hashname' => '__ACTION1__',
                                                                                                         'lookahead' => 0,
                                                                                                         'line' => 24,
                                                                                                         'code' => '{
    if (scalar(@{$item{ServiceClassExtend}}) or scalar(@{$item{Handlers}})) {
        $arg{vars}->{$item{Id}."ServiceClass_dep"} = "SET(".$item{Id}."ServiceClass_dep \\${".$item{Id}."ServiceClass_h} \\${ServiceClass_h}" .
             join(\'\', map {" \\${${_}ServiceClass_dep}"} @{$item{ServiceClassExtend}}) .
             join(\'\', map {" \\${${_}Handler_dep}"} @{$item{Handlers}}) .
             ")\\n";
    }
}'
                                                                                                       }, 'Parse::RecDescent::Action' )
                                                                                              ],
                                                                                   'line' => undef
                                                                                 }, 'Parse::RecDescent::Production' )
                                                                        ],
                                                             'name' => 'ServiceClassBody',
                                                             'vars' => '',
                                                             'line' => 23
                                                           }, 'Parse::RecDescent::Rule' ),
                              'NonHandlerLine' => bless( {
                                                           'impcount' => 0,
                                                           'calls' => [],
                                                           'changed' => 0,
                                                           'opcount' => 0,
                                                           'prods' => [
                                                                        bless( {
                                                                                 'number' => 0,
                                                                                 'strcount' => 1,
                                                                                 'dircount' => 0,
                                                                                 'uncommit' => undef,
                                                                                 'error' => undef,
                                                                                 'patcount' => 1,
                                                                                 'actcount' => 0,
                                                                                 'items' => [
                                                                                              bless( {
                                                                                                       'pattern' => 'handlers',
                                                                                                       'hashname' => '__STRING1__',
                                                                                                       'description' => '\'handlers\'',
                                                                                                       'lookahead' => -1,
                                                                                                       'line' => 5
                                                                                                     }, 'Parse::RecDescent::Literal' ),
                                                                                              bless( {
                                                                                                       'pattern' => '.*?\\n',
                                                                                                       'hashname' => '__PATTERN1__',
                                                                                                       'description' => '/.*?\\\\n/',
                                                                                                       'lookahead' => 0,
                                                                                                       'rdelim' => '/',
                                                                                                       'line' => 5,
                                                                                                       'mod' => '',
                                                                                                       'ldelim' => '/'
                                                                                                     }, 'Parse::RecDescent::Token' )
                                                                                            ],
                                                                                 'line' => undef
                                                                               }, 'Parse::RecDescent::Production' )
                                                                      ],
                                                           'name' => 'NonHandlerLine',
                                                           'vars' => '',
                                                           'line' => 5
                                                         }, 'Parse::RecDescent::Rule' ),
                              'ServiceClassExtend' => bless( {
                                                               'impcount' => 0,
                                                               'calls' => [
                                                                            'IdCommaList'
                                                                          ],
                                                               'changed' => 0,
                                                               'opcount' => 0,
                                                               'prods' => [
                                                                            bless( {
                                                                                     'number' => 0,
                                                                                     'strcount' => 1,
                                                                                     'dircount' => 1,
                                                                                     'uncommit' => undef,
                                                                                     'error' => undef,
                                                                                     'patcount' => 0,
                                                                                     'actcount' => 1,
                                                                                     'items' => [
                                                                                                  bless( {
                                                                                                           'pattern' => ':',
                                                                                                           'hashname' => '__STRING1__',
                                                                                                           'description' => '\':\'',
                                                                                                           'lookahead' => 0,
                                                                                                           'line' => 11
                                                                                                         }, 'Parse::RecDescent::Literal' ),
                                                                                                  bless( {
                                                                                                           'hashname' => '__DIRECTIVE1__',
                                                                                                           'name' => '<commit>',
                                                                                                           'lookahead' => 0,
                                                                                                           'line' => 11,
                                                                                                           'code' => '$commit = 1'
                                                                                                         }, 'Parse::RecDescent::Directive' ),
                                                                                                  bless( {
                                                                                                           'subrule' => 'IdCommaList',
                                                                                                           'matchrule' => 0,
                                                                                                           'implicit' => undef,
                                                                                                           'argcode' => undef,
                                                                                                           'lookahead' => 0,
                                                                                                           'line' => 11
                                                                                                         }, 'Parse::RecDescent::Subrule' ),
                                                                                                  bless( {
                                                                                                           'hashname' => '__ACTION1__',
                                                                                                           'lookahead' => 0,
                                                                                                           'line' => 12,
                                                                                                           'code' => '{
    $return = $item{IdCommaList};
}'
                                                                                                         }, 'Parse::RecDescent::Action' )
                                                                                                ],
                                                                                     'line' => undef
                                                                                   }, 'Parse::RecDescent::Production' ),
                                                                            bless( {
                                                                                     'number' => 1,
                                                                                     'strcount' => 0,
                                                                                     'dircount' => 0,
                                                                                     'uncommit' => undef,
                                                                                     'error' => undef,
                                                                                     'patcount' => 0,
                                                                                     'actcount' => 1,
                                                                                     'items' => [
                                                                                                  bless( {
                                                                                                           'hashname' => '__ACTION1__',
                                                                                                           'lookahead' => 0,
                                                                                                           'line' => 15,
                                                                                                           'code' => '{ $return = []; }'
                                                                                                         }, 'Parse::RecDescent::Action' )
                                                                                                ],
                                                                                     'line' => 15
                                                                                   }, 'Parse::RecDescent::Production' )
                                                                          ],
                                                               'name' => 'ServiceClassExtend',
                                                               'vars' => '',
                                                               'line' => 11
                                                             }, 'Parse::RecDescent::Rule' )
                            }
               }, 'Parse::RecDescent' );
}