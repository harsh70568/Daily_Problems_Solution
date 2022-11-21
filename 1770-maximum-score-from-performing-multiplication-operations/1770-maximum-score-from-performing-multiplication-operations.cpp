class Solution {
public:
    int solve(int i, int j, int k, vector<int> &nums, vector<int> &multi, vector<vector<int>> &dp)
    {
        if(k == multi.size()) return 0;
        
        if(dp[k][i] != -1) return dp[k][i];
        
        
        return dp[k][i] = max(nums[i]*multi[k] + solve(i+1, j, k+1, nums, multi, dp), nums[j]*multi[k] + solve(i, j-1, k+1, nums, multi, dp));
        
        
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size();
        int m = multipliers.size();
        vector<vector<int>> dp(m, vector<int>(m+1,-1));
        return solve(0, n-1, 0, nums, multipliers, dp);
    }
};