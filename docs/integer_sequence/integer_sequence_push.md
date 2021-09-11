# integer_sequence_push_back
```cpp
namespace tuptup{
  template<typename IntSeq, typename IntSeq::value_type Last>
  using integer_sequence_push_back = integer_sequence<IntSeq::value_type, /*template values of IntSeq*/, Last>
}
```

## Example
```cpp
static_assert(std::is_same<
    tuptup::integer_sequence_push_back<tuptup::integer_sequence<int, 4,5,6>, 10>,
    tuptup::integer_sequence<std::size_t, 4,5,6,10>
>::value, "true");
```

# integer_sequence_push_front
```cpp
namespace tuptup{
  template<typename IntSeq, typename IntSeq::value_type First>
  using integer_sequence_push_front = integer_sequence<IntSeq::value_type, First, /*template values of IntSeq*/>
}
```
## Example
```cpp
static_assert(std::is_same<
    tuptup::integer_sequence_push_front<tuptup::integer_sequence<int, 4,5,6>, 10>,
    tuptup::integer_sequence<std::size_t, 10,4,5,6>
>::value, "true");
```