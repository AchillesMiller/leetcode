#ifndef INCLUDED_STACK_636_EXCLUSIVE_TIME_OF_FUNCTIONS
#define INCLUDED_STACK_636_EXCLUSIVE_TIME_OF_FUNCTIONS

#include <vector>
#include <string>

namespace leetcode {

class Solution {
public:
  std::vector<int> exclusiveTime(int n, std::vector<std::string>& logs) {

    std::vector<int> timespans(n, 0);
    std::vector<log> ls; // acts as a stack
    ls.reserve(logs.size());

    for (auto &l: logs)
    {
      auto log = parse_log(l);

      if (log.start)
        ls.push_back(log);
      else
      {
        assert (!ls.empty());
        assert (log.id == ls.back().id);
        int timespan = log.timestamp - ls.back().timestamp + 1;
        timespans[log.id] += timespan;

        ls.pop_back();

        if (!ls.empty())
          timespans[ls.back().id] -= timespan;
      }
    }

    assert (ls.empty());

    return timespans;
  }

private:
  struct log
  {
    int id;
    bool start;
    int timestamp;

    log(int id=-1, bool start=false, int timestamp=0)
    : id(id), start(start), timestamp(timestamp)
    {}
  };

  log parse_log(const std::string &s)
  {
    auto i = s.find(':');
    auto j = s.find(':', i+1);
    int id = stoi(s.substr(0, i));

    bool start = s.substr(i+1, j-i-1) == "start";

    int timestamp = stoi(s.substr(j+1));

    return log(id, start, timestamp);
  }

};

// ----------------------------------------- 1
//     -------                               2
//               ----------------------      3
//                   -----------             4

// it is obvious that, the timespan of 1 should erase 2 and 3
// and timespan of 3 should erase 4

// since 4 is never adjacent with 1, we don't erase the duration of 4 from 1

} // end namespace leetcode

#endif