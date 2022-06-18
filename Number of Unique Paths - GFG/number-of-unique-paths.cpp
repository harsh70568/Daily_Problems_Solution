// { Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    //Function to find total number of unique paths.
    int solve(int i, int j, int a, int b, vector<vector<int>> &dp)
    {
        if(i == (a-1) || j == (b-1)) return 1;
        if(i >= a || j >= b) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int l = solve(i+1,j,a,b,dp);
        int r = solve(i,j+1,a,b,dp);
        return dp[i][j] = l+r;
    }
    int NumberOfPath(int a, int b)
    {
        //code here
        vector<vector<int>> dp(a,vector<int>(b,-1));
        
        int i = 0;
        int j = 0;
        return solve(i,j,a,b,dp);
    }
};


// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}

  // } Driver Code Ends