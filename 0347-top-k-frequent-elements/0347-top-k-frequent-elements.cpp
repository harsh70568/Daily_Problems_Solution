class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for(auto it : nums) mpp[it]++;
        
        vector<pair<int, int>> vec;
        for(auto it : mpp)
        {
            vec.push_back({it.second, it.first});
        }
        
        sort(vec.begin(), vec.end());
        
        vector<int> ans;
        int i = vec.size()-1;
        while(i >= 0 && k)
        {
            ans.push_back(vec[i].second);
            i--;
            k--;
        }
        
        return ans;
    }
};