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
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;
        ListNode* prev = NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        prev->next = NULL;
        ListNode* head2 = reverse(slow);
        
        while(head && head2)
        {
            if(head->val != head2->val) return false;
            head = head->next;
            head2 = head2->next;
        }
        
        return true;
    }
};