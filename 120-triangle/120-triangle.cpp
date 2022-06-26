class Solution {
public:
    int recursion(vector<vector<int>> &triangle,int n,int m,vector<vector<int>>&dp) {
        if(n==triangle.size()-1) return dp[n][m]=triangle[n][m];
        if(dp[n][m]!=-1) return dp[n][m];
        int ans1=triangle[n][m]+recursion(triangle,n+1,m,dp);
        int ans2=triangle[n][m]+recursion(triangle,n+1,m+1,dp);
        return dp[n][m]=min(ans1,ans2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle[n-1].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return recursion(triangle,0,0,dp);
        
        
    }
};