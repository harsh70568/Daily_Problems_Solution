class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        queue<pair<int,int>> st;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 2)
                {
                    st.push({i,j});
                }
            }
        }
        st.push({-1,-1});
        
        while(!st.empty())
        {
            int i = st.front().first;
            int j = st.front().second;
            
            if(i == -1 && j == -1 && st.size() == 1)
            {
                st.pop();
                break;
            }
            
            if(i == -1 && j == -1 && st.size() > 1)
            {
                count++;
                st.pop();
                st.push({-1,-1});
            }
            
            else
            {
            
            if(i-1 >= 0 && grid[i-1][j] == 1)
            {
                grid[i-1][j] = 2;
                st.push({i-1,j});
            }
            
            if(i+1 < n && grid[i+1][j] == 1)
            {
                grid[i+1][j] = 2;
                st.push({i+1,j});
            }
            
            if(j-1 >= 0 && grid[i][j-1] == 1)
            {
                grid[i][j-1] = 2;
                st.push({i,j-1});
            }
            
            if(j+1 < m && grid[i][j+1] == 1)
            {
                grid[i][j+1] = 2;
                st.push({i,j+1});
            }
            st.pop();
            }
        }
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1) return -1;
            }
        }
        
        return count;
    }
};