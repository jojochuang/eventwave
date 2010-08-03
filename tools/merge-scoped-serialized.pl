#!/usr/bin/perl -w

use strict;
use FileHandle;

if (scalar(@ARGV) < 2) {
    print "usage: $0 dir file [file ...]\n";
    exit(1);
}

my $dir = shift(@ARGV);
mkdir($dir) or die "cannot mkdir $dir: $!\n";

my %f = ();
my %o = ();

for my $el (@ARGV) {
    print "opening $el\n";
    my $fh = new FileHandle;
    if ($fh->open("< $el")) {
	$f{$el} = $fh;
    }
    else {
	die "cannot open $el: $!\n";
    }

    my $oh = new FileHandle;
    if ($oh->open("> $dir/$el\n")) {
	$o{$el} = $oh;
    }
    else {
	die "cannot open $dir/el: $!\n";
    }
}

my %s = ();

my %lines = ();
my $last = "";

while (my ($k, $fh) = each(%f)) {
    if (my $l = <$fh>) {
	if ($l =~ m|\d+\.\d{6}|) {
	    $lines{$k} = $l;
	}
	else {
	    die "no timestamp: $l\n";
	}
    }
    else {
	delete($f{$k});
    }
}

while (scalar(%lines)) {
    my $l = nextLine();
    if ($l =~ m|\[ScopedSerialize\] (\d+) (.*)|) {
	$s{$1} = $2;
# 	print "adding $1 -> $2\n";
    }
    else {
	while ($l =~ m|\(str\)\[(\d+)\]|) {
	    my $k = $1;
	    if (defined($s{$k})) {
		my $v = $s{$k};
		$l =~ s|\(str\)\[$k\]|$v|g;
	    }
	    else {
		$l =~ s|\(str\)\[$k\]|\(str\)$k|g;
	    }
	}
	my $fh = $o{$last};
	print $fh $l;
    }
}

sub nextLine {
    if ($last) {
	my $fh = $f{$last};
	if (my $l = <$fh>) {
	    if ($l =~ m|\d+\.\d{6}|) {
		$lines{$last} = $l;
	    }
	    else {
		die "no timestamp: $l\n";
	    }
	}
	else {
	    delete($f{$last});
	}
    }
    my @sorted = sort {
	substr($lines{$a}, 0, 17) <=> substr($lines{$b}, 0, 17)
    } keys(%lines);
    $last = shift(@sorted);
    my $r = $lines{$last};
    delete($lines{$last});
    return $r;
} # nextLine
