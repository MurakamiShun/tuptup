# apply_each

```cpp
namespace tuptup{
  template<typename F, typename T>
  constexpr auto indexed_apply_each(F&& f, T&& tuple); // (1)

  template<typename F, typename T>
  constexpr std::tuple<> indexed_apply_each(F&& f, T&& tuple); // (2)
}
```

## Overview
Apply given function and index to each element.
- (1) `apply_each` returns `std::tuple<std::invoke_result_t<F, TupleElements>...>`.
- (2) When given function returns `void`.

## Example
```cpp
#include <iostream>
#include <tuptup.hpp>

struct Func{
    template<std::size_t N>
    void operator()(const std::string& str){
        std::cout << N << "-string:" << str << std::endl;
    }
    void operator()(const int i){
        std::cout << N << "-int:" << i << std::endl;
    }
};

int main(){
    std::tuple<std::string, int, int> sii{"test", 5, 6};
    
    Func functor;

    tuptup::indexed_apply_each(functor, sii);
}
```