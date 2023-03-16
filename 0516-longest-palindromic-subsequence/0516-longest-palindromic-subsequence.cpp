class Solution {
public:
    int solve(int i, int j, string &s1, string &s2, int n, vector<vector<int>> &dp)
    {
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i] == s2[j]) return dp[i][j] = 1 + solve(i-1, j-1, s1, s2, n, dp);
        else return dp[i][j] = max(solve(i, j-1, s1, s2, n, dp), solve(i-1, j, s1, s2, n, dp));
    }
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        string s2 = s;
        reverse(s2.begin(), s2.end());
        
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        return solve(n-1, n-1, s, s2, n, dp);
    }
};