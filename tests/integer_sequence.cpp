#include <tuptup.hpp>
#include <cassert>
#include <type_traits>

struct square{
    constexpr std::size_t operator()(std::size_t N) const noexcept{
        return N*N;
    }
};

int main(){
    // make integer_sequence
    // even
    assert((std::is_same<
        tuptup::make_integer_sequence<std::size_t, 6>,
        tuptup::integer_sequence<std::size_t, 0,1,2,3,4,5>
    >::value));
    // odd
    assert((std::is_same<
        tuptup::make_integer_sequence<std::size_t, 5>,
        tuptup::integer_sequence<std::size_t, 0,1,2,3,4>
    >::value));
    using big_sequence = tuptup::make_integer_sequence<std::size_t, 10240>;
    
    // make integer range
    assert((std::is_same<
        tuptup::make_integer_range<std::size_t, 5, 10>,
        tuptup::integer_sequence<std::size_t, 5,6,7,8,9>
    >::value));

    // apply function to integer_sequence
    tuptup::integer_sequence<std::size_t, 5,6,9> int_seq_569;
    assert((std::is_same<
        tuptup::integer_sequence_for_each<square, decltype(int_seq_569)>,
        tuptup::integer_sequence<std::size_t, 25,36,81>
    >::value));

    // push back
    assert((std::is_same<
        tuptup::integer_sequence_push_back<decltype(int_seq_569), 4>,
        tuptup::integer_sequence<std::size_t, 5,6,9,4>
    >::value));
    // push front
    assert((std::is_same<
        tuptup::integer_sequence_push_front<decltype(int_seq_569), 4>,
        tuptup::integer_sequence<std::size_t, 4,5,6,9>
    >::value));
}