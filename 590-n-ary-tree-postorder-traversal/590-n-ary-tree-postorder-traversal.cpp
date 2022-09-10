/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        
        stack<Node*> st1;
        stack<int> st2;
        st1.push(root);
        while(!st1.empty())
        {
            Node* curr = st1.top();
            st1.pop();
            
            st2.push(curr->val);
            
            for(int i = 0; i < curr->children.size(); i++)
            {
                st1.push(curr->children[i]);
            }
        }
        
        while(!st2.empty()){
            ans.push_back(st2.top());
            st2.pop();
        }
        
        return ans;
    }
};