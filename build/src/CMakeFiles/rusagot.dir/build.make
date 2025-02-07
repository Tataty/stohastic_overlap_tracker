# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_SOURCE_DIR = /home/rusa/rusagot_genetic_optimizer_tracker

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rusa/rusagot_genetic_optimizer_tracker/build

# Include any dependencies generated for this target.
include src/CMakeFiles/rusagot.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/rusagot.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/rusagot.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/rusagot.dir/flags.make

src/CMakeFiles/rusagot.dir/main.cpp.o: src/CMakeFiles/rusagot.dir/flags.make
src/CMakeFiles/rusagot.dir/main.cpp.o: /home/rusa/rusagot_genetic_optimizer_tracker/src/main.cpp
src/CMakeFiles/rusagot.dir/main.cpp.o: src/CMakeFiles/rusagot.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rusa/rusagot_genetic_optimizer_tracker/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/rusagot.dir/main.cpp.o"
	cd /home/rusa/rusagot_genetic_optimizer_tracker/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/rusagot.dir/main.cpp.o -MF CMakeFiles/rusagot.dir/main.cpp.o.d -o CMakeFiles/rusagot.dir/main.cpp.o -c /home/rusa/rusagot_genetic_optimizer_tracker/src/main.cpp

src/CMakeFiles/rusagot.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rusagot.dir/main.cpp.i"
	cd /home/rusa/rusagot_genetic_optimizer_tracker/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rusa/rusagot_genetic_optimizer_tracker/src/main.cpp > CMakeFiles/rusagot.dir/main.cpp.i

src/CMakeFiles/rusagot.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rusagot.dir/main.cpp.s"
	cd /home/rusa/rusagot_genetic_optimizer_tracker/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rusa/rusagot_genetic_optimizer_tracker/src/main.cpp -o CMakeFiles/rusagot.dir/main.cpp.s

# Object files for target rusagot
rusagot_OBJECTS = \
"CMakeFiles/rusagot.dir/main.cpp.o"

# External object files for target rusagot
rusagot_EXTERNAL_OBJECTS =

src/rusagot: src/CMakeFiles/rusagot.dir/main.cpp.o
src/rusagot: src/CMakeFiles/rusagot.dir/build.make
src/rusagot: /home/rusa/opencv/default_opencv_install/lib/libopencv_gapi.so.4.12.0
src/rusagot: /home/rusa/opencv/default_opencv_install/lib/libopencv_stitching.so.4.12.0
src/rusagot: /home/rusa/opencv/default_opencv_install/lib/libopencv_aruco.so.4.12.0
src/rusagot: /home/rusa/opencv/default_opencv_install/lib/libopencv_bgsegm.so.4.12.0
src/rusagot: /home/rusa/opencv/default_opencv_install/lib/libopencv_bioinspired.so.4.12.0
src/rusagot: /home/rusa/opencv/default_opencv_install/lib/libopencv_ccalib.so.4.12.0
src/rusagot: /home/rusa/opencv/default_opencv_install/lib/libopencv_dnn_objdetect.so.4.12.0
src/rusagot: /home/rusa/opencv/default_opencv_install/lib/libopencv_dnn_superres.so.4.12.0
src/rusagot: /home/rusa/opencv/default_opencv_install/lib/libopencv_dpm.so.4.12.0
src/rusagot: /home/rusa/opencv/default_opencv_install/lib/libopencv_face.so.4.12.0
src/rusagot: /home/rusa/opencv/default_opencv_install/lib/libopencv_freetype.so.4.12.0
src/rusagot: /home/rusa/opencv/default_opencv_install/lib/libopencv_fuzzy.so.4.12.0
src/rusagot: /home/rusa/opencv/default_opencv_install/lib/libopencv_hfs.so.4.12.0
src/rusagot: /home/rusa/opencv/default_opencv_install/lib/libopencv_img_hash.so.4.12.0
src/rusagot: /home/rusa/opencv/default_opencv_install/lib/libopencv_intensity_transform.so.4.12.0
src/rusagot: /home/rusa/opencv/default_opencv_install/lib/libopencv_line_descriptor.so.4.12.0
src/rusagot: /home/rusa/opencv/default_opencv_install/lib/libopencv_mcc.so.4.12.0
src/rusagot: /home/rusa/opencv/default_opencv_install/lib/libopencv_quality.so.4.12.0
src/rusagot: /home/rusa/opencv/default_opencv_install/lib/libopencv_rapid.so.4.12.0
src/rusagot: /home/rusa/opencv/default_opencv_install/lib/libopencv_reg.so.4.12.0
src/rusagot: /home/rusa/opencv/default_opencv_install/lib/libopencv_rgbd.so.4.12.0
src/rusagot: /home/rusa/opencv/default_opencv_install/lib/libopencv_saliency.so.4.12.0
src/rusagot: /home/rusa/opencv/default_opencv_install/lib/libopencv_signal.so.4.12.0
src/rusagot: /home/rusa/opencv/default_opencv_install/lib/libopencv_stereo.so.4.12.0
src/rusagot: /home/rusa/opencv/default_opencv_install/lib/libopencv_structured_light.so.4.12.0
src/rusagot: /home/rusa/opencv/default_opencv_install/lib/libopencv_superres.so.4.12.0
src/rusagot: /home/rusa/opencv/default_opencv_install/lib/libopencv_surface_matching.so.4.12.0
src/rusagot: /home/rusa/opencv/default_opencv_install/lib/libopencv_tracking.so.4.12.0
src/rusagot: /home/rusa/opencv/default_opencv_install/lib/libopencv_videostab.so.4.12.0
src/rusagot: /home/rusa/opencv/default_opencv_install/lib/libopencv_wechat_qrcode.so.4.12.0
src/rusagot: /home/rusa/opencv/default_opencv_install/lib/libopencv_xfeatures2d.so.4.12.0
src/rusagot: /home/rusa/opencv/default_opencv_install/lib/libopencv_xobjdetect.so.4.12.0
src/rusagot: /home/rusa/opencv/default_opencv_install/lib/libopencv_xphoto.so.4.12.0
src/rusagot: /home/rusa/opencv/default_opencv_install/lib/libopencv_shape.so.4.12.0
src/rusagot: /home/rusa/opencv/default_opencv_install/lib/libopencv_highgui.so.4.12.0
src/rusagot: /home/rusa/opencv/default_opencv_install/lib/libopencv_datasets.so.4.12.0
src/rusagot: /home/rusa/opencv/default_opencv_install/lib/libopencv_plot.so.4.12.0
src/rusagot: /home/rusa/opencv/default_opencv_install/lib/libopencv_text.so.4.12.0
src/rusagot: /home/rusa/opencv/default_opencv_install/lib/libopencv_ml.so.4.12.0
src/rusagot: /home/rusa/opencv/default_opencv_install/lib/libopencv_phase_unwrapping.so.4.12.0
src/rusagot: /home/rusa/opencv/default_opencv_install/lib/libopencv_optflow.so.4.12.0
src/rusagot: /home/rusa/opencv/default_opencv_install/lib/libopencv_ximgproc.so.4.12.0
src/rusagot: /home/rusa/opencv/default_opencv_install/lib/libopencv_video.so.4.12.0
src/rusagot: /home/rusa/opencv/default_opencv_install/lib/libopencv_videoio.so.4.12.0
src/rusagot: /home/rusa/opencv/default_opencv_install/lib/libopencv_imgcodecs.so.4.12.0
src/rusagot: /home/rusa/opencv/default_opencv_install/lib/libopencv_objdetect.so.4.12.0
src/rusagot: /home/rusa/opencv/default_opencv_install/lib/libopencv_calib3d.so.4.12.0
src/rusagot: /home/rusa/opencv/default_opencv_install/lib/libopencv_dnn.so.4.12.0
src/rusagot: /home/rusa/opencv/default_opencv_install/lib/libopencv_features2d.so.4.12.0
src/rusagot: /home/rusa/opencv/default_opencv_install/lib/libopencv_flann.so.4.12.0
src/rusagot: /home/rusa/opencv/default_opencv_install/lib/libopencv_photo.so.4.12.0
src/rusagot: /home/rusa/opencv/default_opencv_install/lib/libopencv_imgproc.so.4.12.0
src/rusagot: /home/rusa/opencv/default_opencv_install/lib/libopencv_core.so.4.12.0
src/rusagot: src/CMakeFiles/rusagot.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rusa/rusagot_genetic_optimizer_tracker/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable rusagot"
	cd /home/rusa/rusagot_genetic_optimizer_tracker/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rusagot.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/rusagot.dir/build: src/rusagot
.PHONY : src/CMakeFiles/rusagot.dir/build

src/CMakeFiles/rusagot.dir/clean:
	cd /home/rusa/rusagot_genetic_optimizer_tracker/build/src && $(CMAKE_COMMAND) -P CMakeFiles/rusagot.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/rusagot.dir/clean

src/CMakeFiles/rusagot.dir/depend:
	cd /home/rusa/rusagot_genetic_optimizer_tracker/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rusa/rusagot_genetic_optimizer_tracker /home/rusa/rusagot_genetic_optimizer_tracker/src /home/rusa/rusagot_genetic_optimizer_tracker/build /home/rusa/rusagot_genetic_optimizer_tracker/build/src /home/rusa/rusagot_genetic_optimizer_tracker/build/src/CMakeFiles/rusagot.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/rusagot.dir/depend

