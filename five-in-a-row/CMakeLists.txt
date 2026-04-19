cmake_minimum_required(VERSION 3.10)

project(five-in-a-row VERSION 1.0)

# 设置 C++ 标准为 C++11
set(CMAKE_CXX_STANDARD 11)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(exe main.cpp)