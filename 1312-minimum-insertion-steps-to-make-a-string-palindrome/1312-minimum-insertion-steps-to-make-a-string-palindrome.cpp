class Solution {
public:
    int lcs(int i, int j, string &s1, string &s2, int n, vector<vector<int>> &dp)
    {
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i] == s2[j]) return dp[i][j] = 1 + lcs(i-1, j-1, s1, s2, n, dp);
        else return dp[i][j] = max(lcs(i, j-1, s1, s2, n, dp), lcs(i-1, j, s1, s2, n, dp));
    }
    int minInsertions(string s) {
        int n = s.length();
        string s1 = s;
        reverse(s1.begin(), s1.end());
        
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        int len = lcs(n-1, n-1, s, s1, n, dp);
        
        return n - len;
        
    }
};