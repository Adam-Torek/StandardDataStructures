cmake_minimum_required(VERSION 3.11)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(StandardDataStructures VERSION 0.1)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)
set(CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR})

set(CMAKE_CXX_COMPILER /usr/bin/g++)
SET(CMAKE_CXX_FLAGS "-fPIC -g -D DEBUG -Wall -Wfatal-errors -fstrict-aliasing")

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_subdirectory(data_structures)
add_executable(Tester Tests/main.cpp)
target_include_directories(Tester PRIVATE ${CMAKE_SOURCE_DIR})
target_link_libraries(Tester PRIVATE DataStructures)

enable_testing()
find_package(GTest REQUIRED)

target_link_libraries(Tester PRIVATE GTest::GTest GTest::Main)

gtest_discover_tests(Tester)
