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
  // around a raw modifiable pointer.
  // Optimized for speed rather than memory
  // O(max(m, n)) notation
  static const ListNode* addTwoNumbers(const ListNode* l1, const ListNode* l2) {
    auto p1 = l1;
    auto p2 = l2;

    ListNode* head = nullptr;
    ListNode** cur = &head;

    int carry = 0;

    while (p1 || p2 || carry)
    {
      int value = carry;
      if (p1)
      {
        value += p1->val;
        p1 = p1->next;
      }

      if (p2)
      {
        value += p2->val;
        p2 = p2->next;
      }

      carry = value / 10;
      value %= 10;

      if (!(*cur))
      {
        *cur = new ListNode(value);
        cur = &(*cur)->next;
      }
    }

    return head;
  }
};