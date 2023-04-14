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
    TreeNode* solve(int &index, vector<int> &preorder, int mini, int maxi)
    {
        if(index >= preorder.size()) return NULL;
        if(preorder[index] <= mini || preorder[index] >= maxi) return NULL;
        
        TreeNode* root = new TreeNode(preorder[index++]);
        root->left = solve(index, preorder, mini, root->val);
        root->right = solve(index, preorder, root->val, maxi);
        
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return solve(i, preorder, INT_MIN, INT_MAX);
    }
};