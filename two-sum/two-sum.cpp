// two-sum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>

// Template method given in problem on leetcode
// I modified the return type to unsigned int because an index is never signed
static std::vector<unsigned int> twoSum(std::vector<int>& nums, int target)
{
  unsigned int i = 0;
  unsigned int j = 0;
  auto size = nums.size();
  for (auto& num : nums)
  {
    for (j = i + 1; j < size; ++j)
    {
      if (nums[i] + nums[j] == target)
      {
        goto finish;
      }
    }

    ++i;
  }

  throw std::exception("No pairwise sums match target.");

  finish:
  return std::vector<unsigned int> { i, j };
}

int main()
{
	auto nums = std::vector<int>{ -1, 7, 10, 11, 15 };
	int target = 8;

  std::cout << "Nums:\t[ ";

  auto size = nums.size();
  unsigned int lIdx = size != 0 ? size - 1 : 0;
  for (unsigned int i = 0; i < size; ++i)
  {
    if (i == lIdx)
    {
      std::cout << nums[i];
    }
    else
    {
      std::cout << nums[i] << ", ";
    }
  }

  std::cout << " ]" << std::endl;
  std::cout << "Target:\t" << target << std::endl;

  std::vector<unsigned int> result;
  try
  {
    result = twoSum(nums, target);
  }
  catch (std::exception e)
  {
    std::cerr << e.what() << std::endl;

    return -1;
  }

  // Guaranteed two results
  // Not sure why the template online is using a vector for this. Lots of overhead for no reason.
	std::cout << "Result:\t[ " << result[0] << ", " << result[1] << " ]" << std::endl;

  return 0;
}
