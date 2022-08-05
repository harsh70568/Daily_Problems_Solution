class Solution {
public:
    void solve(vector<int> &candidates, int target, vector<vector<int>> &ans ,vector<int> &temp,int index)
    {
        if(index >= candidates.size())
        {
            if(target == 0){
            ans.push_back(temp);}
            return;
        }
        
        if(candidates[index] <= target)
        {
            temp.push_back(candidates[index]);
            solve(candidates,target-candidates[index],ans,temp,index);
            temp.pop_back();
        }
        
        solve(candidates,target,ans,temp,index+1);
    }
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
            int index = 0;
        solve(candidates,target,ans,temp,index);
        return ans;
    }
};