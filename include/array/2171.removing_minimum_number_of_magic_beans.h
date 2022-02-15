#ifndef INCLUDED_ARRAY_2171_REMOVING_MINIMUM_NUMBER_OF_MAGIC_BEANS
#define INCLUDED_ARRAY_2171_REMOVING_MINIMUM_NUMBER_OF_MAGIC_BEANS

namespace leetcode {

/** @brief: removing minimum number of magic beans
 *  Make array to another array with equal number or zero
 *  Return the minimum number of magic beans that you have to remove
 **/

class Solution {
public:
  long long minimumRemoval(vector<int>& beans) {

    std::sort(beans.begin(), beans.end());

    // so, select one bean x, any bean less than/equal to x is changed to be 0
    //                        any bean greater than x is changed to be x

    int n = beans.size();

    long long min = std::numeric_limits<long long>::max();

    long long sum = 0;

    for (auto i = 0; i != beans.size(); ++i)
    {
      // min(removal) = min(prefix + num - prefix - (n-i) * beans[i])
      //              = min(num - (n-i) * beans[i])

      min = std::min(min, -static_cast<long long>(n-i) * beans[i]);

      sum += beans[i];
    }

    return sum + min;
  }
};

} // end namespace leetcode


#endif