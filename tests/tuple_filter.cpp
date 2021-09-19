#include <cassert>
#include <tuptup.hpp>
#include <string>
#include <cstdint>

template<typename T>
struct is_over2byte{
    constexpr static bool value = sizeof(T) >= 2;
};

int main(){
    using namespace tuptup::placeholder_t;
    std::tuple<std::string, int, int> sii{"test", 5, 6};
    
    auto filtered = tuptup::tuple_filter<std::is_integral<_1>>(sii);
    assert((filtered == std::tuple<int, int>{5, 6}));

    assert((std::is_same<
        tuptup::tuple_filter_t<is_over2byte<_1>, std::tuple<int8_t, int16_t, int8_t, int64_t>>,
        std::tuple<int16_t, int64_t>
    >::value));
}