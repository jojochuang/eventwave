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
include services/FileSync/CMakeFiles/FileSync.dir/depend.make

# Include the progress variables for this target.
include services/FileSync/CMakeFiles/FileSync.dir/progress.make

# Include the compile flags for this target's objects.
include services/FileSync/CMakeFiles/FileSync.dir/flags.make

services/FileSync/CMakeFiles/FileSync.dir/FileSync.o: services/FileSync/CMakeFiles/FileSync.dir/flags.make
services/FileSync/CMakeFiles/FileSync.dir/FileSync.o: services/FileSync/FileSync.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object services/FileSync/CMakeFiles/FileSync.dir/FileSync.o"
	cd /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/FileSync && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/FileSync.dir/FileSync.o -c /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/FileSync/FileSync.cc

services/FileSync/CMakeFiles/FileSync.dir/FileSync.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FileSync.dir/FileSync.i"
	cd /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/FileSync && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/FileSync/FileSync.cc > CMakeFiles/FileSync.dir/FileSync.i

services/FileSync/CMakeFiles/FileSync.dir/FileSync.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FileSync.dir/FileSync.s"
	cd /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/FileSync && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/FileSync/FileSync.cc -o CMakeFiles/FileSync.dir/FileSync.s

services/FileSync/CMakeFiles/FileSync.dir/FileSync.o.requires:
.PHONY : services/FileSync/CMakeFiles/FileSync.dir/FileSync.o.requires

services/FileSync/CMakeFiles/FileSync.dir/FileSync.o.provides: services/FileSync/CMakeFiles/FileSync.dir/FileSync.o.requires
	$(MAKE) -f services/FileSync/CMakeFiles/FileSync.dir/build.make services/FileSync/CMakeFiles/FileSync.dir/FileSync.o.provides.build
.PHONY : services/FileSync/CMakeFiles/FileSync.dir/FileSync.o.provides

services/FileSync/CMakeFiles/FileSync.dir/FileSync.o.provides.build: services/FileSync/CMakeFiles/FileSync.dir/FileSync.o

services/FileSync/CMakeFiles/FileSync.dir/FileSync-init.o: services/FileSync/CMakeFiles/FileSync.dir/flags.make
services/FileSync/CMakeFiles/FileSync.dir/FileSync-init.o: services/FileSync/FileSync-init.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object services/FileSync/CMakeFiles/FileSync.dir/FileSync-init.o"
	cd /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/FileSync && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/FileSync.dir/FileSync-init.o -c /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/FileSync/FileSync-init.cc

services/FileSync/CMakeFiles/FileSync.dir/FileSync-init.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FileSync.dir/FileSync-init.i"
	cd /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/FileSync && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/FileSync/FileSync-init.cc > CMakeFiles/FileSync.dir/FileSync-init.i

services/FileSync/CMakeFiles/FileSync.dir/FileSync-init.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FileSync.dir/FileSync-init.s"
	cd /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/FileSync && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/FileSync/FileSync-init.cc -o CMakeFiles/FileSync.dir/FileSync-init.s

services/FileSync/CMakeFiles/FileSync.dir/FileSync-init.o.requires:
.PHONY : services/FileSync/CMakeFiles/FileSync.dir/FileSync-init.o.requires

services/FileSync/CMakeFiles/FileSync.dir/FileSync-init.o.provides: services/FileSync/CMakeFiles/FileSync.dir/FileSync-init.o.requires
	$(MAKE) -f services/FileSync/CMakeFiles/FileSync.dir/build.make services/FileSync/CMakeFiles/FileSync.dir/FileSync-init.o.provides.build
.PHONY : services/FileSync/CMakeFiles/FileSync.dir/FileSync-init.o.provides

services/FileSync/CMakeFiles/FileSync.dir/FileSync-init.o.provides.build: services/FileSync/CMakeFiles/FileSync.dir/FileSync-init.o

services/FileSync/FileSync.cc: ../services/interfaces/ServiceClass.h
services/FileSync/FileSync.cc: services/interfaces/TransportServiceClass.h
services/FileSync/FileSync.cc: ../services/interfaces/ServiceClass.h
services/FileSync/FileSync.cc: services/interfaces/ReceiveDataHandler.h
services/FileSync/FileSync.cc: services/interfaces/NetworkErrorHandler.h
services/FileSync/FileSync.cc: ../perl5/macec
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/MaceCompiler.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/Context.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/Type.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/Timer.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/Type.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/Param.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/Type.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ContextParam.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/Type.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/TypeOption.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/Param.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/Type.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/Method.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/Param.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/Type.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/Type.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ServiceImpl.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ClassCache.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/Globals.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ClassParser.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ServiceClass.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/Method.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/Param.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/Type.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/Type.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/AutoType.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/SQLize.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/Method.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/Param.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/Type.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/Type.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/Param.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/Type.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/Grammar.pm
services/FileSync/FileSync.cc: perl5/Mace/Compiler/ClassParserRecDescent.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/BraceBlock.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/Expression.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/MethodTerm.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedAbort.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedAssertMsg.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedBinaryAssignOp.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedCatches.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedDefaultCase.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedDoWhile.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedElseIf.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedElseIfs.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedExpectStatement.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedExpression.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedFCall.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedForLoop.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedForUpdate.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedForVar.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedIf.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedLogging.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedLValue.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedOutput.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedPlusPlus.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedCaseOrDefault.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedReturn.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedSwitchCase.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedSwitchCases.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedSwitchConstant.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedMacro.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedTryCatch.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedVar.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedWhile.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/StatementBlock.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/StatementOrBraceBlock.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/SemiStatement.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ScopedId.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ArrayIndex.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ArrayIndOrFunction.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ArrayIndOrFunctionParts.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/Expression1.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/Expression2.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ExpressionLValue.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ExpressionLValue1.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ExpressionLValue2.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ExpressionOrAssignLValue.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ExpressionOrAssignLValue1.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/StateExpression.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/SQLize.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ServiceVar.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/AutoType.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/SQLize.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/RoutineObject.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/Transition.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/TypeDef.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/GeneratedOn.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/Grammar.pm
services/FileSync/FileSync.cc: perl5/Mace/Compiler/MaceRecDescent.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/Guard.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/Timer.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/Type.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/Detect.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/Method.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/Param.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/Type.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/Type.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/Param.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/Type.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/Type.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/Query.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/Properties/SetVariable.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/Properties/Quantification.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/Properties/SetSetExpression.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/Properties/ElementSetExpression.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/Properties/Equation.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/Properties/JoinExpression.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/Properties/Property.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/Properties/NonBExpression.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/BraceBlock.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/Expression.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/MethodTerm.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedAbort.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedAssertMsg.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedBinaryAssignOp.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedCatches.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedDefaultCase.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedDoWhile.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedElseIf.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedElseIfs.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedExpectStatement.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedExpression.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedFCall.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedForLoop.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedForUpdate.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedForVar.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedIf.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedLogging.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedLValue.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedOutput.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedPlusPlus.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedCaseOrDefault.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedReturn.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedSwitchCase.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedSwitchCases.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedSwitchConstant.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedMacro.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedTryCatch.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedVar.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedWhile.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/StatementBlock.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/StatementOrBraceBlock.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/SemiStatement.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ScopedId.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ArrayIndex.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ArrayIndOrFunction.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ArrayIndOrFunctionParts.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/Expression1.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/Expression2.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ExpressionLValue.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ExpressionLValue1.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ExpressionLValue2.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ExpressionOrAssignLValue.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ExpressionOrAssignLValue1.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/StateExpression.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ClassCache.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/Globals.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ClassParser.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ServiceClass.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/Method.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/Param.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/Type.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/Type.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/AutoType.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/SQLize.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/Method.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/Param.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/Type.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/Type.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/Param.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/Type.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/Grammar.pm
services/FileSync/FileSync.cc: perl5/Mace/Compiler/ClassParserRecDescent.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/BraceBlock.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/Expression.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/MethodTerm.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedAbort.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedAssertMsg.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedBinaryAssignOp.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedCatches.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedDefaultCase.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedDoWhile.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedElseIf.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedElseIfs.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedExpectStatement.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedExpression.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedFCall.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedForLoop.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedForUpdate.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedForVar.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedIf.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedLogging.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedLValue.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedOutput.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedPlusPlus.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedCaseOrDefault.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedReturn.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedSwitchCase.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedSwitchCases.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedSwitchConstant.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedMacro.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedTryCatch.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedVar.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedWhile.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/StatementBlock.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/StatementOrBraceBlock.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/SemiStatement.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ScopedId.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ArrayIndex.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ArrayIndOrFunction.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ArrayIndOrFunctionParts.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/Expression1.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/Expression2.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ExpressionLValue.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ExpressionLValue1.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ExpressionLValue2.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ExpressionOrAssignLValue.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/ExpressionOrAssignLValue1.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/ParseTreeObject/StateExpression.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/MInclude.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/Globals.pm
services/FileSync/FileSync.cc: ../perl5/Mace/Compiler/Globals.pm
services/FileSync/FileSync.cc: ../services/FileSync/FileSync.mac
	$(CMAKE_COMMAND) -E cmake_progress_report /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating FileSync.cc, FileSync.h, FileSync-init.h, FileSync-init.cc, FileSync-constants.h, FileSync-macros.h"
	cd /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/FileSync && /usr/bin/perl -I /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/perl5 /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/macec -I/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/FileSync -I/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/FileSync -I/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/FileSync -I/usr/include/boost-1_42 -I/usr/include -I/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds -I/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces -I/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces -I/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport -I/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport -I/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/RequestTransport -I/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/RequestTransport -I/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Http -I/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Http -I/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/File -I/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/File -I/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/RandTree -I/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/RandTree -I/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/ReplayTree -I/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/ReplayTree -I/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/RanSub -I/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/RanSub -I/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Pastry -I/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Pastry -I/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Bamboo -I/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Bamboo -I/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Chord -I/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Chord -I/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/GenericOverlayRoute -I/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/GenericOverlayRoute -I/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/GenericTreeMulticast -I/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/GenericTreeMulticast -I/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/ScribeMS -I/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/ScribeMS -I/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/SignedMulticast -I/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/SignedMulticast -I/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/SimApplication -I/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/SimApplication -I/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/SplitStreamMS -I/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/SplitStreamMS -I/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/lib -I/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext --USE_SNAPSHOT ON /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/FileSync/FileSync.mac

services/FileSync/FileSync.h: services/FileSync/FileSync.cc

services/FileSync/FileSync-init.h: services/FileSync/FileSync.cc

services/FileSync/FileSync-init.cc: services/FileSync/FileSync.cc

services/FileSync/FileSync-constants.h: services/FileSync/FileSync.cc

services/FileSync/FileSync-macros.h: services/FileSync/FileSync.cc

# Object files for target FileSync
FileSync_OBJECTS = \
"CMakeFiles/FileSync.dir/FileSync.o" \
"CMakeFiles/FileSync.dir/FileSync-init.o"

# External object files for target FileSync
FileSync_EXTERNAL_OBJECTS =

services/FileSync/libFileSync.a: services/FileSync/CMakeFiles/FileSync.dir/FileSync.o
services/FileSync/libFileSync.a: services/FileSync/CMakeFiles/FileSync.dir/FileSync-init.o
services/FileSync/libFileSync.a: services/FileSync/CMakeFiles/FileSync.dir/build.make
services/FileSync/libFileSync.a: services/FileSync/CMakeFiles/FileSync.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libFileSync.a"
	cd /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/FileSync && $(CMAKE_COMMAND) -P CMakeFiles/FileSync.dir/cmake_clean_target.cmake
	cd /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/FileSync && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FileSync.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
services/FileSync/CMakeFiles/FileSync.dir/build: services/FileSync/libFileSync.a
.PHONY : services/FileSync/CMakeFiles/FileSync.dir/build

services/FileSync/CMakeFiles/FileSync.dir/requires: services/FileSync/CMakeFiles/FileSync.dir/FileSync.o.requires
services/FileSync/CMakeFiles/FileSync.dir/requires: services/FileSync/CMakeFiles/FileSync.dir/FileSync-init.o.requires
.PHONY : services/FileSync/CMakeFiles/FileSync.dir/requires

services/FileSync/CMakeFiles/FileSync.dir/clean:
	cd /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/FileSync && $(CMAKE_COMMAND) -P CMakeFiles/FileSync.dir/cmake_clean.cmake
.PHONY : services/FileSync/CMakeFiles/FileSync.dir/clean

services/FileSync/CMakeFiles/FileSync.dir/depend: services/FileSync/FileSync.cc
services/FileSync/CMakeFiles/FileSync.dir/depend: services/FileSync/FileSync.h
services/FileSync/CMakeFiles/FileSync.dir/depend: services/FileSync/FileSync-init.h
services/FileSync/CMakeFiles/FileSync.dir/depend: services/FileSync/FileSync-init.cc
services/FileSync/CMakeFiles/FileSync.dir/depend: services/FileSync/FileSync-constants.h
services/FileSync/CMakeFiles/FileSync.dir/depend: services/FileSync/FileSync-macros.h
	cd /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/FileSync /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/FileSync /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/FileSync/CMakeFiles/FileSync.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : services/FileSync/CMakeFiles/FileSync.dir/depend

