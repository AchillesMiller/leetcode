#ifndef INCLUDED_STACK_716_MAX_STACK
#define INCLUDED_STACK_716_MAX_STACK

namespace leetcode {

/** @brief: max stack
 *  Design a max stack data structure that supports the stack operations
 *  and supports finding the stack's maximum element.
 *  Support the popMat method
 **/

class MaxStack {

private:
  std::list<int> _values;
  std::map<int, std::vector<std::list<int>::iterator>> _map;

public:
  MaxStack() {}

  void push(int x) {
    _values.push_back(x);
    auto it =
      _map.insert(std::make_pair(x, std::vector<std::list<int>::iterator>()));

    it.first->second.push_back(std::prev(_values.end(), 1));
  }

  int pop() {

    if (_values.empty())
      return -1;

    int value = _values.back();

    _map[value].pop_back();

    if (_map[value].empty())
      _map.erase(value);

    _values.pop_back();

    return value;
  }

  int top() {
    return _values.back();
  }

  int peekMax() {
    if (_map.empty())
      return -1;
    return _map.rbegin()->first;
  }

  int popMax() {
    if (_map.empty())
      return -1;

    int value = _map.rbegin()->first;
    auto &its = _map.rbegin()->second;

    auto &it = its.back();
    _values.erase(it);

    its.pop_back();

    if (its.empty())
      _map.erase(std::prev(_map.end(), 1));

    return value;
  }
};

} // end namespace leetcode

#endif