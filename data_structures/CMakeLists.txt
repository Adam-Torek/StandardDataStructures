add_subdirectory(linear)
add_subdirectory(utils)

add_library(DataStructures dummy.cpp)
target_include_directories(DataStructures PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(DataStructures PUBLIC Linear)
target_link_libraries(DataStructures PUBLIC Utils)
