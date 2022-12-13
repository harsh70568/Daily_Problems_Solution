class Solution {
public:
    int solve(int i, int j, vector<vector<int>> &grid, int m, int n, vector<vector<int>> &dp)
    {
        // base case
        if(j < 0 || j > n-1) return 1e9;
        if(i == m-1) return grid[i][j];
        
        if(dp[i][j] != -1) return dp[i][j];
        
        // recursion calls
        int left = grid[i][j] +  solve(i+1, j-1, grid, m, n, dp);
        int right = grid[i][j] +  solve(i+1, j+1, grid, m, n, dp);
        int down = grid[i][j] + solve(i+1, j, grid, m, n, dp);
        
        // minimum out of all calls
        return dp[i][j] = min({left, right, down});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n+1,-1));
        
        int ans = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            ans = min(ans, solve(0, i, matrix, m, n, dp));
        }
        
        
        return ans;
    }
};