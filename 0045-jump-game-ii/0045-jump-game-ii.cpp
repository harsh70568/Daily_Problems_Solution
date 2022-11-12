class Solution {
public:
    int solve(int index, vector<int> &nums, int n, vector<int> &dp)
    {
        if(index == nums.size()-1) return 0;
        
        if(dp[index] != -1) return dp[index];
        
        int max_jump = index + nums[index];
        int mini = 1e9;
        for(int i = index+1; i <= min(max_jump, n-1); i++)
        {
            int temp = 1 + solve(i, nums, n, dp);
            mini = min(mini, temp);
        }
        
        return dp[index] = mini;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        return solve(0, nums, n, dp);
    }
};