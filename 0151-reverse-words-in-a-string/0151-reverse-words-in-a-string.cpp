class Solution {
public:
    string reverseWords(string s) {
        string temp = "";
        string ans;
        for(int i = s.length()-1; i >= 0; i--)
        {
            if(s[i] == ' ')
            {
                if(temp != "")
                {
                    reverse(temp.begin(), temp.end());
                    ans += temp;
                    ans += ' ';
                    temp = "";
                }
                else
                {
                    continue;
                }
            }
            else
            {
                temp += s[i];
            }
        }
        if(temp != "")
        {
            reverse(temp.begin(), temp.end());
            ans += temp;
        }
        else
        {
            ans.pop_back();
        }
        
        return ans;
    }
};