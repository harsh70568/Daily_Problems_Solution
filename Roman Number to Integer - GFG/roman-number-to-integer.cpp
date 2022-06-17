// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
   int romanToDecimal(string s) {
    // Write your code here
    int num = 0;
        int n = s.length();
        for(int i = 0; i < s.length(); i++)
        {
            switch(s[i])
            {
                case 'I':
                    if(i+1 < n && s[i+1] == 'V')
                    {
                        num += 4;
                        i++;
                    }
                    else if(i+1 < n && s[i+1] == 'X')
                    {
                        num += 9;
                        i++;
                    }
                    else
                    {
                        num += 1;
                    }
                    break;
                case 'V':
                    num += 5;
                    break;
                case 'X':
                    if(i+1 < n && s[i+1] == 'L')
                    {
                        num += 40;
                        i++;
                    }
                    else if(i+1 < n && s[i+1] == 'C')
                    {
                        num += 90;
                         i++;
                    }
                    else num += 10;
                    break;
                case 'L':
                    num += 50;
                    break;
                case 'C':
                    if(i+1 < n && s[i+1] == 'D'){ 
                        num += 400;
                        i++;
                    }
                    else if(i+1 < n && s[i+1] == 'M')
                    {
                        num += 900;
                        i++;
                    }
                    else num += 100;
                    break;
                case 'D':
                    num += 500;
                    break;
                case 'M':
                    num += 1000;
                    break;
            }
        }
        return num;
    }


};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}  // } Driver Code Ends