class Solution {
public:
    bool is_possible(vector<int> &d, int mid, double hour)
    {
        double t_ti = 0;
        for(int i = 0; i < d.size()-1; i++)
        {
            t_ti += ceil((double)d[i] / mid);
        }
        
        t_ti += ((double)d[d.size()-1] / mid);
        return t_ti <= hour;
    }
    int minSpeedOnTime(vector<int>& d, double hour) {
        int low = 1;
        int high = 1e9;
        int ans = -1;
        
        while(low <= high)
        {
            int mid = (low + high) >> 1;
            if(is_possible(d, mid, hour))
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