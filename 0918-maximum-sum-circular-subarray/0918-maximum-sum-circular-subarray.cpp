class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // max subarray sum in normal subarray (just to held the case when all the elements are negative)
        int curr_sum = 0;
        int max_sum = INT_MIN;
        int total_sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            total_sum += nums[i];
            curr_sum += nums[i];
            
            if(curr_sum > max_sum)
            {
                max_sum = curr_sum;
            }
            
            if(curr_sum < 0) curr_sum = 0;
        }
        
        // total_sum - min_subarray_sum
        curr_sum = 0;
        int min_sum = INT_MAX;
        for(int i = 0; i < nums.size(); i++)
        {
            curr_sum += nums[i];
            
            if(curr_sum < min_sum)
            {
                min_sum = curr_sum;
            }
            
            if(curr_sum > 0) curr_sum = 0;
        }
        int ans = total_sum - min_sum;
        if(ans == 0) return max_sum;
        return max(ans, max_sum);
        
    }
};