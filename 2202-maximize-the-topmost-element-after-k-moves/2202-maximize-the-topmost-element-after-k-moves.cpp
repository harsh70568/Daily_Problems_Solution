class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        if(nums.size() == 1 && k % 2 == 1) return -1;
        int maxi_idx = -1;
        int maxii = -1;
        int n = nums.size();
        //k = k % nums.size();
        for(int i = 0; i < min(k,n); i++)
        {
            if(nums[i] > maxii)
            {
                maxii = nums[i];
                maxi_idx = i+1;
            }
        }
        //cout<<maxi_idx;
        if(k == maxi_idx)
        {
            int maxi = -1;
            for(int i = 0; i < maxi_idx-1; i++)
            {
                maxi = max(maxi, nums[i]);
            }
            return max(nums[k], maxi);
        }
        else
        {
            int maxi = -1;
            for(int i = 0; i < min(k,n); i++)
            {
                maxi = max(maxi, nums[i]);
            }
            if(k <= nums.size()-1) maxi = max(maxi, nums[k]);
            return maxi;
        }
    }
};