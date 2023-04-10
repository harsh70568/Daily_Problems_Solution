//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
    public:
    bool solve(int i, int j, string s, string t, vector<vector<int>> &dp)
    {
        if(i < 0 && j < 0) return true;
        else if(i < 0 && j >= 0) return false;
        else if(j < 0 && i >= 0)
        {
            for(int k = 0; k <= i; k++)
            {
                if(s[k] != '*') return false;
            }
            return true;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i] == t[j] || s[i] == '?')
        {
            return dp[i][j] = solve(i-1, j-1, s, t, dp);
        }
        else if(s[i] == '*')
        {
            return dp[i][j] = solve(i-1, j, s, t, dp) || solve(i, j-1, s, t, dp);
        }
        
        return dp[i][j] = false;
        
    }
    bool match(string s, string t)
    {
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n+1, vector<int>(m,-1));
        return solve(s.length()-1, t.length()-1, s, t, dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        if(ob.match(wild, pattern))
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends