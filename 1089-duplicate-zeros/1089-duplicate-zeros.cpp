class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        int k = 0;
        for(int i = 0; k < n; i++)
        {
            if(arr[i] != 0)
            {
                ans[k] = arr[i];
                k++;
            }
            else
            {
                ans[k] = 0;
                if(k+1 < n) ans[k+1] = 0;
                k += 2;
            }
        }
        arr = ans;
    }
};