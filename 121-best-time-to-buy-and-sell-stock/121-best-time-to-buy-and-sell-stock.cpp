class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = INT_MIN;
        int curr_price = INT_MAX;
        for(int i = 0; i < prices.size(); i++)
        {
            if(prices[i] < curr_price)
            {
                curr_price = prices[i];
            }
            max_profit = max(max_profit,prices[i]-curr_price);
        }
        return max_profit;
    }
};