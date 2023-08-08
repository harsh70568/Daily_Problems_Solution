//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
void solve(int index, vector<int> &arr, vector<int> &temp, vector<int> &ans)
{
    if(index >= arr.size())
    {
        int sum = accumulate(temp.begin(), temp.end(), 0);
        ans.push_back(sum);
        return;
    }
    
    // pick
    temp.push_back(arr[index]);
    solve(index+1, arr, temp, ans);
    temp.pop_back();
    
    //not_pick
    solve(index+1, arr, temp, ans);
}
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        vector<int> temp;
        solve(0, arr, temp, ans);
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