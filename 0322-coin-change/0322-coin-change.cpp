class Solution {
public:
    int solve(int index, vector<int> &coins, int amount, vector<vector<int>> &dp)
    {
        if(amount == 0) return 0;
        if(index == 0)
        {
            if((amount % coins[0]) == 0) return (amount / coins[0]);
            else return 1e9;
        }
        
        if(dp[index][amount] != -1) return dp[index][amount];
        
        int not_pick = solve(index-1, coins, amount, dp);
        int pick = 1e9;
        if(coins[index] <= amount)
        {
            pick = 1 + solve(index, coins, amount - coins[index], dp);
        }
        
        return dp[index][amount] = min(pick, not_pick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1,-1));
        int ans = solve(n-1, coins, amount, dp);

        return ans == 1e9 ? -1 : ans;
    }
};