#pragma once

#include <cstring>
#include <string>

namespace Solution
{
  // Template method given in problem on leetcode
  // I modified the parameter and return type to const. Return type is also unsigned now.
  // Optimized for memory rather than speed in mostly C because I wanted to challenge myself
  // Unsustainable code in my opinion, so I plan to consider different solutions
  // O(max(m, n)) notation
  static const unsigned int lengthOfLongestSubstring(const std::string s)
  {
    auto input = s.c_str();

    if (*input == 0)
    {
      return 0;
    }

    const auto length = s.length();

    unsigned int i = 1;
    unsigned int j = 1;
    unsigned int answer = 0;
    char* sub = new char[length + 1];
    sub[0] = *input;
    sub[1] = '\0';
    unsigned int subLength = 1;
    for (auto c = *++input; c; )
    {
      auto pos = strchr(sub, c);
      if (pos)
      {
        // If substring length is greater than answer, update answer
        if (subLength > answer)
        {
          answer = subLength;
        }

        auto diff = (unsigned int)(&sub[j - 1] - pos);

        // Bail out early if remaining number of characters is <= input length minus our iterated i variable
        if (length - i + diff < answer)
        {
          break;
        }

        if (diff)
        {
          subLength = diff;
          j = 0;

          for (char d = *++pos; d; )
          {
            sub[j] = d;
            sub[++j] = '\0';
            d = *++pos;
          }
        }
        else
        {
          subLength = 0;
          j = 0;
        }
      }

      sub[j] = c;
      sub[++j] = '\0';
      c = *++input;
      ++subLength;
      ++i;
    }

    if (subLength > answer)
    {
      answer = subLength;
    }

    delete[] sub;

    if (!answer)
    {
      return length;
    }

    return answer;
  }  
}
