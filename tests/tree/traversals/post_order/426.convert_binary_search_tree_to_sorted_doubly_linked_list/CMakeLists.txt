set(BINARY 426_convert_binary_search_tree_to_sorted_doubly_linked_list)

file(GLOB SRC_FILES *.t.cpp)

add_executable(${BINARY} ${SRC_FILES})

target_link_libraries(${BINARY} gtest_main)

include(GoogleTest)

gtest_discover_tests(${BINARY})