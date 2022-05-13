cmake_minimum_required(VERSION 3.5)

project(project LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set leak detectation when using clang compiler
message("The compiler is ${CMAKE_CXX_COMPILER_ID}")
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang" AND CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_CXX_FLAGS "-fsanitize=leak")
endif()

add_executable(${PROJECT_NAME}
    main.cpp
)
