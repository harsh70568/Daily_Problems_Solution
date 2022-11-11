class Solution {
public:
    int solve(int index, int prev_idx, vector<vector<int>> &pairs, vector<vector<int>> &dp)
    {
        if(index >= pairs.size()) return 0;
        
        if(dp[index][prev_idx+1] != -1) return dp[index][prev_idx+1];
        
        int not_pick = 0 + solve(index+1, prev_idx, pairs, dp);
        int pick = INT_MIN;
        if(prev_idx == -1 || pairs[index][0] > pairs[prev_idx][1])
        {
            pick = 1 + solve(index+1, index, pairs, dp);
        }
        
        return dp[index][prev_idx+1] = max(pick, not_pick);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        vector<vector<int>> dp(n, vector<int>(n+1,-1));
        sort(pairs.begin(), pairs.end());
        return solve(0, -1, pairs, dp);
        
    }
};