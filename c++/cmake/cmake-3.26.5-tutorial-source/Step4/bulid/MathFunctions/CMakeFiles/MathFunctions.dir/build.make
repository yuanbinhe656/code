# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.27

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\soft\cmake\bin\cmake.exe

# The command to remove a file.
RM = D:\soft\cmake\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\BaiduSyncdisk\code\c++\cmake\cmake-3.26.5-tutorial-source\Step4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\BaiduSyncdisk\code\c++\cmake\cmake-3.26.5-tutorial-source\Step4\bulid

# Include any dependencies generated for this target.
include MathFunctions/CMakeFiles/MathFunctions.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include MathFunctions/CMakeFiles/MathFunctions.dir/compiler_depend.make

# Include the progress variables for this target.
include MathFunctions/CMakeFiles/MathFunctions.dir/progress.make

# Include the compile flags for this target's objects.
include MathFunctions/CMakeFiles/MathFunctions.dir/flags.make

MathFunctions/CMakeFiles/MathFunctions.dir/mysqrt.cxx.obj: MathFunctions/CMakeFiles/MathFunctions.dir/flags.make
MathFunctions/CMakeFiles/MathFunctions.dir/mysqrt.cxx.obj: E:/BaiduSyncdisk/code/c++/cmake/cmake-3.26.5-tutorial-source/Step4/MathFunctions/mysqrt.cxx
MathFunctions/CMakeFiles/MathFunctions.dir/mysqrt.cxx.obj: MathFunctions/CMakeFiles/MathFunctions.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\BaiduSyncdisk\code\c++\cmake\cmake-3.26.5-tutorial-source\Step4\bulid\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object MathFunctions/CMakeFiles/MathFunctions.dir/mysqrt.cxx.obj"
	cd /d E:\BaiduSyncdisk\code\c++\cmake\cmake-3.26.5-tutorial-source\Step4\bulid\MathFunctions && D:\soft\w64devkit\w64devkit\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT MathFunctions/CMakeFiles/MathFunctions.dir/mysqrt.cxx.obj -MF CMakeFiles\MathFunctions.dir\mysqrt.cxx.obj.d -o CMakeFiles\MathFunctions.dir\mysqrt.cxx.obj -c E:\BaiduSyncdisk\code\c++\cmake\cmake-3.26.5-tutorial-source\Step4\MathFunctions\mysqrt.cxx

MathFunctions/CMakeFiles/MathFunctions.dir/mysqrt.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MathFunctions.dir/mysqrt.cxx.i"
	cd /d E:\BaiduSyncdisk\code\c++\cmake\cmake-3.26.5-tutorial-source\Step4\bulid\MathFunctions && D:\soft\w64devkit\w64devkit\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\BaiduSyncdisk\code\c++\cmake\cmake-3.26.5-tutorial-source\Step4\MathFunctions\mysqrt.cxx > CMakeFiles\MathFunctions.dir\mysqrt.cxx.i

MathFunctions/CMakeFiles/MathFunctions.dir/mysqrt.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MathFunctions.dir/mysqrt.cxx.s"
	cd /d E:\BaiduSyncdisk\code\c++\cmake\cmake-3.26.5-tutorial-source\Step4\bulid\MathFunctions && D:\soft\w64devkit\w64devkit\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\BaiduSyncdisk\code\c++\cmake\cmake-3.26.5-tutorial-source\Step4\MathFunctions\mysqrt.cxx -o CMakeFiles\MathFunctions.dir\mysqrt.cxx.s

# Object files for target MathFunctions
MathFunctions_OBJECTS = \
"CMakeFiles/MathFunctions.dir/mysqrt.cxx.obj"

# External object files for target MathFunctions
MathFunctions_EXTERNAL_OBJECTS =

MathFunctions/libMathFunctions.a: MathFunctions/CMakeFiles/MathFunctions.dir/mysqrt.cxx.obj
MathFunctions/libMathFunctions.a: MathFunctions/CMakeFiles/MathFunctions.dir/build.make
MathFunctions/libMathFunctions.a: MathFunctions/CMakeFiles/MathFunctions.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=E:\BaiduSyncdisk\code\c++\cmake\cmake-3.26.5-tutorial-source\Step4\bulid\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libMathFunctions.a"
	cd /d E:\BaiduSyncdisk\code\c++\cmake\cmake-3.26.5-tutorial-source\Step4\bulid\MathFunctions && $(CMAKE_COMMAND) -P CMakeFiles\MathFunctions.dir\cmake_clean_target.cmake
	cd /d E:\BaiduSyncdisk\code\c++\cmake\cmake-3.26.5-tutorial-source\Step4\bulid\MathFunctions && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\MathFunctions.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
MathFunctions/CMakeFiles/MathFunctions.dir/build: MathFunctions/libMathFunctions.a
.PHONY : MathFunctions/CMakeFiles/MathFunctions.dir/build

MathFunctions/CMakeFiles/MathFunctions.dir/clean:
	cd /d E:\BaiduSyncdisk\code\c++\cmake\cmake-3.26.5-tutorial-source\Step4\bulid\MathFunctions && $(CMAKE_COMMAND) -P CMakeFiles\MathFunctions.dir\cmake_clean.cmake
.PHONY : MathFunctions/CMakeFiles/MathFunctions.dir/clean

MathFunctions/CMakeFiles/MathFunctions.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\BaiduSyncdisk\code\c++\cmake\cmake-3.26.5-tutorial-source\Step4 E:\BaiduSyncdisk\code\c++\cmake\cmake-3.26.5-tutorial-source\Step4\MathFunctions E:\BaiduSyncdisk\code\c++\cmake\cmake-3.26.5-tutorial-source\Step4\bulid E:\BaiduSyncdisk\code\c++\cmake\cmake-3.26.5-tutorial-source\Step4\bulid\MathFunctions E:\BaiduSyncdisk\code\c++\cmake\cmake-3.26.5-tutorial-source\Step4\bulid\MathFunctions\CMakeFiles\MathFunctions.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : MathFunctions/CMakeFiles/MathFunctions.dir/depend

