class Solution {
public:
    int solve(int index, vector<vector<int>> &events, vector<int> &v, int k, vector<vector<int>> &dp)
    {
        if(k == 0) return 0;
        if(index == events.size()) return 0;
        
        if(dp[index][k] != -1) return dp[index][k];
        
        int next_idx = upper_bound(v.begin(), v.end(), events[index][1]) - v.begin();
        int not_pick = 0 + solve(index+1, events, v, k, dp);
        int pick = events[index][2] + solve(next_idx, events, v, k-1, dp);
        
        return dp[index][k] = max(pick, not_pick);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end());
        
        vector<int> v;
        for(auto it : events)
        {
            v.push_back(it[0]);
        }
        vector<vector<int>> dp(n, vector<int>(k+1,-1));
        return solve(0, events, v, k, dp);
    }
};