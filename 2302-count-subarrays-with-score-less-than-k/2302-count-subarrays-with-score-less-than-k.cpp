#define ll long long
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        ll i = 0;
        ll j = 0;
        ll sum = 0;
        ll score = 0;
        ll cnt = 0;
        while(j < n)
        {
            sum += nums[j];
            score = sum*(j-i+1);
            while(score >= k)
            {
                cnt += (n-j);
                sum -= nums[i];
                i++;
                score = sum*(j-i+1);
            }
            j++;
        }
        
        return 1LL*n*(n+1)/2 - cnt;
    }
};