#include <data_structures/linear/array>
#include <gtest/gtest.h>
#include <iostream>


static void run_empty_array_tests(ds::linear::static_array<int, 0> arr) {
    EXPECT_EQ(arr.size(), 0);
    EXPECT_EQ(arr.max_size(), 0);
    EXPECT_EQ(arr.empty(), true);
    EXPECT_NE(arr.front(), 0);
    EXPECT_NE(arr.back(), 0);
    EXPECT_EQ(arr.front(), arr.back());
    //EXPECT_NE(*arr.data(), 0);

    EXPECT_EQ(arr.begin(), arr.end());
    EXPECT_EQ(arr.cbegin(), arr.cend());
    EXPECT_NE(arr.rbegin(), arr.rend());
    EXPECT_NE(arr.rcbegin(), arr.rcend());

    ds::linear::static_array<int, 0> arr2;
    EXPECT_EQ((arr == arr2), true);
}

TEST(TestArray, TestEmptyArray) {
    ds::linear::static_array<int, 0> empty_arr;
    run_empty_array_tests(empty_arr);
}

TEST(TestArray, TestEmptyArrayInitialized) {
    ds::linear::static_array<int, 0> empty_arr = {};
    run_empty_array_tests(empty_arr);
}
