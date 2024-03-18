#define CATCH_CONFIG_MAIN
#include <data_structures/linear/array>
#include <catch2/catch_test_macros.hpp>
#include <iostream>

TEST_CASE("Test Empty Array", "[dummy]") {
    ds::linear::array<int, 0> arr;
    REQUIRE(arr.size() == 0);
}
