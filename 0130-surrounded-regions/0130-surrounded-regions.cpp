class Solution {
public:
    vector<int> delRow = {-1, 0, +1, 0};
    vector<int> delCol = {0, +1, 0, -1};
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &board)
    {
        vis[row][col] = 1;
        
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < 4; i++)
        {
            int new_r = row + delRow[i];
            int new_c = col + delCol[i];
            
            if(new_r >= 0 && new_r < m && new_c >= 0 && new_c < n)
            {
                if(vis[new_r][new_c] == 0 && board[new_r][new_c] == 'O')
                {
                    dfs(new_r, new_c, vis, board);
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<int>> vis(m, vector<int>(n,0));
        
        for(int j = 0; j < n; j++)
        {
            if(vis[0][j] == 0 && board[0][j] == 'O')
            {
                dfs(0, j, vis, board);
            }
            
            if(vis[m-1][j] == 0 && board[m-1][j] == 'O')
            {
                dfs(m-1, j, vis, board);
            }
        }
        
        for(int i = 0; i < m; i++)
        {
            if(vis[i][0] == 0 && board[i][0] == 'O')
            {
                dfs(i, 0, vis, board);
            }
            
            if(vis[i][n-1] == 0 && board[i][n-1] == 'O')
            {
                dfs(i, n-1, vis, board);
            }
        }
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == 'O' && vis[i][j] == 0)
                {
                    board[i][j] = 'X';
                }
            }
        }
        
        
    }
};