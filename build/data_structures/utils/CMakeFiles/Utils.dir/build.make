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
include data_structures/utils/CMakeFiles/Utils.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include data_structures/utils/CMakeFiles/Utils.dir/compiler_depend.make

# Include the progress variables for this target.
include data_structures/utils/CMakeFiles/Utils.dir/progress.make

# Include the compile flags for this target's objects.
include data_structures/utils/CMakeFiles/Utils.dir/flags.make

data_structures/utils/CMakeFiles/Utils.dir/dummy.cpp.o: data_structures/utils/CMakeFiles/Utils.dir/flags.make
data_structures/utils/CMakeFiles/Utils.dir/dummy.cpp.o: ../data_structures/utils/dummy.cpp
data_structures/utils/CMakeFiles/Utils.dir/dummy.cpp.o: data_structures/utils/CMakeFiles/Utils.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adam-torek/StandardDataStructures/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object data_structures/utils/CMakeFiles/Utils.dir/dummy.cpp.o"
	cd /home/adam-torek/StandardDataStructures/build/data_structures/utils && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT data_structures/utils/CMakeFiles/Utils.dir/dummy.cpp.o -MF CMakeFiles/Utils.dir/dummy.cpp.o.d -o CMakeFiles/Utils.dir/dummy.cpp.o -c /home/adam-torek/StandardDataStructures/data_structures/utils/dummy.cpp

data_structures/utils/CMakeFiles/Utils.dir/dummy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Utils.dir/dummy.cpp.i"
	cd /home/adam-torek/StandardDataStructures/build/data_structures/utils && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adam-torek/StandardDataStructures/data_structures/utils/dummy.cpp > CMakeFiles/Utils.dir/dummy.cpp.i

data_structures/utils/CMakeFiles/Utils.dir/dummy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Utils.dir/dummy.cpp.s"
	cd /home/adam-torek/StandardDataStructures/build/data_structures/utils && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adam-torek/StandardDataStructures/data_structures/utils/dummy.cpp -o CMakeFiles/Utils.dir/dummy.cpp.s

# Object files for target Utils
Utils_OBJECTS = \
"CMakeFiles/Utils.dir/dummy.cpp.o"

# External object files for target Utils
Utils_EXTERNAL_OBJECTS =

data_structures/utils/libUtils.a: data_structures/utils/CMakeFiles/Utils.dir/dummy.cpp.o
data_structures/utils/libUtils.a: data_structures/utils/CMakeFiles/Utils.dir/build.make
data_structures/utils/libUtils.a: data_structures/utils/CMakeFiles/Utils.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/adam-torek/StandardDataStructures/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libUtils.a"
	cd /home/adam-torek/StandardDataStructures/build/data_structures/utils && $(CMAKE_COMMAND) -P CMakeFiles/Utils.dir/cmake_clean_target.cmake
	cd /home/adam-torek/StandardDataStructures/build/data_structures/utils && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Utils.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
data_structures/utils/CMakeFiles/Utils.dir/build: data_structures/utils/libUtils.a
.PHONY : data_structures/utils/CMakeFiles/Utils.dir/build

data_structures/utils/CMakeFiles/Utils.dir/clean:
	cd /home/adam-torek/StandardDataStructures/build/data_structures/utils && $(CMAKE_COMMAND) -P CMakeFiles/Utils.dir/cmake_clean.cmake
.PHONY : data_structures/utils/CMakeFiles/Utils.dir/clean

data_structures/utils/CMakeFiles/Utils.dir/depend:
	cd /home/adam-torek/StandardDataStructures/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/adam-torek/StandardDataStructures /home/adam-torek/StandardDataStructures/data_structures/utils /home/adam-torek/StandardDataStructures/build /home/adam-torek/StandardDataStructures/build/data_structures/utils /home/adam-torek/StandardDataStructures/build/data_structures/utils/CMakeFiles/Utils.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : data_structures/utils/CMakeFiles/Utils.dir/depend

