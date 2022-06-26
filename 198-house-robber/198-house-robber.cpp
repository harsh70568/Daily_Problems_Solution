class Solution {
public:
    int solve(vector<int>& nums, int n, vector<int> &dp) // recursion + memoization
    {
        if(n<0)
            return 0;
        
        if(n==0)
            return nums[0];
        
        if(dp[n] != -1)
            return dp[n];
        
        int incl = solve(nums,n-2,dp) + nums[n];
        
        int excl = solve(nums,n-1,dp) + 0;
            
        dp[n] = max(incl, excl);
        
        return dp[n];
    }
    
    int rob(vector<int>& nums)
    {
        vector<int> dp(nums.size()+1,-1);
        int ans = solve(nums,nums.size()-1,dp);
        return ans;
    }
};