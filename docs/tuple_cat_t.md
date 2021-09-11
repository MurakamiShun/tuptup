# tuple_cat_t
```cpp
namespace tuptup{
  template<typename... Tuples>
  using tuple_cat_t = decltype(std::tuple_cat(std::declval<Tuples>()...));
}
```

## Example
```cpp
static_assert(std::is_same<
    tuptup::tuple_cat_t<std::tuple<int, char&>, std::tuple<int>>,
    std::tuple<int, char&, int>
>::value, "true");
```