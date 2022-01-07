#ifndef INCLUDED_GREEDY_ALGORITHM_STRING_TEXT_JUSTIFICATION_68
#define INCLUDED_GREEDY_ALGORITHM_STRING_TEXT_JUSTIFICATION_68

#include <vector>

namespace leetcode {

class Solution {
public:
  /**
   * @brief : full justify
   * Given an array of strings words and a width maxWidth,
   * format the text such that each line has exactly maxWidth characters and
   * is fully (left and right) justified.
   */
  std::vector<std::string>
    fullJustify(std::vector<std::string>& words, int maxWidth)
  {
    // nothing excited, greedy algorithm to tell how many words we can wrap
    // into one line
    // add the space based on how many chars left

    std::vector<std::string> lines;
    lines.reserve(words.size());

    int i = 0;
    while (i < words.size())
    {
      std::string line;
      i = justify(words, i, maxWidth, line);
      lines.push_back(std::move(line));
    }

    return lines;
  }

private:
  int justify(const std::vector<std::string> &words,
              int start,
              int max_width,
              std::string &line)
  {
    line.reserve(max_width);

    int end = next(words, start, max_width);

    // justify [start, end)

    // for last line or only one word in line, left-justified
    // others                                , middle-justified

    if (end == words.size() || end-start == 1)
    {
      for (auto i = start; i < end; ++i)
        line.append(words[i]).append(1, ' ');

      line.pop_back();
      line.append(max_width-line.size(), ' ');
    }
    else
    {
      int gaps = end-start-1;
      assert (gaps >= 1); // have at least one gap

      int len = 0;
      for (auto i = start; i < end; ++i)
        len += words[i].size();

      int spaces = (max_width - len) / gaps;
      int mod = (max_width - len) % gaps;

      for (auto i = start; i < end; ++i)
      {
        line.append(words[i]);

        if (i+1 == end)
          continue;

        line.append(spaces, ' ');

        if (i < start + mod)
          line.append(1, ' ');
      }
    }

    return end;
  }

  int next(const std::vector<std::string> &words, int start, int max_width)
  {
    int i = start;
    int w = max_width;

    w -= words[i].size(); // adding the first word
    ++i;

    // if it cannot add a space and a words[i], terminate this loop;
    // and return i as i)
    while (i < words.size() && w - int(words[i].size()) - 1 >= 0)
    //                             --------------------   --
    //                             length of word   minimum space
      w -= int(words[i++].size()) + 1;

    return i;
  }
};

} // end namespace leetcode

#endif
