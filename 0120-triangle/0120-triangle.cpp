class Solution {
public:
    int solve(int i, int j, vector<vector<int>> &grid, int m, vector<vector<int>> &dp)
    {
        if(i == m-1) return grid[i][j];
        
        if(dp[i][j] != -1) return dp[i][j];
        int left = grid[i][j] + solve(i+1, j, grid, m, dp);
        int right = grid[i][j] + solve(i+1, j+1, grid, m, dp);
        
        return dp[i][j] = min(left, right);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp(m, vector<int>(m+1,-1));
        
        return solve(0, 0, triangle, m, dp);
    }
};