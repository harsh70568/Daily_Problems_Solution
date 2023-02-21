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
        int c = 0;
        while(head)
        {
            c++;
            head = head->next;
        }
        
        return c;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next;
        int cnt = 0;
        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            cnt++;
            if(cnt == k) break;
        }
        
        if(length(next) >= k)
        {
            head->next = reverseKGroup(next, k);
        }
        else
        {
            head->next = next;
        }
        
        return prev;
    }
};