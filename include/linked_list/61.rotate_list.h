#ifndef INCLUDED_LINKED_LIST_61_ROTATE_LIST
#define INCLUDED_LINKED_LIST_61_ROTATE_LIST

namespace leetcode {

/** @brief: rotate list
 *  1 -> 2 -> 3 -> 4
 *  4 -> 1 -> 2 -> 3
 **/

class Solution {
public:
  ListNode* rotateRight(ListNode* head, int k) {
    // two pointers
    // l/r

    // 1 -> 2 -> 3 -> 4
    //           l    r
    // k = 1

    if (k == 0 || !head)
      return head;

    auto len = get_len(head);
    k %= len;

    auto l = head;
    auto r = head;

    for (auto i = 0; i != k; ++i)
      r = r->next;

    while (r->next)
    {
      r = r->next;
      l = l->next;
    }

    r->next = head;
    head = l->next;
    l->next = nullptr;

    return head;
  }

private:
  int get_len(ListNode *head)
  {
    int len = 0;

    while(head)
    {
      ++len;
      head = head->next;
    }

    return len;
  }



};

} // end namespace leetcode

#endif