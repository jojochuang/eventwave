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
include services/File/CMakeFiles/File.dir/depend.make

# Include the progress variables for this target.
include services/File/CMakeFiles/File.dir/progress.make

# Include the compile flags for this target's objects.
include services/File/CMakeFiles/File.dir/flags.make

services/File/CMakeFiles/File.dir/Find.o: services/File/CMakeFiles/File.dir/flags.make
services/File/CMakeFiles/File.dir/Find.o: services/File/Find.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object services/File/CMakeFiles/File.dir/Find.o"
	cd /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/File && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/File.dir/Find.o -c /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/File/Find.cc

services/File/CMakeFiles/File.dir/Find.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/File.dir/Find.i"
	cd /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/File && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/File/Find.cc > CMakeFiles/File.dir/Find.i

services/File/CMakeFiles/File.dir/Find.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/File.dir/Find.s"
	cd /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/File && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/File/Find.cc -o CMakeFiles/File.dir/Find.s

services/File/CMakeFiles/File.dir/Find.o.requires:
.PHONY : services/File/CMakeFiles/File.dir/Find.o.requires

services/File/CMakeFiles/File.dir/Find.o.provides: services/File/CMakeFiles/File.dir/Find.o.requires
	$(MAKE) -f services/File/CMakeFiles/File.dir/build.make services/File/CMakeFiles/File.dir/Find.o.provides.build
.PHONY : services/File/CMakeFiles/File.dir/Find.o.provides

services/File/CMakeFiles/File.dir/Find.o.provides.build: services/File/CMakeFiles/File.dir/Find.o

services/File/CMakeFiles/File.dir/Find-init.o: services/File/CMakeFiles/File.dir/flags.make
services/File/CMakeFiles/File.dir/Find-init.o: services/File/Find-init.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object services/File/CMakeFiles/File.dir/Find-init.o"
	cd /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/File && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/File.dir/Find-init.o -c /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/File/Find-init.cc

services/File/CMakeFiles/File.dir/Find-init.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/File.dir/Find-init.i"
	cd /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/File && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/File/Find-init.cc > CMakeFiles/File.dir/Find-init.i

services/File/CMakeFiles/File.dir/Find-init.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/File.dir/Find-init.s"
	cd /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/File && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/File/Find-init.cc -o CMakeFiles/File.dir/Find-init.s

services/File/CMakeFiles/File.dir/Find-init.o.requires:
.PHONY : services/File/CMakeFiles/File.dir/Find-init.o.requires

services/File/CMakeFiles/File.dir/Find-init.o.provides: services/File/CMakeFiles/File.dir/Find-init.o.requires
	$(MAKE) -f services/File/CMakeFiles/File.dir/build.make services/File/CMakeFiles/File.dir/Find-init.o.provides.build
.PHONY : services/File/CMakeFiles/File.dir/Find-init.o.provides

services/File/CMakeFiles/File.dir/Find-init.o.provides.build: services/File/CMakeFiles/File.dir/Find-init.o

services/File/Find.cc: ../services/interfaces/ServiceClass.h
services/File/Find.cc: services/interfaces/FileFindServiceClass.h
services/File/Find.cc: ../services/interfaces/ServiceClass.h
services/File/Find.cc: services/interfaces/FileFindHandler.h
services/File/Find.cc: ../perl5/macec
services/File/Find.cc: ../perl5/Mace/Compiler/MaceCompiler.pm
services/File/Find.cc: ../perl5/Mace/Compiler/Context.pm
services/File/Find.cc: ../perl5/Mace/Compiler/Type.pm
services/File/Find.cc: ../perl5/Mace/Compiler/Timer.pm
services/File/Find.cc: ../perl5/Mace/Compiler/Type.pm
services/File/Find.cc: ../perl5/Mace/Compiler/Param.pm
services/File/Find.cc: ../perl5/Mace/Compiler/Type.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ContextParam.pm
services/File/Find.cc: ../perl5/Mace/Compiler/Type.pm
services/File/Find.cc: ../perl5/Mace/Compiler/TypeOption.pm
services/File/Find.cc: ../perl5/Mace/Compiler/Param.pm
services/File/Find.cc: ../perl5/Mace/Compiler/Type.pm
services/File/Find.cc: ../perl5/Mace/Compiler/Method.pm
services/File/Find.cc: ../perl5/Mace/Compiler/Param.pm
services/File/Find.cc: ../perl5/Mace/Compiler/Type.pm
services/File/Find.cc: ../perl5/Mace/Compiler/Type.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ServiceImpl.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ClassCache.pm
services/File/Find.cc: ../perl5/Mace/Compiler/Globals.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ClassParser.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ServiceClass.pm
services/File/Find.cc: ../perl5/Mace/Compiler/Method.pm
services/File/Find.cc: ../perl5/Mace/Compiler/Param.pm
services/File/Find.cc: ../perl5/Mace/Compiler/Type.pm
services/File/Find.cc: ../perl5/Mace/Compiler/Type.pm
services/File/Find.cc: ../perl5/Mace/Compiler/AutoType.pm
services/File/Find.cc: ../perl5/Mace/Compiler/SQLize.pm
services/File/Find.cc: ../perl5/Mace/Compiler/Method.pm
services/File/Find.cc: ../perl5/Mace/Compiler/Param.pm
services/File/Find.cc: ../perl5/Mace/Compiler/Type.pm
services/File/Find.cc: ../perl5/Mace/Compiler/Type.pm
services/File/Find.cc: ../perl5/Mace/Compiler/Param.pm
services/File/Find.cc: ../perl5/Mace/Compiler/Type.pm
services/File/Find.cc: ../perl5/Mace/Compiler/Grammar.pm
services/File/Find.cc: perl5/Mace/Compiler/ClassParserRecDescent.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/BraceBlock.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/Expression.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/MethodTerm.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedAbort.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedAssertMsg.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedBinaryAssignOp.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedCatches.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedDefaultCase.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedDoWhile.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedElseIf.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedElseIfs.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedExpectStatement.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedExpression.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedFCall.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedForLoop.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedForUpdate.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedForVar.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedIf.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedLogging.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedLValue.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedOutput.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedPlusPlus.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedCaseOrDefault.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedReturn.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedSwitchCase.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedSwitchCases.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedSwitchConstant.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedMacro.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedTryCatch.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedVar.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedWhile.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/StatementBlock.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/StatementOrBraceBlock.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/SemiStatement.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ScopedId.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ArrayIndex.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ArrayIndOrFunction.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ArrayIndOrFunctionParts.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/Expression1.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/Expression2.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ExpressionLValue.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ExpressionLValue1.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ExpressionLValue2.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ExpressionOrAssignLValue.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ExpressionOrAssignLValue1.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/StateExpression.pm
services/File/Find.cc: ../perl5/Mace/Compiler/SQLize.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ServiceVar.pm
services/File/Find.cc: ../perl5/Mace/Compiler/AutoType.pm
services/File/Find.cc: ../perl5/Mace/Compiler/SQLize.pm
services/File/Find.cc: ../perl5/Mace/Compiler/RoutineObject.pm
services/File/Find.cc: ../perl5/Mace/Compiler/Transition.pm
services/File/Find.cc: ../perl5/Mace/Compiler/TypeDef.pm
services/File/Find.cc: ../perl5/Mace/Compiler/GeneratedOn.pm
services/File/Find.cc: ../perl5/Mace/Compiler/Grammar.pm
services/File/Find.cc: perl5/Mace/Compiler/MaceRecDescent.pm
services/File/Find.cc: ../perl5/Mace/Compiler/Guard.pm
services/File/Find.cc: ../perl5/Mace/Compiler/Timer.pm
services/File/Find.cc: ../perl5/Mace/Compiler/Type.pm
services/File/Find.cc: ../perl5/Mace/Compiler/Detect.pm
services/File/Find.cc: ../perl5/Mace/Compiler/Method.pm
services/File/Find.cc: ../perl5/Mace/Compiler/Param.pm
services/File/Find.cc: ../perl5/Mace/Compiler/Type.pm
services/File/Find.cc: ../perl5/Mace/Compiler/Type.pm
services/File/Find.cc: ../perl5/Mace/Compiler/Param.pm
services/File/Find.cc: ../perl5/Mace/Compiler/Type.pm
services/File/Find.cc: ../perl5/Mace/Compiler/Type.pm
services/File/Find.cc: ../perl5/Mace/Compiler/Query.pm
services/File/Find.cc: ../perl5/Mace/Compiler/Properties/SetVariable.pm
services/File/Find.cc: ../perl5/Mace/Compiler/Properties/Quantification.pm
services/File/Find.cc: ../perl5/Mace/Compiler/Properties/SetSetExpression.pm
services/File/Find.cc: ../perl5/Mace/Compiler/Properties/ElementSetExpression.pm
services/File/Find.cc: ../perl5/Mace/Compiler/Properties/Equation.pm
services/File/Find.cc: ../perl5/Mace/Compiler/Properties/JoinExpression.pm
services/File/Find.cc: ../perl5/Mace/Compiler/Properties/Property.pm
services/File/Find.cc: ../perl5/Mace/Compiler/Properties/NonBExpression.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/BraceBlock.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/Expression.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/MethodTerm.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedAbort.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedAssertMsg.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedBinaryAssignOp.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedCatches.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedDefaultCase.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedDoWhile.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedElseIf.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedElseIfs.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedExpectStatement.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedExpression.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedFCall.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedForLoop.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedForUpdate.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedForVar.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedIf.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedLogging.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedLValue.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedOutput.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedPlusPlus.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedCaseOrDefault.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedReturn.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedSwitchCase.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedSwitchCases.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedSwitchConstant.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedMacro.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedTryCatch.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedVar.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedWhile.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/StatementBlock.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/StatementOrBraceBlock.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/SemiStatement.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ScopedId.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ArrayIndex.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ArrayIndOrFunction.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ArrayIndOrFunctionParts.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/Expression1.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/Expression2.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ExpressionLValue.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ExpressionLValue1.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ExpressionLValue2.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ExpressionOrAssignLValue.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ExpressionOrAssignLValue1.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/StateExpression.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ClassCache.pm
services/File/Find.cc: ../perl5/Mace/Compiler/Globals.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ClassParser.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ServiceClass.pm
services/File/Find.cc: ../perl5/Mace/Compiler/Method.pm
services/File/Find.cc: ../perl5/Mace/Compiler/Param.pm
services/File/Find.cc: ../perl5/Mace/Compiler/Type.pm
services/File/Find.cc: ../perl5/Mace/Compiler/Type.pm
services/File/Find.cc: ../perl5/Mace/Compiler/AutoType.pm
services/File/Find.cc: ../perl5/Mace/Compiler/SQLize.pm
services/File/Find.cc: ../perl5/Mace/Compiler/Method.pm
services/File/Find.cc: ../perl5/Mace/Compiler/Param.pm
services/File/Find.cc: ../perl5/Mace/Compiler/Type.pm
services/File/Find.cc: ../perl5/Mace/Compiler/Type.pm
services/File/Find.cc: ../perl5/Mace/Compiler/Param.pm
services/File/Find.cc: ../perl5/Mace/Compiler/Type.pm
services/File/Find.cc: ../perl5/Mace/Compiler/Grammar.pm
services/File/Find.cc: perl5/Mace/Compiler/ClassParserRecDescent.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/BraceBlock.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/Expression.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/MethodTerm.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedAbort.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedAssertMsg.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedBinaryAssignOp.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedCatches.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedDefaultCase.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedDoWhile.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedElseIf.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedElseIfs.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedExpectStatement.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedExpression.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedFCall.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedForLoop.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedForUpdate.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedForVar.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedIf.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedLogging.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedLValue.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedOutput.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedPlusPlus.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedCaseOrDefault.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedReturn.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedSwitchCase.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedSwitchCases.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedSwitchConstant.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedMacro.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedTryCatch.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedVar.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ParsedWhile.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/StatementBlock.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/StatementOrBraceBlock.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/SemiStatement.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ScopedId.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ArrayIndex.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ArrayIndOrFunction.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ArrayIndOrFunctionParts.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/Expression1.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/Expression2.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ExpressionLValue.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ExpressionLValue1.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ExpressionLValue2.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ExpressionOrAssignLValue.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/ExpressionOrAssignLValue1.pm
services/File/Find.cc: ../perl5/Mace/Compiler/ParseTreeObject/StateExpression.pm
services/File/Find.cc: ../perl5/Mace/Compiler/MInclude.pm
services/File/Find.cc: ../perl5/Mace/Compiler/Globals.pm
services/File/Find.cc: ../perl5/Mace/Compiler/Globals.pm
services/File/Find.cc: ../services/File/Find.mac
	$(CMAKE_COMMAND) -E cmake_progress_report /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating Find.cc, Find.h, Find-init.h, Find-init.cc, Find-constants.h, Find-macros.h"
	cd /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/File && /usr/bin/perl -I /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/perl5 /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/perl5/macec -I/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/File -I/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/File -I/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/File -I/usr/include/boost-1_42 -I/usr/include -I/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds -I/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/interfaces -I/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/interfaces -I/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Transport -I/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Transport -I/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/RequestTransport -I/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/RequestTransport -I/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/Http -I/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/Http -I/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/lib -I/homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext --USE_SNAPSHOT ON /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/services/File/Find.mac

services/File/Find.h: services/File/Find.cc

services/File/Find-init.h: services/File/Find.cc

services/File/Find-init.cc: services/File/Find.cc

services/File/Find-constants.h: services/File/Find.cc

services/File/Find-macros.h: services/File/Find.cc

# Object files for target File
File_OBJECTS = \
"CMakeFiles/File.dir/Find.o" \
"CMakeFiles/File.dir/Find-init.o"

# External object files for target File
File_EXTERNAL_OBJECTS =

services/File/libFile.a: services/File/CMakeFiles/File.dir/Find.o
services/File/libFile.a: services/File/CMakeFiles/File.dir/Find-init.o
services/File/libFile.a: services/File/CMakeFiles/File.dir/build.make
services/File/libFile.a: services/File/CMakeFiles/File.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libFile.a"
	cd /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/File && $(CMAKE_COMMAND) -P CMakeFiles/File.dir/cmake_clean_target.cmake
	cd /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/File && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/File.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
services/File/CMakeFiles/File.dir/build: services/File/libFile.a
.PHONY : services/File/CMakeFiles/File.dir/build

services/File/CMakeFiles/File.dir/requires: services/File/CMakeFiles/File.dir/Find.o.requires
services/File/CMakeFiles/File.dir/requires: services/File/CMakeFiles/File.dir/Find-init.o.requires
.PHONY : services/File/CMakeFiles/File.dir/requires

services/File/CMakeFiles/File.dir/clean:
	cd /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/File && $(CMAKE_COMMAND) -P CMakeFiles/File.dir/cmake_clean.cmake
.PHONY : services/File/CMakeFiles/File.dir/clean

services/File/CMakeFiles/File.dir/depend: services/File/Find.cc
services/File/CMakeFiles/File.dir/depend: services/File/Find.h
services/File/CMakeFiles/File.dir/depend: services/File/Find-init.h
services/File/CMakeFiles/File.dir/depend: services/File/Find-init.cc
services/File/CMakeFiles/File.dir/depend: services/File/Find-constants.h
services/File/CMakeFiles/File.dir/depend: services/File/Find-macros.h
	cd /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/File /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/File /homes/bsang/My_Disk/Research/Topic/Full-Context/Mace/mace-fullcontext/builds/services/File/CMakeFiles/File.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : services/File/CMakeFiles/File.dir/depend

