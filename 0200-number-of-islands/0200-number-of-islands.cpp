class Solution {
public:
    void bfs(int i, int j, vector<vector<char>> &grid, vector<vector<int>> &vis)
    {
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = 1;
        int m = grid.size();
        int n = grid[0].size();
        
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            // left
            if(col-1 >= 0 && grid[row][col-1] == '1' && vis[row][col-1] == 0)
            {
                q.push({row, col-1});
                vis[row][col-1] = 1;
            }
            
            // right
            if(col+1 < n && grid[row][col+1] == '1' && vis[row][col+1] == 0)
            {
                q.push({row, col+1});
                vis[row][col+1] = 1;
            }
            
            //up
            if(row-1 >= 0 && grid[row-1][col] == '1' && vis[row-1][col] == 0)
            {
                q.push({row-1, col});
                vis[row-1][col] = 1;
            }
            
            //down
            if(row+1 < m && grid[row+1][col] == '1' && vis[row+1][col] == 0)
            {
                q.push({row+1,col});
                vis[row+1][col] = 1;
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        
        int count = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == '1' && vis[i][j] == 0)
                {
                    count++;
                    bfs(i, j, grid, vis);
                }
            }
        }
        
        return count;
    }
};