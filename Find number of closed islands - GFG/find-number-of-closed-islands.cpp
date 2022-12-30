//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    vector<int> delRow = {-1, 0, +1, 0};
    vector<int> delCol = {0, +1, 0, -1};
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid)
    {
        vis[row][col] = 1;
        
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i = 0; i < 4; i++)
        {
            int new_r = row + delRow[i];
            int new_c = col + delCol[i];
            
            if(new_r >= 0 && new_r < m && new_c >= 0 && new_c < n)
            {
                if(vis[new_r][new_c] == 0 && grid[new_r][new_c] == 1)
                {
                    dfs(new_r, new_c, vis, grid);
                }
            }
        }
    }
    int closedIslands(vector<vector<int>>& grid, int m, int n) {
        // Code here
        vector<vector<int>> vis(m, vector<int>(n, 0));
        
        for(int j = 0; j < n; j++)
        {
            if(vis[0][j] == 0 && grid[0][j] == 1)
            {
                dfs(0, j, vis, grid);
            }
            
            if(vis[m-1][j] == 0 && grid[m-1][j] == 1)
            {
                dfs(m-1, j, vis, grid);
            }
        }
        
        for(int i = 0; i < m; i++)
        {
            if(vis[i][0] == 0 && grid[i][0] == 1)
            {
                dfs(i, 0, vis, grid);
            }
            
            if(vis[i][n-1] == 0 && grid[i][n-1] == 1)
            {
                dfs(i, n-1, vis, grid);
            }
        }
        
        int cnt = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(vis[i][j] == 0 && grid[i][j] == 1)
                {
                    cnt++;
                    dfs(i, j, vis, grid);
                }
            }
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends