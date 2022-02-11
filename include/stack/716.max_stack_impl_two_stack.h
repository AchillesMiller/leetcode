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
  std::stack<int> _max;
  std::stack<int> _values;
  std::stack<int> _buffer;

public:
  MaxStack() {}

  void push(int x) {
    _values.push(x);
    if (_max.empty() || _max.top() <= x)
      _max.push(x);
  }

  int pop()
  {
    if (_values.empty())
      return -1;

    int value = _values.top();
    _values.pop();

    if (_max.top() == value)
      _max.pop();

    return value;
  }

  int top() {
    if (_values.empty())
      return -1;

    return _values.top();
  }

  int peekMax() {
    if (_max.empty())
      return -1;

    return _max.top();
  }

  int popMax() {
    if (_max.empty())
      return -1;

    int max = _max.top();
    _max.pop();

    while (_values.top() != max)
    {
      _buffer.push(_values.top());
      _values.pop();
    }

    _values.pop();

    while(!_buffer.empty())
    {
      this->push(_buffer.top());
      _buffer.pop();
    }

    return max;
  }
};

} // end namespace leetcode

#endif