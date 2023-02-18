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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = length(headA);
        int len2 = length(headB);
        
        ListNode* first = NULL;
        ListNode* second = NULL;
        int diff = abs(len1 - len2);
        if(len1 >= len2)
        {
            first = headA;
            second = headB;  
        }
        else
        {
            first = headB;
            second = headA;
        }
        
        while(diff--)
        {
            first = first->next;
        }
        
        //cout<<first->val<<" "<<second->val<<endl;
        while(first && second)
        {
            if(first == second)
            {
                return first;
            }
            first = first->next;
            second = second->next;
        }
        
        return NULL;
    }
};