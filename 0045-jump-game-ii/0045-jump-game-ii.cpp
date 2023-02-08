class Solution {
public:
    int solve(int index, vector<int> &nums, int n, vector<int> &dp)
    {
        if(index >= nums.size()-1) return 0;
        
        if(dp[index] != -1) return dp[index];
        
        int max_jumps = index + nums[index];
        int ans = 1e9;
        for(int i = index; i < min(n, max_jumps); i++)
        {
            int temp = 1 + solve(i+1, nums, n, dp);
            ans = min(ans, temp);
        }
        
        return dp[index] = ans;
        
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return solve(0, nums, n, dp);
    }
};