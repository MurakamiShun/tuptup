# make_integer_range
```cpp
namespace tuptup{
  template<typename Int, Int First, Int Last>
  using make_integer_range = integer_sequence<Int, First, First + 1, ..., Last - 1>;
}
```

## Overview
if `Last` is smaller than `First`, this is difinition of `integer_sequence<Int>`

## Example
```cpp
static_assert(std::is_same<
    tuptup::make_integer_range<std::size_t, 5, 10>,
    tuptup::integer_sequence<std::size_t, 5,6,7,8,9>
>::value, "true");

static_assert(tuptup::make_integer_range<int, -1, 10>::size() == 11, "true");
static_assert(tuptup::make_integer_range<int, 1, -10>::size() == 0, "true");
```