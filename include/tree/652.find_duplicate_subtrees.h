#ifndef INCLUDED_TREE_652_FIND_DUPLICATE_SUBTREES
#define INCLUDED_TREE_652_FIND_DUPLICATE_SUBTREES

namespace leetcode {

/** @brief: find duplicate trees
 *  Given the root of a binary tree, return all duplicate subtrees.
 *
 *  For each kind of duplicate subtrees,
 *  you only need to return the root node of any one of them.
 *
 *  Two trees are duplicate
 *  if they have the same structure with the same node values.
 **/

class Solution {
public:
  vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    // find duplicate subtree, it can be interpreted as
    // given a tree, iterate using inorder or preorder, or postorder,
    // generate its repr and record them

    // one hint, if two subtree is the same, their lowest common ancestor
    // must not be one of their root

    std::vector<TreeNode *> duplicates;
    std::unordered_map<std::string, int> counts;

    find_duplicates(root, counts, duplicates);

    return duplicates;
  }

private:
  std::string find_duplicates(TreeNode *root,
                              std::unordered_map<std::string, int> &counts,
                              std::vector<TreeNode *> &duplicates)
  {
    if (!root)
      return "#";

    std::string repr = std::to_string(root->val);
    repr.append(1, '-').append(find_duplicates(root->left, counts, duplicates));
    repr.append(1, '-').append(find_duplicates(root->right, counts, duplicates));

    auto it = counts.insert(std::make_pair(repr, 0));
    it.first->second ++;

    if (it.first->second == 2)
      duplicates.push_back(root);

    return repr;
  }
};

} // end namespace leetcode

#endif