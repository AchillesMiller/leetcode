#ifndef INCLUDED_STACK_NULL_1D_CANDY_CRASH
#define INCLUDED_STACK_NULL_1D_CANDY_CRASH

namespace other_resource {

std::vector<int> candy_crush(std::vector<int> &candies)
{
  int n = candies.size();

  std::vector<std::pair<int, int>> cache;
  //                    ---  ---
  //                   value count

  cache.reserve(n);
  int i = 0;

  while (i < n)
  {
    auto &candy = candies[i];

    int j = i;

    // compress to node

    while (j < n && candies[i] == candies[j])
      ++j;

    asset (j > i);

    if (cache.empty() || cache.back().first != candy)
      cache.push_back(std::make_pair(candy, 0));

    cache.back().second += j - i;
    if (cache.back().second >= 3)
      cache.pop_back();

    i = j;

  }

  std::vector<int> crushed;
  crushed.reserve(n);

  for (auto &x: cache)
    for (auto i = 0; i != x.second; ++i)
      crushed.push_back(x.first);

  return crushed;
}

} // end namespace other_resource


#endif