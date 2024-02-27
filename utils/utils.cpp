#include "utils.hpp"

namespace ds::utils {
    template<class It1, class It2>
    constexpr bool elementwise_compare(It1 start_l, It1 end_l, It2 start_r, It2 end_r) {
        for(;(start_l != end_l) && (start_r != end_r); ++start_l, (void) ++start_r) {
            if(*start_l < *start_r) {
                return true;
            }
            if(*start_r < *start_l) {
                return false;
            }
        }

        return (start_l == end_l) && (start_r != end_r);
    }

    template<class It1, class It2>
    constexpr bool equal(It1 start_l, It1 end_l, It2 start_r) {
        for(; start_l != end_l; start_l++, start_r++) {
            if(*start_l != *start_r) {
                return false;
            }
        }
        return true;
    }
}