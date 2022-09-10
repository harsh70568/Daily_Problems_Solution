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
    void solve(TreeNode* root, string temp, vector<string> &ans)
    {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL)
        {
            temp.push_back(root->val+'a');
            reverse(temp.begin(),temp.end());
            ans.push_back(temp);
            return;
        }
        temp += root->val+'a';
        solve(root->left,temp,ans);
        solve(root->right,temp,ans);
        
    }
    string smallestFromLeaf(TreeNode* root) {
        vector<string> ans;
        string temp = "";
        solve(root,temp,ans);
        
        sort(ans.begin(),ans.end());
        return ans[0];
    }
};