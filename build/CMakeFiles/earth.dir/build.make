# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.2.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.2.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Shea/Projects/bluedot

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Shea/Projects/bluedot/build

# Include any dependencies generated for this target.
include CMakeFiles/earth.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/earth.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/earth.dir/flags.make

CMakeFiles/earth.dir/source/common/ObjMesh.cpp.o: CMakeFiles/earth.dir/flags.make
CMakeFiles/earth.dir/source/common/ObjMesh.cpp.o: ../source/common/ObjMesh.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Shea/Projects/bluedot/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/earth.dir/source/common/ObjMesh.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/earth.dir/source/common/ObjMesh.cpp.o -c /Users/Shea/Projects/bluedot/source/common/ObjMesh.cpp

CMakeFiles/earth.dir/source/common/ObjMesh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/earth.dir/source/common/ObjMesh.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/Shea/Projects/bluedot/source/common/ObjMesh.cpp > CMakeFiles/earth.dir/source/common/ObjMesh.cpp.i

CMakeFiles/earth.dir/source/common/ObjMesh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/earth.dir/source/common/ObjMesh.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/Shea/Projects/bluedot/source/common/ObjMesh.cpp -o CMakeFiles/earth.dir/source/common/ObjMesh.cpp.s

CMakeFiles/earth.dir/source/common/ObjMesh.cpp.o.requires:
.PHONY : CMakeFiles/earth.dir/source/common/ObjMesh.cpp.o.requires

CMakeFiles/earth.dir/source/common/ObjMesh.cpp.o.provides: CMakeFiles/earth.dir/source/common/ObjMesh.cpp.o.requires
	$(MAKE) -f CMakeFiles/earth.dir/build.make CMakeFiles/earth.dir/source/common/ObjMesh.cpp.o.provides.build
.PHONY : CMakeFiles/earth.dir/source/common/ObjMesh.cpp.o.provides

CMakeFiles/earth.dir/source/common/ObjMesh.cpp.o.provides.build: CMakeFiles/earth.dir/source/common/ObjMesh.cpp.o

CMakeFiles/earth.dir/source/common/InitShader.cpp.o: CMakeFiles/earth.dir/flags.make
CMakeFiles/earth.dir/source/common/InitShader.cpp.o: ../source/common/InitShader.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Shea/Projects/bluedot/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/earth.dir/source/common/InitShader.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/earth.dir/source/common/InitShader.cpp.o -c /Users/Shea/Projects/bluedot/source/common/InitShader.cpp

CMakeFiles/earth.dir/source/common/InitShader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/earth.dir/source/common/InitShader.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/Shea/Projects/bluedot/source/common/InitShader.cpp > CMakeFiles/earth.dir/source/common/InitShader.cpp.i

CMakeFiles/earth.dir/source/common/InitShader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/earth.dir/source/common/InitShader.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/Shea/Projects/bluedot/source/common/InitShader.cpp -o CMakeFiles/earth.dir/source/common/InitShader.cpp.s

CMakeFiles/earth.dir/source/common/InitShader.cpp.o.requires:
.PHONY : CMakeFiles/earth.dir/source/common/InitShader.cpp.o.requires

CMakeFiles/earth.dir/source/common/InitShader.cpp.o.provides: CMakeFiles/earth.dir/source/common/InitShader.cpp.o.requires
	$(MAKE) -f CMakeFiles/earth.dir/build.make CMakeFiles/earth.dir/source/common/InitShader.cpp.o.provides.build
.PHONY : CMakeFiles/earth.dir/source/common/InitShader.cpp.o.provides

CMakeFiles/earth.dir/source/common/InitShader.cpp.o.provides.build: CMakeFiles/earth.dir/source/common/InitShader.cpp.o

CMakeFiles/earth.dir/source/common/SourcePath.cpp.o: CMakeFiles/earth.dir/flags.make
CMakeFiles/earth.dir/source/common/SourcePath.cpp.o: ../source/common/SourcePath.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Shea/Projects/bluedot/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/earth.dir/source/common/SourcePath.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/earth.dir/source/common/SourcePath.cpp.o -c /Users/Shea/Projects/bluedot/source/common/SourcePath.cpp

CMakeFiles/earth.dir/source/common/SourcePath.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/earth.dir/source/common/SourcePath.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/Shea/Projects/bluedot/source/common/SourcePath.cpp > CMakeFiles/earth.dir/source/common/SourcePath.cpp.i

CMakeFiles/earth.dir/source/common/SourcePath.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/earth.dir/source/common/SourcePath.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/Shea/Projects/bluedot/source/common/SourcePath.cpp -o CMakeFiles/earth.dir/source/common/SourcePath.cpp.s

CMakeFiles/earth.dir/source/common/SourcePath.cpp.o.requires:
.PHONY : CMakeFiles/earth.dir/source/common/SourcePath.cpp.o.requires

CMakeFiles/earth.dir/source/common/SourcePath.cpp.o.provides: CMakeFiles/earth.dir/source/common/SourcePath.cpp.o.requires
	$(MAKE) -f CMakeFiles/earth.dir/build.make CMakeFiles/earth.dir/source/common/SourcePath.cpp.o.provides.build
.PHONY : CMakeFiles/earth.dir/source/common/SourcePath.cpp.o.provides

CMakeFiles/earth.dir/source/common/SourcePath.cpp.o.provides.build: CMakeFiles/earth.dir/source/common/SourcePath.cpp.o

CMakeFiles/earth.dir/source/common/Trackball.cpp.o: CMakeFiles/earth.dir/flags.make
CMakeFiles/earth.dir/source/common/Trackball.cpp.o: ../source/common/Trackball.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Shea/Projects/bluedot/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/earth.dir/source/common/Trackball.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/earth.dir/source/common/Trackball.cpp.o -c /Users/Shea/Projects/bluedot/source/common/Trackball.cpp

CMakeFiles/earth.dir/source/common/Trackball.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/earth.dir/source/common/Trackball.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/Shea/Projects/bluedot/source/common/Trackball.cpp > CMakeFiles/earth.dir/source/common/Trackball.cpp.i

CMakeFiles/earth.dir/source/common/Trackball.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/earth.dir/source/common/Trackball.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/Shea/Projects/bluedot/source/common/Trackball.cpp -o CMakeFiles/earth.dir/source/common/Trackball.cpp.s

CMakeFiles/earth.dir/source/common/Trackball.cpp.o.requires:
.PHONY : CMakeFiles/earth.dir/source/common/Trackball.cpp.o.requires

CMakeFiles/earth.dir/source/common/Trackball.cpp.o.provides: CMakeFiles/earth.dir/source/common/Trackball.cpp.o.requires
	$(MAKE) -f CMakeFiles/earth.dir/build.make CMakeFiles/earth.dir/source/common/Trackball.cpp.o.provides.build
.PHONY : CMakeFiles/earth.dir/source/common/Trackball.cpp.o.provides

CMakeFiles/earth.dir/source/common/Trackball.cpp.o.provides.build: CMakeFiles/earth.dir/source/common/Trackball.cpp.o

CMakeFiles/earth.dir/source/Earth.cpp.o: CMakeFiles/earth.dir/flags.make
CMakeFiles/earth.dir/source/Earth.cpp.o: ../source/Earth.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/Shea/Projects/bluedot/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/earth.dir/source/Earth.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/earth.dir/source/Earth.cpp.o -c /Users/Shea/Projects/bluedot/source/Earth.cpp

CMakeFiles/earth.dir/source/Earth.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/earth.dir/source/Earth.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/Shea/Projects/bluedot/source/Earth.cpp > CMakeFiles/earth.dir/source/Earth.cpp.i

CMakeFiles/earth.dir/source/Earth.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/earth.dir/source/Earth.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/Shea/Projects/bluedot/source/Earth.cpp -o CMakeFiles/earth.dir/source/Earth.cpp.s

CMakeFiles/earth.dir/source/Earth.cpp.o.requires:
.PHONY : CMakeFiles/earth.dir/source/Earth.cpp.o.requires

CMakeFiles/earth.dir/source/Earth.cpp.o.provides: CMakeFiles/earth.dir/source/Earth.cpp.o.requires
	$(MAKE) -f CMakeFiles/earth.dir/build.make CMakeFiles/earth.dir/source/Earth.cpp.o.provides.build
.PHONY : CMakeFiles/earth.dir/source/Earth.cpp.o.provides

CMakeFiles/earth.dir/source/Earth.cpp.o.provides.build: CMakeFiles/earth.dir/source/Earth.cpp.o

# Object files for target earth
earth_OBJECTS = \
"CMakeFiles/earth.dir/source/common/ObjMesh.cpp.o" \
"CMakeFiles/earth.dir/source/common/InitShader.cpp.o" \
"CMakeFiles/earth.dir/source/common/SourcePath.cpp.o" \
"CMakeFiles/earth.dir/source/common/Trackball.cpp.o" \
"CMakeFiles/earth.dir/source/Earth.cpp.o"

# External object files for target earth
earth_EXTERNAL_OBJECTS =

earth: CMakeFiles/earth.dir/source/common/ObjMesh.cpp.o
earth: CMakeFiles/earth.dir/source/common/InitShader.cpp.o
earth: CMakeFiles/earth.dir/source/common/SourcePath.cpp.o
earth: CMakeFiles/earth.dir/source/common/Trackball.cpp.o
earth: CMakeFiles/earth.dir/source/Earth.cpp.o
earth: CMakeFiles/earth.dir/build.make
earth: /usr/local/lib/libjpeg.dylib
earth: /usr/local/lib/libpng.dylib
earth: CMakeFiles/earth.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable earth"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/earth.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/earth.dir/build: earth
.PHONY : CMakeFiles/earth.dir/build

CMakeFiles/earth.dir/requires: CMakeFiles/earth.dir/source/common/ObjMesh.cpp.o.requires
CMakeFiles/earth.dir/requires: CMakeFiles/earth.dir/source/common/InitShader.cpp.o.requires
CMakeFiles/earth.dir/requires: CMakeFiles/earth.dir/source/common/SourcePath.cpp.o.requires
CMakeFiles/earth.dir/requires: CMakeFiles/earth.dir/source/common/Trackball.cpp.o.requires
CMakeFiles/earth.dir/requires: CMakeFiles/earth.dir/source/Earth.cpp.o.requires
.PHONY : CMakeFiles/earth.dir/requires

CMakeFiles/earth.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/earth.dir/cmake_clean.cmake
.PHONY : CMakeFiles/earth.dir/clean

CMakeFiles/earth.dir/depend:
	cd /Users/Shea/Projects/bluedot/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Shea/Projects/bluedot /Users/Shea/Projects/bluedot /Users/Shea/Projects/bluedot/build /Users/Shea/Projects/bluedot/build /Users/Shea/Projects/bluedot/build/CMakeFiles/earth.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/earth.dir/depend

