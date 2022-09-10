/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head)
    {
        ListNode* p = head;
        ListNode* q = NULL;
        ListNode* r = NULL;
        
        while(p)
        {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }
        
        return q;
    }
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        head = reverse(head);
        ans.push_back(0);
        stack<int> st;
        st.push(head->val);
        head = head->next;
        
        while(head)
        {
            while(!st.empty() && head->val >= st.top())
            {
                st.pop();
            }
            
            int res = (st.empty()) ? 0 : st.top();
            ans.push_back(res);
            st.push(head->val);
            head = head->next;
        }
        std::reverse(ans.begin(),ans.end());
        
        return ans;
        
    }
};