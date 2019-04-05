#pragma once

#include <unordered_map>
#include <vector>

class Solution
{
public:
  // Template method given in problem on leetcode
  // I modified the return type to unsigned int because an index is never signed
  // Optimized for speed rather than memory (overhead for unordered_map is less than .1 MB)
  // O(n) notation
  static const std::vector<unsigned int> twoSum(const std::vector<int>& nums, const int target)
  {
    std::unordered_map<int, unsigned int> indices;

    const auto size = nums.size();
    for (unsigned int i = 0; i < size; ++i)
    {
      if (indices.find(target - nums[i]) != indices.end())
      {
        return { indices[target - nums[i]], i };
      }

      indices[nums[i]] = i;
    }

    throw std::exception("No pairwise sums match target.");
  }
};
