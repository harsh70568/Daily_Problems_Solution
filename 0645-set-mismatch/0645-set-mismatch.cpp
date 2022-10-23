class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int missing = 0;
        int rep = 0;
        unordered_map<int,int> mpp;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            mpp[nums[i]]++;
            if(mpp[nums[i]] == 2) rep = nums[i];
        }
        
        sum -= rep;
        missing = n*(n+1)/2 - sum; 
        
        
        
        
        
        return {rep,missing};
    }
};