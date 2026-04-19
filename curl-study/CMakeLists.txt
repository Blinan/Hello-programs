cmake_minimum_required(VERSION 3.20)

project(cURL VERSION 1.0)

add_executable(exe example.cpp)

target_link_libraries(exe curl)