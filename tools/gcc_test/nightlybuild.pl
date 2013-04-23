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
GetOptions(
  "repo=s" => \$repo_url,
  "branch=s" => \$branch_name,
  "prefix=s" => \$prefix_dir,
  );

mkdir $prefix_dir;
chdir $prefix_dir or die "can't enter the directory $prefix_dir";
remove_tree("mace-fullcontext");
system("hg clone $repo_url");
chdir "mace-fullcontext" or die "can't enter the directory mace-fullcontext";
mkdir "build";
chdir "build" or die "can't enter the build directory";
#system("./compilemace.pl -p 2 "); # test all available gcc versions, default build
system("../tools/gcc_test/compilemace.pl -p 1 -b relwithdebinfo "); # test all available gcc versions, relwithdebinfo (-O2 -g) build

# other possible CMake build options: Release (-O3), RelWithDebInfo (-O2 -g), Debug (-g), MinSizeRel (-Os -DNDEBUG)


# TODO: output the result into a HTML viewable on the internet.
