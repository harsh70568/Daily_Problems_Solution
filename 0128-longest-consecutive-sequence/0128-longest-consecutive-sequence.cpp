class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st(nums.begin(), nums.end());
        
        int max_cnt = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(st.find(nums[i]-1) == st.end())
            {
                int curr_cnt = 1;
                int curr_num = nums[i];
                while(st.find(curr_num+1) != st.end())
                {
                    curr_num += 1;
                    curr_cnt += 1;
                }
                max_cnt = max(max_cnt, curr_cnt);
            }
        }
        
        return max_cnt;
    }
};