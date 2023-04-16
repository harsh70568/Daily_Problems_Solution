class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long i = 0;
        long long j = 0;
        
        long long n = nums.size();
        
        long long score = 0;
        long long sum = 0;
        long long cnt = 0;
        while(j < n)
        {
            sum += (1LL*nums[j]);
            score = 1LL*sum*(j-i+1);
            
            while(score >= k)
            {
                cnt += (n - j);
                sum -= (1LL*nums[i]);
                i++;
                score = 1LL*sum*(j-i+1);
            }
            j++;
            
        }
        
        long long total = (1LL*(1LL*n*(n+1) / 2));
        return total - cnt;
    }
};