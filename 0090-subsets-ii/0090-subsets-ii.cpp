class Solution {
public:
    void solve(int index, vector<int> &nums, vector<int> &temp, set<vector<int>> &st)
    {
        if(index >= nums.size())
        {
            st.insert(temp);
            return;
        }
        
        temp.push_back(nums[index]);
        solve(index+1, nums, temp, st);
        temp.pop_back();
        
        solve(index+1, nums, temp, st);
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        set<vector<int>> st;
        
        solve(0, nums, temp, st);
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
        
    }
};