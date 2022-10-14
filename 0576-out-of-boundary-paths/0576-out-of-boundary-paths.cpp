class Solution {
public:
    int dp[52][52][52];
    long long mod = 1e9+7;
    int solve(int i, int j, int m, int n, int moves)
    {
        if(i > m-1 || j > n-1 || j < 0 || i < 0) return 1;
        
        if(moves <= 0) return 0;
        
        if(dp[i][j][moves] != -1) return dp[i][j][moves];
        
        int left = solve(i, j-1, m, n, moves-1) % mod;
        int right = solve(i, j+1, m, n, moves-1) % mod;
        int down = solve(i+1, j, m, n, moves-1) % mod;
        int up = solve(i-1, j, m, n, moves-1) % mod;
        
        return dp[i][j][moves] = (left % mod + right % mod + down % mod + up % mod) % mod;
        
        
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
        return solve(startRow, startColumn, m, n, maxMove);
    }
};