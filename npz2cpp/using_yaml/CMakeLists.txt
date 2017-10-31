
cmake_minimum_required(VERSION 2.8)
 
PROJECT(npz2cpp_yaml)
 
set (CMAKE_CXX_FLAGS "-std=gnu++11 ${CMAKE_CXX_FLAGS}")

find_package(YAML-CPP)

include_directories(${YAML_CPP_INCLUDE_DIR})

set(SRC_FILES main.cpp)

add_executable(npz2cpp_yaml ${SRC_FILES})
target_link_libraries(npz2cpp_yaml ${YAML_CPP_LIBRARIES})
