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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int max_ans = INT_MIN;
        while(!q.empty())
        {
            int size = q.size();
            int first,last;
            int min_of_level = q.front().second;
            for(int i = 0; i < size; i++)
            {
                int curr_index = q.front().second-min_of_level;
                TreeNode* temp = q.front().first;
                q.pop();
                if(i == 0) first = curr_index;
                if(i == size-1) last = curr_index;
                
                if(temp->left)
                {
                    q.push({temp->left,(long long)curr_index*2+1});
                }
                
                if(temp->right) q.push({temp->right,(long long)curr_index*2+2});
            }
            max_ans = max(max_ans,last-first+1);
        }
        return max_ans;
    }
};