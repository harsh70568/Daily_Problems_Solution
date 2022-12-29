class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> vis(m, vector<int>(n,0));
        vector<vector<int>> ans(m, vector<int>(n,0));
        
        queue<vector<int>> q;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(mat[i][j] == 0)
                {
                    q.push({i, j, 0});
                    vis[i][j] = 1;
                }
            }
        }
        
        vector<int> delRow = {-1, 0, +1, 0};
        vector<int> delCol = {0, +1, 0, -1};
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            
            int row = it[0];
            int col = it[1];
            int steps = it[2];
            
            
            ans[row][col] = steps;
            
            for(int i = 0; i < 4; i++)
            {
                int new_r = row + delRow[i];
                int new_c = col + delCol[i];
                
                if(new_r >= 0 && new_r < m && new_c >= 0 && new_c < n)
                {
                    if(vis[new_r][new_c] == 0)
                    {
                        q.push({new_r, new_c, steps+1});
                        vis[new_r][new_c] = 1;
                    }
                }
            }
            
           
        }
        
        return ans;
        
    }
};