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
include application/modelchecker/CMakeFiles/modelchecker.dir/depend.make

# Include the progress variables for this target.
include application/modelchecker/CMakeFiles/modelchecker.dir/progress.make

# Include the compile flags for this target's objects.
include application/modelchecker/CMakeFiles/modelchecker.dir/flags.make

application/modelchecker/CMakeFiles/modelchecker.dir/modelchecker.o: application/modelchecker/CMakeFiles/modelchecker.dir/flags.make
application/modelchecker/CMakeFiles/modelchecker.dir/modelchecker.o: ../application/modelchecker/modelchecker.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object application/modelchecker/CMakeFiles/modelchecker.dir/modelchecker.o"
	cd /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/application/modelchecker && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/modelchecker.dir/modelchecker.o -c /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/application/modelchecker/modelchecker.cc

application/modelchecker/CMakeFiles/modelchecker.dir/modelchecker.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/modelchecker.dir/modelchecker.i"
	cd /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/application/modelchecker && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/application/modelchecker/modelchecker.cc > CMakeFiles/modelchecker.dir/modelchecker.i

application/modelchecker/CMakeFiles/modelchecker.dir/modelchecker.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/modelchecker.dir/modelchecker.s"
	cd /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/application/modelchecker && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/application/modelchecker/modelchecker.cc -o CMakeFiles/modelchecker.dir/modelchecker.s

application/modelchecker/CMakeFiles/modelchecker.dir/modelchecker.o.requires:
.PHONY : application/modelchecker/CMakeFiles/modelchecker.dir/modelchecker.o.requires

application/modelchecker/CMakeFiles/modelchecker.dir/modelchecker.o.provides: application/modelchecker/CMakeFiles/modelchecker.dir/modelchecker.o.requires
	$(MAKE) -f application/modelchecker/CMakeFiles/modelchecker.dir/build.make application/modelchecker/CMakeFiles/modelchecker.dir/modelchecker.o.provides.build
.PHONY : application/modelchecker/CMakeFiles/modelchecker.dir/modelchecker.o.provides

application/modelchecker/CMakeFiles/modelchecker.dir/modelchecker.o.provides.build: application/modelchecker/CMakeFiles/modelchecker.dir/modelchecker.o

application/modelchecker/CMakeFiles/modelchecker.dir/ServiceTests.o: application/modelchecker/CMakeFiles/modelchecker.dir/flags.make
application/modelchecker/CMakeFiles/modelchecker.dir/ServiceTests.o: ../application/modelchecker/ServiceTests.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object application/modelchecker/CMakeFiles/modelchecker.dir/ServiceTests.o"
	cd /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/application/modelchecker && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/modelchecker.dir/ServiceTests.o -c /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/application/modelchecker/ServiceTests.cc

application/modelchecker/CMakeFiles/modelchecker.dir/ServiceTests.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/modelchecker.dir/ServiceTests.i"
	cd /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/application/modelchecker && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/application/modelchecker/ServiceTests.cc > CMakeFiles/modelchecker.dir/ServiceTests.i

application/modelchecker/CMakeFiles/modelchecker.dir/ServiceTests.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/modelchecker.dir/ServiceTests.s"
	cd /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/application/modelchecker && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/application/modelchecker/ServiceTests.cc -o CMakeFiles/modelchecker.dir/ServiceTests.s

application/modelchecker/CMakeFiles/modelchecker.dir/ServiceTests.o.requires:
.PHONY : application/modelchecker/CMakeFiles/modelchecker.dir/ServiceTests.o.requires

application/modelchecker/CMakeFiles/modelchecker.dir/ServiceTests.o.provides: application/modelchecker/CMakeFiles/modelchecker.dir/ServiceTests.o.requires
	$(MAKE) -f application/modelchecker/CMakeFiles/modelchecker.dir/build.make application/modelchecker/CMakeFiles/modelchecker.dir/ServiceTests.o.provides.build
.PHONY : application/modelchecker/CMakeFiles/modelchecker.dir/ServiceTests.o.provides

application/modelchecker/CMakeFiles/modelchecker.dir/ServiceTests.o.provides.build: application/modelchecker/CMakeFiles/modelchecker.dir/ServiceTests.o

# Object files for target modelchecker
modelchecker_OBJECTS = \
"CMakeFiles/modelchecker.dir/modelchecker.o" \
"CMakeFiles/modelchecker.dir/ServiceTests.o"

# External object files for target modelchecker
modelchecker_EXTERNAL_OBJECTS =

application/modelchecker/modelchecker: application/modelchecker/CMakeFiles/modelchecker.dir/modelchecker.o
application/modelchecker/modelchecker: application/modelchecker/CMakeFiles/modelchecker.dir/ServiceTests.o
application/modelchecker/modelchecker: application/modelchecker/libMaceMC.a
application/modelchecker/modelchecker: services/Transport/libTransport.a
application/modelchecker/modelchecker: services/RequestTransport/libRequestTransport.a
application/modelchecker/modelchecker: services/File/libFile.a
application/modelchecker/modelchecker: services/RandTree/libRandTree.a
application/modelchecker/modelchecker: services/ReplayTree/libReplayTree.a
application/modelchecker/modelchecker: services/RanSub/libRanSub.a
application/modelchecker/modelchecker: services/Pastry/libPastry.a
application/modelchecker/modelchecker: services/Bamboo/libBamboo.a
application/modelchecker/modelchecker: services/Chord/libChord.a
application/modelchecker/modelchecker: services/GenericOverlayRoute/libGenericOverlayRoute.a
application/modelchecker/modelchecker: services/GenericTreeMulticast/libGenericTreeMulticast.a
application/modelchecker/modelchecker: services/ScribeMS/libScribeMS.a
application/modelchecker/modelchecker: services/SignedMulticast/libSignedMulticast.a
application/modelchecker/modelchecker: services/SimApplication/libSimApplication.a
application/modelchecker/modelchecker: services/SplitStreamMS/libSplitStreamMS.a
application/modelchecker/modelchecker: services/FileSync/libFileSync.a
application/modelchecker/modelchecker: services/DHT/libDHT.a
application/modelchecker/modelchecker: services/CondorHeartBeat/libCondorHeartBeat.a
application/modelchecker/modelchecker: services/LUFactorization/libLUFactorization.a
application/modelchecker/modelchecker: services/LUFAck/libLUFAck.a
application/modelchecker/modelchecker: services/ThroughputTest/libThroughputTest.a
application/modelchecker/modelchecker: services/GameOfLife/libGameOfLife.a
application/modelchecker/modelchecker: services/Simple/libSimple.a
application/modelchecker/modelchecker: application/simulator_common/libSimulatorCommonFiles.a
application/modelchecker/modelchecker: services/interfaces/libinterfaces.a
application/modelchecker/modelchecker: lib/libmace.a
application/modelchecker/modelchecker: services/GenericTreeMulticast/libGenericTreeMulticast.a
application/modelchecker/modelchecker: services/ScribeMS/libScribeMS.a
application/modelchecker/modelchecker: services/Transport/libTransport.a
application/modelchecker/modelchecker: services/interfaces/libinterfaces.a
application/modelchecker/modelchecker: lib/libmace.a
application/modelchecker/modelchecker: /usr/lib64/libpthread.so
application/modelchecker/modelchecker: /usr/lib64/libcrypto.so
application/modelchecker/modelchecker: /usr/lib64/libssl.so
application/modelchecker/modelchecker: /usr/lib64/libcrypto.so
application/modelchecker/modelchecker: /usr/lib64/libssl.so
application/modelchecker/modelchecker: /usr/lib64/libgsl.so
application/modelchecker/modelchecker: /usr/lib64/libgslcblas.so
application/modelchecker/modelchecker: /usr/lib64/libz.so
application/modelchecker/modelchecker: /usr/lib64/libdl.so
application/modelchecker/modelchecker: /usr/lib64/libgslcblas.so
application/modelchecker/modelchecker: /usr/lib64/libz.so
application/modelchecker/modelchecker: /usr/lib64/libdl.so
application/modelchecker/modelchecker: application/modelchecker/CMakeFiles/modelchecker.dir/build.make
application/modelchecker/modelchecker: application/modelchecker/CMakeFiles/modelchecker.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable modelchecker"
	cd /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/application/modelchecker && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/modelchecker.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
application/modelchecker/CMakeFiles/modelchecker.dir/build: application/modelchecker/modelchecker
.PHONY : application/modelchecker/CMakeFiles/modelchecker.dir/build

application/modelchecker/CMakeFiles/modelchecker.dir/requires: application/modelchecker/CMakeFiles/modelchecker.dir/modelchecker.o.requires
application/modelchecker/CMakeFiles/modelchecker.dir/requires: application/modelchecker/CMakeFiles/modelchecker.dir/ServiceTests.o.requires
.PHONY : application/modelchecker/CMakeFiles/modelchecker.dir/requires

application/modelchecker/CMakeFiles/modelchecker.dir/clean:
	cd /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/application/modelchecker && $(CMAKE_COMMAND) -P CMakeFiles/modelchecker.dir/cmake_clean.cmake
.PHONY : application/modelchecker/CMakeFiles/modelchecker.dir/clean

application/modelchecker/CMakeFiles/modelchecker.dir/depend:
	cd /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/application/modelchecker /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/application/modelchecker /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/application/modelchecker/CMakeFiles/modelchecker.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : application/modelchecker/CMakeFiles/modelchecker.dir/depend

