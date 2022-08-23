class Solution {
public:
    int solve(int i, int j1, int j2, int m, int n, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
    {
        if(j1 < 0 || j1 > n-1 || j2 < 0 || j2 > n-1) return -1e9;
        if(i == m-1)
        {
            if(j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        
        int maxi = INT_MIN;
        for(int x = -1; x <= 1; x++)
        {
            for(int y = -1; y <= 1; y++)
            {
                if(j1 == j2) maxi = max(maxi,grid[i][j1] + solve(i+1,j1+x,j2+y,m,n,grid,dp));
                else
                {
                    maxi = max(maxi,grid[i][j1] + grid[i][j2] + solve(i+1,j1+x,j2+y,m,n,grid,dp));
                }
            }
        }
        return dp[i][j1][j2] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int> (n,-1)));
        return solve(0,0,n-1,m,n,grid,dp);
    }
};