 
cmake_minimum_required(VERSION 3.1)

project(tests LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)
enable_testing()

find_package(tuptup)

add_executable(integer_sequence integer_sequence.cpp)
target_link_libraries(integer_sequence PRIVATE tuptup)

add_executable(tuple_slice tuple_slice.cpp)
target_link_libraries(tuple_slice PRIVATE tuptup)

add_executable(tuple_filter tuple_filter.cpp)
target_link_libraries(tuple_filter PRIVATE tuptup)

add_executable(apply apply.cpp)
target_link_libraries(apply PRIVATE tuptup)

add_executable(apply_each apply_each.cpp)
target_link_libraries(apply_each PRIVATE tuptup)

add_executable(indexed_apply indexed_apply.cpp)
target_link_libraries(indexed_apply PRIVATE tuptup)

add_executable(struct_binder struct_binder.cpp)
target_compile_features(struct_binder PRIVATE cxx_std_17)
target_link_libraries(struct_binder PRIVATE tuptup)


if(MSVC)
    add_test(NAME integer_sequence_test COMMAND integer_sequence.exe)
    add_test(NAME tuple_slice_test COMMAND tuple_slice.exe)
    add_test(NAME tuple_filter_test COMMAND tuple_filter.exe)
    add_test(NAME apply_test COMMAND apply.exe)
    add_test(NAME apply_each_test COMMAND apply_each.exe)
    add_test(NAME indexed_apply_test COMMAND indexed_apply.exe)
    add_test(NAME struct_binder_test COMMAND struct_binder.exe)
else()
    add_test(NAME integer_sequence_test COMMAND integer_sequence)
    add_test(NAME tuple_slice_test COMMAND tuple_slice)
    add_test(NAME tuple_filter_test COMMAND tuple_filter)
    add_test(NAME apply_test COMMAND apply)
    add_test(NAME apply_each_test COMMAND apply_each)
    add_test(NAME indexed_apply_test COMMAND indexed_apply)
    add_test(NAME struct_binder_test COMMAND struct_binder)
endif()
