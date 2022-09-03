class Solution {
public:
    int solve(int index, vector<int> &nums, int target)
    {
        if(index < 0)
        {
            if(target == 0) return 1;
            else return 0;
        }
        //int take = 0;
        int take = solve(index-1,nums,target-nums[index]);
        int not_take = solve(index-1,nums,target+nums[index]);
        
        return take+not_take;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return solve(n-1,nums,target);
    }
};