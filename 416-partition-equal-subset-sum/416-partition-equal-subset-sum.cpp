class Solution {
public:
    bool solve(int index, vector<int> &nums, int target, vector<vector<int>> &dp)
    {
        if(target == 0) return true;
        if(index == 0)
        {
            return nums[0] == target;
        }
        if(dp[index][target] != -1) return dp[index][target];
        bool take = false;
        if(nums[index] <= target)
        {
            take = solve(index-1,nums,target-nums[index],dp);
        }
        bool not_take = solve(index-1,nums,target,dp);
        
        return dp[index][target] = take || not_take;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        
        for(auto it : nums)
        {
            sum += it;
        }
        vector<vector<int>> dp(n, vector<int>(sum+1,-1));
        if(sum % 2 != 0) return false;
        else
        {
            return solve(n-1,nums,sum/2,dp);
        }
    }
};