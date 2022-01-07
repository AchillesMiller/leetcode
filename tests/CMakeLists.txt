include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

FetchContent_MakeAvailable(googletest)

include(GoogleTest)

add_subdirectory(array)
add_subdirectory(divide_and_conquer)
add_subdirectory(dp)
add_subdirectory(greedy_algorithm)
add_subdirectory(intervals)
add_subdirectory(matrix)
add_subdirectory(tree)
add_subdirectory(topological_sort)
add_subdirectory(union_find)
