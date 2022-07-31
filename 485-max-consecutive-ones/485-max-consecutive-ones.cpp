class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int curr_count = 0;
        int max_count = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 1)
            {
                curr_count++;
                max_count = max(curr_count,max_count);
            }
            else
            {
                curr_count = 0;
            }
        }
        return max_count;
    }
};