class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char, int> mpp1;
        unordered_map<char, int> mpp2;
        
        for(auto it : target)
        {
            mpp2[it]++;
        }
        
        for(int i = 0; i < s.size(); i++)
        {
            if(mpp2.find(s[i]) != mpp2.end())
            {
                mpp1[s[i]]++;
            }
        }
        
        int mini = INT_MAX;
        for(int i = 0; i < target.size(); i++)
        {
            mini = min(mini, mpp1[target[i]] / mpp2[target[i]]);
        }
        
        return mini;
    }
};