class Solution {
public:
    
    int lcs(int i, int currSize, int currSum, vector<vector<int>> &dp, string &s, int k)
    {
            if (i<0)    return 0;
            
            if (dp[i][currSize] != -1)  return dp[i][currSize];    

            //  not take
            int c1 = lcs(i - 1, currSize, currSum, dp, s, k) + 0;
            int c2 = 0;
            if (currSum + (s[i]-'0')* pow(2,currSize) <= k)
                c2 = lcs(i - 1, currSize + 1, currSum + (s[i]-'0')* pow(2,currSize), dp, s, k) + 1;
                    
            return dp[i][currSize] = max(c1, c2);
        
    }        
        
        
        
    int longestSubsequence(string s, int k) {
        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(n, -1));
        return lcs(n - 1, 0, 0, dp, s, k);
        
    }
};