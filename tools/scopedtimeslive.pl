#!/usr/bin/perl -w

use strict;

my %stack = ();
my %stats = ();

while (my $l = <>) {
    chomp($l);
    unless ($l =~ m/(STARTING|ENDING)/) {
	next;
    }
    
    my @a = split(/ /, $l);
    my $sc = scalar(@a);
    
    my $time = 0;
    my $sel = "";
    my $bound = "";
    if (scalar(@a) == 5) {
	$time = shift(@a);
	shift(@a); # thread id
	$sel = shift(@a);
	shift(@a); # scoped log
	$bound = shift(@a);
    }

    if ($bound eq "STARTING") {
	push(@{$stack{$sel}}, $time);
    }
    elsif ($bound eq "ENDING") {
	my $start = pop(@{$stack{$sel}});
	my $diff = $time - $start;
	my $s = { };
	if (!defined($stats{$sel})) {
	    $stats{$sel} = $s;
	}
	$s = $stats{$sel};
	$s->{cum} += $diff;
	$s->{count}++;
	if (!defined($s->{min}) || $diff < $s->{min}) {
	    $s->{min} = $diff;
	}
	if (!defined($s->{max}) || $diff > $s->{max}) {
	    $s->{max} = $diff;
	}
    }
    else {
	warn "ignoring unknown bound $bound\n";
    }
}

my ($sel, $total, $count, $min, $max, $avg);

format STDOUT=
@<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< total: @###.###### count: @###### min: @##### max: @###### avg: @######
$sel,                                                                           $total,           $count,      $min,        $max,        $avg
.



for my $k (sort { $stats{$b}->{cum} <=> $stats{$a}->{cum} } keys(%stats)) {
    my $s = $stats{$k};
    $sel = $k;
    $total = $s->{cum};
    $count = $s->{count};
    $min = $s->{min} * 1000000;
    $max = $s->{max} * 1000000;
    $avg = $total * 1000000 / $count;
    write();
}
