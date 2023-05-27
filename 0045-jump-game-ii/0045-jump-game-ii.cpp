class Solution {
public:
    int solve(int index, vector<int> &nums, int n, vector<int> &dp)
    {
        if(index >= nums.size()-1) return 0;
        
        if(dp[index] != -1) return dp[index];
        
        int mini = 1e9;
        int jumps = nums[index] + index;
        for(int i = index; i < min(n, jumps); i++)
        {
            int temp = 1 + solve(i+1, nums, n, dp);
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