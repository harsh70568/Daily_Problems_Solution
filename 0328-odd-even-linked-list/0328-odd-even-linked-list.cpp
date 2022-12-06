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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* even = NULL;
        ListNode* e = NULL;
        
        ListNode* odd = NULL;
        ListNode* o = NULL;
        
        bool flag = true;
        while(head)
        {
            ListNode* temp = new ListNode(head->val);
            if(flag)
            {
                if(even == NULL)
                {
                    even = temp;
                    e = temp;
                }
                else
                {
                    e->next = temp;
                    e = temp;
                }
            }
            else
            {
                if(odd == NULL)
                {
                    odd = temp;
                    o = temp;
                }
                else
                {
                    o->next = temp;
                    o = temp;
                }
            }
            head = head->next;
            flag = !flag;
        }
        
        e->next = odd;
        return even;
    }
};