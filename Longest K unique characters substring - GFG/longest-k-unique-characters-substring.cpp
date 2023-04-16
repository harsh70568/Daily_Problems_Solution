//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    int max_len = -1;
    int i = 0;
    int j = 0;
    
    map<char, int> mpp;
    while(j < s.length())
    {
        mpp[s[j]]++;
        
        if(mpp.size() < k) j++;
        else if(mpp.size() == k)
        {
            max_len = max(max_len, j-i+1);
            j++;
        }
        else
        {
            while(mpp.size() > k)
            {
                mpp[s[i]]--;
                if(mpp[s[i]] == 0) mpp.erase(s[i]);
                i++;
            }
            j++;
        }
    }
    
    return max_len;
}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends