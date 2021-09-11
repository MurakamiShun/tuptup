# tuple_slice
```cpp
namespace tuptup{
  template<typename IntSeq, typename T>
  constexpr auto tuple_slice(T&& tup) -> std::tuple<std::tuple_element_t</*IntSeq values*/>...>;
}
```
## Example
```cpp
#include <tuptup.hpp>

int main(){
    std::tuple<int8_t, int16_t, int32_t, int64_t> tup = {0,1,2,3};
    const auto sliced_tuple = tuptup::tuple_slice<tuptup::make_integer_range<std::size_t, 1,3>>(tup);
    sliced_tuple == std::tuple<int16_t, int32_t, int64_t>{1,2,3}; // true
}
```

# tuple_slice_t
```cpp
namespace tuptup{
  template<typename IntSeq, typename T>
  using tuple_slice_t = decltype(tuple_slice<IntSeq>(std::declval<T>()));
}
```
## Example
```cpp
static_assert(std::is_same<
    tuptup::tuple_slice_t<tuptup::integer_sequence<std::size_t, 1,3>, std::tuple<int8_t, int16_t, int32_t, int64_t>>,
    std::tuple<int16_t, int64_t>
>::value, "true");
```