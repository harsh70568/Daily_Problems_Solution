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
    vector<int> merge_them(vector<int> &first, vector<int> &second)
    {
        int n = first.size();
        int m = second.size();
        vector<int> ans(n+m);
        
        int i = 0;
        int j = 0;
        int k = 0;
        while(i < n && j < m)
        {
            if(first[i] < second[j])
            {
                ans[k++] = first[i++];
            }
            else
            {
                ans[k++] = second[j++];
            }
        }
        while(i < n)
        {
           ans[k++] = first[i++];
        }
        while(j < m)
        {
            ans[k++] = second[j++];
        }
        return ans;
    }
    void inorder(TreeNode* root, vector<int> &temp)
    {
        if(root != NULL)
        {
            inorder(root->left,temp);
            temp.push_back(root->val);
            inorder(root->right,temp);
        }
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> first;
        vector<int> second;
        inorder(root1,first);
        inorder(root2,second);
        
        vector<int> ans = merge_them(first,second);
        return ans;
    }
};