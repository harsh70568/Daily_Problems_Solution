class Solution {
public:
    long long mod = 1e9+7;
    int maximumProduct(vector<int>& nums, int k) {
        long long pro = 1;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < nums.size(); i++)
        {
            pq.push(nums[i]);
        }
        
        while(k--)
        {
            int add = pq.top() + 1;
            pq.pop();
            pq.push(add);
        }
        
        while(!pq.empty())
        {
            pro = (pro % mod)*(pq.top() % mod) % mod;
            pq.pop();
        }
        
        
        return pro % mod;
    }
};