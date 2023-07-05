class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int cnt = 0;
        int i = 0;
        int j = 0;
        
        int maxi = 0;
        while(j < nums.size())
        {
            if(nums[j] == 0)
            {
                cnt++;
            }
            
            if(cnt <= 1)
            {
                maxi = max(maxi, j-i);
                j++;
            }
            else
            {
                while(cnt > 1)
                {
                    if(nums[i] == 0) cnt--;
                    i++;
                }
                j++;
            }
        }
        return maxi;
    }
};