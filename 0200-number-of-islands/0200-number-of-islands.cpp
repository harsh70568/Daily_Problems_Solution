class Solution {
public:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid, vector<int> delRow, vector<int> delCol)
    {
        vis[row][col] = 1;
        
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i = 0; i < 4; i++)
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
        int m = grid.size();
        int n = grid[0].size();
        
        int cnt = 0;
        vector<vector<int>> vis(m, vector<int>(n,0));
        vector<int> delRow = {-1, 0, +1, 0};
        vector<int> delCol = {0, +1, 0, -1};
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