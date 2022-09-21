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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> temp;
        
        ListNode* curr = head->next;
        ListNode* prev = head;
        int count = 1;
        while(curr->next)
        {
            count++;
            if(curr->val > prev->val && curr->val > curr->next->val)
            {
                temp.push_back(count);
            }
            else if(curr->val < prev->val && curr->val < curr->next->val)
            {
                temp.push_back(count);
            }
            prev = curr;
            curr = curr->next;
        }
        
        
        if(temp.size() < 2) return {-1,-1};
        else
        {
            int n = temp.size();
            int maxi = temp[n-1] - temp[0];
            int mini = INT_MAX;
            for(int i = 1; i < n; i++)
            {
                mini = min(mini,temp[i] - temp[i-1]);
            }
            return {mini,maxi};
        }
        
    }
};