class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> temp;
        
        for(int i = 0; i < profit.size(); i++)
        {
            temp.push_back({difficulty[i], profit[i]});
        }
        
        sort(temp.begin(), temp.end());
        sort(worker.begin(), worker.end());
        
        int sum = 0;
        int j = 0;
        int curr_profit = 0;
        for(int i = 0; i < worker.size(); i++)
        {
            while(j < temp.size() && temp[j].first <= worker[i])
            {
                curr_profit = max(curr_profit, temp[j].second);
                j++;
            }
            
            sum += curr_profit;
        }
        
        return sum;
        
    }
};