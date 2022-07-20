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
    TreeNode* solve(int mini, int maxi, vector<int> preorder, int &i)
    {
        if(preorder.size() <= i) return NULL;
        if(preorder[i] <= mini || preorder[i] >= maxi) return NULL;
        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = solve(mini,root->val,preorder,i);
        root->right = solve(root->val,maxi,preorder,i);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return solve(INT_MIN,INT_MAX,preorder,i);
        //return root;
    }
};