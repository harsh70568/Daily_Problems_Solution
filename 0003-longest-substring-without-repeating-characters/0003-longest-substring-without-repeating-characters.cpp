class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int j = 0;
        map<char, int> mpp;
        int maxi = 0;
        while(j < s.length())
        {
            mpp[s[j]]++;
            
            if(j-i+1 == mpp.size())
            {
                maxi = max(maxi, j-i+1);
                j++;
            }
            else
            {
                while(mpp.size() != j-i+1)
                {
                    mpp[s[i]]--;
                    if(mpp[s[i]] == 0) mpp.erase(s[i]);
                    i++;
                }
                j++;
            }
        }
        return maxi;
    }
};