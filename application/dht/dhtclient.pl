#!/usr/bin/perl -w

use strict;
use Frontier::Client;
use Time::HiRes qw(gettimeofday tv_interval);

my $serverURL = 'http://localhost:6666/xmlrpc';
my $client = Frontier::Client->new('url' => $serverURL,
                                   'debug' => 0);

unless (scalar(@ARGV)) {
    printUsage();
}

my $command = shift(@ARGV);
my $key = shift(@ARGV) || "";
unless ($key) {
    printUsage();
}

my @margs = ($key);
my $method = "StringDHT.";
if ($command eq "lookup") {
    $method .= "containsKey";
}
elsif ($command eq "get") {
    $method .= "get";
}
elsif ($command eq "put") {
    $method .= "put";
    my $value = shift(@ARGV) || "";
    unless ($value) {
	printUsage();
    }
    push(@margs, $value);
}
elsif ($command eq "remove") {
    $method .= "remove";
}
else {
    die "unrecognized command $command\n";
}

my $start = [gettimeofday()];
my $r = $client->call($method, @margs);
my $elapsed = tv_interval($start);

# use Data::Dumper;
# print Dumper($r);

if ($command eq "get") {
    my ($v, $f) = @$r;
    print $f->value() . "\n$v\n";
}
elsif ($command eq "lookup") {
    print $r->value() . "\n";
}
else {
    print "$r\n";
}
print "took $elapsed\n";

sub printUsage {
    die "usage: $0 <command> [<options>]\n" .
	"    lookup <key>\n" .
	"    get <key>\n".
	"    put <key> <value>\n" .
	"    remove <key>\n" .
	"\n";
} # printUsage
