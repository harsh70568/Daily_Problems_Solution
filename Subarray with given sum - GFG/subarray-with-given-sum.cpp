//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        if(s == 0) return {-1};
        int sum=0, fix=0;
        for(int i=0;i<n;i++)    
        {
            if(sum<s)
            {
                sum+=arr[i];
                if(sum==s)
                {
                    return {fix+1, i+1};
                }
                else
                {
                    while(sum > s)
                    {
                        sum -= arr[fix];
                        fix++;
                        if(sum == s) return {fix+1, i+1};
                    }
                }
            }
            else if(sum==s)
            {
                return {fix+1,i};
            }
            else if(sum>s)
            {
                while(sum > s)
                {
                    sum -= arr[fix];
                    fix++;
                    if(sum == s) return {fix+1, i};
                }
            }
        }
        return {-1};
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
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends