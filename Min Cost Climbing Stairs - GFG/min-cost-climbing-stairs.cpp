//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
  int solve(int index, vector<int> &cost, vector<int> &dp)
  {
      if(index >= cost.size()) return 0;
      
      if(dp[index] != -1) return dp[index];
      
      int one = cost[index] + solve(index+1, cost, dp);
      int two = cost[index] + solve(index+2, cost, dp);
      
      return dp[index] = min(one, two);
  }
    int minCostClimbingStairs(vector<int>&cost ,int N) {
        //Write your code here
        vector<int> dp(N+1,-1);
        return min(solve(0, cost, dp), solve(1, cost, dp));
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>cost(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>cost[i];
        }

        Solution ob;
        cout<<ob.minCostClimbingStairs(cost,N);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends