class Solution {
public:
    bool is_possible(vector<int> weights, int days, int mid)
    {
        int count = 1;
        int sum = 0;
        
        for(int i = 0; i < weights.size(); i++)
        {
            if(sum + weights[i] <= mid)
            {
                sum += weights[i];
            }
            else
            {
                count++;
                if(count > days || weights[i] > mid)
                {
                    return false;
                }
                sum = weights[i];
            }
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int start = *min_element(weights.begin(),weights.end());
        int sum = 0;
        for(int i = 0; i < weights.size(); i++)
        {
            sum += weights[i];
        }
        int end = sum;
        int ans = -1;
        
        while(start <= end)
        {
            int mid = (start+end)/2;
            if(is_possible(weights,days,mid))
            {
                ans = mid;
                end = mid-1;
            }
            else
            {
                start = mid+1;
            }
        }
        return ans;
    }
};