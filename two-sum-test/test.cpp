#include "stdafx.h"

#include <algorithm>

#include "CppUnitTest.h"
#include "../two-sum/Solution.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test
{
  TEST_CLASS(TwoSum)
  {
  public:
    TEST_METHOD(RandomOrder)
    {
      const std::vector<int> nums = { 20, 3, 9, -2 };
      const auto target = 7;

      const auto actual = Solution::twoSum(nums, target);

      const std::vector<unsigned int> expected = { 2, 3 };

      Assert::AreEqual(expected.size(), actual.size());
      Assert::IsTrue(std::equal(actual.begin(), actual.end(), expected.begin()));
    }

    TEST_METHOD(NoMatch)
    {
      const std::vector<int> nums = { 1, 2, 3 };
      const auto target = 10;

      Assert::ExpectException<std::exception>([&nums, target] { Solution::twoSum(nums, target); });
    }
  };
}