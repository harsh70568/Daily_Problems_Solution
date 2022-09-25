class Solution {
public:
    int minSteps(string s, string t) {
        int count = 0;
        unordered_map<char,int> mpp;
        unordered_map<char,int> sec;
        for(auto it : s)
        {
            mpp[it]++;
        }
        
        for(auto it : t)
        {
            sec[it]++;
        }
        
        for(int i = 0; i < t.length(); i++)
        {
            if(mpp.find(t[i]) != mpp.end())
            {
                sec[t[i]]--;
                if(sec[t[i]] == 0) sec.erase(t[i]);
                mpp[t[i]]--;
                if(mpp[t[i]] == 0) mpp.erase(t[i]);
            }
            else
            {
                count += sec[t[i]];
                sec.erase(t[i]);
            }
        }
        
        for(auto it : mpp)
        {
            if(it.second > 0)
            count += it.second;
        }
        
        return count;
        
    }
};