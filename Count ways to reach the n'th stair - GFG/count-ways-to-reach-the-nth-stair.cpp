// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int const M = 1000000007;
    int solve(int n, vector<long long> &dp)
    {
        if(n == 1 || n == 2) return n;
        if(dp[n] != -1) return dp[n];
        int res = solve(n-1,dp)%M+solve(n-2,dp)%M;
        dp[n] = res % M;
        return dp[n];
    }
    int countWays(int n)
    {
        // your code here
       vector<long long> dp(n+1,-1);
       return solve(n,dp);
    }
};



// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}
  // } Driver Code Ends