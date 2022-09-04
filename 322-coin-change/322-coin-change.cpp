class Solution {
public:
    int solve(int index, int amount, vector<int> &coins, vector<vector<int>> &dp){
        
        if(index == 0)
        {
            if(amount % coins[index] == 0)
            {
                return amount/coins[0];
            }
            else return 1e9;
        }
        
        if(dp[index][amount] != -1) return dp[index][amount];
        int take = INT_MAX;
        if(coins[index] <= amount)
        {
           take =  1 + solve(index,amount-coins[index],coins,dp);
        }
        
        int not_take =  solve(index-1,amount,coins,dp);
        return dp[index][amount] = min(take,not_take);
       
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1,-1));
        int ans = solve(n-1,amount,coins,dp);
        if(ans >= 1e9) return -1;
        else return ans;
    }
};