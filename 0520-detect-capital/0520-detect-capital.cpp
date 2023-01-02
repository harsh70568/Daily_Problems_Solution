class Solution {
public:
    bool detectCapitalUse(string word) {
        int c = 0;
        int s = 0;
        int n = word.length();
        for(int i = 0; i < word.length(); i++)
        {
            if(word[i] >= 'a' && word[i] <= 'z') s++;
            else c++;
        }
        
        if(n == s || n == c) return true;
        else if(word[0] >= 'A' && word[0] <= 'Z' && s == n-1) return true;
        else return false;
    }
};