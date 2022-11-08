class Solution {
public:
    bool solve(int index, vector<int> &nums, vector<int> &dp)
    {
        if(index == nums.size()-1) return true;
        
        if(dp[index] != -1) return dp[index];
        
        int max_jump = index + nums[index]; 
        for(int i = index+1; i <= max_jump; i++)
        {
            if(solve(i, nums, dp)) return dp[index] = true;
        }
        
        return dp[index] = false;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        return solve(0, nums, dp);
    }
};