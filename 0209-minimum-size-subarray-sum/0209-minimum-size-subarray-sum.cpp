class Solution {
public:
    int minSubArrayLen(int k, vector<int>& nums) {
        int i = 0;
        int j = 0;
        
        int sum = 0;
        int min_len = 1e9;
        while(j < nums.size())
        {
            sum += nums[j];
            
            while(sum >= k)
            {
                min_len = min(min_len, j-i+1);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        
        return min_len == 1e9 ? 0 : min_len;
    }
};