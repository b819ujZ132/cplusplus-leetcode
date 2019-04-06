#include "stdafx.h"
#include "CppUnitTest.h"
#include "../add-two-numbers/Solution.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test
{		
	TEST_CLASS(AddTwoNumbers)
	{
	public:
		
		TEST_METHOD(TestDefault)
		{
      ListNode* a = new ListNode(2);
      a->next = new ListNode(4);
      a->next->next = new ListNode(3);

      ListNode* b = new ListNode(5);
      b->next = new ListNode(6);
      b->next->next = new ListNode(4);

      auto actual = Solution::addTwoNumbers(a, b);

      ListNode* expected = new ListNode(7);
      expected->next = new ListNode(0);
      expected->next->next = new ListNode(8);
      
      Assert::IsNotNull(actual);

      AreEqual(expected, actual);
		}

    TEST_METHOD(TestSingleDigitResult)
    {
      ListNode* a = new ListNode(1);
      
      ListNode* b = new ListNode(4);

      auto actual = Solution::addTwoNumbers(a, b);

      Assert::IsNotNull(actual);
      Assert::AreEqual(5, actual->val);
      Assert::IsNull(actual->next);
    }

    TEST_METHOD(TestCarry)
    {
      ListNode* a = new ListNode(5);

      ListNode* b = new ListNode(5);

      auto actual = Solution::addTwoNumbers(a, b);

      ListNode* expected = new ListNode(0);
      expected->next = new ListNode(1);

      Assert::IsNotNull(actual);

      AreEqual(expected, actual);
    }

    TEST_METHOD(TestZero)
    {
      ListNode* a = new ListNode(0);

      ListNode* b = new ListNode(0);

      auto actual = Solution::addTwoNumbers(a, b);

      Assert::IsNotNull(actual);
      Assert::AreEqual(0, actual->val);
      Assert::IsNull(actual->next);
    }

    TEST_METHOD(TestDifferentSizes)
    {
      ListNode* a = new ListNode(1);

      ListNode* b = new ListNode(9);
      b->next = new ListNode(9);
      b->next->next = new ListNode(9);

      auto actual = Solution::addTwoNumbers(a, b);

      ListNode* expected = new ListNode(0);
      expected->next = new ListNode(0);
      expected->next->next = new ListNode(0);
      expected->next->next->next = new ListNode(1);

      Assert::IsNotNull(actual);

      AreEqual(expected, actual);
    }

  private:
    static void AreEqual(const ListNode* expected, const ListNode* actual)
    {
      do
      {
        Assert::AreEqual(expected->val, actual->val);
      } while ((actual = actual->next) && (expected = expected->next));

      Assert::IsNull(actual);
    }
	};
}