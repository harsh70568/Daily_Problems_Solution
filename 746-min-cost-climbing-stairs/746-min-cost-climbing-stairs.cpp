class Solution {
public:
    int solve(int index, vector<int> &cost, vector<int> &dp)
    {
        dp[0] = dp[1] = 0;
        for(int i = 2; i <= index; i++){
        int n_1 = dp[i-1] + cost[i-1];
        int n_2 = dp[i-2] + cost[i-2];
        dp[i] = min(n_1,n_2);
        }
        return dp[index];
    }
    
    int minCostClimbingStairs(vector<int>& cost){
        int n = cost.size();
        vector<int> dp(n+1,-1);
        return solve(n,cost,dp);
    }
};