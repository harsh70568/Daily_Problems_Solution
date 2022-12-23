class Solution {
public:
    int solve(int index, vector<int> &prices, bool flag, vector<vector<int>> &dp)
    {
        if(index >= prices.size()) return 0;
        
        if(dp[index][flag] != -1) return dp[index][flag];
        
        int profit = 0;
        if(flag == true)  // time to buy
        {
            profit = max(-prices[index] + solve(index+1, prices, !flag, dp), solve(index+1, prices, flag, dp));
        }
        else   // time to sell
        {
            profit = max(prices[index] + solve(index+2, prices, !flag, dp), solve(index+1, prices, flag, dp));
        }
        
        return dp[index][flag] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2,-1));
        return solve(0, prices, true, dp);
    }
};