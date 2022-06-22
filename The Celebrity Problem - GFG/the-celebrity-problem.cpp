// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    bool a_knows_b(int i, int j, vector<vector<int>> &M)
    {
        if(M[i][j] == 1) return 1;
        else return 0;
    }
    int celebrity(vector<vector<int>>& M, int n) 
    {
        // code here
        stack<int> st;
        for(int i = 0; i < n; i++)
        {
            st.push(i);
        }
        
        while(st.size() > 1)
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            
            if(a_knows_b(a,b,M))
            {
                st.push(b);
            }
            else
            {
                st.push(a);
            }
        }
        
        int ans = st.top();
        int one_count = 0;
        for(int i = 0; i < M.size(); i++)
        {
            if(M[ans][i] != 0) return -1;
        }
       for(int i = 0; i < M[0].size(); i++)
       {
           if(M[i][ans] == 1) one_count++;
       }
       if(one_count != M[0].size()-1) return -1;
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends