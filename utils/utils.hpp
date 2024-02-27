
namespace ds::utils {

    template<class It1, class It2>
    constexpr bool elementwise_compare(It1 start_l, It1 end_l, It2 start_r, It2 end_r);

    template<class It1, class It2>
    constexpr bool equal(It1 start_l, It1 end_l, It2 start_r);
}
