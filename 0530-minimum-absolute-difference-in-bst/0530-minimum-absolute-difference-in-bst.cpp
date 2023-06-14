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
    void solve(TreeNode* root, vector<int> &in)
    {
        if(root)
        {
            solve(root->left, in);
            in.push_back(root->val);
            solve(root->right, in);
        }
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> ans;
        solve(root, ans);
        
        int mini = 1e9;
        for(int i = 1; i < ans.size(); i++)
        {
            mini = min(mini, ans[i] - ans[i-1]);
        }
        
        return mini;
    }
};