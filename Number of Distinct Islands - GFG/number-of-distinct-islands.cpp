//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  vector<int> delRow = {-1, 0, +1, 0};
  vector<int> delCol = {0, +1, 0, -1};
  void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid, vector<pair<int, int>> &vec, int base_r, int base_c)
  {
      vis[row][col] = 1;
      vec.push_back({row - base_r, col - base_c});
      
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
                  dfs(new_r, new_c, vis, grid, vec, base_r, base_c);
              }
          }
      }
  }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> vis(m, vector<int>(n,0));
        set<vector<pair<int, int>>> st;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(vis[i][j] == 0 && grid[i][j] == 1)
                {
                    vector<pair<int, int>> vec;
                    dfs(i, j, vis, grid, vec, i, j);
                    st.insert(vec);
                }
            }
        }
        
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends