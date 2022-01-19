#ifndef INCLUDED_HEAP_23_MERGE_K_SORTED_LIST
#define INCLUDED_HEAP_23_MERGE_K_SORTED_LIST

#include <vector>

namespace leetcode {

class Solution {
public:
  ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    std::priority_queue<ListNode *, std::vector<ListNode *>, greater> Q;

    for (auto &l: lists)
      if (l)
        Q.push(l);

    ListNode head;
    auto it = &head;

    while (!Q.empty())
    {
      auto top = Q.top();
      Q.pop();

      it->next = top;
      it = it->next;

      if (top->next)
        Q.push(top->next);
    }

    return head.next;
  }

private:
  struct greater
  {
    bool operator()(const ListNode *l, const ListNode *r) const
    {
      return l->val > r->val;
    }
  };

};

} // end namespace leetcode

#endif
