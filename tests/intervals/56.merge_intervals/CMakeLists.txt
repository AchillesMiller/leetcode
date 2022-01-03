set(BINARY merge_intervals_test)

add_executable(${BINARY} 56.merge_intervals.t.cpp)

target_link_libraries(${BINARY} gtest_main)

include(GoogleTest)

gtest_discover_tests(${BINARY})