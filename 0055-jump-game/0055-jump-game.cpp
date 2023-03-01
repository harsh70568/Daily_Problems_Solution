class Solution {
public:
    bool solve(int index, vector<int> &nums, int n, vector<int> &dp)
    {
        if(index >= nums.size()-1) return true;
        
        if(dp[index] != -1) return dp[index];
        
        int max_jumps = index + nums[index];
        for(int i = index; i < min(n, max_jumps); i++)
        {
            if(solve(i+1, nums, n, dp)) return dp[index] = true;
        }
        
        return dp[index] = false;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        return solve(0, nums, n, dp);
    }
};