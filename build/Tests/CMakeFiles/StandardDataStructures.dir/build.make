# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/adam-torek/StandardDataStructures

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/adam-torek/StandardDataStructures/build

# Include any dependencies generated for this target.
include Tests/CMakeFiles/StandardDataStructures.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Tests/CMakeFiles/StandardDataStructures.dir/compiler_depend.make

# Include the progress variables for this target.
include Tests/CMakeFiles/StandardDataStructures.dir/progress.make

# Include the compile flags for this target's objects.
include Tests/CMakeFiles/StandardDataStructures.dir/flags.make

Tests/CMakeFiles/StandardDataStructures.dir/dummy.cpp.o: Tests/CMakeFiles/StandardDataStructures.dir/flags.make
Tests/CMakeFiles/StandardDataStructures.dir/dummy.cpp.o: ../DataStructures/dummy.cpp
Tests/CMakeFiles/StandardDataStructures.dir/dummy.cpp.o: Tests/CMakeFiles/StandardDataStructures.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adam-torek/StandardDataStructures/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Tests/CMakeFiles/StandardDataStructures.dir/dummy.cpp.o"
	cd /home/adam-torek/StandardDataStructures/build/Tests && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Tests/CMakeFiles/StandardDataStructures.dir/dummy.cpp.o -MF CMakeFiles/StandardDataStructures.dir/dummy.cpp.o.d -o CMakeFiles/StandardDataStructures.dir/dummy.cpp.o -c /home/adam-torek/StandardDataStructures/DataStructures/dummy.cpp

Tests/CMakeFiles/StandardDataStructures.dir/dummy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/StandardDataStructures.dir/dummy.cpp.i"
	cd /home/adam-torek/StandardDataStructures/build/Tests && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adam-torek/StandardDataStructures/DataStructures/dummy.cpp > CMakeFiles/StandardDataStructures.dir/dummy.cpp.i

Tests/CMakeFiles/StandardDataStructures.dir/dummy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/StandardDataStructures.dir/dummy.cpp.s"
	cd /home/adam-torek/StandardDataStructures/build/Tests && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adam-torek/StandardDataStructures/DataStructures/dummy.cpp -o CMakeFiles/StandardDataStructures.dir/dummy.cpp.s

# Object files for target StandardDataStructures
StandardDataStructures_OBJECTS = \
"CMakeFiles/StandardDataStructures.dir/dummy.cpp.o"

# External object files for target StandardDataStructures
StandardDataStructures_EXTERNAL_OBJECTS =

Tests/libStandardDataStructures.a: Tests/CMakeFiles/StandardDataStructures.dir/dummy.cpp.o
Tests/libStandardDataStructures.a: Tests/CMakeFiles/StandardDataStructures.dir/build.make
Tests/libStandardDataStructures.a: Tests/CMakeFiles/StandardDataStructures.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/adam-torek/StandardDataStructures/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libStandardDataStructures.a"
	cd /home/adam-torek/StandardDataStructures/build/Tests && $(CMAKE_COMMAND) -P CMakeFiles/StandardDataStructures.dir/cmake_clean_target.cmake
	cd /home/adam-torek/StandardDataStructures/build/Tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/StandardDataStructures.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Tests/CMakeFiles/StandardDataStructures.dir/build: Tests/libStandardDataStructures.a
.PHONY : Tests/CMakeFiles/StandardDataStructures.dir/build

Tests/CMakeFiles/StandardDataStructures.dir/clean:
	cd /home/adam-torek/StandardDataStructures/build/Tests && $(CMAKE_COMMAND) -P CMakeFiles/StandardDataStructures.dir/cmake_clean.cmake
.PHONY : Tests/CMakeFiles/StandardDataStructures.dir/clean

Tests/CMakeFiles/StandardDataStructures.dir/depend:
	cd /home/adam-torek/StandardDataStructures/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/adam-torek/StandardDataStructures /home/adam-torek/StandardDataStructures/DataStructures /home/adam-torek/StandardDataStructures/build /home/adam-torek/StandardDataStructures/build/Tests /home/adam-torek/StandardDataStructures/build/Tests/CMakeFiles/StandardDataStructures.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Tests/CMakeFiles/StandardDataStructures.dir/depend

