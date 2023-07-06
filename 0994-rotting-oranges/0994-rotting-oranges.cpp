class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(m, vector<int>(n,0));
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }
        
        int maxi_time = 0;
        while(!q.empty())
        {
            int time = q.front().second;
            int i = q.front().first.first;
            int j = q.front().first.second;
            q.pop();
            
            vector<int> dx = {-1, 0, +1, 0};
            vector<int> dy = {0, +1, 0, -1};
            
            for(int k = 0; k < 4; k++)
            {
                int new_r = i + dx[k];
                int new_c = j + dy[k];
                
                if(new_r >= 0 && new_r < m && new_c >= 0 && new_c < n)
                {
                    if(vis[new_r][new_c] == 0 && grid[new_r][new_c] == 1)
                    {
                        q.push({{new_r, new_c}, time+1});
                        vis[new_r][new_c] = 1;
                        maxi_time = max(maxi_time, time+1);
                    }
                }
            }
        }
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1 && vis[i][j] == 0) return -1;
            }
        }
        
        return maxi_time;
    }
};