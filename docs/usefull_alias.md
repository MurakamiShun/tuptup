# tuple_front
```cpp
namespace tuptup{
  template<typename T>
  using tuple_front_t = typename tuple_element<0, T>::type;

  template<typename T>
  auto tuple_front(T&& t) noexcept; // alias of std::get<0>
}
```

# tuple_back
```cpp
namespace tuptup{
  template<typename T>
  using tuple_back_t = typename tuple_element<tuple_size<T>::value - 1, T>::type;

  template<typename T>
  auto tuple_back(T&& t) noexcept; // alias of std::get<tuple_size<T>::value - 1>
}
```