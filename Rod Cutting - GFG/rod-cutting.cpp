//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  int solve(int index, int len[], int price[], int n, vector<vector<int>> &dp)
  {
      if(index == 0)
      {
          if(len[0] <= n) return n*price[0];
          else return 0;
      }
      
      if(dp[index][n] != -1) return dp[index][n];
      
      int not_pick = solve(index-1, len, price, n, dp);
      int pick = 0;
      if(len[index] <= n)
      {
          pick = max(price[index] + solve(index, len, price, n - len[index], dp), solve(index-1, len, price, n, dp));
      }
      
      return dp[index][n] = max(pick, not_pick);
  }
    int cutRod(int price[], int n) {
        //code here
        int len[n];
        for(int i = 0; i <= n; i++)
        {
            len[i] = i+1;
        }
        //for(int i = 0; i < n; i++) cout<<len[i]<<" ";
        vector<vector<int>> dp(n, vector<int>(n+1,-1));
        return solve(n-1, len, price, n, dp);
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends