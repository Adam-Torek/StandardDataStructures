#include "../../linear/array.hpp"
#include <iostream>

using namespace ds::linear;

typedef struct test_stats {
    public:
        unsigned int tests_passed;
        unsigned int tests_failed;
        unsigned int total_tests;
} test_stats;

enum comp_type {LESS_THAN, GREATER_THAN, LESS_THAN_EQUAL, GREATER_THAN_EQUAL, EQUAL, NOT_EQUAL};

test_stats stats;


void run_test(bool *test_func(void), std::string test_name) {
    bool result = test_func();
    std::cout << test_name << ": " << (result ? "PASS" : "FAIL") << "\n";
    if(result) {
        stats.tests_passed++;
    } else {
        stats.tests_failed++;
    }
    stats.total_tests++;
}


template<typename T, unsigned int SIZE> 
void array_compare(array<T, SIZE>& one, array<T, SIZE>& two, comp_type comp)
{
    switch(comp) {
        case LESS_THAN:
            static_assert(one < two, "FAIL: one is not less than two");
            break;
        case GREATER_THAN:
            static_assert(one > two, "FAIL: one is not greater than two");
            break;
        case GREATER_THAN_EQUAL:
            static_assert(one >= two, "FAIL: one is not greater than or equal to two");
            break;
        case LESS_THAN_EQUAL:
            static_assert(one >= two, "FAIL: one is not less than or equal to two");
            break;
        case EQUAL:
            static_assert(one == two, "FAIL: one is not equal to two");
            break;
        case NOT_EQUAL:
            static_assert(one != two, "FAIL: one is not equal to two");
            break;
    }
}

int main() {
    return 0;
}