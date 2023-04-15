class Solution {
public:
    int solve(int index, int prev_index, vector<vector<int>> &pairs, vector<vector<int>> &dp)
    {
        if(index >= pairs.size()) return 0;
        
        if(dp[index][prev_index+1] != -1) return dp[index][prev_index+1];
        
        int not_pick = solve(index+1, prev_index, pairs, dp);
        
        int pick = INT_MIN;
        if(prev_index == -1 || pairs[index][0] > pairs[prev_index][1])
        {
            pick = 1 + solve(index+1, index, pairs, dp);
        }
        
        return dp[index][prev_index+1] = max(pick, not_pick);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int n = pairs.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        return solve(0, -1, pairs, dp);
    }
};