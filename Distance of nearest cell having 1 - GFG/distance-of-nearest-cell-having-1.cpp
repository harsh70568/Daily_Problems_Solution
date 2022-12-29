//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int m = grid.size();
	    int n = grid[0].size();
	    vector<vector<int>> vis(m, vector<int>(n,0));
	    vector<vector<int>> ans(m, vector<int>(n,0));
	    
	    queue<vector<int>> q;
	    for(int i = 0; i < m; i++)
	    {
	        for(int j = 0; j < n; j++)
	        {
	            if(grid[i][j] == 1)
	            {
	                vis[i][j] = 1;
	                q.push({i, j, 0});
	            }
	        }
	    }
	    
	    vector<int> delRow = {-1, 0, +1, 0};
	    vector<int> delCol = {0, +1, 0, -1};
	    while(!q.empty())
	    {
	        auto it = q.front();
	        q.pop();
	        
	        int row = it[0];
	        int col = it[1];
	        int stp = it[2];
	        
	        ans[row][col] = stp;
	        
	        for(int i = 0; i < 4; i++)
	        {
	            int new_r = row + delRow[i];
	            int new_c = col + delCol[i];
	            
	            if(new_r >= 0 && new_r < m && new_c >= 0 && new_c < n)
	            {
	                if(vis[new_r][new_c] == 0)
	                {
	                    q.push({new_r, new_c, stp+1});
	                    vis[new_r][new_c] = 1;
	                }
	            }
	        }
	        
	        
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends