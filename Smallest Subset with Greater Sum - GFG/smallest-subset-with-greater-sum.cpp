//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int minSubset(vector<int> &a,int n){
        
        sort(a.begin(), a.end(), greater<int>());
        vector<long long> prefix(n);
        vector<long long> suffix(n);
        
        prefix[0] = a[0];
        for(int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i-1] + a[i];
        }
        
        suffix[n-1] = a[n-1];
        for(int i = n-2; i >= 0; i--)
        {
            suffix[i] = suffix[i+1] + a[i];
        }
        
        for(int i = 0; i < n-1; i++)
        {
            if(prefix[i] > suffix[i+1])
            {
                return i+1;
            }
        }
        
        return n;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> Arr(N);
        for(int i=0;i<N;i++){
            cin>>Arr[i];
        }
        Solution ob;
        cout<<ob.minSubset(Arr,N)<<endl;
    }
    return 0;
}
// } Driver Code Ends