class Solution {
public:
    int solve(int i, int j, vector<vector<int>> &grid, int m, int n, vector<vector<int>> &dp)
    {
        if(i > m-1 || j > n-1) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int first = 0;
        int sec = 0;
        int thi = 0;
        if(i-1 >= 0 && j+1 < n && grid[i-1][j+1] > grid[i][j]) first = 1 + solve(i-1, j+1, grid, m, n, dp);
        if(j+1 < n && grid[i][j+1] > grid[i][j]) sec = 1 + solve(i, j+1, grid, m, n, dp);
        if(i+1 < m && j+1 < n && grid[i+1][j+1] > grid[i][j]) thi = 1 + solve(i+1, j+1, grid, m, n, dp);
        
        return dp[i][j] = max({first, sec, thi});
    }
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int maxi = 0;
        vector<vector<int>> dp(m+1, vector<int>(n+1,-1));
        for(int i = 0; i < m; i++)
        {
            maxi = max(maxi, solve(i, 0, grid, m, n, dp));
        }
        
        return maxi;
    }
};