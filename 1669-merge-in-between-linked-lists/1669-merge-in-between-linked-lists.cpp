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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* prev = list1;
        ListNode* curr = NULL;
        ListNode* next = list1;
        
        a--;
        b++;
        while(a--)
        {
            prev = prev->next;
        }
        while(b--)
        {
            curr = next;
            next = next->next;
        }
        prev->next = NULL;
        curr->next = NULL;
        
        ListNode* conn = list2;
        while(conn->next)
        {
            conn = conn->next;
        }
        
        prev->next = list2;
        conn->next = next;
        
        return list1;
    }
};