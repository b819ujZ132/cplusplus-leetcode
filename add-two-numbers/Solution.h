#pragma once

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  // Template method given in problem on leetcode
  // I modified the parameters and return types to const because there is no need to pass
  // around a raw and modifiable pointer.
  // Optimized for speed rather than memory (overhead for unordered_map is less than .1 MB)
  // O(n) notation
  static const ListNode* addTwoNumbers(const ListNode* l1, const ListNode* l2) {
    auto p1 = l1;
    auto p2 = l2;

    auto sum = p1->val + p2->val;
    auto carry = sum > 9; // Always 0 or 1
    auto result = new ListNode(sum % 10);

    p1 = p1->next;
    p2 = p2->next;

    auto l = result;
    do
    {
      if (!p1 && !p2)
      {
        if (carry)
        {
          l->next = new ListNode(carry);
        }

        return result;
      }

      sum = (p1 != nullptr ? p1->val : 0) + (p2 != nullptr ? p2->val : 0) + carry;
      carry = sum > 9;
      l->next = new ListNode(sum % 10);

      p1 = p1 != nullptr ? p1->next : nullptr;
      p2 = p2 != nullptr ? p2->next : nullptr;
      l = l->next;
    } while (p1 || p2 || carry);

    return result;
  }
};