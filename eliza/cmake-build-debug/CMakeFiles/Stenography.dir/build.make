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
CMAKE_COMMAND = /snap/clion/114/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/114/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/raul/Desktop/C exams/eliza_skeleton"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/raul/Desktop/C exams/eliza_skeleton/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Stenography.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Stenography.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Stenography.dir/flags.make

CMakeFiles/Stenography.dir/eliza.c.o: CMakeFiles/Stenography.dir/flags.make
CMakeFiles/Stenography.dir/eliza.c.o: ../eliza.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/raul/Desktop/C exams/eliza_skeleton/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Stenography.dir/eliza.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Stenography.dir/eliza.c.o   -c "/home/raul/Desktop/C exams/eliza_skeleton/eliza.c"

CMakeFiles/Stenography.dir/eliza.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Stenography.dir/eliza.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/raul/Desktop/C exams/eliza_skeleton/eliza.c" > CMakeFiles/Stenography.dir/eliza.c.i

CMakeFiles/Stenography.dir/eliza.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Stenography.dir/eliza.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/raul/Desktop/C exams/eliza_skeleton/eliza.c" -o CMakeFiles/Stenography.dir/eliza.c.s

CMakeFiles/Stenography.dir/eliza_state.c.o: CMakeFiles/Stenography.dir/flags.make
CMakeFiles/Stenography.dir/eliza_state.c.o: ../eliza_state.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/raul/Desktop/C exams/eliza_skeleton/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Stenography.dir/eliza_state.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Stenography.dir/eliza_state.c.o   -c "/home/raul/Desktop/C exams/eliza_skeleton/eliza_state.c"

CMakeFiles/Stenography.dir/eliza_state.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Stenography.dir/eliza_state.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/raul/Desktop/C exams/eliza_skeleton/eliza_state.c" > CMakeFiles/Stenography.dir/eliza_state.c.i

CMakeFiles/Stenography.dir/eliza_state.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Stenography.dir/eliza_state.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/raul/Desktop/C exams/eliza_skeleton/eliza_state.c" -o CMakeFiles/Stenography.dir/eliza_state.c.s

CMakeFiles/Stenography.dir/string_utils.c.o: CMakeFiles/Stenography.dir/flags.make
CMakeFiles/Stenography.dir/string_utils.c.o: ../string_utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/raul/Desktop/C exams/eliza_skeleton/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Stenography.dir/string_utils.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Stenography.dir/string_utils.c.o   -c "/home/raul/Desktop/C exams/eliza_skeleton/string_utils.c"

CMakeFiles/Stenography.dir/string_utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Stenography.dir/string_utils.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/raul/Desktop/C exams/eliza_skeleton/string_utils.c" > CMakeFiles/Stenography.dir/string_utils.c.i

CMakeFiles/Stenography.dir/string_utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Stenography.dir/string_utils.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/raul/Desktop/C exams/eliza_skeleton/string_utils.c" -o CMakeFiles/Stenography.dir/string_utils.c.s

CMakeFiles/Stenography.dir/list.c.o: CMakeFiles/Stenography.dir/flags.make
CMakeFiles/Stenography.dir/list.c.o: ../list.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/raul/Desktop/C exams/eliza_skeleton/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/Stenography.dir/list.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Stenography.dir/list.c.o   -c "/home/raul/Desktop/C exams/eliza_skeleton/list.c"

CMakeFiles/Stenography.dir/list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Stenography.dir/list.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/raul/Desktop/C exams/eliza_skeleton/list.c" > CMakeFiles/Stenography.dir/list.c.i

CMakeFiles/Stenography.dir/list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Stenography.dir/list.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/raul/Desktop/C exams/eliza_skeleton/list.c" -o CMakeFiles/Stenography.dir/list.c.s

CMakeFiles/Stenography.dir/map.c.o: CMakeFiles/Stenography.dir/flags.make
CMakeFiles/Stenography.dir/map.c.o: ../map.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/raul/Desktop/C exams/eliza_skeleton/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/Stenography.dir/map.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Stenography.dir/map.c.o   -c "/home/raul/Desktop/C exams/eliza_skeleton/map.c"

CMakeFiles/Stenography.dir/map.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Stenography.dir/map.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/raul/Desktop/C exams/eliza_skeleton/map.c" > CMakeFiles/Stenography.dir/map.c.i

CMakeFiles/Stenography.dir/map.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Stenography.dir/map.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/raul/Desktop/C exams/eliza_skeleton/map.c" -o CMakeFiles/Stenography.dir/map.c.s

CMakeFiles/Stenography.dir/parser.c.o: CMakeFiles/Stenography.dir/flags.make
CMakeFiles/Stenography.dir/parser.c.o: ../parser.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/raul/Desktop/C exams/eliza_skeleton/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/Stenography.dir/parser.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Stenography.dir/parser.c.o   -c "/home/raul/Desktop/C exams/eliza_skeleton/parser.c"

CMakeFiles/Stenography.dir/parser.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Stenography.dir/parser.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/raul/Desktop/C exams/eliza_skeleton/parser.c" > CMakeFiles/Stenography.dir/parser.c.i

CMakeFiles/Stenography.dir/parser.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Stenography.dir/parser.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/raul/Desktop/C exams/eliza_skeleton/parser.c" -o CMakeFiles/Stenography.dir/parser.c.s

CMakeFiles/Stenography.dir/rule.c.o: CMakeFiles/Stenography.dir/flags.make
CMakeFiles/Stenography.dir/rule.c.o: ../rule.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/raul/Desktop/C exams/eliza_skeleton/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/Stenography.dir/rule.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Stenography.dir/rule.c.o   -c "/home/raul/Desktop/C exams/eliza_skeleton/rule.c"

CMakeFiles/Stenography.dir/rule.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Stenography.dir/rule.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/raul/Desktop/C exams/eliza_skeleton/rule.c" > CMakeFiles/Stenography.dir/rule.c.i

CMakeFiles/Stenography.dir/rule.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Stenography.dir/rule.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/raul/Desktop/C exams/eliza_skeleton/rule.c" -o CMakeFiles/Stenography.dir/rule.c.s

# Object files for target Stenography
Stenography_OBJECTS = \
"CMakeFiles/Stenography.dir/eliza.c.o" \
"CMakeFiles/Stenography.dir/eliza_state.c.o" \
"CMakeFiles/Stenography.dir/string_utils.c.o" \
"CMakeFiles/Stenography.dir/list.c.o" \
"CMakeFiles/Stenography.dir/map.c.o" \
"CMakeFiles/Stenography.dir/parser.c.o" \
"CMakeFiles/Stenography.dir/rule.c.o"

# External object files for target Stenography
Stenography_EXTERNAL_OBJECTS =

Stenography: CMakeFiles/Stenography.dir/eliza.c.o
Stenography: CMakeFiles/Stenography.dir/eliza_state.c.o
Stenography: CMakeFiles/Stenography.dir/string_utils.c.o
Stenography: CMakeFiles/Stenography.dir/list.c.o
Stenography: CMakeFiles/Stenography.dir/map.c.o
Stenography: CMakeFiles/Stenography.dir/parser.c.o
Stenography: CMakeFiles/Stenography.dir/rule.c.o
Stenography: CMakeFiles/Stenography.dir/build.make
Stenography: CMakeFiles/Stenography.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/raul/Desktop/C exams/eliza_skeleton/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Linking C executable Stenography"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Stenography.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Stenography.dir/build: Stenography

.PHONY : CMakeFiles/Stenography.dir/build

CMakeFiles/Stenography.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Stenography.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Stenography.dir/clean

CMakeFiles/Stenography.dir/depend:
	cd "/home/raul/Desktop/C exams/eliza_skeleton/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/raul/Desktop/C exams/eliza_skeleton" "/home/raul/Desktop/C exams/eliza_skeleton" "/home/raul/Desktop/C exams/eliza_skeleton/cmake-build-debug" "/home/raul/Desktop/C exams/eliza_skeleton/cmake-build-debug" "/home/raul/Desktop/C exams/eliza_skeleton/cmake-build-debug/CMakeFiles/Stenography.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Stenography.dir/depend

