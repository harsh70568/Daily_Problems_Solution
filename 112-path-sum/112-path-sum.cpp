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
    void solve(TreeNode* root, int targetSum, bool &flag, int local_sum)
    {
        if(root){
        if(root->left == NULL && root->right == NULL)
        {
            if(local_sum + root->val == targetSum)
            {
                flag = true;
            }
            return;
        }
        
        solve(root->left,targetSum,flag,local_sum+root->val);
        solve(root->right,targetSum,flag,local_sum+root->val);
    }
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool flag = false;
        int local_sum = 0;
        solve(root,targetSum,flag,local_sum);
        return flag;
    }
};