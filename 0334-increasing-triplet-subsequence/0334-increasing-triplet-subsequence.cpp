class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        
        if(n < 3) return false;
        int left = INT_MAX;
        int mid = INT_MAX;
        bool flag = false;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] > mid && flag)
            {
                return true;
            }
            else if(nums[i] < left)
            {
                left = nums[i];
            }
            else if(nums[i] > left)
            {
                mid = nums[i];
                flag = true;
            }
        }
        
        return false;
    }
};