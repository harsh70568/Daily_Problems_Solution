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
    TreeNode* solve(vector<int> &preorder, vector<int> &inorder, int left, int right)
    {
        if(left > right) return NULL;
        
        TreeNode* root = new TreeNode(preorder[ps++]);
        int idx = -1;
        for(int i = 0; i < inorder.size(); i++)
        {
            if(inorder[i] == root->val)
            {
                idx = i;
                break;
            }
        }
        
        root->left = solve(preorder, inorder, left, idx-1);
        root->right = solve(preorder, inorder, idx+1, right);
        
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        
        sort(inorder.begin(), inorder.end());
        
        return solve(preorder, inorder, 0, inorder.size()-1);
        
    }
};