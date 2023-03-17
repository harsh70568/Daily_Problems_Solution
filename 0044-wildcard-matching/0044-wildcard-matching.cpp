class Solution {
public:
    int solve(int i, int j, string &str1, string &str2, vector<vector<int>> &dp)
    {
        if(i < 0 && j < 0) return 1;
        if(j < 0 && i >= 0) return 0;
        if(i < 0 && j >= 0)
        {
            for(int k = 0; k <= j; k++)
            {
                if(str2[k] != '*') return 0;
            }
            return 1;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(str1[i] == str2[j] || str2[j] == '?')
        {
            return dp[i][j] = solve(i-1, j-1, str1, str2, dp);
        }
        if(str2[j] == '*')
        {
            return dp[i][j] = solve(i-1, j, str1, str2, dp) || solve(i, j-1, str1, str2, dp);
        }
        
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        return solve(n-1, m-1, s, p, dp);
    }
};