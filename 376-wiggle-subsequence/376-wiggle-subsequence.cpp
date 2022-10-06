class Solution {
public:
    int solve(int index, vector<int> &nums, int prev_index, bool flag, vector<vector<vector<int>>> &dp)
    {
        if(index == nums.size()) return 0;
        
        if(dp[index][prev_index+1][flag] != -1) return dp[index][prev_index+1][flag];
        
        int take = INT_MIN;
        int not_take = 0 + solve(index+1, nums, prev_index, flag, dp);
        if(prev_index == -1 || (flag == 1 && nums[index] - nums[prev_index] < 0) || (flag == 0 && nums[index] - nums[prev_index] > 0))
        {
            take = 1 + solve(index+1, nums, index, !flag, dp);
        }
        
        return dp[index][prev_index+1][flag] = max(take,not_take);
    }
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n+1, vector<int>(2,-1)));
        return max(solve(0, nums, -1, false, dp),solve(0,nums, -1, true, dp));  
    }
};