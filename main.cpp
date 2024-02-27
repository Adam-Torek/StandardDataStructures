#include <iostream>
#include <stdexcept>
#include "linear/array.hpp"

using namespace ds::linear;


int main() {
        array<int, 5> arr = {1,2,3,4,5};
        int i = 0;
        for(array<int, 5>::const_iterator start = arr.cbegin(); start != arr.cend(); start++) {
                std::cout << "Value at position " << i << " is " << *start << " \n";
                i++;
        }
        return 0;
}