//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isValid(vector<vector<int>> mat){
        // code here
        int m = mat.size();
        int n = mat[0].size();
        
        set<string> s;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(mat[i][j] != 0)
                {
                    string str1 = "row" + to_string(i) + to_string(mat[i][j]);
                    string str2 = "col" + to_string(j) + to_string(mat[i][j]);
                    string str3 = "box" + to_string((i/3)*3 + (j/3)) + to_string(mat[i][j]);;
                    
                    if(s.find(str1) != s.end() || s.find(str2) != s.end() || s.find(str3) != s.end())
                    {
                        return false;
                    }
                    
                    s.insert(str1);
                    s.insert(str2);
                    s.insert(str3);
                } 
            }
        }
        
        return true;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends