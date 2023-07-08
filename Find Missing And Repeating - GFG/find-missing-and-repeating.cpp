//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        map<long, long> mpp;
        long long sum = 0;
        long long rep = 0;
        for(auto &it : arr)
        {
            sum += it;
            mpp[it]++;
            if(mpp[it] == 2)
            {
                rep = it;
                //break;
            }
        }
        
        long long miss = 1LL*n*(n+1)/2 - (sum - rep);
        return {rep, miss};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends