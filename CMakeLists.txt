cmake_minimum_required(VERSION 3.15)
project(meadowlark)

find_package(pybind11 REQUIRED)
find_package(Python REQUIRED COMPONENTS Interpreter Development)

include_directories(${CMAKE_SOURCE_DIR}/../Cottontail)
link_directories(${CMAKE_SOURCE_DIR}/../Cottontail/bazel-bin/src)

pybind11_add_module(_meadowlark meadowlark/bindings.cpp)
target_link_libraries(_meadowlark PRIVATE cottontail)

set_target_properties(_meadowlark PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/meadowlark
)
