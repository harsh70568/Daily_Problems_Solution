class Solution {
public:
    int solve(int index, int n, vector<int> &nums, vector<vector<int>> &dp)
    {
        if(index == 0)
        {
            return n;
        }
        
        if(dp[index][n] != -1) return dp[index][n];
        
        int not_pick = 0 + solve(index-1, n, nums, dp);
        int pick = 1e9;
        if(nums[index] <= n)
        {
            pick = 1 + solve(index, n - nums[index], nums, dp);
        }
        
        return dp[index][n] = min(pick, not_pick);
    }
    int numSquares(int n) {
        vector<int> ans;
        for(int i = 1; i <= sqrt(n); i++)
        {
            ans.push_back(pow(i,2));
        }
        vector<vector<int>> dp(ans.size(), vector<int>(n+1,-1));
        return solve(ans.size()-1, n, ans, dp);
    }
};