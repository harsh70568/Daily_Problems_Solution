class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> mpp;
        vector<string> ans;
        if(s.length() < 10) return ans;
        for(int i = 0; i < s.length()-9; i++)
        {
            string temp = s.substr(i,10);
            mpp[temp]++;
        }
        
        for(auto it : mpp)
        {
            if(it.second > 1)
            {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};