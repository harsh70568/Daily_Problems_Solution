//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    long long maxDiamonds(int arr[], int n, int k) {
        priority_queue<int> pq(arr, arr+n);
        long long sum = 0;
        while(!pq.empty() && k)
        {
            int s = pq.top();
            pq.pop();
            
            sum += s;
            if(s / 2 != 0) pq.push(s / 2);
            k--;
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        
        cin>>N>>K;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.maxDiamonds(A,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends