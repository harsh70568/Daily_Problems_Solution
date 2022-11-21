class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        
        for(auto &it : nums)
        {
            s.insert(it);
        }
        
        int max_len = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(!s.count(nums[i]-1))
            {
                int curr_elem = nums[i];
                int curr_len = 1;
                while(s.count(curr_elem+1))
                {
                    curr_elem += 1;
                    curr_len += 1;
                }
                max_len = max(max_len, curr_len);
            }
        }
        
        return max_len;
        
    }
};