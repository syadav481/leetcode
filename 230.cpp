#include "TreeNode.h"
#include <stack>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  int kthSmallest(TreeNode *root, int k) {
    if (!root) {
      return -1;
    }
    std::stack<TreeNode *> s;
    s.push(root);
    while (root || !s.empty()) {
      // left
      while (root) {
        s.push(root);
        root = root->left;
      }
      // parent
      TreeNode *curr_node = s.top();
      s.pop();
      if (--k == 0) {
        return curr_node->val;
      }
      // right
      root = curr_node->right;
    }
    return -1;
  }
};
