cmake_minimum_required(VERSION 2.8)
project(cameraShiftDemo)

find_package( OpenCV REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable( cameraShiftDemo camera_shift_demo.cpp )

target_link_libraries( cameraShiftDemo ${OpenCV_LIBS} ) 
