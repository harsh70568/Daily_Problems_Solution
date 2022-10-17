class Solution {
public:
    int minSteps(string s, string t) {
        int count = 0;
        unordered_map<char,int> mpp;
        for(auto it : s)
        {
            mpp[it]++;
        }
        
        for(int i = 0; i < t.length(); i++)
        {
            if(mpp[t[i]] > 0)
            {
                mpp[t[i]]--;
            }
            else
            {
                count++;
            }
        }
        
        return count;
    }
};