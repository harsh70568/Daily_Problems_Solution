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
    ListNode* middle(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* left, ListNode* right)
    {
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        while(left && right)
        {
            if(left->val < right->val)
            {
                curr->next = left;
                left = left->next;
            }
            else
            {
                curr->next = right;
                right = right->next;
            }
            curr = curr->next;
        }
        if(left)
        {
            curr->next = left;
            curr = curr->next;
        }
        if(right)
        {
            curr->next = right;
            curr = curr->next;
        }
        return dummy->next;
    }
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* mid = middle(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = NULL;
        
        left = insertionSortList(left);
        right = insertionSortList(right);
        
        return merge(left,right);
    }
};