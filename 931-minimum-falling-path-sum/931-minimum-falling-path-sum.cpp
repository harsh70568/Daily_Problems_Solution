class Solution {
public:
    int solve(int i, int j, int m , int n, vector<vector<int>> &matrix, vector<vector<int>> &dp)
    {
        if(j < 0 || j > m-1) return 1e9+8;
        if(i == m-1) return matrix[i][j];
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int down = matrix[i][j] + solve(i+1,j,m,n,matrix,dp);
        int left = matrix[i][j] + solve(i+1,j-1,m,n,matrix,dp);
        int right = matrix[i][j] + solve(i+1,j+1,m,n,matrix,dp);
        
        return dp[i][j] = min(down,min(left,right));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int mini = INT_MAX;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i = 0; i < m; i++)
        {
            mini = min(mini, solve(0,i, m,n, matrix,dp));
        }
        
        return mini;
    }
};