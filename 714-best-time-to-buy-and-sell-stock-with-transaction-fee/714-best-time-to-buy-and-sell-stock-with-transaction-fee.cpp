class Solution {
public:
    int solve(int index, int buy, vector<int> &prices, int fee, vector<vector<int>> &dp)
    {
        if(index == prices.size()) return 0;
        
        if(dp[index][buy] != -1) return dp[index][buy];
        int profit = 0;
        if(buy)
        {
            profit = max(-prices[index] + solve(index+1,0,prices,fee,dp),0+solve(index+1,1,prices,fee,dp));
        }
        else
        {
            profit = max(prices[index] - fee + solve(index+1,1,prices,fee,dp),0+solve(index+1,0,prices,fee,dp));
        }
        
        return dp[index][buy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2,-1));
        
        return solve(0,1,prices,fee,dp);
    }
};