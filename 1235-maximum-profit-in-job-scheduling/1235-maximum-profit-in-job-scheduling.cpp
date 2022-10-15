class Solution {
public:
    int solve(int index, vector<vector<int>> &temp, vector<int> &start, vector<int> &dp)
    {
        if(index >= temp.size()) return 0;
        
        if(dp[index] != -1) return dp[index];
        
        int next_index = lower_bound(start.begin(),start.end(), temp[index][1]) - start.begin();
        
        int pick = temp[index][2] + solve(next_index, temp, start, dp);
        int not_pick = 0 + solve(index+1, temp, start, dp);
        
        return dp[index] = max(not_pick, pick);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        
        vector<vector<int>> temp;
        for(int i = 0; i < n; i++)
        {
            temp.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(temp.begin(),temp.end());
        sort(startTime.begin(),startTime.end());
        vector<int> dp(n+1,-1);
        return solve(0, temp, startTime, dp);
    }
};