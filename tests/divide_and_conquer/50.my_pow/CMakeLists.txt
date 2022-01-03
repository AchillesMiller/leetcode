set(BINARY my_pow_test)

add_executable(${BINARY} 50.my_pow.t.cpp)

target_link_libraries(${BINARY} gtest_main)

include(GoogleTest)

gtest_discover_tests(${BINARY})