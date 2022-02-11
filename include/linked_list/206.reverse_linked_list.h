#ifndef INCLUDED_LINKED_LIST_206_REVERSE_LINKED_LIST
#define INCLUDED_LINKED_LIST_206_REVERSE_LINKED_LIST

namespace leetcode {

/** @brief: Reverse Linked List
 *  Given the head of a singly linked list, reverse the list,
 *  and return the reversed list.
 **/

class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    if (!head)
      return head;

    // swap prev, curr and next each time
    ListNode *prev = nullptr;
    auto curr = head;

    while(curr)
    {
      auto next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }

    return prev;
  }
};

} // end namespace leetcode

#endif