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

# Utility rule file for parsers.

perl5/Mace/Compiler/CMakeFiles/parsers: perl5/Mace/Compiler/MaceHeaderRecDescent.pm
perl5/Mace/Compiler/CMakeFiles/parsers: perl5/Mace/Compiler/MaceRecDescent.pm
perl5/Mace/Compiler/CMakeFiles/parsers: perl5/Mace/Compiler/ClassParserRecDescent.pm
perl5/Mace/Compiler/CMakeFiles/parsers: perl5/Mace/Compiler/VariantRecDescent.pm

perl5/Mace/Compiler/MaceHeaderRecDescent.pm: ../perl5/Mace/Compiler/MHGrammar.pm
perl5/Mace/Compiler/MaceHeaderRecDescent.pm: ../perl5/Mace/Compiler/Grammar.pm
perl5/Mace/Compiler/MaceHeaderRecDescent.pm: ../perl5/Mace/Compiler/ServiceClassCommonGrammar.pm
perl5/Mace/Compiler/MaceHeaderRecDescent.pm: ../perl5/Mace/Compiler/Grammar.pm
perl5/Mace/Compiler/MaceHeaderRecDescent.pm: ../perl5/Mace/Compiler/CommonGrammar.pm
perl5/Mace/Compiler/MaceHeaderRecDescent.pm: ../perl5/Mace/Compiler/Grammar.pm
perl5/Mace/Compiler/MaceHeaderRecDescent.pm: ../perl5/compilergen
	$(CMAKE_COMMAND) -E cmake_progress_report /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating MaceHeaderRecDescent.pm"
	cd /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/perl5/Mace/Compiler && /usr/bin/perl /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/compilergen MaceHeaderRecDescent.pm

perl5/Mace/Compiler/MaceRecDescent.pm: ../perl5/Mace/Compiler/MaceGrammar.pm
perl5/Mace/Compiler/MaceRecDescent.pm: ../perl5/Mace/Compiler/Grammar.pm
perl5/Mace/Compiler/MaceRecDescent.pm: ../perl5/Mace/Compiler/CommonGrammar.pm
perl5/Mace/Compiler/MaceRecDescent.pm: ../perl5/Mace/Compiler/Grammar.pm
perl5/Mace/Compiler/MaceRecDescent.pm: ../perl5/compilergen
	$(CMAKE_COMMAND) -E cmake_progress_report /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating MaceRecDescent.pm"
	cd /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/perl5/Mace/Compiler && /usr/bin/perl /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/compilergen MaceRecDescent.pm

perl5/Mace/Compiler/ClassParserRecDescent.pm: ../perl5/Mace/Compiler/ClassGrammar.pm
perl5/Mace/Compiler/ClassParserRecDescent.pm: ../perl5/Mace/Compiler/Grammar.pm
perl5/Mace/Compiler/ClassParserRecDescent.pm: ../perl5/Mace/Compiler/ServiceClassCommonGrammar.pm
perl5/Mace/Compiler/ClassParserRecDescent.pm: ../perl5/Mace/Compiler/Grammar.pm
perl5/Mace/Compiler/ClassParserRecDescent.pm: ../perl5/Mace/Compiler/CommonGrammar.pm
perl5/Mace/Compiler/ClassParserRecDescent.pm: ../perl5/Mace/Compiler/Grammar.pm
perl5/Mace/Compiler/ClassParserRecDescent.pm: ../perl5/compilergen
	$(CMAKE_COMMAND) -E cmake_progress_report /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating ClassParserRecDescent.pm"
	cd /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/perl5/Mace/Compiler && /usr/bin/perl /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/compilergen ClassParserRecDescent.pm

perl5/Mace/Compiler/VariantRecDescent.pm: ../perl5/Mace/Compiler/VariantGrammar.pm
perl5/Mace/Compiler/VariantRecDescent.pm: ../perl5/Mace/Compiler/Grammar.pm
perl5/Mace/Compiler/VariantRecDescent.pm: ../perl5/Mace/Compiler/CommonGrammar.pm
perl5/Mace/Compiler/VariantRecDescent.pm: ../perl5/Mace/Compiler/Grammar.pm
perl5/Mace/Compiler/VariantRecDescent.pm: ../perl5/compilergen
	$(CMAKE_COMMAND) -E cmake_progress_report /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating VariantRecDescent.pm"
	cd /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/perl5/Mace/Compiler && /usr/bin/perl /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/compilergen VariantRecDescent.pm

parsers: perl5/Mace/Compiler/CMakeFiles/parsers
parsers: perl5/Mace/Compiler/MaceHeaderRecDescent.pm
parsers: perl5/Mace/Compiler/MaceRecDescent.pm
parsers: perl5/Mace/Compiler/ClassParserRecDescent.pm
parsers: perl5/Mace/Compiler/VariantRecDescent.pm
parsers: perl5/Mace/Compiler/CMakeFiles/parsers.dir/build.make
.PHONY : parsers

# Rule to build all files generated by this target.
perl5/Mace/Compiler/CMakeFiles/parsers.dir/build: parsers
.PHONY : perl5/Mace/Compiler/CMakeFiles/parsers.dir/build

perl5/Mace/Compiler/CMakeFiles/parsers.dir/clean:
	cd /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/perl5/Mace/Compiler && $(CMAKE_COMMAND) -P CMakeFiles/parsers.dir/cmake_clean.cmake
.PHONY : perl5/Mace/Compiler/CMakeFiles/parsers.dir/clean

perl5/Mace/Compiler/CMakeFiles/parsers.dir/depend:
	cd /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/Mace/Compiler /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/perl5/Mace/Compiler /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/perl5/Mace/Compiler/CMakeFiles/parsers.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : perl5/Mace/Compiler/CMakeFiles/parsers.dir/depend

