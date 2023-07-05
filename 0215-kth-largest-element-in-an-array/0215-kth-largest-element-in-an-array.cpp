class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        k -= 1;
        while(!pq.empty() && k)
        {
            pq.pop();
            k--;
        }
        
        return pq.top();
    }
};