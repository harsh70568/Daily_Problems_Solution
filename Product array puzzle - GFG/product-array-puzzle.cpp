//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& arr, int n) {
       
        //code here  
        vector<long long int> ans;
        vector<long long int> prefix(n);
        vector<long long int> suffix(n);
        
        prefix[0] = suffix[n-1] = 1;
        
        for(int i = 1; i < n; i++) prefix[i] = prefix[i-1]*arr[i-1];
        for(int i = n-2; i >= 0; i--) suffix[i] = suffix[i+1]*arr[i+1];
        
        for(int i = 0; i < n; i++)
        {
            ans.push_back(prefix[i]*suffix[i]);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends