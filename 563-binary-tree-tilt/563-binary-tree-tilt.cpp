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
    int solve(TreeNode* root, int &sum)
    {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return root->val;
        int l = solve(root->left,sum);
        int r = solve(root->right,sum);
        sum += abs(l-r);
        return root->val + l + r;;
    }
    int findTilt(TreeNode* root) {
        int sum = 0;
        if(root == NULL) return sum;
        solve(root,sum);
        return sum;
    }
};