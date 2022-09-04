class Solution {
public:
    int solve(int index, int amount, vector<int> &coins, vector<vector<int>> &dp)
    {
        if(amount == 0) return 1;
        if(index == 0)
        {
            if(amount % coins[0] == 0) return 1;
            return 0;
        }
        if(dp[index][amount] != -1) return dp[index][amount];
        int take = 0;
        if(coins[index] <= amount)
        {
            take = solve(index,amount-coins[index],coins,dp);
        }
        
        int not_take = solve(index-1,amount,coins,dp);
        
        return dp[index][amount] = take + not_take;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1,-1));
        return solve(n-1,amount,coins,dp);
    }
};