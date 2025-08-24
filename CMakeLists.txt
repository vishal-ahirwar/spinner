#Auto Generated Root CMake file by Sage
#Copyright(c) 2025 None.All rights reerved.
cmake_minimum_required(VERSION 3.6...3.31)
project(spinner VERSION 0.1.0 LANGUAGES CXX C)
include(config/config.cmake)
#@add_find_package Warning: Do not remove this line
find_package(fmt)

#@add_subproject Warning: Do not remove this line
if(BUILD_EXAMPLE)
add_subdirectory(example)
endif()

add_subdirectory(spinner)
