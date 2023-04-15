//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    int mod = 1e9 + 7;
    long long int findMaxProduct(vector<int>&a, int n){
        int pos = 0;
        int neg = 0;
        bool zero = false;
        sort(a.begin(), a.end());
        
        // for(auto it : a) cout<<it<<" ";
        // cout<<endl;
        
        for(int i = 0; i < n; i++)
        {
            if(a[i] > 0) pos++;
            else if(a[i] < 0) neg++;
            else if(a[i] == 0)
            {
                zero = true;
            }
        }
        
        if(pos == 0)
        {
            long long pro = 1;
            if(neg >= 2)
            {
                if(neg % 2 != 0) neg--;
                //cout<<neg<<endl;
                for(int i = 0; i < neg; i++)
                {
                    pro = ((pro % mod) * (a[i] % mod)) % mod;
                    pro %= mod;
                }
                return pro;
            }
            else
            {
                if(zero) return 0;
                else return a[0];
            }
        }
        else
        {
            long long pro = 1LL;
            if(neg % 2 != 0) neg--;
            
            for(int i = 0; i < n; i++)
            {
                if(a[i] > 0)
                {
                    pro = ((pro % mod) * (a[i] % mod)) % mod;
                    pro %= mod;
                }
                if(a[i] < 0 && neg)
                {
                    pro = ((pro % mod) * (-1*a[i] % mod)) % mod;
                    pro %= mod;
                    neg--;
                }
            }
            
            return pro;
        }
    }
};



//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    long long int ans = ob.findMaxProduct(arr, n);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends