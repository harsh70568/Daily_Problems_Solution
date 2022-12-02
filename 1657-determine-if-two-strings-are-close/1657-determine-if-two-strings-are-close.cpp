class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length() != word2.length()) return false;
        
        unordered_map<char, int> mpp;
        unordered_map<char, int> mpp2;
        set<char> st;
        
        for(auto it : word1)
        {
            mpp[it]++;
            st.insert(it);
        }
        
        for(auto it : word2)
        {
            mpp2[it]++;
            if(st.find(it) == st.end()) return false;
        }
        
        
        vector<int> ans;
        vector<int> temp;
        for(auto it : mpp)
        {
            ans.push_back(it.second);
        }
        
        for(auto it : mpp2)
        {
            temp.push_back(it.second);
        }
        
        sort(ans.begin(), ans.end());
        sort(temp.begin(), temp.end());
        
        return ans == temp;
    }
};