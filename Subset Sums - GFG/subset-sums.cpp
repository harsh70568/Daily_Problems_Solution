//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
void solve(int index, int sum, vector<int> &ans, vector<int> &arr)
{
    if(index >= arr.size())
    {
        ans.push_back(sum);
        return;
    }
    
    solve(index+1, sum + arr[index], ans, arr);
    solve(index+1, sum, ans, arr);
}
    vector<int> subsetSums(vector<int> arr, int N)
    {
        int sum = 0;
        vector<int> ans;
        solve(0, 0, ans, arr);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends