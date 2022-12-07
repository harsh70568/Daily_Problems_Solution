class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        arr[0] = 1;
        int maxi = INT_MIN;
        for(int i = 1; i < n; i++)
        {
            if(arr[i] - arr[i-1] > 1)
            {
                arr[i] = arr[i-1] + 1;
            }
            maxi = max(maxi, arr[i]);
        }
        
        return maxi == INT_MIN ? 1 : maxi;
    }
};