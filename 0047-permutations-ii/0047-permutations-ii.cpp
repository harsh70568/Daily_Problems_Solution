class Solution {
public:
    void solve(int index, set<vector<int>> &st, vector<int> &nums)
    {
        if(index >= nums.size())
        {
            st.insert(nums);
            return;
        }
        
        for(int i = index; i < nums.size(); i++)
        {
            swap(nums[index], nums[i]);
            solve(index+1, st, nums);
            swap(nums[index], nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> st;
        
        solve(0, st, nums);
        vector<vector<int>> ans(st.begin(), st.end());
        
        return ans;
    }
};