class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        long long pro = 1;
        
        int start = 0;
        int max_len = 0;
        for(int j = 0; j < nums.size(); j++)
        {
            if(nums[j] == 0)
            {
                pro = 1;
                start = j+1;
            }
            else
            {
                pro *= (nums[j] / abs(nums[j]));
                if(pro > 0) max_len = max(max_len, j-start+1);
            }
            
        }
        
        pro = 1;
        int end = nums.size()-1;
        for(int j = nums.size()-1; j >= 0; j--)
        {
            if(nums[j] == 0)
            {
                pro = 1;
                end = j-1;
            }
            else
            {
                 pro *= (nums[j] / abs(nums[j]));
                 if(pro > 0) max_len = max(max_len, end - j + 1);
            
            }
        }
        
        return max_len;
    }
};