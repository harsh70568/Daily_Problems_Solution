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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        while(slow)
        {
            next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        ListNode* dummy = new ListNode(0);
        ListNode* temp  = dummy;
        while(head && prev)
        {
            temp->next = head;
            head = head->next;
            temp  =temp->next;
            temp->next = prev;
            prev = prev->next;
            temp = temp->next;
        }
        if(prev)
        {
            temp->next = prev;
            prev->next = NULL;
            prev = prev->next;
        }
        head = dummy->next;
        
    }
};