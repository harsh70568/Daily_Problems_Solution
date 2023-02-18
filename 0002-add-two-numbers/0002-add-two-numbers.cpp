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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = length(l1);
        int len2 = length(l2);
        
        if(len2 > len1)
        {
            ListNode* temp = l1;
            l1 = l2;
            l2 = temp;
        }
        
        int carry = 0;
        int val;
        ListNode* head = l1;
        ListNode* prev = NULL;
        while(l1 || l2)
        {
            val = l1->val + carry;
            if(l2) val += l2->val;
            l1->val = val%10;
            carry = val / 10;
            prev = l1;
            l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        
        if(carry == 1)
        {
            ListNode* new_node = new ListNode(1);
            prev->next = new_node;
        }
        
        return head;
    }
};