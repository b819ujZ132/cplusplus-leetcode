// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"

#include <iostream>

#include "Solution.h"

int main()
{
  ListNode* a = new ListNode(2);
  a->next = new ListNode(4);
  a->next->next = new ListNode(3);
  
  ListNode* b = new ListNode(5);
  b->next = new ListNode(6);
  b->next->next = new ListNode(4);

  auto result = Solution::addTwoNumbers(a, b);

  std::cout << "Result: ";
  while (result)
  {
    std::cout << result->val;

    result = result->next;
  }

  return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
