# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Produce verbose output by default.
VERBOSE = 1

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
CMAKE_COMMAND = "/Users/phillipmai/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/193.6911.21/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/phillipmai/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/193.6911.21/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/phillipmai/CLionProjects/mcs-dev-02a

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/phillipmai/CLionProjects/mcs-dev-02a/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/mcs-dev.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mcs-dev.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mcs-dev.dir/flags.make

CMakeFiles/mcs-dev.dir/main.cpp.o: CMakeFiles/mcs-dev.dir/flags.make
CMakeFiles/mcs-dev.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/phillipmai/CLionProjects/mcs-dev-02a/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mcs-dev.dir/main.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mcs-dev.dir/main.cpp.o -c /Users/phillipmai/CLionProjects/mcs-dev-02a/main.cpp

CMakeFiles/mcs-dev.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mcs-dev.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/phillipmai/CLionProjects/mcs-dev-02a/main.cpp > CMakeFiles/mcs-dev.dir/main.cpp.i

CMakeFiles/mcs-dev.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mcs-dev.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/phillipmai/CLionProjects/mcs-dev-02a/main.cpp -o CMakeFiles/mcs-dev.dir/main.cpp.s

CMakeFiles/mcs-dev.dir/libs/tinyxml2/tinyxml2.cpp.o: CMakeFiles/mcs-dev.dir/flags.make
CMakeFiles/mcs-dev.dir/libs/tinyxml2/tinyxml2.cpp.o: ../libs/tinyxml2/tinyxml2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/phillipmai/CLionProjects/mcs-dev-02a/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/mcs-dev.dir/libs/tinyxml2/tinyxml2.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mcs-dev.dir/libs/tinyxml2/tinyxml2.cpp.o -c /Users/phillipmai/CLionProjects/mcs-dev-02a/libs/tinyxml2/tinyxml2.cpp

CMakeFiles/mcs-dev.dir/libs/tinyxml2/tinyxml2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mcs-dev.dir/libs/tinyxml2/tinyxml2.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/phillipmai/CLionProjects/mcs-dev-02a/libs/tinyxml2/tinyxml2.cpp > CMakeFiles/mcs-dev.dir/libs/tinyxml2/tinyxml2.cpp.i

CMakeFiles/mcs-dev.dir/libs/tinyxml2/tinyxml2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mcs-dev.dir/libs/tinyxml2/tinyxml2.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/phillipmai/CLionProjects/mcs-dev-02a/libs/tinyxml2/tinyxml2.cpp -o CMakeFiles/mcs-dev.dir/libs/tinyxml2/tinyxml2.cpp.s

CMakeFiles/mcs-dev.dir/src/server/server.cpp.o: CMakeFiles/mcs-dev.dir/flags.make
CMakeFiles/mcs-dev.dir/src/server/server.cpp.o: ../src/server/server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/phillipmai/CLionProjects/mcs-dev-02a/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/mcs-dev.dir/src/server/server.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mcs-dev.dir/src/server/server.cpp.o -c /Users/phillipmai/CLionProjects/mcs-dev-02a/src/server/server.cpp

CMakeFiles/mcs-dev.dir/src/server/server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mcs-dev.dir/src/server/server.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/phillipmai/CLionProjects/mcs-dev-02a/src/server/server.cpp > CMakeFiles/mcs-dev.dir/src/server/server.cpp.i

CMakeFiles/mcs-dev.dir/src/server/server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mcs-dev.dir/src/server/server.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/phillipmai/CLionProjects/mcs-dev-02a/src/server/server.cpp -o CMakeFiles/mcs-dev.dir/src/server/server.cpp.s

CMakeFiles/mcs-dev.dir/src/cameracontroller/cameracontroller.cpp.o: CMakeFiles/mcs-dev.dir/flags.make
CMakeFiles/mcs-dev.dir/src/cameracontroller/cameracontroller.cpp.o: ../src/cameracontroller/cameracontroller.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/phillipmai/CLionProjects/mcs-dev-02a/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/mcs-dev.dir/src/cameracontroller/cameracontroller.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mcs-dev.dir/src/cameracontroller/cameracontroller.cpp.o -c /Users/phillipmai/CLionProjects/mcs-dev-02a/src/cameracontroller/cameracontroller.cpp

CMakeFiles/mcs-dev.dir/src/cameracontroller/cameracontroller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mcs-dev.dir/src/cameracontroller/cameracontroller.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/phillipmai/CLionProjects/mcs-dev-02a/src/cameracontroller/cameracontroller.cpp > CMakeFiles/mcs-dev.dir/src/cameracontroller/cameracontroller.cpp.i

CMakeFiles/mcs-dev.dir/src/cameracontroller/cameracontroller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mcs-dev.dir/src/cameracontroller/cameracontroller.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/phillipmai/CLionProjects/mcs-dev-02a/src/cameracontroller/cameracontroller.cpp -o CMakeFiles/mcs-dev.dir/src/cameracontroller/cameracontroller.cpp.s

CMakeFiles/mcs-dev.dir/src/rootstream/rootstream.cpp.o: CMakeFiles/mcs-dev.dir/flags.make
CMakeFiles/mcs-dev.dir/src/rootstream/rootstream.cpp.o: ../src/rootstream/rootstream.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/phillipmai/CLionProjects/mcs-dev-02a/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/mcs-dev.dir/src/rootstream/rootstream.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mcs-dev.dir/src/rootstream/rootstream.cpp.o -c /Users/phillipmai/CLionProjects/mcs-dev-02a/src/rootstream/rootstream.cpp

CMakeFiles/mcs-dev.dir/src/rootstream/rootstream.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mcs-dev.dir/src/rootstream/rootstream.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/phillipmai/CLionProjects/mcs-dev-02a/src/rootstream/rootstream.cpp > CMakeFiles/mcs-dev.dir/src/rootstream/rootstream.cpp.i

CMakeFiles/mcs-dev.dir/src/rootstream/rootstream.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mcs-dev.dir/src/rootstream/rootstream.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/phillipmai/CLionProjects/mcs-dev-02a/src/rootstream/rootstream.cpp -o CMakeFiles/mcs-dev.dir/src/rootstream/rootstream.cpp.s

CMakeFiles/mcs-dev.dir/src/clientstream/clientstream.cpp.o: CMakeFiles/mcs-dev.dir/flags.make
CMakeFiles/mcs-dev.dir/src/clientstream/clientstream.cpp.o: ../src/clientstream/clientstream.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/phillipmai/CLionProjects/mcs-dev-02a/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/mcs-dev.dir/src/clientstream/clientstream.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mcs-dev.dir/src/clientstream/clientstream.cpp.o -c /Users/phillipmai/CLionProjects/mcs-dev-02a/src/clientstream/clientstream.cpp

CMakeFiles/mcs-dev.dir/src/clientstream/clientstream.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mcs-dev.dir/src/clientstream/clientstream.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/phillipmai/CLionProjects/mcs-dev-02a/src/clientstream/clientstream.cpp > CMakeFiles/mcs-dev.dir/src/clientstream/clientstream.cpp.i

CMakeFiles/mcs-dev.dir/src/clientstream/clientstream.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mcs-dev.dir/src/clientstream/clientstream.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/phillipmai/CLionProjects/mcs-dev-02a/src/clientstream/clientstream.cpp -o CMakeFiles/mcs-dev.dir/src/clientstream/clientstream.cpp.s

# Object files for target mcs-dev
mcs__dev_OBJECTS = \
"CMakeFiles/mcs-dev.dir/main.cpp.o" \
"CMakeFiles/mcs-dev.dir/libs/tinyxml2/tinyxml2.cpp.o" \
"CMakeFiles/mcs-dev.dir/src/server/server.cpp.o" \
"CMakeFiles/mcs-dev.dir/src/cameracontroller/cameracontroller.cpp.o" \
"CMakeFiles/mcs-dev.dir/src/rootstream/rootstream.cpp.o" \
"CMakeFiles/mcs-dev.dir/src/clientstream/clientstream.cpp.o"

# External object files for target mcs-dev
mcs__dev_EXTERNAL_OBJECTS =

mcs-dev: CMakeFiles/mcs-dev.dir/main.cpp.o
mcs-dev: CMakeFiles/mcs-dev.dir/libs/tinyxml2/tinyxml2.cpp.o
mcs-dev: CMakeFiles/mcs-dev.dir/src/server/server.cpp.o
mcs-dev: CMakeFiles/mcs-dev.dir/src/cameracontroller/cameracontroller.cpp.o
mcs-dev: CMakeFiles/mcs-dev.dir/src/rootstream/rootstream.cpp.o
mcs-dev: CMakeFiles/mcs-dev.dir/src/clientstream/clientstream.cpp.o
mcs-dev: CMakeFiles/mcs-dev.dir/build.make
mcs-dev: /usr/local/lib/libgstrtspserver-1.0.dylib
mcs-dev: /usr/local/lib/libgstrtspserver-1.0.dylib
mcs-dev: CMakeFiles/mcs-dev.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/phillipmai/CLionProjects/mcs-dev-02a/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable mcs-dev"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mcs-dev.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mcs-dev.dir/build: mcs-dev

.PHONY : CMakeFiles/mcs-dev.dir/build

CMakeFiles/mcs-dev.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mcs-dev.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mcs-dev.dir/clean

CMakeFiles/mcs-dev.dir/depend:
	cd /Users/phillipmai/CLionProjects/mcs-dev-02a/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/phillipmai/CLionProjects/mcs-dev-02a /Users/phillipmai/CLionProjects/mcs-dev-02a /Users/phillipmai/CLionProjects/mcs-dev-02a/cmake-build-debug /Users/phillipmai/CLionProjects/mcs-dev-02a/cmake-build-debug /Users/phillipmai/CLionProjects/mcs-dev-02a/cmake-build-debug/CMakeFiles/mcs-dev.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mcs-dev.dir/depend

