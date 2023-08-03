//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>& arr, int n)
    {   
        map<int, int> mpp;
        int curr_sum = 0;
        int maxi = 0;
        for(int i = 0; i < n; i++)
        {
            curr_sum += arr[i];
            
            if(curr_sum == 0) maxi = max(maxi, i+1);
            else if(mpp.find(curr_sum) != mpp.end())
            {
                int val = mpp[curr_sum];
                maxi = max(maxi, i - val);
            }
            else mpp[curr_sum] = i;
        }
        return maxi;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends