class Solution {
public:
    bool is_possible(vector<int> &bloom, int mid, int m, int k)
    {
        int cnt = 0;
        int t_fl = 0;
        for(int i = 0; i < bloom.size(); i++)
        {
            if(bloom[i] <= mid)
            {
                cnt++;
                if(cnt == k)
                {
                    t_fl++;
                    cnt = 0;
                }
            }
            else
            {
                cnt = 0;
            }
        }
        
        return t_fl >= m;
    }
    int minDays(vector<int>& bloom, int m, int k) {
        int maxi = -1;
        for(auto it : bloom)
        {
            maxi = max(maxi, it);
        }
        
        int low = 1;
        int high = maxi;
        int ans = -1;
        while(low <= high)
        {
            int mid = (low + high) >> 1;
            if(is_possible(bloom, mid, m, k))
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