class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        int j = 0;
        for(int k = 0; k < nums.size(); k++)
        {
            if(nums[k] == 0)
            {
                i++;
            }
            else
            {
                swap(nums[i],nums[j]);
                i++;
                j++;
            }
        }
    }
};