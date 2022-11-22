class Solution {
public:
    int solve(int index, vector<int> &temp, int target, vector<vector<int>> &dp)
    {
        if(target == 0) return 0;
        if(index == 0)
        {
            if(target % temp[0] == 0) return target / temp[0];
            else return 1e9;
        }
        
        if(dp[index][target] != -1) return dp[index][target];
        
        int not_pick = 0 + solve(index-1, temp, target, dp);
        int pick = 1e9;
        if(temp[index] <= target)
        {
            pick = 1 + solve(index, temp, target - temp[index], dp);
        }
        
        return dp[index][target] = min(pick, not_pick);
    }
    int numSquares(int n) {
        vector<int> temp;
        
        for(int i = 1; i*i <= n; i++)
        {
            temp.push_back(i*i);
        }
        vector<vector<int>> dp(temp.size(), vector<int>(n+1,-1));
        return solve(temp.size()-1, temp, n, dp);
    }
};