class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans;
        
        int row_s = 0;
        int row_e = n-1;
        
        int col_s = 0;
        int col_e = m-1;
        
        while(row_s <= row_e && col_s <= col_e)
        {
            // left to right
            for(int j = col_s; j <= col_e; j++)
            {
                ans.push_back(matrix[row_s][j]);
            }
            row_s++;
            
            // up to down
            for(int i = row_s; i <= row_e; i++)
            {
                ans.push_back(matrix[i][col_e]);
            }
            col_e--;
            
            if(row_s <= row_e && col_s <= col_e){
            // right to left
            for(int j = col_e; j >= col_s; j--)
            {
                ans.push_back(matrix[row_e][j]);
            }
            row_e--;
            }
            
            // down to up
            if(row_s <= row_e && col_s <= col_e){
            for(int i = row_e; i >= row_s; i--)
            {
                ans.push_back(matrix[i][col_s]);
            }
            col_s++;
            }
        }
        
        return ans;
    }
};