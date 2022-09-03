class Solution {
public:
    bool check(string s)
    {
        int i = 0;
        int j = s.length()-1;
        while(i < j)
        {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    bool isPalindrome(string s) {
        string ans = "";
        string temp = "";
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] >= 97 && s[i] <= 122)  // small letters
            {
                temp += s[i];
            }
            else if(s[i] >= 65 && s[i] <= 90) // capital letters
            {
                temp += s[i]+32;
            } 
            else if(s[i] >= 48 && s[i] <= 57)
            {
                temp += s[i];
            }
        }
        
        if(check(temp)) return true;
        else return false;
    }
};