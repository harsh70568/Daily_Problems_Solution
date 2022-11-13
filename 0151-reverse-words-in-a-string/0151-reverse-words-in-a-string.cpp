class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string temp = "";
        for(int i = s.length()-1; i >= 0; i--)
        {
            while(i >= 0 && s[i] != ' ')
            {
                temp += s[i];
                i--;
            }
            if(temp != ""){
            reverse(temp.begin(), temp.end());
            ans += temp;
            ans += " ";
            temp = "";
            }
        }
        
        ans.pop_back();
        
        return ans;
    }
};