#ifndef INCLUDED_MATRIX_BORING_QUESTIONS_498_DIAGONAL_TRAVERSAL
#define INCLUDED_MATRIX_BORING_QUESTIONS_498_DIAGONAL_TRAVERSAL

#include <vector>
#include <algorithm>

namespace leetcode {

class Solution {

private:
  using matrix_t = std::vector<std::vector<int>>;

public:
  std::vector<int> findDiagonalOrder(matrix_t& mat) {
    // diagonal traversal
    // It is easy to think of BFS algorithm with reversed order in each loop
    // But, that will introduce unnecessary memory cost

    // so, if each time, we traversal from bottom left to top right,
    // this is quite simple, 
    // so, what we need do is just flip the new segment, which is equal to
    // use insert/push_back for each traversal

    // will write one auxiliary method traverse

    int M = mat.size(), N = mat[0].size();

    std::vector<int> orders;
    orders.reserve(M*N);

    int flip = false;
    // left edge
    for (auto r = 0; r != M; ++r, flip = !flip)
      traverse(mat, r, 0, flip, orders);

    // bottom edge
    for (auto c = 1; c != N; ++c, flip = !flip)
      traverse(mat, M-1, c, flip, orders);

    return orders;
  }

 private:
  void
  traverse(const matrix_t &m, int r, int c, bool flip, std::vector<int> &orders)
  {
    int gr = -1, gc = 1; // gradient of r and c

    int size = orders.size();

    while(r >= 0 && r < m.size() && c >= 0 && c < m[r].size())
    {
      orders.push_back(m[r][c]);

      r += gr;
      c += gc;
    }

    if (flip)
      std::reverse(orders.begin()+size, orders.end());

    return;
  }

};

} // end namespace leetcode


#endif
