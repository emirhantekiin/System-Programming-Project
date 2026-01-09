cmake_minimum_required(VERSION 3.10)
project(sis_app)

set(CMAKE_CXX_STANDARD 11)

add_executable(sis_app src/main.cpp)
target_link_libraries(sis_app pqxx pq)
