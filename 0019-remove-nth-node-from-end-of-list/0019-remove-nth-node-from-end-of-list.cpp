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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = length(head);
        int move = len - n;
        if(move == 0) return head->next;
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        while(move--)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        
        return head;
    }
};