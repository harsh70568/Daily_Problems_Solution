class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> ans;
        string str = "";
        set<char> se;
        unordered_map<string,char> mpp;
        for(int i = 0; i < pattern.length(); i++)
        {
            se.insert(pattern[i]);
        }
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == ' ')
            {
                ans.push_back(str);
                str = "";
            }
            else
            {
                str += s[i];
            }
        }
        ans.push_back(str);
        
        int i = 0;
        for(auto it : ans)
        {
            if(mpp.find(it) != mpp.end())
            {
                if(mpp[it] != pattern[i])
                {
                    return false;
                }
            }
            else
            {
                mpp[it] = pattern[i];
            }
            i++;
        }
        if(mpp.size() != se.size()) return false;
        return true;
        
    }
};