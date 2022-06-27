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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = 0;
        while(!q.empty())
        {
            int size = q.size();
            vector<int> temp;
            stack<int> st;
            for(int i = 0; i < size; i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                
                if(flag == 0)
                {
                    temp.push_back(curr->val);
                }
                else
                {
                    st.push(curr->val);
                }
                
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            while(!st.empty())
            {
                temp.push_back(st.top());
                st.pop();
            }
            ans.push_back(temp);
            flag = !flag;
        }
        return ans;
    }
};