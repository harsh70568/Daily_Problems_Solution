//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid, vector<int> delRow, vector<int> delCol)
    {
        vis[row][col] = 1;
        
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < 8; i++)
        {
            int new_r = row + delRow[i];
            int new_c = col + delCol[i];
            
            if(new_r < m && new_r >= 0 && new_c < n && new_c >= 0)
            {
                if(vis[new_r][new_c] == 0 && grid[new_r][new_c] == '1')
                {
                    dfs(new_r, new_c, vis, grid, delRow, delCol);
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int m = grid.size();
        int n = grid[0].size();
        
        int cnt = 0;
        vector<vector<int>> vis(m, vector<int>(n,0));
        vector<int> delRow = {-1, -1, -1, 0, +1, +1, +1, 0};
        vector<int> delCol = {-1, 0, +1, +1, +1, 0, -1, -1};
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(vis[i][j] == 0 && grid[i][j] == '1')
                {
                    cnt++;
                    dfs(i, j, vis, grid, delRow, delCol);
                }
            }
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends