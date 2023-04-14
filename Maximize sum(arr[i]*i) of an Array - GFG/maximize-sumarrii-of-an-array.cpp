//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int mod = 1e9+7;
    int Maximize(int a[],int n)
    {
        // Complete the function
        sort(a,a+n);
        long long pro = 0LL;
        for(int i = 0; i < n; i++)
        {
            pro += ((a[i] % mod) * (i*1LL % mod)) % mod;
            pro %= mod;
        }
        
        return pro;
    }
};

//{ Driver Code Starts.
int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<<ob.Maximize(a,n)<<endl;
    }
}
// } Driver Code Ends