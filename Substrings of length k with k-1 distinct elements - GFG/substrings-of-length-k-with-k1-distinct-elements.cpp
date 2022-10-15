//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int countOfSubstrings(string s, int K) {
        // code here
        int i = 0;
        int j = 0;
        unordered_map<char,int> mpp;
        int count = 0;
        while(j < s.length())
        {
            mpp[s[j]]++;
            if(j-i+1 < K)
            {
                j++;
            }
            else
            {
                if(mpp.size() == K-1) count++;
                mpp[s[i]]--;
                if(mpp[s[i]] == 0) mpp.erase(s[i]);
                i++;
                j++;
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        int K;
        cin>>S;
        cin>>K;

        Solution ob;
        cout << ob.countOfSubstrings(S,K) << endl;
    }
    return 0;
}
// } Driver Code Ends