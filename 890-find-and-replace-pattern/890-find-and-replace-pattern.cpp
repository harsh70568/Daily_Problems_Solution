class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(int i = 0; i < words.size(); i++)
        {
            string temp = words[i];
            unordered_map<char,char> mpp;
            set<char> s1;
            set<char> s2;
            bool flag = true;
            for(int i = 0; i < temp.length(); i++)
            {
                if(mpp.find(temp[i]) != mpp.end())
                {
                    char ch = mpp[temp[i]];
                    if(ch != pattern[i])
                    {
                        flag = false;
                        break;
                    }
                }
                mpp[temp[i]] = pattern[i];
                s1.insert(temp[i]);
                s2.insert(pattern[i]);
            }
            if(s1.size() != s2.size()) flag = false;
            
            if(flag)
            {
                ans.push_back(temp);
            }
            
        }
        return ans;
    }
};