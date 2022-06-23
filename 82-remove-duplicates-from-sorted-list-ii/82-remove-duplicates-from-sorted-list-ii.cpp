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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0,head);
        ListNode* temp = dummy;
        ListNode* curr = head;
        while(curr)
        {
            bool is_duplicate = false;
            while(curr->next && curr->val == curr->next->val)
            {
                curr = curr->next;
                is_duplicate = true;
            }
            if(is_duplicate)
            {
                temp->next = curr->next;
                curr = temp->next;
            }
            else
            {
                temp = curr;
                curr = curr->next;
            }
        }
        return dummy->next;
    }
};