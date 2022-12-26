class Solution {
public:
    bool solve(int index, vector<int> &nums, int n, vector<int> &dp)
    {
        if(index >= n-1) return true;
        if(dp[index] != -1) return dp[index];
        
        int max_jump = index + nums[index];
        for(int i = index; i < min(max_jump, n); i++)
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