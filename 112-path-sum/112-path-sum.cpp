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
    void solve(TreeNode* root, int target, bool &flag, int sum)
    {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL)
        {
            if(root->val + sum == target)
            {
                flag = true;
            }
            return;
        }
        sum += root->val;
        solve(root->left,target,flag,sum);
        solve(root->right,target,flag,sum);
        
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        bool flag = false;
        
        solve(root,targetSum,flag,sum);
        
        return flag;
        
    }
};