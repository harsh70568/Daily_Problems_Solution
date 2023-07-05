class Solution {
public:
    void solve(int index, vector<int> &nums, vector<vector<int>> &ans)
    {
        if(index >= nums.size())
        {
            ans.push_back(nums);
            return;
        }
        
        for(int j = index; j < nums.size(); j++)
        {
            swap(nums[j], nums[index]);
            solve(index+1, nums, ans);
            swap(nums[j], nums[index]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int index = 0;
        solve(index, nums, ans);
        return ans;
    }
};