class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][j] == 0)
                {
                    for(int k = 0; k < n; k++) if(matrix[i][k] != 0) matrix[i][k] = 1e9+7;
                    for(int k = 0; k < m; k++) if(matrix[k][j] != 0) matrix[k][j] = 1e9+7;
                }
            }
        }
        
        // for(int i = 0; i < m; i++)
        // {
        //     for(int j = 0; j < n; j++)
        //     {
        //         cout<<matrix[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][j] == 1e9+7) matrix[i][j] = 0;
            }
        }
    }
};