//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> leftSmaller(int n, int a[]){
        // code here
        reverse(a,a+n);
        vector<int> ans;
        stack<int> st;
        st.push(a[n-1]);
        ans.push_back(-1);
        for(int i = n-2; i >= 0; i--)
        {
            while(!st.empty() && st.top() >= a[i])
            {
                st.pop();
            }
            
            int elem = st.empty() ? -1 : st.top();
            
            ans.push_back(elem);
            
            st.push(a[i]);
            
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i = 0;i < n;i++)
            cin>>a[i];
        
        Solution ob;
        vector<int> ans = ob.leftSmaller(n, a);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends