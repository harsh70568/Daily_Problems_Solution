class Solution {
public:
    void solve(int i, vector<int> &temp, set<vector<int>> &st, vector<int> &nums)
    {
        if(i >= nums.size())
        {
            st.insert(temp);
            return;
        }
        
        temp.push_back(nums[i]);
        solve(i+1, temp, st, nums);
        temp.pop_back();
        solve(i+1, temp, st, nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        vector<int> temp;
        
        solve(0, temp, st, nums);
        
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};