class Solution {
public:
    void dfs(int row, int col, int iniColor, vector<vector<int>> &ans, vector<vector<int>> &image, int color, vector<int> delRow, vector<int> delCol)
    {
        ans[row][col] = color;
        int m = image.size();
        int n = image[0].size();
        
        for(int i = 0; i < 4; i++)
        {
            int new_r = row + delRow[i];
            int new_c = col + delCol[i];
            
            if(new_r >= 0 && new_r < m && new_c >= 0 && new_c < n){
            if(image[new_r][new_c] == iniColor && ans[new_r][new_c] != color)
            {
                dfs(new_r, new_c, iniColor, ans, image, color, delRow, delCol);
            }
            }
        }
        
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor = image[sr][sc];
        vector<vector<int>> ans = image;
        
        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, 1, 0, -1};
        dfs(sr, sc, iniColor, ans, image, color, delRow, delCol);
        
        return ans;
        
        
    }
};