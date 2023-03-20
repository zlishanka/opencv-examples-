cmake_minimum_required(VERSION 2.8)
project(contour )

find_package( OpenCV REQUIRED )

set(CMAKE_C_FLAGS, "-g")
set(CMAKE_BUILD_TYPE Debug)

include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable( drawContour draw_contour.cpp )

target_link_libraries( drawContour ${OpenCV_LIBS} ) 
