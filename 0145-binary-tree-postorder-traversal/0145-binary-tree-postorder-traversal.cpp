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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<int> st;
        stack<TreeNode*> st2;
        if(root == NULL) return ans;
        st2.push(root);
        
        
        while(!st2.empty())
        {
            auto node = st2.top();
            st2.pop();
            
            st.push(node->val);
            if(node->left) st2.push(node->left);
            if(node->right) st2.push(node->right);
        }
        
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};