// two-sum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"

#include <iostream>

#include "Solution.h"

int main()
{
	const auto nums = std::vector<int>{ 3, 2, 4 };
	const int target = 6;

  std::cout << "Nums:\t[ ";

  const auto size = nums.size();
  const unsigned int lIdx = size != 0 ? size - 1 : 0;
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
    result = Solution::twoSum(nums, target);
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
