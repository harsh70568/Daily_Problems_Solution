class Solution {
public:
    void dfs(int i, int j, vector<vector<char>> &grid, vector<vector<int>> &vis)
    {
        vis[i][j] = 1;
        
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dx = {-1, 0, +1, 0};
        vector<int> dy = {0, +1, 0, -1};
        
        for(int k = 0; k < 4; k++)
        {
            int new_r = i + dx[k];
            int new_c = j + dy[k];
            
            if(new_r >= 0 && new_r < m && new_c >= 0 && new_c < n)
            {
                if(vis[new_r][new_c] == 0 && grid[new_r][new_c] == '1')
                {
                    dfs(new_r, new_c, grid, vis);
                }
            }
        } 
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> vis(m, vector<int>(n,0));
        int cnt = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == '1' && vis[i][j] == 0)
                {
                    cnt++;
                    dfs(i, j, grid, vis);
                }
            }
        }
        return cnt;
    }
};