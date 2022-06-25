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
    void preorder(TreeNode* root, vector<int> &ans)
    {
        if(root != NULL)
        {
            ans.push_back(root->val);
            preorder(root->left,ans);
            preorder(root->right,ans);
        }
    }
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        vector<int> ans;
        preorder(root,ans);
        root->left = NULL;
        root->right = NULL;
        TreeNode* curr = root;
        for(int i = 1; i < ans.size(); i++)
        {
            TreeNode* temp = new TreeNode(ans[i]);
            curr->left = NULL;
            curr->right = temp;
            curr = curr->right;
        }
        return;
    }
};