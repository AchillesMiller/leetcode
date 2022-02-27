#ifndef INCLUDED_LINKED_LIST_2_ADD_TWO_NUMBERS
#define INCLUDED_LINKED_LIST_2_ADD_TWO_NUMBERS

namespace leetcode {

/** @brief: add two link
 *  2 -> 4 -> 3
 *  2 -> 6 -> 4
 *  @return 4 -> 0 -> 8
 **/

class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
  {
    return addTwoNumbers2(l1, l2);
  }

private:
  ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2, int prev=0)
  {
    if (!l1 && !l2)
      return (prev == 0)? nullptr: new ListNode(prev);

    int val = prev;

    if (l1) val += l1->val;
    if (l2) val += l2->val;

    ListNode *curr = new ListNode(val % 10);
    curr->next =
      addTwoNumbers1(l1?l1->next: nullptr, l2?l2->next: nullptr, val/10);

    return curr;
  }

  ListNode* addTwoNumbers2(ListNode *l1, ListNode *l2)
  {
    if (!l1) return l2;
    if (!l2) return l1;

    ListNode root;

    auto it = &root;
    int prev = 0;

    while (l1 && l2)
    {
      int val = l1->val + l2->val + prev;
      it->next = new ListNode(val%10);
      prev = val / 10;

      it = it->next;

      l1 = l1->next;
      l2 = l2->next;
    }

    while (l1)
    {
      l1->val += prev;
      prev = l1->val / 10;
      l1->val %= 10;
      it->next = l1;
      it = it->next;
      l1 = l1->next;

    }

    while(l2)
    {
      l2->val += prev;
      prev = l2->val / 10;
      l2->val %= 10;
      it ->next = l2;
      it = it->next;
      l2 = l2->next;
    }

    if (prev > 0)
      it->next = new ListNode(prev);

    return root.next;
  }

};

} // end namespace leetcode

#endif