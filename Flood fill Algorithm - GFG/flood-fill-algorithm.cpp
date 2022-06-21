// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // Code here 
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

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends