# struct_as_tuple
```cpp
namespace tuptup{
  template<typename T>
  struct struct_as_tuple { // T must be aggregator
    static constexpr std::size_t base_class_num = /*the number of base class count*/;
    
    static constexpr std::size_t variable_num = /*the number of member variable count of T*/;
    
    using type = std::tuple</*references to struct varible...*/>;
  };
  template<typename T>
  constexpr auto tie_as_tuple(T&& t) noexcept; // make tuple of struct varible references

  template<typename T>
  constexpr auto make_as_tuple(T&& t); // copy or move of struct varible as tuple
}
```

## Overview
`struct_as_tuple` is written by C++17.
The given structure must be an aggregator and not have primitive arrays (like `int[4]`).

## Example
```cpp
#include <iostream>
#include <string>
#include <tuptup.hpp>

struct Base{};

struct Test : public Base{
    int a,b,c;
    std::string str;
};

int main(){
    tuptup::struct_binder<Test>::base_class_num == 1; // true
    tuptup::struct_binder<Test>::varible_num == 4; // true

    Test t = {0,1,2, "test"};
    std::tuple<int&, int&, int&, std::string&> ref_tuple = tuptup::tie_as_tuple(t);
    std::get<3>(ref_tuple) = "ffffff"; // t.str will change

    std::tuple<int, int, int, std::string> copy_tuple = tuptup::make_as_tuple(t);
}
```