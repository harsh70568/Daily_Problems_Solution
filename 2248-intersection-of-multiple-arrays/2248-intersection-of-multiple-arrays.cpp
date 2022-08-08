class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> ans;
       int n = nums.size();
        unordered_map<int,int> mpp;
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = 0; j < nums[i].size(); j++)
            {
                mpp[nums[i][j]]++;
            }
        }
        
        
        for(auto &it : mpp)
        {
            if(it.second == n)
            {
                ans.push_back(it.first);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};