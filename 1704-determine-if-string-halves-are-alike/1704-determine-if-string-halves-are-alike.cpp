class Solution {
public:
    bool halvesAreAlike(string s) {
        int cnt = 0;
        int cnt2 = 0;
        int n = s.length();
        for(int i = 0; i < n/2; i++)
        {
            if(s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' || s[i] == 'i' || s[i] == 'I' || s[i] == 'o' || s[i] == 'O' || s[i] == 'u' || s[i] == 'U') cnt++;
        }
        
        for(int i = n/2; i < n; i++)
        {
            if(s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' || s[i] == 'i' || s[i] == 'I' || s[i] == 'o' || s[i] == 'O' || s[i] == 'u' || s[i] == 'U') cnt2++;
        }
        
        return cnt == cnt2;
    }
};