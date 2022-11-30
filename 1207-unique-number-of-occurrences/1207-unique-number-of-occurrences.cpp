class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mpp;
        for(auto it : arr)
        {
            mpp[it]++;
        }
        set<int> s;
        for(auto it : mpp)
        {
            if(s.find(it.second) != s.end())
            {
                return false;
            }
            else
            {
                s.insert(it.second);
            }
        }
        
        return true;
    }
};