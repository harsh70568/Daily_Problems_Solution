class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        vector<int> ans;
        
        unordered_map<int,int> mpp;
        
        for(int i = 0; i < nums.size(); i++)
        {
            mpp[nums[i]]++;
        }
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(mpp[nums[i]] == 1 && mpp.find(nums[i] + 1) == mpp.end() && mpp.find(nums[i] - 1) == mpp.end())
            {
                ans.push_back(nums[i]);
            }
        }
        
        
        return ans;
    }
};