class Solution {
public:
    int solve(vector<vector<int>> &grid,int m, int n, int i, int j,vector<vector<int>> &dp)
    {
        if(i == m-1 && j == n-1)
        {
            return grid[i][j];
        }
        if(i > m-1 || j > n-1) return INT_MAX;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = grid[i][j] + min(solve(grid,m,n,i+1,j,dp),solve(grid,m,n,i,j+1,dp));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int i = 0;
        int j = 0;
        return solve(grid,m,n,i,j,dp);
    }
};