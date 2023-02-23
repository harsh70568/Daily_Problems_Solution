class Solution {
public:
    bool is_possible(vector<int> &piles, int mid, int h)
    {
        long long  cnt = 0;
        for(int i = 0; i < piles.size(); i++)
        {
            cnt += (piles[i] / mid*1LL);
            if(piles[i] % mid != 0) cnt++;
        }
        
        return cnt <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = -1;
        for(auto it : piles) maxi = max(maxi, it);
        int low = 1;
        int high = maxi;
        
        int ans = -1;
        while(low <= high)
        {
            int mid = (low + high) >> 1;
            if(is_possible(piles, mid, h))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};