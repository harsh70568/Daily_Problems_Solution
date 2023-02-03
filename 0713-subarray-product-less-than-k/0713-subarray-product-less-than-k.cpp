class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k == 0) return 0;
        int i = 0;
        int j = 0;
        
        int n = nums.size();
        int cnt = 0;
        long long pro = 1;
        while(j < n)
        {
            pro *= 1LL*nums[j];
            
            while(i <= j && pro >= k)
            {
                cnt += (n - j);
                pro /= nums[i];
                i++;
            }
            j++;
        }
        
        return 1LL*n*(n+1)/2 - cnt;
    }
};