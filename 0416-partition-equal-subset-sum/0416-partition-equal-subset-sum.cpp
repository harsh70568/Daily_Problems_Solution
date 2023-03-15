class Solution {
public:
    bool solve(int index, vector<int> &nums, int sum, vector<vector<int>> &dp)
    {
        if(index == 0) return nums[0] == sum;
        if(sum == 0) return true;
        
        if(dp[index][sum] != -1) return dp[index][sum];
        
        bool pick = false;
        if(nums[index] <= sum)
        {
            pick = solve(index-1, nums, sum - nums[index], dp);
        }
        bool not_pick = solve(index-1, nums, sum,dp);
        
        return dp[index][sum] = pick || not_pick;
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0) return false;
        else
        {
            sum = sum / 2;
            vector<vector<int>> dp(nums.size(), vector<int>(sum+1,-1));
            return solve(nums.size()-1, nums, sum, dp);
        }
    }
};