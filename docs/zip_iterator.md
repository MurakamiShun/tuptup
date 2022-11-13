# zip_iterator

```cpp
namespace tuptup{
  template<typename IterTuple>
  struct zip_iterator; // (1)

  template<typename... Iterators>
  zip_iterator<tuple<Iterators...>> make_zip_iterator(Iterators&&...); // (2)
}
```

## Overview
Pack some iterators to apply container algorithms.
`zip_iterator` allows the SoA to be treated like an AoS.
- (1) a ramdom_access_iterator.
- (2) Make a `zip_iterator<std::tuple<Iterators...>>` from given iterators.

## Example
```cpp
#include <vector>
#include <algorithm>
#include <tuptup.hpp>

int main(){
    std::vector<int> v = {1,2,4,8,16};
    std::vector<std::size_t> key = {2,1,5,4,3};
    std::sort(
        tuptup::make_zip_iterator(v.begin(), key.begin()),
        tuptup::make_zip_iterator(v.end(), key.end()),
        [](const auto& a, const auto& b){
            return std::get<1>(a) < std::get<1>(b);
        }
    );
    // v = {2,1,16,8,4}
    // key = {1,2,3,4,5}
}
```