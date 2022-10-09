class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long sum = 0;
        long long len = 1;
        for(int i = 1; i < prices.size(); i++)
        {
            if(prices[i] - prices[i-1] == -1)
            {
                len++;
            }
            else
            {
                sum += (len*(len+1)/2);
                len = 1;
            }
        }
        
        sum += (len*(len+1)/2);;
        
        return sum;
    }
};