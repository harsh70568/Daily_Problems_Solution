class Solution {
public:
    string reverseVowels(string s) {
        string v = "";
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == 'a' || s[i] == 'i' || s[i] == 'e' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i]    == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            {
                v += s[i];
                s[i] = '*';
            }
        }
        reverse(v.begin(), v.end());
        int k = 0;

        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '*')
            {
                s[i] = v[k];
                k++;

            }
        }

        return s;
    }
};