# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/joseph/Projects/TMBR

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/joseph/Projects/TMBR

# Include any dependencies generated for this target.
include deps/glew-2.0.0/build/cmake/CMakeFiles/glew_s.dir/depend.make

# Include the progress variables for this target.
include deps/glew-2.0.0/build/cmake/CMakeFiles/glew_s.dir/progress.make

# Include the compile flags for this target's objects.
include deps/glew-2.0.0/build/cmake/CMakeFiles/glew_s.dir/flags.make

deps/glew-2.0.0/build/cmake/CMakeFiles/glew_s.dir/__/__/src/glew.c.o: deps/glew-2.0.0/build/cmake/CMakeFiles/glew_s.dir/flags.make
deps/glew-2.0.0/build/cmake/CMakeFiles/glew_s.dir/__/__/src/glew.c.o: deps/glew-2.0.0/src/glew.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/joseph/Projects/TMBR/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object deps/glew-2.0.0/build/cmake/CMakeFiles/glew_s.dir/__/__/src/glew.c.o"
	cd /home/joseph/Projects/TMBR/deps/glew-2.0.0/build/cmake && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glew_s.dir/__/__/src/glew.c.o   -c /home/joseph/Projects/TMBR/deps/glew-2.0.0/src/glew.c

deps/glew-2.0.0/build/cmake/CMakeFiles/glew_s.dir/__/__/src/glew.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glew_s.dir/__/__/src/glew.c.i"
	cd /home/joseph/Projects/TMBR/deps/glew-2.0.0/build/cmake && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/joseph/Projects/TMBR/deps/glew-2.0.0/src/glew.c > CMakeFiles/glew_s.dir/__/__/src/glew.c.i

deps/glew-2.0.0/build/cmake/CMakeFiles/glew_s.dir/__/__/src/glew.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glew_s.dir/__/__/src/glew.c.s"
	cd /home/joseph/Projects/TMBR/deps/glew-2.0.0/build/cmake && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/joseph/Projects/TMBR/deps/glew-2.0.0/src/glew.c -o CMakeFiles/glew_s.dir/__/__/src/glew.c.s

deps/glew-2.0.0/build/cmake/CMakeFiles/glew_s.dir/__/__/src/glew.c.o.requires:

.PHONY : deps/glew-2.0.0/build/cmake/CMakeFiles/glew_s.dir/__/__/src/glew.c.o.requires

deps/glew-2.0.0/build/cmake/CMakeFiles/glew_s.dir/__/__/src/glew.c.o.provides: deps/glew-2.0.0/build/cmake/CMakeFiles/glew_s.dir/__/__/src/glew.c.o.requires
	$(MAKE) -f deps/glew-2.0.0/build/cmake/CMakeFiles/glew_s.dir/build.make deps/glew-2.0.0/build/cmake/CMakeFiles/glew_s.dir/__/__/src/glew.c.o.provides.build
.PHONY : deps/glew-2.0.0/build/cmake/CMakeFiles/glew_s.dir/__/__/src/glew.c.o.provides

deps/glew-2.0.0/build/cmake/CMakeFiles/glew_s.dir/__/__/src/glew.c.o.provides.build: deps/glew-2.0.0/build/cmake/CMakeFiles/glew_s.dir/__/__/src/glew.c.o


# Object files for target glew_s
glew_s_OBJECTS = \
"CMakeFiles/glew_s.dir/__/__/src/glew.c.o"

# External object files for target glew_s
glew_s_EXTERNAL_OBJECTS =

lib/libGLEW.a: deps/glew-2.0.0/build/cmake/CMakeFiles/glew_s.dir/__/__/src/glew.c.o
lib/libGLEW.a: deps/glew-2.0.0/build/cmake/CMakeFiles/glew_s.dir/build.make
lib/libGLEW.a: deps/glew-2.0.0/build/cmake/CMakeFiles/glew_s.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/joseph/Projects/TMBR/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library ../../../../lib/libGLEW.a"
	cd /home/joseph/Projects/TMBR/deps/glew-2.0.0/build/cmake && $(CMAKE_COMMAND) -P CMakeFiles/glew_s.dir/cmake_clean_target.cmake
	cd /home/joseph/Projects/TMBR/deps/glew-2.0.0/build/cmake && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/glew_s.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
deps/glew-2.0.0/build/cmake/CMakeFiles/glew_s.dir/build: lib/libGLEW.a

.PHONY : deps/glew-2.0.0/build/cmake/CMakeFiles/glew_s.dir/build

deps/glew-2.0.0/build/cmake/CMakeFiles/glew_s.dir/requires: deps/glew-2.0.0/build/cmake/CMakeFiles/glew_s.dir/__/__/src/glew.c.o.requires

.PHONY : deps/glew-2.0.0/build/cmake/CMakeFiles/glew_s.dir/requires

deps/glew-2.0.0/build/cmake/CMakeFiles/glew_s.dir/clean:
	cd /home/joseph/Projects/TMBR/deps/glew-2.0.0/build/cmake && $(CMAKE_COMMAND) -P CMakeFiles/glew_s.dir/cmake_clean.cmake
.PHONY : deps/glew-2.0.0/build/cmake/CMakeFiles/glew_s.dir/clean

deps/glew-2.0.0/build/cmake/CMakeFiles/glew_s.dir/depend:
	cd /home/joseph/Projects/TMBR && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/joseph/Projects/TMBR /home/joseph/Projects/TMBR/deps/glew-2.0.0/build/cmake /home/joseph/Projects/TMBR /home/joseph/Projects/TMBR/deps/glew-2.0.0/build/cmake /home/joseph/Projects/TMBR/deps/glew-2.0.0/build/cmake/CMakeFiles/glew_s.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : deps/glew-2.0.0/build/cmake/CMakeFiles/glew_s.dir/depend

