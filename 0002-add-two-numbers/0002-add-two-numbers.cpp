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
        int cnt = 0;
        while(head)
        {
            cnt++;
           head = head->next;
        }
        return cnt;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* first = l1;
        ListNode* f = l1;
    
        ListNode* second = l2;
        ListNode* s = l2;
        int len1 = length(l1);
        int len2 = length(l2);
        
        if(len2 > len1)
        {
            first = l2;
            f = l2;
            second = l1;
            s = l1;
        }
        
        int fd = 0;
        int sd = 0;
        int carry = 0;
        ListNode* prev = NULL;
        while(first)
        {
            if(first) fd = first->val;
            else fd = 0;
            if(second) sd = second->val;
            else sd = 0;
            
            int val = fd + sd + carry;
            first->val = val % 10;
            carry = val / 10;
            
            prev = first;
            first = first->next;
            if(second) second = second->next;
        }
        
        if(carry == 1)
        {
            ListNode* new_node = new ListNode(1);
            prev->next = new_node;
        }
        
        return f;
        
    }
};