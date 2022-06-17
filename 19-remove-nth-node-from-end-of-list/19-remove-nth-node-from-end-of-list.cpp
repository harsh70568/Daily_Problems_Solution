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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = length(head);
        int d = size - n;
        ListNode* curr = head;
        ListNode* prev = NULL;
        if(d == 0) return curr->next;
        while(d--)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        return head;
    }
};