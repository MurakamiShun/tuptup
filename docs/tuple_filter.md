# tuple_filter
```cpp
namespace tuptup{
  template<typename F, typename T>
  constexpr auto tuple_filter(T&& tup);
}
```

## Overview
This function extracts elements that are `F<element type>::value == true`.

## Example
```cpp
#include <tuptup.hpp>

int main(){
    std::tuple<std::string, int, int> sii{"test", 5, 6};
    
    auto filtered = tuptup::tuple_filter<std::is_integral<tuptup::placeholder_t::_1>>(sii);
    filtered == std::tuple<int, int>{5, 6}; // true
}
```

# tuple_filter_t
```cpp
namespace tuptup{
  template<typename F, typename T>
  using tuple_filter_t = decltype(tuple_filter<F>(declval<T>()));
}
```

## Example
```cpp
template<typename T>
struct is_smaller_than_int16{
    constexpr static bool value = sizeof(T) <= 1;
};
static_assert(std::is_same<
    tuptup::tuple_filter_t<is_over4byte<tuptup::placeholder_t::_1>, std::tuple<int8_t, int16_t, int8_t, int64_t>>,
    std::tuple<int8_t, int16_t, int8_t>
>::value, "true");
```