class Solution {
public:
    void dfs(int r, int c, vector<vector<int>> &vis, vector<vector<char>> &grid, vector<int> &dx, vector<int> &dy)
    {
        vis[r][c] = 1;
        
        for(int i = 0; i < 4; i++)
        {
            int new_i = r + dx[i];
            int new_j = c + dy[i];
            
            if(new_i < grid.size() && new_i >= 0 && new_j < grid[0].size() && new_j >= 0)  // index valid
            {
                if(grid[new_i][new_j] == '1' && vis[new_i][new_j] == 0)
                {
                    dfs(new_i, new_j, vis, grid, dx, dy);
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        
        vector<vector<int>> vis(m, vector<int>(n,0));
        int cnt = 0;
        vector<int> dx = {-1, 0, +1, 0};
        vector<int> dy = {0, +1, 0, -1};
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == '1' && vis[i][j] == 0)
                {
                    cnt++;
                    dfs(i, j, vis, grid, dx, dy);
                }
            }
        }
        
        return cnt;
    }
};