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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(length(l2) > length(l1))
        {
            ListNode* temp = l1;
            l1 = l2;
            l2 = temp;
        }
        ListNode* first =  l1;
        ListNode* f = first;
        ListNode* second = l2;
        ListNode* s = second;
        ListNode* temp = NULL;
        int carry = 0;
        int fd = 0;
        int sd = 0;
        while(first)
        {
            if(first)
            {
                fd = first->val;
            }
            else
            {
                fd = 0;
            }
            if(second)
            {
                sd = second->val;
            }
            else
            {
                sd = 0;
            }
            int sum = fd + sd+carry;
            first->val = sum % 10;
            carry = sum / 10;
            temp = first;
            first = first->next;
            if(second) second = second->next;
        }
        if(carry == 1)
        {
            ListNode* new_node = new ListNode(1);
            temp->next = new_node;
        }
        return f;
    }
};