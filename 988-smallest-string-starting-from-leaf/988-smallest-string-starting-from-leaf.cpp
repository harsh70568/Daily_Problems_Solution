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
    string ans;
    void solve(TreeNode* root, string temp)
    {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL)
        {
            temp.push_back(root->val+'a');
            reverse(temp.begin(),temp.end());
            
            if(temp.length() > 0 && temp < ans) ans = temp;
            return;
        }
        
        temp += root->val + 'a';
        solve(root->left,temp);
        solve(root->right,temp);
        
    }
    string smallestFromLeaf(TreeNode* root) {
        ans = 1 + 'z';
        string temp = "";
        solve(root,temp);
        
        return ans;
    }
};