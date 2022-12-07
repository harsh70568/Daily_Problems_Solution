class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int i = 0;
        int j = 0;
        
        int max_sum = INT_MIN;
        int sum = 0;
        unordered_map<int, int> mpp;
        while(j < nums.size())
        {
            sum += nums[j];
            mpp[nums[j]]++;
            
            if(mpp.size() == j-i+1)
            {
                 max_sum = max(max_sum, sum);
                j++;
            }
            else
            {
                while(mpp.size() != j-i+1)
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