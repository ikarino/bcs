# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.1

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.1.0/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.1.0/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ikarino/Dropbox/work/bcs/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ikarino/Dropbox/work/bcs/build

# Include any dependencies generated for this target.
include CMakeFiles/blood.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/blood.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/blood.dir/flags.make

CMakeFiles/blood.dir/main.cpp.o: CMakeFiles/blood.dir/flags.make
CMakeFiles/blood.dir/main.cpp.o: /Users/ikarino/Dropbox/work/bcs/src/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/ikarino/Dropbox/work/bcs/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/blood.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/blood.dir/main.cpp.o -c /Users/ikarino/Dropbox/work/bcs/src/main.cpp

CMakeFiles/blood.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/blood.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/ikarino/Dropbox/work/bcs/src/main.cpp > CMakeFiles/blood.dir/main.cpp.i

CMakeFiles/blood.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/blood.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/ikarino/Dropbox/work/bcs/src/main.cpp -o CMakeFiles/blood.dir/main.cpp.s

CMakeFiles/blood.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/blood.dir/main.cpp.o.requires

CMakeFiles/blood.dir/main.cpp.o.provides: CMakeFiles/blood.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/blood.dir/build.make CMakeFiles/blood.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/blood.dir/main.cpp.o.provides

CMakeFiles/blood.dir/main.cpp.o.provides.build: CMakeFiles/blood.dir/main.cpp.o

CMakeFiles/blood.dir/GUIField.cpp.o: CMakeFiles/blood.dir/flags.make
CMakeFiles/blood.dir/GUIField.cpp.o: /Users/ikarino/Dropbox/work/bcs/src/GUIField.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/ikarino/Dropbox/work/bcs/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/blood.dir/GUIField.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/blood.dir/GUIField.cpp.o -c /Users/ikarino/Dropbox/work/bcs/src/GUIField.cpp

CMakeFiles/blood.dir/GUIField.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/blood.dir/GUIField.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/ikarino/Dropbox/work/bcs/src/GUIField.cpp > CMakeFiles/blood.dir/GUIField.cpp.i

CMakeFiles/blood.dir/GUIField.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/blood.dir/GUIField.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/ikarino/Dropbox/work/bcs/src/GUIField.cpp -o CMakeFiles/blood.dir/GUIField.cpp.s

CMakeFiles/blood.dir/GUIField.cpp.o.requires:
.PHONY : CMakeFiles/blood.dir/GUIField.cpp.o.requires

CMakeFiles/blood.dir/GUIField.cpp.o.provides: CMakeFiles/blood.dir/GUIField.cpp.o.requires
	$(MAKE) -f CMakeFiles/blood.dir/build.make CMakeFiles/blood.dir/GUIField.cpp.o.provides.build
.PHONY : CMakeFiles/blood.dir/GUIField.cpp.o.provides

CMakeFiles/blood.dir/GUIField.cpp.o.provides.build: CMakeFiles/blood.dir/GUIField.cpp.o

CMakeFiles/blood.dir/status.cpp.o: CMakeFiles/blood.dir/flags.make
CMakeFiles/blood.dir/status.cpp.o: /Users/ikarino/Dropbox/work/bcs/src/status.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/ikarino/Dropbox/work/bcs/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/blood.dir/status.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/blood.dir/status.cpp.o -c /Users/ikarino/Dropbox/work/bcs/src/status.cpp

CMakeFiles/blood.dir/status.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/blood.dir/status.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/ikarino/Dropbox/work/bcs/src/status.cpp > CMakeFiles/blood.dir/status.cpp.i

CMakeFiles/blood.dir/status.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/blood.dir/status.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/ikarino/Dropbox/work/bcs/src/status.cpp -o CMakeFiles/blood.dir/status.cpp.s

CMakeFiles/blood.dir/status.cpp.o.requires:
.PHONY : CMakeFiles/blood.dir/status.cpp.o.requires

CMakeFiles/blood.dir/status.cpp.o.provides: CMakeFiles/blood.dir/status.cpp.o.requires
	$(MAKE) -f CMakeFiles/blood.dir/build.make CMakeFiles/blood.dir/status.cpp.o.provides.build
.PHONY : CMakeFiles/blood.dir/status.cpp.o.provides

CMakeFiles/blood.dir/status.cpp.o.provides.build: CMakeFiles/blood.dir/status.cpp.o

CMakeFiles/blood.dir/Bloodhand.cpp.o: CMakeFiles/blood.dir/flags.make
CMakeFiles/blood.dir/Bloodhand.cpp.o: /Users/ikarino/Dropbox/work/bcs/src/Bloodhand.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/ikarino/Dropbox/work/bcs/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/blood.dir/Bloodhand.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/blood.dir/Bloodhand.cpp.o -c /Users/ikarino/Dropbox/work/bcs/src/Bloodhand.cpp

CMakeFiles/blood.dir/Bloodhand.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/blood.dir/Bloodhand.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/ikarino/Dropbox/work/bcs/src/Bloodhand.cpp > CMakeFiles/blood.dir/Bloodhand.cpp.i

CMakeFiles/blood.dir/Bloodhand.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/blood.dir/Bloodhand.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/ikarino/Dropbox/work/bcs/src/Bloodhand.cpp -o CMakeFiles/blood.dir/Bloodhand.cpp.s

CMakeFiles/blood.dir/Bloodhand.cpp.o.requires:
.PHONY : CMakeFiles/blood.dir/Bloodhand.cpp.o.requires

CMakeFiles/blood.dir/Bloodhand.cpp.o.provides: CMakeFiles/blood.dir/Bloodhand.cpp.o.requires
	$(MAKE) -f CMakeFiles/blood.dir/build.make CMakeFiles/blood.dir/Bloodhand.cpp.o.provides.build
.PHONY : CMakeFiles/blood.dir/Bloodhand.cpp.o.provides

CMakeFiles/blood.dir/Bloodhand.cpp.o.provides.build: CMakeFiles/blood.dir/Bloodhand.cpp.o

CMakeFiles/blood.dir/Daimajin.cpp.o: CMakeFiles/blood.dir/flags.make
CMakeFiles/blood.dir/Daimajin.cpp.o: /Users/ikarino/Dropbox/work/bcs/src/Daimajin.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/ikarino/Dropbox/work/bcs/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/blood.dir/Daimajin.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/blood.dir/Daimajin.cpp.o -c /Users/ikarino/Dropbox/work/bcs/src/Daimajin.cpp

CMakeFiles/blood.dir/Daimajin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/blood.dir/Daimajin.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/ikarino/Dropbox/work/bcs/src/Daimajin.cpp > CMakeFiles/blood.dir/Daimajin.cpp.i

CMakeFiles/blood.dir/Daimajin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/blood.dir/Daimajin.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/ikarino/Dropbox/work/bcs/src/Daimajin.cpp -o CMakeFiles/blood.dir/Daimajin.cpp.s

CMakeFiles/blood.dir/Daimajin.cpp.o.requires:
.PHONY : CMakeFiles/blood.dir/Daimajin.cpp.o.requires

CMakeFiles/blood.dir/Daimajin.cpp.o.provides: CMakeFiles/blood.dir/Daimajin.cpp.o.requires
	$(MAKE) -f CMakeFiles/blood.dir/build.make CMakeFiles/blood.dir/Daimajin.cpp.o.provides.build
.PHONY : CMakeFiles/blood.dir/Daimajin.cpp.o.provides

CMakeFiles/blood.dir/Daimajin.cpp.o.provides.build: CMakeFiles/blood.dir/Daimajin.cpp.o

CMakeFiles/blood.dir/Summon.cpp.o: CMakeFiles/blood.dir/flags.make
CMakeFiles/blood.dir/Summon.cpp.o: /Users/ikarino/Dropbox/work/bcs/src/Summon.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/ikarino/Dropbox/work/bcs/build/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/blood.dir/Summon.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/blood.dir/Summon.cpp.o -c /Users/ikarino/Dropbox/work/bcs/src/Summon.cpp

CMakeFiles/blood.dir/Summon.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/blood.dir/Summon.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/ikarino/Dropbox/work/bcs/src/Summon.cpp > CMakeFiles/blood.dir/Summon.cpp.i

CMakeFiles/blood.dir/Summon.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/blood.dir/Summon.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/ikarino/Dropbox/work/bcs/src/Summon.cpp -o CMakeFiles/blood.dir/Summon.cpp.s

CMakeFiles/blood.dir/Summon.cpp.o.requires:
.PHONY : CMakeFiles/blood.dir/Summon.cpp.o.requires

CMakeFiles/blood.dir/Summon.cpp.o.provides: CMakeFiles/blood.dir/Summon.cpp.o.requires
	$(MAKE) -f CMakeFiles/blood.dir/build.make CMakeFiles/blood.dir/Summon.cpp.o.provides.build
.PHONY : CMakeFiles/blood.dir/Summon.cpp.o.provides

CMakeFiles/blood.dir/Summon.cpp.o.provides.build: CMakeFiles/blood.dir/Summon.cpp.o

CMakeFiles/blood.dir/Map.cpp.o: CMakeFiles/blood.dir/flags.make
CMakeFiles/blood.dir/Map.cpp.o: /Users/ikarino/Dropbox/work/bcs/src/Map.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/ikarino/Dropbox/work/bcs/build/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/blood.dir/Map.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/blood.dir/Map.cpp.o -c /Users/ikarino/Dropbox/work/bcs/src/Map.cpp

CMakeFiles/blood.dir/Map.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/blood.dir/Map.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/ikarino/Dropbox/work/bcs/src/Map.cpp > CMakeFiles/blood.dir/Map.cpp.i

CMakeFiles/blood.dir/Map.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/blood.dir/Map.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/ikarino/Dropbox/work/bcs/src/Map.cpp -o CMakeFiles/blood.dir/Map.cpp.s

CMakeFiles/blood.dir/Map.cpp.o.requires:
.PHONY : CMakeFiles/blood.dir/Map.cpp.o.requires

CMakeFiles/blood.dir/Map.cpp.o.provides: CMakeFiles/blood.dir/Map.cpp.o.requires
	$(MAKE) -f CMakeFiles/blood.dir/build.make CMakeFiles/blood.dir/Map.cpp.o.provides.build
.PHONY : CMakeFiles/blood.dir/Map.cpp.o.provides

CMakeFiles/blood.dir/Map.cpp.o.provides.build: CMakeFiles/blood.dir/Map.cpp.o

CMakeFiles/blood.dir/Unit.cpp.o: CMakeFiles/blood.dir/flags.make
CMakeFiles/blood.dir/Unit.cpp.o: /Users/ikarino/Dropbox/work/bcs/src/Unit.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/ikarino/Dropbox/work/bcs/build/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/blood.dir/Unit.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/blood.dir/Unit.cpp.o -c /Users/ikarino/Dropbox/work/bcs/src/Unit.cpp

CMakeFiles/blood.dir/Unit.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/blood.dir/Unit.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/ikarino/Dropbox/work/bcs/src/Unit.cpp > CMakeFiles/blood.dir/Unit.cpp.i

CMakeFiles/blood.dir/Unit.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/blood.dir/Unit.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/ikarino/Dropbox/work/bcs/src/Unit.cpp -o CMakeFiles/blood.dir/Unit.cpp.s

CMakeFiles/blood.dir/Unit.cpp.o.requires:
.PHONY : CMakeFiles/blood.dir/Unit.cpp.o.requires

CMakeFiles/blood.dir/Unit.cpp.o.provides: CMakeFiles/blood.dir/Unit.cpp.o.requires
	$(MAKE) -f CMakeFiles/blood.dir/build.make CMakeFiles/blood.dir/Unit.cpp.o.provides.build
.PHONY : CMakeFiles/blood.dir/Unit.cpp.o.provides

CMakeFiles/blood.dir/Unit.cpp.o.provides.build: CMakeFiles/blood.dir/Unit.cpp.o

# Object files for target blood
blood_OBJECTS = \
"CMakeFiles/blood.dir/main.cpp.o" \
"CMakeFiles/blood.dir/GUIField.cpp.o" \
"CMakeFiles/blood.dir/status.cpp.o" \
"CMakeFiles/blood.dir/Bloodhand.cpp.o" \
"CMakeFiles/blood.dir/Daimajin.cpp.o" \
"CMakeFiles/blood.dir/Summon.cpp.o" \
"CMakeFiles/blood.dir/Map.cpp.o" \
"CMakeFiles/blood.dir/Unit.cpp.o"

# External object files for target blood
blood_EXTERNAL_OBJECTS =

blood: CMakeFiles/blood.dir/main.cpp.o
blood: CMakeFiles/blood.dir/GUIField.cpp.o
blood: CMakeFiles/blood.dir/status.cpp.o
blood: CMakeFiles/blood.dir/Bloodhand.cpp.o
blood: CMakeFiles/blood.dir/Daimajin.cpp.o
blood: CMakeFiles/blood.dir/Summon.cpp.o
blood: CMakeFiles/blood.dir/Map.cpp.o
blood: CMakeFiles/blood.dir/Unit.cpp.o
blood: CMakeFiles/blood.dir/build.make
blood: CMakeFiles/blood.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable blood"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/blood.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/blood.dir/build: blood
.PHONY : CMakeFiles/blood.dir/build

CMakeFiles/blood.dir/requires: CMakeFiles/blood.dir/main.cpp.o.requires
CMakeFiles/blood.dir/requires: CMakeFiles/blood.dir/GUIField.cpp.o.requires
CMakeFiles/blood.dir/requires: CMakeFiles/blood.dir/status.cpp.o.requires
CMakeFiles/blood.dir/requires: CMakeFiles/blood.dir/Bloodhand.cpp.o.requires
CMakeFiles/blood.dir/requires: CMakeFiles/blood.dir/Daimajin.cpp.o.requires
CMakeFiles/blood.dir/requires: CMakeFiles/blood.dir/Summon.cpp.o.requires
CMakeFiles/blood.dir/requires: CMakeFiles/blood.dir/Map.cpp.o.requires
CMakeFiles/blood.dir/requires: CMakeFiles/blood.dir/Unit.cpp.o.requires
.PHONY : CMakeFiles/blood.dir/requires

CMakeFiles/blood.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/blood.dir/cmake_clean.cmake
.PHONY : CMakeFiles/blood.dir/clean

CMakeFiles/blood.dir/depend:
	cd /Users/ikarino/Dropbox/work/bcs/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ikarino/Dropbox/work/bcs/src /Users/ikarino/Dropbox/work/bcs/src /Users/ikarino/Dropbox/work/bcs/build /Users/ikarino/Dropbox/work/bcs/build /Users/ikarino/Dropbox/work/bcs/build/CMakeFiles/blood.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/blood.dir/depend

