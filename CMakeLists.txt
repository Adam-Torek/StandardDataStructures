cmake_minimum_required(VERSION 3.9.1)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(StandardDataStructures VERSION 0.1 LANGUAGES CXX)

add_subdirectory(linear)
add_subdirectory(utils)
add_subdirectory(tests)

add_library(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE Utils)
target_link_libraries(${PROJECT_NAME} PUBLIC Linear)

add_executable(UnitTests main.cpp)
target_link_libraries(UnitTests PRIVATE Utils)
target_link_libraries(UnitTests PRIVATE Tests)
target_link_libraries(${PROJECT_NAME} PUBLIC Linear)
target_link_libraries(UnitTests PRIVATE Catch2::Catch2WithMain)


find_package(Catch2 REQUIRED)

include(CTest)
include(ParseAndAddCatchTests)
ParseAndAddCatchTests(UnitTests)
