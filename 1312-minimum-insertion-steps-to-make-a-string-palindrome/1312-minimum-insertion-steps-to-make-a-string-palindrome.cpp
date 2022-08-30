class Solution {
public:
    int solve(int i, int j, string &s, string &t, vector<vector<int>> &dp)
    {
        if(i < 0 || j < 0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i] == t[j])
        {
            return 1 + solve(i-1,j-1,s,t,dp);
        }
        
        return dp[i][j] = max(solve(i-1,j,s,t,dp),solve(i,j-1,s,t,dp));
    }
    int minInsertions(string s) {
        string t = s;
        reverse(t.begin(),t.end());
        
        int n = s.length();
        
        vector<vector<int>> dp(n, vector<int> (n+1,-1));
        
        return n - solve(n-1,n-1,s,t,dp);
    }
};