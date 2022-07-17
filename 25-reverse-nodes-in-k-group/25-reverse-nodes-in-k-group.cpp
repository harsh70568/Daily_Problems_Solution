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
            count++;
            head = head->next;
        }
        return count;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next;
        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
            if(count == k) break;
        }
        
        if(length(next) >= k)
        {
            head->next = reverseKGroup(next,k);
        }
        else
        {
            head->next = next;
        }
        return prev;
    }
};