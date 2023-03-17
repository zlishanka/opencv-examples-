cmake_minimum_required(VERSION 2.8)
project(CamCapture )

find_package( OpenCV REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable( camTest videoCapture.cpp )

target_link_libraries( camTest ${OpenCV_LIBS} ) 
