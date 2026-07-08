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
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;
        if (root) q.push(root);
        while (!q.empty()) {
            auto node = q.front(); res.push_back(node->val);
            int size = q.size();
            while (size--) {
                node = q.front(); q.pop();
                if (node->right) q.push(node->right);
                if (node->left) q.push(node->left);
            }
        }
        return res;
    }
};
