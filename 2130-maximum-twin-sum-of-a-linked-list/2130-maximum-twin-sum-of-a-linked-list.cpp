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
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
        ListNode* next;
        int max_sum = -1;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        while(slow)
        {
            next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        while(head && prev)
        {
            int sum = head->val + prev->val;
            max_sum = max(max_sum,sum);
            head = head->next;
            prev = prev->next;
        }
        return max_sum;
    }
};