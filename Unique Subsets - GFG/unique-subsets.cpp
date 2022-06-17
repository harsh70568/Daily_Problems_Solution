// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find all possible unique subsets.
    void solve(vector<int> arr, int n, vector<int> temp, int index, set<vector<int>> &s)
    {
        if(index >= n)
        {
            s.insert(temp);
            return;
        }
        
        temp.push_back(arr[index]);
        solve(arr,n,temp,index+1,s);
        temp.pop_back();
        solve(arr,n,temp,index+1,s);
    }
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        // code here 
        sort(arr.begin(),arr.end());
        vector<int> temp;
        int index = 0;
        set<vector<int>> s;
        
        solve(arr,n,temp,index,s);
        
        vector<vector<int>> ans(s.begin(),s.end());
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   


  // } Driver Code Ends