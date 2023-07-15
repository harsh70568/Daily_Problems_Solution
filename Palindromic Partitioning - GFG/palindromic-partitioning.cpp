//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
bool is_pal(string s, int left, int right)
{
    while(left <= right)
    {
        if(s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}

int solve(int index, string str, vector<int> &dp)
{
    if(index >= str.length()) return 0;
    
    if(dp[index] != -1) return dp[index];
    
    int mini = 1e9;
    for(int i = index; i < str.length(); i++)
    {
        if(is_pal(str, index, i))
        {
            int cnt = 1 + solve(i+1, str, dp);
            mini = min(mini, cnt);
        }
    }
    
    return dp[index] = mini;
}
    int palindromicPartition(string str)
    {
        int n = str.length();
        vector<int> dp(n+1,-1);
        return solve(0, str, dp)-1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends