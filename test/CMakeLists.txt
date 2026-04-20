cmake_minimum_required(VERSION 3.20)

project(test VERSION 1.0)

include_directories(${PROJECT_SOURCE_DIR}/ins)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



add_library(Mylib src/min_cost_climbing_stairs_dp.cpp
    )

add_executable(exe main.cc)

target_link_libraries(exe Mylib)