class Solution {
public:
    bool solve(int i, int j, int k, string a, string b, string c, vector<vector<int>> &dp)
    {
        if(k == c.length()) return true;
        if(dp[i][j] != -1) return dp[i][j];
        
        if(a[i] == c[k] && b[j] == c[k])
        {
            return dp[i][j] = solve(i+1,j,k+1,a,b,c,dp) || solve(i,j+1,k+1,a,b,c,dp);
        }
        else if(a[i] == c[k])
        {
            return dp[i][j] = solve(i+1,j,k+1,a,b,c,dp);
        }
        else if(b[j] == c[k])
        {
            return dp[i][j] = solve(i,j+1,k+1,a,b,c,dp);
        }
        else return dp[i][j] = false;
    }
        
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length();
        int n = s2.length();
        int k = s3.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1,-1));
        if(m+n != k) return false;
        return solve(0,0,0,s1,s2,s3,dp);
    }
};