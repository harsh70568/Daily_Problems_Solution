class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
        if(word1.length() != word2.length()) return false;
        unordered_map<char, int> mpp;
        unordered_map<char, int> mpp2;
        set<char> s1;
        set<char> s2;
        
        for(auto it : word1)
        {
            mpp[it]++;
            s1.insert(it);
        }
        
        for(auto it : word2)
        {
            mpp2[it]++;
            s2.insert(it);
        }
        
        if(s1 != s2) return false;
        vector<int> v1;
        vector<int> v2;
        
        for(auto it : mpp)
        {
            v1.push_back(it.second);
        }
        
        for(auto it : mpp2)
        {
            v2.push_back(it.second);
        }
        
        
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        
        for(int i = 0; i < v1.size(); i++)
        {
            if(v1[i] != v2[i]) return false;
        }
        
        return true;
    }
};