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
CMAKE_SOURCE_DIR = /home/timofey/projects/Task-Manager/Translated

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/timofey/projects/Task-Manager/Translated/build

# Include any dependencies generated for this target.
include CMakeFiles/GeneralRAM.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/GeneralRAM.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/GeneralRAM.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GeneralRAM.dir/flags.make

CMakeFiles/GeneralRAM.dir/src/main.cpp.o: CMakeFiles/GeneralRAM.dir/flags.make
CMakeFiles/GeneralRAM.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/GeneralRAM.dir/src/main.cpp.o: CMakeFiles/GeneralRAM.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/timofey/projects/Task-Manager/Translated/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/GeneralRAM.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GeneralRAM.dir/src/main.cpp.o -MF CMakeFiles/GeneralRAM.dir/src/main.cpp.o.d -o CMakeFiles/GeneralRAM.dir/src/main.cpp.o -c /home/timofey/projects/Task-Manager/Translated/src/main.cpp

CMakeFiles/GeneralRAM.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GeneralRAM.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/timofey/projects/Task-Manager/Translated/src/main.cpp > CMakeFiles/GeneralRAM.dir/src/main.cpp.i

CMakeFiles/GeneralRAM.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GeneralRAM.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/timofey/projects/Task-Manager/Translated/src/main.cpp -o CMakeFiles/GeneralRAM.dir/src/main.cpp.s

CMakeFiles/GeneralRAM.dir/src/ModelGeneralRAM.cpp.o: CMakeFiles/GeneralRAM.dir/flags.make
CMakeFiles/GeneralRAM.dir/src/ModelGeneralRAM.cpp.o: ../src/ModelGeneralRAM.cpp
CMakeFiles/GeneralRAM.dir/src/ModelGeneralRAM.cpp.o: CMakeFiles/GeneralRAM.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/timofey/projects/Task-Manager/Translated/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/GeneralRAM.dir/src/ModelGeneralRAM.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GeneralRAM.dir/src/ModelGeneralRAM.cpp.o -MF CMakeFiles/GeneralRAM.dir/src/ModelGeneralRAM.cpp.o.d -o CMakeFiles/GeneralRAM.dir/src/ModelGeneralRAM.cpp.o -c /home/timofey/projects/Task-Manager/Translated/src/ModelGeneralRAM.cpp

CMakeFiles/GeneralRAM.dir/src/ModelGeneralRAM.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GeneralRAM.dir/src/ModelGeneralRAM.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/timofey/projects/Task-Manager/Translated/src/ModelGeneralRAM.cpp > CMakeFiles/GeneralRAM.dir/src/ModelGeneralRAM.cpp.i

CMakeFiles/GeneralRAM.dir/src/ModelGeneralRAM.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GeneralRAM.dir/src/ModelGeneralRAM.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/timofey/projects/Task-Manager/Translated/src/ModelGeneralRAM.cpp -o CMakeFiles/GeneralRAM.dir/src/ModelGeneralRAM.cpp.s

CMakeFiles/GeneralRAM.dir/src/ViewGeneralRAM.cpp.o: CMakeFiles/GeneralRAM.dir/flags.make
CMakeFiles/GeneralRAM.dir/src/ViewGeneralRAM.cpp.o: ../src/ViewGeneralRAM.cpp
CMakeFiles/GeneralRAM.dir/src/ViewGeneralRAM.cpp.o: CMakeFiles/GeneralRAM.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/timofey/projects/Task-Manager/Translated/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/GeneralRAM.dir/src/ViewGeneralRAM.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GeneralRAM.dir/src/ViewGeneralRAM.cpp.o -MF CMakeFiles/GeneralRAM.dir/src/ViewGeneralRAM.cpp.o.d -o CMakeFiles/GeneralRAM.dir/src/ViewGeneralRAM.cpp.o -c /home/timofey/projects/Task-Manager/Translated/src/ViewGeneralRAM.cpp

CMakeFiles/GeneralRAM.dir/src/ViewGeneralRAM.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GeneralRAM.dir/src/ViewGeneralRAM.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/timofey/projects/Task-Manager/Translated/src/ViewGeneralRAM.cpp > CMakeFiles/GeneralRAM.dir/src/ViewGeneralRAM.cpp.i

CMakeFiles/GeneralRAM.dir/src/ViewGeneralRAM.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GeneralRAM.dir/src/ViewGeneralRAM.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/timofey/projects/Task-Manager/Translated/src/ViewGeneralRAM.cpp -o CMakeFiles/GeneralRAM.dir/src/ViewGeneralRAM.cpp.s

CMakeFiles/GeneralRAM.dir/src/Controller.cpp.o: CMakeFiles/GeneralRAM.dir/flags.make
CMakeFiles/GeneralRAM.dir/src/Controller.cpp.o: ../src/Controller.cpp
CMakeFiles/GeneralRAM.dir/src/Controller.cpp.o: CMakeFiles/GeneralRAM.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/timofey/projects/Task-Manager/Translated/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/GeneralRAM.dir/src/Controller.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GeneralRAM.dir/src/Controller.cpp.o -MF CMakeFiles/GeneralRAM.dir/src/Controller.cpp.o.d -o CMakeFiles/GeneralRAM.dir/src/Controller.cpp.o -c /home/timofey/projects/Task-Manager/Translated/src/Controller.cpp

CMakeFiles/GeneralRAM.dir/src/Controller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GeneralRAM.dir/src/Controller.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/timofey/projects/Task-Manager/Translated/src/Controller.cpp > CMakeFiles/GeneralRAM.dir/src/Controller.cpp.i

CMakeFiles/GeneralRAM.dir/src/Controller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GeneralRAM.dir/src/Controller.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/timofey/projects/Task-Manager/Translated/src/Controller.cpp -o CMakeFiles/GeneralRAM.dir/src/Controller.cpp.s

# Object files for target GeneralRAM
GeneralRAM_OBJECTS = \
"CMakeFiles/GeneralRAM.dir/src/main.cpp.o" \
"CMakeFiles/GeneralRAM.dir/src/ModelGeneralRAM.cpp.o" \
"CMakeFiles/GeneralRAM.dir/src/ViewGeneralRAM.cpp.o" \
"CMakeFiles/GeneralRAM.dir/src/Controller.cpp.o"

# External object files for target GeneralRAM
GeneralRAM_EXTERNAL_OBJECTS =

GeneralRAM: CMakeFiles/GeneralRAM.dir/src/main.cpp.o
GeneralRAM: CMakeFiles/GeneralRAM.dir/src/ModelGeneralRAM.cpp.o
GeneralRAM: CMakeFiles/GeneralRAM.dir/src/ViewGeneralRAM.cpp.o
GeneralRAM: CMakeFiles/GeneralRAM.dir/src/Controller.cpp.o
GeneralRAM: CMakeFiles/GeneralRAM.dir/build.make
GeneralRAM: CMakeFiles/GeneralRAM.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/timofey/projects/Task-Manager/Translated/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable GeneralRAM"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GeneralRAM.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GeneralRAM.dir/build: GeneralRAM
.PHONY : CMakeFiles/GeneralRAM.dir/build

CMakeFiles/GeneralRAM.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/GeneralRAM.dir/cmake_clean.cmake
.PHONY : CMakeFiles/GeneralRAM.dir/clean

CMakeFiles/GeneralRAM.dir/depend:
	cd /home/timofey/projects/Task-Manager/Translated/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/timofey/projects/Task-Manager/Translated /home/timofey/projects/Task-Manager/Translated /home/timofey/projects/Task-Manager/Translated/build /home/timofey/projects/Task-Manager/Translated/build /home/timofey/projects/Task-Manager/Translated/build/CMakeFiles/GeneralRAM.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/GeneralRAM.dir/depend

