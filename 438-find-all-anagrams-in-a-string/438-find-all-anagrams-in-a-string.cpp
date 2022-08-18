class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        unordered_map<char,int> mpp;
        for(auto it : p)
        {
            mpp[it]++;
        }
        int count = mpp.size();
        int i = 0;
        int j = 0;
        int k = p.length();
        while(j < s.length())
        {
            if(mpp.find(s[j]) != mpp.end())
            {
                mpp[s[j]]--;
                if(mpp[s[j]] == 0) count--;
            }
            
            if(j-i+1 < k) j++;
            else if(j-i+1 == k)
            {
                if(count == 0)
                {
                    ans.push_back(i);
                }
                
                if(mpp.find(s[i]) != mpp.end())
                {
                    mpp[s[i]]++;
                    if(mpp[s[i]] == 1)
                    {
                        count++;
                    }
                }
                i++;
                j++;
            }
        }
        return ans;
        
    }
};