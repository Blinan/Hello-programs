cmake_minimum_required(VERSION 3.12)

project(Game VERSION 1.0)

include_directories(/home/tammy/ins/raygui-4.0/src/)

include_directories(${PROJECT_SOURCE_DIR}/ins)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(EXECUTABLE_OUTPUT_PATH  "${PROJECT_SOURCE_DIR}/bin")

add_executable(exe main.cpp)
#add_executable(exe examples/test.cpp)    #for test
#add_executable(client client/client.cpp)
#add_executable(server server/server.cpp)

#add_executable(test music.cpp)

target_link_libraries(exe libraylib.so)
#add_subdirectory(server)
#add_subdirectory(client)

