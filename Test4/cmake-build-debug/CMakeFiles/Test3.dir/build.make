# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "F:\Proggs\CLion 2019.1.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "F:\Proggs\CLion 2019.1.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = F:\Proggs\CLionProj\Test4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = F:\Proggs\CLionProj\Test4\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Test3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Test3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Test3.dir/flags.make

CMakeFiles/Test3.dir/srcs/main.c.obj: CMakeFiles/Test3.dir/flags.make
CMakeFiles/Test3.dir/srcs/main.c.obj: CMakeFiles/Test3.dir/includes_C.rsp
CMakeFiles/Test3.dir/srcs/main.c.obj: ../srcs/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Proggs\CLionProj\Test4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Test3.dir/srcs/main.c.obj"
	F:\Proggs\MiniGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Test3.dir\srcs\main.c.obj   -c F:\Proggs\CLionProj\Test4\srcs\main.c

CMakeFiles/Test3.dir/srcs/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Test3.dir/srcs/main.c.i"
	F:\Proggs\MiniGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E F:\Proggs\CLionProj\Test4\srcs\main.c > CMakeFiles\Test3.dir\srcs\main.c.i

CMakeFiles/Test3.dir/srcs/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Test3.dir/srcs/main.c.s"
	F:\Proggs\MiniGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S F:\Proggs\CLionProj\Test4\srcs\main.c -o CMakeFiles\Test3.dir\srcs\main.c.s

CMakeFiles/Test3.dir/srcs/sdl_init.c.obj: CMakeFiles/Test3.dir/flags.make
CMakeFiles/Test3.dir/srcs/sdl_init.c.obj: CMakeFiles/Test3.dir/includes_C.rsp
CMakeFiles/Test3.dir/srcs/sdl_init.c.obj: ../srcs/sdl_init.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Proggs\CLionProj\Test4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Test3.dir/srcs/sdl_init.c.obj"
	F:\Proggs\MiniGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Test3.dir\srcs\sdl_init.c.obj   -c F:\Proggs\CLionProj\Test4\srcs\sdl_init.c

CMakeFiles/Test3.dir/srcs/sdl_init.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Test3.dir/srcs/sdl_init.c.i"
	F:\Proggs\MiniGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E F:\Proggs\CLionProj\Test4\srcs\sdl_init.c > CMakeFiles\Test3.dir\srcs\sdl_init.c.i

CMakeFiles/Test3.dir/srcs/sdl_init.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Test3.dir/srcs/sdl_init.c.s"
	F:\Proggs\MiniGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S F:\Proggs\CLionProj\Test4\srcs\sdl_init.c -o CMakeFiles\Test3.dir\srcs\sdl_init.c.s

CMakeFiles/Test3.dir/srcs/sdl_loop.c.obj: CMakeFiles/Test3.dir/flags.make
CMakeFiles/Test3.dir/srcs/sdl_loop.c.obj: CMakeFiles/Test3.dir/includes_C.rsp
CMakeFiles/Test3.dir/srcs/sdl_loop.c.obj: ../srcs/sdl_loop.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Proggs\CLionProj\Test4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Test3.dir/srcs/sdl_loop.c.obj"
	F:\Proggs\MiniGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Test3.dir\srcs\sdl_loop.c.obj   -c F:\Proggs\CLionProj\Test4\srcs\sdl_loop.c

CMakeFiles/Test3.dir/srcs/sdl_loop.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Test3.dir/srcs/sdl_loop.c.i"
	F:\Proggs\MiniGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E F:\Proggs\CLionProj\Test4\srcs\sdl_loop.c > CMakeFiles\Test3.dir\srcs\sdl_loop.c.i

CMakeFiles/Test3.dir/srcs/sdl_loop.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Test3.dir/srcs/sdl_loop.c.s"
	F:\Proggs\MiniGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S F:\Proggs\CLionProj\Test4\srcs\sdl_loop.c -o CMakeFiles\Test3.dir\srcs\sdl_loop.c.s

CMakeFiles/Test3.dir/srcs/keyhook.c.obj: CMakeFiles/Test3.dir/flags.make
CMakeFiles/Test3.dir/srcs/keyhook.c.obj: CMakeFiles/Test3.dir/includes_C.rsp
CMakeFiles/Test3.dir/srcs/keyhook.c.obj: ../srcs/keyhook.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Proggs\CLionProj\Test4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/Test3.dir/srcs/keyhook.c.obj"
	F:\Proggs\MiniGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Test3.dir\srcs\keyhook.c.obj   -c F:\Proggs\CLionProj\Test4\srcs\keyhook.c

CMakeFiles/Test3.dir/srcs/keyhook.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Test3.dir/srcs/keyhook.c.i"
	F:\Proggs\MiniGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E F:\Proggs\CLionProj\Test4\srcs\keyhook.c > CMakeFiles\Test3.dir\srcs\keyhook.c.i

CMakeFiles/Test3.dir/srcs/keyhook.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Test3.dir/srcs/keyhook.c.s"
	F:\Proggs\MiniGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S F:\Proggs\CLionProj\Test4\srcs\keyhook.c -o CMakeFiles\Test3.dir\srcs\keyhook.c.s

# Object files for target Test3
Test3_OBJECTS = \
"CMakeFiles/Test3.dir/srcs/main.c.obj" \
"CMakeFiles/Test3.dir/srcs/sdl_init.c.obj" \
"CMakeFiles/Test3.dir/srcs/sdl_loop.c.obj" \
"CMakeFiles/Test3.dir/srcs/keyhook.c.obj"

# External object files for target Test3
Test3_EXTERNAL_OBJECTS =

Test3.exe: CMakeFiles/Test3.dir/srcs/main.c.obj
Test3.exe: CMakeFiles/Test3.dir/srcs/sdl_init.c.obj
Test3.exe: CMakeFiles/Test3.dir/srcs/sdl_loop.c.obj
Test3.exe: CMakeFiles/Test3.dir/srcs/keyhook.c.obj
Test3.exe: CMakeFiles/Test3.dir/build.make
Test3.exe: CMakeFiles/Test3.dir/linklibs.rsp
Test3.exe: CMakeFiles/Test3.dir/objects1.rsp
Test3.exe: CMakeFiles/Test3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=F:\Proggs\CLionProj\Test4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable Test3.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Test3.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Test3.dir/build: Test3.exe

.PHONY : CMakeFiles/Test3.dir/build

CMakeFiles/Test3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Test3.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Test3.dir/clean

CMakeFiles/Test3.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" F:\Proggs\CLionProj\Test4 F:\Proggs\CLionProj\Test4 F:\Proggs\CLionProj\Test4\cmake-build-debug F:\Proggs\CLionProj\Test4\cmake-build-debug F:\Proggs\CLionProj\Test4\cmake-build-debug\CMakeFiles\Test3.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Test3.dir/depend

