class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        map<int, int> mpp;
        for(auto it : nums) mpp[it]++;
        
        priority_queue<pair<int, int>> pq;
        for(auto it : mpp)
        {
            pq.push({it.second, it.first});
        }
        
        while(!pq.empty() && k)
        {
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        
        return ans;
    }
};