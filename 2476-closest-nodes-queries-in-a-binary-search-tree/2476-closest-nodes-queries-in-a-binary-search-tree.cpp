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
   void find_pre_suc(TreeNode* root, TreeNode* &pre, TreeNode* &suc, int key)
   {
       if(root == NULL) return;
       
       if(root->val == key)
       {
           suc = root;
           pre = root;
           return;
       }
       else if(root->val > key)
       {
           suc = root;
           find_pre_suc(root->left, pre, suc, key);
       }
       else
       {
           pre = root;
           find_pre_suc(root->right, pre, suc, key);
       }
   }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> ans;
        
        for(int i = 0; i < queries.size(); i++)
        {
           TreeNode* pre = NULL;
           TreeNode* suc = NULL;
            find_pre_suc(root, pre, suc, queries[i]);
           vector<int> temp;
           if(pre == NULL) temp.push_back(-1);
            else temp.push_back(pre->val);
            if(suc == NULL) temp.push_back(-1);
            else temp.push_back(suc->val);
            
            ans.push_back(temp);
        
            
        }
        
        return ans;
    }
};





