class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0;
        int j = 0;
        
        int max_len = 1;
        unordered_map<int,int> mpp;
        while(j < nums.size())
        {
            mpp[nums[j]]++;
            if(mpp[0] <= 1)
            {
                max_len = max(max_len, j-i+1);
                j++;
            }
            // else if(mpp[0] == 1)
            // {
            //     max_len = max(max_len, j-i);
            //     j++;
            // }
            else
            {
                while(mpp[0] != 1)
                {
                    mpp[nums[i]]--;
                    i++;
                }
                j++;
            }
        }
        
        return max_len-1;
    }
};