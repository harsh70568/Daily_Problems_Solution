class Solution {
public:
    bool isIsomorphic(string s, string t) {
        string temp = "";
        unordered_map<char,char> mpp;
        set<char> st;
        for(int i = 0; i < s.length(); i++)
        {
            mpp[s[i]] = t[i];
        }
        for(auto it : mpp)
        {
            st.insert(it.second);
        }
        if(mpp.size() != st.size()) return false;
                
        for(int i = 0; i < s.length(); i++)
        {
            temp += mpp[s[i]];
        }
        
        if(temp != t) return false;
        return true;
    }
};