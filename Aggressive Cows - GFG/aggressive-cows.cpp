//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool is_possible(vector<int> &stalls, int mid, int k)
    {
        int n = stalls.size();
        int cnt = 1;
        int pos = stalls[0];
        
        int i = 1;
        while(i < n)
        {
            if(stalls[i] - pos >= mid)
            {
                cnt++;
                pos = stalls[i];
            }
            i++;
        }
        
        return cnt >= k;
    }
    int solve(int n, int k, vector<int> &stalls) {
    
        int low = 0;
        sort(stalls.begin(), stalls.end());
        int high = stalls[n-1] - stalls[0];
        
        int ans = 0;
        while(low <= high)
        {
            int mid = (low + high) >> 1;
            if(is_possible(stalls, mid, k))
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return ans;
    }
    
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends