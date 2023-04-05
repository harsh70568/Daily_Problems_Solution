class Solution {
public:
    bool is_possible(vector<int> nums, int mid)
    {
        long long sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > mid)
            {
                int val = nums[i] - mid;
                if(sum < val) return false;
                else sum -= val;
            }
            else
            {
                sum += 1LL*(mid - nums[i]);
            }
        }
        
        return true;
        
    }
    int minimizeArrayValue(vector<int>& nums) {
        int low = 0;
        int high = *max_element(nums.begin(), nums.end());
        
        int ans = -1;
        while(low <= high)
        {
            int mid = (low + high) >> 1;
            if(is_possible(nums, mid))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        
        //cout<<is_possible(nums, 5);
        
        return ans;
    }
};