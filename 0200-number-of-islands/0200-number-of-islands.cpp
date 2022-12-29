class Solution {
public:
    void dfs(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &vis, vector<int> delRow, vector<int> delCol)
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
                if(vis[new_r][new_c] == 0 && grid[new_r][new_c] == '1')
                {
                    dfs(new_r, new_c, grid, vis, delRow, delCol);
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n,0));
        
        int cnt = 0;
        vector<int> delRow = {+1, 0, -1, 0};
        vector<int> delCol = {0, +1, 0, -1};
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == '1' && vis[i][j] == 0)
                {
                    cnt++;
                    dfs(i, j, grid, vis, delRow, delCol);
                }
            }
        }
        
        return cnt;
    }
};