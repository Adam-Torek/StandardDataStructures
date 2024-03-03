cmake_minimum_required(VERSION 3.9.1)
set(CMAKE_CXX_STANDARD 14)
project(StandardDataStructures VERSION 0.1)
add_subdirectory(linear)
add_subdirectory(utils)
add_executable(${PROJECT_NAME} main.cpp)

include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip 
)

FetchContent_MakeAvailable(googletest)
target_link_libraries(StandardDataStructures PUBLIC Linear)
target_link_libraries(StandardDataStructures PUBLIC Utils)