class Solution {
public:
    bool is_possible(vector<int> &weights, int mid, int days)
    {
        int sum = 0;
        int cnt = 1;
        for(int i = 0; i < weights.size(); i++)
        {
            if(sum + weights[i] <= mid)
            {
                sum += weights[i];
            }
            else
            {
                cnt++;
                if(weights[i] > mid || cnt > days) return false;
                sum = weights[i];
            }
        }
        
        return true;
    }
    int shipWithinDays(vector<int>& w, int days) {
        int sum = accumulate(w.begin(), w.end(), 0);
        
        int low = 1;
        int high = sum;
        int ans = 0;
        while(low <= high)
        {
            int mid = (low + high) >> 1;
            if(is_possible(w, mid, days))
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