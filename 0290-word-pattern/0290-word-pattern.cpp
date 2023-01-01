class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string, char> mpp;
        unordered_map<char, string> mpp2;
        int j = 0;
        string str = "";
        int cnt = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == ' ')
            {
                if(mpp.find(str) != mpp.end())
                {
                    char val = mpp[str];
                    if(val != pattern[j]) return false;
                }
                else if(mpp2.find(pattern[j]) != mpp2.end())
                {
                    string tmp = mpp2[pattern[j]];
                    if(tmp != str) return false;
                }
                else
                {
                    mpp[str] = pattern[j];
                    mpp2[pattern[j]] = str;
                }
                j++;
                str = "";
                cnt++;
            }
            else
            {
                str += s[i];
            }
        }
        cnt++;
        if(mpp.find(str) != mpp.end())
        {
            char val = mpp[str];
            if(val != pattern[j]) return false;
        }
        if(mpp2.find(pattern[j]) != mpp2.end())
        {
            string tmp = mpp2[pattern[j]];
            if(tmp != str) return false;
        }
        
        if(cnt != pattern.length()) return false;
        return true;
    }
};