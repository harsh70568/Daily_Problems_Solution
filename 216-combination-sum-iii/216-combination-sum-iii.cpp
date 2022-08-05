class Solution {
public:
    void solve(vector<int> &nums, vector<vector<int>> &ans, vector<int> temp, int index, int k, int n)
    {
        if(index >= nums.size())
        {
            if(temp.size() == k && n == 0)
            {
                ans.push_back(temp);
            }
            return;
        }
        
        if(nums[index] <= n)
        {
            temp.push_back(nums[index]);
            solve(nums,ans,temp,index+1,k,n-nums[index]);
            temp.pop_back();
        }
        
        solve(nums,ans,temp,index+1,k,n);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums;
        for(int i = 1; i <= 9; i++)
        {
            nums.push_back(i);
        }
        
        vector<vector<int>> ans;
        vector<int> temp;
        int index = 0;
        solve(nums,ans,temp,index,k,n);
        return ans;
    }
};