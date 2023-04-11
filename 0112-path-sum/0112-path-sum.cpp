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
    bool solve(TreeNode* root, int target, int sum)
    {
        if(root){
        if(root->left == NULL && root->right == NULL)
        {
            sum += root->val;
            if(sum == target) return true;
        }
        
        return solve(root->left, target, sum + root->val) || solve(root->right, target, sum + root->val);
        }
        
        return false;
    }
    bool hasPathSum(TreeNode* root, int target) {
        int sum = 0;
        return solve(root, target, sum);
    }
};