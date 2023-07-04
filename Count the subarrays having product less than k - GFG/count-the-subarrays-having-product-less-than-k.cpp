//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int i = 0;
        int j = 0;
        long long pro = 1;
        int cnt = 0;
        if(k == 1) return 0;
        int total = n*(n+1)/2;
        while(j < n)
        {
            pro *= a[j];
            while(pro >= k)
            {
                cnt += (n - j);
                pro /= a[i];
                i++;
            }
            j++;
        }
        return total - cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends