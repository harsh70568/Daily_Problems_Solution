class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0;
        int j = 0;
        
        int zero_cnt = 0;
        int max_len = 0;
        while(j < nums.size())
        {
            if(nums[j] == 0) zero_cnt++;
            
            if(zero_cnt <= 1)
            {
                max_len = max(max_len, j-i);  // j-i so, because exactly one eleement need to be deleted
                j++;
            }
            else
            {
                while(zero_cnt > 1)
                {
                    if(nums[i] == 0) zero_cnt--;
                    i++;
                }
                j++;
            }
        }
        
        return max_len;
    }
};