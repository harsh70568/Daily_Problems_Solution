class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int curr_sum = 0;
        int max_sum = INT_MIN;
        for(int i = 0; i < nums.size(); i++)
        {
            curr_sum += nums[i];
            max_sum = max(max_sum, curr_sum);
            
            if(curr_sum < 0) curr_sum = 0;
        }
        
        int min_sum = INT_MAX;
        curr_sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            curr_sum += nums[i];
            min_sum = min(min_sum, curr_sum);
            
            if(curr_sum > 0) curr_sum = 0;
        }
        
        return max(max_sum, -1*min_sum);
    }
};