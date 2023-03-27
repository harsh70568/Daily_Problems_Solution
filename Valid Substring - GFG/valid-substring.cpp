//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string s) {
        int n = s.length();
       stack<int> st;
       for(int i = 0; i < s.length(); i++)
       {
           if(s[i] == '(')
           {
               st.push(i);
           }
           else
           {
               if(st.empty()) s[i] = '#';
               else
               {
                   st.pop();
               }
           }
       }
       
       while(!st.empty())
       {
           s[st.top()] = '#';
           st.pop();
       }
       
       int maxi = 0;
       int cnt = 0;
       for(int i = 0; i < n; i++)
       {
           if(s[i] == '#')
           {
               maxi = max(maxi, cnt);
               cnt = 0;
           }
           else
           {
               cnt++;
           }
       }
       maxi = max(maxi, cnt);
       
       return maxi;
         
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}

// } Driver Code Ends