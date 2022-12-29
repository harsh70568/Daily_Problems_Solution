class Solution {
public:
    vector<int> delRow = {-1, 0, +1, 0};
    vector<int> delCol = {0, +1, 0, -1};
    void dfs(int row, int col, vector<vector<int>> &grid1, vector<vector<int>> &grid2, bool &flag, vector<vector<int>> &vis)
    {
        vis[row][col] = 1;
        
        if(grid1[row][col] == 0) flag = false;
        
        int m = grid1.size();
        int n = grid1[0].size();
        for(int i = 0; i < 4; i++)
        {
            int new_r = row + delRow[i];
            int new_c = col + delCol[i];
            
            if(new_r >= 0 && new_r < m && new_c >= 0 && new_c < n)
            {
                if(vis[new_r][new_c] == 0 && grid2[new_r][new_c] == 1)
                {
                    dfs(new_r, new_c, grid1, grid2, flag, vis);
                }
            }
        }
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();
        vector<vector<int>> vis(m, vector<int>(n,0));
        
        int ans = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(vis[i][j] == 0 && grid2[i][j] == 1)
                {
                    bool flag = true;
                    dfs(i, j, grid1, grid2, flag, vis);
                    if(flag == true) ans += 1;
                }
            }
        }
        
        return ans;
    }
};