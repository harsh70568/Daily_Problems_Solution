class Solution {
public:
    int solve(int i, int j, int k, vector<int> &nums, vector<int> &multipliers, vector<vector<int>> &dp)
    {
        if(k == multipliers.size()) return 0;
        
        if(dp[i][k] != -1) return dp[i][k];
        
        int pick_front = nums[i]*multipliers[k] + solve(i+1, j, k+1, nums, multipliers, dp);
        int pick_back = nums[j]*multipliers[k] + solve(i, j-1, k+1, nums, multipliers, dp);
        
        return dp[i][k] = max(pick_front, pick_back);
    }
    int maximumScore(vector<int>& nums, vector<int>& multi) {
        int n = nums.size();
        int m = multi.size();
        vector<vector<int>> dp(m, vector<int>(m+1,-1));
        return solve(0, n-1, 0, nums, multi, dp);
    }
};