class Solution {
public:
    bool solve(vector<int> &nums, int index, int target, vector<vector<int>> &dp)
    {
        if(target == 0) return true;
        if(index == 0) return(nums[0] == target);
        
        if(dp[index][target] != -1) return dp[index][target];
        
        bool take = false;
        if(nums[index] <= target)
        {
            take = solve(nums,index-1,target-nums[index],dp);
        }
        bool not_take = solve(nums,index-1,target,dp);
        
        return dp[index][target] = take || not_take;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(auto it : nums)
        {
            sum += it;
        }
        if(sum % 2 != 0) return false;
        else
        {
            vector<vector<int>> dp(n, vector<int>(sum/2+1,-1));
            return solve(nums,n-1,sum/2,dp);
        }
    }
};