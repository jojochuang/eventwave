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
include application/http/CMakeFiles/testwebserver.dir/depend.make

# Include the progress variables for this target.
include application/http/CMakeFiles/testwebserver.dir/progress.make

# Include the compile flags for this target's objects.
include application/http/CMakeFiles/testwebserver.dir/flags.make

application/http/CMakeFiles/testwebserver.dir/testwebserver.o: application/http/CMakeFiles/testwebserver.dir/flags.make
application/http/CMakeFiles/testwebserver.dir/testwebserver.o: ../application/http/testwebserver.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object application/http/CMakeFiles/testwebserver.dir/testwebserver.o"
	cd /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/application/http && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/testwebserver.dir/testwebserver.o -c /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/application/http/testwebserver.cc

application/http/CMakeFiles/testwebserver.dir/testwebserver.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testwebserver.dir/testwebserver.i"
	cd /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/application/http && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/application/http/testwebserver.cc > CMakeFiles/testwebserver.dir/testwebserver.i

application/http/CMakeFiles/testwebserver.dir/testwebserver.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testwebserver.dir/testwebserver.s"
	cd /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/application/http && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/application/http/testwebserver.cc -o CMakeFiles/testwebserver.dir/testwebserver.s

application/http/CMakeFiles/testwebserver.dir/testwebserver.o.requires:
.PHONY : application/http/CMakeFiles/testwebserver.dir/testwebserver.o.requires

application/http/CMakeFiles/testwebserver.dir/testwebserver.o.provides: application/http/CMakeFiles/testwebserver.dir/testwebserver.o.requires
	$(MAKE) -f application/http/CMakeFiles/testwebserver.dir/build.make application/http/CMakeFiles/testwebserver.dir/testwebserver.o.provides.build
.PHONY : application/http/CMakeFiles/testwebserver.dir/testwebserver.o.provides

application/http/CMakeFiles/testwebserver.dir/testwebserver.o.provides.build: application/http/CMakeFiles/testwebserver.dir/testwebserver.o

# Object files for target testwebserver
testwebserver_OBJECTS = \
"CMakeFiles/testwebserver.dir/testwebserver.o"

# External object files for target testwebserver
testwebserver_EXTERNAL_OBJECTS =

application/http/testwebserver: application/http/CMakeFiles/testwebserver.dir/testwebserver.o
application/http/testwebserver: services/Http/libHttp.a
application/http/testwebserver: services/Http/libHttp.a
application/http/testwebserver: application/common/libappcommon.a
application/http/testwebserver: services/interfaces/libinterfaces.a
application/http/testwebserver: lib/libmace.a
application/http/testwebserver: /usr/lib64/libpthread.so
application/http/testwebserver: /usr/lib64/libcrypto.so
application/http/testwebserver: /usr/lib64/libssl.so
application/http/testwebserver: /usr/lib64/libcrypto.so
application/http/testwebserver: /usr/lib64/libssl.so
application/http/testwebserver: /usr/lib64/libgsl.so
application/http/testwebserver: /usr/lib64/libgslcblas.so
application/http/testwebserver: /usr/lib64/libz.so
application/http/testwebserver: /usr/lib64/libdl.so
application/http/testwebserver: /usr/lib64/libgslcblas.so
application/http/testwebserver: /usr/lib64/libz.so
application/http/testwebserver: /usr/lib64/libdl.so
application/http/testwebserver: application/http/CMakeFiles/testwebserver.dir/build.make
application/http/testwebserver: application/http/CMakeFiles/testwebserver.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable testwebserver"
	cd /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/application/http && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testwebserver.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
application/http/CMakeFiles/testwebserver.dir/build: application/http/testwebserver
.PHONY : application/http/CMakeFiles/testwebserver.dir/build

application/http/CMakeFiles/testwebserver.dir/requires: application/http/CMakeFiles/testwebserver.dir/testwebserver.o.requires
.PHONY : application/http/CMakeFiles/testwebserver.dir/requires

application/http/CMakeFiles/testwebserver.dir/clean:
	cd /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/application/http && $(CMAKE_COMMAND) -P CMakeFiles/testwebserver.dir/cmake_clean.cmake
.PHONY : application/http/CMakeFiles/testwebserver.dir/clean

application/http/CMakeFiles/testwebserver.dir/depend:
	cd /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/application/http /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/application/http /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/application/http/CMakeFiles/testwebserver.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : application/http/CMakeFiles/testwebserver.dir/depend

