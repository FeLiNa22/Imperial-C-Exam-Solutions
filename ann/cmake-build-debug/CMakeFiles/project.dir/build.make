# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /snap/clion/112/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/112/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/raul/Desktop/C exams/ann"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/raul/Desktop/C exams/ann/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/project.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/project.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/project.dir/flags.make

CMakeFiles/project.dir/train.c.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/train.c.o: ../train.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/raul/Desktop/C exams/ann/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/project.dir/train.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/project.dir/train.c.o   -c "/home/raul/Desktop/C exams/ann/train.c"

CMakeFiles/project.dir/train.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/project.dir/train.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/raul/Desktop/C exams/ann/train.c" > CMakeFiles/project.dir/train.c.i

CMakeFiles/project.dir/train.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/project.dir/train.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/raul/Desktop/C exams/ann/train.c" -o CMakeFiles/project.dir/train.c.s

CMakeFiles/project.dir/layer.c.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/layer.c.o: ../layer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/raul/Desktop/C exams/ann/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/project.dir/layer.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/project.dir/layer.c.o   -c "/home/raul/Desktop/C exams/ann/layer.c"

CMakeFiles/project.dir/layer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/project.dir/layer.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/raul/Desktop/C exams/ann/layer.c" > CMakeFiles/project.dir/layer.c.i

CMakeFiles/project.dir/layer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/project.dir/layer.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/raul/Desktop/C exams/ann/layer.c" -o CMakeFiles/project.dir/layer.c.s

CMakeFiles/project.dir/ann.c.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/ann.c.o: ../ann.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/raul/Desktop/C exams/ann/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/project.dir/ann.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/project.dir/ann.c.o   -c "/home/raul/Desktop/C exams/ann/ann.c"

CMakeFiles/project.dir/ann.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/project.dir/ann.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/raul/Desktop/C exams/ann/ann.c" > CMakeFiles/project.dir/ann.c.i

CMakeFiles/project.dir/ann.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/project.dir/ann.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/raul/Desktop/C exams/ann/ann.c" -o CMakeFiles/project.dir/ann.c.s

# Object files for target project
project_OBJECTS = \
"CMakeFiles/project.dir/train.c.o" \
"CMakeFiles/project.dir/layer.c.o" \
"CMakeFiles/project.dir/ann.c.o"

# External object files for target project
project_EXTERNAL_OBJECTS =

project: CMakeFiles/project.dir/train.c.o
project: CMakeFiles/project.dir/layer.c.o
project: CMakeFiles/project.dir/ann.c.o
project: CMakeFiles/project.dir/build.make
project: CMakeFiles/project.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/raul/Desktop/C exams/ann/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable project"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/project.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/project.dir/build: project

.PHONY : CMakeFiles/project.dir/build

CMakeFiles/project.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/project.dir/cmake_clean.cmake
.PHONY : CMakeFiles/project.dir/clean

CMakeFiles/project.dir/depend:
	cd "/home/raul/Desktop/C exams/ann/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/raul/Desktop/C exams/ann" "/home/raul/Desktop/C exams/ann" "/home/raul/Desktop/C exams/ann/cmake-build-debug" "/home/raul/Desktop/C exams/ann/cmake-build-debug" "/home/raul/Desktop/C exams/ann/cmake-build-debug/CMakeFiles/project.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/project.dir/depend

