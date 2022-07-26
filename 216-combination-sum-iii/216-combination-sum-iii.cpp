class Solution {
public:
    void solve(vector<int> candidates, vector<vector<int>> &ans, vector<int> temp, int k, int n,int index)
    {
        if(index >= candidates.size())
        {
            if(temp.size() == k && n == 0)
            {
                ans.push_back(temp);
            }
            return;
        }
        
        if(candidates[index] <= n)
        {
            temp.push_back(candidates[index]);
            solve(candidates,ans,temp,k,n-candidates[index],index+1);
            temp.pop_back();
        }
        
        solve(candidates,ans,temp,k,n,index+1);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> candidates;
        for(int i = 1; i <= 9; i++)
        {
            candidates.push_back(i);
        }
        vector<vector<int>> ans;
        vector<int> temp;
        int index = 0;
        solve(candidates,ans,temp,k,n,index);
        return ans;
    }
};