class Solution {
public:
    int solve(int i, int j, vector<vector<int>> &grid, int m, int n, vector<vector<int>> &dp)
    {
        // base case
        if(i >= m ||j >= n) return 1e9;
        if(i == m-1 && j == n-1) return grid[i][j];
        
        if(dp[i][j] != -1) return dp[i][j];
            
        // choices
        int right = grid[i][j] + solve(i, j+1, grid, m, n, dp);
        int down = grid[i][j] + solve(i+1, j, grid, m, n, dp);
        
        // returning minimum sum
        return dp[i][j] = min(right, down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return solve(0, 0, grid, m, n, dp);
    }
};