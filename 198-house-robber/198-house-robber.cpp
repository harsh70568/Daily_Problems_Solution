class Solution {
public:
    int solve(int index, vector<int> &nums, vector<int> &dp)
    {
        dp[0] = nums[0];
        if(index < 0) return 0;
        for(int i = 1; i <= index; i++){
            int pick = nums[i];
        if(i > 1) pick += dp[i-2];
        int not_pick = 0 + dp[i-1];
            dp[i] = max(pick,not_pick);
        }
        
        return dp[index];
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        return solve(nums.size()-1,nums,dp);
    }
};