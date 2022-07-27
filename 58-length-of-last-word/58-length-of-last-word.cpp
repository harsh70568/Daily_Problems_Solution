class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        string temp = "";
        int ans = 0;
        for(int i = n-1; i >= 0; i--)
        {
            if(s[i] == ' ' && temp != "")
            {
                ans = temp.length();
                break;
            }
            else if(s[i] != ' ')
            {
                temp += s[i];
            }
        }
        int curr = temp.length();
        ans = max(curr,ans);
        return ans;
    }
};