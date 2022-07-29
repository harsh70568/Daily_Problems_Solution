class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
       for(auto str : words)
        {
            string temp = str;
            unordered_map<char,char> mpp;
            set<char> s;
            int i;
            for(i = 0; i < temp.length(); i++)
            {
                if(mpp.find(temp[i]) != mpp.end())
                {
                    char ch = mpp[temp[i]];
                    if(ch != pattern[i])
                    {
                        break;
                    }
                }
                mpp[temp[i]] = pattern[i];
                s.insert(pattern[i]);
            }
            if(mpp.size() == s.size() && i == temp.length())
            {
                ans.push_back(temp);
            }
            
            
        }
        return ans;
    }
};