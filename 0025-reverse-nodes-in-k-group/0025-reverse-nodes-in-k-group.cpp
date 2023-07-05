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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next;
        int cnt = 0;
        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            cnt++;
            if(cnt == k) break;
        }
        
        if(length(next) < k)
        {
            head->next = next;
        }
        else
        {
            head->next = reverseKGroup(next, k);
        }
        return prev;
        
    }
};