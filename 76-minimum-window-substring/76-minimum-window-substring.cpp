class Solution {
public:
    string minWindow(string s, string t) {
        int i = 0;
        int j = 0;
        unordered_map<char,int> mpp;
        for(auto it : t)
        {
            mpp[it]++;
        }
        
        int count = mpp.size();
        int min_len = INT_MAX;
        int start;
        
        while(j < s.length())
        {
            if(mpp.find(s[j]) != mpp.end())
            {
                mpp[s[j]]--;
                if(mpp[s[j]] == 0) count--;
            }
            
            if(count > 0) j++;
            
            else if(count == 0)
            {
                if(j-i+1 < min_len)
                {
                    min_len = j-i+1;
                    start = i;
                }
                
                while(count == 0)
                {
                    if(mpp.find(s[i]) == mpp.end())
                    {
                        i++;
                        if(j-i+1 < min_len)
                        {
                            min_len = j-i+1;
                            start = i;
                        }
                    }
                    else
                    {
                        mpp[s[i]]++;
                        if(mpp[s[i]] == 1)
                        {
                            i++;
                            count++;
                        }
                        else
                        {
                            i++;
                            if(j-i+1 < min_len)
                            {
                                min_len = j-i+1;
                                start = i;
                            }
                        }
                    }
                }
                j++;
            }
        }
        return (min_len == INT_MAX) ? "" : s.substr(start,min_len);
    }
};