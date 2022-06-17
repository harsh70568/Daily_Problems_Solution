class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int pre_sum = 0;
        int count = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            pre_sum += nums[i];
            
            if(pre_sum == k) count++;
            
            if(mpp.find(pre_sum-k) != mpp.end())
            {
                count += mpp[pre_sum-k];
            }
            mpp[pre_sum]++;
        }
        return count;
    }
};