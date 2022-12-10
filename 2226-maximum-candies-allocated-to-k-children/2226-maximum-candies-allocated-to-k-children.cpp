class Solution {
public:
    bool is_possible(vector<int> &candies, long long mid, long long k)
    {
        long long total = 0;
        for(int i = 0; i < candies.size(); i++)
        {
            total += (candies[i] / mid);
        }
        
        return total >= k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long low = 1;
        long long high = 1e14;
        
        long long ans = 0;
        while(low <= high)
        {
            long long mid = (low + high) >> 1;
            
            if(is_possible(candies, mid, k))
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        
        return ans;
    }
};