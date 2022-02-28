#ifndef INCLUDED_ARRAY_295_FIND_MEDIAN_FROM_DATA_STREAM
#define INCLUDED_ARRAY_295_FIND_MEDIAN_FROM_DATA_STREAM

namespace leetcode {

/** @brief Find Median
 *  The median is the middle value in an ordered integer list.
 *  If the size of the list is even, there is no middle value
 *  and the median is the mean of the two middle values.
 **/

class MedianFinder {

private:
  using data_t = std::multiset<int>;
  using iterator_t = typename data_t::iterator;

  data_t _data;
  iterator_t _l;
  iterator_t _r;

public:
  MedianFinder()
  : _data()
  , _l(_data.end())
  , _r(_data.end())
  {}

  void addNum(int num) {

    int n = _data.size();

    // find the first element that is greater than/equal to num
    auto it = _data.lower_bound(num);
    _data.insert(it, num);

    if (n == 0)
    {
      _l = _r = _data.begin();
      return;
    }

    if (n % 2 == 1)
    {
      assert (_l == _r);
      if (num <= *_l)
        --_l;
      else
        ++_r;
    }
    else
    {
      // 1 3
      // l r
      // insert

      if (num <= *_r)
        --_r;
      if (num > *_l)
        ++_l;
    }
  }

  double findMedian() {
    return (static_cast<double>(*_l) + static_cast<double>(*_r))/2.0;
  }
};


} // end namespace leetcode

#endif