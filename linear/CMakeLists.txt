add_library(Linear array.hpp dummy.cpp)
find_library(NAMES Utils PATHS ../utils)
target_link_libraries(Linear PUBLIC Utils)