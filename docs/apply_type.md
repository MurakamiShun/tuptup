# apply_type
```cpp
namespace tuptup{
  template<template<typename>class F, typename T>
  struct apply_type;
  template<template<typename>class F, template<typename...>class TupleType, typename... Elms>
  struct apply_type<F, TupleType<Elms...>>{
      using type = TupleType<typename F<Elms>::type...>;
  };

  template<template<typename>class F, typename T>
  using apply_type_t = typename apply_type<F, T>::type;
}
```


## Overview
Make tuple with `F<tuple element type>::type`.

## Example
```cpp
static_assert(std::is_same<
    tuptup::apply_type_t<std::remove_reference, std::tuple<int, char&>>,
    std::tuple<int, char>
>::value, "true");
```