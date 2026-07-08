/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    map<TreeNode*,int> dp;
public:
    int rob(TreeNode* root) {
        if (root == nullptr) return 0; else if (dp.count(root)) return dp[root];
        int ans = root->val;
        if (root->left) ans += rob(root->left->left) + rob(root->left->right);
        if (root->right) ans += rob(root->right->left) + rob(root->right->right);
        return dp[root] = max(ans,rob(root->left)+rob(root->right));
    }
};