package Mace::Dependency::MaceGrammarDependencyRecDescent;
use Parse::RecDescent;

{ my $ERRORS;


package Parse::RecDescent::Mace::Dependency::MaceGrammarDependencyRecDescent;
use strict;
use vars qw($skip $AUTOLOAD  );
@Parse::RecDescent::Mace::Dependency::MaceGrammarDependencyRecDescent::ISA = ();
$skip = '\s*';


{
local $SIG{__WARN__} = sub {0};
# PRETEND TO BE IN Parse::RecDescent NAMESPACE
*Parse::RecDescent::Mace::Dependency::MaceGrammarDependencyRecDescent::AUTOLOAD   = sub
{
    no strict 'refs';
    $AUTOLOAD =~ s/^Parse::RecDescent::Mace::Dependency::MaceGrammarDependencyRecDescent/Parse::RecDescent/;
    goto &{$AUTOLOAD};
}
}

push @Parse::RecDescent::Mace::Dependency::MaceGrammarDependencyRecDescent::ISA, 'Parse::RecDescent';
# ARGS ARE: ($parser, $text; $repeating, $_noactions, \@args)
sub Parse::RecDescent::Mace::Dependency::MaceGrammarDependencyRecDescent::InlineFinal
{
	my $thisparser = $_[0];
	use vars q{$tracelevel};
	local $tracelevel = ($tracelevel||0)+1;
	$ERRORS = 0;
    my $thisrule = $thisparser->{"rules"}{"InlineFinal"};
    
    Parse::RecDescent::_trace(q{Trying rule: [InlineFinal]},
                  Parse::RecDescent::_tracefirst($_[1]),
                  q{InlineFinal},
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
    my $expectation = new Parse::RecDescent::Expectation(q{'inline', or 'final'});
    $expectation->at($_[1]);
    
    my $thisline;
    tie $thisline, q{Parse::RecDescent::LineCounter}, \$text, $thisparser;

    

    while (!$_matched && !$commit)
    {
        
        Parse::RecDescent::_trace(q{Trying production: ['inline']},
                      Parse::RecDescent::_tracefirst($_[1]),
                      q{InlineFinal},
                      $tracelevel)
                        if defined $::RD_TRACE;
        my $thisprod = $thisrule->{"prods"}[0];
        $text = $_[1];
        my $_savetext;
        @item = (q{InlineFinal});
        %item = (__RULE__ => q{InlineFinal});
        my $repcount = 0;


        Parse::RecDescent::_trace(q{Trying terminal: ['inline']},
                      Parse::RecDescent::_tracefirst($text),
                      q{InlineFinal},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $lastsep = "";
        $expectation->is(q{})->at($text);
        

        unless ($text =~ s/\A($skip)/$lastsep=$1 and ""/e and   $text =~ s/\Ainline//)
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
        


        Parse::RecDescent::_trace(q{>>Matched production: ['inline']<<},
                      Parse::RecDescent::_tracefirst($text),
                      q{InlineFinal},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $_matched = 1;
        last;
    }


    while (!$_matched && !$commit)
    {
        
        Parse::RecDescent::_trace(q{Trying production: ['final']},
                      Parse::RecDescent::_tracefirst($_[1]),
                      q{InlineFinal},
                      $tracelevel)
                        if defined $::RD_TRACE;
        my $thisprod = $thisrule->{"prods"}[1];
        $text = $_[1];
        my $_savetext;
        @item = (q{InlineFinal});
        %item = (__RULE__ => q{InlineFinal});
        my $repcount = 0;


        Parse::RecDescent::_trace(q{Trying terminal: ['final']},
                      Parse::RecDescent::_tracefirst($text),
                      q{InlineFinal},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $lastsep = "";
        $expectation->is(q{})->at($text);
        

        unless ($text =~ s/\A($skip)/$lastsep=$1 and ""/e and   $text =~ s/\Afinal//)
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
        


        Parse::RecDescent::_trace(q{>>Matched production: ['final']<<},
                      Parse::RecDescent::_tracefirst($text),
                      q{InlineFinal},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $_matched = 1;
        last;
    }


    while (!$_matched && !$commit)
    {
        
        Parse::RecDescent::_trace(q{Trying production: []},
                      Parse::RecDescent::_tracefirst($_[1]),
                      q{InlineFinal},
                      $tracelevel)
                        if defined $::RD_TRACE;
        my $thisprod = $thisrule->{"prods"}[2];
        $text = $_[1];
        my $_savetext;
        @item = (q{InlineFinal});
        %item = (__RULE__ => q{InlineFinal});
        my $repcount = 0;



        Parse::RecDescent::_trace(q{>>Matched production: []<<},
                      Parse::RecDescent::_tracefirst($text),
                      q{InlineFinal},
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
                     q{InlineFinal},
                     $tracelevel)
                    if defined $::RD_TRACE;
        return undef;
    }
    if (!defined($return) && defined($score))
    {
        Parse::RecDescent::_trace(q{>>Accepted scored production<<}, "",
                      q{InlineFinal},
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
                      q{InlineFinal},
                      $tracelevel);
        Parse::RecDescent::_trace(q{(consumed: [} .
                      Parse::RecDescent::_tracemax(substr($_[1],0,-length($text))) . q{])}, 
                      Parse::RecDescent::_tracefirst($text),
                      , q{InlineFinal},
                      $tracelevel)
    }
    $_[1] = $text;
    return $return;
}

# ARGS ARE: ($parser, $text; $repeating, $_noactions, \@args)
sub Parse::RecDescent::Mace::Dependency::MaceGrammarDependencyRecDescent::ServiceBlock
{
	my $thisparser = $_[0];
	use vars q{$tracelevel};
	local $tracelevel = ($tracelevel||0)+1;
	$ERRORS = 0;
    my $thisrule = $thisparser->{"rules"}{"ServiceBlock"};
    
    Parse::RecDescent::_trace(q{Trying rule: [ServiceBlock]},
                  Parse::RecDescent::_tracefirst($_[1]),
                  q{ServiceBlock},
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
    my $expectation = new Parse::RecDescent::Expectation(q{'services'});
    $expectation->at($_[1]);
    
    my $thisline;
    tie $thisline, q{Parse::RecDescent::LineCounter}, \$text, $thisparser;

    

    while (!$_matched && !$commit)
    {
        
        Parse::RecDescent::_trace(q{Trying production: ['services' '\{' ServiceList]},
                      Parse::RecDescent::_tracefirst($_[1]),
                      q{ServiceBlock},
                      $tracelevel)
                        if defined $::RD_TRACE;
        my $thisprod = $thisrule->{"prods"}[0];
        $text = $_[1];
        my $_savetext;
        @item = (q{ServiceBlock});
        %item = (__RULE__ => q{ServiceBlock});
        my $repcount = 0;


        Parse::RecDescent::_trace(q{Trying terminal: ['services']},
                      Parse::RecDescent::_tracefirst($text),
                      q{ServiceBlock},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $lastsep = "";
        $expectation->is(q{})->at($text);
        

        unless ($text =~ s/\A($skip)/$lastsep=$1 and ""/e and   $text =~ s/\Aservices//)
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
        

        Parse::RecDescent::_trace(q{Trying terminal: ['\{']},
                      Parse::RecDescent::_tracefirst($text),
                      q{ServiceBlock},
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
        

        Parse::RecDescent::_trace(q{Trying subrule: [ServiceList]},
                  Parse::RecDescent::_tracefirst($text),
                  q{ServiceBlock},
                  $tracelevel)
                    if defined $::RD_TRACE;
        if (1) { no strict qw{refs};
        $expectation->is(q{ServiceList})->at($text);
        unless (defined ($_tok = Parse::RecDescent::Mace::Dependency::MaceGrammarDependencyRecDescent::ServiceList($thisparser,$text,$repeating,$_noactions,sub { \@arg })))
        {
            
            Parse::RecDescent::_trace(q{<<Didn't match subrule: [ServiceList]>>},
                          Parse::RecDescent::_tracefirst($text),
                          q{ServiceBlock},
                          $tracelevel)
                            if defined $::RD_TRACE;
            $expectation->failed();
            last;
        }
        Parse::RecDescent::_trace(q{>>Matched subrule: [ServiceList]<< (return value: [}
                    . $_tok . q{]},
                      
                      Parse::RecDescent::_tracefirst($text),
                      q{ServiceBlock},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $item{q{ServiceList}} = $_tok;
        push @item, $_tok;
        
        }

        Parse::RecDescent::_trace(q{Trying action},
                      Parse::RecDescent::_tracefirst($text),
                      q{ServiceBlock},
                      $tracelevel)
                        if defined $::RD_TRACE;
        

        $_tok = ($_noactions) ? 0 : do {
    $return = $item{ServiceList}
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
        


        Parse::RecDescent::_trace(q{>>Matched production: ['services' '\{' ServiceList]<<},
                      Parse::RecDescent::_tracefirst($text),
                      q{ServiceBlock},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $_matched = 1;
        last;
    }


    while (!$_matched && !$commit)
    {
        
        Parse::RecDescent::_trace(q{Trying production: []},
                      Parse::RecDescent::_tracefirst($_[1]),
                      q{ServiceBlock},
                      $tracelevel)
                        if defined $::RD_TRACE;
        my $thisprod = $thisrule->{"prods"}[1];
        $text = $_[1];
        my $_savetext;
        @item = (q{ServiceBlock});
        %item = (__RULE__ => q{ServiceBlock});
        my $repcount = 0;


        Parse::RecDescent::_trace(q{Trying action},
                      Parse::RecDescent::_tracefirst($text),
                      q{ServiceBlock},
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
                      q{ServiceBlock},
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
                     q{ServiceBlock},
                     $tracelevel)
                    if defined $::RD_TRACE;
        return undef;
    }
    if (!defined($return) && defined($score))
    {
        Parse::RecDescent::_trace(q{>>Accepted scored production<<}, "",
                      q{ServiceBlock},
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
                      q{ServiceBlock},
                      $tracelevel);
        Parse::RecDescent::_trace(q{(consumed: [} .
                      Parse::RecDescent::_tracemax(substr($_[1],0,-length($text))) . q{])}, 
                      Parse::RecDescent::_tracefirst($text),
                      , q{ServiceBlock},
                      $tracelevel)
    }
    $_[1] = $text;
    return $return;
}

# ARGS ARE: ($parser, $text; $repeating, $_noactions, \@args)
sub Parse::RecDescent::Mace::Dependency::MaceGrammarDependencyRecDescent::Id
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
sub Parse::RecDescent::Mace::Dependency::MaceGrammarDependencyRecDescent::Provides
{
	my $thisparser = $_[0];
	use vars q{$tracelevel};
	local $tracelevel = ($tracelevel||0)+1;
	$ERRORS = 0;
    my $thisrule = $thisparser->{"rules"}{"Provides"};
    
    Parse::RecDescent::_trace(q{Trying rule: [Provides]},
                  Parse::RecDescent::_tracefirst($_[1]),
                  q{Provides},
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
    my $expectation = new Parse::RecDescent::Expectation(q{'provides'});
    $expectation->at($_[1]);
    
    my $thisline;
    tie $thisline, q{Parse::RecDescent::LineCounter}, \$text, $thisparser;

    

    while (!$_matched && !$commit)
    {
        
        Parse::RecDescent::_trace(q{Trying production: ['provides' IdCommaList ';']},
                      Parse::RecDescent::_tracefirst($_[1]),
                      q{Provides},
                      $tracelevel)
                        if defined $::RD_TRACE;
        my $thisprod = $thisrule->{"prods"}[0];
        $text = $_[1];
        my $_savetext;
        @item = (q{Provides});
        %item = (__RULE__ => q{Provides});
        my $repcount = 0;


        Parse::RecDescent::_trace(q{Trying terminal: ['provides']},
                      Parse::RecDescent::_tracefirst($text),
                      q{Provides},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $lastsep = "";
        $expectation->is(q{})->at($text);
        

        unless ($text =~ s/\A($skip)/$lastsep=$1 and ""/e and   $text =~ s/\Aprovides//)
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
                  q{Provides},
                  $tracelevel)
                    if defined $::RD_TRACE;
        if (1) { no strict qw{refs};
        $expectation->is(q{IdCommaList})->at($text);
        unless (defined ($_tok = Parse::RecDescent::Mace::Dependency::MaceGrammarDependencyRecDescent::IdCommaList($thisparser,$text,$repeating,$_noactions,sub { \@arg })))
        {
            
            Parse::RecDescent::_trace(q{<<Didn't match subrule: [IdCommaList]>>},
                          Parse::RecDescent::_tracefirst($text),
                          q{Provides},
                          $tracelevel)
                            if defined $::RD_TRACE;
            $expectation->failed();
            last;
        }
        Parse::RecDescent::_trace(q{>>Matched subrule: [IdCommaList]<< (return value: [}
                    . $_tok . q{]},
                      
                      Parse::RecDescent::_tracefirst($text),
                      q{Provides},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $item{q{IdCommaList}} = $_tok;
        push @item, $_tok;
        
        }

        Parse::RecDescent::_trace(q{Trying terminal: [';']},
                      Parse::RecDescent::_tracefirst($text),
                      q{Provides},
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
                      q{Provides},
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
        


        Parse::RecDescent::_trace(q{>>Matched production: ['provides' IdCommaList ';']<<},
                      Parse::RecDescent::_tracefirst($text),
                      q{Provides},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $_matched = 1;
        last;
    }


    while (!$_matched && !$commit)
    {
        
        Parse::RecDescent::_trace(q{Trying production: []},
                      Parse::RecDescent::_tracefirst($_[1]),
                      q{Provides},
                      $tracelevel)
                        if defined $::RD_TRACE;
        my $thisprod = $thisrule->{"prods"}[1];
        $text = $_[1];
        my $_savetext;
        @item = (q{Provides});
        %item = (__RULE__ => q{Provides});
        my $repcount = 0;


        Parse::RecDescent::_trace(q{Trying action},
                      Parse::RecDescent::_tracefirst($text),
                      q{Provides},
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
                      q{Provides},
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
                     q{Provides},
                     $tracelevel)
                    if defined $::RD_TRACE;
        return undef;
    }
    if (!defined($return) && defined($score))
    {
        Parse::RecDescent::_trace(q{>>Accepted scored production<<}, "",
                      q{Provides},
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
                      q{Provides},
                      $tracelevel);
        Parse::RecDescent::_trace(q{(consumed: [} .
                      Parse::RecDescent::_tracemax(substr($_[1],0,-length($text))) . q{])}, 
                      Parse::RecDescent::_tracefirst($text),
                      , q{Provides},
                      $tracelevel)
    }
    $_[1] = $text;
    return $return;
}

# ARGS ARE: ($parser, $text; $repeating, $_noactions, \@args)
sub Parse::RecDescent::Mace::Dependency::MaceGrammarDependencyRecDescent::IdCommaList
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
        unless (defined ($_tok = Parse::RecDescent::Mace::Dependency::MaceGrammarDependencyRecDescent::Id($thisparser,$text,$repeating,$_noactions,sub { \@arg })))
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
        unless (defined ($_tok = Parse::RecDescent::Mace::Dependency::MaceGrammarDependencyRecDescent::Id($thisparser,$text,$repeating,$_noactions,sub { \@arg })))
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
sub Parse::RecDescent::Mace::Dependency::MaceGrammarDependencyRecDescent::MaceService
{
	my $thisparser = $_[0];
	use vars q{$tracelevel};
	local $tracelevel = ($tracelevel||0)+1;
	$ERRORS = 0;
    my $thisrule = $thisparser->{"rules"}{"MaceService"};
    
    Parse::RecDescent::_trace(q{Trying rule: [MaceService]},
                  Parse::RecDescent::_tracefirst($_[1]),
                  q{MaceService},
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
        Parse::RecDescent::_trace(q{Trying production: [<skip: qr{\s* ((/[*] .*? [*]/|(//[^\n]*\n)|([#]line \s* \d+ \s* ["][^"\r\n]+["])) \s*)*}sx> NonProvidesLine Provides NonServiceLine ServiceBlock]},
                      Parse::RecDescent::_tracefirst($_[1]),
                      q{MaceService},
                      $tracelevel)
                        if defined $::RD_TRACE;
        my $thisprod = $thisrule->{"prods"}[0];
        $text = $_[1];
        my $_savetext;
        @item = (q{MaceService});
        %item = (__RULE__ => q{MaceService});
        my $repcount = 0;


        

        Parse::RecDescent::_trace(q{Trying directive: [<skip: qr{\s* ((/[*] .*? [*]/|(//[^\n]*\n)|([#]line \s* \d+ \s* ["][^"\r\n]+["])) \s*)*}sx>]},
                    Parse::RecDescent::_tracefirst($text),
                      q{MaceService},
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
        

        Parse::RecDescent::_trace(q{Trying repeated subrule: [NonProvidesLine]},
                  Parse::RecDescent::_tracefirst($text),
                  q{MaceService},
                  $tracelevel)
                    if defined $::RD_TRACE;
        $expectation->is(q{NonProvidesLine})->at($text);
        
        unless (defined ($_tok = $thisparser->_parserepeat($text, \&Parse::RecDescent::Mace::Dependency::MaceGrammarDependencyRecDescent::NonProvidesLine, 0, 100000000, $_noactions,$expectation,sub { \@arg }))) 
        {
            Parse::RecDescent::_trace(q{<<Didn't match repeated subrule: [NonProvidesLine]>>},
                          Parse::RecDescent::_tracefirst($text),
                          q{MaceService},
                          $tracelevel)
                            if defined $::RD_TRACE;
            last;
        }
        Parse::RecDescent::_trace(q{>>Matched repeated subrule: [NonProvidesLine]<< (}
                    . @$_tok . q{ times)},
                      
                      Parse::RecDescent::_tracefirst($text),
                      q{MaceService},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $item{q{NonProvidesLine(s?)}} = $_tok;
        push @item, $_tok;
        


        Parse::RecDescent::_trace(q{Trying subrule: [Provides]},
                  Parse::RecDescent::_tracefirst($text),
                  q{MaceService},
                  $tracelevel)
                    if defined $::RD_TRACE;
        if (1) { no strict qw{refs};
        $expectation->is(q{Provides})->at($text);
        unless (defined ($_tok = Parse::RecDescent::Mace::Dependency::MaceGrammarDependencyRecDescent::Provides($thisparser,$text,$repeating,$_noactions,sub { \@arg })))
        {
            
            Parse::RecDescent::_trace(q{<<Didn't match subrule: [Provides]>>},
                          Parse::RecDescent::_tracefirst($text),
                          q{MaceService},
                          $tracelevel)
                            if defined $::RD_TRACE;
            $expectation->failed();
            last;
        }
        Parse::RecDescent::_trace(q{>>Matched subrule: [Provides]<< (return value: [}
                    . $_tok . q{]},
                      
                      Parse::RecDescent::_tracefirst($text),
                      q{MaceService},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $item{q{Provides}} = $_tok;
        push @item, $_tok;
        
        }

        Parse::RecDescent::_trace(q{Trying repeated subrule: [NonServiceLine]},
                  Parse::RecDescent::_tracefirst($text),
                  q{MaceService},
                  $tracelevel)
                    if defined $::RD_TRACE;
        $expectation->is(q{NonServiceLine})->at($text);
        
        unless (defined ($_tok = $thisparser->_parserepeat($text, \&Parse::RecDescent::Mace::Dependency::MaceGrammarDependencyRecDescent::NonServiceLine, 0, 100000000, $_noactions,$expectation,sub { \@arg }))) 
        {
            Parse::RecDescent::_trace(q{<<Didn't match repeated subrule: [NonServiceLine]>>},
                          Parse::RecDescent::_tracefirst($text),
                          q{MaceService},
                          $tracelevel)
                            if defined $::RD_TRACE;
            last;
        }
        Parse::RecDescent::_trace(q{>>Matched repeated subrule: [NonServiceLine]<< (}
                    . @$_tok . q{ times)},
                      
                      Parse::RecDescent::_tracefirst($text),
                      q{MaceService},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $item{q{NonServiceLine(s?)}} = $_tok;
        push @item, $_tok;
        


        Parse::RecDescent::_trace(q{Trying subrule: [ServiceBlock]},
                  Parse::RecDescent::_tracefirst($text),
                  q{MaceService},
                  $tracelevel)
                    if defined $::RD_TRACE;
        if (1) { no strict qw{refs};
        $expectation->is(q{ServiceBlock})->at($text);
        unless (defined ($_tok = Parse::RecDescent::Mace::Dependency::MaceGrammarDependencyRecDescent::ServiceBlock($thisparser,$text,$repeating,$_noactions,sub { \@arg })))
        {
            
            Parse::RecDescent::_trace(q{<<Didn't match subrule: [ServiceBlock]>>},
                          Parse::RecDescent::_tracefirst($text),
                          q{MaceService},
                          $tracelevel)
                            if defined $::RD_TRACE;
            $expectation->failed();
            last;
        }
        Parse::RecDescent::_trace(q{>>Matched subrule: [ServiceBlock]<< (return value: [}
                    . $_tok . q{]},
                      
                      Parse::RecDescent::_tracefirst($text),
                      q{MaceService},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $item{q{ServiceBlock}} = $_tok;
        push @item, $_tok;
        
        }

        Parse::RecDescent::_trace(q{Trying action},
                      Parse::RecDescent::_tracefirst($text),
                      q{MaceService},
                      $tracelevel)
                        if defined $::RD_TRACE;
        

        $_tok = ($_noactions) ? 0 : do {
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
        


        Parse::RecDescent::_trace(q{>>Matched production: [<skip: qr{\s* ((/[*] .*? [*]/|(//[^\n]*\n)|([#]line \s* \d+ \s* ["][^"\r\n]+["])) \s*)*}sx> NonProvidesLine Provides NonServiceLine ServiceBlock]<<},
                      Parse::RecDescent::_tracefirst($text),
                      q{MaceService},
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
                     q{MaceService},
                     $tracelevel)
                    if defined $::RD_TRACE;
        return undef;
    }
    if (!defined($return) && defined($score))
    {
        Parse::RecDescent::_trace(q{>>Accepted scored production<<}, "",
                      q{MaceService},
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
                      q{MaceService},
                      $tracelevel);
        Parse::RecDescent::_trace(q{(consumed: [} .
                      Parse::RecDescent::_tracemax(substr($_[1],0,-length($text))) . q{])}, 
                      Parse::RecDescent::_tracefirst($text),
                      , q{MaceService},
                      $tracelevel)
    }
    $_[1] = $text;
    return $return;
}

# ARGS ARE: ($parser, $text; $repeating, $_noactions, \@args)
sub Parse::RecDescent::Mace::Dependency::MaceGrammarDependencyRecDescent::ServiceItem
{
	my $thisparser = $_[0];
	use vars q{$tracelevel};
	local $tracelevel = ($tracelevel||0)+1;
	$ERRORS = 0;
    my $thisrule = $thisparser->{"rules"}{"ServiceItem"};
    
    Parse::RecDescent::_trace(q{Trying rule: [ServiceItem]},
                  Parse::RecDescent::_tracefirst($_[1]),
                  q{ServiceItem},
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
    my $expectation = new Parse::RecDescent::Expectation(q{InlineFinal});
    $expectation->at($_[1]);
    
    my $thisline;
    tie $thisline, q{Parse::RecDescent::LineCounter}, \$text, $thisparser;

    

    while (!$_matched && !$commit)
    {
        
        Parse::RecDescent::_trace(q{Trying production: [InlineFinal Id /[^=;]*=/ ServiceDefault]},
                      Parse::RecDescent::_tracefirst($_[1]),
                      q{ServiceItem},
                      $tracelevel)
                        if defined $::RD_TRACE;
        my $thisprod = $thisrule->{"prods"}[0];
        $text = $_[1];
        my $_savetext;
        @item = (q{ServiceItem});
        %item = (__RULE__ => q{ServiceItem});
        my $repcount = 0;


        Parse::RecDescent::_trace(q{Trying subrule: [InlineFinal]},
                  Parse::RecDescent::_tracefirst($text),
                  q{ServiceItem},
                  $tracelevel)
                    if defined $::RD_TRACE;
        if (1) { no strict qw{refs};
        $expectation->is(q{})->at($text);
        unless (defined ($_tok = Parse::RecDescent::Mace::Dependency::MaceGrammarDependencyRecDescent::InlineFinal($thisparser,$text,$repeating,$_noactions,sub { \@arg })))
        {
            
            Parse::RecDescent::_trace(q{<<Didn't match subrule: [InlineFinal]>>},
                          Parse::RecDescent::_tracefirst($text),
                          q{ServiceItem},
                          $tracelevel)
                            if defined $::RD_TRACE;
            $expectation->failed();
            last;
        }
        Parse::RecDescent::_trace(q{>>Matched subrule: [InlineFinal]<< (return value: [}
                    . $_tok . q{]},
                      
                      Parse::RecDescent::_tracefirst($text),
                      q{ServiceItem},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $item{q{InlineFinal}} = $_tok;
        push @item, $_tok;
        
        }

        Parse::RecDescent::_trace(q{Trying subrule: [Id]},
                  Parse::RecDescent::_tracefirst($text),
                  q{ServiceItem},
                  $tracelevel)
                    if defined $::RD_TRACE;
        if (1) { no strict qw{refs};
        $expectation->is(q{Id})->at($text);
        unless (defined ($_tok = Parse::RecDescent::Mace::Dependency::MaceGrammarDependencyRecDescent::Id($thisparser,$text,$repeating,$_noactions,sub { \@arg })))
        {
            
            Parse::RecDescent::_trace(q{<<Didn't match subrule: [Id]>>},
                          Parse::RecDescent::_tracefirst($text),
                          q{ServiceItem},
                          $tracelevel)
                            if defined $::RD_TRACE;
            $expectation->failed();
            last;
        }
        Parse::RecDescent::_trace(q{>>Matched subrule: [Id]<< (return value: [}
                    . $_tok . q{]},
                      
                      Parse::RecDescent::_tracefirst($text),
                      q{ServiceItem},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $item{q{Id}} = $_tok;
        push @item, $_tok;
        
        }

        Parse::RecDescent::_trace(q{Trying terminal: [/[^=;]*=/]}, Parse::RecDescent::_tracefirst($text),
                      q{ServiceItem},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $lastsep = "";
        $expectation->is(q{/[^=;]*=/})->at($text);
        

        unless ($text =~ s/\A($skip)/$lastsep=$1 and ""/e and   $text =~ s/\A(?:[^=;]*=)//)
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
        

        Parse::RecDescent::_trace(q{Trying subrule: [ServiceDefault]},
                  Parse::RecDescent::_tracefirst($text),
                  q{ServiceItem},
                  $tracelevel)
                    if defined $::RD_TRACE;
        if (1) { no strict qw{refs};
        $expectation->is(q{ServiceDefault})->at($text);
        unless (defined ($_tok = Parse::RecDescent::Mace::Dependency::MaceGrammarDependencyRecDescent::ServiceDefault($thisparser,$text,$repeating,$_noactions,sub { \@arg })))
        {
            
            Parse::RecDescent::_trace(q{<<Didn't match subrule: [ServiceDefault]>>},
                          Parse::RecDescent::_tracefirst($text),
                          q{ServiceItem},
                          $tracelevel)
                            if defined $::RD_TRACE;
            $expectation->failed();
            last;
        }
        Parse::RecDescent::_trace(q{>>Matched subrule: [ServiceDefault]<< (return value: [}
                    . $_tok . q{]},
                      
                      Parse::RecDescent::_tracefirst($text),
                      q{ServiceItem},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $item{q{ServiceDefault}} = $_tok;
        push @item, $_tok;
        
        }

        Parse::RecDescent::_trace(q{Trying action},
                      Parse::RecDescent::_tracefirst($text),
                      q{ServiceItem},
                      $tracelevel)
                        if defined $::RD_TRACE;
        

        $_tok = ($_noactions) ? 0 : do {
    $return = [ $item{Id}, $item{ServiceDefault}];
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
        


        Parse::RecDescent::_trace(q{>>Matched production: [InlineFinal Id /[^=;]*=/ ServiceDefault]<<},
                      Parse::RecDescent::_tracefirst($text),
                      q{ServiceItem},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $_matched = 1;
        last;
    }


    while (!$_matched && !$commit)
    {
        
        Parse::RecDescent::_trace(q{Trying production: [InlineFinal Id /[^;]*;/]},
                      Parse::RecDescent::_tracefirst($_[1]),
                      q{ServiceItem},
                      $tracelevel)
                        if defined $::RD_TRACE;
        my $thisprod = $thisrule->{"prods"}[1];
        $text = $_[1];
        my $_savetext;
        @item = (q{ServiceItem});
        %item = (__RULE__ => q{ServiceItem});
        my $repcount = 0;


        Parse::RecDescent::_trace(q{Trying subrule: [InlineFinal]},
                  Parse::RecDescent::_tracefirst($text),
                  q{ServiceItem},
                  $tracelevel)
                    if defined $::RD_TRACE;
        if (1) { no strict qw{refs};
        $expectation->is(q{})->at($text);
        unless (defined ($_tok = Parse::RecDescent::Mace::Dependency::MaceGrammarDependencyRecDescent::InlineFinal($thisparser,$text,$repeating,$_noactions,sub { \@arg })))
        {
            
            Parse::RecDescent::_trace(q{<<Didn't match subrule: [InlineFinal]>>},
                          Parse::RecDescent::_tracefirst($text),
                          q{ServiceItem},
                          $tracelevel)
                            if defined $::RD_TRACE;
            $expectation->failed();
            last;
        }
        Parse::RecDescent::_trace(q{>>Matched subrule: [InlineFinal]<< (return value: [}
                    . $_tok . q{]},
                      
                      Parse::RecDescent::_tracefirst($text),
                      q{ServiceItem},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $item{q{InlineFinal}} = $_tok;
        push @item, $_tok;
        
        }

        Parse::RecDescent::_trace(q{Trying subrule: [Id]},
                  Parse::RecDescent::_tracefirst($text),
                  q{ServiceItem},
                  $tracelevel)
                    if defined $::RD_TRACE;
        if (1) { no strict qw{refs};
        $expectation->is(q{Id})->at($text);
        unless (defined ($_tok = Parse::RecDescent::Mace::Dependency::MaceGrammarDependencyRecDescent::Id($thisparser,$text,$repeating,$_noactions,sub { \@arg })))
        {
            
            Parse::RecDescent::_trace(q{<<Didn't match subrule: [Id]>>},
                          Parse::RecDescent::_tracefirst($text),
                          q{ServiceItem},
                          $tracelevel)
                            if defined $::RD_TRACE;
            $expectation->failed();
            last;
        }
        Parse::RecDescent::_trace(q{>>Matched subrule: [Id]<< (return value: [}
                    . $_tok . q{]},
                      
                      Parse::RecDescent::_tracefirst($text),
                      q{ServiceItem},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $item{q{Id}} = $_tok;
        push @item, $_tok;
        
        }

        Parse::RecDescent::_trace(q{Trying terminal: [/[^;]*;/]}, Parse::RecDescent::_tracefirst($text),
                      q{ServiceItem},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $lastsep = "";
        $expectation->is(q{/[^;]*;/})->at($text);
        

        unless ($text =~ s/\A($skip)/$lastsep=$1 and ""/e and   $text =~ s/\A(?:[^;]*;)//)
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
        

        Parse::RecDescent::_trace(q{Trying action},
                      Parse::RecDescent::_tracefirst($text),
                      q{ServiceItem},
                      $tracelevel)
                        if defined $::RD_TRACE;
        

        $_tok = ($_noactions) ? 0 : do {
    $return = [ $item{Id}, "" ];
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
        


        Parse::RecDescent::_trace(q{>>Matched production: [InlineFinal Id /[^;]*;/]<<},
                      Parse::RecDescent::_tracefirst($text),
                      q{ServiceItem},
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
                     q{ServiceItem},
                     $tracelevel)
                    if defined $::RD_TRACE;
        return undef;
    }
    if (!defined($return) && defined($score))
    {
        Parse::RecDescent::_trace(q{>>Accepted scored production<<}, "",
                      q{ServiceItem},
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
                      q{ServiceItem},
                      $tracelevel);
        Parse::RecDescent::_trace(q{(consumed: [} .
                      Parse::RecDescent::_tracemax(substr($_[1],0,-length($text))) . q{])}, 
                      Parse::RecDescent::_tracefirst($text),
                      , q{ServiceItem},
                      $tracelevel)
    }
    $_[1] = $text;
    return $return;
}

# ARGS ARE: ($parser, $text; $repeating, $_noactions, \@args)
sub Parse::RecDescent::Mace::Dependency::MaceGrammarDependencyRecDescent::ServiceList
{
	my $thisparser = $_[0];
	use vars q{$tracelevel};
	local $tracelevel = ($tracelevel||0)+1;
	$ERRORS = 0;
    my $thisrule = $thisparser->{"rules"}{"ServiceList"};
    
    Parse::RecDescent::_trace(q{Trying rule: [ServiceList]},
                  Parse::RecDescent::_tracefirst($_[1]),
                  q{ServiceList},
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
    my $expectation = new Parse::RecDescent::Expectation(q{ServiceItem});
    $expectation->at($_[1]);
    
    my $thisline;
    tie $thisline, q{Parse::RecDescent::LineCounter}, \$text, $thisparser;

    

    while (!$_matched && !$commit)
    {
        
        Parse::RecDescent::_trace(q{Trying production: [ServiceItem]},
                      Parse::RecDescent::_tracefirst($_[1]),
                      q{ServiceList},
                      $tracelevel)
                        if defined $::RD_TRACE;
        my $thisprod = $thisrule->{"prods"}[0];
        $text = $_[1];
        my $_savetext;
        @item = (q{ServiceList});
        %item = (__RULE__ => q{ServiceList});
        my $repcount = 0;


        Parse::RecDescent::_trace(q{Trying repeated subrule: [ServiceItem]},
                  Parse::RecDescent::_tracefirst($text),
                  q{ServiceList},
                  $tracelevel)
                    if defined $::RD_TRACE;
        $expectation->is(q{})->at($text);
        
        unless (defined ($_tok = $thisparser->_parserepeat($text, \&Parse::RecDescent::Mace::Dependency::MaceGrammarDependencyRecDescent::ServiceItem, 0, 100000000, $_noactions,$expectation,sub { \@arg }))) 
        {
            Parse::RecDescent::_trace(q{<<Didn't match repeated subrule: [ServiceItem]>>},
                          Parse::RecDescent::_tracefirst($text),
                          q{ServiceList},
                          $tracelevel)
                            if defined $::RD_TRACE;
            last;
        }
        Parse::RecDescent::_trace(q{>>Matched repeated subrule: [ServiceItem]<< (}
                    . @$_tok . q{ times)},
                      
                      Parse::RecDescent::_tracefirst($text),
                      q{ServiceList},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $item{q{ServiceItem(s?)}} = $_tok;
        push @item, $_tok;
        



        Parse::RecDescent::_trace(q{>>Matched production: [ServiceItem]<<},
                      Parse::RecDescent::_tracefirst($text),
                      q{ServiceList},
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
                     q{ServiceList},
                     $tracelevel)
                    if defined $::RD_TRACE;
        return undef;
    }
    if (!defined($return) && defined($score))
    {
        Parse::RecDescent::_trace(q{>>Accepted scored production<<}, "",
                      q{ServiceList},
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
                      q{ServiceList},
                      $tracelevel);
        Parse::RecDescent::_trace(q{(consumed: [} .
                      Parse::RecDescent::_tracemax(substr($_[1],0,-length($text))) . q{])}, 
                      Parse::RecDescent::_tracefirst($text),
                      , q{ServiceList},
                      $tracelevel)
    }
    $_[1] = $text;
    return $return;
}

# ARGS ARE: ($parser, $text; $repeating, $_noactions, \@args)
sub Parse::RecDescent::Mace::Dependency::MaceGrammarDependencyRecDescent::ProvidesOrService
{
	my $thisparser = $_[0];
	use vars q{$tracelevel};
	local $tracelevel = ($tracelevel||0)+1;
	$ERRORS = 0;
    my $thisrule = $thisparser->{"rules"}{"ProvidesOrService"};
    
    Parse::RecDescent::_trace(q{Trying rule: [ProvidesOrService]},
                  Parse::RecDescent::_tracefirst($_[1]),
                  q{ProvidesOrService},
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
    my $expectation = new Parse::RecDescent::Expectation(q{'provides', or 'services'});
    $expectation->at($_[1]);
    
    my $thisline;
    tie $thisline, q{Parse::RecDescent::LineCounter}, \$text, $thisparser;

    

    while (!$_matched && !$commit)
    {
        
        Parse::RecDescent::_trace(q{Trying production: ['provides']},
                      Parse::RecDescent::_tracefirst($_[1]),
                      q{ProvidesOrService},
                      $tracelevel)
                        if defined $::RD_TRACE;
        my $thisprod = $thisrule->{"prods"}[0];
        $text = $_[1];
        my $_savetext;
        @item = (q{ProvidesOrService});
        %item = (__RULE__ => q{ProvidesOrService});
        my $repcount = 0;


        Parse::RecDescent::_trace(q{Trying terminal: ['provides']},
                      Parse::RecDescent::_tracefirst($text),
                      q{ProvidesOrService},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $lastsep = "";
        $expectation->is(q{})->at($text);
        

        unless ($text =~ s/\A($skip)/$lastsep=$1 and ""/e and   $text =~ s/\Aprovides//)
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
        


        Parse::RecDescent::_trace(q{>>Matched production: ['provides']<<},
                      Parse::RecDescent::_tracefirst($text),
                      q{ProvidesOrService},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $_matched = 1;
        last;
    }


    while (!$_matched && !$commit)
    {
        
        Parse::RecDescent::_trace(q{Trying production: ['services']},
                      Parse::RecDescent::_tracefirst($_[1]),
                      q{ProvidesOrService},
                      $tracelevel)
                        if defined $::RD_TRACE;
        my $thisprod = $thisrule->{"prods"}[1];
        $text = $_[1];
        my $_savetext;
        @item = (q{ProvidesOrService});
        %item = (__RULE__ => q{ProvidesOrService});
        my $repcount = 0;


        Parse::RecDescent::_trace(q{Trying terminal: ['services']},
                      Parse::RecDescent::_tracefirst($text),
                      q{ProvidesOrService},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $lastsep = "";
        $expectation->is(q{})->at($text);
        

        unless ($text =~ s/\A($skip)/$lastsep=$1 and ""/e and   $text =~ s/\Aservices//)
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
        


        Parse::RecDescent::_trace(q{>>Matched production: ['services']<<},
                      Parse::RecDescent::_tracefirst($text),
                      q{ProvidesOrService},
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
                     q{ProvidesOrService},
                     $tracelevel)
                    if defined $::RD_TRACE;
        return undef;
    }
    if (!defined($return) && defined($score))
    {
        Parse::RecDescent::_trace(q{>>Accepted scored production<<}, "",
                      q{ProvidesOrService},
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
                      q{ProvidesOrService},
                      $tracelevel);
        Parse::RecDescent::_trace(q{(consumed: [} .
                      Parse::RecDescent::_tracemax(substr($_[1],0,-length($text))) . q{])}, 
                      Parse::RecDescent::_tracefirst($text),
                      , q{ProvidesOrService},
                      $tracelevel)
    }
    $_[1] = $text;
    return $return;
}

# ARGS ARE: ($parser, $text; $repeating, $_noactions, \@args)
sub Parse::RecDescent::Mace::Dependency::MaceGrammarDependencyRecDescent::NonProvidesLine
{
	my $thisparser = $_[0];
	use vars q{$tracelevel};
	local $tracelevel = ($tracelevel||0)+1;
	$ERRORS = 0;
    my $thisrule = $thisparser->{"rules"}{"NonProvidesLine"};
    
    Parse::RecDescent::_trace(q{Trying rule: [NonProvidesLine]},
                  Parse::RecDescent::_tracefirst($_[1]),
                  q{NonProvidesLine},
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
    my $expectation = new Parse::RecDescent::Expectation(q{ProvidesOrService});
    $expectation->at($_[1]);
    
    my $thisline;
    tie $thisline, q{Parse::RecDescent::LineCounter}, \$text, $thisparser;

    

    while (!$_matched && !$commit)
    {
        
        Parse::RecDescent::_trace(q{Trying production: [ProvidesOrService /.*?\\n/]},
                      Parse::RecDescent::_tracefirst($_[1]),
                      q{NonProvidesLine},
                      $tracelevel)
                        if defined $::RD_TRACE;
        my $thisprod = $thisrule->{"prods"}[0];
        $text = $_[1];
        my $_savetext;
        @item = (q{NonProvidesLine});
        %item = (__RULE__ => q{NonProvidesLine});
        my $repcount = 0;


        Parse::RecDescent::_trace(q{Trying subrule: [ProvidesOrService]},
                  Parse::RecDescent::_tracefirst($text),
                  q{NonProvidesLine},
                  $tracelevel)
                    if defined $::RD_TRACE;
        if (1) { no strict qw{refs};
        $expectation->is(q{})->at($text);
        $_savetext = $text;if (defined ($_tok = Parse::RecDescent::Mace::Dependency::MaceGrammarDependencyRecDescent::ProvidesOrService($thisparser,$text,$repeating,1,sub { \@arg })))
        {
            $text = $_savetext;
            Parse::RecDescent::_trace(q{<<Didn't match subrule: [ProvidesOrService]>>},
                          Parse::RecDescent::_tracefirst($text),
                          q{NonProvidesLine},
                          $tracelevel)
                            if defined $::RD_TRACE;
            $expectation->failed();
            last;
        }
        Parse::RecDescent::_trace(q{>>Matched subrule: [ProvidesOrService]<< (return value: [}
                    . $_tok . q{]},
                      
                      Parse::RecDescent::_tracefirst($text),
                      q{NonProvidesLine},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $item{q{ProvidesOrService}} = $_tok;
        push @item, $_tok;
        $text = $_savetext;
        }

        Parse::RecDescent::_trace(q{Trying terminal: [/.*?\\n/]}, Parse::RecDescent::_tracefirst($text),
                      q{NonProvidesLine},
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
        


        Parse::RecDescent::_trace(q{>>Matched production: [ProvidesOrService /.*?\\n/]<<},
                      Parse::RecDescent::_tracefirst($text),
                      q{NonProvidesLine},
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
                     q{NonProvidesLine},
                     $tracelevel)
                    if defined $::RD_TRACE;
        return undef;
    }
    if (!defined($return) && defined($score))
    {
        Parse::RecDescent::_trace(q{>>Accepted scored production<<}, "",
                      q{NonProvidesLine},
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
                      q{NonProvidesLine},
                      $tracelevel);
        Parse::RecDescent::_trace(q{(consumed: [} .
                      Parse::RecDescent::_tracemax(substr($_[1],0,-length($text))) . q{])}, 
                      Parse::RecDescent::_tracefirst($text),
                      , q{NonProvidesLine},
                      $tracelevel)
    }
    $_[1] = $text;
    return $return;
}

# ARGS ARE: ($parser, $text; $repeating, $_noactions, \@args)
sub Parse::RecDescent::Mace::Dependency::MaceGrammarDependencyRecDescent::NonServiceLine
{
	my $thisparser = $_[0];
	use vars q{$tracelevel};
	local $tracelevel = ($tracelevel||0)+1;
	$ERRORS = 0;
    my $thisrule = $thisparser->{"rules"}{"NonServiceLine"};
    
    Parse::RecDescent::_trace(q{Trying rule: [NonServiceLine]},
                  Parse::RecDescent::_tracefirst($_[1]),
                  q{NonServiceLine},
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
    my $expectation = new Parse::RecDescent::Expectation(q{'services'});
    $expectation->at($_[1]);
    
    my $thisline;
    tie $thisline, q{Parse::RecDescent::LineCounter}, \$text, $thisparser;

    

    while (!$_matched && !$commit)
    {
        
        Parse::RecDescent::_trace(q{Trying production: ['services' /.*?\\n/]},
                      Parse::RecDescent::_tracefirst($_[1]),
                      q{NonServiceLine},
                      $tracelevel)
                        if defined $::RD_TRACE;
        my $thisprod = $thisrule->{"prods"}[0];
        $text = $_[1];
        my $_savetext;
        @item = (q{NonServiceLine});
        %item = (__RULE__ => q{NonServiceLine});
        my $repcount = 0;


        Parse::RecDescent::_trace(q{Trying terminal: ['services']},
                      Parse::RecDescent::_tracefirst($text),
                      q{NonServiceLine},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $lastsep = "";
        $expectation->is(q{})->at($text);
        $_savetext = $text;

        if ($text =~ s/\A($skip)/$lastsep=$1 and ""/e and   $text =~ s/\Aservices//)
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
                      q{NonServiceLine},
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
        


        Parse::RecDescent::_trace(q{>>Matched production: ['services' /.*?\\n/]<<},
                      Parse::RecDescent::_tracefirst($text),
                      q{NonServiceLine},
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
                     q{NonServiceLine},
                     $tracelevel)
                    if defined $::RD_TRACE;
        return undef;
    }
    if (!defined($return) && defined($score))
    {
        Parse::RecDescent::_trace(q{>>Accepted scored production<<}, "",
                      q{NonServiceLine},
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
                      q{NonServiceLine},
                      $tracelevel);
        Parse::RecDescent::_trace(q{(consumed: [} .
                      Parse::RecDescent::_tracemax(substr($_[1],0,-length($text))) . q{])}, 
                      Parse::RecDescent::_tracefirst($text),
                      , q{NonServiceLine},
                      $tracelevel)
    }
    $_[1] = $text;
    return $return;
}

# ARGS ARE: ($parser, $text; $repeating, $_noactions, \@args)
sub Parse::RecDescent::Mace::Dependency::MaceGrammarDependencyRecDescent::ServiceDefault
{
	my $thisparser = $_[0];
	use vars q{$tracelevel};
	local $tracelevel = ($tracelevel||0)+1;
	$ERRORS = 0;
    my $thisrule = $thisparser->{"rules"}{"ServiceDefault"};
    
    Parse::RecDescent::_trace(q{Trying rule: [ServiceDefault]},
                  Parse::RecDescent::_tracefirst($_[1]),
                  q{ServiceDefault},
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
    my $expectation = new Parse::RecDescent::Expectation(q{Id});
    $expectation->at($_[1]);
    
    my $thisline;
    tie $thisline, q{Parse::RecDescent::LineCounter}, \$text, $thisparser;

    

    while (!$_matched && !$commit)
    {
        
        Parse::RecDescent::_trace(q{Trying production: [Id '(' /[^;]*;/]},
                      Parse::RecDescent::_tracefirst($_[1]),
                      q{ServiceDefault},
                      $tracelevel)
                        if defined $::RD_TRACE;
        my $thisprod = $thisrule->{"prods"}[0];
        $text = $_[1];
        my $_savetext;
        @item = (q{ServiceDefault});
        %item = (__RULE__ => q{ServiceDefault});
        my $repcount = 0;


        Parse::RecDescent::_trace(q{Trying subrule: [Id]},
                  Parse::RecDescent::_tracefirst($text),
                  q{ServiceDefault},
                  $tracelevel)
                    if defined $::RD_TRACE;
        if (1) { no strict qw{refs};
        $expectation->is(q{})->at($text);
        unless (defined ($_tok = Parse::RecDescent::Mace::Dependency::MaceGrammarDependencyRecDescent::Id($thisparser,$text,$repeating,$_noactions,sub { \@arg })))
        {
            
            Parse::RecDescent::_trace(q{<<Didn't match subrule: [Id]>>},
                          Parse::RecDescent::_tracefirst($text),
                          q{ServiceDefault},
                          $tracelevel)
                            if defined $::RD_TRACE;
            $expectation->failed();
            last;
        }
        Parse::RecDescent::_trace(q{>>Matched subrule: [Id]<< (return value: [}
                    . $_tok . q{]},
                      
                      Parse::RecDescent::_tracefirst($text),
                      q{ServiceDefault},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $item{q{Id}} = $_tok;
        push @item, $_tok;
        
        }

        Parse::RecDescent::_trace(q{Trying terminal: ['(']},
                      Parse::RecDescent::_tracefirst($text),
                      q{ServiceDefault},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $lastsep = "";
        $expectation->is(q{'('})->at($text);
        

        unless ($text =~ s/\A($skip)/$lastsep=$1 and ""/e and   $text =~ s/\A\(//)
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
        

        Parse::RecDescent::_trace(q{Trying terminal: [/[^;]*;/]}, Parse::RecDescent::_tracefirst($text),
                      q{ServiceDefault},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $lastsep = "";
        $expectation->is(q{/[^;]*;/})->at($text);
        

        unless ($text =~ s/\A($skip)/$lastsep=$1 and ""/e and   $text =~ s/\A(?:[^;]*;)//)
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
        

        Parse::RecDescent::_trace(q{Trying action},
                      Parse::RecDescent::_tracefirst($text),
                      q{ServiceDefault},
                      $tracelevel)
                        if defined $::RD_TRACE;
        

        $_tok = ($_noactions) ? 0 : do {
    $return = $item{Id}
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
        


        Parse::RecDescent::_trace(q{>>Matched production: [Id '(' /[^;]*;/]<<},
                      Parse::RecDescent::_tracefirst($text),
                      q{ServiceDefault},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $_matched = 1;
        last;
    }


    while (!$_matched && !$commit)
    {
        
        Parse::RecDescent::_trace(q{Trying production: [Id /[^;]*;/]},
                      Parse::RecDescent::_tracefirst($_[1]),
                      q{ServiceDefault},
                      $tracelevel)
                        if defined $::RD_TRACE;
        my $thisprod = $thisrule->{"prods"}[1];
        $text = $_[1];
        my $_savetext;
        @item = (q{ServiceDefault});
        %item = (__RULE__ => q{ServiceDefault});
        my $repcount = 0;


        Parse::RecDescent::_trace(q{Trying subrule: [Id]},
                  Parse::RecDescent::_tracefirst($text),
                  q{ServiceDefault},
                  $tracelevel)
                    if defined $::RD_TRACE;
        if (1) { no strict qw{refs};
        $expectation->is(q{})->at($text);
        unless (defined ($_tok = Parse::RecDescent::Mace::Dependency::MaceGrammarDependencyRecDescent::Id($thisparser,$text,$repeating,$_noactions,sub { \@arg })))
        {
            
            Parse::RecDescent::_trace(q{<<Didn't match subrule: [Id]>>},
                          Parse::RecDescent::_tracefirst($text),
                          q{ServiceDefault},
                          $tracelevel)
                            if defined $::RD_TRACE;
            $expectation->failed();
            last;
        }
        Parse::RecDescent::_trace(q{>>Matched subrule: [Id]<< (return value: [}
                    . $_tok . q{]},
                      
                      Parse::RecDescent::_tracefirst($text),
                      q{ServiceDefault},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $item{q{Id}} = $_tok;
        push @item, $_tok;
        
        }

        Parse::RecDescent::_trace(q{Trying terminal: [/[^;]*;/]}, Parse::RecDescent::_tracefirst($text),
                      q{ServiceDefault},
                      $tracelevel)
                        if defined $::RD_TRACE;
        $lastsep = "";
        $expectation->is(q{/[^;]*;/})->at($text);
        

        unless ($text =~ s/\A($skip)/$lastsep=$1 and ""/e and   $text =~ s/\A(?:[^;]*;)//)
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
        

        Parse::RecDescent::_trace(q{Trying action},
                      Parse::RecDescent::_tracefirst($text),
                      q{ServiceDefault},
                      $tracelevel)
                        if defined $::RD_TRACE;
        

        $_tok = ($_noactions) ? 0 : do { $return = ""; };
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
        


        Parse::RecDescent::_trace(q{>>Matched production: [Id /[^;]*;/]<<},
                      Parse::RecDescent::_tracefirst($text),
                      q{ServiceDefault},
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
                     q{ServiceDefault},
                     $tracelevel)
                    if defined $::RD_TRACE;
        return undef;
    }
    if (!defined($return) && defined($score))
    {
        Parse::RecDescent::_trace(q{>>Accepted scored production<<}, "",
                      q{ServiceDefault},
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
                      q{ServiceDefault},
                      $tracelevel);
        Parse::RecDescent::_trace(q{(consumed: [} .
                      Parse::RecDescent::_tracemax(substr($_[1],0,-length($text))) . q{])}, 
                      Parse::RecDescent::_tracefirst($text),
                      , q{ServiceDefault},
                      $tracelevel)
    }
    $_[1] = $text;
    return $return;
}
}
package Mace::Dependency::MaceGrammarDependencyRecDescent; sub new { my $self = bless( {
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
                 'namespace' => 'Parse::RecDescent::Mace::Dependency::MaceGrammarDependencyRecDescent',
                 '_AUTOACTION' => undef,
                 'rules' => {
                              'InlineFinal' => bless( {
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
                                                                              'patcount' => 0,
                                                                              'actcount' => 0,
                                                                              'items' => [
                                                                                           bless( {
                                                                                                    'pattern' => 'inline',
                                                                                                    'hashname' => '__STRING1__',
                                                                                                    'description' => '\'inline\'',
                                                                                                    'lookahead' => 0,
                                                                                                    'line' => 46
                                                                                                  }, 'Parse::RecDescent::Literal' )
                                                                                         ],
                                                                              'line' => undef
                                                                            }, 'Parse::RecDescent::Production' ),
                                                                     bless( {
                                                                              'number' => 1,
                                                                              'strcount' => 1,
                                                                              'dircount' => 0,
                                                                              'uncommit' => undef,
                                                                              'error' => undef,
                                                                              'patcount' => 0,
                                                                              'actcount' => 0,
                                                                              'items' => [
                                                                                           bless( {
                                                                                                    'pattern' => 'final',
                                                                                                    'hashname' => '__STRING1__',
                                                                                                    'description' => '\'final\'',
                                                                                                    'lookahead' => 0,
                                                                                                    'line' => 46
                                                                                                  }, 'Parse::RecDescent::Literal' )
                                                                                         ],
                                                                              'line' => 46
                                                                            }, 'Parse::RecDescent::Production' ),
                                                                     bless( {
                                                                              'number' => 2,
                                                                              'strcount' => 0,
                                                                              'dircount' => 0,
                                                                              'uncommit' => undef,
                                                                              'error' => undef,
                                                                              'patcount' => 0,
                                                                              'actcount' => 0,
                                                                              'items' => [],
                                                                              'line' => 46
                                                                            }, 'Parse::RecDescent::Production' )
                                                                   ],
                                                        'name' => 'InlineFinal',
                                                        'vars' => '',
                                                        'line' => 46
                                                      }, 'Parse::RecDescent::Rule' ),
                              'ServiceBlock' => bless( {
                                                         'impcount' => 0,
                                                         'calls' => [
                                                                      'ServiceList'
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
                                                                                                     'pattern' => 'services',
                                                                                                     'hashname' => '__STRING1__',
                                                                                                     'description' => '\'services\'',
                                                                                                     'lookahead' => 0,
                                                                                                     'line' => 36
                                                                                                   }, 'Parse::RecDescent::Literal' ),
                                                                                            bless( {
                                                                                                     'pattern' => '{',
                                                                                                     'hashname' => '__STRING2__',
                                                                                                     'description' => '\'\\{\'',
                                                                                                     'lookahead' => 0,
                                                                                                     'line' => 36
                                                                                                   }, 'Parse::RecDescent::Literal' ),
                                                                                            bless( {
                                                                                                     'subrule' => 'ServiceList',
                                                                                                     'matchrule' => 0,
                                                                                                     'implicit' => undef,
                                                                                                     'argcode' => undef,
                                                                                                     'lookahead' => 0,
                                                                                                     'line' => 36
                                                                                                   }, 'Parse::RecDescent::Subrule' ),
                                                                                            bless( {
                                                                                                     'hashname' => '__ACTION1__',
                                                                                                     'lookahead' => 0,
                                                                                                     'line' => 37,
                                                                                                     'code' => '{
    $return = $item{ServiceList}
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
                                                                                                     'line' => 40,
                                                                                                     'code' => '{ $return = []; }'
                                                                                                   }, 'Parse::RecDescent::Action' )
                                                                                          ],
                                                                               'line' => 40
                                                                             }, 'Parse::RecDescent::Production' )
                                                                    ],
                                                         'name' => 'ServiceBlock',
                                                         'vars' => '',
                                                         'line' => 36
                                                       }, 'Parse::RecDescent::Rule' ),
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
                                                                                           'line' => 43,
                                                                                           'mod' => '',
                                                                                           'ldelim' => '/'
                                                                                         }, 'Parse::RecDescent::Token' )
                                                                                ],
                                                                     'line' => undef
                                                                   }, 'Parse::RecDescent::Production' )
                                                          ],
                                               'name' => 'Id',
                                               'vars' => '',
                                               'line' => 43
                                             }, 'Parse::RecDescent::Rule' ),
                              'Provides' => bless( {
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
                                                                                                 'pattern' => 'provides',
                                                                                                 'hashname' => '__STRING1__',
                                                                                                 'description' => '\'provides\'',
                                                                                                 'lookahead' => 0,
                                                                                                 'line' => 28
                                                                                               }, 'Parse::RecDescent::Literal' ),
                                                                                        bless( {
                                                                                                 'subrule' => 'IdCommaList',
                                                                                                 'matchrule' => 0,
                                                                                                 'implicit' => undef,
                                                                                                 'argcode' => undef,
                                                                                                 'lookahead' => 0,
                                                                                                 'line' => 28
                                                                                               }, 'Parse::RecDescent::Subrule' ),
                                                                                        bless( {
                                                                                                 'pattern' => ';',
                                                                                                 'hashname' => '__STRING2__',
                                                                                                 'description' => '\';\'',
                                                                                                 'lookahead' => 0,
                                                                                                 'line' => 28
                                                                                               }, 'Parse::RecDescent::Literal' ),
                                                                                        bless( {
                                                                                                 'hashname' => '__ACTION1__',
                                                                                                 'lookahead' => 0,
                                                                                                 'line' => 29,
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
                                                                                                 'line' => 32,
                                                                                                 'code' => '{ $return = []; }'
                                                                                               }, 'Parse::RecDescent::Action' )
                                                                                      ],
                                                                           'line' => 32
                                                                         }, 'Parse::RecDescent::Production' )
                                                                ],
                                                     'name' => 'Provides',
                                                     'vars' => '',
                                                     'line' => 28
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
                                                                                                                          'line' => 44
                                                                                                                        }, 'Parse::RecDescent::Subrule' ),
                                                                                                    'rightarg' => bless( {
                                                                                                                           'subrule' => 'Id',
                                                                                                                           'matchrule' => 0,
                                                                                                                           'implicit' => undef,
                                                                                                                           'argcode' => undef,
                                                                                                                           'lookahead' => 0,
                                                                                                                           'line' => 44
                                                                                                                         }, 'Parse::RecDescent::Subrule' ),
                                                                                                    'hashname' => '__DIRECTIVE1__',
                                                                                                    'type' => 'leftop',
                                                                                                    'op' => bless( {
                                                                                                                     'pattern' => ',',
                                                                                                                     'hashname' => '__PATTERN1__',
                                                                                                                     'description' => '/,/',
                                                                                                                     'lookahead' => 0,
                                                                                                                     'rdelim' => '/',
                                                                                                                     'line' => 44,
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
                                                        'line' => 44
                                                      }, 'Parse::RecDescent::Rule' ),
                              'MaceService' => bless( {
                                                        'impcount' => 0,
                                                        'calls' => [
                                                                     'NonProvidesLine',
                                                                     'Provides',
                                                                     'NonServiceLine',
                                                                     'ServiceBlock'
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
                                                                              'actcount' => 1,
                                                                              'items' => [
                                                                                           bless( {
                                                                                                    'hashname' => '__DIRECTIVE1__',
                                                                                                    'name' => '<skip: qr{\\s* ((/[*] .*? [*]/|(//[^\\n]*\\n)|([#]line \\s* \\d+ \\s* ["][^"\\r\\n]+["])) \\s*)*}sx>',
                                                                                                    'lookahead' => 0,
                                                                                                    'line' => 3,
                                                                                                    'code' => 'my $oldskip = $skip; $skip= qr{\\s* ((/[*] .*? [*]/|(//[^\\n]*\\n)|([#]line \\s* \\d+ \\s* ["][^"\\r\\n]+["])) \\s*)*}sx; $oldskip'
                                                                                                  }, 'Parse::RecDescent::Directive' ),
                                                                                           bless( {
                                                                                                    'subrule' => 'NonProvidesLine',
                                                                                                    'expected' => undef,
                                                                                                    'min' => 0,
                                                                                                    'argcode' => undef,
                                                                                                    'max' => 100000000,
                                                                                                    'matchrule' => 0,
                                                                                                    'repspec' => 's?',
                                                                                                    'lookahead' => 0,
                                                                                                    'line' => 3
                                                                                                  }, 'Parse::RecDescent::Repetition' ),
                                                                                           bless( {
                                                                                                    'subrule' => 'Provides',
                                                                                                    'matchrule' => 0,
                                                                                                    'implicit' => undef,
                                                                                                    'argcode' => undef,
                                                                                                    'lookahead' => 0,
                                                                                                    'line' => 3
                                                                                                  }, 'Parse::RecDescent::Subrule' ),
                                                                                           bless( {
                                                                                                    'subrule' => 'NonServiceLine',
                                                                                                    'expected' => undef,
                                                                                                    'min' => 0,
                                                                                                    'argcode' => undef,
                                                                                                    'max' => 100000000,
                                                                                                    'matchrule' => 0,
                                                                                                    'repspec' => 's?',
                                                                                                    'lookahead' => 0,
                                                                                                    'line' => 3
                                                                                                  }, 'Parse::RecDescent::Repetition' ),
                                                                                           bless( {
                                                                                                    'subrule' => 'ServiceBlock',
                                                                                                    'matchrule' => 0,
                                                                                                    'implicit' => undef,
                                                                                                    'argcode' => undef,
                                                                                                    'lookahead' => 0,
                                                                                                    'line' => 3
                                                                                                  }, 'Parse::RecDescent::Subrule' ),
                                                                                           bless( {
                                                                                                    'hashname' => '__ACTION1__',
                                                                                                    'lookahead' => 0,
                                                                                                    'line' => 4,
                                                                                                    'code' => '{
    my @vars;
    if (scalar(@{$item{Provides}}) or scalar(@{$item{ServiceBlock}})) {
        $arg{vars}->{$arg{name}."Service_dep"} = "SET(".$arg{name}."Service_dep \\${ServiceClass_h}" .
               join(\'\', map {" \\${${_}ServiceClass_dep}"} @{$item{Provides}}) . 
               join(\'\', map {" \\${".@{${_}}[0]."ServiceClass_dep}"} @{$item{ServiceBlock}}) .
               ")\\n";
        $arg{vars}->{$arg{name}."Service_tgt_dep"} = "SET(".$arg{name}."Service_tgt_dep ServiceClass_dep" .
               join(\'\', map {" ${_}ServiceClass_dep"} @{$item{Provides}}) . 
               join(\'\', map {" ".@{${_}}[0]."ServiceClass_dep"} @{$item{ServiceBlock}}) . 
               ")\\n";
    }
    $arg{vars}->{$arg{name}."Service_sv_dep"} = "SET(".$arg{name}."Service_sv_dep ".$arg{name} .
           join(\'\', map {" \\${".@{${_}}[1]."Service_sv_dep}"} @{$item{ServiceBlock}}) .
           ")\\n";
    $arg{vars}->{$arg{name}."Service_sv_list"} = "SET(".$arg{name}."Service_sv_list ".
           join(\'\', map {" ".@{${_}}[1]} @{$item{ServiceBlock}}) .
           ")\\n";
    $return = 1;
}'
                                                                                                  }, 'Parse::RecDescent::Action' )
                                                                                         ],
                                                                              'line' => undef
                                                                            }, 'Parse::RecDescent::Production' )
                                                                   ],
                                                        'name' => 'MaceService',
                                                        'vars' => '',
                                                        'line' => 1
                                                      }, 'Parse::RecDescent::Rule' ),
                              'ServiceItem' => bless( {
                                                        'impcount' => 0,
                                                        'calls' => [
                                                                     'InlineFinal',
                                                                     'Id',
                                                                     'ServiceDefault'
                                                                   ],
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
                                                                              'actcount' => 1,
                                                                              'items' => [
                                                                                           bless( {
                                                                                                    'subrule' => 'InlineFinal',
                                                                                                    'matchrule' => 0,
                                                                                                    'implicit' => undef,
                                                                                                    'argcode' => undef,
                                                                                                    'lookahead' => 0,
                                                                                                    'line' => 52
                                                                                                  }, 'Parse::RecDescent::Subrule' ),
                                                                                           bless( {
                                                                                                    'subrule' => 'Id',
                                                                                                    'matchrule' => 0,
                                                                                                    'implicit' => undef,
                                                                                                    'argcode' => undef,
                                                                                                    'lookahead' => 0,
                                                                                                    'line' => 52
                                                                                                  }, 'Parse::RecDescent::Subrule' ),
                                                                                           bless( {
                                                                                                    'pattern' => '[^=;]*=',
                                                                                                    'hashname' => '__PATTERN1__',
                                                                                                    'description' => '/[^=;]*=/',
                                                                                                    'lookahead' => 0,
                                                                                                    'rdelim' => '/',
                                                                                                    'line' => 52,
                                                                                                    'mod' => '',
                                                                                                    'ldelim' => '/'
                                                                                                  }, 'Parse::RecDescent::Token' ),
                                                                                           bless( {
                                                                                                    'subrule' => 'ServiceDefault',
                                                                                                    'matchrule' => 0,
                                                                                                    'implicit' => undef,
                                                                                                    'argcode' => undef,
                                                                                                    'lookahead' => 0,
                                                                                                    'line' => 52
                                                                                                  }, 'Parse::RecDescent::Subrule' ),
                                                                                           bless( {
                                                                                                    'hashname' => '__ACTION1__',
                                                                                                    'lookahead' => 0,
                                                                                                    'line' => 53,
                                                                                                    'code' => '{
    $return = [ $item{Id}, $item{ServiceDefault}];
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
                                                                              'patcount' => 1,
                                                                              'actcount' => 1,
                                                                              'items' => [
                                                                                           bless( {
                                                                                                    'subrule' => 'InlineFinal',
                                                                                                    'matchrule' => 0,
                                                                                                    'implicit' => undef,
                                                                                                    'argcode' => undef,
                                                                                                    'lookahead' => 0,
                                                                                                    'line' => 56
                                                                                                  }, 'Parse::RecDescent::Subrule' ),
                                                                                           bless( {
                                                                                                    'subrule' => 'Id',
                                                                                                    'matchrule' => 0,
                                                                                                    'implicit' => undef,
                                                                                                    'argcode' => undef,
                                                                                                    'lookahead' => 0,
                                                                                                    'line' => 56
                                                                                                  }, 'Parse::RecDescent::Subrule' ),
                                                                                           bless( {
                                                                                                    'pattern' => '[^;]*;',
                                                                                                    'hashname' => '__PATTERN1__',
                                                                                                    'description' => '/[^;]*;/',
                                                                                                    'lookahead' => 0,
                                                                                                    'rdelim' => '/',
                                                                                                    'line' => 56,
                                                                                                    'mod' => '',
                                                                                                    'ldelim' => '/'
                                                                                                  }, 'Parse::RecDescent::Token' ),
                                                                                           bless( {
                                                                                                    'hashname' => '__ACTION1__',
                                                                                                    'lookahead' => 0,
                                                                                                    'line' => 57,
                                                                                                    'code' => '{
    $return = [ $item{Id}, "" ];
}'
                                                                                                  }, 'Parse::RecDescent::Action' )
                                                                                         ],
                                                                              'line' => 56
                                                                            }, 'Parse::RecDescent::Production' )
                                                                   ],
                                                        'name' => 'ServiceItem',
                                                        'vars' => '',
                                                        'line' => 52
                                                      }, 'Parse::RecDescent::Rule' ),
                              'ServiceList' => bless( {
                                                        'impcount' => 0,
                                                        'calls' => [
                                                                     'ServiceItem'
                                                                   ],
                                                        'changed' => 0,
                                                        'opcount' => 0,
                                                        'prods' => [
                                                                     bless( {
                                                                              'number' => 0,
                                                                              'strcount' => 0,
                                                                              'dircount' => 0,
                                                                              'uncommit' => undef,
                                                                              'error' => undef,
                                                                              'patcount' => 0,
                                                                              'actcount' => 0,
                                                                              'items' => [
                                                                                           bless( {
                                                                                                    'subrule' => 'ServiceItem',
                                                                                                    'expected' => undef,
                                                                                                    'min' => 0,
                                                                                                    'argcode' => undef,
                                                                                                    'max' => 100000000,
                                                                                                    'matchrule' => 0,
                                                                                                    'repspec' => 's?',
                                                                                                    'lookahead' => 0,
                                                                                                    'line' => 60
                                                                                                  }, 'Parse::RecDescent::Repetition' )
                                                                                         ],
                                                                              'line' => undef
                                                                            }, 'Parse::RecDescent::Production' )
                                                                   ],
                                                        'name' => 'ServiceList',
                                                        'vars' => '',
                                                        'line' => 60
                                                      }, 'Parse::RecDescent::Rule' ),
                              'ProvidesOrService' => bless( {
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
                                                                                    'patcount' => 0,
                                                                                    'actcount' => 0,
                                                                                    'items' => [
                                                                                                 bless( {
                                                                                                          'pattern' => 'provides',
                                                                                                          'hashname' => '__STRING1__',
                                                                                                          'description' => '\'provides\'',
                                                                                                          'lookahead' => 0,
                                                                                                          'line' => 25
                                                                                                        }, 'Parse::RecDescent::Literal' )
                                                                                               ],
                                                                                    'line' => undef
                                                                                  }, 'Parse::RecDescent::Production' ),
                                                                           bless( {
                                                                                    'number' => 1,
                                                                                    'strcount' => 1,
                                                                                    'dircount' => 0,
                                                                                    'uncommit' => undef,
                                                                                    'error' => undef,
                                                                                    'patcount' => 0,
                                                                                    'actcount' => 0,
                                                                                    'items' => [
                                                                                                 bless( {
                                                                                                          'pattern' => 'services',
                                                                                                          'hashname' => '__STRING1__',
                                                                                                          'description' => '\'services\'',
                                                                                                          'lookahead' => 0,
                                                                                                          'line' => 25
                                                                                                        }, 'Parse::RecDescent::Literal' )
                                                                                               ],
                                                                                    'line' => 25
                                                                                  }, 'Parse::RecDescent::Production' )
                                                                         ],
                                                              'name' => 'ProvidesOrService',
                                                              'vars' => '',
                                                              'line' => 25
                                                            }, 'Parse::RecDescent::Rule' ),
                              'NonProvidesLine' => bless( {
                                                            'impcount' => 0,
                                                            'calls' => [
                                                                         'ProvidesOrService'
                                                                       ],
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
                                                                                                        'subrule' => 'ProvidesOrService',
                                                                                                        'matchrule' => 0,
                                                                                                        'implicit' => undef,
                                                                                                        'argcode' => undef,
                                                                                                        'lookahead' => -1,
                                                                                                        'line' => 26
                                                                                                      }, 'Parse::RecDescent::Subrule' ),
                                                                                               bless( {
                                                                                                        'pattern' => '.*?\\n',
                                                                                                        'hashname' => '__PATTERN1__',
                                                                                                        'description' => '/.*?\\\\n/',
                                                                                                        'lookahead' => 0,
                                                                                                        'rdelim' => '/',
                                                                                                        'line' => 26,
                                                                                                        'mod' => '',
                                                                                                        'ldelim' => '/'
                                                                                                      }, 'Parse::RecDescent::Token' )
                                                                                             ],
                                                                                  'line' => undef
                                                                                }, 'Parse::RecDescent::Production' )
                                                                       ],
                                                            'name' => 'NonProvidesLine',
                                                            'vars' => '',
                                                            'line' => 26
                                                          }, 'Parse::RecDescent::Rule' ),
                              'NonServiceLine' => bless( {
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
                                                                                                       'pattern' => 'services',
                                                                                                       'hashname' => '__STRING1__',
                                                                                                       'description' => '\'services\'',
                                                                                                       'lookahead' => -1,
                                                                                                       'line' => 34
                                                                                                     }, 'Parse::RecDescent::Literal' ),
                                                                                              bless( {
                                                                                                       'pattern' => '.*?\\n',
                                                                                                       'hashname' => '__PATTERN1__',
                                                                                                       'description' => '/.*?\\\\n/',
                                                                                                       'lookahead' => 0,
                                                                                                       'rdelim' => '/',
                                                                                                       'line' => 34,
                                                                                                       'mod' => '',
                                                                                                       'ldelim' => '/'
                                                                                                     }, 'Parse::RecDescent::Token' )
                                                                                            ],
                                                                                 'line' => undef
                                                                               }, 'Parse::RecDescent::Production' )
                                                                      ],
                                                           'name' => 'NonServiceLine',
                                                           'vars' => '',
                                                           'line' => 34
                                                         }, 'Parse::RecDescent::Rule' ),
                              'ServiceDefault' => bless( {
                                                           'impcount' => 0,
                                                           'calls' => [
                                                                        'Id'
                                                                      ],
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
                                                                                 'actcount' => 1,
                                                                                 'items' => [
                                                                                              bless( {
                                                                                                       'subrule' => 'Id',
                                                                                                       'matchrule' => 0,
                                                                                                       'implicit' => undef,
                                                                                                       'argcode' => undef,
                                                                                                       'lookahead' => 0,
                                                                                                       'line' => 47
                                                                                                     }, 'Parse::RecDescent::Subrule' ),
                                                                                              bless( {
                                                                                                       'pattern' => '(',
                                                                                                       'hashname' => '__STRING1__',
                                                                                                       'description' => '\'(\'',
                                                                                                       'lookahead' => 0,
                                                                                                       'line' => 47
                                                                                                     }, 'Parse::RecDescent::Literal' ),
                                                                                              bless( {
                                                                                                       'pattern' => '[^;]*;',
                                                                                                       'hashname' => '__PATTERN1__',
                                                                                                       'description' => '/[^;]*;/',
                                                                                                       'lookahead' => 0,
                                                                                                       'rdelim' => '/',
                                                                                                       'line' => 47,
                                                                                                       'mod' => '',
                                                                                                       'ldelim' => '/'
                                                                                                     }, 'Parse::RecDescent::Token' ),
                                                                                              bless( {
                                                                                                       'hashname' => '__ACTION1__',
                                                                                                       'lookahead' => 0,
                                                                                                       'line' => 48,
                                                                                                       'code' => '{
    $return = $item{Id}
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
                                                                                 'patcount' => 1,
                                                                                 'actcount' => 1,
                                                                                 'items' => [
                                                                                              bless( {
                                                                                                       'subrule' => 'Id',
                                                                                                       'matchrule' => 0,
                                                                                                       'implicit' => undef,
                                                                                                       'argcode' => undef,
                                                                                                       'lookahead' => 0,
                                                                                                       'line' => 51
                                                                                                     }, 'Parse::RecDescent::Subrule' ),
                                                                                              bless( {
                                                                                                       'pattern' => '[^;]*;',
                                                                                                       'hashname' => '__PATTERN1__',
                                                                                                       'description' => '/[^;]*;/',
                                                                                                       'lookahead' => 0,
                                                                                                       'rdelim' => '/',
                                                                                                       'line' => 51,
                                                                                                       'mod' => '',
                                                                                                       'ldelim' => '/'
                                                                                                     }, 'Parse::RecDescent::Token' ),
                                                                                              bless( {
                                                                                                       'hashname' => '__ACTION1__',
                                                                                                       'lookahead' => 0,
                                                                                                       'line' => 51,
                                                                                                       'code' => '{ $return = ""; }'
                                                                                                     }, 'Parse::RecDescent::Action' )
                                                                                            ],
                                                                                 'line' => 51
                                                                               }, 'Parse::RecDescent::Production' )
                                                                      ],
                                                           'name' => 'ServiceDefault',
                                                           'vars' => '',
                                                           'line' => 47
                                                         }, 'Parse::RecDescent::Rule' )
                            }
               }, 'Parse::RecDescent' );
}