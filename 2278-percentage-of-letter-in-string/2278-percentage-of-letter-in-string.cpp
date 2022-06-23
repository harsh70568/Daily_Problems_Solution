class Solution {
public:
    int percentageLetter(string s, char letter) {
        unordered_map<char,int> mpp;
        int n = s.length();
        for(int i = 0; i < s.length(); i++)
        {
            mpp[s[i]]++;
        }
        
        return  (mpp[letter]*100)/n;
    }
};