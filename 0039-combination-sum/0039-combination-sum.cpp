class Solution {
public:
    void solve(int index, int target, vector<vector<int>> &ans, vector<int> &temp, vector<int> &candidate)
    {
        if(index >= candidate.size())
        {
            if(target == 0)
            {
                ans.push_back(temp);
            }
            return;
        }
        
        if(candidate[index] <= target)
        {
            temp.push_back(candidate[index]);
            solve(index, target - candidate[index], ans, temp, candidate);
            temp.pop_back();
        }
        
        solve(index+1, target, ans, temp, candidate);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        
        solve(0, target, ans, temp, candidates);
        return ans;
    }
};