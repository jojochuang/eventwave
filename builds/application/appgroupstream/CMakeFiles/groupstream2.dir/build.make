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
include application/appgroupstream/CMakeFiles/groupstream2.dir/depend.make

# Include the progress variables for this target.
include application/appgroupstream/CMakeFiles/groupstream2.dir/progress.make

# Include the compile flags for this target's objects.
include application/appgroupstream/CMakeFiles/groupstream2.dir/flags.make

application/appgroupstream/CMakeFiles/groupstream2.dir/groupstream2.o: application/appgroupstream/CMakeFiles/groupstream2.dir/flags.make
application/appgroupstream/CMakeFiles/groupstream2.dir/groupstream2.o: ../application/appgroupstream/groupstream2.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object application/appgroupstream/CMakeFiles/groupstream2.dir/groupstream2.o"
	cd /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/application/appgroupstream && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/groupstream2.dir/groupstream2.o -c /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/application/appgroupstream/groupstream2.cc

application/appgroupstream/CMakeFiles/groupstream2.dir/groupstream2.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/groupstream2.dir/groupstream2.i"
	cd /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/application/appgroupstream && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/application/appgroupstream/groupstream2.cc > CMakeFiles/groupstream2.dir/groupstream2.i

application/appgroupstream/CMakeFiles/groupstream2.dir/groupstream2.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/groupstream2.dir/groupstream2.s"
	cd /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/application/appgroupstream && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/application/appgroupstream/groupstream2.cc -o CMakeFiles/groupstream2.dir/groupstream2.s

application/appgroupstream/CMakeFiles/groupstream2.dir/groupstream2.o.requires:
.PHONY : application/appgroupstream/CMakeFiles/groupstream2.dir/groupstream2.o.requires

application/appgroupstream/CMakeFiles/groupstream2.dir/groupstream2.o.provides: application/appgroupstream/CMakeFiles/groupstream2.dir/groupstream2.o.requires
	$(MAKE) -f application/appgroupstream/CMakeFiles/groupstream2.dir/build.make application/appgroupstream/CMakeFiles/groupstream2.dir/groupstream2.o.provides.build
.PHONY : application/appgroupstream/CMakeFiles/groupstream2.dir/groupstream2.o.provides

application/appgroupstream/CMakeFiles/groupstream2.dir/groupstream2.o.provides.build: application/appgroupstream/CMakeFiles/groupstream2.dir/groupstream2.o

# Object files for target groupstream2
groupstream2_OBJECTS = \
"CMakeFiles/groupstream2.dir/groupstream2.o"

# External object files for target groupstream2
groupstream2_EXTERNAL_OBJECTS =

application/appgroupstream/groupstream2: application/appgroupstream/CMakeFiles/groupstream2.dir/groupstream2.o
application/appgroupstream/groupstream2: services/Bamboo/libBamboo.a
application/appgroupstream/groupstream2: services/ReplayTree/libReplayTree.a
application/appgroupstream/groupstream2: services/RandTree/libRandTree.a
application/appgroupstream/groupstream2: services/GenericTreeMulticast/libGenericTreeMulticast.a
application/appgroupstream/groupstream2: services/SignedMulticast/libSignedMulticast.a
application/appgroupstream/groupstream2: services/Pastry/libPastry.a
application/appgroupstream/groupstream2: services/ScribeMS/libScribeMS.a
application/appgroupstream/groupstream2: services/GenericOverlayRoute/libGenericOverlayRoute.a
application/appgroupstream/groupstream2: services/Transport/libTransport.a
application/appgroupstream/groupstream2: services/interfaces/libinterfaces.a
application/appgroupstream/groupstream2: lib/libmace.a
application/appgroupstream/groupstream2: services/GenericTreeMulticast/libGenericTreeMulticast.a
application/appgroupstream/groupstream2: services/interfaces/libinterfaces.a
application/appgroupstream/groupstream2: lib/libmace.a
application/appgroupstream/groupstream2: /usr/lib64/libpthread.so
application/appgroupstream/groupstream2: /usr/lib64/libcrypto.so
application/appgroupstream/groupstream2: /usr/lib64/libssl.so
application/appgroupstream/groupstream2: /usr/lib64/libcrypto.so
application/appgroupstream/groupstream2: /usr/lib64/libssl.so
application/appgroupstream/groupstream2: /usr/lib64/libgsl.so
application/appgroupstream/groupstream2: /usr/lib64/libgslcblas.so
application/appgroupstream/groupstream2: /usr/lib64/libz.so
application/appgroupstream/groupstream2: /usr/lib64/libdl.so
application/appgroupstream/groupstream2: /usr/lib64/libgslcblas.so
application/appgroupstream/groupstream2: /usr/lib64/libz.so
application/appgroupstream/groupstream2: /usr/lib64/libdl.so
application/appgroupstream/groupstream2: application/appgroupstream/CMakeFiles/groupstream2.dir/build.make
application/appgroupstream/groupstream2: application/appgroupstream/CMakeFiles/groupstream2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable groupstream2"
	cd /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/application/appgroupstream && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/groupstream2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
application/appgroupstream/CMakeFiles/groupstream2.dir/build: application/appgroupstream/groupstream2
.PHONY : application/appgroupstream/CMakeFiles/groupstream2.dir/build

application/appgroupstream/CMakeFiles/groupstream2.dir/requires: application/appgroupstream/CMakeFiles/groupstream2.dir/groupstream2.o.requires
.PHONY : application/appgroupstream/CMakeFiles/groupstream2.dir/requires

application/appgroupstream/CMakeFiles/groupstream2.dir/clean:
	cd /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/application/appgroupstream && $(CMAKE_COMMAND) -P CMakeFiles/groupstream2.dir/cmake_clean.cmake
.PHONY : application/appgroupstream/CMakeFiles/groupstream2.dir/clean

application/appgroupstream/CMakeFiles/groupstream2.dir/depend:
	cd /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/application/appgroupstream /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/application/appgroupstream /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/application/appgroupstream/CMakeFiles/groupstream2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : application/appgroupstream/CMakeFiles/groupstream2.dir/depend

