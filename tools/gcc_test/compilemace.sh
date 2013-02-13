#!/bin/bash

# NOTICE: This script assumes you are at the mace build directory.
gcc_dir=/scratch/chuangw/opt
parallel_build=4

for ver in $gcc_dir/*
do
  echo "Compile ContextLattice using " $ver
  make clean
  cmake  -D CMAKE_CXX_COMPILER=$ver/bin/g++ ..
  make -j $parallel_build
  make test
done
