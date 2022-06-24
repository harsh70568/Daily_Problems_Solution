// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
    public:
        int isValid(string s) {
            // code here
            long long num = 0;
            string str = "";
            int occur = 0;
            int n = s.length();
            for(int i = 0; i < n; i++)
            {
                if(s[i] == '.')
                {
                    occur++;
                    if(str == "") return 0;
                    num = stoi(str);
                    if(num < 0 || num > 255) return 0;
                    str = "";
                }
                else if(i+1 < n && s[i] == '0' && s[i+1] != 46)
                {
                    return 0;
                }
                else if(!(s[i] >= 48 && s[i] <= 57)) return false;
                else
                {
                    str += s[i];
                }
            }
            if(occur != 3) return 0;
            num = stoi(str);
            if(num < 0 || num > 255) return 0;
            else return 1;
        }
};

// { Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}  // } Driver Code Ends