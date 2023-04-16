class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        
        int i = 0;
        int j = 0;
        int pro = 1;
        
        int cnt = 0;
        while(j < n)
        {
            pro *= nums[j];
            
            while(i <= j && pro >= k)
            {
                cnt += (n - j);
                pro /= nums[i];
                i++;
            }
            j++;
        }
        
        int total = (n*(n+1)) / 2;
        return total - cnt;
    }
};