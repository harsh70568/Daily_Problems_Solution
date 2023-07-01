class Solution {
public:
    int solve(int i, int j, string &word1, string &word2, vector<vector<int>> &dp)
    {
        if(i < 0) return j+1;
        else if(j < 0) return i+1;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        
        if(word1[i] == word2[j]) return solve(i-1, j-1, word1, word2, dp);
        else
        {
            int insert = 1 + solve(i, j-1, word1, word2, dp);
            int del = 1 + solve(i-1, j, word1, word2, dp);
            int rep = 1 + solve(i-1, j-1, word1, word2, dp);
            
            return dp[i][j] = min({insert, del, rep});
        }
    }
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1,-1));
        return solve(m-1, n-1, word1, word2, dp);
    }
};