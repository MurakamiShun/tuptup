#include <cassert>
#include <string>
#include <tuptup.hpp>
#include <cstdint>

int main(){
    std::tuple<std::string, int, int> sii{"test", 5, 6};
    
    auto sliced = tuptup::tuple_slice<tuptup::integer_sequence<std::size_t, 0,2>>(sii);
    assert((sliced == std::tuple<std::string, int>{"test", 6}));

    assert((std::is_same<
        tuptup::tuple_slice_t<tuptup::integer_sequence<std::size_t, 0,2>,std::tuple<int8_t, int16_t, int8_t, int64_t>>,
        std::tuple<int8_t, int8_t>
    >::value));
}