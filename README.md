# leetcode

## index

| category            | id                                                                                  | problem statement                                                             | supposed solution                                                                                                                                 | 
|---------------------|-------------------------------------------------------------------------------------|-------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------|
| two pointers        | [1423](include/array/two_pointers/1423.maximum_points_you_can_obstain_from_cards.h) | Given an array and k, either select front and back, get maximum sum           | find minimum sum in middle                                                                                                                        |
| two pointers        | [1610](include/array/two_pointers/1610.maximum_number_of_visible_points.h)          | Find maximum points with an angle                                             | sorted the angle for each point and use two pointers algorithm to find maximum points                                                             |
| two pointers        |                                                                                     |                                                                               |                                                                                                                                                   |
| monotonic queue     | [84](include/monotonic_queue/rectangle/84.largest_rectangle_in_histogram.h)         | Find largest area of rectangle in a histogram                                 | monotonic queue                                                                                                                                   |
| monotonic queue     | [85](include/monotonic_queue/rectangle/85.maximal_rectangle.h)                      | Find largest area of rectangle in a matrix                                    | for each row, calculate heights and turning into problem 84                                                                                       |
| dijistra            | [787](include/dijistra/787.cheapest_flights_within_k_stops.h)                       | Find the min costs within k stops from src to dest                            | min cost from src to dest, this is Dijistra problem                                                                                               |
| dfs                 | [39](include/dfs/array/combinations/39.combination_sum.h)                           | Find all combinations(distinct candidate + unlimited use)                     |                                                                                                                                                   |
| dfs                 | [40](include/dfs/array/combinations/40.combination_sum_II.h)                        | Find all combinations(non-distinct candidate + one use)                       | like a tree, when append node as child, two same value is not necessary to push as the same child of its parent                                   |
| dynamic programming | [1937](include/dp/1937.maximum_number_of_points_with_cost.h)                        | Find maximum points with cost-abs(col_1-col2)                                 | dynamic programming with two passes                                                                                                               |
| dynamic programming | [377](include/dp/377.combination_sum_iv.h)                                          | Given nums and target, find the number of combination of which sum == target  | dp[target] = ∑( dp[target - nums[i]] )                                                                                                            |
| dynamic programming | [322](include/dp/322.coin_change.h)                                                 | Given coins and target, return the fewest coin combination                    | dp[target] = min( dp[target - num[i]] ) + 1                                                                                                       |
| heap                | [632](include/heap/632.smallest_range_covering_elements_from_k_lists.h)             | Give a list of vector, find smallest range covering all elements from k lists | any kind of sorted structure to keep exactly one element from k lists, when popping smallest number, push the next number in corresponding vector |



# TODO:

  - 44. Wildcard Matching
  - 727. Minimum Window Subsequence
  - 23. Merge k Sorted Lists
  - 490. The Maze
  - 499. The Maze III
  - 505. The Maze II
  - 307. Range Sum Query - Mutable (segment tree and binary indexed tree)
