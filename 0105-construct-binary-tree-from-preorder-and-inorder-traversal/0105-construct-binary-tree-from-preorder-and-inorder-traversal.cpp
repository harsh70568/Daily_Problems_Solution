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
    int ps = 0;
    TreeNode* solve(vector<int> &pre, vector<int> &in, int left, int right)
    {
        if(left > right) return NULL;
        
        TreeNode* root = new TreeNode(pre[ps++]);
        
        int idx = 0;
        for(int i = 0; i < in.size(); i++)
        {
            if(in[i] == root->val)
            {
                idx = i;
                break;
            }
        }
        
        root->left = solve(pre, in, left, idx-1);
        root->right = solve(pre, in, idx+1, right);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        return solve(pre, in, 0, in.size()-1);
    }
};