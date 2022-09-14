class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int count = 1;
        int mini = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] - mini <= k)
            {
                continue;
            }
            else
            {
                count++;
                mini = nums[i];
            }
        }
        
        return count;
    }
};