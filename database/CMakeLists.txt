cmake_minimum_required(VERSION 3.20)

project(MySQLDemo VERSION 1.0)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(mysql-concpp_DIR /usr/local/mysql/connector-c++-9.6.0)
find_package(mysql-concpp REQUIRED )

add_executable(MySQLDemoe connector-cpp.cpp)

target_link_libraries(MySQLDemoe mysql::concpp)

