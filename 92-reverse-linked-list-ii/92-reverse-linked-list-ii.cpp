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
        if(head == NULL || head->next == NULL) return head;
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
      //  if(left == right) return head;
        ListNode* prev_end = NULL;
        ListNode* end = head;
        while(right--)
        {
            prev_end = end;
            end = end->next;
        }
        prev_end->next = NULL;
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        left--;
        bool flag = false;
        while(left--)
        {
            prev = curr;
            curr = curr->next;
            flag = true;
        }
        if(flag == true) prev->next = NULL;
        
        prev_end = reverse(curr);
        if(flag == true) prev->next = prev_end;
        curr->next = end;
        if(flag == false) return prev_end;
        return head;
    }
};