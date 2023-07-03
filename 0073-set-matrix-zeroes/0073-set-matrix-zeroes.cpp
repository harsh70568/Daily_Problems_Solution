class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        stack<pair<int, int>> st;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][j] == 0) st.push({i, j});
            }
        }
        
        while(!st.empty())
        {
            int r = st.top().first;
            int c = st.top().second;
            st.pop();
            
            for(int j = 0; j < n; j++) matrix[r][j] = 0;
            for(int i = 0; i < m; i++) matrix[i][c] = 0;
        }
        
        //return matrix;
    }
};