// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    string longestPalin (string S) {
        // code here
        int n = S.length();
        int max_length = 1;
        int start = 0;
        for(int i = 1; i < n; i++)
        {
            // for even length
            int left = i-1;
            int right = i;
            while(left >= 0 && right < n && S[left] == S[right])
            {
                if(right-left+1 > max_length)
                {
                    max_length = right-left+1;
                    start = left;
                }
                left--;
                right++;
            }
        
        // for odd length
        left = i-1;
        right = i+1;
        while(left >= 0 && right < n && S[left] == S[right])
        {
            if(right-left+1 > max_length)
            {
                max_length = right-left+1;
                start = left;
            }
            left--;
            right++;
        }
        }
        return S.substr(start,max_length);
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends