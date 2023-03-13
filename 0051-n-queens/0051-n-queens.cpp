class Solution {
public:
    bool is_safe(int row, int col, vector<string> &temp, int n)
    {
        for(int i = row-1; i >= 0; i--)
        {
            if(temp[i][col] == 'Q') return false;
        }
        
        for(int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--)
        {
            if(temp[i][j] == 'Q') return false;
        }
        
        for(int i = row-1, j = col+1; i >= 0 && j < n; i--, j++)
        {
            if(temp[i][j] == 'Q') return false;
        }
        
        return true;
    }
    void solve(int row, vector<vector<string>> &ans, vector<string> &temp, int n)
    {
        if(row == n)
        {
            ans.push_back(temp);
            return;
        }
        
        for(int j = 0; j < n; j++)
        {
            if(is_safe(row, j, temp, n))
            {
                temp[row][j] = 'Q';
                solve(row+1, ans, temp, n);
                // backtrack
                temp[row][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> temp(n);
        string s(n, '.');
        
        for(int i = 0; i < n; i++)
        {
            temp[i] = s;
        }
        
        solve(0, ans, temp, n);
        
        return ans;
    }
};