class Solution {
public:
    int balancedStringSplit(string s) {
        int count = 0;
        int c_r = 0;
        int c_l = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(c_r == c_l && c_r != 0)
            {
                count++;
                c_r = 0;
                c_l = 0;
            }
            if(s[i] == 'R')
            {
                c_r++;
            }
            if(s[i] == 'L') c_l++;
        }
        if(c_r == c_l && c_r != 0) count++;
        return count;
    }
};