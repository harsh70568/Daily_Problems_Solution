class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++)
        {
            mpp[nums[i]]++;
        }
        
        for(auto it : mpp)
        {
            if(it.second > n/3)
            {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};