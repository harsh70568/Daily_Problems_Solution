class Solution {
public:
    int solve(int index, vector<int> &val, int n, vector<vector<int>> &dp)
    {
        if(index == 0)
        {
            if(val[0] <= n) return 1;
            else return -1e9;
        }
        
        if(dp[index][n] != -1) return dp[index][n];
        
        int not_pick = solve(index-1, val, n, dp);
        int pick = 1;
        if(val[index] <= n)
        {
            pick = max(solve(index-1, val, n, dp), val[index] * solve(index, val, n - val[index], dp));
        }
        
        return dp[index][n] = max(pick, not_pick);
    }
    int integerBreak(int n) {
        vector<int> val;
        for(int i = 1; i <= n-1; i++)
        {
            val.push_back(i);
        }
        
        //for(auto it : val) cout<<it<<" ";
        vector<vector<int>> dp(n, vector<int>(n+1,-1));
        return solve(n-2, val, n, dp);
        
    }
};