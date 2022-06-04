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
    ListNode* findMid(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = slow->next;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode* merge_them(ListNode* left, ListNode* right)
    {
        if(left == NULL) return right;
        if(right == NULL) return left;
        
        ListNode* ans = new ListNode(0);
        ListNode* temp = ans;
        
        while(left && right)
        {
            if(left->val < right->val)
            {
                temp->next = left;
                left = left->next;
            }
            else
            {
                temp->next = right;
                right = right->next;
            }
            temp = temp->next;
        }
        if(left)
        {
            temp->next = left;
            left = left->next;
        }
        if(right)
        {
            temp->next = right;
            right = right->next;
        }
        return ans->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        
        ListNode* mid = findMid(head);
        
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = NULL;
        
        left = sortList(left);
        right = sortList(right);
        
        ListNode* ans = merge_them(left,right);
        
        return ans;
    }
};