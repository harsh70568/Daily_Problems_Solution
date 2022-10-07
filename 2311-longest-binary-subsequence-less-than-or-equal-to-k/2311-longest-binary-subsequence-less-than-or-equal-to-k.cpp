class Solution {
public:
    int solve(int index, int sum, int count, string &s, int k, vector<vector<int>> &dp)
    {
        if(index < 0) return 0;
        if(dp[index][count] != -1) return dp[index][count];
        
        int not_take = 0 + solve(index-1, sum, count, s, k, dp);
        int take = 0;
        if(sum + (s[index] - '0') * pow(2,count) <= k)
        {
            take = 1 + solve(index-1, sum + (s[index] - '0')*pow(2,count), count+1, s, k, dp);
        }
        
        return dp[index][count] = max(take,not_take);
    }
    int longestSubsequence(string s, int k) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n+1,-1));
        return solve(n-1, 0, 0, s, k, dp);
    }
};