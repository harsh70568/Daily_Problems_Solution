class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string temp = "";
        string ans = "";
        for(int i = 0; i < n; i++)
        {
            if(s[i] == ' ')
            {
                reverse(temp.begin(),temp.end());
                ans += temp;
                ans += ' ';
                temp = "";
            }
            else
            {
                temp += s[i];
            }
        }
        reverse(temp.begin(),temp.end());
        ans += temp;
        return ans;
    }
};