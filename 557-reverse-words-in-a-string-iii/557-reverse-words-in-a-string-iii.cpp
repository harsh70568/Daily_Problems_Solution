class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string temp = "";
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == ' ')
            {
                reverse(temp.begin(),temp.end());
                ans += temp;
                ans += " ";
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