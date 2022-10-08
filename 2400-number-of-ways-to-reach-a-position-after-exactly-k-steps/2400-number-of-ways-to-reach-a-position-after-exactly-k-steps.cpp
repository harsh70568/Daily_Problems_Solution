class Solution {
public:
    int dp[3005][1005];
    long long mod = 1e9+7;
    int solve(int index, int k, int endPos)
    {
        if(k == 0)
        {
            if(index == endPos) return 1;
            else return 0;
        }
        
        if(dp[index+1000][k] != -1) return dp[index + 1000][k];
        
        int right = solve(index+1, k-1, endPos) % mod;
        int left = solve(index-1, k-1, endPos) % mod;
        
        return dp[index+1000][k] = (right + left) % mod;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(startPos, k, endPos);
    }
};