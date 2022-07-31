class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        long long curr_count = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)
            {
                curr_count++;
            }
            else
            {
                ans += curr_count*(curr_count+1)/2;
                curr_count = 0;
            }
        }
        ans += curr_count*(curr_count+1)/2;
        return ans;
    }
};