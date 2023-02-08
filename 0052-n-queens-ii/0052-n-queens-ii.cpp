class Solution {
public:
    bool is_safe(int row, int col, vector<vector<char>> &board)
    {
        int n = board.size();
        // column checking
        for(int i = row-1; i >= 0; i--)
        {
            if(board[i][col] == 'Q') return false;
        }
        
        // left diagonal checking
        for(int i = row-1, j = col-1; i >= 0 && j >= 0; i--,j--)
        {
            if(board[i][j] == 'Q') return false;
        }
        
        // right diagonal checking
        for(int i = row-1, j = col+1; i >= 0 && j < n; i--,j++)
        {
            if(board[i][j] == 'Q') return false;
        }
        
        return true;
    }
    int solve(int row, vector<vector<char>> &board, int n)
    {
        if(row == n)
        {
            return 1;
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(is_safe(row, i, board))
            {
                board[row][i] = 'Q';
                ans += solve(row+1, board, n);
                board[row][i] = '.';
            }
        }
        
        return ans;
    }
    int totalNQueens(int n) {
        vector<vector<char>> grid(n, vector<char>(n,'.'));
        
        return solve(0, grid, n);
    }
};