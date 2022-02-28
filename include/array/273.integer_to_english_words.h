#ifndef INCLUDED_ARRAY_273_INTEGER_TO_ENGLISH_WORDS
#define INCLUDED_ARRAY_273_INTEGER_TO_ENGLISH_WORDS

namespace leetcode {

/** @brief Integer to English Words
 *  Convert a non-negative integer num to its English words representation.
 **/

class Solution {
public:
  string numberToWords(int num) {

    if (num == 0)
      return "Zero";

    // 2^32 - 1 = 4B

    static const std::vector<std::pair<std::string, int>> units = {
      {"", 1},
      {"Thousand", 1000},
      {"Million", 1000000},
      {"Billion", 1000000000}
    };

    std::string words;

    for (int i = units.size()-1; i >= 0; --i)
    {
      int val = num / units[i].second;
      if (val == 0)
        continue;

      words.append(less_than_thousand(val));
      if (!units[i].first.empty())
        words.append(1, ' ').append(units[i].first);

      words.append(1, ' ');

      num %= units[i].second;
    }

    if (!words.empty())
      words.pop_back();

    return words;
  }

private:

  std::string less_than_thousand(int num)
  {
    assert (num < 1000);

    // check hundred -> ten -> one

    static std::unordered_map<int, std::string> map = {
      {1, "One"},
      {2, "Two"},
      {3, "Three"},
      {4, "Four"},
      {5, "Five"},
      {6, "Six"},
      {7, "Seven"},
      {8, "Eight"},
      {9, "Nine"},
      {10, "Ten"},
      {11, "Eleven"},
      {12, "Twelve"},
      {13, "Thirteen"},
      {14, "Fourteen"},
      {15, "Fifteen"},
      {16, "Sixteen"},
      {17, "Seventeen"},
      {18, "Eighteen"},
      {19, "Nineteen"},
      {20, "Twenty"},
      {30, "Thirty"},
      {40, "Forty"},
      {50, "Fifty"},
      {60, "Sixty"},
      {70, "Seventy"},
      {80, "Eighty"},
      {90, "Ninety"}
    };

    std::string word;

    if (num / 100 >= 1)
    {
      word.append(map[num/100]);
      word.append(1, ' ');
      word.append("Hundred");
      word.append(1, ' ');
      num %= 100;
    }

    auto found = map.find(num);

    if (found != map.end())
      word.append(found->second).append(1, ' ');
    else if (num != 0)
    {
      word.append(map[num/10*10]).append(1, ' ');
      num %= 10;

      if (num != 0)
        word.append(map[num]).append(1, ' ');
    }

    if (!word.empty())
      word.pop_back();

    return word;
  }

};

}


#endif