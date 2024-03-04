add_subdirectory(linear_tests)

add_library(Tests tests.cpp)
target_link_libraries(Tests PUBLIC LinearTests)
