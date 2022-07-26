class Solution {
public:
    string reverseWords(string s) {
        string temp = "";
        string ans = "";
        int n = s.length();
        for(int i = n-1; i >= 0; i--)
        {
            if(s[i] == ' ' && temp != "")
            {
                reverse(temp.begin(),temp.end());
                ans += temp;
                ans += " ";
                temp = "";
            }
            else if(s[i] != ' ')
            {
                temp.push_back(s[i]);
            }
        }
        if(temp != "")
        {
            reverse(temp.begin(),temp.end());
            ans += temp;
        }
        if(s[0] == ' ') ans.pop_back();
        return ans;
    }
};