class Solution {
public:
    int solve(int i, int j,int m, int n, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if(i > m-1 || j > n-1) return 1e9;
        if(i == m-1 && j == n-1) return grid[i][j];
        
        if(dp[i][j] != -1) return dp[i][j];
        int down = grid[i][j] + solve(i+1,j,m,n,grid,dp);
        int right = grid[i][j] + solve(i,j+1,m,n,grid,dp);
        
        return dp[i][j] = min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m+1,-1));
        
        
        return solve(0,0,n,m,grid,dp);
    }
};