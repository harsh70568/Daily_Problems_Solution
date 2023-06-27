class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowest_price = INT_MAX;
        int max_profit = 0;
        
        for(int i = 0; i < prices.size(); i++)
        {
            if(prices[i] <= lowest_price)
            {
                lowest_price = prices[i];
            }
            
            max_profit = max(max_profit, prices[i] - lowest_price);
        }
        
        return max_profit;
    }
};