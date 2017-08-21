cmake_minimum_required(VERSION 2.8)

project(VexCL_NN)

#find_package(OpenCL REQUIRED)
#find_package(Boost REQUIRED COMPONENTS System filesystem )
find_package(VexCL REQUIRED COMPONENTS Common OpenCL)

add_definitions(
  -g
)

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/bin)

#include_directories(${VexCL_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS} ${OpenCL_INCLUDE_DIR})
#link_libraries(${VexCL_LIBRARIES} ${Boost_LIBRARIES} ${OpenCL_LIBRARIES})

link_libraries(VexCL::OpenCL)

add_executable(main main.cpp)
set_property(TARGET main PROPERTY CXX_STANDARD 14)
