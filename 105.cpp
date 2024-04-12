#include "TreeNode.h"
#include <cstddef>
#include <unordered_map>
#include <vector>
using std::vector;

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
  std::unordered_map<int, int> m;
  std::vector<int> pre;
  std::vector<int> in;
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {

    // fill out map, elt -> index in inorder
    for (size_t i = 0; i < inorder.size(); ++i) {
      m[inorder[i]] = i;
    }
    int index = 0;
    pre = std::move(preorder);
    in = std::move(inorder);
    return dfs(index, 0, pre.size() - 1);
  }

  TreeNode *dfs(int &root_index, int l, int r) {
    if (l > r) {
      return nullptr;
    }
    int mid = m[pre[root_index]];
    TreeNode *new_node = new TreeNode(pre[root_index++]);
    // must be left then right since it is a preorder traversal.
    // when going left use old left bound but new right bound is just mid - 1;
    new_node->left = dfs(root_index, l, mid - 1);
    // when going right use old right bound but new left bound is just mid + 1;
    new_node->right = dfs(root_index, mid + 1, r);
    return new_node;
  }
};
