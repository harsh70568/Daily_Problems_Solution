class Solution {
public:
    bool solve(int index, string &s, int open, int close, vector<vector<vector<int>>> &dp)
    {
        if(close > open) return false;
        if(index == s.length()) return open == close;
        
        if(dp[index][open][close] != -1) return dp[index][open][close];
            
        if(s[index] == '(')
        {
            return dp[index][open][close] = solve(index+1, s, open+1, close, dp);
        }
        
        if(s[index] == ')')
        {
            return dp[index][open][close] = solve(index+1, s, open, close+1, dp);
        }
        
        if(s[index] == '*')
        {
            int choice_1 = solve(index+1, s, open+1, close, dp);
            int choice_2 = solve(index+1, s, open, close+1, dp);
            int choice_3 = solve(index+1, s, open, close, dp);
            
            return dp[index][open][close] = choice_1 | choice_2 | choice_3;
        }
        
        return dp[index][open][close] = false;
    }
    bool checkValidString(string s) {
        int n = s.length();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n+1, vector<int> (n+1,-1)));
        return solve(0, s, 0, 0, dp);
    }
};