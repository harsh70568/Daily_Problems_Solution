class Solution {
public:
    int no_of_stores(vector<int> &quantities, int mid)
    {
        int stores = 0;
        for(auto it : quantities)
        {
            if(it % mid == 0) stores += (it / mid);
            else stores += ((it / mid) + 1);
        }
        
        return stores;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 1;
        int high = *max_element(quantities.begin(), quantities.end());
        
        int ans = 0;
        while(low <= high)
        {
            int mid = (low + high) >> 1;
            
            if(no_of_stores(quantities, mid) <= n)
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