set(BINARY 791_custom_sort_string)

file(GLOB SRC_FILES *.t.cpp)

add_executable(${BINARY} ${SRC_FILES})

target_link_libraries(${BINARY} gtest_main)

include(GoogleTest)

gtest_discover_tests(${BINARY})