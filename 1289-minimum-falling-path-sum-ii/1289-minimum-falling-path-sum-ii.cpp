class Solution {
public:
    int solve(int i, int j, int m, int n, vector<vector<int>> &matrix, vector<vector<int>> &dp)
    {
        if(i == m-1) return matrix[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        
        int mini = INT_MAX;
        for(int col = 0; col < n; col++)
        {
            if(col != j)
            {
                mini = min(mini, matrix[i][j] + solve(i+1,col,m,n,matrix,dp));
            }
        }
        
        return dp[i][j] = mini;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n,-1));
        
        int mini = INT_MAX;
        
        for(int i = 0; i < n; i++)
        {
            mini = min(mini, solve(0,i,m,n,grid,dp));
        }
        
        return mini;
    }
};