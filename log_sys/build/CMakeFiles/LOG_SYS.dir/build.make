# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.22

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\cmake-3.22.0-rc2-windows-x86_64\cmake-3.22.0-rc2-windows-x86_64\bin\cmake.exe

# The command to remove a file.
RM = D:\cmake-3.22.0-rc2-windows-x86_64\cmake-3.22.0-rc2-windows-x86_64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\lab_f1\xjtu_810_nrcl_lab_f1\log_sys

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\lab_f1\xjtu_810_nrcl_lab_f1\log_sys\build

# Include any dependencies generated for this target.
include CMakeFiles/LOG_SYS.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/LOG_SYS.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/LOG_SYS.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LOG_SYS.dir/flags.make

CMakeFiles/LOG_SYS.dir/src/log.cpp.obj: CMakeFiles/LOG_SYS.dir/flags.make
CMakeFiles/LOG_SYS.dir/src/log.cpp.obj: CMakeFiles/LOG_SYS.dir/includes_CXX.rsp
CMakeFiles/LOG_SYS.dir/src/log.cpp.obj: ../src/log.cpp
CMakeFiles/LOG_SYS.dir/src/log.cpp.obj: CMakeFiles/LOG_SYS.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\lab_f1\xjtu_810_nrcl_lab_f1\log_sys\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/LOG_SYS.dir/src/log.cpp.obj"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/LOG_SYS.dir/src/log.cpp.obj -MF CMakeFiles\LOG_SYS.dir\src\log.cpp.obj.d -o CMakeFiles\LOG_SYS.dir\src\log.cpp.obj -c D:\lab_f1\xjtu_810_nrcl_lab_f1\log_sys\src\log.cpp

CMakeFiles/LOG_SYS.dir/src/log.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LOG_SYS.dir/src/log.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\lab_f1\xjtu_810_nrcl_lab_f1\log_sys\src\log.cpp > CMakeFiles\LOG_SYS.dir\src\log.cpp.i

CMakeFiles/LOG_SYS.dir/src/log.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LOG_SYS.dir/src/log.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\lab_f1\xjtu_810_nrcl_lab_f1\log_sys\src\log.cpp -o CMakeFiles\LOG_SYS.dir\src\log.cpp.s

CMakeFiles/LOG_SYS.dir/test/test.cpp.obj: CMakeFiles/LOG_SYS.dir/flags.make
CMakeFiles/LOG_SYS.dir/test/test.cpp.obj: CMakeFiles/LOG_SYS.dir/includes_CXX.rsp
CMakeFiles/LOG_SYS.dir/test/test.cpp.obj: ../test/test.cpp
CMakeFiles/LOG_SYS.dir/test/test.cpp.obj: CMakeFiles/LOG_SYS.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\lab_f1\xjtu_810_nrcl_lab_f1\log_sys\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/LOG_SYS.dir/test/test.cpp.obj"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/LOG_SYS.dir/test/test.cpp.obj -MF CMakeFiles\LOG_SYS.dir\test\test.cpp.obj.d -o CMakeFiles\LOG_SYS.dir\test\test.cpp.obj -c D:\lab_f1\xjtu_810_nrcl_lab_f1\log_sys\test\test.cpp

CMakeFiles/LOG_SYS.dir/test/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LOG_SYS.dir/test/test.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\lab_f1\xjtu_810_nrcl_lab_f1\log_sys\test\test.cpp > CMakeFiles\LOG_SYS.dir\test\test.cpp.i

CMakeFiles/LOG_SYS.dir/test/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LOG_SYS.dir/test/test.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\lab_f1\xjtu_810_nrcl_lab_f1\log_sys\test\test.cpp -o CMakeFiles\LOG_SYS.dir\test\test.cpp.s

# Object files for target LOG_SYS
LOG_SYS_OBJECTS = \
"CMakeFiles/LOG_SYS.dir/src/log.cpp.obj" \
"CMakeFiles/LOG_SYS.dir/test/test.cpp.obj"

# External object files for target LOG_SYS
LOG_SYS_EXTERNAL_OBJECTS =

LOG_SYS.exe: CMakeFiles/LOG_SYS.dir/src/log.cpp.obj
LOG_SYS.exe: CMakeFiles/LOG_SYS.dir/test/test.cpp.obj
LOG_SYS.exe: CMakeFiles/LOG_SYS.dir/build.make
LOG_SYS.exe: CMakeFiles/LOG_SYS.dir/linklibs.rsp
LOG_SYS.exe: CMakeFiles/LOG_SYS.dir/objects1.rsp
LOG_SYS.exe: CMakeFiles/LOG_SYS.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\lab_f1\xjtu_810_nrcl_lab_f1\log_sys\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable LOG_SYS.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\LOG_SYS.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LOG_SYS.dir/build: LOG_SYS.exe
.PHONY : CMakeFiles/LOG_SYS.dir/build

CMakeFiles/LOG_SYS.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\LOG_SYS.dir\cmake_clean.cmake
.PHONY : CMakeFiles/LOG_SYS.dir/clean

CMakeFiles/LOG_SYS.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\lab_f1\xjtu_810_nrcl_lab_f1\log_sys D:\lab_f1\xjtu_810_nrcl_lab_f1\log_sys D:\lab_f1\xjtu_810_nrcl_lab_f1\log_sys\build D:\lab_f1\xjtu_810_nrcl_lab_f1\log_sys\build D:\lab_f1\xjtu_810_nrcl_lab_f1\log_sys\build\CMakeFiles\LOG_SYS.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LOG_SYS.dir/depend

