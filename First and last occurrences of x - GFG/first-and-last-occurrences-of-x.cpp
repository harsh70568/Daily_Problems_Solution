// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

int start(int nums[], int n, int x)
{
    int low = 0;
    int high = n-1;
    
    while(low <= high)
    {
        int mid = (low + high) >> 1;
        
        if(nums[mid] < x) low = mid + 1;
        else if(nums[mid] > x) high = mid - 1;
        else
        {
            if(mid == 0) return 0;
            else if(nums[mid-1] == x) high = mid - 1;
            else return mid;
        }
    }
    
    return -1;
}

int last(int nums[], int n, int x)
{
    int low = 0;
    int high = n-1;
    
    
    while(low <= high)
    {
        int mid = (low + high) >> 1;
        
        if(nums[mid] < x) low = mid + 1;
        else if(nums[mid] > x) high = mid - 1;
        else
        {
            if(mid == n-1) return mid;
            else if(nums[mid+1] == x) low = mid + 1;
            else return mid;
        }
    }
    
    return -1;
}
vector<int> find(int arr[], int n , int x )
{
    // code here
    int start_idx = start(arr, n, x);
    int last_idx = last(arr, n, x);
    
    return {start_idx, last_idx};
}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


  // } Driver Code Ends