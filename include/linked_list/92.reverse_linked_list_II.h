#ifndef INCLUDED_LINKED_LIST_92_REVERSE_LINKED_LIST_II
#define INCLUDED_LINKED_LIST_92_REVERSE_LINKED_LIST_II

namespace leetcode {

/** @brief: Reverse Linked List II
 *  Given the head of a singly linked list and two integers left and right
 *  where left <= right, reverse the nodes of the list
 *  from position left to position right, and return the reversed list.
 **/

class Solution {
public:
  ListNode* reverseBetween(ListNode* head, int left, int right) {

    ListNode root;
    root.next = head;

    // steps on the left-1, and reverse next right-left + 1 nodes
    auto prev = steps(&root, left-1);
    if (!prev) // left out of bound
      return head;

    // 1 2 3 4 5
    //   2   4

    // reverse the next (right-left+1) nodes
    prev->next = reverse(prev->next, right-left+1);

    return root.next;
  }

private:

  ListNode * steps(ListNode *root, int n)
  {
    int i = 0;
    while (i++ < n && root)
      root = root->next;

    return root;
  }

  ListNode *reverse(ListNode *curr, int n)
  {
    int i = 0;

    ListNode *prev = nullptr;
    ListNode *next = nullptr;

    ListNode *start = curr;

    while (i++ < n)
    {
      assert (curr);
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }

    start->next = curr;
    return prev;
  }

};

} // end namespace leetcode

#endif