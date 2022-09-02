class Solution {
public:
    int solve(int index, int buy, int capacity, vector<int> &prices, vector<vector<vector<int>>> &dp)
    {
        if(index == prices.size()) return 0;
        if(capacity == 0) return 0;
        
        if(dp[index][buy][capacity] != -1) return dp[index][buy][capacity];
        int profit = 0;
        if(buy)
        {
            profit = max(-prices[index]+solve(index+1,0,capacity,prices,dp),0+solve(index+1,1,capacity,prices,dp));
        }
        else
        {
            profit = max(prices[index]+solve(index+1,1,capacity-1,prices,dp),solve(index+1,0,capacity,prices,dp));
        }
        
        return dp[index][buy][capacity] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3,-1)));
        return solve(0,1,2,prices,dp);
    }
};