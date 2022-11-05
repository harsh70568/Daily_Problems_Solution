class Solution {
public:
    long long solve(int index, bool flag, vector<int> &nums, vector<vector<long long>> &dp)
    {
        if(index == nums.size()) return 0;
        
        if(dp[index][flag] != -1) return dp[index][flag];
        
        long long profit = 0;
        if(flag) // if you are at even index
        {
            profit = max(nums[index] + solve(index+1, false, nums, dp), solve(index+1, true, nums, dp));
        }
        else // if you are at odd index
        {
            profit = max(-nums[index] + solve(index+1, true, nums, dp), solve(index+1, false, nums, dp));
        }
        
        return dp[index][flag] = profit;
    }
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> dp(n, vector<long long>(2,-1));
        return solve(0, true, nums, dp);
    }
};