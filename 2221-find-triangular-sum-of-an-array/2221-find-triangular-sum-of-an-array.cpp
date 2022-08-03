class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n-1; i++)
        {
            int k = 0;
            int m = nums.size();
            for(int j = 0; j < m-1; j++)
            {
                nums[k++] = (nums[j] + nums[j+1]) % 10;
            }
        }
        return nums[0];
    }
};