class Solution {
public:
    int solve(int index, int cnt, vector<int> &s, vector<vector<int>> &dp)
    {
        if(index >= s.size()) return 0;
        
        if(dp[index][cnt] != -1) return dp[index][cnt];
        
        int not_pick = 0 + solve(index+1, cnt, s, dp);
        int pick = s[index]*cnt + solve(index+1, cnt+1, s, dp);
        
        return dp[index][cnt] = max(pick, not_pick);
    }
    int maxSatisfaction(vector<int>& s) {
        int n = s.size();
        sort(s.begin(), s.end());
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        return solve(0, 1, s, dp);
    }
};