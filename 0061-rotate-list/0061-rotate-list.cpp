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
        if(head == NULL || head->next == NULL) return head;
        int len = length(head);
        k = k % len;
        int move = len - k;
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(move--)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = NULL;
        
        ListNode* h1 = reverse(head);
        curr = reverse(curr);
        
        head->next = curr;
        head = reverse(h1);
        return head;
    }
};