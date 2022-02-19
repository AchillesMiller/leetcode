#ifndef INCLUDED_LINKED_LIST_138_COPY_LIST_WITH_RANDOM_POINTER
#define INCLUDED_LINKED_LIST_138_COPY_LIST_WITH_RANDOM_POINTER

namespace leetcode {

/** @brief: copy list with random pointer
 *  A linked list of length n is given
 *  such that each node contains an additional random pointer,
 *  which could point to any node in the list, or null.
 **/

class Solution {
public:
  Node* copyRandomList(Node* head)
  {
    std::unordered_map<Node *, Node *> copied;
    copied.insert(std::make_pair(nullptr, nullptr));

    return copy_random_list(head, copied);
  }

private:
  Node * copy_random_list(Node *head, std::unordered_map<Node *, Node *> &m)
  {
    if (!head)
      return head;

    auto it = m.insert(std::make_pair(head, nullptr));

    if (it.second) // succeed to insert
      it.first->second = new Node(head->val);

    it.first->second->next = copy_random_list(head->next, m);

    // when set the random, every node is already deep copied
    it.first->second->random = m[head->random];

    return it.first->second;
  }

};

} // end namespace leetcode

#endif