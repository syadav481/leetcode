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
  vector<vector<int>> levelOrder(TreeNode *root) {
    if (!root) {
      return {};
    }
    vector<vector<int>> ans;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      size_t level_size = q.size();
      vector<int> level;
      level.reserve(level_size);
      for (size_t i = 0; i < level_size; ++i) {
        TreeNode *curr_node = q.front();
        q.pop();
        level.push_back(curr_node->val);
        if (curr_node->left) {
          q.push(curr_node->left);
        }
        if (curr_node->right) {
          q.push(curr_node->right);
        }
      }
      ans.push_back(level);
    }
    return ans;
  }
};
