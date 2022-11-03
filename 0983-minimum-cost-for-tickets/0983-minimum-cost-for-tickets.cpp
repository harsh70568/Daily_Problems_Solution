class Solution {
public:
    int solve(int i, vector<int> &days, vector<int> &costs, int final_day, vector<int> &dp)
    {
        if(i >= days.size()) return 0;
        if(days[i] <= final_day) return solve(i+1, days, costs, final_day, dp);
        
        if(dp[i] != -1) return dp[i];
        
        int one_day = costs[0] + solve(i+1, days, costs, days[i], dp);
        int one_week = costs[1] + solve(i+1, days, costs, days[i]+6, dp);
        int one_month = costs[2] + solve(i+1, days, costs, days[i]+29, dp);
        
        return dp[i] = min({one_day, one_week, one_month});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n, -1);
        return solve(0, days, costs, 0, dp);
    }
};