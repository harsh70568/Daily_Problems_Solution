class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = 1e9;
        int max_profit = 0;
        for(int i = 0; i < prices.size(); i++)
        {
            if(prices[i] < min_price)
            {
                min_price = prices[i];
            }
            
            max_profit = max(max_profit, prices[i] - min_price);
        }
        
        return max_profit;
    }
};