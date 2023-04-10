class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;
        
        map<char, char> mpp;
        map<char, char> mpp2;
        for(int i = 0; i < s.length(); i++)
        {
            if(mpp.find(s[i]) != mpp.end())
            {
                if(mpp[s[i]] != t[i]) return false;
            }
            else if(mpp2.find(t[i]) != mpp2.end())
            {
                if(mpp2[t[i]] != s[i]) return false;
            }
            else
            {
                mpp[s[i]] = t[i];
                mpp2[t[i]] = s[i];
            }
        }
        
        return true;
    }
};