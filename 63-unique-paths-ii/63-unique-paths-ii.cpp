class Solution {
public:
    int solve(int i, int j, int m, int n, set<pair<int,int>> &s, vector<vector<int>> &dp)
    {
        if(s.find({i,j}) != s.end()) return 0;
        if(i == m-1 && j == n-1) return 1;
        if(i > m-1 || j > n-1) return 0; 
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int right = solve(i,j+1,m,n,s,dp);
        int down = solve(i+1,j,m,n,s,dp);
        return dp[i][j] = right+down;
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        set<pair<int,int>> s;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,-1));
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(obstacleGrid[i][j] == 1)
                {
                    s.insert({i,j});
                }
            }
        }
        return solve(0,0,m,n,s,dp);
    }
};