//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        priority_queue<long long, vector<long long>, greater<long long>> pq(arr, arr+n);
        long long sum = 0;
        
        while(pq.size() > 1)
        {
            long long f = pq.top();
            pq.pop();
            
            long long s = pq.top();
            pq.pop();
            
            sum += (f + s)*1LL;
            if(f + s > 0LL) pq.push(f + s);
        }
        
        return sum;
        
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends