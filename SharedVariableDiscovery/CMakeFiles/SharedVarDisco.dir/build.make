# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /home/bernard/Software/clion-2017.2.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/bernard/Software/clion-2017.2.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/bernard/Workspace/GitHub/SyncFault-LLVM/SharedVariableDiscovery/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bernard/Workspace/GitHub/SyncFault-LLVM/SharedVariableDiscovery

# Include any dependencies generated for this target.
include CMakeFiles/SharedVarDisco.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SharedVarDisco.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SharedVarDisco.dir/flags.make

CMakeFiles/SharedVarDisco.dir/SharedVarDisco.o: CMakeFiles/SharedVarDisco.dir/flags.make
CMakeFiles/SharedVarDisco.dir/SharedVarDisco.o: src/SharedVarDisco.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bernard/Workspace/GitHub/SyncFault-LLVM/SharedVariableDiscovery/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SharedVarDisco.dir/SharedVarDisco.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SharedVarDisco.dir/SharedVarDisco.o -c /home/bernard/Workspace/GitHub/SyncFault-LLVM/SharedVariableDiscovery/src/SharedVarDisco.cpp

CMakeFiles/SharedVarDisco.dir/SharedVarDisco.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SharedVarDisco.dir/SharedVarDisco.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bernard/Workspace/GitHub/SyncFault-LLVM/SharedVariableDiscovery/src/SharedVarDisco.cpp > CMakeFiles/SharedVarDisco.dir/SharedVarDisco.i

CMakeFiles/SharedVarDisco.dir/SharedVarDisco.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SharedVarDisco.dir/SharedVarDisco.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bernard/Workspace/GitHub/SyncFault-LLVM/SharedVariableDiscovery/src/SharedVarDisco.cpp -o CMakeFiles/SharedVarDisco.dir/SharedVarDisco.s

CMakeFiles/SharedVarDisco.dir/SharedVarDisco.o.requires:

.PHONY : CMakeFiles/SharedVarDisco.dir/SharedVarDisco.o.requires

CMakeFiles/SharedVarDisco.dir/SharedVarDisco.o.provides: CMakeFiles/SharedVarDisco.dir/SharedVarDisco.o.requires
	$(MAKE) -f CMakeFiles/SharedVarDisco.dir/build.make CMakeFiles/SharedVarDisco.dir/SharedVarDisco.o.provides.build
.PHONY : CMakeFiles/SharedVarDisco.dir/SharedVarDisco.o.provides

CMakeFiles/SharedVarDisco.dir/SharedVarDisco.o.provides.build: CMakeFiles/SharedVarDisco.dir/SharedVarDisco.o


CMakeFiles/SharedVarDisco.dir/SharedVarDiscoEngine.o: CMakeFiles/SharedVarDisco.dir/flags.make
CMakeFiles/SharedVarDisco.dir/SharedVarDiscoEngine.o: src/SharedVarDiscoEngine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bernard/Workspace/GitHub/SyncFault-LLVM/SharedVariableDiscovery/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SharedVarDisco.dir/SharedVarDiscoEngine.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SharedVarDisco.dir/SharedVarDiscoEngine.o -c /home/bernard/Workspace/GitHub/SyncFault-LLVM/SharedVariableDiscovery/src/SharedVarDiscoEngine.cpp

CMakeFiles/SharedVarDisco.dir/SharedVarDiscoEngine.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SharedVarDisco.dir/SharedVarDiscoEngine.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bernard/Workspace/GitHub/SyncFault-LLVM/SharedVariableDiscovery/src/SharedVarDiscoEngine.cpp > CMakeFiles/SharedVarDisco.dir/SharedVarDiscoEngine.i

CMakeFiles/SharedVarDisco.dir/SharedVarDiscoEngine.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SharedVarDisco.dir/SharedVarDiscoEngine.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bernard/Workspace/GitHub/SyncFault-LLVM/SharedVariableDiscovery/src/SharedVarDiscoEngine.cpp -o CMakeFiles/SharedVarDisco.dir/SharedVarDiscoEngine.s

CMakeFiles/SharedVarDisco.dir/SharedVarDiscoEngine.o.requires:

.PHONY : CMakeFiles/SharedVarDisco.dir/SharedVarDiscoEngine.o.requires

CMakeFiles/SharedVarDisco.dir/SharedVarDiscoEngine.o.provides: CMakeFiles/SharedVarDisco.dir/SharedVarDiscoEngine.o.requires
	$(MAKE) -f CMakeFiles/SharedVarDisco.dir/build.make CMakeFiles/SharedVarDisco.dir/SharedVarDiscoEngine.o.provides.build
.PHONY : CMakeFiles/SharedVarDisco.dir/SharedVarDiscoEngine.o.provides

CMakeFiles/SharedVarDisco.dir/SharedVarDiscoEngine.o.provides.build: CMakeFiles/SharedVarDisco.dir/SharedVarDiscoEngine.o


# Object files for target SharedVarDisco
SharedVarDisco_OBJECTS = \
"CMakeFiles/SharedVarDisco.dir/SharedVarDisco.o" \
"CMakeFiles/SharedVarDisco.dir/SharedVarDiscoEngine.o"

# External object files for target SharedVarDisco
SharedVarDisco_EXTERNAL_OBJECTS =

libSharedVarDisco.so: CMakeFiles/SharedVarDisco.dir/SharedVarDisco.o
libSharedVarDisco.so: CMakeFiles/SharedVarDisco.dir/SharedVarDiscoEngine.o
libSharedVarDisco.so: CMakeFiles/SharedVarDisco.dir/build.make
libSharedVarDisco.so: CMakeFiles/SharedVarDisco.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bernard/Workspace/GitHub/SyncFault-LLVM/SharedVariableDiscovery/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX shared module libSharedVarDisco.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SharedVarDisco.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SharedVarDisco.dir/build: libSharedVarDisco.so

.PHONY : CMakeFiles/SharedVarDisco.dir/build

CMakeFiles/SharedVarDisco.dir/requires: CMakeFiles/SharedVarDisco.dir/SharedVarDisco.o.requires
CMakeFiles/SharedVarDisco.dir/requires: CMakeFiles/SharedVarDisco.dir/SharedVarDiscoEngine.o.requires

.PHONY : CMakeFiles/SharedVarDisco.dir/requires

CMakeFiles/SharedVarDisco.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SharedVarDisco.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SharedVarDisco.dir/clean

CMakeFiles/SharedVarDisco.dir/depend:
	cd /home/bernard/Workspace/GitHub/SyncFault-LLVM/SharedVariableDiscovery && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bernard/Workspace/GitHub/SyncFault-LLVM/SharedVariableDiscovery/src /home/bernard/Workspace/GitHub/SyncFault-LLVM/SharedVariableDiscovery/src /home/bernard/Workspace/GitHub/SyncFault-LLVM/SharedVariableDiscovery /home/bernard/Workspace/GitHub/SyncFault-LLVM/SharedVariableDiscovery /home/bernard/Workspace/GitHub/SyncFault-LLVM/SharedVariableDiscovery/CMakeFiles/SharedVarDisco.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SharedVarDisco.dir/depend
