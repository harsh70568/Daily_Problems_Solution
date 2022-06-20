class Solution {
public:
    int solve(vector<vector<int>> &dp,int i, int j, int m, int n)
    {
        if(i == m-1 && j == n-1) return 1;
        if(i > m-1 || j > n-1) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        return dp[i][j] = solve(dp,i+1,j,m,n) +  solve(dp,i,j+1,m,n);   
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int i = 0;
        int j = 0;
        return solve(dp,i,j,m,n);
    }
};