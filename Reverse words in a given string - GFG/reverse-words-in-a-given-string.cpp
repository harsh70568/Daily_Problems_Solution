// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        string ans = "";
        string temp = "";
        int i = S.length()-1;
        while(i >= 0)
        {
            if(S[i] == '.')
            {
                reverse(temp.begin(),temp.end());
                ans.append(temp);
                ans.append(".");
                temp = "";
            }
            else
            {
                temp += S[i];
            }
            i--;
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
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}  // } Driver Code Ends