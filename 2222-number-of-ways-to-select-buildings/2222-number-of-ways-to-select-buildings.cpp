class Solution {
public:
    long long dp[100001][3][4];
    long long solve(int i, int prev_ch, string &s, int size)
    {
        if(size == 3) return 1;
        if(i == s.length()) return 0;

        
        if(dp[i][prev_ch][size] != -1) return dp[i][prev_ch][size];
        
        long long not_take = solve(i+1, prev_ch, s, size);
        long long take = 0;
        if(s[i]-'0' != prev_ch)
        {
            take = solve(i+1, s[i]-'0', s, size+1);
        }
        
        return dp[i][prev_ch][size] = take + not_take;
    }
    long long numberOfWays(string s) {
        int n = s.size();
        long long size = 0;
        memset(dp, -1, sizeof(dp));
        return solve(0, 2, s, size);
    }
};