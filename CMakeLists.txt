cmake_minimum_required(VERSION 2.8)

project(VexCL_NN)

find_package(VexCL REQUIRED COMPONENTS Common OpenCL)

add_definitions(
  -g
)

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/bin)

link_libraries(VexCL::OpenCL)

add_executable(main main.cpp)
set_property(TARGET main PROPERTY CXX_STANDARD 14)
