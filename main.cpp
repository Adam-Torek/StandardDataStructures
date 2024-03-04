#include <iostream>
#include <stdexcept>
#include <catch2/catch_test_macros.hpp>
#include "tests/linear_tests/array_tests.cpp"

TEST_CASE("This is a simple test","[SimpleTest]") {
    REQUIRE(2 == 2);
}