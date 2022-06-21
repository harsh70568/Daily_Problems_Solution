class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int elem = image[sr][sc];
        if(elem == color) return image;
        int n = image.size();
        int m = image[0].size();
        queue<pair<int,int>> st;
        st.push({sr,sc});
        image[sr][sc] = color;
        while(!st.empty())
        {
            int i = st.front().first;
            int j = st.front().second;
            
            
            if(i-1 >= 0 && image[i-1][j] == elem)
            {
                image[i-1][j] = color;
                st.push({i-1,j});
            }
            
            if(i+1 < n && image[i+1][j] == elem)
            {
                image[i+1][j] = color;
                st.push({i+1,j});
            }
            
            if(j-1 >= 0 && image[i][j-1] == elem)
            {
                image[i][j-1] = color;
                st.push({i,j-1});
            }
            
            if(j+1 < m && image[i][j+1] == elem)
            {
                
                image[i][j+1] = color;
                st.push({i,j+1});
            }
            st.pop();
        }
        return image;
    }
};