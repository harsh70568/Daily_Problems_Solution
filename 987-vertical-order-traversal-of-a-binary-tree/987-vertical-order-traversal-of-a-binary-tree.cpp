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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        map<int,map<int,multiset<int>>> mpp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty())
        {
            pair<TreeNode*,pair<int,int>> temp = q.front();
            q.pop();
            
            TreeNode* curr = temp.first;
            int hd = temp.second.first;
            int level = temp.second.second;
            
            mpp[hd][level].insert(curr->val);
            
            if(curr->left) q.push({curr->left,{hd-1,level+1}});
            if(curr->right) q.push({curr->right,{hd+1,level+1}});
        }
        
        for(auto i : mpp)
        {
            vector<int> res;
            for(auto j : i.second)
            {
                res.insert(res.end(), j.second.begin(), j.second.end());
            }
            ans.push_back(res);
        }
        return ans;
    }
};