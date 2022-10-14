class Solution {
public:
    int solve(int i, int j, string &s, int n, int idx)
    {
        if(idx >= s.length()) return 0;
        
        if(s[idx] == 'R' && j+1 < n)
        {
            return 1 + solve(i, j+1, s, n, idx+1);
        }
        
        if(s[idx] == 'L' && j-1 >= 0)
        {
            return 1 + solve(i, j-1, s, n, idx+1);
        }
        
        if(s[idx] == 'U' && i-1 >= 0)
        {
            return 1 + solve(i-1, j, s, n, idx+1);
        }
        
        if(s[idx] == 'D' && i+1 < n)
        {
            return 1 + solve(i+1, j, s, n, idx+1);
        }
        
        return 0;
    }
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> ans;
        
        for(int i = 0; i < s.length(); i++)
        {
            ans.push_back(solve(startPos[0], startPos[1], s, n, i));
        }
        
        return ans;
    }
};