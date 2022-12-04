class Solution {
public:
    int solve(int index, vector<int> &nums, vector<int> &dp)
    {
        if(index >= nums.size()) return 0;
        
        if(dp[index] != -1) return dp[index];
        
        int sum = 0;
        int i = index;
        while(i < nums.size() && nums[i] == nums[index])
        {
            sum += nums[index];
            i++;
        }
        
        while(i < nums.size() && nums[i] == nums[index]+1)
        {
            i++;
        }
        
        int not_pick = 0 + solve(index+1, nums, dp);
        int pick = sum + solve(i, nums, dp);
        
        return dp[index] = max(pick, not_pick);
    }
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        sort(nums.begin(), nums.end());
        return solve(0, nums, dp);
    }
};