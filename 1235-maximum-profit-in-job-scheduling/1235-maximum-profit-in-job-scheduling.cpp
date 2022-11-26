class Solution {
public:
    int solve(int index, vector<vector<int>> &ans, vector<int> &startTime, vector<int> &dp)
    {
        if(index >= ans.size()) return 0;
        
        if(dp[index] != -1) return dp[index];
        
        int next_idx = lower_bound(startTime.begin(), startTime.end(), ans[index][1]) - startTime.begin();
        int not_pick = 0 + solve(index+1, ans, startTime, dp);
        int pick = ans[index][2] + solve(next_idx, ans, startTime, dp);
        
        
        return dp[index] = max(pick, not_pick);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> ans;
        int n = endTime.size();
        for(int i = 0; i < startTime.size(); i++)
        {
            ans.push_back({startTime[i], endTime[i], profit[i]});
        }
        
        sort(ans.begin(), ans.end());
        sort(startTime.begin(), startTime.end());
        
        vector<int> dp(n+1,-1);
        return solve(0, ans, startTime, dp);
    }
};