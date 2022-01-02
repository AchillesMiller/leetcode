#ifndef INCLUDED_MY_POW
#define INCLUDED_MY_POW

#include <unordered_map>

namespace leetcode {

class my_pow {

private:
  double _pow(double x, int n, std::unordered_map<int, double> &m)
  {
    auto it = m.insert({n, 0});

    if (!it.second) // failed to insert
      return it.first->second;

    it.first->second = _pow(x, n/2, m) * _pow(x, n/2, m) * _pow(x, n%2, m);
    return it.first->second;
  }

public:
  double pow(double x, int n)
  {
    std::unordered_map<int, double> m;

    m.insert({0, 1});
    m.insert({1, x});
    m.insert({-1, 1.0/x});

    return _pow(x, n, m);
  }
};

} // end namespace leetcode

#endif