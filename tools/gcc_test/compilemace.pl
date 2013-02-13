#!/usr/bin/perl

# chuangw: by default, this script runs for all versions of gcc in $gcc_dir.
# to change the default, appen parameters: e.g. -ver=4.5.1 or -v for short
# also, you can also change the gcc build directory by -dir=/scratch/chuangw/blah or -d for short
# Finall, the number of parallel builds can be change by e.g. -parallel_build=8 or -p for short

use strict;
use Getopt::Long;

my $gcc_dir="/scratch/chuangw/opt";
my $parallel_build = 4;
my $gcc_ver = "all";
GetOptions("parallel_build" => \$parallel_build,
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

  `make clean 2>&1 | tee $ver.log`;
  `cmake  -D CMAKE_CXX_COMPILER=$ver/bin/g++ .. 2>&1 | tee -a $ver.log`;
  `make -j $parallel_build 2>&1 | tee -a $ver.log`;
  `make test 2>&1 | tee -a $ver.log`;

}
