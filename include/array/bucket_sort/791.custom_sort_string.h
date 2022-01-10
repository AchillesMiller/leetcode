#ifndef INCLUDED_ARRAY_BUCKET_SORT_791_CUSTOM_SORT_STRING
#define INCLUDED_ARRAY_BUCKET_SORT_791_CUSTOM_SORT_STRING

namespace leetcode {

class Solution {
public:
  std::string customSortString(std::string order, std::string s)
  {
    // this is bucket sort problem
    // 1. char in string order can map to a index of buckets
    // 2. each bucket tell's us how many chars in the s

    // conclusion, for those kind of problem, if the order is fixed,
    // it is obvious to use bucket sort

    std::vector<int> buckets(order.size()); // how many order[i] appears in s
    std::vector<int> lookup(26, -1);        // lookup from char to int

    for (auto i = 0; i != order.size(); ++i)
    {
      buckets[i] = 0;
      lookup[index(order[i])] = i;
    }

    std::string ret;
    ret.reserve(s.size());

    for (auto &x: s)
    {
      if (lookup[index(x)] == -1) // not presented in order
        ret.append(1, x);
      else
        buckets[lookup[index(x)]] ++;
    }

    for (auto i = 0; i != buckets.size(); ++i)
      if (buckets[i] != 0)
        ret.append(buckets[i], order[i]);

    return ret;
  }

private:
  int index(char &c) { return c - 'a'; }

};

} // end namespace leetcode

#endif
