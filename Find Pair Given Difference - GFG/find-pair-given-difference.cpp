//{ Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}
// } Driver Code Ends


bool findPair(int arr[], int size, int n){
    //code
    map<int, int> mpp;
    for(int i = 0; i < size; i++) mpp[arr[i]]++;
    
    for(int i = 0; i < size; i++)
    {
        if(n == 0)
        {
            if(mpp[arr[i]] > 1) return true;
        }
        else
        {
            if(mpp[arr[i] + n]) return true;
        }
    }
    
    return false;
    
}