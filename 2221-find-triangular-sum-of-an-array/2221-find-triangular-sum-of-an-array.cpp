class Solution {
public:
    int triangularSum(vector<int>& nums) {
        while(nums.size() > 1)
        {
            vector<int> new_nums;
            for(int i = 0; i < nums.size()-1; i++)
            {
                int s = (nums[i] + nums[i+1]) % 10;
                new_nums.push_back(s);
            }
            nums = new_nums;
        }
        return nums[0];
    }
};