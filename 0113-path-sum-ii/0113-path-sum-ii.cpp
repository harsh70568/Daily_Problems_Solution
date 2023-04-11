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
    void solve(TreeNode* root, int target, int sum, vector<vector<int>> &ans, vector<int> temp)
    {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL)
        {
            if(root->val + sum == target)
            {
                temp.push_back(root->val);
                ans.push_back(temp);
            }
            return;
        }
        
        sum += root->val;
        temp.push_back(root->val);
        solve(root->left, target, sum, ans, temp);
        solve(root->right, target, sum, ans, temp);
    }
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int sum = 0;
        solve(root, target, sum, ans, temp);
        return ans;
    }
};