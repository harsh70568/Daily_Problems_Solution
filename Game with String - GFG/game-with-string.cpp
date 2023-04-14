//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        map<char, int> mpp;
        for(auto it : s) mpp[it]++;
        
        priority_queue<int> pq;
        for(auto it : mpp) pq.push(it.second);
        
        while(k && !pq.empty())
        {
            int top = pq.top();
            pq.pop();
            
            if(top-1 > 0) pq.push(top-1);
            k--;
        }
        
        int ans = 0;
        while(!pq.empty())
        {
            ans += (pq.top()*pq.top());
            pq.pop();
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends