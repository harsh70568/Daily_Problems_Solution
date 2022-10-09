class Solution {
public:
    int mod = 1e9+7;
    int solve(int i, int j, vector<vector<int>> &grid, int m, int n, vector<vector<int>> &dp)
    {
        
        if(i < 0 || j < 0 || i > m-1 || j > n-1) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        int right = 0;
        int left = 0;
        int down = 0;
        int up = 0;
        
        if(j < n-1 && grid[i][j+1] > grid[i][j])
        {
            right = 1 + solve(i, j+1, grid, m, n, dp);
        }
        if(j > 0 && grid[i][j-1] > grid[i][j])
        {
            left = 1 + solve(i, j-1, grid, m, n, dp);
        }
        if(i < m-1 && grid[i+1][j] > grid[i][j])
        {
            down = 1 + solve(i+1, j, grid, m, n, dp);
        }
        if(i > 0 && grid[i-1][j] > grid[i][j])
        {
            up = 1 + solve(i-1, j, grid, m, n, dp);
        }
        
        return dp[i][j] = (right + left + down + up) % mod;
    }
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int total = 0;
        vector<vector<int>> dp(m+1, vector<int>(n+1,-1));
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                total += solve(i, j, grid, m, n, dp);
                total %= mod;
            }
        }
        
        return total + (m*n);
    }
};