# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
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
CMAKE_COMMAND = /cygdrive/c/Users/s-sumi/.CLion2016.3/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/s-sumi/.CLion2016.3/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/s-sumi/ClionProjects/Atcoder-new

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/s-sumi/ClionProjects/Atcoder-new/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/A.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/A.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/A.dir/flags.make

CMakeFiles/A.dir/SolveA.cpp.o: CMakeFiles/A.dir/flags.make
CMakeFiles/A.dir/SolveA.cpp.o: ../SolveA.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/s-sumi/ClionProjects/Atcoder-new/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/A.dir/SolveA.cpp.o"
	/usr/bin/c++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/A.dir/SolveA.cpp.o -c /cygdrive/c/Users/s-sumi/ClionProjects/Atcoder-new/SolveA.cpp

CMakeFiles/A.dir/SolveA.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/A.dir/SolveA.cpp.i"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/s-sumi/ClionProjects/Atcoder-new/SolveA.cpp > CMakeFiles/A.dir/SolveA.cpp.i

CMakeFiles/A.dir/SolveA.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/A.dir/SolveA.cpp.s"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/s-sumi/ClionProjects/Atcoder-new/SolveA.cpp -o CMakeFiles/A.dir/SolveA.cpp.s

CMakeFiles/A.dir/SolveA.cpp.o.requires:

.PHONY : CMakeFiles/A.dir/SolveA.cpp.o.requires

CMakeFiles/A.dir/SolveA.cpp.o.provides: CMakeFiles/A.dir/SolveA.cpp.o.requires
	$(MAKE) -f CMakeFiles/A.dir/build.make CMakeFiles/A.dir/SolveA.cpp.o.provides.build
.PHONY : CMakeFiles/A.dir/SolveA.cpp.o.provides

CMakeFiles/A.dir/SolveA.cpp.o.provides.build: CMakeFiles/A.dir/SolveA.cpp.o


# Object files for target A
A_OBJECTS = \
"CMakeFiles/A.dir/SolveA.cpp.o"

# External object files for target A
A_EXTERNAL_OBJECTS =

A.exe: CMakeFiles/A.dir/SolveA.cpp.o
A.exe: CMakeFiles/A.dir/build.make
A.exe: CMakeFiles/A.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/s-sumi/ClionProjects/Atcoder-new/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable A.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/A.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/A.dir/build: A.exe

.PHONY : CMakeFiles/A.dir/build

CMakeFiles/A.dir/requires: CMakeFiles/A.dir/SolveA.cpp.o.requires

.PHONY : CMakeFiles/A.dir/requires

CMakeFiles/A.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/A.dir/cmake_clean.cmake
.PHONY : CMakeFiles/A.dir/clean

CMakeFiles/A.dir/depend:
	cd /cygdrive/c/Users/s-sumi/ClionProjects/Atcoder-new/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/s-sumi/ClionProjects/Atcoder-new /cygdrive/c/Users/s-sumi/ClionProjects/Atcoder-new /cygdrive/c/Users/s-sumi/ClionProjects/Atcoder-new/cmake-build-debug /cygdrive/c/Users/s-sumi/ClionProjects/Atcoder-new/cmake-build-debug /cygdrive/c/Users/s-sumi/ClionProjects/Atcoder-new/cmake-build-debug/CMakeFiles/A.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/A.dir/depend

