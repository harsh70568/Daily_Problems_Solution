class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        int ans = INT_MIN;
        int zero_count = 0;
        while(j < nums.size())
        {
            if(nums[j] == 0)
            {
                zero_count++;
                while(zero_count > k)
                {
                    if(nums[i] == 0)
                    {
                        zero_count--;
                    }
                    i++;
                }
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};