include(CMakePrintHelpers)

cmake_minimum_required(VERSION 3.0)
project(pybind11-call)

set(TOP_DIR ${CMAKE_CURRENT_SOURCE_DIR})


message("TOP_DIR: ${TOP_DIR}")

add_subdirectory(../pybind11-lib lib-build)
pybind11_add_module(mycalc calc.cpp)

add_custom_command(
    TARGET mycalc POST_BUILD
    COMMAND cp ${TOP_DIR}/main.py ${CMAKE_BINARY_DIR}
    COMMAND python main.py
)
