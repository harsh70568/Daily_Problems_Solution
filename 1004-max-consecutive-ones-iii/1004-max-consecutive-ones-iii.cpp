class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        
        int zero_cnt = 0;
        int max_len = 0;
        while(j < nums.size())
        {
            if(nums[j] == 0) zero_cnt++;
            
            if(zero_cnt <= k)
            {
                max_len = max(max_len, j-i+1);
                j++;
            }
            else
            {
                while(zero_cnt > k)
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