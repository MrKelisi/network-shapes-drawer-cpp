cmake_minimum_required(VERSION 3.9)
project(martin_cpp_tests)

set(CMAKE_CXX_STANDARD 11)

include_directories("${CMAKE_SOURCE_DIR}")
include_directories("catch")

set(SOURCE_FILES
        main.cpp
        geometrie/point.cpp
        geometrie/vecteur.cpp
        formes.cpp formes/triangle.cpp)
add_executable(martin_cpp_tests ${SOURCE_FILES})
target_link_libraries(martin_cpp_tests martin_cpp)