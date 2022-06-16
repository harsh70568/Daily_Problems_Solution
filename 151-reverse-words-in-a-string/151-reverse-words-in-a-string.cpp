class Solution {
public:
    bool check(string str)
    {
        for(int i = 0; i < str.length(); i++)
        {
            if(str[i] != ' ')
            {
                return true;
            }
        }
        return false;
    }
    string reverseWords(string s) {
        string ans = "";
        string str = "";
        int n = s.length(); 
        int i = n-1;
        while(i >= 0)
        {
            if(s[i] == ' ' && check(str))
            {
                reverse(str.begin(),str.end());
                ans.append(str);
                ans.append(" ");
                str = "";
            }
            else if(s[i] != ' ')
            {
                str += s[i];
            }
            i--;
        }
        if(s[0] == ' ') ans.pop_back();
            else
            {
                reverse(str.begin(),str.end());
                ans.append(str);
            }
        return ans;
    }
};