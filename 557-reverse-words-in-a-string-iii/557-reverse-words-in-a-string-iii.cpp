class Solution {
public:
    string reverseWords(string s) {
        string str = "";
        string ans = "";
        int n = s.length();
        int i = 0;
        while(i < n)
        {
            if(s[i] == ' ')
            {
                reverse(str.begin(),str.end());
                ans.append(str);
                ans.append(" ");
                str = "";
            }
            else str += s[i];
            i++;
        }
        reverse(str.begin(),str.end());
        ans.append(str);
        return ans;
    }
};