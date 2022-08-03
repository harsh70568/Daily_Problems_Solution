class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int count = 0;
        for(int i = 0; i < words.size(); i++)
        {
            string str = words[i];
            bool flag = true;
            for(int j = 0; j < str.length(); j++)
            {
                if(str[j] != s[j]) flag = false;
            }
            if(flag) count++;
        }
        return count;
    }
};