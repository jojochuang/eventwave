#!/usr/bin/perl

# chuangw: by default, this script runs for all versions of gcc in $gcc_dir.
# to change the default, appen parameters: e.g. -ver=gcc-4.5.1 or -v for short
# also, you can also change the gcc build directory by -dir=/scratch/chuangw/blah or -d for short
# Finall, the number of parallel builds can be change by e.g. -parallel_build=8 or -p for short

use strict;
use Getopt::Long;

my $gcc_dir="/scratch/chuangw/opt";
my $parallel_build = 4;
my $gcc_ver = "all";
GetOptions("parallel_build=i" => \$parallel_build,
           "ver=s" => \$gcc_ver,
           "dir=s" => \$gcc_dir,
       );


if( $gcc_ver eq "all" ){

  my $all_ver_str = `find $gcc_dir/* -maxdepth 0 -type d`;
  my @all_ver = split ("\n", $all_ver_str);
  foreach my $ver ( @all_ver ) {

    test_ver( $ver );
  }
}else{
    test_ver( "$gcc_dir/$gcc_ver" );
}

sub test_ver {
  my $ver = shift;
  print "Testing version $ver\n";

  system("make clean 2>&1 | tee $ver.log") == 0 or die "failed to make clean";
  system("cmake -D CMAKE_CXX_COMPILER=$ver/bin/g++ .. 2>&1 | tee -a $ver.log") == 0 or die "failed to configure makefiles";
  system("make -j $parallel_build 2>&1 | tee -a $ver.log") == 0 or die "failed to make all services";
  system("make test 2>&1 | tee -a $ver.log") == 0 or die "failed to pass test cases";

}
