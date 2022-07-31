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
    void solve(TreeNode* root, long long mini, long long maxi, bool &flag)
    {
       if(root == NULL) return;
       if(root->val <= mini || root->val >= maxi) flag = false;
        
       solve(root->left,mini,root->val,flag);
        solve(root->right,root->val,maxi,flag);
        
    }
    bool isValidBST(TreeNode* root) {
        bool flag = true;
        solve(root,LONG_MIN,LONG_MAX,flag);
        return flag;
    }
};