//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int solve(int i, int j, vector<vector<int>> &mat, int m, int n, vector<vector<int>> &dp)
{
    if(j < 0 || j > n-1) return -1e9;
    if(i == m-1) return mat[i][j];
    
    if(dp[i][j] != -1) return dp[i][j];
    
    int down = mat[i][j] + solve(i+1, j, mat, m, n, dp);
    int left_dia = mat[i][j] + solve(i+1, j-1, mat, m, n, dp);
    int right_dia = mat[i][j] + solve(i+1, j+1, mat, m, n, dp);
    
    return dp[i][j] = max(down, max(left_dia, right_dia));
}
    int maximumPath(int m, vector<vector<int>> matrix)
    {
        // code here
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        int ans = INT_MIN;
        for(int i = 0; i < m; i++)
        {
            ans = max(ans, solve(0, i, matrix, m, n, dp));
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends