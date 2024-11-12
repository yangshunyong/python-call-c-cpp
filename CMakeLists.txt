include(CMakePrintHelpers)

cmake_minimum_required(VERSION 3.22)
project(python_call_c)


set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(TOP_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(C_LIB_DIR ${TOP_DIR}/c_library)
set(C_LIB_FILES ${C_LIB_DIR}/multiply.c
                ${C_LIB_DIR}/to_upper.c
   )

message("FILES: ${C_LIB_FILES}")

add_library(libs SHARED ${C_LIB_FILES})
add_executable(c_main ${TOP_DIR}/main.c)
target_include_directories(c_main PUBLIC ${C_LIB_DIR}/include)


target_link_libraries(c_main PRIVATE libs)

add_custom_command(TARGET c_main POST_BUILD
    COMMAND cp ${TOP_DIR}/main.py ${CMAKE_BINARY_DIR}
    COMMAND python main.py
    COMMAND ./c_main
)
