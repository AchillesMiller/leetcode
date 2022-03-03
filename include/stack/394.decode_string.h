#ifndef INCLUDED_STACK_394_DECODE_STRING
#define INCLUDED_STACK_394_DECODE_STRING

namespace leetcode {

/** @brief: Decode String
 *  Given an encoded string, return its decoded string.
 *  The encoding rule is: k[encoded_string],
 *  where the encoded_string inside the square brackets
 *  is being repeated exactly k times.
 *  Note that k is guaranteed to be a positive integer.
 **/

class Solution {
public:
  string decodeString(string s) {

    int i = 0;

    return decode(s, i);
  }

private:

  // iterate the leaves and iterate further

  std::string decode(const std::string &s, int &start)
  {
    std::string decoded;

    int k = 0;

    while(start < s.size() && s[start] != ']') // find the first unbalanced ]
    {
      // if curr is digit, get the number, and skip the first [
      k = 0;

      while(std::isdigit(s[start]))
        k = 10 * k - '0' + s[start++];

      if (k > 0)
      {
        assert (s[start] == '[');

        // skip the [
        std::string sub = decode(s, ++start);
        decoded.reserve(decoded.size() + k * sub.size());

        assert(s[start] == ']');
        ++start; // skip the ]

        while (k-- > 0)
          decoded.append(sub);
      }
      else
        decoded.append(1, s[start++]);
    }

    return decoded;
  }

};

} // end namespace leetcode

#endif
