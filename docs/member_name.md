# member_name
```cpp
namespace tuptup{
  template <std::size_t N, typename T>
  constexpr auto get_name(); // return Nth member variable name of T
}
```

## Overview
`member_name` is written by C++20.

## Example
```cpp
#include <iostream>
#include <string>
#include <tuptup.hpp>

struct Base{};

struct Test : public Base{
    int a1,b_56
    float ccc;
    std::string str;
};

int main(){
    tuptup::get_name<0, Test>() == "a1"sv;
    tuptup::get_name<1, Test>() == "b_56"sv;
    tuptup::get_name<2, Test>() == "ccc"sv;
    tuptup::get_name<3, Test>() == "str"sv;
}
```