class Solution {
public:
   
    int solve(int i, vector<int> &ans, int sum, vector<vector<int>> &dp)
    {
        if(i == 0)
        {
            if(sum % ans[i] == 0) return pow(ans[i],sum/ans[i]); 
        }
        
        if(dp[i][sum] != -1) return dp[i][sum];
        
        int not_pick = solve(i-1, ans, sum, dp);
        int pick = -1e9;
        if(ans[i] <= sum)
        {
            pick = ans[i]*solve(i, ans, sum - ans[i], dp);
        }
        
        return dp[i][sum] = max(pick, not_pick);
    }
    int integerBreak(int n) {
        vector<int> ans;
        for(int i = 1; i < n; i++)
        {
            ans.push_back(i);
        }
        vector<vector<int>> dp(n, vector<int>(n+1,-1));
        return solve(n-2, ans, n, dp);
        
    }
};