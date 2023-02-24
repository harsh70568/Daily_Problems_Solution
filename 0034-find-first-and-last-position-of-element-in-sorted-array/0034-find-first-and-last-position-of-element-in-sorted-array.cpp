class Solution {
public:
    int start(vector<int> &nums, int target)
    {
        int low = 0;
        int high = nums.size()-1;
        
        while(low <= high)
        {
            int mid = (low + high) >> 1;
            if(nums[mid] < target) low = mid + 1;
            else if(nums[mid] > target) high = mid - 1;
            else
            {
                if(mid == 0) return mid;
                else if(nums[mid-1] == target) high = mid - 1;
                else return mid;
            }
        }
        
        return -1;
    }
    int last(vector<int> &nums, int target)
    {
        int low = 0;
        int high = nums.size()-1;
        
        while(low <= high)
        {
            int mid = (low + high) >> 1;
            if(nums[mid] < target)
            {
                low = mid + 1;
            }
            else if(nums[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                if(mid == nums.size()-1) return mid;
                else if(nums[mid + 1] == target) low = mid + 1;
                else return mid;
            }
        }
        
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int start_idx = start(nums, target);
        int last_idx = last(nums, target);
        
        return {start_idx, last_idx};
    }
};