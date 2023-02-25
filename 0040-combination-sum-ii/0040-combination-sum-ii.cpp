class Solution {
public:
    void solve(int index, vector<vector<int>> &ans, vector<int> &temp, int target, vector<int> &candidates)
    {
        if(target == 0)
        {
            if(target == 0) ans.push_back(temp);
            return;
        }
        
        for(int i = index; i < candidates.size(); i++)
        {
            if(i > index && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) break;
            
            temp.push_back(candidates[i]);
            solve(i+1, ans, temp, target - candidates[i], candidates);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        
        solve(0, ans, temp, target, candidates);
        
        return ans;
    }
};