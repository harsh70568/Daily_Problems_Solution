class Solution {
public:
    int solve(int index, vector<int> &prices, bool flag, int k, vector<vector<vector<int>>> &dp)
    {
        if(k == 0) return 0;
        if(index >= prices.size()) return 0;
        
        if(dp[index][flag][k] != -1) return dp[index][flag][k];
        
        int profit = 0;
        if(flag)
        {
            profit = max(-prices[index] + solve(index+1, prices, false, k, dp), solve(index+1, prices, true, k, dp));
        }
        else
        {
            profit = max(prices[index] + solve(index+1, prices, true, k-1, dp), solve(index+1, prices, false, k, dp));
        }
        
        return dp[index][flag][k] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1,-1)));
        return solve(0, prices, true, k, dp);
    }
};