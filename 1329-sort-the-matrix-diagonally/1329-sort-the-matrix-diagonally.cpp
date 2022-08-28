class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        for(int r = 0; r < m; r++)
        {
            vector<int> temp;
            for(int i = r, j = 0; i < m && j < n; i++, j++) temp.push_back(mat[i][j]);
            sort(temp.begin(),temp.end());
            for(int i = r, j = 0; i < m && j < n; i++, j++) mat[i][j] = temp[j];
        }
        
        for(int c = 1; c < n; c++)
        {
            vector<int> temp;
            for(int i = 0, j = c; i < m && j < n; i++, j++) temp.push_back(mat[i][j]);
            sort(temp.begin(),temp.end());
            for(int i = 0, j = c; i < m && j < n; i++, j++) mat[i][j] = temp[i];
        }
        
        return mat;
    }
};