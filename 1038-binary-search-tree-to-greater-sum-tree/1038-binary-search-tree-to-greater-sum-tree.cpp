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
    void solve(TreeNode* root, int &index, vector<int> &inorder)
    {
        if(root)
        {
            solve(root->left, index, inorder);
            root->val = inorder[index++];
            solve(root->right, index, inorder);
        }
    }
    void inorder(TreeNode* root, vector<int> &ans)
    {
        if(root)
        {
            inorder(root->left, ans);
            ans.push_back(root->val);
            inorder(root->right, ans);
        }
    }
    TreeNode* bstToGst(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        
        int n = ans.size();
        for(int i = n-2; i >= 0; i--)
        {
            ans[i] = ans[i] + ans[i+1];
        }
        
        //for(auto it : ans) cout<<it<<" ";
        //cout<<"harsh";
        
        int i = 0;
        solve(root, i, ans);
        return root;
    }
};