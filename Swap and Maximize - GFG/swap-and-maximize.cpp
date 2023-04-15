//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int maxSum(int arr[], int n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;++i)
			cin>>arr[i];
		cout<<maxSum(arr,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends


long long int maxSum(int arr[], int n)
{
    sort(arr, arr+n);
    vector<int> ans(n);
    
    // for(int i = 0; i < n; i++) cout<<arr[i]<<" ";
    // cout<<endl;
    
    bool flag = true;
    for(int i = 0; i < n / 2; i++)
    {
        if(flag == true)
        {
            ans[i] = arr[i];
            ans[n-1-i] = arr[n-1-i];
            flag = false;
        }
        else
        {
            ans[i] = arr[n-1-i];
            ans[n-i-1] = arr[i];
            flag = true;
        }
    }
    
    if(n % 2 != 0)
    {
        ans[n/2] = arr[n/2];
    }
    
    //for(int i = 0; i < n; i++) cout<<ans[i]<<" ";
    
    long long sum = 0;
    for(int i = 1; i < n; i++)
    {
        sum += abs(ans[i] - ans[i-1]);
    }
    sum += abs(ans[n-1] - ans[0]);
    return sum;
    
}