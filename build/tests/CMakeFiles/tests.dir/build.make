# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.27.4/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.27.4/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/miu/git_location/Haptic_Gestures_Library

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/miu/git_location/Haptic_Gestures_Library/build

# Include any dependencies generated for this target.
include tests/CMakeFiles/tests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tests/CMakeFiles/tests.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/tests.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/tests.dir/flags.make

tests/CMakeFiles/tests.dir/src/main.cpp.o: tests/CMakeFiles/tests.dir/flags.make
tests/CMakeFiles/tests.dir/src/main.cpp.o: /Users/miu/git_location/Haptic_Gestures_Library/tests/src/main.cpp
tests/CMakeFiles/tests.dir/src/main.cpp.o: tests/CMakeFiles/tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/miu/git_location/Haptic_Gestures_Library/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/tests.dir/src/main.cpp.o"
	cd /Users/miu/git_location/Haptic_Gestures_Library/build/tests && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/tests.dir/src/main.cpp.o -MF CMakeFiles/tests.dir/src/main.cpp.o.d -o CMakeFiles/tests.dir/src/main.cpp.o -c /Users/miu/git_location/Haptic_Gestures_Library/tests/src/main.cpp

tests/CMakeFiles/tests.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tests.dir/src/main.cpp.i"
	cd /Users/miu/git_location/Haptic_Gestures_Library/build/tests && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/miu/git_location/Haptic_Gestures_Library/tests/src/main.cpp > CMakeFiles/tests.dir/src/main.cpp.i

tests/CMakeFiles/tests.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tests.dir/src/main.cpp.s"
	cd /Users/miu/git_location/Haptic_Gestures_Library/build/tests && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/miu/git_location/Haptic_Gestures_Library/tests/src/main.cpp -o CMakeFiles/tests.dir/src/main.cpp.s

# Object files for target tests
tests_OBJECTS = \
"CMakeFiles/tests.dir/src/main.cpp.o"

# External object files for target tests
tests_EXTERNAL_OBJECTS =

tests/tests: tests/CMakeFiles/tests.dir/src/main.cpp.o
tests/tests: tests/CMakeFiles/tests.dir/build.make
tests/tests: /opt/homebrew/Cellar/liblo/0.32/lib/liblo.dylib
tests/tests: Haptic_Gestures/libHaptic_Gestures.dylib
tests/tests: tests/CMakeFiles/tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/miu/git_location/Haptic_Gestures_Library/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable tests"
	cd /Users/miu/git_location/Haptic_Gestures_Library/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/tests.dir/build: tests/tests
.PHONY : tests/CMakeFiles/tests.dir/build

tests/CMakeFiles/tests.dir/clean:
	cd /Users/miu/git_location/Haptic_Gestures_Library/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/tests.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/tests.dir/clean

tests/CMakeFiles/tests.dir/depend:
	cd /Users/miu/git_location/Haptic_Gestures_Library/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/miu/git_location/Haptic_Gestures_Library /Users/miu/git_location/Haptic_Gestures_Library/tests /Users/miu/git_location/Haptic_Gestures_Library/build /Users/miu/git_location/Haptic_Gestures_Library/build/tests /Users/miu/git_location/Haptic_Gestures_Library/build/tests/CMakeFiles/tests.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : tests/CMakeFiles/tests.dir/depend

