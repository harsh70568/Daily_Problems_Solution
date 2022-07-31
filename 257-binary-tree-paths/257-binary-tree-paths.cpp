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
    void solve(TreeNode* root, vector<string> &ans,string str)
    {
        if(root)
        {
            if(root->left == NULL && root->right == NULL)
            {
                str += to_string(root->val);
                ans.push_back(str);
            }
        
        str += to_string(root->val);
        str += "->";
        solve(root->left,ans,str);
        solve(root->right,ans,str);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string temp = "";
        solve(root,ans,temp);
        return ans;
    }
};