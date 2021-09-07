# tuptup

tuptup is advanced `std::tuple` library for C++11/14/17.


# Example

```cpp
using tuptup;
static_assert(std::is_same<make_integer_range<int, 1, 4>, integer_sequence <int, 1, 2, 3>>::value, "true");

std::tuple<int, int> i_tup;
static_assert(std::is_same<
    apply_to_types_t<std::make_unsigned, decltype(i_tup)>,
    std::tuple<unsigned int, unsigned int>
>::value, "true");

#if __cplusplus >= 201703L
struct {} base;
struct :decltype(base){ int a,b,c; } some_aggregate;

struct_binder<decltype(some_aggregate)>::variable_num; // 3
struct_binder<decltype(some_aggregate)>::base_class_num; // 1
#endif

```