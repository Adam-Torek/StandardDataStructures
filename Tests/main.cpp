#include <data_structures/linear/array>
#include <gtest/gtest.h>
#include <iostream>

template<unsigned int SIZE>
static void run_iter_tests(ds::linear::static_array<int, SIZE> arr, std::array<int, SIZE> other) {
    EXPECT_TRUE(ds::utils::equal(arr.begin(), arr.end(), other.begin()));
    EXPECT_TRUE(ds::utils::equal(arr.cbegin(), arr.cend(), other.cbegin()));
    EXPECT_TRUE(ds::utils::equal(arr.rbegin(), arr.rend(), other.rbegin()));
    EXPECT_TRUE(ds::utils::equal(arr.crbegin(), arr.crend(), other.crbegin()));
}

static void run_empty_array_tests(ds::linear::static_array<int, 0> arr) {
    EXPECT_EQ(arr.size(), 0);
    EXPECT_EQ(arr.max_size(), 0);
    EXPECT_EQ(arr.empty(), true);
    EXPECT_NE(arr.front(), 0);
    EXPECT_NE(arr.back(), 0);
    EXPECT_EQ(arr.front(), arr.back());
    EXPECT_NE(arr.at(0), 0);
    EXPECT_NE(arr[0], 0);
    EXPECT_NE(*arr.data(), 0);

    EXPECT_EQ(arr.begin(), arr.end());
    EXPECT_EQ(arr.cbegin(), arr.cend());
    EXPECT_NE(arr.rbegin(), arr.rend());
    EXPECT_NE(arr.crbegin(), arr.crend());

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

TEST(TestArray, TestEmptyArrayInitializedAnotherArray) {
    ds::linear::static_array<int, 0> empty_arr;
    ds::linear::static_array<int, 0> empty_arr2 = empty_arr;
    run_empty_array_tests(empty_arr2);
}

template<unsigned int SIZE>
static void run_n_element_tests(ds::linear::static_array<int, SIZE> arr, std::array<int, SIZE> other) {
    EXPECT_EQ(arr.size(), SIZE);
    EXPECT_EQ(arr.max_size(), SIZE);
    EXPECT_EQ(arr.front(), other.front());
    EXPECT_EQ(arr.back(), other.back());
    int* arr_data = arr.data();
    int* other_data = other.data();
    typename std::array<int, SIZE>::iterator other_iter = other.begin();
    ds::linear::array_iterator<int> arr_iter = arr.begin();
    for(unsigned int i = 0; i < SIZE; i++) {
        EXPECT_EQ(other_iter[i], arr_iter[i]);
        EXPECT_EQ(arr.at(i), other.at(i));
        EXPECT_EQ(arr[i], other[i]);
        EXPECT_EQ(arr_data[i], other_data[i]);
    }

    run_iter_tests<SIZE>(arr, other);
}

TEST(TestArray, TestOneElementListInitialized) {
    ds::linear::static_array<int, 1> arr = {1};
    std::array<int, 1> other = {1};
    run_n_element_tests<1>(arr, other);
}

TEST(TestArray, TestTwoElementListInitialized) {
    ds::linear::static_array<int, 2> arr = {1, 2};
    std::array<int, 2> other = {1, 2};
    run_n_element_tests<2>(arr, other);
}

TEST(TestArray, TestThreeElementListInitialized) {
    ds::linear::static_array<int, 3> arr = {1, 2, 3};
    std::array<int, 3> other = {1, 2, 3};
    run_n_element_tests<3>(arr, other);
}


TEST(TestArray, TestTenElementListInitialized) {
    ds::linear::static_array<int, 10> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::array<int, 10> other =  {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    run_n_element_tests<10>(arr, other);
}

