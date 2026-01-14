cmake_minimum_required(VERSION 3.10)

# Project metadata
project(sis_app
    VERSION 1.0
    DESCRIPTION "Student Information System (C++ + PostgreSQL + Docker)"
    LANGUAGES CXX
)

# C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Output directory (optional - düzenli olsun diye)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# Executable
add_executable(sis_app
    src/main.cpp
)

# Warnings (optional)
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(sis_app PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Include dirs (genelde gerekmez ama şık dursun)
target_include_directories(sis_app PRIVATE ${CMAKE_SOURCE_DIR}/src)

# PostgreSQL libraries
# Dockerfile'da libpqxx-dev kurulu olduğu için bu linkleme yeterli
target_link_libraries(sis_app PRIVATE pqxx pq)

# Optional: print a config summary
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "C++ standard: ${CMAKE_CXX_STANDARD}")
