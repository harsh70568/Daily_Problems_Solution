class Solution {
public:
    int solve(int index, vector<int> &coins, int amount, vector<vector<int>> &dp)
    {
        if(amount == 0) return 1;
        if(index == 0)
        {
            return amount % coins[0] == 0;
        }
        
        if(dp[index][amount] != -1) return dp[index][amount];
        
        int not_pick = solve(index-1, coins, amount, dp);
        int pick = 0;
        if(coins[index] <= amount)
        {
            pick = solve(index, coins, amount - coins[index], dp);
        }
        
        return dp[index][amount] = pick + not_pick;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1,-1));
        return solve(n-1, coins, amount, dp);
    }
};