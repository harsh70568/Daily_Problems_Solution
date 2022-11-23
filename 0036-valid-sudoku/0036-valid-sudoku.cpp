class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        set<string> s;
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] != '.')
                {
                    string str1 = "row" + to_string(i) + board[i][j];
                    string str2 = "col" + to_string(j) + board[i][j];
                    string str3 = "box" + to_string((i/3)*3 + (j/3)) + board[i][j];
                    
                    if(s.find(str1) != s.end() || s.find(str2) != s.end() || s.find(str3) != s.end())
                    {
                        return false;
                    }
                    
                    s.insert(str1);
                    s.insert(str2);
                    s.insert(str3);
                }
            }
        }
        
        return true;
    }
};