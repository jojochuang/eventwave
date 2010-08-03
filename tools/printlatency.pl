#!/usr/bin/perl

use strict;

my $lc = 0;
my %h = ();
my %stats = ();

while (my $l = <>) {
    $lc++;
    if ($l =~ m|^\d+\.\d+\s(\d+)\s+(\w+)|) {
# 	print "$1\t$2\n";
	my $lat = $1;
	my $el = $2;
	$h{$el} = "$lat $lc";
	my $s = { };
	if (!defined($stats{$el})) {
	    $stats{$el} = $s;
	}
	$s = $stats{$el};
	$s->{cum} += $lat;
	$s->{count}++;
	if (!defined($s->{min}) || $lat < $s->{min}) {
	    $s->{min} = $lat;
	}
	if (!defined($s->{max}) || $lat > $s->{max}) {
	    $s->{max} = $lat;
	}
    }
}

# use Data::Dumper;
# while (my ($k, $v) = each(%stats)) {
#     print "$k\n";
#     print Dumper($v);
# }

# for my $el (sort { $b <=> $a } keys(%h)) {
#     print "$el " . $h{$el} . "\n";
# }

my ($sel, $total, $count, $min, $max, $avg);

format STDOUT=
@<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< total: @######### count: @###### min: @##### max: @###### avg: @######
$sel,                                                                           $total,           $count,      $min,        $max,        $avg
.


for my $k (sort { $stats{$b}->{cum} <=> $stats{$a}->{cum} } keys(%stats)) {
    my $s = $stats{$k};
    $sel = $k;
    $total = $s->{cum};
    $count = $s->{count};
    $min = $s->{min};
    $max = $s->{max};
    $avg = $total / $count;
    write();
}
