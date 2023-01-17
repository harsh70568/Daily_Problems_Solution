class Solution {
public:
    unordered_map<int, int> prime_factors(int n)
    {
        unordered_map<int, int> mpp;
        for(int i = 2; i*i <= n; i++)
        {
            while(n % i == 0)
            {
                mpp[i]++;
                n /= i;
            }
        }
        if(n > 1) mpp[n]++;
        
        return mpp;
    }
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();
        int total_sum = 0;
        
        for(int i = 0; i < n; i++)
        {
            // storing prime factors
            unordered_map<int, int> mpp = prime_factors(nums[i]);
            
            long long total_div = 1; // find total divisors using the formula (a+1)*(b+1)*(c+1)
            long long sum_of_div = 1;
            for(auto it : mpp)
            {
                total_div *= (it.second+1);
                sum_of_div *= (pow(it.first,it.second+1)-1) / (it.first-1);
                
            }
            if(total_div == 4) total_sum += sum_of_div;
        }
        
        return total_sum;
    }
};