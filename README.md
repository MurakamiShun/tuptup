# tuptup [![gcc](https://github.com/MurakamiShun/tuptup/actions/workflows/gcc-test.yml/badge.svg)](https://github.com/MurakamiShun/tuptup/actions/workflows/gcc-test.yml) [![clang](https://github.com/MurakamiShun/tuptup/actions/workflows/clang-test.yml/badge.svg)](https://github.com/MurakamiShun/tuptup/actions/workflows/clang-test.yml) [![MSVC](https://github.com/MurakamiShun/tuptup/actions/workflows/msvc-test.yml/badge.svg)](https://github.com/MurakamiShun/tuptup/actions/workflows/msvc-test.yml)

tuptup is advanced `std::tuple` library for C++11/14/17.


## Type traits

C++11 or later
- [tuple_cat_t](docs/tuple_cat_t.md)
- [tuple_front_t](docs/useful_alias.md)
- [tuple_back_t](docs/useful_alias.md)
- [apply_type_t](docs/apply_type.md)
- [tuple_slice_t](docs/tuple_slice.md)
- [tuple_filter_t](docs/tuple_filter.md)

C++17 or later
- [struct_as_tuple](docs/struct_as_tuple.md)

## Functions

C++11 or later
- [tuple_front](docs/get_alias.md)
- [tuple_back](docs/useful_alias.md)
- [tuple_slice](docs/tuple_slice.md)
- [tuple_filter](docs/tuple_filter.md)
- [apply_each](docs/apply_each.md)
- [indexed_apply_each](docs/indexed_apply_each.md)
- apply (Compatible with `std::apply`)

C++14 or later
- [make_zip_iterator](docs/zip_iterator.md)

C++17 or later
- [tie_as_tuple](docs/struct_as_tuple.md)
- [make_as_tuple](docs/struct_as_tuple.md)

C++20 or later
- [get_name()](docs/member_name.md)

## Others

C++11 or later
- [integer_sequence](docs/integer_sequence.md)
- [type_placeholders](docs/type_placeholders.md)

C++14 or later
- [zip_iterator](docs/zip_iterator.md)


# License
This software is released under the MIT License, see [LICENSE](LICENSE).
