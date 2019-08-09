/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 private:
  void collect(TreeNode* root, vector<TreeNode*>& leaves) {
    if (root->left == nullptr && root->right == nullptr) {
      leaves.push_back(root);
    }
    if (root->left) {
      collect(root->left, leaves);
      if (root->left == leaves.back()) {
        root->left = nullptr;
      }
    }
    if (root->right) {
      collect(root->right, leaves);
      if (root->right == leaves.back()) {
        root->right = nullptr;
      }
    }
  }

 public:
  vector<vector<int>> findLeaves(TreeNode* root) {
    if (!root) {
      return {};
    }

    vector<vector<int>> ans;

    while (root->left || root->right) {
      ans.push_back({});
      vector<TreeNode*> leaves;
      collect(root, leaves);

      for (const auto& v : leaves) {
        ans.back().push_back(v->val);
      }
    }
    ans.push_back({root->val});

    return ans;
  }
};
