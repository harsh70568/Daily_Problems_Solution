class Solution {
public:
    int minimumMoves(string s) {
        int count=  0;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == 'X')
            {
                count++;
                i = i+2;
            }
        }
        return count;
    }
};