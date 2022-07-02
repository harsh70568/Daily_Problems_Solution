class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        vector<int> temp;
        for(int i = 0; i < nums.size(); i++)
        {
            mpp[nums[i]]++;
        }
        vector<pair<int,int>> ans;
        
        for(auto it : mpp)
        {
            ans.push_back({it.second,it.first});
        }
        
        sort(ans.begin(),ans.end());
        reverse(ans.begin(),ans.end());
        
        for(auto it : ans)
        {
            if(k == 0) return temp;
            temp.push_back(it.second);
            k--;
        }
        return temp;
    }
};