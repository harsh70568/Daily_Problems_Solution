class Solution {
public:
    void solve(vector<int> nums, set<vector<int>> &s, int index)
    {
        if(index >= nums.size())
        {
            s.insert(nums);
            return;
        }
        
        for(int i = index; i < nums.size(); i++)
        {
            swap(nums[index],nums[i]);
            solve(nums,s,index+1);
            swap(nums[index],nums[i]);
        }
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> s;
        solve(nums,s,0);
        
        vector<vector<int>> temp(s.begin(),s.end());
        return temp;
    }
};