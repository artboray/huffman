# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Applications/lastchance/huffman

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Applications/lastchance/huffman/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/huffman-coding.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/huffman-coding.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/huffman-coding.dir/flags.make

CMakeFiles/huffman-coding.dir/lib/huffman.cpp.o: CMakeFiles/huffman-coding.dir/flags.make
CMakeFiles/huffman-coding.dir/lib/huffman.cpp.o: ../lib/huffman.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Applications/lastchance/huffman/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/huffman-coding.dir/lib/huffman.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/huffman-coding.dir/lib/huffman.cpp.o -c /Applications/lastchance/huffman/lib/huffman.cpp

CMakeFiles/huffman-coding.dir/lib/huffman.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/huffman-coding.dir/lib/huffman.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Applications/lastchance/huffman/lib/huffman.cpp > CMakeFiles/huffman-coding.dir/lib/huffman.cpp.i

CMakeFiles/huffman-coding.dir/lib/huffman.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/huffman-coding.dir/lib/huffman.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Applications/lastchance/huffman/lib/huffman.cpp -o CMakeFiles/huffman-coding.dir/lib/huffman.cpp.s

CMakeFiles/huffman-coding.dir/lib/huffman.cpp.o.requires:

.PHONY : CMakeFiles/huffman-coding.dir/lib/huffman.cpp.o.requires

CMakeFiles/huffman-coding.dir/lib/huffman.cpp.o.provides: CMakeFiles/huffman-coding.dir/lib/huffman.cpp.o.requires
	$(MAKE) -f CMakeFiles/huffman-coding.dir/build.make CMakeFiles/huffman-coding.dir/lib/huffman.cpp.o.provides.build
.PHONY : CMakeFiles/huffman-coding.dir/lib/huffman.cpp.o.provides

CMakeFiles/huffman-coding.dir/lib/huffman.cpp.o.provides.build: CMakeFiles/huffman-coding.dir/lib/huffman.cpp.o


# Object files for target huffman-coding
huffman__coding_OBJECTS = \
"CMakeFiles/huffman-coding.dir/lib/huffman.cpp.o"

# External object files for target huffman-coding
huffman__coding_EXTERNAL_OBJECTS =

libhuffman-coding.a: CMakeFiles/huffman-coding.dir/lib/huffman.cpp.o
libhuffman-coding.a: CMakeFiles/huffman-coding.dir/build.make
libhuffman-coding.a: CMakeFiles/huffman-coding.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Applications/lastchance/huffman/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libhuffman-coding.a"
	$(CMAKE_COMMAND) -P CMakeFiles/huffman-coding.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/huffman-coding.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/huffman-coding.dir/build: libhuffman-coding.a

.PHONY : CMakeFiles/huffman-coding.dir/build

CMakeFiles/huffman-coding.dir/requires: CMakeFiles/huffman-coding.dir/lib/huffman.cpp.o.requires

.PHONY : CMakeFiles/huffman-coding.dir/requires

CMakeFiles/huffman-coding.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/huffman-coding.dir/cmake_clean.cmake
.PHONY : CMakeFiles/huffman-coding.dir/clean

CMakeFiles/huffman-coding.dir/depend:
	cd /Applications/lastchance/huffman/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Applications/lastchance/huffman /Applications/lastchance/huffman /Applications/lastchance/huffman/cmake-build-debug /Applications/lastchance/huffman/cmake-build-debug /Applications/lastchance/huffman/cmake-build-debug/CMakeFiles/huffman-coding.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/huffman-coding.dir/depend

