class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int dirx[4] = {-1,1,0,0};
        int diry[4] = {0,0,1,-1};
        queue<pair<int, int>> q;
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 0) continue;
                q.push({i,j});
                int mx = 1;
                grid[i][j] = 0;
                while(!q.empty())
                {
                    pair<int,int> tp = q.front();
                    q.pop();
                    int x = tp.first;
                    int y = tp.second;
                    for(int i = 0; i < 4; i++)
                    {
                        int nxtx = x+dirx[i];
                        int nxty = y+diry[i];
                        if(nxtx < 0 || nxtx >= n || nxty < 0 || nxty >= m) continue;
                        if(grid[nxtx][nxty] == 0) continue;
                        q.push({nxtx,nxty});
                        grid[nxtx][nxty] = 0;
                        mx++;
                    }
                }
                ans = max(ans, mx);
            }
        }
        return ans;
    }
};