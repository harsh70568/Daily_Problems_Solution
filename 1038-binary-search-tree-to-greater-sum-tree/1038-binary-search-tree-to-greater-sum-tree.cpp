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
    void inorder(TreeNode* root, vector<int> &ans, vector<TreeNode*> &node)
    {
        if(root)
        {
            inorder(root->left, ans, node);
            ans.push_back(root->val);
            node.push_back(root);
            inorder(root->right,ans, node);
        }
    }
    TreeNode* bstToGst(TreeNode* root) {
        vector<int> ans;
        vector<TreeNode*> node;
        inorder(root,ans,node);
        
        int n = ans.size();
        
        vector<int> temp(n);
        temp[n-1] = ans[n-1];
        
        for(int i = n-2; i >= 0; i--)
        {
            temp[i] = ans[i] + temp[i+1];
        }
        
        for(int i = 0; i < n; i++)
        {
            node[i]->val = temp[i];
        }
        
        return root;
    }
};