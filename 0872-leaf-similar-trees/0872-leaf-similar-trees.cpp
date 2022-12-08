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
    void inorder(TreeNode* root, vector<int> &first)
    {
        if(root)
        {
            inorder(root->left, first);
            if(root->left == NULL && root->right == NULL)
            {
                first.push_back(root->val);
            }
            inorder(root->right, first);
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> first;
        vector<int> second;
        inorder(root1, first);
        inorder(root2, second);
        
        return first == second;
    }
};