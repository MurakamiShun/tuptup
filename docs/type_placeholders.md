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

## defer tramsformation traits
```cpp
namespace tuptup::type_placeholders{
    template<typename T, typename enabler = typename std::enable_if<is_transformation_trait<T>::value>::type>
    struct defer;
}
```
Make transformation traits to deferred evaluation.
(`std::add_const_t<_1>` becomes `const placeholder_t<1>`. So use `defer<std::add_const<_1>>` instead of type aliases.)

## replace placehoders
```cpp
namespace tuptup::type_placeholders{
    template<typename Binded, typename... Args>
    using replace = /* replace placeholder_t in Binded to Args */;
}
```

## count placeholders
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

    using remove_cv_ref = std::remove_cv<defer<std::remove_reference<_1>>>;
    
    replaced::type i = 0; // int
    count<std::tuple<_1, _2, _3>>::value; // 3
}
```