cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(csapp)
include_directories(${PROJECT_SOURCE_DIR}/include)

add_library(Mylib src/show_byte.cc)
add_executable(exe main.cc)

target_link_libraries(exe Mylib)
