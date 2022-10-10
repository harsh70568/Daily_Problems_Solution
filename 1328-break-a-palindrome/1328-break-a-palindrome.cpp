class Solution {
public:
    string breakPalindrome(string s) {
        if(s.length() == 1) return "";
        int i;
        for(i = 0; i < s.length()/2; i++)
        {
            if(s[i] > 97)
            {
                s[i] = 'a';
                break;
            }
        }
        if(i == s.length()/2) s[s.length()-1] = 'b';
        return s;
    }
};