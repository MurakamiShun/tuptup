# type_placeholders
```cpp
namespace tuptup::type_placeholders{
    template<std::size_t N> placeholder_t<N>;

    using _1 = placeholder_t<1>;
    using _2 = placeholder_t<2>;
    using _3 = placeholder_t<3>;
    ...
}
```

# replace placehoders
```cpp
namespace tuptup::type_placeholders{
    template<typename Binded, typename... Args>
    using replace = /* replace placeholder_t in Binded to Args */;
}
```

# count placeholders
```cpp
namespace tuptup::type_placeholders{
    template<typename Binded> struct count{
        static constexpr std::size_t value = /* amount of placeholder_t in Binded */;
    };
}
```

# Example

```cpp
#include <tuptup>
#include <tuple>

int main(){
    using namespace tuptup::type_placeholders;
    using binded = std::decay<_1>;
    
    using replaced = replace<binded, int&>; // decay<int&>
    
    replaced::type i = 0; // int
    count<std::tuple<_1, _2, _3>>::value; // 3
}
```