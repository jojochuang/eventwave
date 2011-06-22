#!/usr/bin/perl -w

use strict;

use FindBin;
use lib "$FindBin::Bin";
use SimulatorScriptsCommon;

my $replayFile = shift(@ARGV) || "";
unless (-e $replayFile) {
    print "usage: $0 replayFile\n";
    exit(1);
}

my $path = $FindBin::Bin;
my $mc = findSimulator();
my $gengraph = "$path/generateEventGraph.pl";
my $parsescoped = "$path/parse-scoped-serialize.pl";
my $errorlog = "error.log";
my $errorgraph = "error.graph";

print "running modelchecker with path $replayFile...\n";
system("$mc -RANDOM_REPLAY_FILE $replayFile -TRACE_ALL 1 -max_num_steps 2000 | $parsescoped > $errorlog");
print "generating error graph to $errorgraph...\n";
system("$gengraph -w 2000 -o $errorgraph $errorlog");

