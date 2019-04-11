#include "stdafx.h"
#include "CppUnitTest.h"
#include "../longest-substring-without-repeating-characters/Solution.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test
{		
	TEST_CLASS(LongestSubstringWithoutRepeatingCharacters)
	{
	public:
		
		TEST_METHOD(BasicTest)
		{
      auto result = Solution::lengthOfLongestSubstring("abcabc");

      Assert::AreEqual((unsigned int)3, result);
		}

    TEST_METHOD(SingleTest)
    {
      auto result = Solution::lengthOfLongestSubstring("aaaaaa");

      Assert::AreEqual((unsigned int)1, result);
    }

    TEST_METHOD(WholeTest)
    {
      auto result = Solution::lengthOfLongestSubstring("abcdefg");

      Assert::AreEqual((unsigned int)7, result);
    }

    TEST_METHOD(OverlapTest)
    {
      auto result = Solution::lengthOfLongestSubstring("dvdfvedfe");

      Assert::AreEqual((unsigned int)4, result);
    }
	};
}