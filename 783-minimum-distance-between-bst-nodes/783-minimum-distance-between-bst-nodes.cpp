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
    void inorder(TreeNode* root, vector<int> &ans)
    {
        if(root)
        {
            inorder(root->left,ans);
            ans.push_back(root->val);
            inorder(root->right,ans);
        }
    }
    int minDiffInBST(TreeNode* root) {
        vector<int> ans;
        inorder(root,ans);
        
        int min_diff = INT_MAX;
        
        for(int i = 0; i < ans.size()-1; i++)
        {
            if(min_diff > ans[i+1]-ans[i]) min_diff = ans[i+1] - ans[i];
        }
        
        return min_diff;
    }
};