class Solution {
public:
    bool is_possible(int row, int col, vector<vector<char>> &temp, int n)
    {
        // column checking
        for(int i = row-1; i >= 0; i--)
        {
            if(temp[i][col] == 'Q') return false;
        }
        
        // left diagonal chakeing
        for(int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--)
        {
            if(temp[i][j] == 'Q') return false;
        }
        
        // right diagonal checking
        for(int i = row-1, j = col + 1; i >= 0 && j < n; i--, j++)
        {
            if(temp[i][j] == 'Q') return false;
        }
        
        return true;
    }
    int total_ways(int row, vector<vector<char>> &temp, int n)
    {
        if(row >= n) return 1;
        
        int ans = 0;
        for(int j = 0; j < n; j++)
        {
            if(is_possible(row, j, temp, n))
            {
                temp[row][j] = 'Q';
                ans += total_ways(row+1, temp, n);
                temp[row][j] = '.';
            }
        }
        
        return ans;
    }
    int totalNQueens(int n) {
        vector<vector<char>> temp(n, vector<char>(n,'.'));
        return total_ways(0, temp, n);
        
    }
};