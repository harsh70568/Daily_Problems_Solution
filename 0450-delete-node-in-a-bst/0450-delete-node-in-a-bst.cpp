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
    TreeNode* inorder_succ(TreeNode* root)
    {
        while(root->left)
        {
            root = root->left;
        }
        
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        
        if(root->val < key)
        {
            root->right = deleteNode(root->right, key);
        }
        else if(root->val > key)
        {
            root->left = deleteNode(root->left, key);
        }
        else // node found
        {
            // handle case when child <= 1
            if(root->left == NULL)
            {
                TreeNode* temp = root->right;
                delete(root);
                return temp;
            }
            if(root->right == NULL)
            {
                TreeNode* temp = root->left;
                delete(root);
                return temp;
            }
            // handle case when child == 2
            else
            {
                TreeNode* temp = inorder_succ(root->right);
                swap(root->val, temp->val);
                root->right = deleteNode(root->right, temp->val);
                
            }
        }
        return root;
    }
};