//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int k, vector<int> &arr , int n){
        // code here 
        int i = 0;
        int j = 0;
        long long max_sum = INT_MIN;
        long long sum = 0;
        while(j < n)
        {
            sum += arr[j];
            
            if(j-i+1 < k)
            {
                j++;
            }
            else if(j-i+1 == k)
            {
                max_sum = max(max_sum, sum);
                sum -= arr[i];
                i++;
                j++;
            }
        }
        
        return max_sum;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends