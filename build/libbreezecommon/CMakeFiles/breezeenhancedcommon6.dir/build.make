# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_SOURCE_DIR = /home/rtx/Desktop/BreezeEnhanced-master

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rtx/Desktop/BreezeEnhanced-master/build

# Include any dependencies generated for this target.
include libbreezecommon/CMakeFiles/breezeenhancedcommon6.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include libbreezecommon/CMakeFiles/breezeenhancedcommon6.dir/compiler_depend.make

# Include the progress variables for this target.
include libbreezecommon/CMakeFiles/breezeenhancedcommon6.dir/progress.make

# Include the compile flags for this target's objects.
include libbreezecommon/CMakeFiles/breezeenhancedcommon6.dir/flags.make

libbreezecommon/breezeenhancedcommon6_autogen/timestamp: /usr/lib/qt6/moc
libbreezecommon/breezeenhancedcommon6_autogen/timestamp: libbreezecommon/CMakeFiles/breezeenhancedcommon6.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/rtx/Desktop/BreezeEnhanced-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC for target breezeenhancedcommon6"
	cd /home/rtx/Desktop/BreezeEnhanced-master/build/libbreezecommon && /usr/bin/cmake -E cmake_autogen /home/rtx/Desktop/BreezeEnhanced-master/build/libbreezecommon/CMakeFiles/breezeenhancedcommon6_autogen.dir/AutogenInfo.json Release
	cd /home/rtx/Desktop/BreezeEnhanced-master/build/libbreezecommon && /usr/bin/cmake -E touch /home/rtx/Desktop/BreezeEnhanced-master/build/libbreezecommon/breezeenhancedcommon6_autogen/timestamp

libbreezecommon/CMakeFiles/breezeenhancedcommon6.dir/breezeenhancedcommon6_autogen/mocs_compilation.cpp.o: libbreezecommon/CMakeFiles/breezeenhancedcommon6.dir/flags.make
libbreezecommon/CMakeFiles/breezeenhancedcommon6.dir/breezeenhancedcommon6_autogen/mocs_compilation.cpp.o: libbreezecommon/breezeenhancedcommon6_autogen/mocs_compilation.cpp
libbreezecommon/CMakeFiles/breezeenhancedcommon6.dir/breezeenhancedcommon6_autogen/mocs_compilation.cpp.o: libbreezecommon/CMakeFiles/breezeenhancedcommon6.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/rtx/Desktop/BreezeEnhanced-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object libbreezecommon/CMakeFiles/breezeenhancedcommon6.dir/breezeenhancedcommon6_autogen/mocs_compilation.cpp.o"
	cd /home/rtx/Desktop/BreezeEnhanced-master/build/libbreezecommon && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT libbreezecommon/CMakeFiles/breezeenhancedcommon6.dir/breezeenhancedcommon6_autogen/mocs_compilation.cpp.o -MF CMakeFiles/breezeenhancedcommon6.dir/breezeenhancedcommon6_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/breezeenhancedcommon6.dir/breezeenhancedcommon6_autogen/mocs_compilation.cpp.o -c /home/rtx/Desktop/BreezeEnhanced-master/build/libbreezecommon/breezeenhancedcommon6_autogen/mocs_compilation.cpp

libbreezecommon/CMakeFiles/breezeenhancedcommon6.dir/breezeenhancedcommon6_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/breezeenhancedcommon6.dir/breezeenhancedcommon6_autogen/mocs_compilation.cpp.i"
	cd /home/rtx/Desktop/BreezeEnhanced-master/build/libbreezecommon && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rtx/Desktop/BreezeEnhanced-master/build/libbreezecommon/breezeenhancedcommon6_autogen/mocs_compilation.cpp > CMakeFiles/breezeenhancedcommon6.dir/breezeenhancedcommon6_autogen/mocs_compilation.cpp.i

libbreezecommon/CMakeFiles/breezeenhancedcommon6.dir/breezeenhancedcommon6_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/breezeenhancedcommon6.dir/breezeenhancedcommon6_autogen/mocs_compilation.cpp.s"
	cd /home/rtx/Desktop/BreezeEnhanced-master/build/libbreezecommon && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rtx/Desktop/BreezeEnhanced-master/build/libbreezecommon/breezeenhancedcommon6_autogen/mocs_compilation.cpp -o CMakeFiles/breezeenhancedcommon6.dir/breezeenhancedcommon6_autogen/mocs_compilation.cpp.s

libbreezecommon/CMakeFiles/breezeenhancedcommon6.dir/breezeboxshadowrenderer.cpp.o: libbreezecommon/CMakeFiles/breezeenhancedcommon6.dir/flags.make
libbreezecommon/CMakeFiles/breezeenhancedcommon6.dir/breezeboxshadowrenderer.cpp.o: /home/rtx/Desktop/BreezeEnhanced-master/libbreezecommon/breezeboxshadowrenderer.cpp
libbreezecommon/CMakeFiles/breezeenhancedcommon6.dir/breezeboxshadowrenderer.cpp.o: libbreezecommon/CMakeFiles/breezeenhancedcommon6.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/rtx/Desktop/BreezeEnhanced-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object libbreezecommon/CMakeFiles/breezeenhancedcommon6.dir/breezeboxshadowrenderer.cpp.o"
	cd /home/rtx/Desktop/BreezeEnhanced-master/build/libbreezecommon && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT libbreezecommon/CMakeFiles/breezeenhancedcommon6.dir/breezeboxshadowrenderer.cpp.o -MF CMakeFiles/breezeenhancedcommon6.dir/breezeboxshadowrenderer.cpp.o.d -o CMakeFiles/breezeenhancedcommon6.dir/breezeboxshadowrenderer.cpp.o -c /home/rtx/Desktop/BreezeEnhanced-master/libbreezecommon/breezeboxshadowrenderer.cpp

libbreezecommon/CMakeFiles/breezeenhancedcommon6.dir/breezeboxshadowrenderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/breezeenhancedcommon6.dir/breezeboxshadowrenderer.cpp.i"
	cd /home/rtx/Desktop/BreezeEnhanced-master/build/libbreezecommon && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rtx/Desktop/BreezeEnhanced-master/libbreezecommon/breezeboxshadowrenderer.cpp > CMakeFiles/breezeenhancedcommon6.dir/breezeboxshadowrenderer.cpp.i

libbreezecommon/CMakeFiles/breezeenhancedcommon6.dir/breezeboxshadowrenderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/breezeenhancedcommon6.dir/breezeboxshadowrenderer.cpp.s"
	cd /home/rtx/Desktop/BreezeEnhanced-master/build/libbreezecommon && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rtx/Desktop/BreezeEnhanced-master/libbreezecommon/breezeboxshadowrenderer.cpp -o CMakeFiles/breezeenhancedcommon6.dir/breezeboxshadowrenderer.cpp.s

# Object files for target breezeenhancedcommon6
breezeenhancedcommon6_OBJECTS = \
"CMakeFiles/breezeenhancedcommon6.dir/breezeenhancedcommon6_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/breezeenhancedcommon6.dir/breezeboxshadowrenderer.cpp.o"

# External object files for target breezeenhancedcommon6
breezeenhancedcommon6_EXTERNAL_OBJECTS =

bin/libbreezeenhancedcommon6.so.6.0.0: libbreezecommon/CMakeFiles/breezeenhancedcommon6.dir/breezeenhancedcommon6_autogen/mocs_compilation.cpp.o
bin/libbreezeenhancedcommon6.so.6.0.0: libbreezecommon/CMakeFiles/breezeenhancedcommon6.dir/breezeboxshadowrenderer.cpp.o
bin/libbreezeenhancedcommon6.so.6.0.0: libbreezecommon/CMakeFiles/breezeenhancedcommon6.dir/build.make
bin/libbreezeenhancedcommon6.so.6.0.0: /usr/lib/libGLX.so
bin/libbreezeenhancedcommon6.so.6.0.0: /usr/lib/libOpenGL.so
bin/libbreezeenhancedcommon6.so.6.0.0: libbreezecommon/CMakeFiles/breezeenhancedcommon6.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/rtx/Desktop/BreezeEnhanced-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX shared library ../bin/libbreezeenhancedcommon6.so"
	cd /home/rtx/Desktop/BreezeEnhanced-master/build/libbreezecommon && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/breezeenhancedcommon6.dir/link.txt --verbose=$(VERBOSE)
	cd /home/rtx/Desktop/BreezeEnhanced-master/build/libbreezecommon && $(CMAKE_COMMAND) -E cmake_symlink_library ../bin/libbreezeenhancedcommon6.so.6.0.0 ../bin/libbreezeenhancedcommon6.so.6 ../bin/libbreezeenhancedcommon6.so

bin/libbreezeenhancedcommon6.so.6: bin/libbreezeenhancedcommon6.so.6.0.0
	@$(CMAKE_COMMAND) -E touch_nocreate bin/libbreezeenhancedcommon6.so.6

bin/libbreezeenhancedcommon6.so: bin/libbreezeenhancedcommon6.so.6.0.0
	@$(CMAKE_COMMAND) -E touch_nocreate bin/libbreezeenhancedcommon6.so

# Rule to build all files generated by this target.
libbreezecommon/CMakeFiles/breezeenhancedcommon6.dir/build: bin/libbreezeenhancedcommon6.so
.PHONY : libbreezecommon/CMakeFiles/breezeenhancedcommon6.dir/build

libbreezecommon/CMakeFiles/breezeenhancedcommon6.dir/clean:
	cd /home/rtx/Desktop/BreezeEnhanced-master/build/libbreezecommon && $(CMAKE_COMMAND) -P CMakeFiles/breezeenhancedcommon6.dir/cmake_clean.cmake
.PHONY : libbreezecommon/CMakeFiles/breezeenhancedcommon6.dir/clean

libbreezecommon/CMakeFiles/breezeenhancedcommon6.dir/depend: libbreezecommon/breezeenhancedcommon6_autogen/timestamp
	cd /home/rtx/Desktop/BreezeEnhanced-master/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rtx/Desktop/BreezeEnhanced-master /home/rtx/Desktop/BreezeEnhanced-master/libbreezecommon /home/rtx/Desktop/BreezeEnhanced-master/build /home/rtx/Desktop/BreezeEnhanced-master/build/libbreezecommon /home/rtx/Desktop/BreezeEnhanced-master/build/libbreezecommon/CMakeFiles/breezeenhancedcommon6.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : libbreezecommon/CMakeFiles/breezeenhancedcommon6.dir/depend
