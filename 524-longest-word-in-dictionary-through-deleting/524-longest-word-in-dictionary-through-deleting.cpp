class Solution {
public:
    static bool cmp(string &a, string &b)
    {
        if(a.length() == b.length()) return a < b;
        return a.length() > b.length();
    }
    bool is_check(string t, string s)
    {
        int i = 0;
        int j = 0;
        while(i < t.length() && j < s.length())
        {
            if(t[i] != s[j])
            {
                i++;
            }
            else
            {
                i++;
                j++;
            }
        }
        if(j == s.length()) return true;
        else return false;
    }
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(),dictionary.end(),cmp);
        for(int i = 0; i < dictionary.size(); i++)
        {
            if(is_check(s,dictionary[i]))
            {
               return dictionary[i];
            }
        }
        
        return "";
    }
};