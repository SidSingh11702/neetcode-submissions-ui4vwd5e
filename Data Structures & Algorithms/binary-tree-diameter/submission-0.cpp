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
    pair<int,int> helper(TreeNode* root) {
        if (!root) return {-1,-1};
        auto l = helper(root->left), r = helper(root->right);
        return {max(l.second+r.second+2,max(l.first,r.first)),max(l.second,r.second)+1};
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return helper(root).first;
    }
};
