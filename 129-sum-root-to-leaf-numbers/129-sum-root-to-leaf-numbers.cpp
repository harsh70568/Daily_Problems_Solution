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
    void solve(TreeNode* root, int digit, int &sum)
    {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL)
        {
            sum += digit*10+root->val;
            return;
        }
        solve(root->left,digit*10+root->val,sum);
        solve(root->right,digit*10+root->val,sum);
    }
    int sumNumbers(TreeNode* root) {
        int digit = 0;
        int sum = 0;
        solve(root,digit,sum);
        return sum;
    }
};