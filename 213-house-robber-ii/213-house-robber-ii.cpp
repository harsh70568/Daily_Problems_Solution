class Solution {
public:
    int solve(int index, vector<int> &nums, vector<int> &dp)
    {
        if(index < 0) return 0;
        if(dp[index] != -1) return dp[index];
        int not_pick = 0 + solve(index-1,nums,dp);
        int pick = nums[index];
        if(index > 1) pick = nums[index] + solve(index-2,nums,dp);
        
        return dp[index] = max(not_pick,pick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> temp1,temp2;
        vector<int> dp1(n-1,-1),dp2(n-1,-1);
        for(int i = 0; i < n; i++)
        {
            if(i != 0) temp1.push_back(nums[i]);
            if(i != n-1) temp2.push_back(nums[i]);
        }
        
        return max(solve(n-2,temp1,dp1),solve(n-2,temp2,dp2));
    }
};



