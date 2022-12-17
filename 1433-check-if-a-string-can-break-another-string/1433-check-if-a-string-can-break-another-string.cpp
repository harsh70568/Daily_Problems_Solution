class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        if(s1.length() != s2.length()) return false;
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        
        int count = 0;
        for(int i = 0; i < s1.length(); i++)
        {
            if(s1[i] >= s2[i]) count++;
        }
        
        int count2 = 0;
        for(int i = 0; i < s2.length(); i++)
        {
            if(s2[i] >= s1[i]) count2++;
        }
        
        if(count == s1.length() || count2 == s2.length()) return true;
        else return false;
        
        
    }
};