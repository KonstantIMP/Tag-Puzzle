# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/konstantin/Projects/Tag-Puzzle

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/konstantin/Projects/Tag-Puzzle

# Include any dependencies generated for this target.
include CMakeFiles/tag_puzzle.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tag_puzzle.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tag_puzzle.dir/flags.make

CMakeFiles/tag_puzzle.dir/src/main.cpp.o: CMakeFiles/tag_puzzle.dir/flags.make
CMakeFiles/tag_puzzle.dir/src/main.cpp.o: src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/konstantin/Projects/Tag-Puzzle/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tag_puzzle.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tag_puzzle.dir/src/main.cpp.o -c /home/konstantin/Projects/Tag-Puzzle/src/main.cpp

CMakeFiles/tag_puzzle.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tag_puzzle.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/konstantin/Projects/Tag-Puzzle/src/main.cpp > CMakeFiles/tag_puzzle.dir/src/main.cpp.i

CMakeFiles/tag_puzzle.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tag_puzzle.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/konstantin/Projects/Tag-Puzzle/src/main.cpp -o CMakeFiles/tag_puzzle.dir/src/main.cpp.s

CMakeFiles/tag_puzzle.dir/src/tag_puzzle.cpp.o: CMakeFiles/tag_puzzle.dir/flags.make
CMakeFiles/tag_puzzle.dir/src/tag_puzzle.cpp.o: src/tag_puzzle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/konstantin/Projects/Tag-Puzzle/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/tag_puzzle.dir/src/tag_puzzle.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tag_puzzle.dir/src/tag_puzzle.cpp.o -c /home/konstantin/Projects/Tag-Puzzle/src/tag_puzzle.cpp

CMakeFiles/tag_puzzle.dir/src/tag_puzzle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tag_puzzle.dir/src/tag_puzzle.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/konstantin/Projects/Tag-Puzzle/src/tag_puzzle.cpp > CMakeFiles/tag_puzzle.dir/src/tag_puzzle.cpp.i

CMakeFiles/tag_puzzle.dir/src/tag_puzzle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tag_puzzle.dir/src/tag_puzzle.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/konstantin/Projects/Tag-Puzzle/src/tag_puzzle.cpp -o CMakeFiles/tag_puzzle.dir/src/tag_puzzle.cpp.s

# Object files for target tag_puzzle
tag_puzzle_OBJECTS = \
"CMakeFiles/tag_puzzle.dir/src/main.cpp.o" \
"CMakeFiles/tag_puzzle.dir/src/tag_puzzle.cpp.o"

# External object files for target tag_puzzle
tag_puzzle_EXTERNAL_OBJECTS =

tag_puzzle: CMakeFiles/tag_puzzle.dir/src/main.cpp.o
tag_puzzle: CMakeFiles/tag_puzzle.dir/src/tag_puzzle.cpp.o
tag_puzzle: CMakeFiles/tag_puzzle.dir/build.make
tag_puzzle: /usr/lib/libsfml-graphics.so.2.5.1
tag_puzzle: /usr/lib/libsfml-network.so.2.5.1
tag_puzzle: /usr/lib/libsfml-audio.so.2.5.1
tag_puzzle: /usr/lib/libsfml-window.so.2.5.1
tag_puzzle: /usr/lib/libsfml-system.so.2.5.1
tag_puzzle: CMakeFiles/tag_puzzle.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/konstantin/Projects/Tag-Puzzle/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable tag_puzzle"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tag_puzzle.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tag_puzzle.dir/build: tag_puzzle

.PHONY : CMakeFiles/tag_puzzle.dir/build

CMakeFiles/tag_puzzle.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tag_puzzle.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tag_puzzle.dir/clean

CMakeFiles/tag_puzzle.dir/depend:
	cd /home/konstantin/Projects/Tag-Puzzle && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/konstantin/Projects/Tag-Puzzle /home/konstantin/Projects/Tag-Puzzle /home/konstantin/Projects/Tag-Puzzle /home/konstantin/Projects/Tag-Puzzle /home/konstantin/Projects/Tag-Puzzle/CMakeFiles/tag_puzzle.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tag_puzzle.dir/depend
