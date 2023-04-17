//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends


int minFlips (string s)
{
    int len = s.length();
    
    int cnt_0 = 0;
    
    bool flag = true;
    for(int i = 0; i < s.length(); i++)
    {
        if(flag == true)
        {
            if(s[i] != '0') cnt_0++;
        }
        else
        {
            if(s[i] != '1') cnt_0++;
        }
        flag = !flag;
    }
    
    int cnt_1 = 0;
    bool ok = true;
    for(int i = 0; i < s.length(); i++)
    {
        if(ok == true)
        {
            if(s[i] != '1') cnt_1++;
        }
        else
        {
            if(s[i] != '0') cnt_1++;
        }
        ok = !ok;
    }
    
    return min(cnt_0, cnt_1);
    
}