/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int length(ListNode * head)
    {
        int count = 0;
        while(head)
        {
            count++;
            head = head->next;
        }
        return count;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* ptr1 = NULL;
        ListNode* ptr2 = NULL;
        if(length(headA) > length(headB))
        {
            ptr1 = headA;
            ptr2 = headB;
        }
        else
        {
            ptr1 = headB;
            ptr2 = headA;
        }
        int d = abs(length(headA) - length(headB));
        while(d--)
        {
            ptr1 = ptr1->next;
        }
        while(ptr1 && ptr2)
        {
            if(ptr1 == ptr2)
            {
                return ptr1;
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return NULL;
    }
};