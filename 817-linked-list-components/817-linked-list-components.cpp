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
   
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(auto it : nums)
        {
            mpp[it]++;
        }
        int ans = 0;
        bool flag = true;
        while(head)
        {
            while(head && mpp.find(head->val) != mpp.end())
            {
                head = head->next;
                flag = false;
            }
            if(flag == false)
            {
                ans++;
                flag = !flag;
            }
            if(head) head = head->next;
        }
        return ans;
        
    }
};