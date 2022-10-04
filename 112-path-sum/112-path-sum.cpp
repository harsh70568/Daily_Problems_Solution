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
    void solve(TreeNode* root, int target, bool &flag, int local_sum)
    {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL)
        {
            if(root->val + local_sum == target)
            {
                flag = true;
            }
            return;
        }
        
        local_sum += root->val;
        solve(root->left, target, flag, local_sum);
        solve(root->right, target, flag, local_sum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int local_sum = 0;
        bool flag = false;
        solve(root, targetSum, flag, local_sum);
        return flag;
        
    }
};