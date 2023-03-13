//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  bool is_pal(string str, int s, int e)
  {
      while(s < e)
      {
          if(str[s] != str[e]) return false;
          s++;
          e--;
      }
      
      return true;
  }
  void solve(int index, string &s, vector<vector<string>> &ans, vector<string> &temp)
  {
      if(index == s.size())
      {
          ans.push_back(temp);
          return;
      }
      
      for(int i = index; i < s.size(); i++)
      {
          if(is_pal(s, index, i))
          {
              temp.push_back(s.substr(index, i - index + 1));
              solve(i+1, s, ans, temp);
              temp.pop_back();
          }
      }
  }
    vector<vector<string>> allPalindromicPerms(string s) {
        // code here
        vector<vector<string>> ans;
        vector<string> temp;
        
        solve(0, s, ans, temp);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends