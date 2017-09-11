cmake_minimum_required(VERSION 2.8)

project(VexCL_NN)

find_package(VexCL REQUIRED COMPONENTS Common OpenCL)

add_definitions(
  -g
)

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/bin)


add_library(nn SHARED nn-impl.cpp)
target_link_libraries(nn VexCL::OpenCL)
set_property(TARGET nn PROPERTY CXX_STANDARD 14)


add_executable(main main.cpp)
target_link_libraries(main nn)
set_property(TARGET main PROPERTY CXX_STANDARD 14)
