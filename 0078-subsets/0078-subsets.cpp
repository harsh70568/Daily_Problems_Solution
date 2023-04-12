class Solution {
public:
    void solve(int index, vector<vector<int>> &ans, vector<int> &temp, vector<int> &nums)
    {
        if(index >= nums.size())
        {
            ans.push_back(temp);
            return;
        }
        
        temp.push_back(nums[index]);
        solve(index+1, ans, temp, nums);
        temp.pop_back();
        
        solve(index+1, ans, temp, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        
        solve(0, ans, temp, nums);
        
        return ans;
    }
};