class Solution {
public:
    bool is_possible(vector<int> &weights, int mid, int days)
    {
        int sum = 0;
        int cnt = 1;
        for(int i = 0; i < weights.size(); i++)
        {
            if(sum + weights[i] > mid)
            {
                cnt++;
                sum = weights[i];
                if(sum > mid) return false;
            }
            else
            {
                sum += weights[i];
                //if(sum > mid) return false;
            }
        }
        
        if(sum > mid) return false;
        
        return cnt <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = accumulate(weights.begin(), weights.end(), 0);
        
        int low = 1;
        int high = sum;
        int ans = -1;
        while(low <= high)
        {
            int mid = (low + high) >> 1;
            if(is_possible(weights, mid, days))
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