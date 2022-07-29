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
    void solve(TreeNode* root, int targetSum, vector<vector<int>> &ans, vector<int> temp,int local_sum)
    {
        if(root)
        {
            if(root->left == NULL && root->right == NULL)
            {
                if(local_sum + root->val == targetSum){
                temp.push_back(root->val);
                ans.push_back(temp);
                }
                return;
            }
        
        temp.push_back(root->val);
        solve(root->left,targetSum,ans,temp,local_sum+root->val);
        solve(root->right,targetSum,ans,temp,local_sum+root->val);
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        int local_sum = 0;
        solve(root,targetSum,ans,temp,local_sum);
        return ans;
    }
};