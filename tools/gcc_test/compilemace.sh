#!/bin/bash

# NOTICE: This script assumes you are at the mace build directory.
gcc_dir=/scratch/chuangw/opt
parallel_build=8

for ver in $gcc_dir
do
  make clean
  cmake  -D CMAKE_CXX_COMPILER=$gcc_dir/$ver/bin/g++ ..
  make -j $parallel_build
  make test
done
