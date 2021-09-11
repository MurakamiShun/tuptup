# integer_sequence_for_each
```cpp
namespace tuptup{
  template<typename F, typename IntSeq>
  using integer_sequence_for_each = integer_sequence<IntSeq::value_type, /*apply F to template value of IntSeq*/>
}
```

## Example
```cpp
template<typename Int>
struct mul2 {
    constexpr Int operator()(Int i) noexcept { return i * 2; }
}

template<typename Int, Int N>
using make_even_sequence = tuptup::integer_sequence_for_each<mul2<Int>, tuptup::make_integer_sequence<Int, (N+1)/2>>;

static_assert(std::is_same<
    make_even_sequence<std::size_t 10>,
    tuptup::integer_sequence<std::size_t, 0,2,4,6,8>
>::value, "true");
```