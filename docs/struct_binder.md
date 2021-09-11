# struct_binder
```cpp
namespace tuptup{
  template<typename T>
  struct struct_binder { // T must be aggregator
    static constexpr std::size_t base_class_num = /*the number of base class count*/;
    static constexpr std::size_t variable_num = /*the number of member variable count of T*/;
    using type = std::tuple</*reference to struct varible...*/>;
  };
}
```

## Overview
`struct_binder` is written by C++17.
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
    tuptup::struct_binder<Test> binder;
    binder.base_class_num == 1; // true
    binder.varible_num == 4; // true

    Test t = {0,1,2, "test"};
    std::tuple<int&, int&, int&, std::string&> ref_tuple = binder(t);
    std::get<3>(ref_tuple) = "changed";

    std::cout << t.str << std::endl; // changed
}
```