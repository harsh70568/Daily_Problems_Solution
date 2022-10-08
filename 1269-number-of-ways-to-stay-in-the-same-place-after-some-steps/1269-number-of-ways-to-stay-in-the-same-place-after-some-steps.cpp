class Solution {
public:

    long long mod = 1e9+7;
    int dp[2005][1005];
    int solve(int index, int steps, int arrLen)
    {
        if(index < 0 || index > arrLen-1) return 0;
        if(steps == 0)
        {
            if(index == 0) return 1;
            else return 0;
        }
        
        if(dp[index][steps] != -1) return dp[index][steps];
        
        long long right = solve(index+1, steps-1, arrLen) % mod;
        long long left = solve(index-1, steps-1, arrLen) % mod;
        long long stay = solve(index, steps-1, arrLen) % mod;
        
        return dp[index][steps] = (right + left + stay) % mod;
    }
    int numWays(int steps, int arrLen) {
        memset(dp, -1, sizeof(dp));
        return solve(0, steps, arrLen);
    }
};