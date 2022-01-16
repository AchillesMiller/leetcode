#ifndef INCLUDED_STACK_735_ASTEROID_COLLISION
#define INCLUDED_STACK_735_ASTEROID_COLLISION

#include <vector>

namespace leetcode {

class Solution {
public:
  std::vector<int> asteroidCollision(std::vector<int>& asteroids)
  {
    // positive go left, negative go right
    // only left and right can collision

    std::vector<int> asts;
    asts.reserve(asteroids.size());

    for (auto &ast: asteroids)
    {
      if (ast < 0)
      {
        // asteroid going right
        bool exploded = false;

        while(!asts.empty() && asts.back() > 0 && asts.back() < -ast)
          asts.pop_back();

        // after popping the small left-going asteroids,
        // checking if it is same

        if (!asts.empty() && asts.back() == -ast)
        {
          asts.pop_back();
          continue;
        }

        if (asts.empty() || asts.back() < 0)
          asts.push_back(ast);
      }
      else
        asts.push_back(ast);
    }

    return asts;
  }
};

} // end namespace leetcode

#endif