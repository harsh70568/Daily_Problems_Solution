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
    TreeNode* solve(vector<int> &pre, vector<int> &in, int ps, int pe, int is, int ie, map<int, int> &mpp)
    {
        if(ps > pe || is > ie) return NULL;
        
        TreeNode* root = new TreeNode(pre[ps]);
        int idx = mpp[root->val];
        int skip = idx - is;
        
        root->left = solve(pre, in, ps+1, ps+skip, is, idx-1, mpp);
        root->right = solve(pre, in, ps+skip+1, pe, idx+1, ie, mpp);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> mpp;
        for(int i = 0; i < inorder.size(); i++)
        {
            mpp[inorder[i]] = i;
        }
        
        return solve(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1, mpp);
    }
};