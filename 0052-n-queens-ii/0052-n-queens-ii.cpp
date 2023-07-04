class Solution {
public:
    bool is_possible(int i, int j, vector<vector<char>> &arr, int n)
    {
        // for column
        for(int r = i-1; r >= 0; r--) if(arr[r][j] == 'Q') return false;
        // for row
        for(int c = j-1; c >= 0; c--) if(arr[i][c] == 'Q') return false;
        // for left diagonal
        for(int r = i-1, c = j-1; r >= 0 && c >= 0; r--, c--) if(arr[r][c] == 'Q') return false;
        // for right diagonal
        for(int r = i-1, c = j+1; r >= 0 && c < n; r--, c++) if(arr[r][c] == 'Q') return false;
        
        return true;
    }
    
    int solve(int i, vector<vector<char>> &arr, int n)
    {
        if(i == n) return 1;
        
        int cnt = 0;
        for(int j = 0; j < n; j++)
        {
            if(is_possible(i, j, arr, n) == false) continue;
            else
            {
                arr[i][j] = 'Q';
                cnt += solve(i+1, arr, n);
                arr[i][j] = '.';
            }
        }
        return cnt;
    }
    int totalNQueens(int n) {
        vector<vector<char>> arr(n, vector<char>(n,'.'));
        return solve(0, arr, n);
    }
};