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
    pair<int,int> maxPathSumHelper(TreeNode* root) {
        if (!root) return {INT_MIN,0};
        auto l = maxPathSumHelper(root->left), r = maxPathSumHelper(root->right);
        return {max(max(0, max(l.second + r.second, max(l.second, r.second))) + root->val, max(l.first, r.first)), root->val + max(0, max(l.second, r.second))};
    }
public:
    int maxPathSum(TreeNode* root) {
        return maxPathSumHelper(root).first;
    }
};
