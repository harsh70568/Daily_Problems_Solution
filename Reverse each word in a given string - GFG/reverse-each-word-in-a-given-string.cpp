// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
  public:
    string reverseWords (string s)
    {
        //code here.
        string ans = "";
        string temp = "";
        int i = 0;
        while(i < s.length())
        {
            if(s[i] == '.')
            {
                reverse(temp.begin(),temp.end());
                ans.append(temp);
                ans.append(".");
                temp = "";
            }
            else
            {
                temp += s[i];
            }
            i++;
        }
        reverse(temp.begin(),temp.end());
        ans.append(temp);
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.reverseWords (s) << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends