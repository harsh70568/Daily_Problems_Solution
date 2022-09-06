class Solution {
public:
    int solve(int i, int j, vector<int> &values, vector<vector<int>> &dp)
    {
        if(i == j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int mini = INT_MAX;
        for(int k = i; k <= j-1; k++)
        {
            int steps = values[i-1] * values[k] * values[j] + solve(i,k,values,dp) + solve(k+1,j,values,dp);
            mini = min(mini,steps);
        }
        
        return dp[i][j] = mini;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        
        vector<vector<int>> dp(n, vector<int> (n,-1));
        
        return solve(1,n-1,values,dp);
    }
};