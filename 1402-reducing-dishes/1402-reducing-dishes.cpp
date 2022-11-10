class Solution {
public:
    int solve(int index, vector<int> &satisfaction, int count, vector<vector<int>> &dp)
    {
        if(index >= satisfaction.size()) return 0;
        
        if(dp[index][count] != -1) return dp[index][count];
        
        int pick = INT_MIN;
        int not_pick = INT_MIN;
        
        not_pick = 0 + solve(index+1, satisfaction, count, dp);
        pick = satisfaction[index] * count + solve(index+1, satisfaction, count+1, dp);
        
        return dp[index][count] = max(pick, not_pick);
        
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        
        vector<vector<int>> dp(n, vector<int>(n+1,-1));
        return solve(0, satisfaction, 1, dp);
        
    }
};