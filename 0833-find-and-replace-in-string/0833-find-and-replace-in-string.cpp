class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        unordered_map<int, pair<int, string>> mpp;
        for(int i = 0; i < sources.size(); i++)
        {
            if(sources[i] == s.substr(indices[i], sources[i].length()))
            {
                mpp[indices[i]] = {sources[i].length(), targets[i]};
            }
        }
        
        string ans = "";
        for(int i = 0; i < s.length(); i++)
        {
            if(mpp.find(i) != mpp.end())
            {
                ans += mpp[i].second;
                int k = mpp[i].first;
                k--;
                while(k--)
                {
                    i++;
                }
            }
            else
            {
                ans += s[i];
            }
        }
        
        return ans;
    }
};