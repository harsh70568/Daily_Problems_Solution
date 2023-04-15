class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            if(k == 0) break;
            else if(nums[i] < 0)
            {
                nums[i] = -1*nums[i];
                k--;
            }
            else
            {
                break;
            }
        }
        
        int sum = accumulate(nums.begin(), nums.end(),  0);
        
        if(k % 2 != 0)
        {
            int val = *min_element(nums.begin(), nums.end());
            sum -= 2*val;
        }
        
        return sum;
    }
};