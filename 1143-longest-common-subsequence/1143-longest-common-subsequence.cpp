class Solution {
public:
    int solve(int i, int j, string &text1, string &text2, int m, int n, vector<vector<int>> &dp)
    {
        if(i < 0 || j < 0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(text1[i] == text2[j])
        {
            return dp[i][j] = 1 + solve(i-1, j-1, text1, text2, m, n, dp);
        }
        else
        {
            return dp[i][j] = max(solve(i, j-1, text1, text2, m, n, dp), solve(i-1, j, text1, text2, m, n, dp));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        
        vector<vector<int>> dp(m+1, vector<int>(n+1,-1));
        return solve(m-1, n-1, text1, text2, m, n, dp);
    }
};