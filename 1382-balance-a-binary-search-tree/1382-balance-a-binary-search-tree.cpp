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
    TreeNode* solve(vector<int> &temp, int low, int high)
    {
        if(low > high) return NULL;
        int mid = (low + high) >> 1;
        TreeNode* root = new TreeNode(temp[mid]);
        root->left = solve(temp, low, mid - 1);
        root->right = solve(temp, mid + 1, high);
        
        return root;
    }
    void inorder(TreeNode* root, vector<int> &ans)
    {
        if(root)
        {
            inorder(root->left, ans);;
            ans.push_back(root->val);
            inorder(root->right, ans);
        }
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> temp;
        inorder(root, temp);
        
        return solve(temp, 0, temp.size()-1);
    }
};