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
    int length(ListNode* head)
    {
        int count = 0;
        while(head)
        {
            head = head->next;
            count++;
        }
        return count;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* forw = NULL;
        int count = 0;
        while(curr && count < k)
        {
            forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
            count++;
        }
        
        if(forw && length(forw) >= k)
        {
            head->next = reverseKGroup(forw,k);
        }
        else
        {
            head->next = forw;
        }
        
        return prev;
    }
};