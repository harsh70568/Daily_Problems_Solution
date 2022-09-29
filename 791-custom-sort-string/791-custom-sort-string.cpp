class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> mpp;
        for(int i = 0; i < s.length(); i++)
        {
            mpp[s[i]]++;
        }
        
        string ans = "";
        for(int i = 0; i < order.length(); i++)
        {
            if(mpp.find(order[i]) != mpp.end())
            {
                while(mpp[order[i]]--)
                {
                   ans += order[i];
                }
                mpp.erase(order[i]);
            }
        }
        
        for(int i = 0; i < s.length(); i++)
        {
            if(mpp.find(s[i]) != mpp.end())
            {
                ans += s[i];
            }
        }
        
        return ans;
    }
};