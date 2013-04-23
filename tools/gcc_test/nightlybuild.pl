#!/usr/bin/perl
# download the latest revision in the repository ('default' branch by default)
# and compile the code using different version of gcc
# and mail the result
# usage:
#   add a cron entry ( crontab -e )
# #MIN HOUR DAY MONTH DAYOFWEEK   COMMAND
# 0 4 * * * /scratch/chuangw/mace-fullcontext/tools/gcc_test/nightlybuild.pl


use strict;
use Getopt::Long;
use File::Path qw(remove_tree);

my $repo_url = "ssh://hg\@bitbucket.org/chuangw/mace-fullcontext";
my $branch_name = "default"; # test default branch
my $prefix_dir = "/scratch/chuangw/nightlybuild"; # this is where the test code is placed
my $report_dir;
if( -e $ENV{"HOME"} ){
  $report_dir = $ENV{"HOME"} . "/.www/contextlattice";
}
GetOptions(
  "repo=s" => \$repo_url,
  "branch=s" => \$branch_name,
  "prefix=s" => \$prefix_dir,
  "log" => \$report_dir,
  );

mkdir $prefix_dir;
chdir $prefix_dir or die "can't enter the directory $prefix_dir";
remove_tree("mace-fullcontext");
system("hg clone -b $branch_name $repo_url");
chdir "mace-fullcontext" or die "can't enter the directory mace-fullcontext";
my $latest_revision_hash;
#my $latest_revision_hash = `hg id -i`; # revision hash id
chomp( $latest_revision_hash= `hg id -n`); # local, numerical revision id
if( not -e $report_dir ){
  mkdir "$report_dir" or die "can't create directory $report_dir";
  chmod 0755, "$report_dir";
}
if( not -e "$report_dir/$latest_revision_hash" ){
  mkdir "$report_dir/$latest_revision_hash" or die "can't create directory $report_dir/$latest_revision_hash";
  chmod 0755, "$report_dir/$latest_revision_hash";
}
mkdir "build";
chdir "build" or die "can't enter the build directory";

my $log_filename = "$report_dir/$latest_revision_hash/$latest_revision_hash.log";
open( LOGFILE, '>', $log_filename );
print "log is available at $log_filename\n";
chmod 0755, $log_filename;
#system("../tools/gcc_test/compilemace.pl -p 1 -b relwithdebinfo "); # test all available gcc versions, relwithdebinfo (-O2 -g) build
open(my $compilemace, '-|', '../tools/gcc_test/compilemace.pl', '-p', '1', '-b', 'relwithdebinfo') or die "can't open pipe to start compiling mace"; # test all available     gcc versions, relwithdebinfo (-O2 -g) build
while( my $line = <$compilemace> ){
  print LOGFILE $line;
  #print ".";
  print $line;
}
close LOGFILE;
close $compilemace;


