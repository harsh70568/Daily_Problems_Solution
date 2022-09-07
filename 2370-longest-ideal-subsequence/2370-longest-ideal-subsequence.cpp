class Solution {
public:
    int solve(int index, int prev, string &s, int &k, vector<vector<int>> &dp)
    {
        if(index >= s.length()) return 0;
        if(dp[index][prev] != -1) return dp[index][prev];
        int not_pick = 0 + solve(index+1,prev,s,k,dp);
        
        int pick = 0;
        if(prev == 0 || abs(s[index] - prev) <= k)
        {
            pick = 1 + solve(index+1,s[index],s,k,dp);
        }
        
        return dp[index][prev] = max(pick,not_pick);
    }
    int longestIdealString(string s, int k) {
        int n = s.length();
        vector<vector<int>> dp(n+1, vector<int>(150,-1));
        return solve(0,0,s,k,dp);
    }
};