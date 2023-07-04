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
    int solve(TreeNode* root, bool &flag)
    {
        if(root == NULL) return 0;
        
        int left = solve(root->left, flag);
        int right = solve(root->right, flag);
        if(abs(left-right) > 1) flag = false;
        
        return max(left, right) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        bool flag = true;
        solve(root, flag);
        return flag;
    }
};