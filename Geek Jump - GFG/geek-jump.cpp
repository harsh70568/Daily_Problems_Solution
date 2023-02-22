//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int solve(vector<int> &height, int n, vector<int> &dp)
  {
      if(n==0)return 0;
      if(dp[n] != -1) return dp[n];
        int step2=INT_MAX;
        int step1 =  abs(height[n]-height[n-1]) + solve(height,n-1, dp);
        if(n-2>=0)
        {
            step2 = abs(height[n]-height[n-2])  + solve(height,n-2, dp);
        }
        return dp[n] = min(step1,step2);
  }
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int> dp(n+1, -1);
        return solve(height, n-1, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends