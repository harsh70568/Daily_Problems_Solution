class Solution {
public:
    int solve(int i, int j, vector<vector<int>> &grid, int m, int n, vector<vector<int>> &dp)
    {
        if(i == m && j == n-1) return 0;
        if(i < 0 || i > m-1 || j < 0 || j > n-1) return 1e9;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int down = grid[i][j] + solve(i+1, j, grid, m, n, dp);
        int right = grid[i][j] + solve(i, j+1, grid, m, n, dp);
        
        return dp[i][j] = min(down, right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1,-1));
        return solve(0, 0, grid, m, n, dp);
    }
};