# apply_each

```cpp
template<typename F, typename T>
constexpr auto apply_each(F&& f, T&& tuple); // (1)

template<typename F, typename T>
constexpr void apply_each(F&& f, T&& tuple); // (2)
```

# Overview
Apply given function to each element.
- (1) `apply_each` returns `std::tuple<std::invoke_result_t<F, TupleElements>...>`.
- (2) When given function returns `void`.

## Example
```cpp
#include <iostream>
#include <tuptup.hpp>

int main(){
    std::tuple<std::string, int, int> sii{"test", 5, 6};
    
    struct {
        void operator()(const std::string& str){
            std::cout << "string:" << str << std::endl;
        }
        void operator()(const int i){
            std::cout << "int:" << i << std::endl;
        }
    } functor;

    tuptup::apply_each(functor, sii);
}
```