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
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL) return;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
        while(fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        ListNode* new_head = reverse(slow);
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        while(new_head && head)
        {
            curr->next = head;
            head = head->next;
            curr = curr->next;
            
            curr->next = new_head;
            new_head = new_head->next;
            curr = curr->next;
        }
        if(new_head)
        {
            curr->next = new_head;
            curr = curr->next;
        }
        if(head)
        {
             curr->next = head;
            curr = curr->next;
        }
        curr->next = NULL;
        head = dummy->next;
        
    }
};