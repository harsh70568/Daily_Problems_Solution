class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        
        int row_s = 0;
        int row_e = n-1;
        
        int col_s = 0;
        int col_e = n-1;
        
        int cnt = 1;
        while(row_s <= row_e && col_s <= col_e)
        {
            for(int j = row_s; j <= row_e; j++)
            {
                ans[row_s][j] = cnt;
                cnt++;
            }
            row_s++;
            
            for(int i = row_s; i <= row_e; i++)
            {
                ans[i][col_e] = cnt;
                cnt++;
            }
            col_e--;
            
            for(int j = col_e; j >= col_s; j--)
            {
                ans[row_e][j] = cnt;
                cnt++;
            }
            row_e--;
            
            for(int i = row_e; i >= row_s; i--)
            {
                ans[i][col_s] = cnt;
                cnt++;
            }
            col_s++;
        }
        
        return ans;
    }
};