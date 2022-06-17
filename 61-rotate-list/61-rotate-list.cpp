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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return NULL;
        int size = length(head);
        k = k % size;
        int move_req = size - k;
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(move_req--)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = NULL;
        curr = reverse(curr);
        prev = reverse(head);
        
        head->next = curr;
        
        head = reverse(prev);
        return head;
        
    }
};