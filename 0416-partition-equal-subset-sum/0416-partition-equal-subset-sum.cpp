class Solution {
public:
    bool solve(int index, vector<int> &nums, int sum, vector<vector<int>> &dp)
    {
        if(sum == 0) return true;
        if(index == 0) return sum == nums[0];
        
        if(dp[index][sum] != -1) return dp[index][sum];
        
        int not_pick = solve(index-1, nums, sum, dp);
        int pick = false;
        if(nums[index] <= sum)
        {
            pick = solve(index-1, nums, sum - nums[index], dp);
        }
        
        return dp[index][sum] = not_pick || pick;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto it : nums) sum += it;
        
        if(sum % 2 != 0) return false;
        else {
            sum /= 2;
             vector<vector<int>> dp(nums.size()+1, vector<int>(sum+1,-1));
            return solve(nums.size()-1, nums, sum, dp);
        }
    }
};