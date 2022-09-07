class Solution {
public:
    int solve(int index, int prev_index, vector<int> &nums, vector<vector<int>> &dp)
    {
        if(index == nums.size()) return 0;
        if(dp[index][prev_index+1] != -1) return dp[index][prev_index+1]; 
        
        int not_pick = 0 + solve(index+1,prev_index,nums,dp);
        
        int pick = INT_MIN;
        if(prev_index == -1 || nums[index] > nums[prev_index])
        {
            pick = 1 + solve(index+1,index,nums,dp);
        }
        
        return dp[index][prev_index+1] = max(pick,not_pick);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1,-1));
        return solve(0,-1,nums,dp);
    }
};