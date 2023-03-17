class Solution {
public:
    int lcs(int i, int j, string &str1, string &str2, vector<vector<int>> &dp)
	{
	    if(i < 0 || j < 0) return 0;
	    
	    if(dp[i][j] != -1) return dp[i][j];
	    
	    if(str1[i] == str2[j])
	    {
	        return dp[i][j] = 1 + lcs(i-1, j-1, str1, str2, dp); 
	    }
	    else
	    {
	        return dp[i][j] = max(lcs(i, j-1, str1, str2, dp), lcs(i-1, j, str1, str2, dp));
	    }
	}
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        int ans = lcs(n-1, m-1, word1, word2, dp);
        cout<<ans<<endl;
        return (n + m) - (2*ans);
    }
};