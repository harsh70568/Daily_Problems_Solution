class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for(int i = 0; i < queries.size(); i++)
        {
            int sum = 0;
            int j;
            for(j = 0; j < nums.size(); j++)
            {
                sum += nums[j];
                if(sum > queries[i]) break;
            }
            ans.push_back(j);
        }
        
        return ans;
    }
};