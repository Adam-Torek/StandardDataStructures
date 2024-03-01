#include "../../linear/array.hpp"

using namespace ds::linear;

enum comp_type {LESS_THAN, GREATER_THAN, LESS_THAN_EQUAL, GREATER_THAN_EQUAL, EQUAL, NOT_EQUAL};

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