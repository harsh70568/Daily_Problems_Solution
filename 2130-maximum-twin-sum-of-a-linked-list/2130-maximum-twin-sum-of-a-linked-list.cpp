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
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* head2 = slow->next;
        slow->next = NULL;
        
        head2 = reverse(head2);
        
        int max_sum = -1;
        while(head && head2)
        {
            max_sum = max(max_sum, head->val + head2->val);
            head = head->next;
            head2 = head2->next;
        }
        
        return max_sum;
    }
};