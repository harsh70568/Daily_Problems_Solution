class Solution {
public:
    void solve(vector<int> nums, vector<int> temp, set<vector<int>> &s,int index)
    {
        if(index >= nums.size())
        {
            s.insert(temp);
            return;
        }
        
        temp.push_back(nums[index]);
        solve(nums,temp,s,index+1);
        temp.pop_back();
        solve(nums,temp,s,index+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> temp;
        set<vector<int>> s;
        int index = 0;
        solve(nums,temp,s,index);
        
        vector<vector<int>> ans(s.begin(),s.end());
        return ans;
        
    }
};