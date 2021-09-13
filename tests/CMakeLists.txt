 
cmake_minimum_required(VERSION 3.1)

project(tests LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)
enable_testing()


add_executable(integer_sequence integer_sequence.cpp)
add_test(NAME integer_sequence_test COMMAND integer_sequence)

add_executable(tuple_slice tuple_slice.cpp)
add_test(NAME tuple_slice_test COMMAND tuple_slice)

add_executable(tuple_filter tuple_filter.cpp)
add_test(NAME tuple_filter_test COMMAND tuple_filter)

add_executable(apply apply.cpp)
add_test(NAME apply_test COMMAND apply)

add_executable(apply_each apply_each.cpp)
add_test(NAME apply_each_test COMMAND apply_each)

add_executable(indexed_apply indexed_apply.cpp)
add_test(NAME indexed_apply_test COMMAND indexed_apply)

add_executable(struct_binder struct_binder.cpp)
target_compile_features(struct_binder PRIVATE cxx_std_17)
add_test(NAME struct_binder_test COMMAND struct_binder)
