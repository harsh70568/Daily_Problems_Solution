class Solution {
public:
    long long is_possible(vector<int> &piles, int mid)
    {
        long long t_h = 0;
        for(int i = 0; i < piles.size(); i++)
        {
            t_h += (piles[i] / mid);
            if(piles[i] % mid != 0) t_h++;
        }
        
        return t_h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = -1;
        for(auto it : piles) maxi = max(maxi, it);
        int low = 1;
        int high = maxi;
        int ans = 0;
     
        while(low <= high)
        {
            int mid = (low + high) >> 1;
            if(is_possible(piles, mid) <= h)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        //cout<<is_possible(piles, 6);
        
        return ans;
    }
};