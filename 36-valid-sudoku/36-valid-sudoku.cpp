class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<string> s;
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] != '.')
                {
                    string res1 = "row"+to_string(i)+board[i][j];
                    string res2 = "col"+to_string(j)+board[i][j];
                    string res3 = "box"+to_string((i/3)*3+(j/3))+board[i][j];
                    
                    if(s.find(res1) != s.end()) return false;
                    if(s.find(res2) != s.end()) return false;
                    if(s.find(res3) != s.end()) return false;
                    
                    s.insert(res1);
                    s.insert(res2);
                    s.insert(res3);
                }
            }
        }
        return true;
    }
};