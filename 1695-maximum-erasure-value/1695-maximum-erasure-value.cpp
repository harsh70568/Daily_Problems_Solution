class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int i = 0;
        int j = 0;
        
        map<int, int> mpp;
        int sum = 0;
        int max_sum = 0;
        
        while(j < nums.size())
        {
            mpp[nums[j]]++;
            sum += nums[j];
            
            if(mpp.size() == j-i+1) // all unique characters
            {
                max_sum = max(max_sum, sum);
                j++;
            }
            else
            {
                while(mpp.size() < j-i+1)
                {
                    sum -= nums[i];
                    mpp[nums[i]]--;
                    if(mpp[nums[i]] == 0) mpp.erase(nums[i]);
                    i++;
                }
                j++;
            }
        }
        
        return max_sum;
    }
};