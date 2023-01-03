class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for(auto it : nums)
        {
            mpp[it]++;
        }
        
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            int req_num = nums[i] - k;
            if(k == 0)
            {
                if(mpp[nums[i]] > 1)
                {
                    cnt++;
                    mpp.erase(nums[i]);
                }
            }
            else if(mpp.find(req_num) != mpp.end())
            {
                cnt++;
                mpp.erase(req_num);
            }
        }
        
        return cnt;
    }
};