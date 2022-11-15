class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        unordered_map<char, unordered_set<char>> mpp;
        
        for(int i = 0; i < mappings.size(); i++)
        {
            mpp[mappings[i][0]].insert(mappings[i][1]);
        }
        int k;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == sub[0] || mpp[sub[0]].find(s[i]) != mpp[sub[0]].end())
            {
                int j = 0;
                for(j = 0,k=i; j < sub.length() && k < s.length(); j++,k++)
                {
                    if(s[k] == sub[j] || mpp[sub[j]].find(s[k]) != mpp[sub[j]].end())
                    {
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }
                if(j == sub.length()) return true;
            }
        }
        
        return false;
    }
};