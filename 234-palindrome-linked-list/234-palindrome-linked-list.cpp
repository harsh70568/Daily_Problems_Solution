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
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next)
        {
           
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* start = head;
        ListNode* end = reverse(slow);
        while(end)
        {
            if(start->val != end->val)
            {
                return false;
            }
            start = start->next;
            end = end->next;
        }
        return true;
    }
};