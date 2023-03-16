class Solution {
public:
    int solve(int index, vector<int> &nums, int target, int temp)
    {
        if(index < 0)
        {
            return temp == target;
        }
        
        
        int add = solve(index-1, nums, target, temp + nums[index]);
        int sub = solve(index-1, nums, target, temp - nums[index]);
        
        return add + sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        //vector<vector<int>> dp(n+1, vector<int>(target+1,-1));
        return solve(n-1, nums, target, 0);
    }
};