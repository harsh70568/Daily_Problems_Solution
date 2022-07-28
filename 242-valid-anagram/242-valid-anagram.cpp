class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mpp;
        if(s.length() != t.length()) return false;
        for(int i = 0; i < s.length(); i++)
        {
            mpp[s[i]]++;
        }
        
        for(int i = 0; i < t.length(); i++)
        {
            if(mpp[t[i]])
            {
                mpp[t[i]]--;
            }
            else
            {
                return false;
            }
        }
        
        return true;
    }
};