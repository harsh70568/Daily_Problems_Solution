class Solution {
public:
   
    int solve(int i, vector<int> &ans, int sum)
    {
        if(i == 0)
        {
            if(sum % ans[i] == 0) return pow(ans[i],sum/ans[i]); 
        }
        
        int not_pick = solve(i-1, ans, sum);
        int pick = -1e9;
        if(ans[i] <= sum)
        {
            pick = ans[i]*solve(i, ans, sum - ans[i]);
        }
        
        return max(pick, not_pick);
    }
    int integerBreak(int n) {
        vector<int> ans;
        for(int i = 1; i < n; i++)
        {
            ans.push_back(i);
        }
        
        return solve(n-2, ans, n);
        
    }
};