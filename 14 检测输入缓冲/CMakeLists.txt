cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(recipt LANGUAGES CXX)

# 默认构建DEBUG版本的代码
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -march=native -O3 -pthread" )
add_executable(service service.cpp)
add_executable(client client.cpp)
add_executable(a.out main.cpp)