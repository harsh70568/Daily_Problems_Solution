class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> ans(n);
        
        int sum = 0;
        for(auto it : nums)
        {
            if(it % 2 == 0) sum += it;
        }
        
        for(int i = 0; i < n; i++)
        {
            if(nums[queries[i][1]] % 2 == 0) sum -= nums[queries[i][1]];
            nums[queries[i][1]] += queries[i][0];
            
            if(nums[queries[i][1]] % 2 == 0)
            {
                sum += nums[queries[i][1]];
            }
            ans[i] = sum;
        }
        
        return ans;
    }
};