# integer_sequence

```cpp
namespace tuptup{
  template<typename Int, Int... I>
  struct integer_sequence; // C++11

  template<typename Int, Int... I>
  using integer_sequence = std::integer_sequence<Int, I...>; // C++14
}
```

## Overview
`tuptup::integer_sequence` is compatible with `std::integer_sequence`.
`tuptup::integer_sequence` is written by C++11.

## Generator alias

- `make_integer_sequence` (Compatible with `std::make_integer_sequence`)
- [`make_integer_range`](integer_sequence/make_integer_range.md)
- [`integer_sequence_push_back`](integer_sequence/integer_sequence_push.md)
- [`integer_sequence_push_front`](integer_sequence/integer_sequence_push.md)
- [`integer_sequence_for_each`](integer_sequence/integer_sequence_for_each.md)