class Solution {
public:
    bool solve(int i, int j, string s, string p)
    {
        if(i < 0 && j < 0) return true;
        if(i >= 0 && j < 0) return false;
        if(i < 0 && j >= 0)
        {
            if(p[j] == '*') return solve(i,j-2,s,p);
            else return false;
        }
        if(s[i] == p[j] || p[j] == '.')
        {
            return solve(i-1,j-1,s,p);
        }
        
        if(p[j] == '*')
        {
            if(j > 0 && (p[j-1] == '.' || p[j-1] == s[i]))
            {
                return solve(i-1,j,s,p) || solve(i,j-2,s,p);
            }
            else return solve(i,j-2,s,p);
        }
        
        return false;
    }
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        
        return solve(n-1,m-1,s,p);
    }
};