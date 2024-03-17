cmake_minimum_required(VERSION 3.11)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(StandardDataStructures VERSION 0.1)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)
set(CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR})

set(CMAKE_CXX_COMPILER g++)
SET(CMAKE_CXX_FLAGS "-fPIC -g -D DEBUG -Wall -Wfatal-errors -fstrict-aliasing")

MESSAGE("${CMAKE_SOURCE_DIR}/data_structures")

add_subdirectory(data_structures)
add_executable(Tester Tests/main.cpp)
target_include_directories(Tester PUBLIC ${CMAKE_SOURCE_DIR})
target_link_libraries(Tester PUBLIC DataStructures)
target_link_libraries(Tester PRIVATE Catch2::Catch2WithMain)

find_package(Catch2 REQUIRED)

include(CTest)
include(ParseAndAddCatchTests)
