class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> Matrix01(n, vector<int>(m, 20001));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(mat[i][j] == 0)
                {
                    Matrix01[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        int dirx[4] = {-1,1,0,0};
        int diry[4] = {0,0,-1,1};
        while(!q.empty())
        {
            pair<int,int> tp = q.front();
            q.pop();
            int x = tp.first;
            int y = tp.second;
            for(int i = 0; i < 4; i++)
            {
                int nxtx = x + dirx[i];
                int nxty = y + diry[i];
                if(nxtx < 0 || nxtx >= n || nxty < 0 || nxty >= m) continue;
                if(Matrix01[nxtx][nxty] <= Matrix01[x][y] + 1) continue;
                Matrix01[nxtx][nxty] = Matrix01[x][y] + 1;
                q.push({nxtx,nxty});
            }
        }
        return Matrix01;
    }
};