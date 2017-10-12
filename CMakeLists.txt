cmake_minimum_required(VERSION 3.9)
project(martin_cpp)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory("tests")

include_directories("${CMAKE_SOURCE_DIR}")

set(SOURCE_FILES main.cpp formes/base.cpp formes/base.h geometrie/point.cpp geometrie/point.h geometrie/vecteur.cpp geometrie/vecteur.h couleur.h couleur.cpp formes/segment.cpp formes/segment.h formes/cercle.cpp formes/cercle.h formes/triangle.cpp formes/triangle.h formes/polygone.cpp formes/polygone.h transformation/transformation.h)
add_library(martin_cpp ${SOURCE_FILES})