class Solution {
public:
    int solve(int index, vector<int> cost, vector<int> &dp)
    {
        if(index <= 1) return 0;
        if(dp[index] != -1) return dp[index];
        int n_2 = INT_MAX;
        int n_1 = solve(index-1,cost,dp) + cost[index-1];
        if(index > 1)  n_2 = solve(index-2,cost,dp) + cost[index-2];
        return dp[index] = min(n_1,n_2);
    }
    
    int minCostClimbingStairs(vector<int>& cost){
        int n = cost.size();
        vector<int> dp(n+1,-1);
        return solve(n,cost,dp);
    }
};