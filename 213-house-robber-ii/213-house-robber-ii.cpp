class Solution {
public:
    int solve(int index, vector<int> &nums, vector<int> &dp)
    {
        dp[0] = nums[0];
        
        for(int i = 1; i <= index; i++)
        {
            int pick = nums[i];
            if(i > 1) pick += dp[i-2];
            int not_pick = dp[i-1];
            dp[i] = max(pick,not_pick);
        }
        
        return dp[index];
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> dp(nums.size()+1,-1);
        vector<int> temp1,temp2;
        for(int i = 0; i < nums.size(); i++)
        {
            if(i != nums.size()-1) temp1.push_back(nums[i]);
            if(i != 0) temp2.push_back(nums[i]);
        }
        
        return max(solve(temp1.size()-1,temp1,dp),solve(temp2.size()-1,temp2,dp));
    }
};