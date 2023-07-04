class Solution {
public:
    void solve(int index, vector<int> &candidates, vector<int> &temp, int target, vector<vector<int>> &ans)
    {
        if(target == 0)
        {
            ans.push_back(temp);
            return;
        }
        if(index == -1)
        {
            if(target == 0)
            {
                ans.push_back(temp);
            }
            return;
        }
        
        solve(index-1, candidates, temp, target, ans);
        if(candidates[index] <= target)
        {
            temp.push_back(candidates[index]);
            solve(index, candidates, temp, target - candidates[index], ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        
        int n = candidates.size();
        solve(n-1, candidates, temp, target, ans);
        return ans;
    }
};