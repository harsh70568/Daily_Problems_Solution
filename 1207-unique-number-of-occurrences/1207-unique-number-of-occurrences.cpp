class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mpp;
        for(auto it : arr)
        {
            mpp[it]++;
        }
        set<int> st;
        for(auto it : mpp)
        {
            st.insert(it.second);
        }
        
        return st.size() == mpp.size();
    }
};