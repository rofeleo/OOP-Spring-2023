# CMakeList.txt : CMake project for RationalNumbers, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("RationalNumbers")

# Add source to this project's executable.
add_executable (RationalNumbers "main.cpp")

include_directories(.)

add_subdirectory(test)

add_subdirectory(lib)

set_property(TARGET RationalNumbers PROPERTY CXX_STANDARD 20)

find_package(doctest CONFIG REQUIRED)
target_link_libraries(test doctest::doctest)

