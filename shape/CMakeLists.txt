cmake_minimum_required(VERSION 2.8)
project(shape)

find_package( OpenCV REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable( shape_example shape_example.cpp )

target_link_libraries( shape_example ${OpenCV_LIBS} ) 
