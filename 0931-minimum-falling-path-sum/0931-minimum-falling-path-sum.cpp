class Solution {
public:
    int solve(int i, int j, vector<vector<int>> &matrix, int m, int n, vector<vector<int>> &dp)
    {
        if(i < 0 || i >= m || j < 0 || j >= n) return 1e9;
        if(i == m-1) return matrix[i][j];
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int left_diagonal = matrix[i][j] + solve(i+1, j-1, matrix, m, n, dp);
        int down = matrix[i][j] + solve(i+1, j, matrix, m, n, dp);
        int right_diagonal = matrix[i][j] + solve(i+1, j+1, matrix, m, n, dp);
        
        return dp[i][j] = min({left_diagonal, down, right_diagonal});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> dp(m+1, vector<int>(n+1,-1));
        int mini = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            mini = min(mini, solve(0, i, matrix, m, n, dp));
        }
        
        return mini;
    }
};