#!/usr/bin/perl

use strict;
use POSIX ":sys_wait_h";

my $n = shift(@ARGV);
my ($server, $url, @args) = @ARGV;
# my $cmd = shift(@ARGV);

unless ($n and $server and $url) {
    die "usage: $0 n-processes server url";
}

my @servers = split(/,/, $server);

my @children = ();
for my $i (1..$n) {
    my $pid;
    if ($pid = fork()) {
	push(@children, $pid);
    }
    else {
	push(@args, "--clientprefix", $i);
	exec("./httpget", $servers[$i % scalar(@servers)] . $url, @args);
    }
}

while (scalar(@children) > 0) {
    waitpid($children[0], 0);
    shift(@children);
}
