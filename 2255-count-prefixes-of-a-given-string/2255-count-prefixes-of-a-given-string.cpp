class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int count = 0;
        int m = words.size();
        for(int i = 0; i < m; i++)
        {
            int n = words[i].length();
            if(s.substr(0,n) == words[i]) count++;
        }
        return count;
    }
};