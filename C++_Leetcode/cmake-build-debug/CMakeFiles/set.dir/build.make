# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = "F:\Clion\CLion 2022.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "F:\Clion\CLion 2022.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = G:\Deeping_Learing\Leetcode-master\C++_Leetcode

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = G:\Deeping_Learing\Leetcode-master\C++_Leetcode\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/set.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/set.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/set.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/set.dir/flags.make

CMakeFiles/set.dir/NiuKe/set.cpp.obj: CMakeFiles/set.dir/flags.make
CMakeFiles/set.dir/NiuKe/set.cpp.obj: ../NiuKe/set.cpp
CMakeFiles/set.dir/NiuKe/set.cpp.obj: CMakeFiles/set.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\Deeping_Learing\Leetcode-master\C++_Leetcode\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/set.dir/NiuKe/set.cpp.obj"
	F:\MinGW\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/set.dir/NiuKe/set.cpp.obj -MF CMakeFiles\set.dir\NiuKe\set.cpp.obj.d -o CMakeFiles\set.dir\NiuKe\set.cpp.obj -c G:\Deeping_Learing\Leetcode-master\C++_Leetcode\NiuKe\set.cpp

CMakeFiles/set.dir/NiuKe/set.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/set.dir/NiuKe/set.cpp.i"
	F:\MinGW\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E G:\Deeping_Learing\Leetcode-master\C++_Leetcode\NiuKe\set.cpp > CMakeFiles\set.dir\NiuKe\set.cpp.i

CMakeFiles/set.dir/NiuKe/set.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/set.dir/NiuKe/set.cpp.s"
	F:\MinGW\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S G:\Deeping_Learing\Leetcode-master\C++_Leetcode\NiuKe\set.cpp -o CMakeFiles\set.dir\NiuKe\set.cpp.s

# Object files for target set
set_OBJECTS = \
"CMakeFiles/set.dir/NiuKe/set.cpp.obj"

# External object files for target set
set_EXTERNAL_OBJECTS =

set.exe: CMakeFiles/set.dir/NiuKe/set.cpp.obj
set.exe: CMakeFiles/set.dir/build.make
set.exe: CMakeFiles/set.dir/linklibs.rsp
set.exe: CMakeFiles/set.dir/objects1.rsp
set.exe: CMakeFiles/set.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=G:\Deeping_Learing\Leetcode-master\C++_Leetcode\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable set.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\set.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/set.dir/build: set.exe
.PHONY : CMakeFiles/set.dir/build

CMakeFiles/set.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\set.dir\cmake_clean.cmake
.PHONY : CMakeFiles/set.dir/clean

CMakeFiles/set.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" G:\Deeping_Learing\Leetcode-master\C++_Leetcode G:\Deeping_Learing\Leetcode-master\C++_Leetcode G:\Deeping_Learing\Leetcode-master\C++_Leetcode\cmake-build-debug G:\Deeping_Learing\Leetcode-master\C++_Leetcode\cmake-build-debug G:\Deeping_Learing\Leetcode-master\C++_Leetcode\cmake-build-debug\CMakeFiles\set.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/set.dir/depend
