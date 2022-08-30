class Solution {
public:
    int solve(int i, int j, string &word1, string &word2, vector<vector<int>> &dp)
    {
        if(i < 0 || j < 0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        if(word1[i] == word2[j])
        {
            return 1 + solve(i-1,j-1,word1,word2,dp);
        }
        
        return dp[i][j] = max(solve(i-1,j,word1,word2,dp),solve(i,j-1,word1,word2,dp));
    }
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n, vector<int>(m+1,-1));
        int ans = solve(n-1,m-1,word1,word2,dp);
        return (n - ans) + (m - ans);
    }
};