# CMakeList.txt : CMake project for DynamicArray, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("DynamicArray")

include_directories(.)

add_subdirectory(lib)

add_subdirectory(test)

