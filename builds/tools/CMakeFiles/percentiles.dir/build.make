# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds

# Include any dependencies generated for this target.
include tools/CMakeFiles/percentiles.dir/depend.make

# Include the progress variables for this target.
include tools/CMakeFiles/percentiles.dir/progress.make

# Include the compile flags for this target's objects.
include tools/CMakeFiles/percentiles.dir/flags.make

tools/CMakeFiles/percentiles.dir/percentiles.o: tools/CMakeFiles/percentiles.dir/flags.make
tools/CMakeFiles/percentiles.dir/percentiles.o: ../tools/percentiles.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object tools/CMakeFiles/percentiles.dir/percentiles.o"
	cd /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/tools && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/percentiles.dir/percentiles.o -c /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/tools/percentiles.cc

tools/CMakeFiles/percentiles.dir/percentiles.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/percentiles.dir/percentiles.i"
	cd /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/tools && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/tools/percentiles.cc > CMakeFiles/percentiles.dir/percentiles.i

tools/CMakeFiles/percentiles.dir/percentiles.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/percentiles.dir/percentiles.s"
	cd /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/tools && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/tools/percentiles.cc -o CMakeFiles/percentiles.dir/percentiles.s

tools/CMakeFiles/percentiles.dir/percentiles.o.requires:
.PHONY : tools/CMakeFiles/percentiles.dir/percentiles.o.requires

tools/CMakeFiles/percentiles.dir/percentiles.o.provides: tools/CMakeFiles/percentiles.dir/percentiles.o.requires
	$(MAKE) -f tools/CMakeFiles/percentiles.dir/build.make tools/CMakeFiles/percentiles.dir/percentiles.o.provides.build
.PHONY : tools/CMakeFiles/percentiles.dir/percentiles.o.provides

tools/CMakeFiles/percentiles.dir/percentiles.o.provides.build: tools/CMakeFiles/percentiles.dir/percentiles.o

# Object files for target percentiles
percentiles_OBJECTS = \
"CMakeFiles/percentiles.dir/percentiles.o"

# External object files for target percentiles
percentiles_EXTERNAL_OBJECTS =

tools/percentiles: tools/CMakeFiles/percentiles.dir/percentiles.o
tools/percentiles: lib/libmace.a
tools/percentiles: /usr/lib64/libpthread.so
tools/percentiles: /usr/lib64/libcrypto.so
tools/percentiles: /usr/lib64/libssl.so
tools/percentiles: /usr/lib64/libcrypto.so
tools/percentiles: /usr/lib64/libssl.so
tools/percentiles: /usr/lib64/libgsl.so
tools/percentiles: /usr/lib64/libgslcblas.so
tools/percentiles: /usr/lib64/libz.so
tools/percentiles: /usr/lib64/libdl.so
tools/percentiles: /usr/lib64/libgslcblas.so
tools/percentiles: /usr/lib64/libz.so
tools/percentiles: /usr/lib64/libdl.so
tools/percentiles: tools/CMakeFiles/percentiles.dir/build.make
tools/percentiles: tools/CMakeFiles/percentiles.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable percentiles"
	cd /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/tools && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/percentiles.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tools/CMakeFiles/percentiles.dir/build: tools/percentiles
.PHONY : tools/CMakeFiles/percentiles.dir/build

tools/CMakeFiles/percentiles.dir/requires: tools/CMakeFiles/percentiles.dir/percentiles.o.requires
.PHONY : tools/CMakeFiles/percentiles.dir/requires

tools/CMakeFiles/percentiles.dir/clean:
	cd /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/tools && $(CMAKE_COMMAND) -P CMakeFiles/percentiles.dir/cmake_clean.cmake
.PHONY : tools/CMakeFiles/percentiles.dir/clean

tools/CMakeFiles/percentiles.dir/depend:
	cd /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/tools /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/tools /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/tools/CMakeFiles/percentiles.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tools/CMakeFiles/percentiles.dir/depend

