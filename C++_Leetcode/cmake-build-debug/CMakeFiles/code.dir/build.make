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
include CMakeFiles/code.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/code.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/code.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/code.dir/flags.make

CMakeFiles/code.dir/Review_code/code.cpp.obj: CMakeFiles/code.dir/flags.make
CMakeFiles/code.dir/Review_code/code.cpp.obj: ../Review_code/code.cpp
CMakeFiles/code.dir/Review_code/code.cpp.obj: CMakeFiles/code.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\Deeping_Learing\Leetcode-master\C++_Leetcode\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/code.dir/Review_code/code.cpp.obj"
	F:\MinGW\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/code.dir/Review_code/code.cpp.obj -MF CMakeFiles\code.dir\Review_code\code.cpp.obj.d -o CMakeFiles\code.dir\Review_code\code.cpp.obj -c G:\Deeping_Learing\Leetcode-master\C++_Leetcode\Review_code\code.cpp

CMakeFiles/code.dir/Review_code/code.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/code.dir/Review_code/code.cpp.i"
	F:\MinGW\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E G:\Deeping_Learing\Leetcode-master\C++_Leetcode\Review_code\code.cpp > CMakeFiles\code.dir\Review_code\code.cpp.i

CMakeFiles/code.dir/Review_code/code.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/code.dir/Review_code/code.cpp.s"
	F:\MinGW\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S G:\Deeping_Learing\Leetcode-master\C++_Leetcode\Review_code\code.cpp -o CMakeFiles\code.dir\Review_code\code.cpp.s

# Object files for target code
code_OBJECTS = \
"CMakeFiles/code.dir/Review_code/code.cpp.obj"

# External object files for target code
code_EXTERNAL_OBJECTS =

code.exe: CMakeFiles/code.dir/Review_code/code.cpp.obj
code.exe: CMakeFiles/code.dir/build.make
code.exe: CMakeFiles/code.dir/linklibs.rsp
code.exe: CMakeFiles/code.dir/objects1.rsp
code.exe: CMakeFiles/code.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=G:\Deeping_Learing\Leetcode-master\C++_Leetcode\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable code.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\code.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/code.dir/build: code.exe
.PHONY : CMakeFiles/code.dir/build

CMakeFiles/code.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\code.dir\cmake_clean.cmake
.PHONY : CMakeFiles/code.dir/clean

CMakeFiles/code.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" G:\Deeping_Learing\Leetcode-master\C++_Leetcode G:\Deeping_Learing\Leetcode-master\C++_Leetcode G:\Deeping_Learing\Leetcode-master\C++_Leetcode\cmake-build-debug G:\Deeping_Learing\Leetcode-master\C++_Leetcode\cmake-build-debug G:\Deeping_Learing\Leetcode-master\C++_Leetcode\cmake-build-debug\CMakeFiles\code.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/code.dir/depend

