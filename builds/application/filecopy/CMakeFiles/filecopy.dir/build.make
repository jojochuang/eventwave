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
include application/filecopy/CMakeFiles/filecopy.dir/depend.make

# Include the progress variables for this target.
include application/filecopy/CMakeFiles/filecopy.dir/progress.make

# Include the compile flags for this target's objects.
include application/filecopy/CMakeFiles/filecopy.dir/flags.make

application/filecopy/CMakeFiles/filecopy.dir/filecopy.o: application/filecopy/CMakeFiles/filecopy.dir/flags.make
application/filecopy/CMakeFiles/filecopy.dir/filecopy.o: ../application/filecopy/filecopy.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object application/filecopy/CMakeFiles/filecopy.dir/filecopy.o"
	cd /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/application/filecopy && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/filecopy.dir/filecopy.o -c /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/application/filecopy/filecopy.cc

application/filecopy/CMakeFiles/filecopy.dir/filecopy.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/filecopy.dir/filecopy.i"
	cd /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/application/filecopy && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/application/filecopy/filecopy.cc > CMakeFiles/filecopy.dir/filecopy.i

application/filecopy/CMakeFiles/filecopy.dir/filecopy.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/filecopy.dir/filecopy.s"
	cd /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/application/filecopy && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/application/filecopy/filecopy.cc -o CMakeFiles/filecopy.dir/filecopy.s

application/filecopy/CMakeFiles/filecopy.dir/filecopy.o.requires:
.PHONY : application/filecopy/CMakeFiles/filecopy.dir/filecopy.o.requires

application/filecopy/CMakeFiles/filecopy.dir/filecopy.o.provides: application/filecopy/CMakeFiles/filecopy.dir/filecopy.o.requires
	$(MAKE) -f application/filecopy/CMakeFiles/filecopy.dir/build.make application/filecopy/CMakeFiles/filecopy.dir/filecopy.o.provides.build
.PHONY : application/filecopy/CMakeFiles/filecopy.dir/filecopy.o.provides

application/filecopy/CMakeFiles/filecopy.dir/filecopy.o.provides.build: application/filecopy/CMakeFiles/filecopy.dir/filecopy.o

# Object files for target filecopy
filecopy_OBJECTS = \
"CMakeFiles/filecopy.dir/filecopy.o"

# External object files for target filecopy
filecopy_EXTERNAL_OBJECTS =

application/filecopy/filecopy: application/filecopy/CMakeFiles/filecopy.dir/filecopy.o
application/filecopy/filecopy: services/Transport/libTransport.a
application/filecopy/filecopy: application/common/libappcommon.a
application/filecopy/filecopy: services/interfaces/libinterfaces.a
application/filecopy/filecopy: lib/libmace.a
application/filecopy/filecopy: /usr/lib64/libpthread.so
application/filecopy/filecopy: /usr/lib64/libcrypto.so
application/filecopy/filecopy: /usr/lib64/libssl.so
application/filecopy/filecopy: /usr/lib64/libcrypto.so
application/filecopy/filecopy: /usr/lib64/libssl.so
application/filecopy/filecopy: /usr/lib64/libgsl.so
application/filecopy/filecopy: /usr/lib64/libgslcblas.so
application/filecopy/filecopy: /usr/lib64/libz.so
application/filecopy/filecopy: /usr/lib64/libdl.so
application/filecopy/filecopy: /usr/lib64/libgslcblas.so
application/filecopy/filecopy: /usr/lib64/libz.so
application/filecopy/filecopy: /usr/lib64/libdl.so
application/filecopy/filecopy: application/filecopy/CMakeFiles/filecopy.dir/build.make
application/filecopy/filecopy: application/filecopy/CMakeFiles/filecopy.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable filecopy"
	cd /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/application/filecopy && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/filecopy.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
application/filecopy/CMakeFiles/filecopy.dir/build: application/filecopy/filecopy
.PHONY : application/filecopy/CMakeFiles/filecopy.dir/build

application/filecopy/CMakeFiles/filecopy.dir/requires: application/filecopy/CMakeFiles/filecopy.dir/filecopy.o.requires
.PHONY : application/filecopy/CMakeFiles/filecopy.dir/requires

application/filecopy/CMakeFiles/filecopy.dir/clean:
	cd /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/application/filecopy && $(CMAKE_COMMAND) -P CMakeFiles/filecopy.dir/cmake_clean.cmake
.PHONY : application/filecopy/CMakeFiles/filecopy.dir/clean

application/filecopy/CMakeFiles/filecopy.dir/depend:
	cd /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/application/filecopy /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/application/filecopy /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/application/filecopy/CMakeFiles/filecopy.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : application/filecopy/CMakeFiles/filecopy.dir/depend

