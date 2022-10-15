class Solution {
public:
    long long solve(int index, vector<vector<int>> &rides, vector<int> &start, vector<long long> &dp)
    {
        if(index >= rides.size()) return 0;
        
        if(dp[index] != -1) return dp[index];
        int next_idx = lower_bound(start.begin(),start.end(), rides[index][1]) - start.begin();
        
        long long not_pick = 0 + solve(index+1, rides, start, dp);
        long long pick = (rides[index][1] - rides[index][0] + rides[index][2]) + solve(next_idx, rides, start, dp);
        
        return dp[index] = max(pick, not_pick);
    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        int n1 = rides.size();
        vector<int> start;
        sort(rides.begin(), rides.end());
        
        for(int i = 0; i < n1; i++){
            start.push_back(rides[i][0]);
        }
        vector<long long> dp(n1+1,-1);
        return solve(0, rides, start, dp);
    }
};