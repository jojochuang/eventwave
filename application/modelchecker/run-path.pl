#!/usr/bin/perl -w

use strict;

my $replayFile = shift(@ARGV) || "";
unless (-e $replayFile) {
    print "usage: $0 replayFile\n";
    exit(1);
}

my $path = ".";
if ($0 =~ m|(.*)/run-path.pl|) {
    $path = $1;
}
my $mc = "$path/modelchecker";
my $gengraph = "$path/generateEventGraph.pl";
my $parsescoped = "$path/parse-scoped-serialize.pl";
my $errorlog = "error.log";
my $errorgraph = "error.graph";

print "running modelchecker with path $replayFile...\n";
system("$mc -RANDOM_REPLAY_FILE $replayFile -TRACE_ALL 1 -max_num_steps 2000 | $parsescoped > $errorlog");
print "generating error graph to $errorgraph...\n";
system("$gengraph -w 2000 -o $errorgraph $errorlog");

