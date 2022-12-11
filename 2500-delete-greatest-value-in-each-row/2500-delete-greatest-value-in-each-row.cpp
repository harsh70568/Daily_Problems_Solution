class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i = 0; i < m; i++)
        {
            sort(grid[i].begin(), grid[i].end());
        }
        
        vector<vector<int>> t(n, vector<int>(m,0));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                t[i][j] = grid[j][i];
            }
        }
        
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += *max_element(t[i].begin(), t[i].end());
        }
        
        return sum;
    }
};