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
  bool isValidBST(TreeNode *root) {
    if (!root) {
      return true;
    }
    TreeNode *predecessor = nullptr;
    std::stack<TreeNode *> s;
    while (!s.empty() || root) {
      // Left
      while (root) {
        s.push(root);
        root = root->left;
      }
      // Process
      TreeNode *curr_node = s.top();
      s.pop();
      if (predecessor && predecessor->val >= curr_node->val) {
        return false;
      }
      predecessor = curr_node;
      root = curr_node->right;
    }
    return true;
  }
};
