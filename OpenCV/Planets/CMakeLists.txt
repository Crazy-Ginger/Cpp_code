cmake_minimum_required(VERSION 2.8)
project(Planets)
#find_package(OpenCV PATHS /usr/local/include/lib/cmake NO_DEFAULT_PATH)
find_package( OpenCV REQUIRED)
#include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(planets planets.cpp)
target_link_libraries(planets ${OpenCV_LIBS})
