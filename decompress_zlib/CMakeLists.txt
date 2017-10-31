cmake_minimum_required(VERSION 2.8)
 
PROJECT(zlib_decompression)
 
set(CMAKE_CXX_FLAGS "-std=gnu++11 ${CMAKE_CXX_FLAGS}")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

find_package(Boost REQUIRED COMPONENTS system iostreams serialization)

include_directories(${Boost_INCLUDE_DIRS})

# Get all source *.cpp files recursively
set(SRC_FILES main.cpp)

add_executable(zlib_decompression ${SRC_FILES})
target_link_libraries(zlib_decompression ${Boost_LIBRARIES})

