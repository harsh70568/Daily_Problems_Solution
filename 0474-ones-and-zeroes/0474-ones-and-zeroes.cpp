class Solution {
public:
    int count_one(string s)
    {
        int cnt = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '1') cnt++;
        }
        
        return cnt;
    }
    int count_zero(string s)
    {
        int cnt = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '0') cnt++;
        }
        
        return cnt;
    }
    int solve(int index, vector<string> &strs, int m, int n, vector<vector<vector<int>>> &dp)
    {
        if(index >= strs.size()) return 0;
        
        if(dp[index][m][n] != -1) return dp[index][m][n];
        
        int not_pick = solve(index+1, strs, m, n, dp);
        int pick = INT_MIN;
        if(m - count_zero(strs[index]) >= 0 && n - count_one(strs[index]) >= 0)
        {
            pick = 1 + solve(index+1, strs, m-count_zero(strs[index]), n - count_one(strs[index]), dp);
        }
        
        return dp[index][m][n] = max(pick, not_pick);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int k = strs.size();
        vector<vector<vector<int>>> dp(k+1, vector<vector<int>>(m+1, vector<int>(n+1,-1)));
        return solve(0, strs, m, n, dp);
    }
};