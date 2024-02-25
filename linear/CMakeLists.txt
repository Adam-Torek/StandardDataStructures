add_library(Linear array.hpp dummy.cpp)
target_link_directories(Linear PUBLIC ../utils)
target_link_libraries(Linear PUBLIC Utils)