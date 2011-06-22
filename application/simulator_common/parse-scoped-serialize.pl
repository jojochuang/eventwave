#!/usr/bin/perl -w

use strict;

# my $f = $ARGV[0] || "";
# unless (-f $f) {
#     print "usage: $0 file\n";
#     exit(1);
# }

my %s = ();

# open(F, $f) or die "cannot open $f: $!\n";

# while (my $l = <F>) {
#     if ($l =~ m|\[ScopedSerialize\] (\d+) (.*)|) {
# 	$s{$1} = $2;
# # 	print "adding $1 -> $2\n";
#     }
# }
# close(F);
# open(F, $f) or die "cannot open $f: $!\n";

# while (my $l = <F>) {
#     if ($l =~ m|\[ScopedSerialize\] (\d+) (.*)|) {
# 	next;
#     }
#     while ($l =~ m|\(str\)\[(\d+)\]|) {
# 	my $k = $1;
# 	if (defined($s{$k})) {
# 	    my $v = $s{$k};
# 	    $l =~ s|\(str\)\[$k\]|$v|g;
# 	}
# 	else {
# 	    $l =~ s|\(str\)\[$k\]|\(str\)$k|g;
# 	}
#     }
#     print $l;
# }

# close(F);

while (my $l = <>) {
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
	print $l;
    }
}
