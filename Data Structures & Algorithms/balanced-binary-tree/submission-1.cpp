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
    pair<bool,int> helper(TreeNode* root) {
        if (!root) return {true,-1};
        auto l = helper(root->left), r = helper(root->right);
        return {l.first && r.first && abs(l.second-r.second) <= 1, max(l.second,r.second)+1};

    }
public:
    bool isBalanced(TreeNode* root) {
        return helper(root).first;
    }
};
