class Solution {
public:
    int solve(int i, bool flag, vector<int> &values, int k, vector<vector<vector<int>>> &dp)
    {
        if(k <= 0) return 0;
        if(i >= values.size()) return INT_MIN;
        
        if(dp[i][flag][k] != -1) return dp[i][flag][k];
        int profit = INT_MIN;
        if(flag == 0)
        {
            profit = max(values[i] + i +  solve(i+1, 1, values, k, dp), solve(i+1, flag, values, k, dp));
        }
        else // ab aapne ek elenent le leiya h
        {
            profit = max(values[i] - i +  solve(i+1, 0, values, k-1, dp), solve(i+1, flag, values, k, dp));
        }
        
        return dp[i][flag][k] = profit;
    }
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int k = 1;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1,-1)));
        return solve(0, 0, values, k, dp);
    }
};